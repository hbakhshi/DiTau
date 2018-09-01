{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Sun Aug 27 10:25:57 2017) by ROOT version5.34/07
   TCanvas *Exclusion2 = new TCanvas("Exclusion2", "Exclusion2",13,36,700,500);
   Exclusion2->Range(-26.36364,-1.67603,337.2727,2.07397);
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
   gre->SetPoint(0,10,0.000465);
   gre->SetPointError(0,0,-0.000165);
   gre->SetPoint(1,40,0.052);
   gre->SetPointError(1,0,-0.017);
   gre->SetPoint(2,70,0.2075);
   gre->SetPointError(2,0,-0.06650001);
   gre->SetPoint(3,100,0.51);
   gre->SetPointError(3,0,-0.163);
   gre->SetPoint(4,130,0.95);
   gre->SetPointError(4,0,-0.31);
   gre->SetPoint(5,160,1.57);
   gre->SetPointError(5,0,-0.5);
   gre->SetPoint(6,190,2.375);
   gre->SetPointError(6,0,-0.7549999);
   gre->SetPoint(7,220,3.9);
   gre->SetPointError(7,0,-1.22);
   gre->SetPoint(8,250,5.7);
   gre->SetPointError(8,0,-1.8);
   gre->SetPoint(9,280,8.650001);
   gre->SetPointError(9,0,-2.75);
   gre->SetPoint(10,310,12.65);
   gre->SetPointError(10,0,-3.95);
   gre->SetPoint(11,330,12.65);
   gre->SetPointError(11,0,-3.95);
   
   TH1F *Graph_myHisto1 = new TH1F("Graph_myHisto1","",11,10,330);
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
   graph->SetPoint(0,10,0.0003399999987);
   graph->SetPoint(1,40,0.02600000054);
   graph->SetPoint(2,70,0.1050000042);
   graph->SetPoint(3,100,0.253000021);
   graph->SetPoint(4,130,0.4699999988);
   graph->SetPoint(5,160,0.8199999928);
   graph->SetPoint(6,190,1.289999962);
   graph->SetPoint(7,220,2.190000057);
   graph->SetPoint(8,250,3.299999952);
   graph->SetPoint(9,280,5.200000286);
   graph->SetPoint(10,310,7.700000286);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,0,340);
   Graph_Graph1->SetMinimum(0.000306);
   Graph_Graph1->SetMaximum(8.469966);
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
   graph->SetPoint(0,10,0.0004399999743);
   graph->SetPoint(1,40,0.04900000244);
   graph->SetPoint(2,70,0.1950000077);
   graph->SetPoint(3,100,0.476000011);
   graph->SetPoint(4,130,0.8799999952);
   graph->SetPoint(5,160,1.469999909);
   graph->SetPoint(6,190,2.210000038);
   graph->SetPoint(7,220,3.639999866);
   graph->SetPoint(8,250,5.300000191);
   graph->SetPoint(9,280,8);
   graph->SetPoint(10,310,11.80000019);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,0,340);
   Graph_Graph2->SetMinimum(0.000396);
   Graph_Graph2->SetMaximum(12.97996);
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
   TLegendEntry *entry=leg->AddEntry("Graph","#theta = 45^{#circ}","c");
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
   TLine *line = new TLine(10,1,300,1);
   line->SetLineStyle(7);
   line->Draw();
   Exclusion2->Modified();
   Exclusion2->cd();
   Exclusion2->SetSelected(Exclusion2);
}
