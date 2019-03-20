void CombineTreesBackgrounds(){

	TList *listTTMaster = new TList; 

	std::ifstream infileb("/cms/mchristos/software/CMSSW_10_3_ROOT614_X_2018-09-16-0000/pyPlotterSeesaw/pyplotter/runPlotter_3L_27bins_NTuplePlotter_2016/names.txt");
   	std::string lineb;

   	std::getline(infileb, lineb);    //throws away first line which includes titles

   	while (std::getline(infileb, lineb)) {    

      std::string bg;      
      
      std::istringstream ss(lineb);       
      
      ss >> bg;
      std::string in;

      
      // if file is ttbar or dy, it is store in a different directory than all other MCs!
      
      in = "/cms/mchristos/software/CMSSW_10_3_ROOT614_X_2018-09-16-0000/pyPlotterSeesaw/pyplotter/runPlotter_3L_27bins_NTuplePlotter_2016/InputBundle_"+bg+"_Tree.root";
      const char *back_name = in.c_str();
      TFile *back_input = TFile::Open( back_name ); 
      
      std::cout << "--- Using background input file: " << back_input->GetName() <<         std::endl;
      TTree *background = (TTree*)back_input->Get("rootTupleTreeVeryLoose/tree");

    	TFile *endfile;
    	endfile = new TFile("shortTree_3L.root","RECREATE");
    	TTree *analysisTree;
		analysisTree = background->CopyTree("floor(10000*abs(LightLeptonEta[2]))%4==1");

    	cout<<"Background Tree # of events: "<<analysisTree->GetEntries()<<endl;
    	listTTMaster->Add(analysisTree); 
   	}




	
	TFile *endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/Seesaw_2_16_19/BackgroundTree.root","RECREATE");   
	endfile->mkdir("rootTupleTreeVeryLoose/");
   	endfile->cd("rootTupleTreeVeryLoose/");

   	TTree *TTMasterTree = TTree::MergeTrees(listTTMaster); 
	TTMasterTree->SetName("tree"); 
	TTMasterTree->Write();
	cout<<"Final Tree: "<<TTMasterTree->GetEntries()<<endl;

	endfile->Close();

	


}