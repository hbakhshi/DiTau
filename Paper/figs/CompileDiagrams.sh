pdflatex DiagramHadronicDecay.tex
#for f in *.mp; do mpost $f; done
pdflatex DiagramHadronicDecay.tex
pdflatex DiagramHadronicDecay.tex

#pdfcrop --margins '1 5 5 -365' Diagram-TChipmSlepSnu.pdf TChipmSlepSnu.pdf
pdfcrop --margins '1 0 5 -430' DiagramHadronicDecay.pdf WpWpTauTau.pdf

rm -rf *.log
rm -rf *.mp
rm -rf *.*1
rm -rf *.aux
rm -rf DiagramHadronicDecay.pdf

