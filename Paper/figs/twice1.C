{
//=========Macro generated from canvas: massWpNrvalue/Mwp_r.value
//=========  (Tue Aug  8 19:43:18 2017) by ROOT version5.34/23
   TCanvas *massWpNrvalue = new TCanvas("massWpNrvalue", "Mwp_r.value",65,52,700,500);
   massWpNrvalue->Range(43.75,-0.079375,456.25,0.429375);
   massWpNrvalue->SetFillColor(0);
   massWpNrvalue->SetBorderMode(0);
   massWpNrvalue->SetBorderSize(2);
   massWpNrvalue->SetGridx();
   massWpNrvalue->SetGridy();
   massWpNrvalue->SetFrameBorderMode(0);
   massWpNrvalue->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("TGraph m_rvalue");
   
   TGraph *graph = new TGraph(11);
   graph->SetName("Graph1");
   graph->SetTitle("Observed");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   
   TH1F *Graph_Graph_Graph13 = new TH1F("Graph_Graph_Graph13","Observed",100,70,430);
   Graph_Graph_Graph13->SetMinimum(-0.028);
   Graph_Graph_Graph13->SetMaximum(0.188);
   Graph_Graph_Graph13->SetDirectory(0);
   Graph_Graph_Graph13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph13->SetLineColor(ci);
   Graph_Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph13);
   
   multigraph->Add(graph,"");
   
   graph = new TGraph(11);
   graph->SetName("Graph");
   graph->SetTitle("Exp-1#sigma");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ffff00");
   graph->SetLineColor(ci);
   graph->SetPoint(0,100,-0.009999999776);
   graph->SetPoint(1,130,0.009999999776);
   graph->SetPoint(2,160,0.009999999776);
   graph->SetPoint(3,190,0.01999999955);
   graph->SetPoint(4,220,0.03999999911);
   graph->SetPoint(5,250,0.05999999866);
   graph->SetPoint(6,280,0.08999999613);
   graph->SetPoint(7,310,0.1299999952);
   graph->SetPoint(8,340,0.1899999976);
   graph->SetPoint(9,370,0.2599999905);
   graph->SetPoint(10,400,0.3599999845);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Exp-1#sigma",100,70,430);
   Graph_Graph4->SetMinimum(-0.047);
   Graph_Graph4->SetMaximum(0.397);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph4->SetLineColor(ci);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   multigraph->Add(graph,"");
   
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
   
   TH1F *Graph_Graph_Graph25 = new TH1F("Graph_Graph_Graph25","Expected",100,70,430);
   Graph_Graph_Graph25->SetMinimum(-0.036);
   Graph_Graph_Graph25->SetMaximum(0.276);
   Graph_Graph_Graph25->SetDirectory(0);
   Graph_Graph_Graph25->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph25->SetLineColor(ci);
   Graph_Graph_Graph25->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph25->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph25->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph25->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph25->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph25->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph25->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph25->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph25->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph25->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph25->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph25->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph25);
   
   multigraph->Add(graph,"");
   
   graph = new TGraph(11);
   graph->SetName("Graph");
   graph->SetTitle("Exp+1#sigma");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ffff00");
   graph->SetLineColor(ci);
   graph->SetPoint(0,100,-0.009999999776);
   graph->SetPoint(1,130,-0.009999999776);
   graph->SetPoint(2,160,-0.009999999776);
   graph->SetPoint(3,190,0.009999999776);
   graph->SetPoint(4,220,0.01999999955);
   graph->SetPoint(5,250,0.02999999933);
   graph->SetPoint(6,280,0.03999999911);
   graph->SetPoint(7,310,0.05999999866);
   graph->SetPoint(8,340,0.09999999404);
   graph->SetPoint(9,370,0.1299999952);
   graph->SetPoint(10,400,0.1799999923);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Exp+1#sigma",100,70,430);
   Graph_Graph6->SetMinimum(-0.029);
   Graph_Graph6->SetMaximum(0.199);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   multigraph->Add(graph,"");
   multigraph->Draw("AC");
   multigraph->GetXaxis()->SetTitle("wprime mass");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("r_value");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TPaveText *pt = new TPaveText(0.348477,0.9342405,0.651523,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("TGraph m_rvalue");
   pt->Draw();
   massWpNrvalue->Modified();
   massWpNrvalue->cd();
   massWpNrvalue->SetSelected(massWpNrvalue);
}
