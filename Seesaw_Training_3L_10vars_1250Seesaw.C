#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/TMVAGui.h"
#include "TMVA/Tools.h"



void Seesaw_Training_3L_10vars_1250Seesaw( TString myMethodList = "" )
{

   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars2.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars3.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars4.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars5.C");
   gROOT->ProcessLineSync(".L /cms/mchristos/ANN/Seesaw/2016/custom_functions/inputVars6.C");

   TMVA::Tools::Instance();
   std::map<std::string,int> Use;

   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
            std::cout << std::endl;
            return;
         }
         Use[regMethod] = 1;
      }
   }

   TString outfileName( "class_perf/Seesaw_3L_1250Seesaw_10vars_Skims.root" );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   TMVA::Factory *factory = new TMVA::Factory( "Seesaw_3L_1250Seesaw_10vars_Skims", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:AnalysisType=Classification" );

   TMVA::DataLoader* dl = new TMVA::DataLoader("dl");
   
   //dl->AddVariable("Alt$(LT,0)");
   //dl->AddVariable("Alt$(MET,0)");
   dl->AddVariable("Alt$(LightLeptonPt[0],0)");
   dl->AddVariable("Alt$(LightLeptonPt[1],0)");
   dl->AddVariable("Alt$(LightLeptonPt[2],0)");
   dl->AddVariable("Alt$(MT3,0)");
   dl->AddVariable("Alt$(LightLeptonEta[0],0)");
   dl->AddVariable("Alt$(LightLeptonEta[1],0)");
   dl->AddVariable("Alt$(LightLeptonEta[2],0)");
   dl->AddVariable("Alt$(LightLeptonMass[0],0)");
   //dl->AddVariable("JetN[0]");
   dl->AddVariable("Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)");
   dl->AddVariable("Alt$(LightLeptonPairDR[0],0)");
   dl->AddVariable("Alt$(LightLeptonBestMOSSF[0],0)");

   //dl->AddVariable("PtRatio(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2])");
   //dl->AddVariable("PtRatio(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2])");
   //dl->AddVariable("PtRatio(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1])");

   //dl->AddVariable("DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])");
   //dl->AddVariable("DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])");
   //dl->AddVariable("DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])");

   dl->AddVariable("LightLeptonDXY[0]");
   dl->AddVariable("LightLeptonDXY[1]");
   dl->AddVariable("LightLeptonDXY[2]");

   /*dl->AddVariable("metRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");
   dl->AddVariable("metStRatio := metRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   dl->AddVariable("metRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))");

   dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");
   dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   dl->AddVariable("metSquaredRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))");
   dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),Alt$(Sum$(JetPt),0))");

   dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),LightLeptonLT3[0]+Alt$(PFMETType1[0],0)+Alt$(Sum$(JetPt),0))");
   dl->AddVariable("metQuadRatio(Alt$(PFMETType1[0],0),Alt$(LightLeptonLT3[0],0))");*/
   //dl->AddVariable("Alt$(Sum$(JetPt),0)");

   dl->AddVariable("Alt$(LT,0)+Alt$(MET,0)+Alt$(Sum$(JetPt),0)");
   //dl->AddVariable("Alt$(LightLeptonBestMSSSF[0],0)");
   //dl->AddVariable("Alt$(LightLeptonPairPt[0],0)");






   

   TCut mycuts = "1";

   TCut mycutb = "1";


   //////////////////////////
   // Adding signal Tree //
   //////////////////////////

   TFile *sig_input = TFile::Open( "/cms/mchristos/ANN/Seesaw/2016/Seesaw_2_16_19/SignalTree1250.root" );     //opens signal file matching process name

   std::cout << "--- Using signal input file: " << sig_input->GetName() <<         std::endl;
   // --- Register the training and test trees
   TTree *signal     = (TTree*)sig_input->Get("rootTupleTreeVeryLoose/tree");     //gets signal tree
   

   
   dl->AddSignalTree    ( signal,      1 );
      

   dl->SetSignalWeightExpression("TrainingWeight");

   

   /////////////////////////////
   // Add MC Background Tree  //
   /////////////////////////////

   //background weight expression (see key.txt for dataType of different files)

   
   TFile *back_input = TFile::Open( "/cms/mchristos/ANN/Seesaw/2016/Seesaw_2_16_19/BackgroundTree.root" );     //opens background file matching process name

   std::cout << "--- Using background input file: " << back_input->GetName() <<         std::endl;
   // --- Register the training and test trees
   TTree *background     = (TTree*)back_input->Get("rootTupleTreeVeryLoose/tree");     //gets background tree
   

   
   dl->AddBackgroundTree    ( background,      1 );
      

   dl->SetBackgroundWeightExpression("TrainingWeight");



   

   cout<<"Prepare Training and Testing Trees:"<<endl;
   dl->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=9000:nTrain_Background=50000:SplitMode=Random:NormMode=NumEvents:!V" );

   //factory->BookMethod( dl, TMVA::Types::kBDT, "QQQ Trees","!H:!V:NTrees=QQQ:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "25 Trees","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "50 Trees","!H:!V:NTrees=50:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "100 Trees","!H:!V:NTrees=100:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "200 Trees","!H:!V:NTrees=200:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "300 Trees","!H:!V:NTrees=300:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "400 Trees","!H:!V:NTrees=400:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   

   //factory->BookMethod( dl, TMVA::Types::kBDT, "Depth QQQ","!H:!V:NTrees=50:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=QQQ" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Depth 1","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=1" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Depth 2","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Depth 3","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=3" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Depth 4","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Depth 5","!H:!V:NTrees=25:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=5" );
   
   
   // //factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize QQQ","!H:!V:NTrees=50:MinNodeSize=QQQ%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=4" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize 1.0","!H:!V:NTrees=25:MinNodeSize=1.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize 2.0","!H:!V:NTrees=25:MinNodeSize=2.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize 3.0","!H:!V:NTrees=25:MinNodeSize=3.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize 5.0","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "MinNodeSize 10.0","!H:!V:NTrees=25:MinNodeSize=10.0%:BoostType=Grad:Shrinkage=1:nCuts=20:MaxDepth=2" );
   
   // //factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage QQQ","!H:!V:NTrees=50:MinNodeSize=3.0%:BoostType=Grad:Shrinkage=QQQ:nCuts=20:MaxDepth=4" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage .1","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.1:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage .3","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.3:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage .5","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.5:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage .8","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=20:MaxDepth=2" );
   // factory->BookMethod( dl, TMVA::Types::kBDT, "Shrinkage 1.0","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=1.0:nCuts=20:MaxDepth=2" );
   
   factory->BookMethod( dl, TMVA::Types::kBDT, "BDT","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=20:MaxDepth=2" );

   // //factory->BookMethod( dl, TMVA::Types::kBDT, "NCutsQQQ","!H:!V:NTrees=50:MinNodeSize=3.0%:BoostType=Grad:Shrinkage=.3:nCuts=QQQ:MaxDepth=4" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "NCuts 10","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=2:MaxDepth=2" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "NCuts 30","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=5:MaxDepth=2" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "NCuts 50","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=10:MaxDepth=2" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "NCuts 80","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=20:MaxDepth=2" );
   //factory->BookMethod( dl, TMVA::Types::kBDT, "NCuts 100","!H:!V:NTrees=25:MinNodeSize=5.0%:BoostType=Grad:Shrinkage=.8:nCuts=100:MaxDepth=2" );
   
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();



   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;


   delete factory;

   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()){;
         TMVA::TMVAGui( outfileName );
   }
   

}