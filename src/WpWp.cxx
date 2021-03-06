/**
 *
 */

#include "Tauola/Tauola.h"
#include "Tauola/TauolaHEPEVTParticle.h"
#include "Tauola/TauolaHEPEVTEvent.h"

using namespace std;
using namespace Tauolapp;

#define LHEF_cxx
#include "LHEF.h"
#include "Davismt2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>




inline TH1F*  CreateHistogram( TString name , TString title , int nPoints, double* xBins, double* yValues ){
  TH1F* h = new TH1F( name , title , nPoints , xBins );
  for(int i=1 ; i <= nPoints ; i++)
    h->SetBinContent( i , yValues[i-1] );

  return h;
};


void LHEF::Loop()
{
  double sumWeightsSR1 = 0.0; 
  double sumWeightsSR2 = 0.0; 
  double sumWeightsEleTau = 0.0; 
  double sumWeightsMuTau = 0.0; 
  Davismt2 *mt2 = new Davismt2();

  TH1* hTauPt_hadhadmax = new TH1D("hTauPt_hadhad-max" , "p_{T}^{#tau_hadhad-max}" , 40 , 0 , 400 );
  TH1* hTauPt_hadhadmin = new TH1D("hTauPt_hadhad-min" , "p_{T}^{#tau_hadhad-min}" , 40 , 0 , 400 );
  TH1* hTauPt_lhad = new TH1D("hTauPt_lhad" , "p_{T}^{#tau_lhad}" , 40 , 0 , 400 );
  TH1* hTauPt_ll = new TH1D("hTauPt_ll" , "p_{T}^{#tau_ll}" , 40 , 0 , 400 );

  TH1* hMET_hadhad = new TH1D("hMET_hadhad" , "MET" , 40 , 0 , 400 );
  TH1* hMET_lhad = new TH1D("hMET_lhad" , "MET" , 40 , 0 , 400 );

  TH1* hMT2_hadhad = new TH1D("hMT2_hadhad" , "MT_{2}" , 40 , 0 , 400 );
  TH1* hMT2_lhad = new TH1D("hMT2_lhad" , "MT_{2}" , 40 , 0 , 400 );



  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;


  //=========================================table 8============================================
  double EffPtBins[] = {20,30,40,60,80,120,160,200,5000}; // table 8, 1st column
  double EffHad_TauPtMax[] = {0.0,0.0,0.03,0.10,0.18,0.22,0.24,0.26}; // table 8, 4th column
  TH1F* hEffHad_TauPtMax = CreateHistogram( "hEffHad_TauPtMax" , "hEffHad_TauPtMax" , 8 , EffPtBins , EffHad_TauPtMax );

  double EffHad_TauPtMin[] = {0.00,0.00,0.61,0.69,0.70,0.70,0.71,0.71}; //table 8, 5th column
  TH1F* hEffHad_TauPtMin = CreateHistogram( "hEffHad_TauPtMin" , "hEffHad_TauPtMin" , 8 , EffPtBins , EffHad_TauPtMin );

  double Eff_El_Pt[] = {0.27 ,0.68 ,0.75 ,0.80 ,0.83 ,0.86 ,0.87 ,0.89}; //table 8, 2nd column
  TH1F* hEff_El_Pt = CreateHistogram( "hEff_El" , "hEff_El" , 8 , EffPtBins , Eff_El_Pt );


  double Eff_Mu_Pt[] = {0.80,0.86,0.87,0.89,0.90,0.90,0.91,0.92}; //table 8, 3rd column
  TH1F* hEff_Mu_Pt = CreateHistogram( "hEff_Mu" , "hEff_Mu" , 8 , EffPtBins , Eff_Mu_Pt );

  double Eff_lTau_HadTau_Pt[] = {0.16, 0.29, 0.34, 0.38, 0.40, 0.41, 0.41, 0.41}; //table 8, 4th column
  TH1F* hEff_lTau_HadTau_Pt = CreateHistogram("hEff_lTau_HadTau_Pt" , "hEff_lTau_HadTau_Pt" , 8 , EffPtBins , Eff_lTau_HadTau_Pt );
  //=====================================end of table 8 ===========================================
  

  //=========================================table 9============================================  
  double EffMETBins[] = {0,10,20,30,40,50,60,70,80,90,100,120,140,160,5000};// table 9, 1st column 
  double Eff_MET[] = { 0.52, 0.58, 0.68, 0.79, 0.87, 0.93, 0.95, 0.97, 0.98,0.98,0.99, 0.99, 0.99,1.0 }; //table 9, 2nd column
  TH1F* hEff_MET = CreateHistogram( "hEff_MET" , "hEff_MET" , 14 , EffMETBins , Eff_MET );
  //=========================================end of table 9============================================


  //=========================================table 10============================================
  double Effhh_MBins[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,5000}; //first column
  double EffHad_hEff_M[] = {  0.00,0.00,0.20,0.90,0.94,0.98,1.00,1.00,0.99, 0.95, 0.68, 0.18, 0.06, 0.03, 0.05, 0.15, 0.40, 0.78, 0.92, 0.95, 0.98, 0.99, 1.00 }; //table 10, last column
  TH1F* hEffHad_hEff_M = CreateHistogram( "hEffhh_M" , "hEffhh_M" , 23 , Effhh_MBins , EffHad_hEff_M  );
  
  double EffHad_l_M[] = { 0.00,0.10,0.23,0.97,0.99,1.00,0.99,0.98,0.84,0.16, 0.04, 0.02, 0.01, 0.04, 0.23, 0.78, 0.91, 0.96, 0.97, 0.98, 1.00, 1.00, 1.00 }; //table 10, 2nd column
  TH1F* hEffHad_l_M = CreateHistogram( "hEffhl_M" , "hEffhl_M" , 23 , Effhh_MBins , EffHad_l_M );
  //=========================================end of table 10============================================


  //=========================================table 11============================================
  double EffMT2Bins[] = {0,20,40,50,60,70,80,90,100,110,120,130,140,160,180,5000};//first column
  double EffHad_h1Eff_Mt2[] = { 0.00,0.01,0.01,0.03,0.07,0.17,0.44,0.73,0.88,0.94,0.97,0.98,0.98,0.99,1.00  }; //table 11, 3rd column
  TH1F* hEffHad_h1Eff_Mt2 = CreateHistogram( "hEffhh1_Mt2" , "hEffhh1_Mt2" , 15 , EffMT2Bins , EffHad_h1Eff_Mt2 );
  
  double EffHad_lEff_Mt2[] = { 0.00,0.002,0.01,0.02,0.05,0.13,0.35,0.65,0.82,0.90,0.93,0.95,0.96,0.97,0.97 };//table 11, 2nd column
  TH1F* hEffHad_lEff_Mt2 = CreateHistogram( "hEff_hl_Mt2" , "hEff_hl_Mt2" , 15 , EffMT2Bins , EffHad_lEff_Mt2 );
  //=========================================end of table 11============================================  


  //=========================================table 12============================================
  double Effhl_MTBins[] = {100,125,150,170,190,200,210,230,250,275,300,5000}; // first column
  double EffHad_lEffMT[] = { 0.01, 0.03, 0.09, 0.26, 0.51, 0.67, 0.82, 0.91, 0.94, 0.97, 1.00}; //table 12, second column
  TH1F* hEffHad_lEffMT = CreateHistogram( "hEffhl_MT" , "hEffhl_MT" , 11 , Effhl_MTBins , EffHad_lEffMT );
  //=========================================end of table 12============================================


  //=========================================table 13============================================
  double EffMT2_SR2_Bins[] = {0,20,40,50,60,70,80,90,100,110,120,130,140,160,180,5000};
  double EffHad_h2Eff_Mt2[] = {  0.08,0.43,0.75,0.82,0.81,0.72,0.49,0.24,0.11,0.05,0.03,0.02,0.01,0.01,0.00 };
  TH1F* hEffHad_h2Eff_Mt2 = CreateHistogram( "hEff_hh2_Mt2" , "hEff_hh2_Mt2" , 15 , EffMT2_SR2_Bins , EffHad_h2Eff_Mt2 );
  //=========================================end of table 13============================================


  //=========================================table 14============================================
  double EffsigmaMTBins[] = {0,80,180,200,210,220,230,240,250,260,270,280,290,300,320,340,360,380,400,5000};//first column
  double EffsigmaHad_hEffMT[] = {  0.00,0.16,0.19,0.25,0.30,0.36,0.43,0.52,0.55,0.61,0.67,0.68,0.73,0.76,0.77,0.80,0.81,0.81,0.82};
  TH1F* hEffsigmaHad_hEffMT = CreateHistogram( "hEffhh_sigMT" , "hEffhh_sigMT" , 19 , EffsigmaMTBins , EffsigmaHad_hEffMT );
  //=========================================end of table 14============================================


  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    TauolaHEPEVTEvent * evt = new TauolaHEPEVTEvent();
    //(PDG_id, status, p_x, p_y, p_z, energy, mass, position of first mother, position of second mother,
    //  position first daugter, last daughter)

    int wp_p_index =  Particle_PID[2] > 0 ? 2 : 3 ;
    int wp_n_index =  Particle_PID[2] > 0 ? 3 : 2 ;
    int tau_p_index , tau_n_index , nu_index , anu_index ;
    for(int p = 0 ; p < Event_Nparticles[0] ; p++){
      if( Particle_PID[p] == 15 )
	tau_n_index = p;
      else if( Particle_PID[p] == -15 )
	tau_p_index = p;
      else if(Particle_PID[p] == 16 )
	nu_index = p;
      else if(Particle_PID[p] == -16 )
	anu_index = p;
    }

    TauolaHEPEVTParticle *q1  = new TauolaHEPEVTParticle( Particle_PID[0], Particle_Status[0], Particle_Px[0], Particle_Py[0], Particle_Pz[0], Particle_E[0] , Particle_M[0] , -1 , -1 , 2, 3 );
    TauolaHEPEVTParticle *q2  = new TauolaHEPEVTParticle(  Particle_PID[1], Particle_Status[1], Particle_Px[1], Particle_Py[1], Particle_Pz[1], Particle_E[1] , Particle_M[1] , -1 , -1 , 2, 3 );
    TauolaHEPEVTParticle *wp_p  = new TauolaHEPEVTParticle(  Particle_PID[wp_p_index], Particle_Status[wp_p_index], Particle_Px[wp_p_index], Particle_Py[wp_p_index], Particle_Pz[wp_p_index], Particle_E[wp_p_index] , Particle_M[wp_p_index] , 0 , 1 , 4 , 5 );
    TauolaHEPEVTParticle *wp_n  = new TauolaHEPEVTParticle(  Particle_PID[wp_n_index], Particle_Status[wp_n_index], Particle_Px[wp_n_index], Particle_Py[wp_n_index], Particle_Pz[wp_n_index], Particle_E[wp_n_index] , Particle_M[wp_n_index] , 0 , 1, 6, 7 );
    TauolaHEPEVTParticle *wpp_d1  = new TauolaHEPEVTParticle( Particle_PID[tau_p_index], Particle_Status[tau_p_index], Particle_Px[tau_p_index], Particle_Py[tau_p_index], Particle_Pz[tau_p_index], Particle_E[tau_p_index] , Particle_M[tau_p_index] , 2 , -1 , -1 , -1 );
    TauolaHEPEVTParticle *wpp_d2  = new TauolaHEPEVTParticle(  Particle_PID[nu_index], Particle_Status[nu_index], Particle_Px[nu_index], Particle_Py[nu_index], Particle_Pz[nu_index], Particle_E[nu_index] , Particle_M[nu_index] , 2, -1 , -1 , -1 );
    TauolaHEPEVTParticle *wpn_d1  = new TauolaHEPEVTParticle( Particle_PID[tau_n_index], Particle_Status[tau_n_index], Particle_Px[tau_n_index], Particle_Py[tau_n_index], Particle_Pz[tau_n_index], Particle_E[tau_n_index] , Particle_M[tau_n_index] , 3 ,-1 , -1 , -1 );
    TauolaHEPEVTParticle *wpn_d2  = new TauolaHEPEVTParticle(  Particle_PID[anu_index], Particle_Status[anu_index], Particle_Px[anu_index], Particle_Py[anu_index], Particle_Pz[anu_index], Particle_E[anu_index] , Particle_M[anu_index] , 3, -1 , -1 , -1 );
    
    evt->addParticle( q1 );
    evt->addParticle( q2 );
    evt->addParticle( wp_p );
    evt->addParticle( wp_n );
    evt->addParticle( wpp_d1 );
    evt->addParticle( wpp_d2 );
    evt->addParticle( wpn_d1 );
    evt->addParticle( wpn_d2 );

    // cout << "event BEFORE decays:"<<endl;
    // evt->print();

    evt->decayTaus();

    // cout << "event AFTER decays:"<<endl;
    // evt->print();

 


    int tau1_decaymode = 0 ; //0h , 1e ,2m
    int tau2_decaymode = 0 ; //0h , 1e ,2m
    TLorentzVector vtau_1;
    TLorentzVector vtau_2;

    for(int tdi = 0 ; tdi < wpp_d1->getDaughters().size() ; tdi++){
      TauolaParticle* td =  wpp_d1->getDaughters()[tdi] ;
      switch( td->getPdgID() ){
      case 11:
      case -11:
	tau1_decaymode = 1;
	vtau_1.SetXYZT( td->getPx() , td->getPy() , td->getPz() , td->getE() );
	break;
      case 13:
      case -13:
	tau1_decaymode = 2;
	vtau_1.SetXYZT( td->getPx() , td->getPy() , td->getPz() , td->getE() );
	break;
      }
    }
    if( tau1_decaymode == 0 )
      for(int tdi = 0 ; tdi < wpp_d1->getDaughters().size() ; tdi++){
	TauolaParticle* td =  wpp_d1->getDaughters()[tdi] ;
	if(abs(td->getPdgID()) == 16 )
	  vtau_1.SetXYZT( wpp_d1->getPx() - td->getPx() , wpp_d1->getPy() - td->getPy() , wpp_d1->getPz() - td->getPz() , wpp_d1->getE() - td->getE() );
      }

    for(int tdi = 0 ; tdi < wpn_d1->getDaughters().size() ; tdi++){
      TauolaParticle* td =  wpn_d1->getDaughters()[tdi] ;
      switch( td->getPdgID() ){
      case 11:
      case -11:
	tau2_decaymode = 1;
	vtau_2.SetXYZT( td->getPx() , td->getPy() , td->getPz() , td->getE() );
	break;
      case 13:
      case -13:
	tau2_decaymode = 2;
	vtau_2.SetXYZT( td->getPx() , td->getPy() , td->getPz() , td->getE() );
	break;
      }
    }
    if( tau2_decaymode == 0 )
      for(int tdi = 0 ; tdi < wpn_d1->getDaughters().size() ; tdi++){
	TauolaParticle* td =  wpn_d1->getDaughters()[tdi] ;
	if(abs(td->getPdgID()) == 16 )
	  vtau_2.SetXYZT( wpn_d1->getPx() - td->getPx() , wpn_d1->getPy() - td->getPy() , wpn_d1->getPz() - td->getPz() , wpn_d1->getE() - td->getE() );
      }



    double w = 1.0;

    int DecayMode = 0 ; // 1 : had-had , 2 : el-had , 3 : mu-had

    if( tau1_decaymode == 0 && tau2_decaymode == 0 )
      DecayMode = 1;
    else if( tau1_decaymode+tau2_decaymode == 1 )
      DecayMode = 2;
    else if( ( tau1_decaymode == 2 && tau2_decaymode == 0 ) || (tau1_decaymode == 0 && tau2_decaymode == 2 ) )
      DecayMode = 3;
    else
      continue;


    TLorentzVector met =(-(vtau_1 + vtau_2) );
    TLorentzVector tauSystem = vtau_1 + vtau_2 ;
    double systemMass = tauSystem.M();

    if( DecayMode == 1 ){

      double tauptmax = max( vtau_1.Pt() , vtau_2.Pt() );
      double tauptmin = min( vtau_1.Pt() , vtau_2.Pt() );


     
      w *= hEffHad_TauPtMax->GetBinContent( hEffHad_TauPtMax->FindBin(tauptmax) );//table 8, 4th column
      w *= hEffHad_TauPtMin->GetBinContent( hEffHad_TauPtMin->FindBin(tauptmin) );//table 8, 5th column
      hTauPt_hadhadmax->Fill  (tauptmax) ;
      hTauPt_hadhadmin->Fill  (tauptmin) ;

      w *= hEff_MET->GetBinContent( hEff_MET->FindBin( met.Pt() ) );//table 9
      hMET_hadhad->Fill( met.Pt());
       
      w *= hEffHad_hEff_M->GetBinContent( hEffHad_hEff_M->FindBin( tauSystem.M()) );//table 10, last column

      double pa[3];
      double pb[3];
      double pmiss[3];
      pmiss[0] = 0;
      pmiss[1] = static_cast<double>  (met.Px());
      pmiss[2] = static_cast<double> (met.Py());
      pa[0] = static_cast<double> (0);
      pa[1] = static_cast<double> (vtau_1.Px());
      pa[2] = static_cast<double> (vtau_1.Py());
  
      pb[0] = static_cast<double> (0);
      pb[1] = static_cast<double> (vtau_2.Px());
      pb[2] = static_cast<double> (vtau_2.Py());
  

      mt2->set_momenta(pa, pb, pmiss);
      mt2->set_mn(0);
      Float_t MT2=mt2->get_mt2();
       
      w *= hEffHad_h2Eff_Mt2->GetBinContent( hEffHad_h2Eff_Mt2->FindBin( (MT2)));//table 13
      hMT2_hadhad->Fill(MT2);

      double tau1m = vtau_1.M();
      double tau2m = vtau_2.M();
      double tau1et = sqrt( vtau_1.Pt()*vtau_1.Pt() + tau1m*tau1m );
      double tau2et = sqrt( vtau_2.Pt()*vtau_2.Pt() + tau2m*tau2m );
      double tau1Mt = sqrt( tau1m*tau1m + 2*(tau1et*met.Pt() - vtau_1.Px()*met.Px() - vtau_1.Py()*met.Py() ) );
      double tau2Mt = sqrt( tau2m*tau2m + 2*(tau2et*met.Pt() - vtau_2.Px()*met.Px() - vtau_2.Py()*met.Py() ) );
      double sumMt = tau1Mt + tau2Mt ;
      w *= hEffsigmaHad_hEffMT->GetBinContent( hEffsigmaHad_hEffMT->FindBin( (tau1Mt+tau2Mt)));//table 14
      

      sumWeightsSR2 += w;
    }


 
    if(DecayMode == 1 ){
      w = 1.0;
      
      double tauptmax = max( vtau_1.Pt() , vtau_2.Pt() );
      double tauptmin = min( vtau_1.Pt() , vtau_2.Pt() );
      
  
      w *= hEffHad_TauPtMax->GetBinContent( hEffHad_TauPtMax->FindBin(tauptmax) );//table 8, 4th column
      w *= hEffHad_TauPtMin->GetBinContent( hEffHad_TauPtMin->FindBin(tauptmin) );//table 8, 5th column
     
      w *= hEff_MET->GetBinContent( hEff_MET->FindBin( met.Pt() ) );//table 9
       
      w *= hEffHad_hEff_M->GetBinContent( hEffHad_hEff_M->FindBin( tauSystem.M()) );//table 10, last column

      double pa[3];
      double pb[3];
      double pmiss[3];
      pmiss[0] = 0;
      pmiss[1] = static_cast<double>  (met.Px());
      pmiss[2] = static_cast<double> (met.Py());
      pa[0] = static_cast<double> (0);
      pa[1] = static_cast<double> (vtau_1.Px());
      pa[2] = static_cast<double> (vtau_1.Py());
  
      pb[0] = static_cast<double> (0);
      pb[1] = static_cast<double> (vtau_2.Px());
      pb[2] = static_cast<double> (vtau_2.Py());
  

      mt2->set_momenta(pa, pb, pmiss);
      mt2->set_mn(0);
      Float_t MT2=mt2->get_mt2();
     
      w *= hEffHad_h1Eff_Mt2->GetBinContent( hEffHad_h1Eff_Mt2->FindBin( (MT2)));//table 11, 3rd column

      sumWeightsSR1 += w;
    }  

    if( DecayMode == 2 ){
      w = 1.0;

      TLorentzVector vele( tau1_decaymode == 1 ? vtau_1 : vtau_2 );
      TLorentzVector vtau( tau2_decaymode == 1 ? vtau_1 : vtau_2 );

      
     
      w *= hEff_El_Pt->GetBinContent( hEff_El_Pt->FindBin( vele.Pt() ) );//table 8, 2nd column
      w *= hEff_lTau_HadTau_Pt->GetBinContent( hEff_lTau_HadTau_Pt->FindBin( vtau.Pt() ) );//table 8, 4th column
      hTauPt_lhad->Fill (vtau.Pt());
      hTauPt_ll->Fill (vele.Pt());

      w *= hEff_MET->GetBinContent( hEff_MET->FindBin( met.Pt() ) );//table 9
      hMET_lhad->Fill( met.Pt() );
    
      w *= hEffHad_l_M->GetBinContent( hEffHad_l_M->FindBin( tauSystem.M()) );//table 10, 2nd column

      double pa[3];
      double pb[3];
      double pmiss[3];
      pmiss[0] = 0;
      pmiss[1] = static_cast<double>  (met.Px());
      pmiss[2] = static_cast<double> (met.Py());
      pa[0] = static_cast<double> (0);
      pa[1] = static_cast<double> (vtau_1.Px());
      pa[2] = static_cast<double> (vtau_1.Py());
  
      pb[0] = static_cast<double> (0);
      pb[1] = static_cast<double> (vtau_2.Px());
      pb[2] = static_cast<double> (vtau_2.Py());
  

      mt2->set_momenta(pa, pb, pmiss);
      mt2->set_mn(0);
      Float_t MT2=mt2->get_mt2();
      w *= hEffHad_lEff_Mt2->GetBinContent( hEffHad_lEff_Mt2->FindBin ((MT2)));//table 11, 2nd column

      hMT2_lhad->Fill(MT2);

      double taum  = vtau.M();
      double tauet = sqrt( vtau.Pt()*vtau.Pt() + taum*taum );
      double tauMt = sqrt( taum*taum + 2*(tauet*met.Pt() - vtau.Px()*met.Px() - vtau.Py()*met.Py() ) );
      w *= hEffHad_lEffMT->GetBinContent( hEffHad_lEffMT->FindBin( tauMt));//table 12, second column

      sumWeightsEleTau += w;
    }

 
    if( DecayMode == 3 ){
      w = 1.0;
      
      TLorentzVector vmuo( tau1_decaymode == 2 ? vtau_1 : vtau_2 );
      TLorentzVector vtau( tau2_decaymode == 2 ? vtau_1 : vtau_2 );
      
      

      w *= hEff_Mu_Pt->GetBinContent( hEff_Mu_Pt->FindBin(vmuo.Pt() ) );//table 8, 3rd column
      w *= hEff_lTau_HadTau_Pt->GetBinContent( hEff_lTau_HadTau_Pt->FindBin( vtau.Pt() ) );//table 8, 4th column
      hTauPt_lhad->Fill (vtau.Pt());
      hTauPt_ll->Fill (vmuo.Pt());      
      
      w *= hEff_MET->GetBinContent( hEff_MET->FindBin( met.Pt() ) );//table 9
      hMET_lhad->Fill( met.Pt() );
             
      w *= hEffHad_l_M->GetBinContent( hEffHad_l_M->FindBin( tauSystem.M()) );//table 10, 2nd column
       
      double pa[3];
      double pb[3];;
      double pmiss[3];
      pmiss[0] = 0;
      pmiss[1] = static_cast<double>  (met.Px());
      pmiss[2] = static_cast<double> (met.Py());
      pa[0] = static_cast<double> (0);
      pa[1] = static_cast<double> (vtau_1.Px());
      pa[2] = static_cast<double> (vtau_1.Py());
      
      pb[0] = static_cast<double> (0);
      pb[1] = static_cast<double> (vtau_2.Px());
      pb[2] = static_cast<double> (vtau_2.Py());
  
      mt2->set_momenta(pa, pb, pmiss);
      mt2->set_mn(0);
      Float_t MT2=mt2->get_mt2();

      w *= hEffHad_lEff_Mt2->GetBinContent( hEffHad_lEff_Mt2->FindBin( (MT2)));//table 11, 2nd column

      hMT2_lhad->Fill(MT2);

      double taum = vtau.M();
      double tauet = sqrt( vtau.Pt()*vtau.Pt() + taum*taum );
      double tauMt = sqrt( taum*taum + 2*(tauet*met.Pt() - vtau.Px()*met.Px() - vtau.Py()*met.Py() ) );
      
      w *= hEffHad_lEffMT->GetBinContent( hEffHad_lEffMT->FindBin(tauMt));//table 12, second column
      sumWeightsMuTau += w;
    }
    // char file[100];
    // fprintf(file, "gSMHalf/tree_gSMHalfwp%I.root",MassInd);
    TFile* fout = new TFile("gSMTheta60/tree_gta60" + TString::Itoa(MassInd,10) + ".root", "RECREATE");
    //TFile* fout = new TFile("gSMHalf/tree_gSMHalf_wp160.root" , "RECREATE",0,0);
    //TFile* fout = new TFile(file, "RECREATE",0,0);
    hTauPt_hadhadmax->SetLineColor(kRed);
    hTauPt_hadhadmin->SetLineColor(kRed);
    hTauPt_ll->SetLineColor(kRed);
    hTauPt_lhad->SetLineColor(kRed);

    hMET_hadhad->SetLineColor(kRed);
    hMET_lhad->SetLineColor(kRed);

    hMT2_hadhad->SetLineColor(kRed);
    hMT2_lhad->SetLineColor(kRed);

    hTauPt_hadhadmax->Draw();
    hTauPt_hadhadmin->Draw();
    hTauPt_lhad->Draw();
    hTauPt_ll->Draw();
    hTauPt_hadhadmax->Write();
    hTauPt_hadhadmin->Write();
    hTauPt_lhad->Write();
    hTauPt_ll->Write();

    hMET_lhad->Draw();
    hMET_hadhad->Draw();
    hMET_lhad->Write();
    hMET_hadhad->Write();

    hMT2_lhad->Draw();
    hMT2_hadhad->Draw();
    hMT2_lhad->Write();
    hMT2_hadhad->Write();

    fout->Close();
  }
  cout << "SumWeights SR1  : " << sumWeightsSR1 << " out of " << nentries << " ( efficiecny : " << 100*sumWeightsSR1/nentries << " %)" << endl; 
  cout << "SumWeights SR2  : " << sumWeightsSR2 << " out of " << nentries << " ( efficiecny : " << 100*sumWeightsSR2/nentries << " %)" << endl;
  cout << "SumWeights MuTau: " << sumWeightsMuTau << " out of " << nentries << " ( efficiecny : " << 100*sumWeightsMuTau/nentries << " %)" << endl;
  cout << "SumWeights ElTau: " << sumWeightsEleTau << " out of " << nentries << " ( efficiecny : " << 100*sumWeightsEleTau/nentries << " %)" << endl;

  cout<<MassInd<<"& "<<100*sumWeightsSR1/nentries<< "\\%& "<<100*sumWeightsSR2/nentries<<"\\%& "<<100*sumWeightsMuTau/nentries <<"\\%& "<<100*sumWeightsEleTau/nentries<<"\\%\\\\ "<<endl;
  
}



/** Example of using Tauola to decay taus stored in HEPEVT-like event record */
int main(){
  
  //These three lines are not really necessary since they are the default
  Tauola::setDecayingParticle(15);
  Tauola::setSameParticleDecayMode(0);
  Tauola::setOppositeParticleDecayMode(0);
  
  Tauola::initialize();
  
  LHEF lhef;
  lhef.Loop();
}

