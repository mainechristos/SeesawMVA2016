void CombineTreesSignal(){

	TList *listTTMaster = new TList; 

	std::ifstream infileXsecs("/cms/mchristos/software/CMSSW_10_3_ROOT614_X_2018-09-16-0000/pyPlotterSeesaw/pyplotter/runPlotter_3L_SeesawSR_NTuplePlotter_2016/names1250.txt");
   	std::string lines;

   	std::getline(infileXsecs, lines);    //throws away first line which includes titles

   	while (std::getline(infileXsecs, lines)) {    //loops through remaining lines in xsecs file

    	std::string process;
      
    	std::istringstream ss(lines);       //takes each line and converts to string
    	ss >> process;
    	//reads process name and other numbers into respective variables


    	std::string in = "/cms/mchristos/software/CMSSW_10_3_ROOT614_X_2018-09-16-0000/pyPlotterSeesaw/pyplotter/runPlotter_3L_SeesawSR_NTuplePlotter_2016/"+process+"_Tree.root";
    	const char *sig_name = in.c_str();
    	TFile *sig_input = TFile::Open( sig_name );     //opens signal file matching process name

    	std::cout << "--- Using signal input file: " << sig_input->GetName() <<         std::endl;
      // --- Register the training and test trees
    	TTree *signal     = (TTree*)sig_input->Get("rootTupleTreeVeryLoose/tree");     //gets signal tree
    	TFile *endfile;
    	endfile = new TFile("shortTree_3L.root","RECREATE");
    	TTree *analysisTree;
		analysisTree = signal->CopyTree("floor(10000*abs(LightLeptonEta[2]))%4==1");

    	cout<<"Signal Tree ss: "<<analysisTree->GetEntries()<<endl;
    	listTTMaster->Add(analysisTree); 
   	}




	
	TFile *endfile = new TFile("/cms/mchristos/ANN/Seesaw/2016/Seesaw_2_16_19/SignalTree1250.root","RECREATE");   
	endfile->mkdir("rootTupleTreeVeryLoose/");
   	endfile->cd("rootTupleTreeVeryLoose/");

   	TTree *TTMasterTree = TTree::MergeTrees(listTTMaster); 
	TTMasterTree->SetName("tree"); 
	TTMasterTree->Write();
	cout<<"Final Tree: "<<TTMasterTree->GetEntries()<<endl;

	endfile->Close();

	


}