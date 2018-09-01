//This code calculates the  observed limits, exclusion and  its uncertainties.
#include "iostream"
#include <TH1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLimitDataSource.h>
#include <TConfidenceLevel.h>
#include <TLimit.h>

using namespace std;

void Limit(int massindex){


  
  // g_R=0 , g_L= g_{SM} = 0.65
  // const int NoOfPoints = 11;
  // int wpMasses[NoOfPoints] = {100,130,160,190,220,250,280,310,340,370,400};//XSec in fb 
  // double SignalXSec[NoOfPoints] = {929, 315, 130, 59.7, 28.0, 14.1, 7.68, 4.43, 2.67,  1.67, 1.08};
  // double SR1SignalEff[NoOfPoints] = {0.0379751, 0.154663, 0.354395, 0.658262 , 0.972755, 1.32546, 1.66713, 1.99265, 2.2922, 2.58878, 2.87068};//Eff in percent must be mulitiplied by 0.01
  // double SR2SignalEff[NoOfPoints] = {0.462838, 0.623578, 0.729301, 0.807349, 0.850829, 0.898142, 0.918439, 0.914542, 0.926687, 0.911694, 0.911545};
  // double muTauSignalEff[NoOfPoints] = {0.00404094, 0.0258567, 0.0768502, 0.185076, 0.344936, 0.522344, 0.743787, 0.970375, 1.20054, 1.44506, 1.66933};
  // double eleTauSignalEff[NoOfPoints] = {0.003593, 0.0172164, 0.0649245, 0.157442, 0.298101, 0.44767, 0.623895, 0.853668, 1.02897, 1.25585, 1.44915};

  // g_R=0 , g_L=g_{SM}/2 =0.32
  // const int NoOfPoints = 14;
  // int wpMasses[NoOfPoints] = {10, 40, 70, 100,130,160,190,220,250,280,310,340,370,400};
  // double SignalXSec[NoOfPoints] = {432000, 2150, 242, 58.1, 19.7, 8.16, 3.72, 1.75, 0.885, 0.482, 0.278, 0.168, 0.105, 0.0678};//XSec in fb 
  // double SR1SignalEff[NoOfPoints] = {0.0,0.0028236, 0.00919168, 0.0345377, 0.15893, 0.368314, 0.62216, 0.948005, 1.27376, 1.65801, 1.93526, 2.2478, 2.54731, 2.85855};//Eff in percent must be mulitiplied by 0.01
  // double SR2SignalEff[NoOfPoints] = {0.0762914, 0.122778, 0.280796, 0.466139, 0.624427, 0.727216, 0.80706, 0.865473, 0.915664, 0.925479, 0.916426, 0.903645, 0.886463, 0.886657};
  // double muTauSignalEff[NoOfPoints] = {0, 0.000103397, 0.000783301, 0.00454572, 0.0255106, 0.0837797, 0.203787, 0.352325, 0.539323, 0.777479, 0.99158, 1.21943, 1.53535, 1.75473};
  // double eleTauSignalEff[NoOfPoints] = {0.0, 9.10524e-05, 0.000661304, 0.00469618, 0.0198486, 0.0735631, 0.148178, 0.28512, 0.445757, 0.630866, 0.838777, 1.03899, 1.27345, 1.4878};

  // g_R=0 , g_L=1.5 * g_{SM} =0.96
  const int NoOfPoints = 14;
  int wpMasses[NoOfPoints] = {100,130,160,190,220,250,280,310,340,370,400, 430, 460, 490};
  double SignalXSec[NoOfPoints] = {4410, 1500, 618, 284, 132, 67.1, 36.3, 21.0, 12.0, 7.48, 5.11, 3.33, 2.29, 1.52};//XSec in fb 
  double SR1SignalEff[NoOfPoints] = {0.0386288, 0.163603, 0.352132, 0.636463, 0.964389, 1.28343, 1.59721, 1.91734, 2.20466, 2.53987, 2.81811, 3.11286, 3.22499, 3.61958};
  double SR2SignalEff[NoOfPoints] = {0.445375, 0.600979, 0.699415, 0.788807, 0.832831, 0.879037, 0.885904, 0.924166, 0.91485, 0.888721, 0.872968, 0.87605, 0.852219, 0.880012};
  double muTauSignalEff[NoOfPoints] = {0.00560499, 0.0182618, 0.08994, 0.172166, 0.355963, 0.514521, 0.766945, 1.00774, 1.21469, 1.54151, 1.69623, 1.97975, 2.22211, 2.20792};
  double eleTauSignalEff[NoOfPoints] = {0.00294153, 0.0243421, 0.0706265, 0.167566, 0.279967, 0.435443, 0.602507, 0.89846, 1.05288, 1.22226, 1.43933, 1.6421, 1.8821, 2.05626};

  // g_R=0.32 , g_L=0.56 \theta = 30
  // const int NoOfPoints = 11;
  // int wpMasses[NoOfPoints] = {100,130,160,190,220,250,280,310,340,370,400};
  // double SignalXSec[NoOfPoints] = {386.8, 131.1, 54.35, 24.64, 11.39, 5.713, 3.104, 1.781, 1.073, 0.6701, 0.4320};//XSec in fb 
  // double SR1SignalEff[NoOfPoints] = {0.033608, 0.14014, 0.357321, 0.625591, 0.9845, 1.30926, 1.64447, 1.97527, 2.22767, 2.54287, 2.81958};
  // double SR2SignalEff[NoOfPoints] = {0.461249, 0.603185, 0.707703, 0.800132, 0.859147, 0.903036, 0.907284, 0.907188, 0.935574, 0.910357, 0.865802};
  // double muTauSignalEff[NoOfPoints] = {0.00370257, 0.0234032, 0.0887572, 0.208677, 0.364947, 0.556638, 0.786534, 0.992823, 1.25061, 1.53093, 1.73399};
  // double eleTauSignalEff[NoOfPoints] = {0.00321656, 0.0223469, 0.0749057, 0.153876, 0.292647, 0.471289, 0.644953, 0.822228, 1.0192, 1.22167, 1.43768};

  // // g_R=0.46 , g_L=0.46 \theta = 45
  // const int NoOfPoints = 14;
  // int wpMasses[NoOfPoints] = {10, 40, 70, 100,130,160,190,220,250,280,310,340,370,400};
  // double SignalXSec[NoOfPoints] = {1180370, 6155.1, 695.4, 166.6, 56.65, 23.43, 10.61, 4.852, 2.415, 1.297, 0.7422, 0.4454, 0.2778, 0.1791};//XSec in fb 
  // double SR1SignalEff[NoOfPoints] = {0, 0.00285615, 0.00871512, 0.0340024, 0.153406, 0.364502, 0.652278, 0.933457, 1.33292, 1.67456, 1.97841, 2.22473, 2.57298, 2.87597};
  // double SR2SignalEff[NoOfPoints] = {0.074251, 0.12034, 0.266957, 0.449497, 0.62229, 0.723609, 0.815322, 0.869257, 0.912923, 0.896985, 0.959325, 0.924947, 0.923597, 0.913171};
  // double muTauSignalEff[NoOfPoints] = {0, 9.11778e-05, 0.000705422, 0.0055887, 0.0251504, 0.0811364, 0.194501, 0.348398, 0.570482, 0.787179, 0.973748, 1.24593, 1.4692, 1.7245};
  // double eleTauSignalEff[NoOfPoints] = {0, 7.94554e-05, 0.000821552, 0.00277501, 0.0212106, 0.0554376, 0.155277, 0.282581, 0.45119, 0.621461, 0.835509, 1.05895, 1.28732, 1.44771};
  
 // g_R=0.56 , g_L=0.32 \theta = 60
  // const int NoOfPoints = 14;
  // int wpMasses[NoOfPoints] = {10, 40, 70, 100,130,160,190,220,250,280,310,340,370,400};
  // double SignalXSec[NoOfPoints] = {461395, 2387, 268.98, 64.41, 21.86, 9.072, 4.077, 1.846, 0.9082, 0.4837, 0.2749, 0.1643, 0.1025, 0.06575};//XSec in fb 
  // double SR1SignalEff[NoOfPoints] = {0, 0.00281166, 0.00906904, 0.0335185, 0.157006, 0.360138, 0.647787, 0.990703, 1.30039, 1.66359, 1.99261, 2.23947, 2.56543, 2.91588};
  // double SR2SignalEff[NoOfPoints] = {0.0730116, 0.123918, 0.270709, 0.450079, 0.620562, 0.754883, 0.82604, 0.854859, 0.905802, 0.92026, 0.953489, 0.980384, 0.917449, 0.91147};
  // double muTauSignalEff[NoOfPoints] = {0, 0.000121224, 0.000736552, 0.00671611, 0.019821, 0.0838412, 0.190401, 0.35944, 0.504099, 0.752807, 1.02783, 1.22866, 1.49769, 1.76612};
  // double eleTauSignalEff[NoOfPoints] = {0, 6.15145e-05, 0.000564453, 0.00345025, 0.0192161, 0.0652481, 0.155307, 0.267376, 0.444503, 0.639239, 0.843597, 1.04877, 1.26401, 1.4732};

  double leptonTauIL = 19.6; //Invfb
  double tauTauIL = 18.1; //Invfb

  double muTauSignals[NoOfPoints] = {0.0};
  double eleTauSignals[NoOfPoints] = {0.0};
  double SR1Signals[NoOfPoints] = {0.0};
  double SR2Signals[NoOfPoints] = {0.0};

  for(int i = 0; i < NoOfPoints; i++){
    muTauSignals[i]  = 0.01 * leptonTauIL * SignalXSec[i] * muTauSignalEff[i];
    eleTauSignals[i] = 0.01 * leptonTauIL * SignalXSec[i] * eleTauSignalEff[i];
    SR1Signals[i]    = 0.01 * tauTauIL    * SignalXSec[i] * SR1SignalEff[i];
    SR2Signals[i]    = 0.01 * tauTauIL    * SignalXSec[i] * SR2SignalEff[i];
  }

  double theMass = wpMasses[massindex];
  double muTauSignal = muTauSignals[massindex];
  double eleTauSignal = eleTauSignals[massindex];
  double SR1Signal = SR1Signals[massindex];
  double SR2Signal = SR2Signals[massindex];

  TH1F *signal=new TH1F("signal","signal",4, 0., 4.);
  TH1F *bkg=new TH1F("bkg","bkg",4, 0., 4.);
  TH1F *data=new TH1F("data","data",4, 0., 4.);      

  //Bin1 muTau
  data->SetBinContent(1,5.0);
  data->SetBinError(1,sqrt(5.0));

  //Bin2 eleTau
  data->SetBinContent(2,3.0);
  data->SetBinError(2,sqrt(3.0));

  //Bin3 SR1
  data->SetBinContent(3,1.0);
  data->SetBinError(3,sqrt(1.0));

  //Bin4 SR2
  data->SetBinContent(4,2.0);
  data->SetBinError(4,sqrt(2.0));


  //Bin1 muTau bkg from PAS
  bkg->SetBinContent(1,8.59);
  bkg->SetBinError(1,(4.83));

  //Bin2 eleTau bkg from PAS
  bkg->SetBinContent(2,3.52);
  bkg->SetBinError(2,(3.39));
      
  //Bin3 SR1 bkg from PAS
  bkg->SetBinContent(3,1.58);
  bkg->SetBinError(3,(0.65));

  //Bin4 SR2 bkg from PAS
  bkg->SetBinContent(4,7.07);
  bkg->SetBinError(4,(2.25));
 
   
  float r_step = 0.0001;
  int steps = 100000;
  TH1F *cls = new TH1F("cls", "cls",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe0 = new TH1F("Expe0", "ExpectedCLs_b(0)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe_plus1 = new TH1F("Expe_plus1", "ExpectedCLs_b(1)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe_minus1 = new TH1F("Expe_minus1", "ExpectedCLs_b(-1)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
   
   
  //  for(int i = 1; i < (steps + 1); i++) {
    int i = 1;
    //Following code tries to find the sensitive range of the variable then scans that area carefully. Time consuming is almost half.

    bool Below5PerCent = false;
    bool iTwiced = false;
    bool iHalved = false;


   while(!Below5PerCent){


     //std::cout << "  r    : " << (i * r_step) << std::endl;
    signal->SetBinContent(1,muTauSignal * i * r_step);
    signal->SetBinContent(2,eleTauSignal * i * r_step);   
    signal->SetBinContent(3,SR1Signal * i * r_step);  
    signal->SetBinContent(4,SR2Signal * i * r_step);
  
    signal->SetBinError(1,0.2 * signal->GetBinContent(1)); 
    signal->SetBinError(2,0.2 * signal->GetBinContent(2)); 
    signal->SetBinError(3,0.25 * signal->GetBinContent(3));
    signal->SetBinError(4,0.25 * signal->GetBinContent(4)); 
 
    TLimitDataSource* mydatasource = new TLimitDataSource(signal,bkg,data);
    TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
    // std::cout << "  Observed CLs    : " << myconfidence->CLs()  << std::endl;
    // std::cout << "  Expected CLs_b    : " << myconfidence->GetExpectedCLs_b(0)  << std::endl;
    // std::cout << "  Expected+1 CLs_b   : " << myconfidence->GetExpectedCLs_b(1) << std::endl;
    // std::cout << "  Expected-1 CLs_b    : " << myconfidence->GetExpectedCLs_b(-1)  << std::endl;


    float observed = myconfidence->CLs();
    float expected = myconfidence->GetExpectedCLs_b(0);
    float expected_Plus1 = myconfidence->GetExpectedCLs_b(1);
    float expected_Minus1 = myconfidence->GetExpectedCLs_b(-1);

    int binNumber = cls->FindBin(i * r_step);
    cls->SetBinContent(binNumber, observed);
    Expe_plus1->SetBinContent(binNumber, expected_Plus1);
    Expe_minus1->SetBinContent(binNumber, expected_Minus1);
    Expe0->SetBinContent(binNumber, expected);

    delete mydatasource;
    delete myconfidence;

    if(observed < 0.05 && expected < 0.05 && expected_Plus1 < 0.05 && expected_Minus1  < 0.05 && (i==1 || iHalved))
      Below5PerCent = true;
    else
      if((observed < 0.05 || expected < 0.05 || expected_Plus1 < 0.05 || expected_Minus1 < 0.05) && iTwiced){
	    i = i/2 + 1;
	    iTwiced = false;
	    iHalved = true;
	  }
	  else{
	    if(!iHalved){
	    i *= 2;
	    iTwiced = true;
	    }
	  }	   
    i++;
   }
   
  TFile* f = TFile::Open("clsgSM3Over2wp" + TString::Itoa(theMass,10) + ".root" , "RECREATE");
  cls->Write();
  Expe0->Write();
  Expe_plus1->Write();
  Expe_minus1->Write();
  f->Close();


  Int_t last = cls->FindLastBinAbove(0.05);
  std::cout << last << " "
	    << cls->GetBinLowEdge(last) << " "
	    << cls->GetBinWidth(last) << " "
	    << cls->GetBinCenter(last) << " "
	    << cls->GetBinContent(last) << " " << std::endl;

  last =Expe0 ->FindLastBinAbove(0.05);
  std::cout << last << " "
	    << Expe0->GetBinLowEdge(last) << " "
	    << Expe0->GetBinWidth(last) << " "
	    << Expe0->GetBinCenter(last) << " "
	    << Expe0->GetBinContent(last) << " " << std::endl;

  last =Expe_plus1 ->FindLastBinAbove(0.05);
  std::cout << last << " "
	    << Expe_plus1->GetBinLowEdge(last) << " "
	    << Expe_plus1->GetBinWidth(last) << " "
	    << Expe_plus1 ->GetBinCenter(last) << " "
	    << Expe_plus1->GetBinContent(last) << " " << std::endl;

  last = Expe_minus1->FindLastBinAbove(0.05);
  std::cout << last << " "
	    <<  Expe_minus1->GetBinLowEdge(last) << " "
	    <<  Expe_minus1->GetBinWidth(last) << " "
	    <<  Expe_minus1->GetBinCenter(last) << " "
	    <<  Expe_minus1->GetBinContent(last) << " " << std::endl;

  signal->Delete();
  bkg->Delete();
  data->Delete();
  cls->Delete();
  Expe0->Delete();
  Expe_plus1->Delete();
  Expe_minus1->Delete();

  //cls->Draw();
 
}
