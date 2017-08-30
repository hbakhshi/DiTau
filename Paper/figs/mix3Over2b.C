{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Wed Aug 30 15:12:29 2017) by ROOT version5.34/07
   TCanvas *Exclusion2 = new TCanvas("Exclusion2", "Exclusion2",13,36,700,500);
   Exclusion2->Range(153.6364,-1.67603,517.2727,2.07397);
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
   gre->SetPoint(0,190,0.09);
   gre->SetPointError(0,0,-0.03);
   gre->SetPoint(1,220,0.1422);
   gre->SetPointError(1,0,-0.0443);
   gre->SetPoint(2,250,0.21);
   gre->SetPointError(2,0,-0.07);
   gre->SetPoint(3,280,0.32);
   gre->SetPointError(3,0,-0.09999999);
   gre->SetPoint(4,310,0.45);
   gre->SetPointError(4,0,-0.14);
   gre->SetPoint(5,340,0.69);
   gre->SetPointError(5,0,-0.22);
   gre->SetPoint(6,370,0.965);
   gre->SetPointError(6,0,-0.303);
   gre->SetPoint(7,400,1.2675);
   gre->SetPointError(7,0,-0.3975);
   gre->SetPoint(8,430,1.735);
   gre->SetPointError(8,0,-0.545);
   gre->SetPoint(9,460,2.37);
   gre->SetPointError(9,0,-0.7499999);
   gre->SetPoint(10,490,3.26);
   gre->SetPointError(10,0,-1.02);
   gre->SetPoint(11,510,3.26);
   gre->SetPointError(11,0,-1.02);
   
   TH1F *Graph_myHisto1 = new TH1F("Graph_myHisto1","",11,190,510);
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
   graph->SetPoint(0,190,0.04999999702);
   graph->SetPoint(1,220,0.08069999516);
   graph->SetPoint(2,250,0.1199999973);
   graph->SetPoint(3,280,0.1899999976);
   graph->SetPoint(4,310,0.2699999809);
   graph->SetPoint(5,340,0.4199999869);
   graph->SetPoint(6,370,0.5990000367);
   graph->SetPoint(7,400,0.7980000377);
   graph->SetPoint(8,430,1.100000024);
   graph->SetPoint(9,460,1.5);
   graph->SetPoint(10,490,2.089999914);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,160,520);
   Graph_Graph1->SetMinimum(0.045);
   Graph_Graph1->SetMaximum(2.294);
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
   graph->SetPoint(0,190,0.07999999821);
   graph->SetPoint(1,220,0.1323999912);
   graph->SetPoint(2,250,0.1999999881);
   graph->SetPoint(3,280,0.2999999821);
   graph->SetPoint(4,310,0.4199999869);
   graph->SetPoint(5,340,0.6399999857);
   graph->SetPoint(6,370,0.8980000615);
   graph->SetPoint(7,400,1.175000072);
   graph->SetPoint(8,430,1.610000014);
   graph->SetPoint(9,460,2.210000038);
   graph->SetPoint(10,490,3.019999981);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,160,520);
   Graph_Graph2->SetMinimum(0.072);
   Graph_Graph2->SetMaximum(3.314);
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
   TLegendEntry *entry=leg->AddEntry("Graph","#frac{3}{2} g_{SM}","c");
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
   TLine *line = new TLine(190,1,480,1);
   line->SetLineStyle(7);
   line->Draw();
   Exclusion2->Modified();
   Exclusion2->cd();
   Exclusion2->SetSelected(Exclusion2);
}
