
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
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "AS", "ADD", "SUB", "MUL", "DIV", "MOD", "DOT", 
      "EQUALITY", "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "INT", "FLOAT", 
      "CHAR", "STRING", "NAME", "LAYOUT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'return'", "'if'", "'elif'", "'else'", "'\\n'", "'\\r'", "';'", 
      "'def'", "'->'", "'public'", "'private'", "'protected'", "'fileprivae'", 
      "'in'", "'out'", "'inout'", "'('", "')'", "','", "'='", "'class'", 
      "':'", "'let'", "'var'", "'{'", "'}'", "'.'", "'as'", "", "", "", 
      "", "", "", "'=='", "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "AS", "ADD", "SUB", "MUL", 
      "DIV", "MOD", "DOT", "EQUALITY", "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", 
      "INT", "FLOAT", "CHAR", "STRING", "NAME", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,44,299,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,
  	2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,
  	1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,22,1,23,
  	1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,27,1,28,1,28,
  	1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,34,1,35,
  	1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,37,1,38,4,38,230,8,38,11,38,12,38,
  	231,1,38,1,38,5,38,236,8,38,10,38,12,38,239,9,38,3,38,241,8,38,1,39,5,
  	39,244,8,39,10,39,12,39,247,9,39,1,39,1,39,4,39,251,8,39,11,39,12,39,
  	252,1,39,1,39,5,39,257,8,39,10,39,12,39,260,9,39,3,39,262,8,39,1,40,1,
  	40,1,40,1,40,1,40,3,40,269,8,40,3,40,271,8,40,1,40,1,40,1,41,1,41,1,41,
  	1,41,1,41,3,41,280,8,41,5,41,282,8,41,10,41,12,41,285,9,41,1,41,1,41,
  	1,42,1,42,5,42,291,8,42,10,42,12,42,294,9,42,1,43,1,43,1,43,1,43,0,0,
  	44,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,
  	14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,
  	51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,
  	37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,1,0,11,1,0,43,43,1,0,45,
  	45,1,0,42,42,1,0,47,47,1,0,37,37,1,0,46,46,1,0,48,57,3,0,65,90,95,95,
  	97,122,4,0,48,57,65,90,95,95,97,122,4,0,10,10,13,13,34,34,92,92,2,0,9,
  	9,32,32,311,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,
  	0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,
  	0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,
  	53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,
  	0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,
  	0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,
  	85,1,0,0,0,0,87,1,0,0,0,1,89,1,0,0,0,3,96,1,0,0,0,5,99,1,0,0,0,7,104,
  	1,0,0,0,9,109,1,0,0,0,11,111,1,0,0,0,13,113,1,0,0,0,15,115,1,0,0,0,17,
  	119,1,0,0,0,19,122,1,0,0,0,21,129,1,0,0,0,23,137,1,0,0,0,25,147,1,0,0,
  	0,27,158,1,0,0,0,29,161,1,0,0,0,31,165,1,0,0,0,33,171,1,0,0,0,35,173,
  	1,0,0,0,37,175,1,0,0,0,39,177,1,0,0,0,41,179,1,0,0,0,43,185,1,0,0,0,45,
  	187,1,0,0,0,47,191,1,0,0,0,49,195,1,0,0,0,51,197,1,0,0,0,53,199,1,0,0,
  	0,55,201,1,0,0,0,57,204,1,0,0,0,59,206,1,0,0,0,61,208,1,0,0,0,63,210,
  	1,0,0,0,65,212,1,0,0,0,67,214,1,0,0,0,69,216,1,0,0,0,71,219,1,0,0,0,73,
  	222,1,0,0,0,75,225,1,0,0,0,77,229,1,0,0,0,79,245,1,0,0,0,81,263,1,0,0,
  	0,83,274,1,0,0,0,85,288,1,0,0,0,87,295,1,0,0,0,89,90,5,114,0,0,90,91,
  	5,101,0,0,91,92,5,116,0,0,92,93,5,117,0,0,93,94,5,114,0,0,94,95,5,110,
  	0,0,95,2,1,0,0,0,96,97,5,105,0,0,97,98,5,102,0,0,98,4,1,0,0,0,99,100,
  	5,101,0,0,100,101,5,108,0,0,101,102,5,105,0,0,102,103,5,102,0,0,103,6,
  	1,0,0,0,104,105,5,101,0,0,105,106,5,108,0,0,106,107,5,115,0,0,107,108,
  	5,101,0,0,108,8,1,0,0,0,109,110,5,10,0,0,110,10,1,0,0,0,111,112,5,13,
  	0,0,112,12,1,0,0,0,113,114,5,59,0,0,114,14,1,0,0,0,115,116,5,100,0,0,
  	116,117,5,101,0,0,117,118,5,102,0,0,118,16,1,0,0,0,119,120,5,45,0,0,120,
  	121,5,62,0,0,121,18,1,0,0,0,122,123,5,112,0,0,123,124,5,117,0,0,124,125,
  	5,98,0,0,125,126,5,108,0,0,126,127,5,105,0,0,127,128,5,99,0,0,128,20,
  	1,0,0,0,129,130,5,112,0,0,130,131,5,114,0,0,131,132,5,105,0,0,132,133,
  	5,118,0,0,133,134,5,97,0,0,134,135,5,116,0,0,135,136,5,101,0,0,136,22,
  	1,0,0,0,137,138,5,112,0,0,138,139,5,114,0,0,139,140,5,111,0,0,140,141,
  	5,116,0,0,141,142,5,101,0,0,142,143,5,99,0,0,143,144,5,116,0,0,144,145,
  	5,101,0,0,145,146,5,100,0,0,146,24,1,0,0,0,147,148,5,102,0,0,148,149,
  	5,105,0,0,149,150,5,108,0,0,150,151,5,101,0,0,151,152,5,112,0,0,152,153,
  	5,114,0,0,153,154,5,105,0,0,154,155,5,118,0,0,155,156,5,97,0,0,156,157,
  	5,101,0,0,157,26,1,0,0,0,158,159,5,105,0,0,159,160,5,110,0,0,160,28,1,
  	0,0,0,161,162,5,111,0,0,162,163,5,117,0,0,163,164,5,116,0,0,164,30,1,
  	0,0,0,165,166,5,105,0,0,166,167,5,110,0,0,167,168,5,111,0,0,168,169,5,
  	117,0,0,169,170,5,116,0,0,170,32,1,0,0,0,171,172,5,40,0,0,172,34,1,0,
  	0,0,173,174,5,41,0,0,174,36,1,0,0,0,175,176,5,44,0,0,176,38,1,0,0,0,177,
  	178,5,61,0,0,178,40,1,0,0,0,179,180,5,99,0,0,180,181,5,108,0,0,181,182,
  	5,97,0,0,182,183,5,115,0,0,183,184,5,115,0,0,184,42,1,0,0,0,185,186,5,
  	58,0,0,186,44,1,0,0,0,187,188,5,108,0,0,188,189,5,101,0,0,189,190,5,116,
  	0,0,190,46,1,0,0,0,191,192,5,118,0,0,192,193,5,97,0,0,193,194,5,114,0,
  	0,194,48,1,0,0,0,195,196,5,123,0,0,196,50,1,0,0,0,197,198,5,125,0,0,198,
  	52,1,0,0,0,199,200,5,46,0,0,200,54,1,0,0,0,201,202,5,97,0,0,202,203,5,
  	115,0,0,203,56,1,0,0,0,204,205,7,0,0,0,205,58,1,0,0,0,206,207,7,1,0,0,
  	207,60,1,0,0,0,208,209,7,2,0,0,209,62,1,0,0,0,210,211,7,3,0,0,211,64,
  	1,0,0,0,212,213,7,4,0,0,213,66,1,0,0,0,214,215,7,5,0,0,215,68,1,0,0,0,
  	216,217,5,61,0,0,217,218,5,61,0,0,218,70,1,0,0,0,219,220,5,33,0,0,220,
  	221,5,61,0,0,221,72,1,0,0,0,222,223,5,38,0,0,223,224,5,38,0,0,224,74,
  	1,0,0,0,225,226,5,124,0,0,226,227,5,124,0,0,227,76,1,0,0,0,228,230,7,
  	6,0,0,229,228,1,0,0,0,230,231,1,0,0,0,231,229,1,0,0,0,231,232,1,0,0,0,
  	232,240,1,0,0,0,233,237,7,7,0,0,234,236,7,8,0,0,235,234,1,0,0,0,236,239,
  	1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,
  	0,240,233,1,0,0,0,240,241,1,0,0,0,241,78,1,0,0,0,242,244,7,6,0,0,243,
  	242,1,0,0,0,244,247,1,0,0,0,245,243,1,0,0,0,245,246,1,0,0,0,246,248,1,
  	0,0,0,247,245,1,0,0,0,248,250,7,5,0,0,249,251,7,6,0,0,250,249,1,0,0,0,
  	251,252,1,0,0,0,252,250,1,0,0,0,252,253,1,0,0,0,253,261,1,0,0,0,254,258,
  	7,7,0,0,255,257,7,8,0,0,256,255,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,
  	0,258,259,1,0,0,0,259,262,1,0,0,0,260,258,1,0,0,0,261,254,1,0,0,0,261,
  	262,1,0,0,0,262,80,1,0,0,0,263,270,5,39,0,0,264,271,8,9,0,0,265,268,5,
  	92,0,0,266,269,9,0,0,0,267,269,5,0,0,1,268,266,1,0,0,0,268,267,1,0,0,
  	0,269,271,1,0,0,0,270,264,1,0,0,0,270,265,1,0,0,0,271,272,1,0,0,0,272,
  	273,5,39,0,0,273,82,1,0,0,0,274,283,5,34,0,0,275,282,8,9,0,0,276,279,
  	5,92,0,0,277,280,9,0,0,0,278,280,5,0,0,1,279,277,1,0,0,0,279,278,1,0,
  	0,0,280,282,1,0,0,0,281,275,1,0,0,0,281,276,1,0,0,0,282,285,1,0,0,0,283,
  	281,1,0,0,0,283,284,1,0,0,0,284,286,1,0,0,0,285,283,1,0,0,0,286,287,5,
  	34,0,0,287,84,1,0,0,0,288,292,7,7,0,0,289,291,7,8,0,0,290,289,1,0,0,0,
  	291,294,1,0,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,86,1,0,0,0,294,292,
  	1,0,0,0,295,296,7,10,0,0,296,297,1,0,0,0,297,298,6,43,0,0,298,88,1,0,
  	0,0,14,0,231,237,240,245,252,258,261,268,270,279,281,283,292,1,6,0,0
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
