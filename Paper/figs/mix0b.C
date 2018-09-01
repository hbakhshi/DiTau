{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Sun Aug 27 10:30:47 2017) by ROOT version5.34/07
   TCanvas *Exclusion2 = new TCanvas("Exclusion2", "Exclusion2",13,36,700,500);
   Exclusion2->Range(63.63636,-1.67603,427.2727,2.07397);
   Exclusion2->SetFillColor(0);
   Exclusion2->SetBorderMode(0);
   Exclusion2->SetBorderSize(2);
   Exclusion2->SetLogy();
   Exclusion2->SetFrameBorderMode(0);
   Exclusion2->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(12);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(3);
   gre->SetLineColor(2);
   gre->SetLineStyle(2);
   gre->SetLineWidth(4);
   gre->SetPoint(0,100,0.08865);
   gre->SetPointError(0,0,-0.02855);
   gre->SetPoint(1,130,0.17135);
   gre->SetPointError(1,0,-0.05485);
   gre->SetPoint(2,160,0.28525);
   gre->SetPointError(2,0,-0.09085);
   gre->SetPoint(3,190,0.415);
   gre->SetPointError(3,0,-0.135);
   gre->SetPoint(4,220,0.65);
   gre->SetPointError(4,0,-0.2);
   gre->SetPoint(5,250,0.975);
   gre->SetPointError(5,0,-0.325);
   gre->SetPoint(6,280,1.45);
   gre->SetPointError(6,0,-0.45);
   gre->SetPoint(7,310,2.1);
   gre->SetPointError(7,0,-0.65);
   gre->SetPoint(8,340,3.025);
   gre->SetPointError(8,0,-0.975);
   gre->SetPoint(9,370,4.25);
   gre->SetPointError(9,0,-1.35);
   gre->SetPoint(10,400,5.9);
   gre->SetPointError(10,0,-1.85);
   gre->SetPoint(11,420,5.9);
   gre->SetPointError(11,0,-1.85);
   
   TH1F *Graph_myHisto1 = new TH1F("Graph_myHisto1","",11,100,420);
   Graph_myHisto1->SetMinimum(0.05);
   Graph_myHisto1->SetMaximum(50);
   Graph_myHisto1->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_myHisto1->SetLineColor(ci);
   Graph_myHisto1->GetXaxis()->SetTitle("m_{W'} (GeV)");
   Graph_myHisto1->GetXaxis()->SetRange(1,10);
   Graph_myHisto1->GetXaxis()->SetLabelFont(42);
   Graph_myHisto1->GetXaxis()->SetLabelSize(0.035);
   Graph_myHisto1->GetXaxis()->SetTitleSize(0.05);
   Graph_myHisto1->GetXaxis()->SetTitleOffset(0.8);
   Graph_myHisto1->GetXaxis()->SetTitleFont(42);
   Graph_myHisto1->GetYaxis()->SetTitle("95% CL upper limit on  #sigma / #sigma_{pp #rightarrow W'W'}");
   Graph_myHisto1->GetYaxis()->SetLabelFont(42);
   Graph_myHisto1->GetYaxis()->SetLabelSize(0.035);
   Graph_myHisto1->GetYaxis()->SetTitleSize(0.05);
   Graph_myHisto1->GetYaxis()->SetTitleOffset(0.8);
   Graph_myHisto1->GetYaxis()->SetTitleFont(42);
   Graph_myHisto1->GetZaxis()->SetLabelFont(42);
   Graph_myHisto1->GetZaxis()->SetLabelSize(0.035);
   Graph_myHisto1->GetZaxis()->SetTitleSize(0.035);
   Graph_myHisto1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_myHisto1);
   
   gre->Draw("ap40");
   
   TGraph *graph = new TGraph(11);
   graph->SetName("Graph");
   graph->SetTitle("Observed");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(4);
   graph->SetPoint(0,100,0.04399999976);
   graph->SetPoint(1,130,0.08540000021);
   graph->SetPoint(2,160,0.1481999904);
   graph->SetPoint(3,190,0.2299999893);
   graph->SetPoint(4,220,0.349999994);
   graph->SetPoint(5,250,0.5500000119);
   graph->SetPoint(6,280,0.8500000238);
   graph->SetPoint(7,310,1.25);
   graph->SetPoint(8,340,1.850000024);
   graph->SetPoint(9,370,2.650000095);
   graph->SetPoint(10,400,3.700000048);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,70,430);
   Graph_Graph1->SetMinimum(0.0396);
   Graph_Graph1->SetMaximum(4.0656);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("pc");
   
   graph = new TGraph(11);
   graph->SetName("Graph");
   graph->SetTitle("Expected");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(4);
   graph->SetPoint(0,100,0.08269999921);
   graph->SetPoint(1,130,0.1592999995);
   graph->SetPoint(2,160,0.2675999999);
   graph->SetPoint(3,190,0.3899999857);
   graph->SetPoint(4,220,0.6000000238);
   graph->SetPoint(5,250,0.9000000358);
   graph->SetPoint(6,280,1.350000024);
   graph->SetPoint(7,310,1.950000048);
   graph->SetPoint(8,340,2.850000143);
   graph->SetPoint(9,370,3.950000048);
   graph->SetPoint(10,400,5.450000286);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,70,430);
   Graph_Graph2->SetMinimum(0.07443);
   Graph_Graph2->SetMaximum(5.98673);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("pc");
   
   TLegend *leg = new TLegend(0.15,0.6515152,0.4,0.8572568,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.0400641);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","g_{SM}","c");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","Observed","l");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","Expected #pm1 #sigma","fl");
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
   TLine *line = new TLine(100,1,390,1);
   line->SetLineStyle(7);
   line->Draw();
   Exclusion2->Modified();
   Exclusion2->cd();
   Exclusion2->SetSelected(Exclusion2);
}
