from ROOT import TFile, TH1, TCanvas, gStyle, TLatex, gPad, TLegend

#gStyle.SetOpt

masses = [100,190,310,400]
hists = { "hTauPt_hadhad-max":["#tau p_{T}^{max} (GeV)" , "#tau #tau" , True] ,
          "hTauPt_hadhad-min":["#tau p_{T}^{min} (GeV)" , "#tau #tau" , True],
          "hTauPt_lhad":["lepton p_{T} (GeV)" , "lepton #tau", True] ,
          "hTauPt_ll":["#tau p_{T} (GeV)" , "lepton #tau", True] ,
          "hMET_lhad":["MET (GeV)" , "lepton #tau", True] ,
          "hMET_hadhad":["MET (GeV)" , "#tau #tau", True] ,
          "hMT2_lhad":["MT2 (GeV)" , "lepton #tau", True] ,
          "hMT2_hadhad":["MT2 (GeV)" , "#tau #tau", True] }

files = { mass:TFile.Open("/home/paktinat/DiTau/bin/gSM/tree_gSM_wp%d.root"%(mass)) for mass in masses }
canvases = { h:[TCanvas(h)] for h in hists }

gStyle.SetOptTitle(0)
latex = TLatex()
latex.SetTextSize( 0.03 )
latex.SetTextFont(42);

for hist in hists:
    canvases[hist][0].cd()
    text = hists[hist][1]
    legend = TLegend(0.5,0.6,0.87,0.88, text,"brNDC")
    legend.SetBorderSize(0)
    legend.SetFillStyle(0)
    canvases[hist].append( legend )
    option = ""
    a=1
    for mass in masses:
        files[mass].Get( hist ).SetTitle( "m_{W'}=%s GeV" %(mass) )
        files[mass].Get( hist ).SetStats( False )
        files[mass].Get( hist ).GetXaxis().SetTitle( hists[hist][0] )
        files[mass].Get( hist ).SetLineWidth(2)
        files[mass].Get( hist ).SetLineStyle(a)
        files[mass].Get( hist ).SetLineColor(a)
        files[mass].Get( hist ).DrawNormalized(option)
        option = "sames"
        legend.AddEntry( files[mass].Get( hist ) , "" , "l")
        a=a+1

#    canvases[hist].append( latex.DrawLatex(250, 0.1, text ) )
    legend.Draw()
    if hists[hist][2] :
        canvases[hist][0].SetLogy()
    canvases[hist][0].SaveAs( "log_%s.C" % (hist) )
