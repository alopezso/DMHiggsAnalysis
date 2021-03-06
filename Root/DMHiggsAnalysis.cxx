#include "DMHiggsAnalysis/DMHiggsAnalysis.h"
#include "HGamAnalysisFramework/HgammaIncludes.h"

// this is needed to distribute the algorithm to the workers
ClassImp(DMHiggsAnalysis)



DMHiggsAnalysis::DMHiggsAnalysis(const char *name)
    : HgammaAnalysis(name)
{
    // Here you put any code for the base initialization of variables,
    // e.g. initialize all pointers to 0.  Note that you should only put
    // the most basic initialization here, since this method will be
    // called on both the submission and the worker node.  Most of your
    // initialization code will go into histInitialize() and
    // initialize().


}



DMHiggsAnalysis::~DMHiggsAnalysis()
{
    // Here you delete any memory you allocated during your analysis.
}



EL::StatusCode DMHiggsAnalysis::createOutput()
{
    // Here you setup the histograms needed for you analysis. This method
    // gets called after the Handlers are initialized, so that the systematic
    // registry is already filled.

  histoStore()->createTH1F("m_yy", 60, 110, 140);
  
  
  //Create a TTree
  //  TFile *outfile = wk()->getOutputFile("MxAOD");
  
  
    return EL::StatusCode::SUCCESS;
}


void DMHiggsAnalysis::declareVariables(){

  myEvents->Branch("RunNumber",&RunNumber,"RunNumber/I"); 
  myEvents->Branch("LumiBlock",&LumiBlock,"LumiBlock/I"); 
  myEvents->Branch("EventNumber",&EventNumber,"EventNumber/I"); 
  myEvents->Branch("mcEventWeights",&mcEventWeights_var,"mcEventWeights_var/F");

  myEvents->Branch("mcID",&mcID_var,"mcID_var/I"); 
  myEvents->Branch("NPV",&NPV_var,"NPV_var/I"); 
  myEvents->Branch("mu",&mu_var,"mu_var/I"); 
  myEvents->Branch("isMC",&isMC_var,"isMC_var/I"); 
  myEvents->Branch("initWeight",&initWeight_var,"initWeight_var/I"); 
  myEvents->Branch("xsectionBRfilterEff",&xsecBrFilterEff_var,"xsecBrFilterEff_var/F");
  // myEvents->Branch("myy",&myy_var,"/I"); 
  // myEvents->Branch("phi_yy_met",&phi_yy_met_var,"/F"); 
  // myEvents->Branch("phi_yyj_met",&phi_yyj_met_var,"/F"); 
  // myEvents->Branch("phi_yyjj_met",&phi_yyjj_met_var,"/F"); 
  // myEvents->Branch("phi_jj_met",&phi_jj_met_var,"/F"); 
  // myEvents->Branch("phi_yy_jj",&phi_yy_jj_var,"/F"); 
  // myEvents->Branch("phi_y1_j",&phi_y1_j_var,"/F"); 
  // myEvents->Branch("phi_y2_j",&phi_y2_j_var,"/F"); 
  // myEvents->Branch("phi_y1_met",&phi_y1_met_var,"/F"); 
  // myEvents->Branch("phi_y2_met",&phi_y2_met_var,"/F");  
  // myEvents->Branch("phi_y1_y2",&phi_y1_y2_var,"/F");  
  // myEvents->Branch("phi_j1_j2",&phi_j1_j2_var,"/F");  
  // myEvents->Branch("phi_allparticles_met",&phi_allparticles_met_var,"/F"); 
  myEvents->Branch("metSig",&metSig_var,"metSig_var/F"); 
  myEvents->Branch("passDiphotonToHardestVertexZCut",&passVertex_var,"passVertex_var/I"); 
  myEvents->Branch("passHiggsSelection",&passHiggsSelection_var,"passHiggsSelection_var/I"); 
  myEvents->Branch("passQualityCuts",&passQualityCuts_var,"passQualityCuts_var/I"); 


  myEvents->Branch("nPhotons", &nPhotons,"nPhotons/I");
  //  myEvents->Branch("photonAuthor", photonAuthor,"photonAuthor[nPhotons]/I");
  myEvents->Branch("photonPx", photonPx,"photonPx[nPhotons]/F");
  myEvents->Branch("photonPy", photonPy,"photonPy[nPhotons]/F");
  myEvents->Branch("photonPz", photonPz,"photonPz[nPhotons]/F");
  myEvents->Branch("photonE",  photonE, "photonE[nPhotons]/F");
  myEvents->Branch("photons_Eps",photons_Eps,"photon_Eps[nPhotons]/F");
  myEvents->Branch("photons_E1",photons_E1,"photons_E1[nPhotons]/F");
  myEvents->Branch("photons_E2",photons_E2,"photons_E2[nPhotons]/F");
  myEvents->Branch("photons_E3",photons_E3,"photons_E3[nPhotons]/F");
  myEvents->Branch("photons_conversion",photons_conversionType,"photons_conversionType[nPhotons]/I");
  myEvents->Branch("photons_conversionRadius",photons_conversionRadius,"photons_conversionRadius[nPhotons]/F");
  myEvents->Branch("photon_isTight", photons_isTight,"photons_isTight[nPhotons]/I");
  myEvents->Branch("photon_isLoose", photons_isLoose,"photons_isLoose[nPhotons]/I");
  myEvents->Branch("photon_isLoosePrime2", photons_isLoosePrime2,"photons_isLoosePrime2[nPhotons]/I");
  myEvents->Branch("photon_isLoosePrime3", photons_isLoosePrime3,"photons_isLoosePrime3[nPhotons]/I");
  myEvents->Branch("photon_isLoosePrime4", photons_isLoosePrime4,"photons_isLoosePrime4[nPhotons]/I");
  myEvents->Branch("photon_isLoosePrime5", photons_isLoosePrime5,"photons_isLoosePrime5[nPhotons]/I");
  myEvents->Branch("photon_isIsoFixedCutTight",  photons_isIsoFixedCutTight, "photons_isIsoFixedCutTight[nPhotons]/I");
  myEvents->Branch("photons_isIsoFixedCutTightCaloOnly",photons_isIsoFixedCutTightCaloOnly,"photons_isIsoFixedCutTightCaloOnly[nPhotons]/I");
  myEvents->Branch("photons_isIsoFixedCutLooseCaloOnly",photons_isIsoFixedCutLooseCaloOnly,"photons_isIsoFixedCutLooseCaloOnly[nPhotons]/I");
  myEvents->Branch("photons_isIsoFixedCutLoose",photons_isIsoFixedCutLoose,"photons_isIsoFixedCutLoose[nPhotons]/I");
  myEvents->Branch("photons_topoCone20",photons_topoCone20,"photons_topoCone20[nPhotons]/F");
  myEvents->Branch("photons_topoCone40",photons_topoCone40,"photons_topoCone40[nPhotons]/F");
  myEvents->Branch("photons_Cone20",photons_Cone20,"photons_Cone20[nPhotons]/F");
  myEvents->Branch("photons_Cone40",photons_Cone40,"photons_Cone40[nPhotons]/F");

  myEvents->Branch("nElectrons", &nElectrons,"nElectrons/I");
  //  myEvents->Branch("electronAuthor", electronAuthor,"electronAuthor[nElectrons]/I");
  myEvents->Branch("electronPx", electronPx,"electronPx[nElectrons]/F");
  myEvents->Branch("electronPy", electronPy,"electronPy[nElectrons]/F");
  myEvents->Branch("electronPz", electronPz,"electronPz[nElectrons]/F");
  myEvents->Branch("electronE",  electronE, "electronE[nElectrons]/F");
  myEvents->Branch("electrons_Eps",electrons_Eps,"electron_Eps[nElectrons]/F");
  myEvents->Branch("electrons_E1",electrons_E1,"electrons_E1[nElectrons]/F");
  myEvents->Branch("electrons_E2",electrons_E2,"electrons_E2[nElectrons]/F");
  myEvents->Branch("electrons_E3",electrons_E3,"electrons_E3[nElectrons]/F");
  myEvents->Branch("electrons_charge",electrons_charge,"electrons_charge[nElectrons]/F");
  myEvents->Branch("electron_isTight", electrons_isTight,"electrons_isTight[nElectrons]/I");
  myEvents->Branch("electron_isMedium", electrons_isMedium,"electrons_isMedium[nElectrons]/I");
  myEvents->Branch("electron_isIsoLoose", electrons_isIsoLoose,"electrons_isIsoLoose[nElectrons]/I");
  myEvents->Branch("electrons_ptvarCone20",electrons_ptvarCone20,"electrons_ptvarCone20[nElectrons]/F");
  myEvents->Branch("electrons_topoCone20",electrons_topoCone20,"electrons_topoCone20[nElectrons]/F");


  myEvents->Branch("nMuons", &nMuons,"nMuons/I");
  //  myEvents->Branch("muonAuthor", muonAuthor,"muonAuthor[nMuons]/I");
  myEvents->Branch("muonPx", muonPx,"muonPx[nMuons]/F");
  myEvents->Branch("muonPy", muonPy,"muonPy[nMuons]/F");
  myEvents->Branch("muonPz", muonPz,"muonPz[nMuons]/F");
  myEvents->Branch("muonE",  muonE, "muonE[nMuons]/F");
  myEvents->Branch("muons_charge",muons_charge,"muons_charge[nMuons]/F");
  myEvents->Branch("muon_passIPcut", muons_passIPcut,"muons_passIPcut[nMuons]/I");
  myEvents->Branch("muon_isTight", muons_isTight,"muons_isTight[nMuons]/I");
  myEvents->Branch("muon_isMedium", muons_isMedium,"muons_isMedium[nMuons]/I");
  myEvents->Branch("muon_isLoose", muons_isLoose,"muons_isLoose[nMuons]/I");
  myEvents->Branch("muon_isIsoGradientLoose", muons_isIsoGradientLoose,"muons_isIsoGradientLoose[nMuons]/I");
  myEvents->Branch("muon_isIsoGradient", muons_isIsoGradient,"muons_isIsoGradient[nMuons]/I");
  myEvents->Branch("muon_isIsoLoose", muons_isIsoLoose,"muons_isIsoLoose[nMuons]/I");
  myEvents->Branch("muons_ptvarCone20",muons_ptvarCone20,"muons_ptvarCone20[nMuons]/F");
  myEvents->Branch("muons_topoCone20",muons_topoCone20,"muons_topoCone20[nMuons]/F");


  myEvents->Branch("nJets", &nJets,"nJets/I");
  myEvents->Branch("jetPx", jetPx,"jetPx[nJets]/F");
  myEvents->Branch("jetPy", jetPy,"jetPy[nJets]/F");
  myEvents->Branch("jetPz", jetPz,"jetPz[nJets]/F");
  myEvents->Branch("jetJvt",  jetJvt, "jetJvt[nJets]/F");
  myEvents->Branch("jetPassSelection",  jetPassSelection, "jetPassSelection[nJets]/I");

  myEvents->Branch("met", &met,"met/F");
  myEvents->Branch("sumet", &sumet,"sumet/F");
  myEvents->Branch("phi_met", &phi_met,"phi_met/F");


  myEvents->Branch("ntruthPhotons", &ntruthPhotons,"ntruthPhotons/I");
  myEvents->Branch("photonTruthPx", photonTruthPx,"photonTruthPx[ntruthPhotons]/F");
  myEvents->Branch("photonTruthPy", photonTruthPy,"photonTruthPy[ntruthPhotons]/F");
  myEvents->Branch("photonTruthPz", photonTruthPz,"photonTruthPz[ntruthPhotons]/F");
  myEvents->Branch("photonTruthE",  photonTruthE, "photonTruthE[ntruthPhotons]/F");
  myEvents->Branch("photonTruth_ptcone20",photonTruth_ptcone20,"photonTruth_ptcone20[ntruthPhotons]/F");
  myEvents->Branch("photonTruth_ptcone40",photonTruth_ptcone40,"photonTruth_ptcone40[ntruthPhotons]/F");
  myEvents->Branch("photonTruth_etcone20",photonTruth_etcone20,"photonTruth_etcone20[ntruthPhotons]/F");
  myEvents->Branch("photonTruth_etcone40",photonTruth_etcone40,"photonTruth_etcone40[ntruthPhotons]/F");
  myEvents->Branch("photonTruth_truthOrigin",photonTruth_truthOrigin,"photonTruth_truthOrigin[ntruthPhotons]/I");
  myEvents->Branch("photonTruth_truthType",photonTruth_truthType,"photonTruth_truthType[ntruthPhotons]/I");

  myEvents->Branch("ntruthElectrons", &ntruthElectrons,"ntruthElectrons/I");
  myEvents->Branch("electronTruthPx", electronTruthPx,"electronTruthPx[ntruthElectrons]/F");
  myEvents->Branch("electronTruthPy", electronTruthPy,"electronTruthPy[ntruthElectrons]/F");
  myEvents->Branch("electronTruthPz", electronTruthPz,"electronTruthPz[ntruthElectrons]/F");
  myEvents->Branch("electronTruthE",  electronTruthE, "electronTruthE[ntruthElectrons]/F");

  myEvents->Branch("ntruthMuons", &ntruthMuons,"ntruthMuons/I");
  myEvents->Branch("muonTruthPx", muonTruthPx,"muonTruthPx[ntruthMuons]/F");
  myEvents->Branch("muonTruthPy", muonTruthPy,"muonTruthPy[ntruthMuons]/F");
  myEvents->Branch("muonTruthPz", muonTruthPz,"muonTruthPz[ntruthMuons]/F");
  myEvents->Branch("muonTruthE",  muonTruthE, "muonTruthE[ntruthMuons]/F");

  myEvents->Branch("ntruthJets", &ntruthJets,"ntruthJets/I");
  myEvents->Branch("jetTruthPx", jetTruthPx,"jetTruthPx[ntruthJets]/F");
  myEvents->Branch("jetTruthPy", jetTruthPy,"jetTruthPy[ntruthJets]/F");
  myEvents->Branch("jetTruthPz", jetTruthPz,"jetTruthPz[ntruthJets]/F");
  myEvents->Branch("jetTruthE",  jetTruthE, "jetTruthE[ntruthJets]/F");

  myEvents->Branch("mpxTruthInt", &mpxTruthInt,"mpxTruthInt/F");
  myEvents->Branch("mpyTruthInt", &mpyTruthInt,"mpyTruthInt/F");
  myEvents->Branch("metTruthInt", &metTruthInt,"metTruthInt/F");
  myEvents->Branch("sumetTruthInt",  &sumetTruthInt, "sumetTruthInt/F");
  myEvents->Branch("mpxTruthNonInt", &mpxTruthNonInt,"mpxTruthNonInt/F");
  myEvents->Branch("mpyTruthNonInt", &mpyTruthNonInt,"mpyTruthNonInt/F");
  myEvents->Branch("metTruthNonInt", &metTruthNonInt,"metTruthNonInt/F");
  myEvents->Branch("sumetTruthNonInt",  &sumetTruthNonInt, "sumetTruthNonInt/F");
}


void DMHiggsAnalysis::clearVectors(){


  for( int iparticle = 0 ; iparticle < MAXPARTICLES ; ++iparticle){

    //    photonAuthor[iparticle] =  - 9999;
    photonPx[iparticle] =  - 9999;
    photonE[iparticle] =  - 9999;
    photonPy[iparticle] =  - 9999;
    photonPz[iparticle] =  - 9999;
    photons_Eps[iparticle] =  - 9999;
    photons_E1[iparticle] =  - 9999;
    photons_E2[iparticle] =  - 9999;
    photons_E3[iparticle] =  - 9999;

    photons_conversionType[iparticle] =  - 9999;
    photons_isTight[iparticle] =  - 9999;
    photons_isLoose[iparticle] =  - 9999;
    photons_isLoosePrime2[iparticle] =  - 9999;
    photons_isLoosePrime3[iparticle] =  - 9999;
    photons_isLoosePrime4[iparticle] =  - 9999;
    photons_isLoosePrime5[iparticle] =  - 9999;

    photons_isIsoFixedCutTight[iparticle] =  - 9999;
    photons_isIsoFixedCutTightCaloOnly[iparticle] =  - 9999;
    photons_isIsoFixedCutLooseCaloOnly[iparticle] =  - 9999;
    photons_isIsoFixedCutLoose[iparticle] =  - 9999;
    photons_Cone20[iparticle] =  - 9999;
    photons_Cone40[iparticle] =  - 9999;
    photons_topoCone20[iparticle] =  - 9999;
    photons_topoCone40[iparticle] =  - 9999;

    //electronAuthor[iparticle] =  - 9999;
    electronPx[iparticle] =  - 9999;
    electronE[iparticle] =  - 9999;
    electronPy[iparticle] =  - 9999;
    electronPz[iparticle] =  - 9999;
    electrons_Eps[iparticle] =  - 9999;
    electrons_E1[iparticle] =  - 9999;
    electrons_E2[iparticle] =  - 9999;
    electrons_E3[iparticle] =  - 9999;

    electrons_isTight[iparticle] =  - 9999;
    electrons_isMedium[iparticle] =  - 9999;
    electrons_isIsoLoose[iparticle] =  - 9999;
    electrons_topoCone20[iparticle] =  - 9999;
    electrons_ptvarCone20[iparticle] =  - 9999;

    //muonAuthor[iparticle] =  - 9999;
    muonPx[iparticle] =  - 9999;
    muonE[iparticle] =  - 9999;
    muonPy[iparticle] =  - 9999;
    muonPz[iparticle] =  - 9999;

    muons_passIPcut[iparticle] =  - 9999;
    muons_isLoose[iparticle] =  - 9999;
    muons_isTight[iparticle] =  - 9999;
    muons_isMedium[iparticle] =  - 9999;
    muons_isIsoGradientLoose[iparticle] =  - 9999;
    muons_isIsoGradient[iparticle] =  - 9999;
    muons_isIsoLoose[iparticle] =  - 9999;
    muons_topoCone20[iparticle] =  - 9999;
    muons_ptvarCone20[iparticle] =  - 9999;

    //jetAuthor[iparticle] =  - 9999;
    jetPx[iparticle] =  - 9999;
    jetJvt[iparticle] =  - 9999;
    jetPy[iparticle] =  - 9999;
    jetPz[iparticle] =  - 9999;
    jetPassSelection[iparticle] =  - 9999;



    photonTruthPx[iparticle] =  - 9999;
    photonTruthE[iparticle] =  - 9999;
    photonTruthPy[iparticle] =  - 9999;
    photonTruthPz[iparticle] =  - 9999;
    photonTruth_etcone20[iparticle] =  - 9999;
    photonTruth_etcone40[iparticle] =  - 9999;
    photonTruth_ptcone20[iparticle] =  - 9999;
    photonTruth_ptcone40[iparticle] =  - 9999;
    photonTruth_truthOrigin[iparticle] =  - 9999;
    photonTruth_truthType[iparticle] =  - 9999;


    electronTruthPx[iparticle] =  - 9999;
    electronTruthE[iparticle] =  - 9999;
    electronTruthPy[iparticle] =  - 9999;
    electronTruthPz[iparticle] =  - 9999;

    muonTruthPx[iparticle] =  - 9999;
    muonTruthE[iparticle] =  - 9999;
    muonTruthPy[iparticle] =  - 9999;
    muonTruthPz[iparticle] =  - 9999;


    jetTruthPx[iparticle] =  - 9999;
    jetTruthE[iparticle] =  - 9999;
    jetTruthPy[iparticle] =  - 9999;
    jetTruthPz[iparticle] =  - 9999;

    mpxTruthInt =  - 9999;
    mpyTruthInt =  - 9999;
    metTruthInt =  - 9999;
    sumetTruthInt =  - 9999;
    mpxTruthNonInt =  - 9999;
    mpyTruthNonInt =  - 9999;
    metTruthNonInt =  - 9999;
    sumetTruthNonInt =  - 9999;
  }

}

EL::StatusCode DMHiggsAnalysis::initialize()
{


  HgammaAnalysis::initialize();

  std::string inputfileName = wk()->inputFileName();
  currentfilename = inputfileName;
  inputfileName.replace(inputfileName.find(".MxAOD") , -1, "") ;
  inputfileName.append(".NTuple.root");




  m_outputFile = TFile::Open(inputfileName.c_str(),"RECREATE");
  myEvents = new TTree("DMHiggsAnalysis","DMHiggsAnalysis");

  // m_outputFiles[currentfilename] = TFile::Open(inputfileName.c_str(),"RECREATE");

  // inputfileName.replace(inputfileName.find(".NTuple.root") , -1, ".Tree");

  // myEvents = new TTree(inputfileName.c_str(),"DMHiggsAnalysis");

  // m_outputTTree[currentfilename] = myEvents;



  //  wk()->addOutput( m_outputFiles[inputfileName] );


  //myEvents->SetDirectory(outFile);

  declareVariables();

  m_muonTightSelectionTool = new CP::MuonSelectionTool("MuonTightSelectionTool");
  m_muonMediumSelectionTool = new CP::MuonSelectionTool("MuonMediumSelectionTool");
  m_muonLooseSelectionTool = new CP::MuonSelectionTool("MuonLooseSelectionTool");

  CP_CHECK( "initialize()" , m_muonTightSelectionTool->setProperty("MuQuality", int(xAOD::Muon::Tight)) );
  CP_CHECK( "initialize()" , m_muonMediumSelectionTool->setProperty("MuQuality", int(xAOD::Muon::Medium)) );
  CP_CHECK( "initialize()" , m_muonLooseSelectionTool->setProperty("MuQuality", int(xAOD::Muon::Loose)) );

  if( m_muonTightSelectionTool->initialize().isFailure() )
    HG::fatal("Couldn't initalize MuonSelectionTool for tight WP. Exiting");
  if( m_muonMediumSelectionTool->initialize().isFailure() )
    HG::fatal("Couldn't initalize MuonSelectionTool for medium WP. Exiting");
  if( m_muonLooseSelectionTool->initialize().isFailure() )
    HG::fatal("Couldn't initalize MuonSelectionTool for loose WP. Exiting");


  return EL::StatusCode::SUCCESS;
}
EL::StatusCode DMHiggsAnalysis::execute()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  // Important to keep this, so that internal tools / event variables
  // are filled properly.

  HgammaAnalysis::execute();


  SG::AuxElement::Accessor<unsigned int> runNumber("runNumber");
  SG::AuxElement::Accessor<unsigned int> lumiBlock("lumiBlock");
  SG::AuxElement::Accessor<unsigned long long> eventNumber("eventNumber");
  SG::AuxElement::Accessor< std::vector<float> > mcEventWeights("mcEventWeights");

  SG::AuxElement::Accessor<int> NPV("numberOfPrimaryVertices");
  SG::AuxElement::Accessor<float> mu("mu");
  SG::AuxElement::Accessor<float> initWeight("weightInitial");
  SG::AuxElement::Accessor<float> crossSectionBRflterEff("crossSectionBRfilterEff");
  //  SG::AuxElement::Accessor<float> TotalWeight("TotalWeight");
  SG::AuxElement::Accessor<float> myy("m_yy");
  SG::AuxElement::Accessor<float> met_sumet("sumet_TST");
  SG::AuxElement::Accessor<float> met_phi("phi_TST");
  SG::AuxElement::Accessor<float> met_TST("met_TST");
  SG::AuxElement::Accessor<float> phi_allparticles_met("DeltaPhi_allPart_MET");
  SG::AuxElement::Accessor<float> photons_ePS("E0_raw");
  SG::AuxElement::Accessor<float> photons_e1("E1_raw");
  SG::AuxElement::Accessor<float> photons_e2("E2_raw");
  SG::AuxElement::Accessor<float> photons_e3("E3_raw");
  SG::AuxElement::Accessor<int> photons_converted("conversionType");
  SG::AuxElement::Accessor<float> photons_convertedRadius("conversionRadius");
  SG::AuxElement::Accessor<float> hardestVertex("hardestVertexZ");
  SG::AuxElement::Accessor<float> selectedVertex("selectedVertexZ");
  SG::AuxElement::Accessor<char> passHiggsSelection("isPassed");
  SG::AuxElement::Accessor<char> passQualityCuts("isPassedBasic");
  SG::AuxElement::Accessor<char> passDoubleHiggsSelection("isPassedLowHighMyy");

  SG::AuxElement::Accessor<float> ptvarCone20("ptvarcone20");
  SG::AuxElement::Accessor<float> topoetCone20("topoetcone20");
  SG::AuxElement::Accessor<float> topoetCone40("topoetcone40");
  SG::AuxElement::Accessor<float> etCone20("topoetcone20");
  SG::AuxElement::Accessor<float> etCone40("topoetcone40");
  SG::AuxElement::Accessor<float> ptCone20("ptcone20");
  SG::AuxElement::Accessor<float> ptCone40("ptcone40");
  SG::AuxElement::Accessor<int> truthType("truthType");
  SG::AuxElement::Accessor<int> truthOrigin("truthOrigin");
  SG::AuxElement::Accessor<char> isisoFixedCutTight("isisoFixedCutTight");
  SG::AuxElement::Accessor<char> isisoFixedCutLoose("isisoFixedCutLoose");
  SG::AuxElement::Accessor<char> isisoFixedCutTightCaloOnly("isisoFixedCutTightCaloOnly");
  SG::AuxElement::Accessor<char> isisoFixedCutLooseCaloOnly("isisoFixedCutLooseCaloOnly");
  SG::AuxElement::Accessor<char> isTight("isTight");
  SG::AuxElement::Accessor<char> isLoose("isLoose");
  SG::AuxElement::Accessor<char> isMedium("isMedium");
  SG::AuxElement::Accessor<char> passIPcut("passIPCut");

  SG::AuxElement::Accessor<float> Jvt("Jvt");



  // photons

  //if (photons.size() < 2) return EL::StatusCode::SUCCESS;
  //TLorentzVector h = photons[0]->p4() + photons[1]->p4();
  //histoStore()->fillTH1F("m_yy", h.M()/HG::GeV);


  const xAOD::EventInfo* HGameventInfo = 0 ;

  if(event()->retrieve(HGameventInfo,"HGamEventInfo").isFailure() )
    HG::fatal("Cannot retrieve event Info .");



  const xAOD::EventInfo* eventInfo = 0 ;

  if(event()->retrieve(eventInfo,"EventInfo").isFailure() )
    HG::fatal("Cannot retrieve event Info .");


  RunNumber = runNumber( *eventInfo );
  LumiBlock = lumiBlock( *eventInfo );
  EventNumber = eventNumber( *eventInfo );

  TLorentzVector etmissVector;

  mcEventWeights_var = isMC() ?  mcEventWeights( *eventInfo )[0] : 1.; 
  xsecBrFilterEff_var = crossSectionBRflterEff.isAvailable( *HGameventInfo ) ?  crossSectionBRflterEff( *HGameventInfo )  : 1.; 
  mcID_var = isMC() ? eventInfo->mcChannelNumber() : -999;
  NPV_var = NPV(*HGameventInfo);
  mu_var = mu(*HGameventInfo);
  isMC_var = isMC();
  initWeight_var = initWeight(*HGameventInfo);
  myy_var = myy(*HGameventInfo);
  metSig_var = met_TST(*HGameventInfo)/met_sumet(*HGameventInfo);
  passVertex_var = fabs(hardestVertex(*HGameventInfo) - selectedVertex(*HGameventInfo)) < 0.3 ? 1 : 0;
  passHiggsSelection_var = passHiggsSelection(*HGameventInfo) == 1 ?  1 : 0;
  passQualityCuts_var = passQualityCuts(*HGameventInfo) == 1 ? 1 : 0 ;


  std::string inputfileName = wk()->inputFileName();

  if( currentfilename != inputfileName ){

    currentfilename = inputfileName;

    inputfileName.replace(inputfileName.find(".MxAOD") , -1, "") ;
    inputfileName.append(".NTuple.root");

    m_outputFile->cd();

    myEvents->Write();
    //    if( m_histCutFlow[currentdirectory] ) m_histCutFlow[it.first]->Write();
    m_outputFile->Close();

    //myEvents->Delete();

    m_outputFile = TFile::Open(inputfileName.c_str(),"RECREATE");
    myEvents = new TTree("DMHiggsAnalysis","DMHiggsAnalysis");

    //    m_outputFiles[currentfilename] = TFile::Open(inputfileName.c_str(),"RECREATE");

    //    inputfileName.replace(inputfileName.find(".NTuple.root") , -1, ".Tree");

    // myEvents = new TTree(inputfileName.c_str(),"DMHiggsAnalysis");

    declareVariables();
    //    m_outputTTree[currentfilename] = myEvents;

    // wk()->addOutput(m_outputFiles[inputfileName]);


    inputfileName = wk()->inputFileName();
  

  }


  std::string cutFlowName ;

  cutFlowName = "CutFlow_" + inputfileName;
  cutFlowName.replace(cutFlowName.find(".MxAOD") , -1, "") ;
  cutFlowName.append("_weighted");

  if( m_eventCounter == 1 ) m_histCutFlow[inputfileName] = (TH1F*) HG::getHistogramFromFile(cutFlowName,inputfileName);

  xAOD::PhotonContainer photons = photonHandler()->getCorrectedContainer() ;
  xAOD::ElectronContainer electrons = electronHandler()->getCorrectedContainer() ;
  xAOD::MuonContainer muons = muonHandler()->getCorrectedContainer() ;
  xAOD::JetContainer jets = jetHandler()->getCorrectedContainer() ;


  overlapHandler()->removeOverlap(photons,jets,electrons, muons);


  TLorentzVector photon_lead;
  TLorentzVector photon_sublead;
  TLorentzVector jet_lead;
  TLorentzVector jet_sublead;

  if( photons.size() > 0 ) photon_lead = (photons)[0]->p4();
  if( photons.size() > 1 ) photon_sublead = (photons)[1]->p4();


  if( jets.size() > 0 ) jet_lead = jets[0]->p4();
  if( jets.size() > 1 ) jet_sublead = jets[1]->p4();

  TLorentzVector allparticles;

  for(xAOD::Jet* jet : jets){
    TLorentzVector test=jet->p4();
    allparticles = allparticles+test;
  }
  for(xAOD::Photon* photon: photons){
    TLorentzVector test = photon->p4();
    allparticles = allparticles +test;
  }
  for(xAOD::Electron* electron: electrons){
    TLorentzVector test = electron->p4();
    allparticles = allparticles +test;
  }
  for(xAOD::Muon* muon: muons){
    TLorentzVector test = muon->p4();
    allparticles = allparticles +test;
  }



  // switch( photons.size() ) {


  // case 0 :

  //   break;
  // case 1 :


  //   phi_y1_met_var = (photon_lead).DeltaPhi(etmissVector);
  //   if( jets.size() > 0 )phi_y1_j_var = (photon_lead).DeltaPhi(jet_lead);

  //   break;
  // case 2 : 

  //   phi_y2_met_var = (photon_sublead).DeltaPhi(etmissVector);
  //   phi_yy_met_var = (photon_lead + photon_sublead).DeltaPhi(etmissVector);
  //   phi_y1_y2_var = (photon_lead).DeltaPhi(photon_sublead);


  //   if( jets.size() > 0 ){
  //     phi_yyj_met_var = (photon_lead + photon_sublead + jet_lead).DeltaPhi(etmissVector);
  //     phi_y2_j_var = (photon_sublead).DeltaPhi(jet_lead);
  //   }
  //   if( jets.size() > 1 ){
  //     phi_yyjj_met_var = (photon_lead + photon_sublead + jet_lead + jet_sublead).DeltaPhi(etmissVector);
  //     phi_yy_jj_var = (photon_lead + photon_sublead).DeltaPhi(jet_lead + jet_sublead);
  //   }



  // default : 

  //   phi_y2_met_var = (photon_sublead).DeltaPhi(etmissVector);
  //   phi_yy_met_var = (photon_lead + photon_sublead).DeltaPhi(etmissVector);
  //   phi_y1_y2_var = (photon_lead).DeltaPhi(photon_sublead);


  //   if( jets.size() > 0 ){
  //     phi_yyj_met_var = (photon_lead + photon_sublead + jet_lead).DeltaPhi(etmissVector);
  //     phi_y2_j_var = (photon_sublead).DeltaPhi(jet_lead);
  //   }
  //   if( jets.size() > 1 ){
  //     phi_yyjj_met_var = (photon_lead + photon_sublead + jet_lead + jet_sublead).DeltaPhi(etmissVector);
  //     phi_yy_jj_var = (photon_lead + photon_sublead).DeltaPhi(jet_lead + jet_sublead);
  //   }


  //   break;

  // }




  // phi_allparticles_met_var = allparticles.DeltaPhi(etmissVector);


  nPhotons=0;


  for(size_t gn=0; gn<photons.size(); gn++) {
    //    photonAuthor[nPhotons] = photons[gn]->author();
    photonPx[nPhotons] = photons[gn]->p4().Px();
    photonPy[nPhotons] = photons[gn]->p4().Py();
    photonPz[nPhotons] = photons[gn]->p4().Pz();
    photonE[nPhotons] = photons[gn]->p4().E();
    photons_Eps[nPhotons] = photons_ePS( *photons[gn] ); 
    photons_E1[nPhotons] = photons_e1( *photons[gn] ); 
    photons_E2[nPhotons] = photons_e2( *photons[gn] ); 
    photons_E3[nPhotons] = photons_e3( *photons[gn] ); 
    photons_conversionType[nPhotons] = photons_converted( *photons[gn] ); 
    photons_conversionRadius[nPhotons] = photons_convertedRadius( *photons[gn] ); 
    photons_topoCone20[nPhotons] = topoetCone20( *photons[gn] ); 
    photons_topoCone40[nPhotons] = topoetCone40( *photons[gn] ); 
    photons_Cone20[nPhotons] = ptCone20( *photons[gn] ); 
    photons_Cone40[nPhotons] = ptCone40( *photons[gn] ); 
    photons_isIsoFixedCutTight[nPhotons] = isisoFixedCutTight( *photons[gn] ) == 1 ? 1 : 0; 
    photons_isIsoFixedCutTightCaloOnly[nPhotons] = isisoFixedCutTightCaloOnly( *photons[gn] ) == 1 ? 1 : 0; 
    photons_isIsoFixedCutLooseCaloOnly[nPhotons] = isisoFixedCutLooseCaloOnly( *photons[gn] ) == 1 ? 1 : 0; 
    photons_isIsoFixedCutLoose[nPhotons] = isisoFixedCutLoose( *photons[gn] ) == 1 ? 1 : 0;
    photons_isTight[nPhotons] = isTight( *photons[gn] ) == 1 ? 1 : 0;   
    photons_isLoose[nPhotons] = photonHandler()->passPIDCut( photons[gn] , egammaPID::IsEMLoose  ) ? 1 : 0;  
    photons_isLoosePrime2[nPhotons] = photonHandler()->passLoosePrime( photons[gn] , 2 ) == 1 ? 1 : 0;    
    photons_isLoosePrime3[nPhotons] = photonHandler()->passLoosePrime( photons[gn] , 3 ) == 1 ? 1 : 0;    
    photons_isLoosePrime4[nPhotons] = photonHandler()->passLoosePrime( photons[gn] , 4 ) == 1 ? 1 : 0;    
    photons_isLoosePrime5[nPhotons] = photonHandler()->passLoosePrime( photons[gn] , 5 ) == 1 ? 1 : 0;   

    nPhotons++;
  }

  nElectrons=0;


  for(size_t gn=0; gn<electrons.size(); gn++) {
    //    electronAuthor[nElectrons] = electrons[gn]->author();
    electronPx[nElectrons] = electrons[gn]->p4().Px();
    electronPy[nElectrons] = electrons[gn]->p4().Py();
    electronPz[nElectrons] = electrons[gn]->p4().Pz();
    electronE[nElectrons] = electrons[gn]->e();
    electrons_Eps[nElectrons] = electrons[gn]->caloCluster() != nullptr ? electrons[gn]->caloCluster()->energyBE(0) : 0. ; 
    electrons_E1[nElectrons] = electrons[gn]->caloCluster() != nullptr ? electrons[gn]->caloCluster()->energyBE(1) : 0. ; 
    electrons_E2[nElectrons] = electrons[gn]->caloCluster() != nullptr ? electrons[gn]->caloCluster()->energyBE(2) : 0. ; 
    electrons_E3[nElectrons] = electrons[gn]->caloCluster() != nullptr ? electrons[gn]->caloCluster()->energyBE(3) : 0. ;
    

    electrons_topoCone20[nElectrons] = topoetCone20( *electrons[gn] ); 
    electrons_ptvarCone20[nElectrons] = ptvarCone20( *electrons[gn] );
    electrons_isTight[nElectrons] = isTight( *electrons[gn] ) == 1 ? 1 : 0; 
    electrons_isMedium[nElectrons] = electronHandler()->passPIDCut( electrons[gn] , "Medium" )  ?  1 : 0; 
    std::cout << " ================" << " Electron " << "======================== " << std::endl;
    electrons_isIsoLoose[nElectrons] = electronHandler()->passIsoCut( electrons[gn] , HG::Iso::Loose )  ? 1 : 0; 
    electrons_charge[nElectrons] = electrons[gn]->charge() ;   

    nElectrons++;
  }


  nMuons=0;


  for(size_t gn=0; gn<muons.size(); gn++) {


    muonPx[nMuons] = muons[gn]->p4().Px();
    muonPy[nMuons] = muons[gn]->p4().Py();
    muonPz[nMuons] = muons[gn]->p4().Pz();
    muonE[nMuons] = muons[gn]->e();
    
    muons_topoCone20[nMuons] = topoetCone20( *muons[gn] ); 
    muons_ptvarCone20[nMuons] = ptvarCone20( *muons[gn] );
    muons_charge[nMuons] = muons[gn]->charge() ;   
    muons_passIPcut[nMuons] = passIPcut( *muons[gn] ); 
    std::cout << " ======================================== " << std::endl;
    // muons_isLoose[nMuons] = m_muonLooseSelectionTool->accept( muons[gn] ) ? 1 : 0;  
    // muons_isMedium[nMuons] = m_muonMediumSelectionTool->accept( muons[gn] ) ? 1 : 0;  
    // muons_isTight[nMuons] = m_muonTightSelectionTool->accept( muons[gn] ) ? 1 : 0; 
    muons_isIsoGradientLoose[nMuons] = muonHandler()->passIsoCut( muons[gn], HG::Iso::GradientLoose ) ? 1 : 0;  
    muons_isIsoGradient[nMuons] = muonHandler()->passIsoCut( muons[gn], HG::Iso::Gradient ) ? 1 : 0;  
    muons_isIsoLoose[nMuons] = muonHandler()->passIsoCut( muons[gn], HG::Iso::Loose ) ? 1 : 0;  



    nMuons++;
  }


  nJets=0;


  for(size_t gn=0; gn<jets.size(); gn++) {

    jetPx[nJets] = jets[gn]->px();
    jetPy[nJets] = jets[gn]->py();
    jetPz[nJets] = jets[gn]->pz();
    jetJvt[nJets] = Jvt( *jets[gn] );
    jetPassSelection[nJets] = ( jetHandler()->passPtEtaCuts( jets[gn]) && jetHandler()->passJVFCut( jets[gn]) ) && jetHandler()->passJVTCut( jets[gn] ) ? 1 : 0;

    nJets++;

  }




  met = met_TST(*HGameventInfo);
  sumet = met_sumet(*HGameventInfo);
  phi_met = met_phi(*HGameventInfo);





  HG::TruthParticles* truthParticles = truthHandler()->getTruthParticles();
  xAOD::TruthParticleContainer truthPhotons = truthHandler()->getPhotons();
  xAOD::TruthParticleContainer truthElectrons = truthHandler()->getElectrons();
  xAOD::TruthParticleContainer truthMuons = truthHandler()->getMuons();
  xAOD::JetContainer truthJets = truthHandler()->getJets();
  xAOD::MissingETContainer truthMET = truthHandler()->getMissingET();


  ntruthPhotons = 0 ;

  for( xAOD::TruthParticle* truthpart : truthPhotons){

    photonTruthPx[ntruthPhotons] = truthpart->p4().Px();
    photonTruthPy[ntruthPhotons] = truthpart->p4().Py();
    photonTruthPz[ntruthPhotons] = truthpart->p4().Pz();
    photonTruthE[ntruthPhotons] = truthpart->p4().E();
    photonTruth_ptcone20[ntruthPhotons] = ptCone20( *truthpart ); 
    photonTruth_ptcone40[ntruthPhotons] = ptCone40( *truthpart ); 
    photonTruth_etcone20[ntruthPhotons] = etCone20( *truthpart ); 
    photonTruth_etcone40[ntruthPhotons] = etCone40( *truthpart ); 
    photonTruth_truthOrigin[ntruthPhotons] = truthOrigin( *truthpart ); 
    photonTruth_truthType[ntruthPhotons] = truthType( *truthpart ); 


    ++ntruthPhotons;
  }


  ntruthElectrons = 0 ;

  for( xAOD::TruthParticle* truthpart : truthElectrons){

    electronTruthPx[ntruthElectrons] = truthpart->p4().Px();
    electronTruthPy[ntruthElectrons] = truthpart->p4().Py();
    electronTruthPz[ntruthElectrons] = truthpart->p4().Pz();
    electronTruthE[ntruthElectrons] = truthpart->p4().E();


    ++ntruthElectrons;
  }




  ntruthMuons = 0 ;

  for( xAOD::TruthParticle* truthpart : truthMuons){

    muonTruthPx[ntruthMuons] = truthpart->p4().Px();
    muonTruthPy[ntruthMuons] = truthpart->p4().Py();
    muonTruthPz[ntruthMuons] = truthpart->p4().Pz();
    muonTruthE[ntruthMuons] = truthpart->p4().E();


    ++ntruthMuons;
  }


  ntruthJets = 0 ;

  for( xAOD::Jet* truthpart : truthJets){

    jetTruthPx[ntruthJets] = truthpart->p4().Px();
    jetTruthPy[ntruthJets] = truthpart->p4().Py();
    jetTruthPz[ntruthJets] = truthpart->p4().Pz();
    jetTruthE[ntruthJets] = truthpart->p4().E();


    ++ntruthJets;
  }



  // mpxTruthInt = ((*truthMET["Int"])+(*truthMET["IntMuons"])).mpx();
  // mpyTruthInt = ((*truthMET["Int"])+(*truthMET["IntMuons"])).mpy();
  // metTruthInt = ((*truthMET["Int"])+(*truthMET["IntMuons"])).met();
  // sumetTruthInt = ((*truthMET["Int"])+(*truthMET["IntMuons"])).sumet();

  mpxTruthInt = truthMET["Int"]->mpx();
  mpyTruthInt = truthMET["Int"]->mpy();
  metTruthInt = truthMET["Int"]->met();
  sumetTruthInt = truthMET["Int"]->sumet();
  mpxTruthNonInt = truthMET["NonInt"]->mpx();
  mpyTruthNonInt = truthMET["NonInt"]->mpy();
  metTruthNonInt = truthMET["NonInt"]->met();
  sumetTruthNonInt = truthMET["NonInt"]->sumet();


  //  for( xAOD::TruthParticle* )




  myEvents->Fill();
  return EL::StatusCode::SUCCESS;
}





EL::StatusCode DMHiggsAnalysis::finalize() {

  
  m_outputFile->cd();
  myEvents->Write();
  //  if( m_histCutFlow ) m_histCutFlow[it.first]->Write();
  m_outputFile->Close();

  
  // for( auto it : m_outputFiles ){
  //   it.second->cd();
  //   m_outputTTree[it.first]->Write();
  //   if( m_histCutFlow[it.first] ) m_histCutFlow[it.first]->Write();
  //   it.second->Close();

  // }


  if( m_muonTightSelectionTool )
    delete m_muonTightSelectionTool;
  if( m_muonMediumSelectionTool )
    delete m_muonMediumSelectionTool;
  if( m_muonLooseSelectionTool )
    delete m_muonLooseSelectionTool;

  HgammaAnalysis::finalize();

  return EL::StatusCode::SUCCESS;

}
