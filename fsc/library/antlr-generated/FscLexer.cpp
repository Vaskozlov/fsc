
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
      "ASSIGN", "LESS", "GREATER", "LESS_EQ", "GREATER_EQ", "EQUALITY", 
      "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "TRUE", "FALSE", "INT", 
      "FLOAT", "CHAR", "STRING", "IDENTIFIER", "LAYOUT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "','", "'return'", "'{'", "'}'", "'class'", "'while'", "'if'", 
      "'elif'", "'else'", "'func'", "'->'", "'public'", "'private'", "'protected'", 
      "'fileprivae'", "'in'", "'out'", "'inout'", "'('", "')'", "'let'", 
      "'var'", "':'", "'\\n'", "'.'", "'\\r'", "';'", "'as'", "", "", "", 
      "", "", "", "'='", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", 
      "'||'", "'true'", "'false'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "AS", "ADD", "SUB", "MUL", 
      "DIV", "MOD", "DOT", "ASSIGN", "LESS", "GREATER", "LESS_EQ", "GREATER_EQ", 
      "EQUALITY", "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "TRUE", "FALSE", 
      "INT", "FLOAT", "CHAR", "STRING", "IDENTIFIER", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,51,358,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,
  	1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,20,1,
  	21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,
  	27,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,
  	33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,
  	39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,1,
  	43,1,43,1,44,1,44,1,44,1,44,1,44,1,44,1,45,3,45,272,8,45,1,45,4,45,275,
  	8,45,11,45,12,45,276,1,45,1,45,5,45,281,8,45,10,45,12,45,284,9,45,3,45,
  	286,8,45,1,46,3,46,289,8,46,1,46,5,46,292,8,46,10,46,12,46,295,9,46,1,
  	46,1,46,4,46,299,8,46,11,46,12,46,300,1,46,1,46,3,46,305,8,46,1,46,4,
  	46,308,8,46,11,46,12,46,309,3,46,312,8,46,1,46,1,46,5,46,316,8,46,10,
  	46,12,46,319,9,46,3,46,321,8,46,1,47,1,47,1,47,1,47,1,47,3,47,328,8,47,
  	3,47,330,8,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,3,48,339,8,48,5,48,341,
  	8,48,10,48,12,48,344,9,48,1,48,1,48,1,49,1,49,5,49,350,8,49,10,49,12,
  	49,353,9,49,1,50,1,50,1,50,1,50,0,0,51,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,
  	39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,
  	31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,
  	85,43,87,44,89,45,91,46,93,47,95,48,97,49,99,50,101,51,1,0,11,1,0,43,
  	43,1,0,45,45,1,0,42,42,1,0,47,47,1,0,37,37,1,0,46,46,1,0,48,57,3,0,65,
  	90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,4,0,10,10,13,13,34,34,92,
  	92,2,0,9,9,32,32,375,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,
  	0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,
  	1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,
  	0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,
  	0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,
  	1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,
  	0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,1,103,1,0,0,
  	0,3,105,1,0,0,0,5,112,1,0,0,0,7,114,1,0,0,0,9,116,1,0,0,0,11,122,1,0,
  	0,0,13,128,1,0,0,0,15,131,1,0,0,0,17,136,1,0,0,0,19,141,1,0,0,0,21,146,
  	1,0,0,0,23,149,1,0,0,0,25,156,1,0,0,0,27,164,1,0,0,0,29,174,1,0,0,0,31,
  	185,1,0,0,0,33,188,1,0,0,0,35,192,1,0,0,0,37,198,1,0,0,0,39,200,1,0,0,
  	0,41,202,1,0,0,0,43,206,1,0,0,0,45,210,1,0,0,0,47,212,1,0,0,0,49,214,
  	1,0,0,0,51,216,1,0,0,0,53,218,1,0,0,0,55,220,1,0,0,0,57,223,1,0,0,0,59,
  	225,1,0,0,0,61,227,1,0,0,0,63,229,1,0,0,0,65,231,1,0,0,0,67,233,1,0,0,
  	0,69,235,1,0,0,0,71,237,1,0,0,0,73,239,1,0,0,0,75,241,1,0,0,0,77,244,
  	1,0,0,0,79,247,1,0,0,0,81,250,1,0,0,0,83,253,1,0,0,0,85,256,1,0,0,0,87,
  	259,1,0,0,0,89,264,1,0,0,0,91,271,1,0,0,0,93,288,1,0,0,0,95,322,1,0,0,
  	0,97,333,1,0,0,0,99,347,1,0,0,0,101,354,1,0,0,0,103,104,5,44,0,0,104,
  	2,1,0,0,0,105,106,5,114,0,0,106,107,5,101,0,0,107,108,5,116,0,0,108,109,
  	5,117,0,0,109,110,5,114,0,0,110,111,5,110,0,0,111,4,1,0,0,0,112,113,5,
  	123,0,0,113,6,1,0,0,0,114,115,5,125,0,0,115,8,1,0,0,0,116,117,5,99,0,
  	0,117,118,5,108,0,0,118,119,5,97,0,0,119,120,5,115,0,0,120,121,5,115,
  	0,0,121,10,1,0,0,0,122,123,5,119,0,0,123,124,5,104,0,0,124,125,5,105,
  	0,0,125,126,5,108,0,0,126,127,5,101,0,0,127,12,1,0,0,0,128,129,5,105,
  	0,0,129,130,5,102,0,0,130,14,1,0,0,0,131,132,5,101,0,0,132,133,5,108,
  	0,0,133,134,5,105,0,0,134,135,5,102,0,0,135,16,1,0,0,0,136,137,5,101,
  	0,0,137,138,5,108,0,0,138,139,5,115,0,0,139,140,5,101,0,0,140,18,1,0,
  	0,0,141,142,5,102,0,0,142,143,5,117,0,0,143,144,5,110,0,0,144,145,5,99,
  	0,0,145,20,1,0,0,0,146,147,5,45,0,0,147,148,5,62,0,0,148,22,1,0,0,0,149,
  	150,5,112,0,0,150,151,5,117,0,0,151,152,5,98,0,0,152,153,5,108,0,0,153,
  	154,5,105,0,0,154,155,5,99,0,0,155,24,1,0,0,0,156,157,5,112,0,0,157,158,
  	5,114,0,0,158,159,5,105,0,0,159,160,5,118,0,0,160,161,5,97,0,0,161,162,
  	5,116,0,0,162,163,5,101,0,0,163,26,1,0,0,0,164,165,5,112,0,0,165,166,
  	5,114,0,0,166,167,5,111,0,0,167,168,5,116,0,0,168,169,5,101,0,0,169,170,
  	5,99,0,0,170,171,5,116,0,0,171,172,5,101,0,0,172,173,5,100,0,0,173,28,
  	1,0,0,0,174,175,5,102,0,0,175,176,5,105,0,0,176,177,5,108,0,0,177,178,
  	5,101,0,0,178,179,5,112,0,0,179,180,5,114,0,0,180,181,5,105,0,0,181,182,
  	5,118,0,0,182,183,5,97,0,0,183,184,5,101,0,0,184,30,1,0,0,0,185,186,5,
  	105,0,0,186,187,5,110,0,0,187,32,1,0,0,0,188,189,5,111,0,0,189,190,5,
  	117,0,0,190,191,5,116,0,0,191,34,1,0,0,0,192,193,5,105,0,0,193,194,5,
  	110,0,0,194,195,5,111,0,0,195,196,5,117,0,0,196,197,5,116,0,0,197,36,
  	1,0,0,0,198,199,5,40,0,0,199,38,1,0,0,0,200,201,5,41,0,0,201,40,1,0,0,
  	0,202,203,5,108,0,0,203,204,5,101,0,0,204,205,5,116,0,0,205,42,1,0,0,
  	0,206,207,5,118,0,0,207,208,5,97,0,0,208,209,5,114,0,0,209,44,1,0,0,0,
  	210,211,5,58,0,0,211,46,1,0,0,0,212,213,5,10,0,0,213,48,1,0,0,0,214,215,
  	5,46,0,0,215,50,1,0,0,0,216,217,5,13,0,0,217,52,1,0,0,0,218,219,5,59,
  	0,0,219,54,1,0,0,0,220,221,5,97,0,0,221,222,5,115,0,0,222,56,1,0,0,0,
  	223,224,7,0,0,0,224,58,1,0,0,0,225,226,7,1,0,0,226,60,1,0,0,0,227,228,
  	7,2,0,0,228,62,1,0,0,0,229,230,7,3,0,0,230,64,1,0,0,0,231,232,7,4,0,0,
  	232,66,1,0,0,0,233,234,7,5,0,0,234,68,1,0,0,0,235,236,5,61,0,0,236,70,
  	1,0,0,0,237,238,5,60,0,0,238,72,1,0,0,0,239,240,5,62,0,0,240,74,1,0,0,
  	0,241,242,5,60,0,0,242,243,5,61,0,0,243,76,1,0,0,0,244,245,5,62,0,0,245,
  	246,5,61,0,0,246,78,1,0,0,0,247,248,5,61,0,0,248,249,5,61,0,0,249,80,
  	1,0,0,0,250,251,5,33,0,0,251,252,5,61,0,0,252,82,1,0,0,0,253,254,5,38,
  	0,0,254,255,5,38,0,0,255,84,1,0,0,0,256,257,5,124,0,0,257,258,5,124,0,
  	0,258,86,1,0,0,0,259,260,5,116,0,0,260,261,5,114,0,0,261,262,5,117,0,
  	0,262,263,5,101,0,0,263,88,1,0,0,0,264,265,5,102,0,0,265,266,5,97,0,0,
  	266,267,5,108,0,0,267,268,5,115,0,0,268,269,5,101,0,0,269,90,1,0,0,0,
  	270,272,5,45,0,0,271,270,1,0,0,0,271,272,1,0,0,0,272,274,1,0,0,0,273,
  	275,7,6,0,0,274,273,1,0,0,0,275,276,1,0,0,0,276,274,1,0,0,0,276,277,1,
  	0,0,0,277,285,1,0,0,0,278,282,7,7,0,0,279,281,7,8,0,0,280,279,1,0,0,0,
  	281,284,1,0,0,0,282,280,1,0,0,0,282,283,1,0,0,0,283,286,1,0,0,0,284,282,
  	1,0,0,0,285,278,1,0,0,0,285,286,1,0,0,0,286,92,1,0,0,0,287,289,5,45,0,
  	0,288,287,1,0,0,0,288,289,1,0,0,0,289,293,1,0,0,0,290,292,7,6,0,0,291,
  	290,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,293,294,1,0,0,0,294,296,1,
  	0,0,0,295,293,1,0,0,0,296,298,7,5,0,0,297,299,7,6,0,0,298,297,1,0,0,0,
  	299,300,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,311,1,0,0,0,302,304,
  	5,101,0,0,303,305,5,45,0,0,304,303,1,0,0,0,304,305,1,0,0,0,305,307,1,
  	0,0,0,306,308,7,6,0,0,307,306,1,0,0,0,308,309,1,0,0,0,309,307,1,0,0,0,
  	309,310,1,0,0,0,310,312,1,0,0,0,311,302,1,0,0,0,311,312,1,0,0,0,312,320,
  	1,0,0,0,313,317,7,7,0,0,314,316,7,8,0,0,315,314,1,0,0,0,316,319,1,0,0,
  	0,317,315,1,0,0,0,317,318,1,0,0,0,318,321,1,0,0,0,319,317,1,0,0,0,320,
  	313,1,0,0,0,320,321,1,0,0,0,321,94,1,0,0,0,322,329,5,39,0,0,323,330,8,
  	9,0,0,324,327,5,92,0,0,325,328,9,0,0,0,326,328,5,0,0,1,327,325,1,0,0,
  	0,327,326,1,0,0,0,328,330,1,0,0,0,329,323,1,0,0,0,329,324,1,0,0,0,330,
  	331,1,0,0,0,331,332,5,39,0,0,332,96,1,0,0,0,333,342,5,34,0,0,334,341,
  	8,9,0,0,335,338,5,92,0,0,336,339,9,0,0,0,337,339,5,0,0,1,338,336,1,0,
  	0,0,338,337,1,0,0,0,339,341,1,0,0,0,340,334,1,0,0,0,340,335,1,0,0,0,341,
  	344,1,0,0,0,342,340,1,0,0,0,342,343,1,0,0,0,343,345,1,0,0,0,344,342,1,
  	0,0,0,345,346,5,34,0,0,346,98,1,0,0,0,347,351,7,7,0,0,348,350,7,8,0,0,
  	349,348,1,0,0,0,350,353,1,0,0,0,351,349,1,0,0,0,351,352,1,0,0,0,352,100,
  	1,0,0,0,353,351,1,0,0,0,354,355,7,10,0,0,355,356,1,0,0,0,356,357,6,50,
  	0,0,357,102,1,0,0,0,19,0,271,276,282,285,288,293,300,304,309,311,317,
  	320,327,329,338,340,342,351,1,6,0,0
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
