from ROOT import TFile, TH1, TCanvas, gStyle, TLatex, gPad, TLegend

#gStyle.SetOpt

masses = [100,190,310,400]
hists = { "hTauPt_hadhad-max":["#tau p_{T}max" , "#tau#tau channel" , True] ,
          "hTauPt_hadhad-min":["#tau p_{T}min" , "#tau#tau channel" , True],
          "hTauPt_lhad":["lepton p_{T}" , "lepton#tau channel", True] ,
          "hTauPt_ll":["#hadronictau p_{T}" , "lepton#tau channel", True] ,
          "hMET_lhad":["MET (GeV)" , "lepton#tau channel", True] ,
          "hMET_hadhad":["MET (GeV)" , "#tau#tau channel", True] ,
          "hMT2_lhad":["MT2 (GeV)" , "lepton#tau channel", True] ,
          "hMT2_hadhad":["MT2 (GeV)" , "#tau#tau channel", False] }

files = { mass:TFile.Open("out%d.root"%(mass)) for mass in masses }
canvases = { h:[TCanvas(h)] for h in hists }

gStyle.SetOptTitle(0)
latex = TLatex()
latex.SetTextSize( 0.03 )

for hist in hists:
    canvases[hist][0].cd()
    legend = TLegend( 0.75 , 0.7 , 0.89 , 0.9 )
    legend.SetBorderSize(0)
    legend.SetFillStyle(0)
    canvases[hist].append( legend )
    option = "E"
    for mass in masses:
        files[mass].Get( hist ).SetTitle( "m_{W'}=%s GeV" %(mass) )
        files[mass].Get( hist ).SetStats( False )
        files[mass].Get( hist ).GetXaxis().SetTitle( hists[hist][0] )
        files[mass].Get( hist ).SetLineWidth(2)
        files[mass].Get( hist ).DrawNormalized(option)
        option = "sames E"
        legend.AddEntry( files[mass].Get( hist ) , "" , "l")

    text = hists[hist][1]
    canvases[hist].append( latex.DrawTextNDC(0.13,0.943,text ) )
    legend.Draw()
    if hists[hist][2] :
        canvases[hist][0].SetLogy()
    canvases[hist][0].SaveAs( "log_%s.C" % (hist) )
