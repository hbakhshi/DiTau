from ROOT import TGraph, TMultiGraph, TCanvas, kRed, kBlue, kOrange, kGreen, TLegend, kWhite

graphs = {"SR1":[1 , kRed , "Signal Region I" , 20],
          "SR2":[2 , kBlue , "Signal Region II" , 21],
          "MuTau":[3 , kGreen , "#mu#tau" , 22 ],
          "EleTau":[4 , kOrange , "e#tau" , 23]}
mgraph = TMultiGraph()

def make_formatter(n):
    ret = "%lg"
    for i in range(1,n):
        ret += " %*lg"
    ret += " %lg"
    return ret
for region in graphs :
    info = graphs[region]
    graph = TGraph("Efficiencies.csv" , make_formatter(info[0]) )
    graph.SetName( region )
    graph.SetTitle( info[2] )
    graph.SetMarkerColor( info[1] )
    graph.SetMarkerStyle( info[3] )
    info.append( graph )
    mgraph.Add( graph )

canvas = TCanvas("EfficiencyGraphs" , "EfficiencyGraphs" , 1400 , 1000 )
mgraph.Draw("ap")
mgraph.GetXaxis().SetTitle("W' Mass (GeV)")
mgraph.GetXaxis().SetTitleSize(0.05)
mgraph.GetYaxis().SetTitle("Selection Efficiency (%)")
mgraph.GetYaxis().SetTitleSize(0.05)
legend = canvas.BuildLegend( .15 , .6 , .5 , .85 , "" , "P" )
legend.SetLineColor(kWhite) 
legend.SetFillStyle(0)

canvas.SaveAs("../EfficiencyGraphs.pdf")
