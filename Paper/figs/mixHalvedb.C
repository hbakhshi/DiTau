{
//=========Macro generated from canvas: Exclusion2/Exclusion2
//=========  (Sun Aug 27 10:51:46 2017) by ROOT version5.34/07
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
   gre->SetPoint(0,10,0.001245);
   gre->SetPointError(0,0,-0.000445);
   gre->SetPoint(1,40,0.1466);
   gre->SetPointError(1,0,-0.047);
   gre->SetPoint(2,70,0.568);
   gre->SetPointError(2,0,-0.183);
   gre->SetPoint(3,100,1.405);
   gre->SetPointError(3,0,-0.455);
   gre->SetPoint(4,130,2.715);
   gre->SetPointError(4,0,-0.865);
   gre->SetPoint(5,160,4.475);
   gre->SetPointError(5,0,-1.435);
   gre->SetPoint(6,190,7);
   gre->SetPointError(6,0,-2.23);
   gre->SetPoint(7,220,10.65);
   gre->SetPointError(7,0,-3.35);
   gre->SetPoint(8,250,16.2);
   gre->SetPointError(8,0,-5.1);
   gre->SetPoint(9,280,23.45);
   gre->SetPointError(9,0,-7.35);
   gre->SetPoint(10,310,34.5);
   gre->SetPointError(10,0,-10.8);
   gre->SetPoint(11,330,34.5);
   gre->SetPointError(11,0,-10.8);
   
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
   graph->SetPoint(0,10,0.0009199999622);
   graph->SetPoint(1,40,0.07440000027);
   graph->SetPoint(2,70,0.2870000005);
   graph->SetPoint(3,100,0.6999999881);
   graph->SetPoint(4,130,1.350000024);
   graph->SetPoint(5,160,2.319999933);
   graph->SetPoint(6,190,3.779999971);
   graph->SetPoint(7,220,6);
   graph->SetPoint(8,250,9.400000572);
   graph->SetPoint(9,280,14);
   graph->SetPoint(10,310,20.80000114);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Observed",100,0,340);
   Graph_Graph1->SetMinimum(0.000828);
   Graph_Graph1->SetMaximum(22.87991);
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
   graph->SetPoint(0,10,0.001180000021);
   graph->SetPoint(1,40,0.1381999999);
   graph->SetPoint(2,70,0.533000052);
   graph->SetPoint(3,100,1.309999943);
   graph->SetPoint(4,130,2.529999971);
   graph->SetPoint(5,160,4.170000076);
   graph->SetPoint(6,190,6.539999962);
   graph->SetPoint(7,220,10);
   graph->SetPoint(8,250,15.19999981);
   graph->SetPoint(9,280,21.80000114);
   graph->SetPoint(10,310,32.10000229);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Expected",100,0,340);
   Graph_Graph2->SetMinimum(0.001062);
   Graph_Graph2->SetMaximum(35.30988);
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
   TLegendEntry *entry=leg->AddEntry("Graph","#frac{1}{2} g_{SM}","c");
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
