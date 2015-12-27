#define LHEF_cxx
#include "LHEF.h"
#include "Davismt2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>



void LHEF::Loop()
{
  //   In a ROOT session, you can do:
  //      Root > .L LHEF.C
  //      Root > LHEF t
  //      Root > t.GetEntry(12); // Fill t data members with entry number 12
  //      Root > t.Show();       // Show values of entry 12
  //      Root > t.Show(16);     // Read and show values of entry 16
  //      Root > t.Loop();       // Loop on all entries
  //

  //     This is the loop skeleton where:
  //    jentry is the global entry number in the chain
  //    ientry is the entry number in the current Tree
  //  Note that the argument to GetEntry must be:
  //    jentry for TChain::GetEntry
  //    ientry for TTree::GetEntry and TBranch::GetEntry
  //
  //       To read only selected branches, Insert statements like:
  // METHOD1:
  //    fChain->SetBranchStatus("*",0);  // disable all branches
  //    fChain->SetBranchStatus("branchname",1);  // activate branchname
  // METHOD2: replace line
  //    fChain->GetEntry(jentry);       //read all branches
  //by  b_branchname->GetEntry(ientry); //read only this branch
  
  double sumWeights = 0.0; 
  
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

    TLorentzVector vtau_1;
    TLorentzVector vtau_2;

    TLorentzVector vneutrino;
    TLorentzVector vanti_neutrino;

    for(int p = 0 ; p < Event_Nparticles[0] ; p++){
      if( Particle_PID[p] == 15 ){
  
	vtau_1.SetXYZT( Particle_Px[p] , Particle_Py[p] , Particle_Pz[p] , Particle_E[p]);
      }
      if(  Particle_PID[p] == -15 ){
	vtau_2.SetXYZT( Particle_Px[p] , Particle_Py[p] , Particle_Pz[p] , Particle_E[p]);
      }

      if(  Particle_PID[p] == 16 ){
	vneutrino.SetXYZT( Particle_Px[p] , Particle_Py[p] , Particle_Pz[p] , Particle_E[p]);
      }
      if(  Particle_PID[p] == -16 ){
	vanti_neutrino.SetXYZT( Particle_Px[p] , Particle_Py[p] , Particle_Pz[p] , Particle_E[p]);
      }

    }

    double w = 1.0;

    int DecayMode = 1 ; // 1 : had-had , 2 : el-had , 3 : mu-had
    

    // if( fabs(vtau_1.Eta()) > 2.1 )
    //   continue;
    // if( fabs(vtau_2.Eta()) > 2.1 )
    //   continue;

    if( DecayMode == 1 ){

    double tauptmax = max( vtau_1.Pt() , vtau_2.Pt() );
    double tauptmin = min( vtau_1.Pt() , vtau_2.Pt() );
    w *= hEffHad_TauPtMax->GetBinContent( hEffHad_TauPtMax->FindBin(tauptmax) );
    w *= hEffHad_TauPtMin->GetBinContent( hEffHad_TauPtMin->FindBin(tauptmin) );
    
 
    TLorentzVector met = ( vneutrino + vanti_neutrino );
    w *= hEffHad_hEff_MET->GetBinContent( hEffHad_hEff_MET->FindBin( met.Pt() ) );


    TLorentzVector tauSystem = vtau_1 + vtau_2 ;
    double systemMass = tauSystem.M();
    w *= hEffHad_hEff_M->GetBinContent( hEffHad_hEff_M->FindBin( tauSystem.M()) );

    double tau1m = vtau_1.M();
    double tau2m = vtau_2.M();
    double tau1et = sqrt( vtau_1.Pt()*vtau_1.Pt() + tau1m*tau1m );
    double tau2et = sqrt( vtau_2.Pt()*vtau_2.Pt() + tau2m*tau2m );
    double tau1Mt = sqrt( tau1m*tau1m + 2*(tau1et*met.Pt() - vtau_1.Px()*met.Px() - vtau_1.Py()*met.Py() ) );
    double tau2Mt = sqrt( tau2m*tau2m + 2*(tau2et*met.Pt() - vtau_2.Px()*met.Px() - vtau_2.Py()*met.Py() ) );
    double sumMt = tau1Mt + tau2Mt ;
    w *= hEffHad_hEffMT->GetBinContent( hEffHad_hEffMT->FindBin( (tau1Mt+tau2Mt)));
    

    }

    sumWeights += w;
    
  }
  
  cout << "SumWeights : " << sumWeights << " out of " << nentries << " ( efficiecny : " << 100*sumWeights/nentries << " %)" << endl;
  
}
