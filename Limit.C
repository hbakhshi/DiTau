void Limit(){
      TH1F signal("signal","signal",4, 0., 4.);
      TH1F bkg("bkg","bkg",4, 0., 4.);
      TH1F data("data","data",4, 0., 4.);      

      //Bin1 muTau
      data.SetBinContent(1,5.0);
      data.SetBinError(1,sqrt(5.0));

      //Bin2 eleTau
      data.SetBinContent(2,3.0);
      data.SetBinError(2,sqrt(3.0));

      //Bin1 muTau bkg from PAS
      bkg.SetBinContent(1,8.59);
      bkg.SetBinError(1,sqrt(4.83));

      //Bin2 eleTau bkg from PAS
      bkg.SetBinContent(2,3.52)
	bkg.SetBinError(2,sqrt(3.39));


      //Bin1 muTau from WpWp.cxx
      signal.SetBinContent(1,75.808);
      signal.SetBinError(1,sqrt(75.808));
      
      //Bin2 eleTau from WpWp.cxx
      signal.SetBinContent(2,53.469);
      signal.SetBinError(2,sqrt(53.469));
      
       //Bin3 SR1
      data.SetBinContent(3,1.0);
      data.SetBinError(3,sqrt(1.0));

        //Bin4 SR2
      data.SetBinContent(4,2.0);
      data.SetBinError(4,sqrt(2.0));

        //Bin3 SR1 bkg from PAS
      bkg.SetBinContent(3,1.60);
      bkg.SetBinError(3,sqrt(0.63));

      //Bin4 SR2 bkg from PAS
      bkg.SetBinContent(4,5.29);
      bkg.SetBinError(4,sqrt(1.66));

       //Bin3 SR1 from WpWp.cxx
      signal.SetBinContent(3,130.89);
      signal.SetBinError(3,sqrt(130.89);
      
      //Bin4  SR2 from WpWp.cxx
      signal.SetBinContent(4,182.15);
      signal.SetBinError(4,sqrt(182.15));

	TLimitDataSource* mydatasource = new TLimitDataSource(&signal,&bkg,&data);
	TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
      
        std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
        std::cout << "  CLsb   : " << myconfidence->CLsb() << std::endl;
        std::cout << "  CLb    : " << myconfidence->CLb()  << std::endl;




}
