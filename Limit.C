void Limit(){
      TH1F signal("signal","signal",1, 0., 1.);
      TH1F bkg("bkg","bkg",1, 0., 1.);
      TH1F data("data","data",1, 0., 1.);      
      data.SetBinContent(1,5.0);
      data.SetBinError(1,sqrt(5.0));
      bkg.SetBinContent(1,3.0);
      bkg.SetBinError(1,1.0);
      signal.SetBinContent(1,1.0);
      signal.SetBinError(1,0.2);

	TLimitDataSource* mydatasource = new TLimitDataSource(&signal,&bkg,&data);
	TConfidenceLevel* myconfidence = TLimit::ComputeLimit(mydatasource,50000);
      
        std::cout << "  CLs    : " << myconfidence->CLs()  << std::endl;
        std::cout << "  CLsb   : " << myconfidence->CLsb() << std::endl;
        std::cout << "  CLb    : " << myconfidence->CLb()  << std::endl;




}
