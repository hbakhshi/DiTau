{
//=========Macro generated from canvas: mass wp- rvalue/Mwp_r.value
//=========  (Mon Jul 24 21:40:18 2017) by ROOT version5.34/23
   TCanvas *mass wp- rvalue = new TCanvas("mass wp- rvalue", "Mwp_r.value",65,52,700,500);
   mass wp- rvalue->Range(43.75,-2.623563,456.25,23.61206);
   mass wp- rvalue->SetFillColor(0);
   mass wp- rvalue->SetBorderMode(0);
   mass wp- rvalue->SetBorderSize(2);
   mass wp- rvalue->SetGridx();
   mass wp- rvalue->SetGridy();
   mass wp- rvalue->SetFrameBorderMode(0);
   mass wp- rvalue->SetFrameBorderMode(0);
   
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
   graph->SetPoint(0,100,0.2299999893);
   graph->SetPoint(1,130,0.4399999976);
   graph->SetPoint(2,160,0.7799999714);
   graph->SetPoint(3,190,1.25999999);
   graph->SetPoint(4,220,2.079999924);
   graph->SetPoint(5,250,3.379999876);
   graph->SetPoint(6,280,5.079999924);
   graph->SetPoint(7,310,7.659999847);
   graph->SetPoint(8,340,10.72999954);
   graph->SetPoint(9,370,15);
   graph->SetPoint(10,400,20);
   
   TH1F *Graph_Graph_Graph13 = new TH1F("Graph_Graph_Graph13","Observed",100,70,430);
   Graph_Graph_Graph13->SetMinimum(0.207);
   Graph_Graph_Graph13->SetMaximum(21.977);
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
   graph->SetPoint(0,100,0.6100000143);
   graph->SetPoint(1,130,1.199999928);
   graph->SetPoint(2,160,1.9799999);
   graph->SetPoint(3,190,3.059999943);
   graph->SetPoint(4,220,4.809999943);
   graph->SetPoint(5,250,7.599999905);
   graph->SetPoint(6,280,10);
   graph->SetPoint(7,310,15);
   graph->SetPoint(8,340,20);
   graph->SetPoint(9,370,15);
   graph->SetPoint(10,400,20);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Exp-1#sigma",100,70,430);
   Graph_Graph4->SetMinimum(0);
   Graph_Graph4->SetMaximum(21.939);
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
   graph->SetPoint(0,100,0.4299999774);
   graph->SetPoint(1,130,0.8399999738);
   graph->SetPoint(2,160,1.399999976);
   graph->SetPoint(3,190,2.159999847);
   graph->SetPoint(4,220,3.399999857);
   graph->SetPoint(5,250,5.409999847);
   graph->SetPoint(6,280,7.909999847);
   graph->SetPoint(7,310,11.7699995);
   graph->SetPoint(8,340,16.21999931);
   graph->SetPoint(9,370,15);
   graph->SetPoint(10,400,20);
   
   TH1F *Graph_Graph_Graph25 = new TH1F("Graph_Graph_Graph25","Expected",100,70,430);
   Graph_Graph_Graph25->SetMinimum(0.387);
   Graph_Graph_Graph25->SetMaximum(21.957);
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
   graph->SetPoint(0,100,0.3100000024);
   graph->SetPoint(1,130,0.6100000143);
   graph->SetPoint(2,160,1.019999981);
   graph->SetPoint(3,190,1.579999924);
   graph->SetPoint(4,220,2.519999981);
   graph->SetPoint(5,250,3.980000019);
   graph->SetPoint(6,280,5.849999905);
   graph->SetPoint(7,310,8.720000267);
   graph->SetPoint(8,340,11.96000004);
   graph->SetPoint(9,370,15);
   graph->SetPoint(10,400,20);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Exp+1#sigma",100,70,430);
   Graph_Graph6->SetMinimum(0);
   Graph_Graph6->SetMaximum(21.969);
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
   mass wp- rvalue->Modified();
   mass wp- rvalue->cd();
   mass wp- rvalue->SetSelected(mass wp- rvalue);
}
