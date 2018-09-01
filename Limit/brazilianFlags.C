//A code to make the brazilian flags
void brazilianFlags(){


  TCanvas* c1 = new TCanvas("mass wp- rvalue","Mwp_r.value");
  c1->SetGrid();
  TMultiGraph *mg = new TMultiGraph();

  const Int_t n = 11;
  Float_t observed[n], expected_median[n],  expected_p1s[n], expected_m1s[n];

  float ExpectedP1M1Mean[n+1];
  float ExpectedP1M1Error[n+1];
  float WpMassP1M1_x[n+1];
  float WpMassP1M1_xError[n+1] = {0.0};

  //Float_t wpMasses[n] = {100,130,160,190,220,250,280,310,340,370,400};//gSM, 30^\circ

  //Float_t wpMasses[n] = {10,40,70,100,130,160,190,220,250,280,310};//gSM/2, 45^\circ and 60^\circ
  Float_t wpMasses[n] = {190,220,250,280,310,340,370,400,430,460,490};//1.5gSM

  for(int i = 0 ; i< n ; i++){
    int theMass = int(wpMasses[i]);
    TFile* f = TFile::Open("clsgSM3Over2wp" + TString::Itoa(theMass,10) + ".root" );

    TH1 *cls = (TH1*)(f->Get("cls"));
    observed[i] = cls->GetBinCenter( cls->FindLastBinAbove(0.05) );
    
    TH1 *Expe0 = (TH1*)(f->Get("Expe0"));
    expected_median[i] = Expe0->GetBinCenter( Expe0->FindLastBinAbove(0.05) );
    
    TH1 *Expe_plus1 = (TH1*)(f->Get("Expe_plus1"));
    expected_p1s[i] = Expe_plus1->GetBinCenter( Expe_plus1->FindLastBinAbove(0.05) );
    
    TH1 *Expe_minus1 = (TH1*)(f->Get("Expe_minus1"));
    expected_m1s[i] = Expe_minus1->GetBinCenter( Expe_minus1->FindLastBinAbove(0.05) );
    
    WpMassP1M1_x[i] = wpMasses[i];
    
    ExpectedP1M1Mean[i] = 0.5 * (expected_p1s[i] + expected_m1s[i]);
 
    ExpectedP1M1Error[i] = 0.5 * (expected_p1s[i] - expected_m1s[i]);
    
    f->Close();
  }

  WpMassP1M1_x[n] = wpMasses[n-1] + 20.0;

  ExpectedP1M1Mean[n] = ExpectedP1M1Mean[n-1];

  ExpectedP1M1Error[n] = ExpectedP1M1Error[n-1];
  
  TGraph *gr_observed = new TGraph(n,wpMasses,observed);
  gr_observed->SetTitle("Observed");
  gr_observed->SetLineColor(kBlue);
  gr_observed->SetLineWidth(4);

  TGraph *gr_expM = new TGraph(n, wpMasses , expected_median );
  gr_expM->SetTitle("Expected");
  gr_expM->SetLineColor( kBlue );
  gr_expM->SetLineColor(kRed);
  gr_expM->SetLineWidth(4);
  gr_expM->SetLineStyle(2);

  TGraph *gr_expP1 = new TGraph(n, wpMasses , expected_p1s );
  gr_expP1->SetTitle("Exp+1#sigma");
  gr_expP1->SetLineColor(kYellow);
  TGraph *gr_expM1 = new TGraph(n, wpMasses , expected_m1s );
  gr_expM1->SetTitle("Exp-1#sigma");
  gr_expM1->SetLineColor(kYellow);
 
  mg->Add(gr_observed);
  mg->Add(gr_expM1);
  mg->Add(gr_expM);
  mg->Add(gr_expP1);

  mg->SetTitle("TGraph m_rvalue");

  mg->Draw("AC");

  mg->GetXaxis()->SetTitle("wprime mass");
  mg->GetYaxis()->SetTitle("r_value");

  TCanvas *Exclusion2 = new TCanvas("Exclusion2","Exclusion2");
  Exclusion2->SetLogy();
  TGraphErrors *gExpectedP1M1 = new TGraphErrors(n+1, WpMassP1M1_x, ExpectedP1M1Mean,WpMassP1M1_xError, ExpectedP1M1Error);
  gExpectedP1M1->SetFillColor(3);
  gExpectedP1M1->SetLineColor(2);
  gExpectedP1M1->SetLineWidth(4);
  gExpectedP1M1->SetLineStyle(2);
  TH1F *myHisto = new TH1F("myHisto", "",11,WpMassP1M1_x[0],WpMassP1M1_x[n]);
  myHisto->SetStats(0);
  myHisto->GetXaxis()->SetRange(int(WpMassP1M1_x[0])+5, int(WpMassP1M1_x[n])-10);
  //myHisto->GetXaxis()->SetRangeUser(105,390);
  myHisto->GetYaxis()->SetRangeUser(0.05,50.0);
  myHisto->GetYaxis()->SetTitle("95% CL upper limit on  #sigma / #sigma_{pp #rightarrow W'W'}");
  myHisto->GetYaxis()->SetTitleOffset(0.8);
  myHisto->GetYaxis()->SetTitleSize(0.05);
  myHisto->GetXaxis()->SetTitle("m_{W'} (GeV)");
  myHisto->GetXaxis()->SetTitleOffset(0.8);
  myHisto->GetXaxis()->SetTitleSize(0.05);
 
  gExpectedP1M1->SetHistogram(myHisto);

  gExpectedP1M1->Draw("ap40");

  gr_observed->Draw("PC");
   
  gr_expM->Draw("PC");
   TLegend *leg = new TLegend(0.15,0.6515152,0.4,0.8572568,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.0400641);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry(gr_observed,"#frac{3}{2} g_{SM}","c");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry(gr_observed,"Observed","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry(gExpectedP1M1,"Expected #pm1 #sigma","fl");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();

   TLine *line = new TLine(WpMassP1M1_x[0], 1, WpMassP1M1_x[n-1],1);
   //TLine *line = new TLine(105, 1, 390,1);
   line->SetLineStyle(7);
   line->Draw();
}
