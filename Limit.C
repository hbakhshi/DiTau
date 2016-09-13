void Limit(int massindex){

  int wpMasses[11] = {100,130,160,190,220,250,280,310,340,370,400};

  // signals gl=standard model, gr=0 (width: fit):
  // double muTauSignals[11]  = {1.363,1.474,1.938,2.338,1.308,1.437,1.094,0.868,0.662,0.482,0.359};
  //double eleTauSignals[11] = {0.680,0.926,1.367,1.674,1.981,1.087,0.919,0.729,0.520,0.421,0.301};
  // double SR1Signals[11] = {6.042,7.160,6.153,6.339,4.285,2.284,2.128,1.524,1.031,0.767,0.524};
  //double SR2Signals[11] = {79.45,30.02,12.95,8.011,3.992,2.161,1.204,0.731,0.454,0.266,0.170};

  // gl=standard model,gr=0
  // double muTauSignals[11]  ={2.1252,2.9066,3.8896,3.0973,2.8759,2.1711,1.6137,1.2424,0.9925,0.7067,0.5323}; 
  // double eleTauSignals[11] = {0.7512,1.8331,2.1737,2.5677,2.1702,1.7727,1.3118,0.9567,0.8029,0.5993,0.4620};
  // double SR1Signals[11]    = {8.0535,10.9420,10.889,8.9778,6.4552,4.5969,3.1186,2.1858,1.5380,1.1055,0.7860};
  //double SR2Signals[11] = {107.879,47.3403,22.4841,11.4115,5.8560,3.1147,1.7703,1.0794,0.6481,0.4032,0.2566};
 
 // signals gl=1/2 standard model, gr=0 :
 // double muTauSignals[11]  = {0.1445,0.1515,0.1986,0.2177,0.1666,0.1289,0.1103,0.0745,0.0558,0.0439,0.0332};
  //double eleTauSignals[11] = {0.0523,0.1111,0.1372,0.1617,0.1252,0.1094,0.0456,0.0632,0.0488,0.0367,0.0285};
  // double SR1Signals[11] = {0.5136,0.6559,0.7115,0.5772,0.4042,0.2852,0.1934,0.1364,0.0955,0.0681,0.0508};
  //double SR2Signals[11] = {6.7623,3.07111,1.4499,0.7464,0.3785,0.1965,0.1088,0.0650,0.0403,0.0249,0.0156};
 
 // signals gl=2* standard model, gr=0 :
  double muTauSignals[11] ={49.210,48.061,59.524,57.437,44.133,32.006,24.770,18.262,13.880,9.833,8.0004};
  double eleTauSignals[11] = {18.685,38.89,43.035,41.124,36.193,26.808,21.109,14.912,11.377,8.839,6.913};
  double SR1Signals[11] = {173.603,189.92,187.78,147.46,100.963,70.385,47.079,33.423,22.828,16.380,11.847};
  double SR2Signals[11] = {1072.513,731.45,359.26,185.107,89.323,46.313,26.108,15.269,9.513,5.830,3.815};




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
 
   
  float r_step = 0.01;
  int steps = 200;
  TH1F *cls = new TH1F("cls", "cls",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe0 = new TH1F("Expe0", "ExpectedCLs_b(0)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe_plus1 = new TH1F("Expe_plus1", "ExpectedCLs_b(1)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
  TH1F *Expe_minus1 = new TH1F("Expe_minus1", "ExpectedCLs_b(-1)",  steps, (0.5 *r_step), ((0.5+ steps) *r_step));
   
   
  for(int i = 1; i < (steps + 1); i++) {
    std::cout << "  r    : " << (i * r_step) << std::endl;
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
    std::cout << "  Observed CLs    : " << myconfidence->CLs()  << std::endl;
    std::cout << "  Expected CLs_b    : " << myconfidence->GetExpectedCLs_b(0)  << std::endl;
    std::cout << "  Expected+1 CLs_b   : " << myconfidence->GetExpectedCLs_b(1) << std::endl;
    std::cout << "  Expected-1 CLs_b    : " << myconfidence->GetExpectedCLs_b(-1)  << std::endl;

    cls->Fill((i * r_step), myconfidence->CLs());
    Expe_plus1->Fill((i * r_step), myconfidence->GetExpectedCLs_b(1));
    Expe_minus1->Fill((i * r_step), myconfidence->GetExpectedCLs_b(-1));
    Expe0->Fill((i * r_step), myconfidence->GetExpectedCLs_b(0));

    delete mydatasource;
    delete myconfidence;

  }

  TFile* f = TFile::Open("wp(twice)_" + TString::Itoa(theMass,10) + ".root" , "RECREATE");
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
     
     
  //cls->Draw();
 
}
