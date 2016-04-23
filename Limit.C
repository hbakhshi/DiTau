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
      bkg.SetBinContent(1,3.0);
      bkg.SetBinError(1,1.0);

      //Bin2 eleTau bkg from PAS
      bkg.SetBinContent(2,2.0);
      bkg.SetBinError(2,1.5);


      //Bin1 muTau from WpWp.cxx
      signal.SetBinContent(1,1.0);
      signal.SetBinError(1,0.2);
      
      //Bin2 eleTau from WpWp.cxx
      signal.SetBinContent(2,1.5);
      signal.SetBinError(2,0.3);

	TLimitDataSource* mydatasource = new TLimitDataSource(&signal,&bkg,&data);
	TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
      
        std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
        std::cout << "  CLsb   : " << myconfidence->CLsb() << std::endl;
        std::cout << "  CLb    : " << myconfidence->CLb()  << std::endl;




}
