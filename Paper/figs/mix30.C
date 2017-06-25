{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Thu Jun  8 11:13:08 2017) by ROOT version5.34/23
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
   gre->SetPoint(0,100,0.205);
   gre->SetPointError(0,0,-0.06499999);
   gre->SetPoint(1,130,0.41);
   gre->SetPointError(1,0,-0.13);
   gre->SetPoint(2,160,0.65);
   gre->SetPointError(2,0,-0.21);
   gre->SetPoint(3,190,0.98);
   gre->SetPointError(3,0,-0.31);
   gre->SetPoint(4,220,1.58);
   gre->SetPointError(4,0,-0.4899999);
   gre->SetPoint(5,250,2.455);
   gre->SetPointError(5,0,-0.765);
   gre->SetPoint(6,280,3.55);
   gre->SetPointError(6,0,-1.11);
   gre->SetPoint(7,310,5.31);
   gre->SetPointError(7,0,-1.64);
   gre->SetPoint(8,340,7.395);
   gre->SetPointError(8,0,-2.325);
   gre->SetPoint(9,370,10.485);
   gre->SetPointError(9,0,-3.285);
   gre->SetPoint(10,400,13.505);
   gre->SetPointError(10,0,-3.495);
   gre->SetPoint(11,420,13.505);
   gre->SetPointError(11,0,-3.495);
   
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
   graph->SetPoint(0,100,0.09999999404);
   graph->SetPoint(1,130,0.1999999881);
   graph->SetPoint(2,160,0.3299999833);
   graph->SetPoint(3,190,0.5299999714);
   graph->SetPoint(4,220,0.8899999857);
   graph->SetPoint(5,250,1.439999938);
   graph->SetPoint(6,280,2.119999886);
   graph->SetPoint(7,310,3.539999962);
   graph->SetPoint(8,340,4.5);
   graph->SetPoint(9,370,6.509999752);
   graph->SetPoint(10,400,9.13999939);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,70,430);
   Graph_Graph1->SetMinimum(0.08999999);
   Graph_Graph1->SetMaximum(10.044);
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
   graph->SetPoint(0,100,0.1899999976);
   graph->SetPoint(1,130,0.3799999952);
   graph->SetPoint(2,160,0.6100000143);
   graph->SetPoint(3,190,0.9199999571);
   graph->SetPoint(4,220,1.469999909);
   graph->SetPoint(5,250,2.289999962);
   graph->SetPoint(6,280,3.299999952);
   graph->SetPoint(7,310,4.940000057);
   graph->SetPoint(8,340,6.879999638);
   graph->SetPoint(9,370,9.75);
   graph->SetPoint(10,400,13.50999928);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,70,430);
   Graph_Graph2->SetMinimum(0.171);
   Graph_Graph2->SetMaximum(14.842);
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
   
   TLegend *leg = new TLegend(0.1997126,0.6518987,0.5804598,0.8586498,NULL,"brNDC");
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
