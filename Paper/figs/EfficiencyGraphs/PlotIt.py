from ROOT import TGraph, TMultiGraph, TCanvas, kRed, kBlue, kOrange, kGreen, TLegend, kWhite

graphs = {1:[1 , kRed , "Signal Region I" , 20 , "SR1"],
          2:[2 , kBlue , "Signal Region II" , 21 , "SR2"],
          3:[3 , kGreen , "#mu#tau" , 22 , "MuTau"],
          4:[4 , kOrange , "e#tau" , 23 , "EleTau"]}
mgraph = TMultiGraph()

def make_formatter(n):
    ret = "%lg"
    for i in range(1,n):
        ret += " %*lg"
    ret += " %lg"
    return ret
for region in sorted(graphs) :
    info = graphs[region]
    graph = TGraph("Efficiencies.csv" , make_formatter(info[0]) )
    graph.SetName( info[4] )
    graph.SetTitle( info[2] )
    graph.SetMarkerColor( info[1] )
    graph.SetMarkerSize( 2 )
    graph.SetMarkerStyle( info[3] )
    info.append( graph )
    mgraph.Add( graph )

canvas = TCanvas("EfficiencyGraphs" , "EfficiencyGraphs" , 1400 , 1000 )
mgraph.SetMinimum(0.0001)
mgraph.SetMaximum(5)
mgraph.Draw("ap")
canvas.SetLogy()
mgraph.GetXaxis().SetTitle("m_{W'} (GeV)")
mgraph.GetXaxis().SetTitleSize(0.05)
mgraph.GetYaxis().SetTitle("Selection Efficiency (%)")
mgraph.GetYaxis().SetTitleSize(0.05)
legend = canvas.BuildLegend( .55 , .2 , .8 , .45 , "" , "P" )
legend.SetLineColor(kWhite) 
legend.SetFillStyle(0)

canvas.SaveAs("../EfficiencyGraphs.pdf")
