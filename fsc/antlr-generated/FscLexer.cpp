
// Generated from Fsc.g4 by ANTLR 4.11.1


#include "FscLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct FscLexerStaticData final {
  FscLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FscLexerStaticData(const FscLexerStaticData&) = delete;
  FscLexerStaticData(FscLexerStaticData&&) = delete;
  FscLexerStaticData& operator=(const FscLexerStaticData&) = delete;
  FscLexerStaticData& operator=(FscLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag fsclexerLexerOnceFlag;
FscLexerStaticData *fsclexerLexerStaticData = nullptr;

void fsclexerLexerInitialize() {
  assert(fsclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<FscLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "AS", "ADD", 
      "SUB", "MUL", "DIV", "MOD", "EQUALITY", "INEQUALITY", "LOGICAL_AND", 
      "LOGICAL_OR", "INT", "FLOAT", "NAME", "LAYOUT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'return'", "'\\n'", "'\\r'", "';'", "'func'", "'->'", "'public'", 
      "'private'", "'protected'", "'fileprivae'", "'in'", "'out'", "'inout'", 
      "'('", "')'", "','", "'='", "'class'", "':'", "'let'", "'var'", "'{'", 
      "'}'", "'as'", "", "", "", "", "", "'=='", "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "AS", "ADD", "SUB", "MUL", "DIV", "MOD", 
      "EQUALITY", "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "INT", "FLOAT", 
      "NAME", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,37,244,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,
  	1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,26,
  	1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,
  	1,32,1,32,1,32,1,33,4,33,200,8,33,11,33,12,33,201,1,33,1,33,5,33,206,
  	8,33,10,33,12,33,209,9,33,3,33,211,8,33,1,34,5,34,214,8,34,10,34,12,34,
  	217,9,34,1,34,1,34,4,34,221,8,34,11,34,12,34,222,1,34,1,34,5,34,227,8,
  	34,10,34,12,34,230,9,34,3,34,232,8,34,1,35,1,35,5,35,236,8,35,10,35,12,
  	35,239,9,35,1,36,1,36,1,36,1,36,0,0,37,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,
  	39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,
  	31,63,32,65,33,67,34,69,35,71,36,73,37,1,0,10,1,0,43,43,1,0,45,45,1,0,
  	42,42,1,0,47,47,1,0,37,37,1,0,48,57,3,0,65,90,95,95,97,122,4,0,48,57,
  	65,90,95,95,97,122,1,0,46,46,2,0,9,9,32,32,251,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,1,75,1,0,0,0,3,82,1,0,0,0,5,84,
  	1,0,0,0,7,86,1,0,0,0,9,88,1,0,0,0,11,93,1,0,0,0,13,96,1,0,0,0,15,103,
  	1,0,0,0,17,111,1,0,0,0,19,121,1,0,0,0,21,132,1,0,0,0,23,135,1,0,0,0,25,
  	139,1,0,0,0,27,145,1,0,0,0,29,147,1,0,0,0,31,149,1,0,0,0,33,151,1,0,0,
  	0,35,153,1,0,0,0,37,159,1,0,0,0,39,161,1,0,0,0,41,165,1,0,0,0,43,169,
  	1,0,0,0,45,171,1,0,0,0,47,173,1,0,0,0,49,176,1,0,0,0,51,178,1,0,0,0,53,
  	180,1,0,0,0,55,182,1,0,0,0,57,184,1,0,0,0,59,186,1,0,0,0,61,189,1,0,0,
  	0,63,192,1,0,0,0,65,195,1,0,0,0,67,199,1,0,0,0,69,215,1,0,0,0,71,233,
  	1,0,0,0,73,240,1,0,0,0,75,76,5,114,0,0,76,77,5,101,0,0,77,78,5,116,0,
  	0,78,79,5,117,0,0,79,80,5,114,0,0,80,81,5,110,0,0,81,2,1,0,0,0,82,83,
  	5,10,0,0,83,4,1,0,0,0,84,85,5,13,0,0,85,6,1,0,0,0,86,87,5,59,0,0,87,8,
  	1,0,0,0,88,89,5,102,0,0,89,90,5,117,0,0,90,91,5,110,0,0,91,92,5,99,0,
  	0,92,10,1,0,0,0,93,94,5,45,0,0,94,95,5,62,0,0,95,12,1,0,0,0,96,97,5,112,
  	0,0,97,98,5,117,0,0,98,99,5,98,0,0,99,100,5,108,0,0,100,101,5,105,0,0,
  	101,102,5,99,0,0,102,14,1,0,0,0,103,104,5,112,0,0,104,105,5,114,0,0,105,
  	106,5,105,0,0,106,107,5,118,0,0,107,108,5,97,0,0,108,109,5,116,0,0,109,
  	110,5,101,0,0,110,16,1,0,0,0,111,112,5,112,0,0,112,113,5,114,0,0,113,
  	114,5,111,0,0,114,115,5,116,0,0,115,116,5,101,0,0,116,117,5,99,0,0,117,
  	118,5,116,0,0,118,119,5,101,0,0,119,120,5,100,0,0,120,18,1,0,0,0,121,
  	122,5,102,0,0,122,123,5,105,0,0,123,124,5,108,0,0,124,125,5,101,0,0,125,
  	126,5,112,0,0,126,127,5,114,0,0,127,128,5,105,0,0,128,129,5,118,0,0,129,
  	130,5,97,0,0,130,131,5,101,0,0,131,20,1,0,0,0,132,133,5,105,0,0,133,134,
  	5,110,0,0,134,22,1,0,0,0,135,136,5,111,0,0,136,137,5,117,0,0,137,138,
  	5,116,0,0,138,24,1,0,0,0,139,140,5,105,0,0,140,141,5,110,0,0,141,142,
  	5,111,0,0,142,143,5,117,0,0,143,144,5,116,0,0,144,26,1,0,0,0,145,146,
  	5,40,0,0,146,28,1,0,0,0,147,148,5,41,0,0,148,30,1,0,0,0,149,150,5,44,
  	0,0,150,32,1,0,0,0,151,152,5,61,0,0,152,34,1,0,0,0,153,154,5,99,0,0,154,
  	155,5,108,0,0,155,156,5,97,0,0,156,157,5,115,0,0,157,158,5,115,0,0,158,
  	36,1,0,0,0,159,160,5,58,0,0,160,38,1,0,0,0,161,162,5,108,0,0,162,163,
  	5,101,0,0,163,164,5,116,0,0,164,40,1,0,0,0,165,166,5,118,0,0,166,167,
  	5,97,0,0,167,168,5,114,0,0,168,42,1,0,0,0,169,170,5,123,0,0,170,44,1,
  	0,0,0,171,172,5,125,0,0,172,46,1,0,0,0,173,174,5,97,0,0,174,175,5,115,
  	0,0,175,48,1,0,0,0,176,177,7,0,0,0,177,50,1,0,0,0,178,179,7,1,0,0,179,
  	52,1,0,0,0,180,181,7,2,0,0,181,54,1,0,0,0,182,183,7,3,0,0,183,56,1,0,
  	0,0,184,185,7,4,0,0,185,58,1,0,0,0,186,187,5,61,0,0,187,188,5,61,0,0,
  	188,60,1,0,0,0,189,190,5,33,0,0,190,191,5,61,0,0,191,62,1,0,0,0,192,193,
  	5,38,0,0,193,194,5,38,0,0,194,64,1,0,0,0,195,196,5,124,0,0,196,197,5,
  	124,0,0,197,66,1,0,0,0,198,200,7,5,0,0,199,198,1,0,0,0,200,201,1,0,0,
  	0,201,199,1,0,0,0,201,202,1,0,0,0,202,210,1,0,0,0,203,207,7,6,0,0,204,
  	206,7,7,0,0,205,204,1,0,0,0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,
  	0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,210,203,1,0,0,0,210,211,1,0,0,0,
  	211,68,1,0,0,0,212,214,7,5,0,0,213,212,1,0,0,0,214,217,1,0,0,0,215,213,
  	1,0,0,0,215,216,1,0,0,0,216,218,1,0,0,0,217,215,1,0,0,0,218,220,7,8,0,
  	0,219,221,7,5,0,0,220,219,1,0,0,0,221,222,1,0,0,0,222,220,1,0,0,0,222,
  	223,1,0,0,0,223,231,1,0,0,0,224,228,7,6,0,0,225,227,7,7,0,0,226,225,1,
  	0,0,0,227,230,1,0,0,0,228,226,1,0,0,0,228,229,1,0,0,0,229,232,1,0,0,0,
  	230,228,1,0,0,0,231,224,1,0,0,0,231,232,1,0,0,0,232,70,1,0,0,0,233,237,
  	7,6,0,0,234,236,7,7,0,0,235,234,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,
  	0,237,238,1,0,0,0,238,72,1,0,0,0,239,237,1,0,0,0,240,241,7,9,0,0,241,
  	242,1,0,0,0,242,243,6,36,0,0,243,74,1,0,0,0,9,0,201,207,210,215,222,228,
  	231,237,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fsclexerLexerStaticData = staticData.release();
}

}

FscLexer::FscLexer(CharStream *input) : Lexer(input) {
  FscLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *fsclexerLexerStaticData->atn, fsclexerLexerStaticData->decisionToDFA, fsclexerLexerStaticData->sharedContextCache);
}

FscLexer::~FscLexer() {
  delete _interpreter;
}

std::string FscLexer::getGrammarFileName() const {
  return "Fsc.g4";
}

const std::vector<std::string>& FscLexer::getRuleNames() const {
  return fsclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& FscLexer::getChannelNames() const {
  return fsclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& FscLexer::getModeNames() const {
  return fsclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& FscLexer::getVocabulary() const {
  return fsclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FscLexer::getSerializedATN() const {
  return fsclexerLexerStaticData->serializedATN;
}

const atn::ATN& FscLexer::getATN() const {
  return *fsclexerLexerStaticData->atn;
}




void FscLexer::initialize() {
  ::antlr4::internal::call_once(fsclexerLexerOnceFlag, fsclexerLexerInitialize);
}
