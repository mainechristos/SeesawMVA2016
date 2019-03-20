#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TMVA/Tools.h"


using namespace TMVA;

void runBackground(TString ifile = ""){


   TMVA::Tools::Instance();
  

   TMVA::Reader *reader1 = new TMVA::Reader( "!Color:!Silent" );  
   TMVA::Reader *reader2 = new TMVA::Reader( "!Color:!Silent" );    
   TMVA::Reader *reader3 = new TMVA::Reader( "!Color:!Silent" );   


   Float_t ElectronDXY0, ElectronDXY1, ElectronDXY2, LightLeptonPhi0, LightLeptonPhi1, LightLeptonPhi2;
   Int_t LightLeptonFlavor0, LightLeptonFlavor1, LightLeptonFlavor2, LightLeptonFlavor3, LightLeptonNativeIndex0, LightLeptonNativeIndex1, LightLeptonNativeIndex2, LightLeptonNativeIndex3;
   Float_t LT, MT3, LightLeptonPt0, LightLeptonPt1, LightLeptonPt2, LightLeptonPt3, LightLeptonBestMOSSF, MET;
   Float_t LightLeptonEta0, LightLeptonEta1, LightLeptonEta2, LightLeptonEta3, LightLeptonMass, LightLeptonPairDR0, LightLeptonPairDR1, LightLeptonPairDR2;
   Float_t JetN;
   Int_t LightLeptonN,  ElectronN, LightLeptonTightType3D, MuonN;
   Float_t PtRatio1, PtRatio2, PtRatio3, DPhi1, DPhi2,  DPhi3, DPhi4, DPhi5, DPhi6, LightLeptonDXY0, LightLeptonDXY1, LightLeptonDXY2; 
   Float_t metHtRatio, metStRatio, metLtRatio, metHtSquaredRatio, metSquaredStRatio, metLtSquaredRatio, metHtQuadRatio, metQuadStRatio, metLtQuadRatio, HT, ST, LightLeptonBestMSSSF, LightLeptonPairPt;
   Float_t PtRatio4L1, PtRatio4L2, PtRatio4L3, PtRatio4L4;
   Float_t BJetN;
   
   //reader1->AddVariable("LT := Alt$(LT,0)", &LT);
   //reader1->AddVariable("MET := Alt$(MET,0)", &MET);
   reader1->AddVariable("LightLeptonPt0 := Alt$(LightLeptonPt[0],0)", &LightLeptonPt0 );
   reader1->AddVariable("LightLeptonPt1 := Alt$(LightLeptonPt[1],0)",&LightLeptonPt1);
   reader1->AddVariable("LightLeptonPt2 := Alt$(LightLeptonPt[2],0)",&LightLeptonPt2);
   //reader1->AddVariable("LightLeptonPt3 := Alt$(LightLeptonPt[3],0)",&LightLeptonPt3);
   reader1->AddVariable("MT3 := Alt$(MT3,0)",&MT3);
   reader1->AddVariable("LightLeptonEta0 := Alt$(LightLeptonEta[0],0)", &LightLeptonEta0 );
   reader1->AddVariable("LightLeptonEta1 := Alt$(LightLeptonEta[1],0)",&LightLeptonEta1);
   reader1->AddVariable("LightLeptonEta2 := Alt$(LightLeptonEta[2],0)",&LightLeptonEta2);
   //reader1->AddVariable("LightLeptonEta3 := Alt$(LightLeptonEta[3],0)",&LightLeptonEta3);
   reader1->AddVariable("LightLeptonMass := Alt$(LightLeptonMass[0],0)",&LightLeptonMass);
   //reader1->AddVariable("JetN := JetN[0]",&JetN);
   reader1->AddVariable("BJetN := Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)",&BJetN);
   reader1->AddVariable("LightLeptonPairDR := Alt$(LightLeptonPairDR[0],0)", &LightLeptonPairDR0 );
   reader1->AddVariable("LightLeptonBestMOSSF := Alt$(LightLeptonBestMOSSF[0],0)", &LightLeptonBestMOSSF );

   //reader1->AddVariable("PtRatio1 := PtRatio(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2])", &PtRatio1);
   //reader1->AddVariable("PtRatio2 := PtRatio(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2])", &PtRatio2);
   //reader1->AddVariable("PtRatio3 := PtRatio(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1])", &PtRatio3);

   //reader1->AddVariable("PtRatio4L1 := PtRatio4(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L1);
   //reader1->AddVariable("PtRatio4L2 := PtRatio4(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L2);
   //reader1->AddVariable("PtRatio4L3 := PtRatio4(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[3])", &PtRatio4L3);
   //reader1->AddVariable("PtRatio4L4 := PtRatio4(LightLeptonPt[3],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[0])", &PtRatio4L4);

   //reader1->AddVariable("DPhi1 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])", &DPhi1);
   //reader1->AddVariable("DPhi2 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])", &DPhi2);
   //reader1->AddVariable("DPhi3 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])", &DPhi3);

   reader1->AddVariable("LightLeptonDXY0 := LightLeptonDXY[0]", &LightLeptonDXY0);
   reader1->AddVariable("LightLeptonDXY1 := LightLeptonDXY[1]", &LightLeptonDXY1);
   reader1->AddVariable("LightLeptonDXY2 := LightLeptonDXY[2]", &LightLeptonDXY2);
   //reader1->AddVariable("DPhi4 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[3])", &DPhi4);
   //reader1->AddVariable("DPhi5 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[3])", &DPhi5);
   //reader1->AddVariable("DPhi6 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[3])", &DPhi6);

   // reader1->AddVariable("metHtRatio := metRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtRatio);
   // reader1->AddVariable("metStRatio := metRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metStRatio);
   // reader1->AddVariable("metLtRatio := metRatio(Alt$(MET,0),Alt$(LT,0))", &metLtRatio);

   // reader1->AddVariable("metHtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtSquaredRatio);
   // reader1->AddVariable("metSquaredStRatio := metSquaredRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metSquaredStRatio);
   // reader1->AddVariable("metLtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(LT,0))", &metLtSquaredRatio);
   
   // reader1->AddVariable("metHtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtQuadRatio);
   // reader1->AddVariable("metQuadStRatio := metQuadRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metQuadStRatio);
   // reader1->AddVariable("metLtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(LT,0))", &metLtQuadRatio);

   //reader1->AddVariable("HT := Alt$(Sum$(JetPt),0)",&HT);
   reader1->AddVariable("ST := Alt$(LT,0)+Alt$(MET,0)+Alt$(Sum$(JetPt),0)",&ST);
   //reader1->AddVariable("LightLeptonBestMSSSF := Alt$(LightLeptonBestMSSSF[0],0)",&LightLeptonBestMSSSF);
   //reader1->AddVariable("LightLeptonPairPt := Alt$(LightLeptonPairPt[0],0)",&LightLeptonPairPt);


   //reader2->AddVariable("LT := Alt$(LT,0)", &LT);
   //reader2->AddVariable("MET := Alt$(MET,0)", &MET);
   reader2->AddVariable("LightLeptonPt0 := Alt$(LightLeptonPt[0],0)", &LightLeptonPt0 );
   reader2->AddVariable("LightLeptonPt1 := Alt$(LightLeptonPt[1],0)",&LightLeptonPt1);
   reader2->AddVariable("LightLeptonPt2 := Alt$(LightLeptonPt[2],0)",&LightLeptonPt2);
   //reader2->AddVariable("LightLeptonPt3 := Alt$(LightLeptonPt[3],0)",&LightLeptonPt3);
   reader2->AddVariable("MT3 := Alt$(MT3,0)",&MT3);
   reader2->AddVariable("LightLeptonEta0 := Alt$(LightLeptonEta[0],0)", &LightLeptonEta0 );
   reader2->AddVariable("LightLeptonEta1 := Alt$(LightLeptonEta[1],0)",&LightLeptonEta1);
   reader2->AddVariable("LightLeptonEta2 := Alt$(LightLeptonEta[2],0)",&LightLeptonEta2);
   //reader2->AddVariable("LightLeptonEta3 := Alt$(LightLeptonEta[3],0)",&LightLeptonEta3);
   reader2->AddVariable("LightLeptonMass := Alt$(LightLeptonMass[0],0)",&LightLeptonMass);
   //reader2->AddVariable("JetN := JetN[0]",&JetN);
   reader2->AddVariable("BJetN := Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)",&BJetN);
   reader2->AddVariable("LightLeptonPairDR := Alt$(LightLeptonPairDR[0],0)", &LightLeptonPairDR0 );
   reader2->AddVariable("LightLeptonBestMOSSF := Alt$(LightLeptonBestMOSSF[0],0)", &LightLeptonBestMOSSF );

   //reader2->AddVariable("PtRatio1 := PtRatio(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2])", &PtRatio1);
   //reader2->AddVariable("PtRatio2 := PtRatio(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2])", &PtRatio2);
   //reader2->AddVariable("PtRatio3 := PtRatio(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1])", &PtRatio3);

   //reader2->AddVariable("PtRatio4L1 := PtRatio4(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L1);
   //reader2->AddVariable("PtRatio4L2 := PtRatio4(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L2);
   //reader2->AddVariable("PtRatio4L3 := PtRatio4(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[3])", &PtRatio4L3);
   //reader2->AddVariable("PtRatio4L4 := PtRatio4(LightLeptonPt[3],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[0])", &PtRatio4L4);

   //reader2->AddVariable("DPhi1 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])", &DPhi1);
   //reader2->AddVariable("DPhi2 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])", &DPhi2);
   //reader2->AddVariable("DPhi3 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])", &DPhi3);

   reader2->AddVariable("LightLeptonDXY0 := LightLeptonDXY[0]", &LightLeptonDXY0);
   reader2->AddVariable("LightLeptonDXY1 := LightLeptonDXY[1]", &LightLeptonDXY1);
   reader2->AddVariable("LightLeptonDXY2 := LightLeptonDXY[2]", &LightLeptonDXY2);
   //reader2->AddVariable("DPhi4 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[3])", &DPhi4);
   //reader2->AddVariable("DPhi5 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[3])", &DPhi5);
   //reader2->AddVariable("DPhi6 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[3])", &DPhi6);

   // reader2->AddVariable("metHtRatio := metRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtRatio);
   // reader2->AddVariable("metStRatio := metRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metStRatio);
   // reader2->AddVariable("metLtRatio := metRatio(Alt$(MET,0),Alt$(LT,0))", &metLtRatio);

   // reader2->AddVariable("metHtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtSquaredRatio);
   // reader2->AddVariable("metSquaredStRatio := metSquaredRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metSquaredStRatio);
   // reader2->AddVariable("metLtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(LT,0))", &metLtSquaredRatio);
   
   // reader2->AddVariable("metHtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtQuadRatio);
   // reader2->AddVariable("metQuadStRatio := metQuadRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metQuadStRatio);
   // reader2->AddVariable("metLtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(LT,0))", &metLtQuadRatio);

   //reader2->AddVariable("HT := Alt$(Sum$(JetPt),0)",&HT);
   reader2->AddVariable("ST := Alt$(LT,0)+Alt$(MET,0)+Alt$(Sum$(JetPt),0)",&ST);
   //reader2->AddVariable("LightLeptonBestMSSSF := Alt$(LightLeptonBestMSSSF[0],0)",&LightLeptonBestMSSSF);
   //reader2->AddVariable("LightLeptonPairPt := Alt$(LightLeptonPairPt[0],0)",&LightLeptonPairPt);

   //reader3->AddVariable("LT := Alt$(LT,0)", &LT);
   //reader3->AddVariable("MET := Alt$(MET,0)", &MET);
   reader3->AddVariable("LightLeptonPt0 := Alt$(LightLeptonPt[0],0)", &LightLeptonPt0 );
   reader3->AddVariable("LightLeptonPt1 := Alt$(LightLeptonPt[1],0)",&LightLeptonPt1);
   reader3->AddVariable("LightLeptonPt2 := Alt$(LightLeptonPt[2],0)",&LightLeptonPt2);
   //reader3->AddVariable("LightLeptonPt3 := Alt$(LightLeptonPt[3],0)",&LightLeptonPt3);
   reader3->AddVariable("MT3 := Alt$(MT3,0)",&MT3);
   reader3->AddVariable("LightLeptonEta0 := Alt$(LightLeptonEta[0],0)", &LightLeptonEta0 );
   reader3->AddVariable("LightLeptonEta1 := Alt$(LightLeptonEta[1],0)",&LightLeptonEta1);
   reader3->AddVariable("LightLeptonEta2 := Alt$(LightLeptonEta[2],0)",&LightLeptonEta2);
   //reader3->AddVariable("LightLeptonEta3 := Alt$(LightLeptonEta[3],0)",&LightLeptonEta3);
   reader3->AddVariable("LightLeptonMass := Alt$(LightLeptonMass[0],0)",&LightLeptonMass);
   //reader3->AddVariable("JetN := JetN[0]",&JetN);
   reader3->AddVariable("BJetN := Sum$(JetCombinedInclusiveSecondaryVertexV2BJetTags>0.8484&&fabs(JetEta)<2.4)",&BJetN);
   reader3->AddVariable("LightLeptonPairDR := Alt$(LightLeptonPairDR[0],0)", &LightLeptonPairDR0 );
   reader3->AddVariable("LightLeptonBestMOSSF := Alt$(LightLeptonBestMOSSF[0],0)", &LightLeptonBestMOSSF );

   //reader3->AddVariable("PtRatio1 := PtRatio(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2])", &PtRatio1);
   //reader3->AddVariable("PtRatio2 := PtRatio(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2])", &PtRatio2);
   //reader3->AddVariable("PtRatio3 := PtRatio(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1])", &PtRatio3);

   //reader3->AddVariable("PtRatio4L1 := PtRatio4(LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L1);
   //reader3->AddVariable("PtRatio4L2 := PtRatio4(LightLeptonPt[1],LightLeptonPt[0],LightLeptonPt[2],LightLeptonPt[3])", &PtRatio4L2);
   //reader3->AddVariable("PtRatio4L3 := PtRatio4(LightLeptonPt[2],LightLeptonPt[0],LightLeptonPt[1],LightLeptonPt[3])", &PtRatio4L3);
   //reader3->AddVariable("PtRatio4L4 := PtRatio4(LightLeptonPt[3],LightLeptonPt[1],LightLeptonPt[2],LightLeptonPt[0])", &PtRatio4L4);

   //reader3->AddVariable("DPhi1 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[1])", &DPhi1);
   //reader3->AddVariable("DPhi2 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[2])", &DPhi2);
   //reader3->AddVariable("DPhi3 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[0])", &DPhi3);

   reader3->AddVariable("LightLeptonDXY0 := LightLeptonDXY[0]", &LightLeptonDXY0);
   reader3->AddVariable("LightLeptonDXY1 := LightLeptonDXY[1]", &LightLeptonDXY1);
   reader3->AddVariable("LightLeptonDXY2 := LightLeptonDXY[2]", &LightLeptonDXY2);
   //reader3->AddVariable("DPhi4 := DeltaPhi(LightLeptonEta[0],LightLeptonEta[3])", &DPhi4);
   //reader3->AddVariable("DPhi5 := DeltaPhi(LightLeptonEta[1],LightLeptonEta[3])", &DPhi5);
   //reader3->AddVariable("DPhi6 := DeltaPhi(LightLeptonEta[2],LightLeptonEta[3])", &DPhi6);

   // reader3->AddVariable("metHtRatio := metRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtRatio);
   // reader3->AddVariable("metStRatio := metRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metStRatio);
   // reader3->AddVariable("metLtRatio := metRatio(Alt$(MET,0),Alt$(LT,0))", &metLtRatio);

   // reader3->AddVariable("metHtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtSquaredRatio);
   // reader3->AddVariable("metSquaredStRatio := metSquaredRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metSquaredStRatio);
   // reader3->AddVariable("metLtSquaredRatio := metSquaredRatio(Alt$(MET,0),Alt$(LT,0))", &metLtSquaredRatio);
   
   // reader3->AddVariable("metHtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(Sum$(JetPt),0))", &metHtQuadRatio);
   // reader3->AddVariable("metQuadStRatio := metQuadRatio(Alt$(MET,0),LT+Alt$(MET,0)+Alt$(Sum$(JetPt),0))", &metQuadStRatio);
   // reader3->AddVariable("metLtQuadRatio := metQuadRatio(Alt$(MET,0),Alt$(LT,0))", &metLtQuadRatio);

   //reader3->AddVariable("HT := Alt$(Sum$(JetPt),0)",&HT);
   reader3->AddVariable("ST := Alt$(LT,0)+Alt$(MET,0)+Alt$(Sum$(JetPt),0)",&ST);
   //reader3->AddVariable("LightLeptonBestMSSSF := Alt$(LightLeptonBestMSSSF[0],0)",&LightLeptonBestMSSSF);
   //reader3->AddVariable("LightLeptonPairPt := Alt$(LightLeptonPairPt[0],0)",&LightLeptonPairPt);
   


   // --- Book the MVA methods



   reader1->BookMVA( "BDTG method",  "dl/weights/Seesaw_3L_300Seesaw_10vars_Skims_BDT.weights.xml");
   reader2->BookMVA( "BDTG method",  "dl/weights/Seesaw_3L_700Seesaw_10vars_Skims_BDT.weights.xml");
   reader3->BookMVA( "BDTG method",  "dl/weights/Seesaw_3L_1250Seesaw_10vars_Skims_BDT.weights.xml");


   vector<float>  vecBDTG; 
  
   TFile *input(0);
   TString fname = ifile;   
   input = TFile::Open(fname);

   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;
   
   // --- Event loop

   // Prepare the event tree
   std::cout << "--- Select Background sample" << std::endl;
   TTree *tree = (TTree*)input->Get("rootTupleTreeVeryLoose/tree");
    TTree *PsetInputsTree = (TTree*)input->Get("PsetInputsTree");
    TH1F *EventCounter = (TH1F*)input->Get("dileptonEventFilter/EventCount/EventCounter");
    TH1F *PileUpProfile = (TH1F*)input->Get("dileptonEventFilter/TrueNumInteractionsBX0/PileUpProfile");
    PileUpProfile->SetName("PileUpProfile");
    //EventCounter->SetName("EventCounter");
    PsetInputsTree->SetName("PsetInputsTree");
   TTreeReader myReader(tree);

    
 
   TTreeReaderValue<vector<Float_t>> inLightLeptonPhi(myReader, "LightLeptonPhi");
   TTreeReaderValue<vector<Int_t>> inLightLeptonFlavor(myReader, "LightLeptonFlavor");
   TTreeReaderValue<vector<Float_t>> inLightLeptonBestMOSSF(myReader, "LightLeptonBestMOSSF");
   TTreeReaderValue<vector<float,ROOT::Detail::VecOps::RAdoptAllocator<float> >> inLightLeptonDXY(myReader, "LightLeptonDXY");
   TTreeReaderValue<float> inMET(myReader, "MET");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPt(myReader, "LightLeptonPt");
   TTreeReaderValue<vector<Float_t>> inLightLeptonEta(myReader, "LightLeptonEta");
   TTreeReaderValue<vector<Float_t>> inJetEta(myReader, "JetEta");
   TTreeReaderValue<vector<Float_t>> inJetCombinedInclusiveSecondaryVertexV2BJetTags(myReader, "JetCombinedInclusiveSecondaryVertexV2BJetTags");
   TTreeReaderValue<vector<Int_t>> inJetN(myReader, "JetN");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPairDR(myReader, "LightLeptonPairDR");
   TTreeReaderValue<vector<Float_t>> inLightLeptonMass(myReader, "LightLeptonMass");
   TTreeReaderValue<float> inLT(myReader, "LT");
   TTreeReaderValue<float> inMT3(myReader, "MT3");
   TTreeReaderValue<vector<Int_t>> inLightLeptonN(myReader, "LightLeptonN");
   TTreeReaderValue<vector<Int_t>> inElectronN(myReader, "ElectronN");
   TTreeReaderValue<vector<Int_t>> inMuonN(myReader, "MuonN");
   TTreeReaderValue<vector<Float_t>> inJetPt(myReader, "JetPt");
   TTreeReaderValue<vector<Float_t>> inLightLeptonBestMSSSF(myReader, "LightLeptonBestMSSSF");
   TTreeReaderValue<vector<Float_t>> inLightLeptonPairPt(myReader, "LightLeptonPairPt");

   


   TFile *endfile = new TFile("outFiles/Application_1/Conv_Input_47/BDTtree2.root","RECREATE");   
   
   endfile->cd();

   PsetInputsTree->Write();
   endfile->cd();

   endfile->mkdir("dileptonEventFilter/");

   endfile->mkdir("dileptonEventFilter/EventCount/");
   endfile->cd("dileptonEventFilter/EventCount/");


   //EventCounter->Write();

   endfile->cd();

   endfile->mkdir("dileptonEventFilter/TrueNumInteractionsBX0/");
   endfile->cd("dileptonEventFilter/TrueNumInteractionsBX0/");



   PileUpProfile->Write();

   endfile->cd();

   endfile->mkdir("rootTupleTreeVeryLoose/");
   endfile->cd("rootTupleTreeVeryLoose/");
   TTree *found_back_tree = tree->CloneTree(0);

   std::vector<float> *BDTResponse1 = new std::vector<float>(0);
   found_back_tree->Branch("SeesawBDT300_2_19_19",&BDTResponse1);
    std::vector<float> *BDTResponse2 = new std::vector<float>(0);
   found_back_tree->Branch("SeesawBDT700_2_19_19",&BDTResponse2);
    std::vector<float> *BDTResponse3 = new std::vector<float>(0);
   found_back_tree->Branch("SeesawBDT1250_2_19_19",&BDTResponse3);

   std::vector<float> vecVar(4); // vector for EvaluateMVA tests

   std::cout << "--- Processing: " << tree->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   int count = 0;
   
   while (myReader.Next()) {

      if (count%1000 == 0) std::cout << "--- ... Processing event: " << count << std::endl;
      
      //This will get entries to fill nonspecified branches in the cloned tree.
      tree->GetEntry(count);
      
      HT=0;
      for(std::vector<float>::iterator jetpt = inJetPt->begin(); jetpt != inJetPt->end(); ++jetpt){
         HT += *jetpt;
      }


      if(inLightLeptonPhi->size()>=3){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = inLightLeptonPhi->at(1);
         LightLeptonPhi2 = inLightLeptonPhi->at(2);
      }else if(inLightLeptonPhi->size()==2){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = inLightLeptonPhi->at(1);
         LightLeptonPhi2 = 0;
      }else if(inLightLeptonPhi->size()==1){
         LightLeptonPhi0 = inLightLeptonPhi->at(0);
         LightLeptonPhi1 = 0;
         LightLeptonPhi2 = 0;
      }else{
         LightLeptonPhi0 = 0;
         LightLeptonPhi1 = 0;
         LightLeptonPhi2 = 0;
      }

      if(inLightLeptonDXY->size()>=3){
         LightLeptonDXY0 = inLightLeptonDXY->at(0);
         LightLeptonDXY1 = inLightLeptonDXY->at(1);
         LightLeptonDXY2 = inLightLeptonDXY->at(2);
      }else if(inLightLeptonDXY->size()==2){
         LightLeptonDXY0 = inLightLeptonDXY->at(0);
         LightLeptonDXY1 = inLightLeptonDXY->at(1);
         LightLeptonDXY2 = 0;
      }else if(inLightLeptonDXY->size()==1){
         LightLeptonDXY0 = inLightLeptonDXY->at(0);
         LightLeptonDXY1 = 0;
         LightLeptonDXY2 = 0;
      }else{
         LightLeptonDXY0 = 0;
         LightLeptonDXY1 = 0;
         LightLeptonDXY2 = 0;
      }



      if(inLightLeptonBestMSSSF->empty()){
         LightLeptonBestMSSSF = 0;
      }else{
         LightLeptonBestMSSSF = inLightLeptonBestMSSSF->at(0);
      }


      if(inLightLeptonPairPt->empty()){
         LightLeptonPairPt = 0;
      }else{
         LightLeptonPairPt = inLightLeptonPairPt->at(0);
      }
      if(inLightLeptonPairDR->size()>=3){
         LightLeptonPairDR0 = inLightLeptonPairDR->at(0);
         LightLeptonPairDR1 = inLightLeptonPairDR->at(1);
         LightLeptonPairDR2 = inLightLeptonPairDR->at(2);
      }else if(inLightLeptonPairDR->size()==2){
         LightLeptonPairDR0 = inLightLeptonPairDR->at(0);
         LightLeptonPairDR1 = inLightLeptonPairDR->at(1);
         LightLeptonPairDR2 = 0;
      }else if(inLightLeptonPairDR->size()==1){
         LightLeptonPairDR0 = inLightLeptonPairDR->at(0);
         LightLeptonPairDR1 = 0;
         LightLeptonPairDR2 = 0;
      }else{
         LightLeptonPairDR0 = 0;
         LightLeptonPairDR1 = 0;
         LightLeptonPairDR2 = 0;
      }

      if(*inMT3<0){
         MT3 = 0;
      }else{
         MT3 = *inMT3;
      }
      //START
      if(*inMET<0){
         MET = 0;
      }else{
         MET = *inMET;
      }

      if(inLightLeptonMass->empty()){
         LightLeptonMass = 0;
      }else{
         LightLeptonMass = inLightLeptonMass->at(0);
      }

      if(inLightLeptonBestMOSSF->empty()){
         LightLeptonBestMOSSF = 0;
      }else{
         LightLeptonBestMOSSF = inLightLeptonBestMOSSF->at(0);
      }

      if(inLightLeptonN->empty()){
         LightLeptonN = 0;
      }else{
         LightLeptonN = inLightLeptonN->at(0);
      }
      if(inMuonN->empty()){
         MuonN = 0;
      }else{
         MuonN = inMuonN->at(0);
      }

      if(inElectronN->empty()){
         ElectronN = 0;
      }else{
         ElectronN = inElectronN->at(0);
      }


      if(*inLT<0){
         LT = 0;
      }else{
         LT = *inLT;
      }


      if(inJetN->empty()){
         JetN = 0;
      }else{
         JetN = inJetN->at(0);
      }

      if(inLightLeptonPt->size()>=4){
         LightLeptonPt0 = inLightLeptonPt->at(0);
         LightLeptonPt1 = inLightLeptonPt->at(1);
         LightLeptonPt2 = inLightLeptonPt->at(2);
         LightLeptonPt3 = inLightLeptonPt->at(3);
      }else if(inLightLeptonPt->size()==3){
         LightLeptonPt0 = inLightLeptonPt->at(0);
         LightLeptonPt1 = inLightLeptonPt->at(1);
         LightLeptonPt2 = inLightLeptonPt->at(2);
         LightLeptonPt3 = 0;
      }else if(inLightLeptonPt->size()==2){
         LightLeptonPt0 = inLightLeptonPt->at(0);
         LightLeptonPt1 = inLightLeptonPt->at(1);
         LightLeptonPt2 = 0;
         LightLeptonPt3 = 0;
      }else if(inLightLeptonPt->size()==1){
         LightLeptonPt0 = inLightLeptonPt->at(0);
         LightLeptonPt1 = 0;
         LightLeptonPt2 = 0;
         LightLeptonPt3 = 0;
      }else{
         LightLeptonPt0 = 0;
         LightLeptonPt1 = 0;
         LightLeptonPt2 = 0;
         LightLeptonPt3 = 0;
      }

      if(inLightLeptonEta->size()>=4){
         LightLeptonEta0 = inLightLeptonEta->at(0);
         LightLeptonEta1 = inLightLeptonEta->at(1);
         LightLeptonEta2 = inLightLeptonEta->at(2);
         LightLeptonEta3 = inLightLeptonEta->at(3);
      }else if(inLightLeptonEta->size()==3){
         LightLeptonEta0 = inLightLeptonEta->at(0);
         LightLeptonEta1 = inLightLeptonEta->at(1);
         LightLeptonEta2 = inLightLeptonEta->at(2);
         LightLeptonEta3 = 0;
      }else if(inLightLeptonEta->size()==2){
         LightLeptonEta0 = inLightLeptonEta->at(0);
         LightLeptonEta1 = inLightLeptonEta->at(1);
         LightLeptonEta2 = 0;
         LightLeptonEta3 = 0;
      }else if(inLightLeptonEta->size()==1){
         LightLeptonEta0 = inLightLeptonEta->at(0);
         LightLeptonEta1 = 0;
         LightLeptonEta2 = 0;
         LightLeptonEta3 = 0;
      }else{
         LightLeptonEta0 = 0;
         LightLeptonEta1 = 0;
         LightLeptonEta2 = 0;
         LightLeptonEta3 = 0;
      }



      if(inLightLeptonFlavor->size()>=4){
         LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
         LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
         LightLeptonFlavor2 = inLightLeptonFlavor->at(2);
         LightLeptonFlavor3 = inLightLeptonFlavor->at(3);
      }else if(inLightLeptonFlavor->size()==3){
         LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
         LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
         LightLeptonFlavor2 = inLightLeptonFlavor->at(2);
         LightLeptonFlavor3 = 0;
      }else if(inLightLeptonFlavor->size()==2){
         LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
         LightLeptonFlavor1 = inLightLeptonFlavor->at(1);
         LightLeptonFlavor2 = 0;
         LightLeptonFlavor3 = 0;
      }else if(inLightLeptonFlavor->size()==1){
         LightLeptonFlavor0 = inLightLeptonFlavor->at(0);
         LightLeptonFlavor1 = 0;
         LightLeptonFlavor2 = 0;
         LightLeptonFlavor3 = 0;
      }else{
         LightLeptonFlavor0 = 0;
         LightLeptonFlavor1 = 0;
         LightLeptonFlavor2 = 0;
         LightLeptonFlavor3 = 0;
      }

      // if(inLightLeptonNativeIndex->size()>=4){
      //    LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
      //    LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
      //    LightLeptonNativeIndex2 = inLightLeptonNativeIndex->at(2);
      //    LightLeptonNativeIndex3 = inLightLeptonNativeIndex->at(3);
      // }else if(inLightLeptonNativeIndex->size()==3){
      //    LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
      //    LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
      //    LightLeptonNativeIndex2 = inLightLeptonNativeIndex->at(2);
      //    LightLeptonNativeIndex3 = 0;
      // }else if(inLightLeptonNativeIndex->size()==2){
      //    LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
      //    LightLeptonNativeIndex1 = inLightLeptonNativeIndex->at(1);
      //    LightLeptonNativeIndex2 = 0;
      //    LightLeptonNativeIndex3 = 0;
      // }else if(inLightLeptonNativeIndex->size()==1){
      //    LightLeptonNativeIndex0 = inLightLeptonNativeIndex->at(0);
      //    LightLeptonNativeIndex1 = 0;
      //    LightLeptonNativeIndex2 = 0;
      //    LightLeptonNativeIndex3 = 0;
      // }else{
      //    LightLeptonNativeIndex0 = 0;
      //    LightLeptonNativeIndex1 = 0;
      //    LightLeptonNativeIndex2 = 0;
      //    LightLeptonNativeIndex3 = 0;
      // }

      // PtRatio1 = PtRatio(LightLeptonPt0,LightLeptonPt1,LightLeptonPt2);
      // PtRatio2 = PtRatio(LightLeptonPt1,LightLeptonPt0,LightLeptonPt2);
      // PtRatio3 = PtRatio(LightLeptonPt2,LightLeptonPt0,LightLeptonPt1);

      // PtRatio4L1 = PtRatio4(LightLeptonPt0,LightLeptonPt1,LightLeptonPt2,LightLeptonPt3);
      // PtRatio4L2 = PtRatio4(LightLeptonPt1,LightLeptonPt0,LightLeptonPt2,LightLeptonPt3);
      // PtRatio4L3 = PtRatio4(LightLeptonPt2,LightLeptonPt0,LightLeptonPt1,LightLeptonPt3);
      // PtRatio4L4 = PtRatio4(LightLeptonPt3,LightLeptonPt1,LightLeptonPt2,LightLeptonPt0);

      // DPhi1 = DeltaPhi(LightLeptonEta0,LightLeptonEta1);
      // DPhi2 = DeltaPhi(LightLeptonEta1,LightLeptonEta2);
      // DPhi3 = DeltaPhi(LightLeptonEta2,LightLeptonEta0);
      // DPhi4 = DeltaPhi(LightLeptonEta0,LightLeptonEta3);
      // DPhi5 = DeltaPhi(LightLeptonEta1,LightLeptonEta3);
      // DPhi6 = DeltaPhi(LightLeptonEta2,LightLeptonEta3);

      // LightLeptonDXY0 = LightLeptonDXY(0, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);
      // LightLeptonDXY1 = LightLeptonDXY(1, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);
      // LightLeptonDXY2 = LightLeptonDXY(2, MuonDXY0,MuonDXY1,MuonDXY2, ElectronDXY0,ElectronDXY1,ElectronDXY2, LightLeptonFlavor0, LightLeptonNativeIndex0);

      ST=LT+MET+HT;

      // metHtRatio=metRatio(MET,HT);
      // metStRatio=metRatio(MET,ST);
      // metLtRatio=metRatio(MET,LT);

      // metHtSquaredRatio=metSquaredRatio(MET,HT);
      // metSquaredStRatio=metSquaredRatio(MET,ST);
      // metLtSquaredRatio=metSquaredRatio(MET,LT);

      // metHtQuadRatio=metQuadRatio(MET,HT);
      // metQuadStRatio=metQuadRatio(MET,ST);
      // metLtQuadRatio=metQuadRatio(MET,LT);

      BJetN = 0;
      int countEta=0;
      for(std::vector<float>::iterator tag = inJetCombinedInclusiveSecondaryVertexV2BJetTags->begin(); tag != inJetCombinedInclusiveSecondaryVertexV2BJetTags->end(); ++tag){
         if(*tag>.84&&fabs(inJetEta->at(countEta))<2.4){
            BJetN++;
         }
         countEta++;
      }


      float result1 =  reader1->EvaluateMVA( "BDTG method" );
      float result2 =  reader2->EvaluateMVA( "BDTG method" );
      float result3 =  reader3->EvaluateMVA( "BDTG method" );

      BDTResponse1->clear();
      BDTResponse1->push_back(result1);
      BDTResponse2->clear();
      BDTResponse2->push_back(result2);
      BDTResponse3->clear();
      BDTResponse3->push_back(result3);
      found_back_tree->Fill();
      count++;

   }
   
   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: "; sw.Print();

   
   std::cout << "Printing out all passed events... " << std::endl;
   

   std::cout << "BDT: \n"<< vecBDTG.size() << "\t passed events" << std::endl;

   
   found_back_tree->Write();
   

   
   endfile->Close();               
  
   delete reader1;
   delete reader2;
   delete reader3;
    


}

void Application_2016_2( TString myMethodList = "" ) 
{   

   TMVA::Tools::Instance();



   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   TString back_name = "/cms/mchristos/software/CMSSW_10_3_ROOT614_X_2018-09-16-0000/pyPlotterSeesaw/pyplotter/runPlotter_3L_27bins_NTuplePlotter_2016_MakeSkims/InputBundle_Conv_Input_47_Tree.root";


   runBackground(back_name);
   std::cout << "==> TMVAClassificationApplication is done!" << endl << std::endl;
} 