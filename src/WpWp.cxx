/**
 * Example of use of tauola C++ interface.
 * e+, e- -> tau + tau - HEPEVT events are constructed.
 * Taus are subsequently decayed via tauola.
 *
 * @author Tomasz Przedzinski
 * @date 24 November 2011
 */

#include "Tauola/Tauola.h"
#include "Tauola/TauolaHEPEVTParticle.h"
#include "Tauola/TauolaHEPEVTEvent.h"

//#include "tauola_print_parameters.h"
using namespace std;
using namespace Tauolapp;

#define LHEF_cxx
#include "LHEF.h"
#include "Davismt2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>

void LHEF::Loop()
{
  double sumWeightsSR1 = 0.0; 
  double sumWeightsSR2 = 0.0; 
  double sumWeightsEleTau = 0.0; 
  double sumWeightsMuTau = 0.0; 

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;

  double EffPtBins[] = {0,10,20,30,40,60,80,120,160,200,5000};
  TH1F* hEffHad_TauPtMax = new TH1F( "hEffHad_TauPtMax" , "hEffHad_TauPtMax" , 10 , EffPtBins );
  hEffHad_TauPtMax->SetBinContent( 1 , 0.0 );
  hEffHad_TauPtMax->SetBinContent( 2 , 0.0 );
  hEffHad_TauPtMax->SetBinContent( 3 , 0.0 );
  hEffHad_TauPtMax->SetBinContent( 4 , 0.0 );
  hEffHad_TauPtMax->SetBinContent( 5 , 0.02 );
  hEffHad_TauPtMax->SetBinContent( 6 , 0.08 );
  hEffHad_TauPtMax->SetBinContent( 7 , 0.12 );
  hEffHad_TauPtMax->SetBinContent( 8 , 0.15 );
  hEffHad_TauPtMax->SetBinContent( 9 , 0.16 );
  hEffHad_TauPtMax->SetBinContent( 10 , 0.17 );
 
  TH1F* hEffHad_TauPtMin = new TH1F( "hEffHad_TauPtMin" , "hEffHad_TauPtMin" , 10 , EffPtBins );
  hEffHad_TauPtMin->SetBinContent( 1 , 0.52 );
  hEffHad_TauPtMin->SetBinContent( 2 , 0.54 );
  hEffHad_TauPtMin->SetBinContent( 3 , 0.56 );
  hEffHad_TauPtMin->SetBinContent( 4 , 0.55 );
  hEffHad_TauPtMin->SetBinContent( 5 , 0.61 );
  hEffHad_TauPtMin->SetBinContent( 6 , 0.69 );
  hEffHad_TauPtMin->SetBinContent( 7 , 0.70 );
  hEffHad_TauPtMin->SetBinContent( 8 , 0.70 );
  hEffHad_TauPtMin->SetBinContent( 9 , 0.71 );
  hEffHad_TauPtMin->SetBinContent( 10 , 0.71 );
  

  double EffMTBins[] = {0,50,100,125,150,170,190,210,230,250,275,300,5000};
  TH1F* hEffHad_hEffMT = new TH1F( "hEff_MT" , "hEff_MT" , 12 , EffMTBins );
  hEffHad_hEffMT->SetBinContent( 1 , 0.35 );
  hEffHad_hEffMT->SetBinContent( 2 , 0.1 );
  hEffHad_hEffMT->SetBinContent( 3 , 0.05 );
  hEffHad_hEffMT->SetBinContent( 4 , 0.07 );
  hEffHad_hEffMT->SetBinContent( 5 , 0.14 );
  hEffHad_hEffMT->SetBinContent( 6 , 0.32 );
  hEffHad_hEffMT->SetBinContent( 7 , 0.55 );
  hEffHad_hEffMT->SetBinContent( 8 , 0.68 );
  hEffHad_hEffMT->SetBinContent( 9 , 0.83 );
  hEffHad_hEffMT->SetBinContent( 10 , 0.91);
  hEffHad_hEffMT->SetBinContent( 11 , 0.95);
  hEffHad_hEffMT->SetBinContent( 12 , 0.97);
 
  // TH1F* hEff_El = new TH1F( "hEff_El" , "hEff_El" , 10 , EffPtBins );
  // TH1F* hEff_Mu = new TH1F( "hEff_Mu" , "hEff_Mu" , 10 , EffPtBins );

  double EffMETBins[] = {0,10,20,30,40,50,60,70,80,90,100,120,140,160,200,5000};
  TH1F* hEffHad_hEff_MET = new TH1F( "hEff_MET" , "hEff_MET" , 15 , EffMETBins );
  hEffHad_hEff_MET->SetBinContent( 1 , 0.52 );
  hEffHad_hEff_MET->SetBinContent( 2 , 0.57 );
  hEffHad_hEff_MET->SetBinContent( 3 , 0.68 );
  hEffHad_hEff_MET->SetBinContent( 4 , 0.79 );
  hEffHad_hEff_MET->SetBinContent( 5 , 0.87 );
  hEffHad_hEff_MET->SetBinContent( 6 , 0.93 );
  hEffHad_hEff_MET->SetBinContent( 7 , 0.95 );
  hEffHad_hEff_MET->SetBinContent( 8 , 0.97 );
  hEffHad_hEff_MET->SetBinContent( 9 , 0.98 );
  hEffHad_hEff_MET->SetBinContent( 10 , 0.98 );
  hEffHad_hEff_MET->SetBinContent( 11 , 0.99 );
  hEffHad_hEff_MET->SetBinContent( 12 , 0.99 );
  hEffHad_hEff_MET->SetBinContent( 13 , 0.99 );
  hEffHad_hEff_MET->SetBinContent( 14 , 1 );
  hEffHad_hEff_MET->SetBinContent( 15 , 1 );
  
  double EffMBins[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,115,5000};
   TH1F* hEffHad_hEff_M = new TH1F( "hEff_M" , "hEff_M" , 22 , EffMBins );
  hEffHad_hEff_M->SetBinContent( 1 , 0.52 );
  hEffHad_hEff_M->SetBinContent( 2 , 0.57 );
  hEffHad_hEff_M->SetBinContent( 3 , 0.68 );
  hEffHad_hEff_M->SetBinContent( 4 , 0.79 );
  hEffHad_hEff_M->SetBinContent( 5 , 0.87 );
  hEffHad_hEff_M->SetBinContent( 6 , 0.93 );
  hEffHad_hEff_M->SetBinContent( 7 , 0.95 );
  hEffHad_hEff_M->SetBinContent( 8 , 0.97 );
  hEffHad_hEff_M->SetBinContent( 9 , 0.98 );
  hEffHad_hEff_M->SetBinContent( 10 , 0.98 );
  hEffHad_hEff_M->SetBinContent( 11 , 0.99 );
  hEffHad_hEff_M->SetBinContent( 12 , 0.99 );
  hEffHad_hEff_M->SetBinContent( 13 , 0.99 );
  hEffHad_hEff_M->SetBinContent( 14 , 1 );
  hEffHad_hEff_M->SetBinContent( 15 , 1 );
  

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


    TLorentzVector met = -( vtau_1 + vtau_2 );
    TLorentzVector tauSystem = vtau_1 + vtau_2 ;
    double systemMass = tauSystem.M();

    // if( fabs(vtau_1.Eta()) > 2.1 )
    //   continue;
    // if( fabs(vtau_2.Eta()) > 2.1 )
    //   continue;

    if( DecayMode == 1 ){

      double tauptmax = max( vtau_1.Pt() , vtau_2.Pt() );
      double tauptmin = min( vtau_1.Pt() , vtau_2.Pt() );
      w *= hEffHad_TauPtMax->GetBinContent( hEffHad_TauPtMax->FindBin(tauptmax) );
      w *= hEffHad_TauPtMin->GetBinContent( hEffHad_TauPtMin->FindBin(tauptmin) );
      w *= hEffHad_hEff_MET->GetBinContent( hEffHad_hEff_MET->FindBin( met.Pt() ) );
      w *= hEffHad_hEff_M->GetBinContent( hEffHad_hEff_M->FindBin( tauSystem.M()) );

      double tau1m = vtau_1.M();
      double tau2m = vtau_2.M();
      double tau1et = sqrt( vtau_1.Pt()*vtau_1.Pt() + tau1m*tau1m );
      double tau2et = sqrt( vtau_2.Pt()*vtau_2.Pt() + tau2m*tau2m );
      double tau1Mt = sqrt( tau1m*tau1m + 2*(tau1et*met.Pt() - vtau_1.Px()*met.Px() - vtau_1.Py()*met.Py() ) );
      double tau2Mt = sqrt( tau2m*tau2m + 2*(tau2et*met.Pt() - vtau_2.Px()*met.Px() - vtau_2.Py()*met.Py() ) );
      double sumMt = tau1Mt + tau2Mt ;
      w *= hEffHad_hEffMT->GetBinContent( hEffHad_hEffMT->FindBin( (tau1Mt+tau2Mt)));
      sumWeightsSR2 += w;

    }
  }
  
  cout << "SumWeights : " << sumWeightsSR1 << " out of " << nentries << " ( efficiecny : " << 100*sumWeightsSR1/nentries << " %)" << endl;
  
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

