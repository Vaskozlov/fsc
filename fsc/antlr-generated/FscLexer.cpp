
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
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "ADD", "SUB", 
      "MUL", "DIV", "MOD", "IF", "FOR", "WHILE", "FUNC", "RETURN", "INT", 
      "FLOAT", "NAME", "LAYOUT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'\\n'", "'\\r'", "';'", "'->'", "':'", "'in'", "'out'", "'inout'", 
      "'('", "')'", "'='", "','", "'var'", "'{'", "'}'", "", "", "", "", 
      "", "'if'", "'for'", "'while'", "'func'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ADD", 
      "SUB", "MUL", "DIV", "MOD", "IF", "FOR", "WHILE", "FUNC", "RETURN", 
      "INT", "FLOAT", "NAME", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,29,180,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,
  	12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,
  	18,1,18,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,
  	24,1,25,4,25,136,8,25,11,25,12,25,137,1,25,1,25,5,25,142,8,25,10,25,12,
  	25,145,9,25,3,25,147,8,25,1,26,5,26,150,8,26,10,26,12,26,153,9,26,1,26,
  	1,26,4,26,157,8,26,11,26,12,26,158,1,26,1,26,5,26,163,8,26,10,26,12,26,
  	166,9,26,3,26,168,8,26,1,27,1,27,5,27,172,8,27,10,27,12,27,175,9,27,1,
  	28,1,28,1,28,1,28,0,0,29,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,
  	22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,1,0,10,1,0,43,43,1,0,45,
  	45,1,0,42,42,1,0,47,47,1,0,37,37,1,0,48,57,3,0,65,90,95,95,97,122,4,0,
  	48,57,65,90,95,95,97,122,1,0,46,46,2,0,9,9,32,32,187,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,
  	0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,
  	1,0,0,0,1,59,1,0,0,0,3,61,1,0,0,0,5,63,1,0,0,0,7,65,1,0,0,0,9,68,1,0,
  	0,0,11,70,1,0,0,0,13,73,1,0,0,0,15,77,1,0,0,0,17,83,1,0,0,0,19,85,1,0,
  	0,0,21,87,1,0,0,0,23,89,1,0,0,0,25,91,1,0,0,0,27,95,1,0,0,0,29,97,1,0,
  	0,0,31,99,1,0,0,0,33,101,1,0,0,0,35,103,1,0,0,0,37,105,1,0,0,0,39,107,
  	1,0,0,0,41,109,1,0,0,0,43,112,1,0,0,0,45,116,1,0,0,0,47,122,1,0,0,0,49,
  	127,1,0,0,0,51,135,1,0,0,0,53,151,1,0,0,0,55,169,1,0,0,0,57,176,1,0,0,
  	0,59,60,5,10,0,0,60,2,1,0,0,0,61,62,5,13,0,0,62,4,1,0,0,0,63,64,5,59,
  	0,0,64,6,1,0,0,0,65,66,5,45,0,0,66,67,5,62,0,0,67,8,1,0,0,0,68,69,5,58,
  	0,0,69,10,1,0,0,0,70,71,5,105,0,0,71,72,5,110,0,0,72,12,1,0,0,0,73,74,
  	5,111,0,0,74,75,5,117,0,0,75,76,5,116,0,0,76,14,1,0,0,0,77,78,5,105,0,
  	0,78,79,5,110,0,0,79,80,5,111,0,0,80,81,5,117,0,0,81,82,5,116,0,0,82,
  	16,1,0,0,0,83,84,5,40,0,0,84,18,1,0,0,0,85,86,5,41,0,0,86,20,1,0,0,0,
  	87,88,5,61,0,0,88,22,1,0,0,0,89,90,5,44,0,0,90,24,1,0,0,0,91,92,5,118,
  	0,0,92,93,5,97,0,0,93,94,5,114,0,0,94,26,1,0,0,0,95,96,5,123,0,0,96,28,
  	1,0,0,0,97,98,5,125,0,0,98,30,1,0,0,0,99,100,7,0,0,0,100,32,1,0,0,0,101,
  	102,7,1,0,0,102,34,1,0,0,0,103,104,7,2,0,0,104,36,1,0,0,0,105,106,7,3,
  	0,0,106,38,1,0,0,0,107,108,7,4,0,0,108,40,1,0,0,0,109,110,5,105,0,0,110,
  	111,5,102,0,0,111,42,1,0,0,0,112,113,5,102,0,0,113,114,5,111,0,0,114,
  	115,5,114,0,0,115,44,1,0,0,0,116,117,5,119,0,0,117,118,5,104,0,0,118,
  	119,5,105,0,0,119,120,5,108,0,0,120,121,5,101,0,0,121,46,1,0,0,0,122,
  	123,5,102,0,0,123,124,5,117,0,0,124,125,5,110,0,0,125,126,5,99,0,0,126,
  	48,1,0,0,0,127,128,5,114,0,0,128,129,5,101,0,0,129,130,5,116,0,0,130,
  	131,5,117,0,0,131,132,5,114,0,0,132,133,5,110,0,0,133,50,1,0,0,0,134,
  	136,7,5,0,0,135,134,1,0,0,0,136,137,1,0,0,0,137,135,1,0,0,0,137,138,1,
  	0,0,0,138,146,1,0,0,0,139,143,7,6,0,0,140,142,7,7,0,0,141,140,1,0,0,0,
  	142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,147,1,0,0,0,145,143,
  	1,0,0,0,146,139,1,0,0,0,146,147,1,0,0,0,147,52,1,0,0,0,148,150,7,5,0,
  	0,149,148,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,
  	154,1,0,0,0,153,151,1,0,0,0,154,156,7,8,0,0,155,157,7,5,0,0,156,155,1,
  	0,0,0,157,158,1,0,0,0,158,156,1,0,0,0,158,159,1,0,0,0,159,167,1,0,0,0,
  	160,164,7,6,0,0,161,163,7,7,0,0,162,161,1,0,0,0,163,166,1,0,0,0,164,162,
  	1,0,0,0,164,165,1,0,0,0,165,168,1,0,0,0,166,164,1,0,0,0,167,160,1,0,0,
  	0,167,168,1,0,0,0,168,54,1,0,0,0,169,173,7,6,0,0,170,172,7,7,0,0,171,
  	170,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,56,1,
  	0,0,0,175,173,1,0,0,0,176,177,7,9,0,0,177,178,1,0,0,0,178,179,6,28,0,
  	0,179,58,1,0,0,0,9,0,137,143,146,151,158,164,167,173,1,6,0,0
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
