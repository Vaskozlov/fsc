
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
      "T__17", "T__18", "AS", "ADD", "SUB", "MUL", "DIV", "MOD", "EQUALITY", 
      "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "INT", "FLOAT", "NAME", 
      "LAYOUT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'return'", "'\\n'", "'\\r'", "';'", "'func'", "'->'", "'in'", 
      "'out'", "'inout'", "'('", "')'", "','", "'='", "'class'", "':'", 
      "'let'", "'var'", "'{'", "'}'", "'as'", "", "", "", "", "", "'=='", 
      "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "AS", "ADD", "SUB", "MUL", "DIV", "MOD", "EQUALITY", "INEQUALITY", 
      "LOGICAL_AND", "LOGICAL_OR", "INT", "FLOAT", "NAME", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,33,200,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,
  	6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,
  	1,27,1,27,1,28,1,28,1,28,1,29,4,29,156,8,29,11,29,12,29,157,1,29,1,29,
  	5,29,162,8,29,10,29,12,29,165,9,29,3,29,167,8,29,1,30,5,30,170,8,30,10,
  	30,12,30,173,9,30,1,30,1,30,4,30,177,8,30,11,30,12,30,178,1,30,1,30,5,
  	30,183,8,30,10,30,12,30,186,9,30,3,30,188,8,30,1,31,1,31,5,31,192,8,31,
  	10,31,12,31,195,9,31,1,32,1,32,1,32,1,32,0,0,33,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,
  	30,61,31,63,32,65,33,1,0,10,1,0,43,43,1,0,45,45,1,0,42,42,1,0,47,47,1,
  	0,37,37,1,0,48,57,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	1,0,46,46,2,0,9,9,32,32,207,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,
  	0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,
  	0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,
  	1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,
  	0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,
  	0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,
  	1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,1,67,1,0,0,0,3,74,1,0,0,0,5,76,1,0,
  	0,0,7,78,1,0,0,0,9,80,1,0,0,0,11,85,1,0,0,0,13,88,1,0,0,0,15,91,1,0,0,
  	0,17,95,1,0,0,0,19,101,1,0,0,0,21,103,1,0,0,0,23,105,1,0,0,0,25,107,1,
  	0,0,0,27,109,1,0,0,0,29,115,1,0,0,0,31,117,1,0,0,0,33,121,1,0,0,0,35,
  	125,1,0,0,0,37,127,1,0,0,0,39,129,1,0,0,0,41,132,1,0,0,0,43,134,1,0,0,
  	0,45,136,1,0,0,0,47,138,1,0,0,0,49,140,1,0,0,0,51,142,1,0,0,0,53,145,
  	1,0,0,0,55,148,1,0,0,0,57,151,1,0,0,0,59,155,1,0,0,0,61,171,1,0,0,0,63,
  	189,1,0,0,0,65,196,1,0,0,0,67,68,5,114,0,0,68,69,5,101,0,0,69,70,5,116,
  	0,0,70,71,5,117,0,0,71,72,5,114,0,0,72,73,5,110,0,0,73,2,1,0,0,0,74,75,
  	5,10,0,0,75,4,1,0,0,0,76,77,5,13,0,0,77,6,1,0,0,0,78,79,5,59,0,0,79,8,
  	1,0,0,0,80,81,5,102,0,0,81,82,5,117,0,0,82,83,5,110,0,0,83,84,5,99,0,
  	0,84,10,1,0,0,0,85,86,5,45,0,0,86,87,5,62,0,0,87,12,1,0,0,0,88,89,5,105,
  	0,0,89,90,5,110,0,0,90,14,1,0,0,0,91,92,5,111,0,0,92,93,5,117,0,0,93,
  	94,5,116,0,0,94,16,1,0,0,0,95,96,5,105,0,0,96,97,5,110,0,0,97,98,5,111,
  	0,0,98,99,5,117,0,0,99,100,5,116,0,0,100,18,1,0,0,0,101,102,5,40,0,0,
  	102,20,1,0,0,0,103,104,5,41,0,0,104,22,1,0,0,0,105,106,5,44,0,0,106,24,
  	1,0,0,0,107,108,5,61,0,0,108,26,1,0,0,0,109,110,5,99,0,0,110,111,5,108,
  	0,0,111,112,5,97,0,0,112,113,5,115,0,0,113,114,5,115,0,0,114,28,1,0,0,
  	0,115,116,5,58,0,0,116,30,1,0,0,0,117,118,5,108,0,0,118,119,5,101,0,0,
  	119,120,5,116,0,0,120,32,1,0,0,0,121,122,5,118,0,0,122,123,5,97,0,0,123,
  	124,5,114,0,0,124,34,1,0,0,0,125,126,5,123,0,0,126,36,1,0,0,0,127,128,
  	5,125,0,0,128,38,1,0,0,0,129,130,5,97,0,0,130,131,5,115,0,0,131,40,1,
  	0,0,0,132,133,7,0,0,0,133,42,1,0,0,0,134,135,7,1,0,0,135,44,1,0,0,0,136,
  	137,7,2,0,0,137,46,1,0,0,0,138,139,7,3,0,0,139,48,1,0,0,0,140,141,7,4,
  	0,0,141,50,1,0,0,0,142,143,5,61,0,0,143,144,5,61,0,0,144,52,1,0,0,0,145,
  	146,5,33,0,0,146,147,5,61,0,0,147,54,1,0,0,0,148,149,5,38,0,0,149,150,
  	5,38,0,0,150,56,1,0,0,0,151,152,5,124,0,0,152,153,5,124,0,0,153,58,1,
  	0,0,0,154,156,7,5,0,0,155,154,1,0,0,0,156,157,1,0,0,0,157,155,1,0,0,0,
  	157,158,1,0,0,0,158,166,1,0,0,0,159,163,7,6,0,0,160,162,7,7,0,0,161,160,
  	1,0,0,0,162,165,1,0,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,167,1,0,0,
  	0,165,163,1,0,0,0,166,159,1,0,0,0,166,167,1,0,0,0,167,60,1,0,0,0,168,
  	170,7,5,0,0,169,168,1,0,0,0,170,173,1,0,0,0,171,169,1,0,0,0,171,172,1,
  	0,0,0,172,174,1,0,0,0,173,171,1,0,0,0,174,176,7,8,0,0,175,177,7,5,0,0,
  	176,175,1,0,0,0,177,178,1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,179,187,
  	1,0,0,0,180,184,7,6,0,0,181,183,7,7,0,0,182,181,1,0,0,0,183,186,1,0,0,
  	0,184,182,1,0,0,0,184,185,1,0,0,0,185,188,1,0,0,0,186,184,1,0,0,0,187,
  	180,1,0,0,0,187,188,1,0,0,0,188,62,1,0,0,0,189,193,7,6,0,0,190,192,7,
  	7,0,0,191,190,1,0,0,0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,
  	194,64,1,0,0,0,195,193,1,0,0,0,196,197,7,9,0,0,197,198,1,0,0,0,198,199,
  	6,32,0,0,199,66,1,0,0,0,9,0,157,163,166,171,178,184,187,193,1,6,0,0
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
