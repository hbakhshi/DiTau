{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Tue Aug  8 19:42:46 2017) by ROOT version5.34/23
   TCanvas *Exclusion2 = new TCanvas("Exclusion2", "Exclusion2",65,52,700,500);
   Exclusion2->Range(63.63636,-1.67603,427.2727,2.07397);
   Exclusion2->SetFillColor(0);
   Exclusion2->SetBorderMode(0);
   Exclusion2->SetBorderSize(2);
   Exclusion2->SetLogy();
   Exclusion2->SetFrameBorderMode(0);
   Exclusion2->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(12);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(3);
   gre->SetLineColor(2);
   gre->SetLineStyle(2);
   gre->SetLineWidth(4);
   gre->SetPoint(0,100,-0.01);
   gre->SetPointError(0,0,0);
   gre->SetPoint(1,130,0);
   gre->SetPointError(1,0,-0.01);
   gre->SetPoint(2,160,0);
   gre->SetPointError(2,0,-0.01);
   gre->SetPoint(3,190,0.015);
   gre->SetPointError(3,0,-0.005);
   gre->SetPoint(4,220,0.03);
   gre->SetPointError(4,0,-0.01);
   gre->SetPoint(5,250,0.045);
   gre->SetPointError(5,0,-0.015);
   gre->SetPoint(6,280,0.065);
   gre->SetPointError(6,0,-0.025);
   gre->SetPoint(7,310,0.095);
   gre->SetPointError(7,0,-0.035);
   gre->SetPoint(8,340,0.145);
   gre->SetPointError(8,0,-0.045);
   gre->SetPoint(9,370,0.195);
   gre->SetPointError(9,0,-0.065);
   gre->SetPoint(10,400,0.27);
   gre->SetPointError(10,0,-0.09);
   gre->SetPoint(11,420,0.27);
   gre->SetPointError(11,0,-0.09);
   
   TH1F *Graph_myHisto1 = new TH1F("Graph_myHisto1","",11,100,420);
   Graph_myHisto1->SetMinimum(0.05);
   Graph_myHisto1->SetMaximum(50);
   Graph_myHisto1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   
   gre->Draw("ap4");
   
   TGraph *graph = new TGraph(11);
   graph->SetName("Graph1");
   graph->SetTitle("Observed");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(4);
   graph->SetPoint(0,100,-0.009999999776);
   graph->SetPoint(1,130,-0.009999999776);
   graph->SetPoint(2,160,-0.009999999776);
   graph->SetPoint(3,190,0.009999999776);
   graph->SetPoint(4,220,0.009999999776);
   graph->SetPoint(5,250,0.01999999955);
   graph->SetPoint(6,280,0.03999999911);
   graph->SetPoint(7,310,0.05999999866);
   graph->SetPoint(8,340,0.07999999821);
   graph->SetPoint(9,370,0.1199999973);
   graph->SetPoint(10,400,0.1700000018);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,70,430);
   Graph_Graph1->SetMinimum(-0.028);
   Graph_Graph1->SetMaximum(0.188);
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
   graph->SetName("Graph2");
   graph->SetTitle("Expected");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(2);
   graph->SetLineWidth(4);
   graph->SetPoint(0,100,-0.009999999776);
   graph->SetPoint(1,130,-0.009999999776);
   graph->SetPoint(2,160,0.009999999776);
   graph->SetPoint(3,190,0.009999999776);
   graph->SetPoint(4,220,0.01999999955);
   graph->SetPoint(5,250,0.03999999911);
   graph->SetPoint(6,280,0.05999999866);
   graph->SetPoint(7,310,0.08999999613);
   graph->SetPoint(8,340,0.1299999952);
   graph->SetPoint(9,370,0.1799999923);
   graph->SetPoint(10,400,0.25);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,70,430);
   Graph_Graph2->SetMinimum(-0.036);
   Graph_Graph2->SetMaximum(0.276);
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
   
   TLegend *leg = new TLegend(0.3291024,0.6515152,0.7107888,0.8572568,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.0400641);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph1","Observed","l");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Expected #pm1 #sigma","fl");
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
   TLine *line = new TLine(105,1,390,1);
   line->SetLineStyle(7);
   line->Draw();
   Exclusion2->Modified();
   Exclusion2->cd();
   Exclusion2->SetSelected(Exclusion2);
}
