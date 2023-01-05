
// Generated from Fsc.g4 by ANTLR 4.11.1


#include "FscVisitor.h"

#include "FscParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FscParserStaticData final {
  FscParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FscParserStaticData(const FscParserStaticData&) = delete;
  FscParserStaticData(FscParserStaticData&&) = delete;
  FscParserStaticData& operator=(const FscParserStaticData&) = delete;
  FscParserStaticData& operator=(FscParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag fscParserOnceFlag;
FscParserStaticData *fscParserStaticData = nullptr;

void fscParserInitialize() {
  assert(fscParserStaticData == nullptr);
  auto staticData = std::make_unique<FscParserStaticData>(
    std::vector<std::string>{
      "program", "type", "templated_types", "stmt", "body", "class", "while_loop", 
      "if_stmt", "if", "elif", "else", "elif_def", "else_def", "function", 
      "visibility", "function_templates", "function_attibutes", "variable_attributes", 
      "argument_passing_type", "argument_definition", "parameters", "typed_arguments_list", 
      "argument", "function_call", "function_parameter", "function_typed_arguments_list", 
      "function_argument", "variable_prefix", "auto_variable_definition", 
      "variable_definition", "member_variable_access", "method_call", "expr", 
      "new_line", "stmt_end"
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
  	4,1,51,347,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,5,
  	0,72,8,0,10,0,12,0,75,9,0,1,1,1,1,1,1,1,1,1,1,1,1,3,1,83,8,1,1,2,1,2,
  	1,2,5,2,88,8,2,10,2,12,2,91,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,111,8,3,1,4,1,4,5,4,115,8,4,10,
  	4,12,4,118,9,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,5,9,144,8,9,10,9,12,9,147,9,
  	9,1,10,3,10,150,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,3,13,168,8,13,1,13,1,13,1,13,1,14,1,14,
  	1,15,1,15,1,15,1,15,3,15,179,8,15,1,16,3,16,182,8,16,1,17,3,17,185,8,
  	17,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,3,20,195,8,20,1,20,1,20,1,
  	21,1,21,1,21,5,21,202,8,21,10,21,12,21,205,9,21,1,22,1,22,1,22,3,22,210,
  	8,22,1,23,1,23,1,23,1,24,1,24,3,24,217,8,24,1,24,1,24,1,25,1,25,1,25,
  	5,25,224,8,25,10,25,12,25,227,9,25,1,26,1,26,3,26,231,8,26,1,26,1,26,
  	1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,5,29,250,8,29,10,29,12,29,253,9,29,1,29,3,29,256,8,29,1,30,1,30,
  	1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,3,32,280,8,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,5,32,331,8,32,10,32,12,32,334,9,32,1,33,5,33,337,8,33,10,33,
  	12,33,340,9,33,1,34,4,34,343,8,34,11,34,12,34,344,1,34,0,1,64,35,0,2,
  	4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,54,56,58,60,62,64,66,68,0,4,1,0,12,15,1,0,16,18,1,0,21,22,2,0,24,24,
  	26,27,365,0,73,1,0,0,0,2,82,1,0,0,0,4,84,1,0,0,0,6,110,1,0,0,0,8,112,
  	1,0,0,0,10,121,1,0,0,0,12,126,1,0,0,0,14,132,1,0,0,0,16,136,1,0,0,0,18,
  	145,1,0,0,0,20,149,1,0,0,0,22,151,1,0,0,0,24,157,1,0,0,0,26,160,1,0,0,
  	0,28,172,1,0,0,0,30,178,1,0,0,0,32,181,1,0,0,0,34,184,1,0,0,0,36,186,
  	1,0,0,0,38,188,1,0,0,0,40,192,1,0,0,0,42,198,1,0,0,0,44,206,1,0,0,0,46,
  	211,1,0,0,0,48,214,1,0,0,0,50,220,1,0,0,0,52,230,1,0,0,0,54,234,1,0,0,
  	0,56,236,1,0,0,0,58,242,1,0,0,0,60,257,1,0,0,0,62,260,1,0,0,0,64,279,
  	1,0,0,0,66,338,1,0,0,0,68,342,1,0,0,0,70,72,3,6,3,0,71,70,1,0,0,0,72,
  	75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,1,1,0,0,0,75,73,1,0,0,0,76,
  	83,5,50,0,0,77,78,5,50,0,0,78,79,5,36,0,0,79,80,3,4,2,0,80,81,5,37,0,
  	0,81,83,1,0,0,0,82,76,1,0,0,0,82,77,1,0,0,0,83,3,1,0,0,0,84,89,3,2,1,
  	0,85,86,5,1,0,0,86,88,3,2,1,0,87,85,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,
  	0,89,90,1,0,0,0,90,5,1,0,0,0,91,89,1,0,0,0,92,111,3,26,13,0,93,94,3,64,
  	32,0,94,95,3,68,34,0,95,111,1,0,0,0,96,97,3,10,5,0,97,98,3,68,34,0,98,
  	111,1,0,0,0,99,100,5,2,0,0,100,101,3,64,32,0,101,102,3,68,34,0,102,111,
  	1,0,0,0,103,104,3,14,7,0,104,105,3,68,34,0,105,111,1,0,0,0,106,107,3,
  	12,6,0,107,108,3,68,34,0,108,111,1,0,0,0,109,111,3,68,34,0,110,92,1,0,
  	0,0,110,93,1,0,0,0,110,96,1,0,0,0,110,99,1,0,0,0,110,103,1,0,0,0,110,
  	106,1,0,0,0,110,109,1,0,0,0,111,7,1,0,0,0,112,116,5,3,0,0,113,115,3,6,
  	3,0,114,113,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,
  	119,1,0,0,0,118,116,1,0,0,0,119,120,5,4,0,0,120,9,1,0,0,0,121,122,5,5,
  	0,0,122,123,5,50,0,0,123,124,3,66,33,0,124,125,3,8,4,0,125,11,1,0,0,0,
  	126,127,5,6,0,0,127,128,3,66,33,0,128,129,3,64,32,0,129,130,3,66,33,0,
  	130,131,3,8,4,0,131,13,1,0,0,0,132,133,3,16,8,0,133,134,3,18,9,0,134,
  	135,3,20,10,0,135,15,1,0,0,0,136,137,5,7,0,0,137,138,3,64,32,0,138,139,
  	3,66,33,0,139,140,3,8,4,0,140,141,3,66,33,0,141,17,1,0,0,0,142,144,3,
  	22,11,0,143,142,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,
  	0,146,19,1,0,0,0,147,145,1,0,0,0,148,150,3,24,12,0,149,148,1,0,0,0,149,
  	150,1,0,0,0,150,21,1,0,0,0,151,152,5,8,0,0,152,153,3,64,32,0,153,154,
  	3,66,33,0,154,155,3,8,4,0,155,156,3,66,33,0,156,23,1,0,0,0,157,158,5,
  	9,0,0,158,159,3,8,4,0,159,25,1,0,0,0,160,161,3,32,16,0,161,162,5,10,0,
  	0,162,163,5,50,0,0,163,164,3,30,15,0,164,167,3,40,20,0,165,166,5,11,0,
  	0,166,168,5,50,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,169,1,0,0,0,169,
  	170,3,66,33,0,170,171,3,8,4,0,171,27,1,0,0,0,172,173,7,0,0,0,173,29,1,
  	0,0,0,174,175,5,36,0,0,175,176,3,4,2,0,176,177,5,37,0,0,177,179,1,0,0,
  	0,178,174,1,0,0,0,178,179,1,0,0,0,179,31,1,0,0,0,180,182,3,28,14,0,181,
  	180,1,0,0,0,181,182,1,0,0,0,182,33,1,0,0,0,183,185,3,28,14,0,184,183,
  	1,0,0,0,184,185,1,0,0,0,185,35,1,0,0,0,186,187,7,1,0,0,187,37,1,0,0,0,
  	188,189,3,36,18,0,189,190,5,50,0,0,190,191,5,50,0,0,191,39,1,0,0,0,192,
  	194,5,19,0,0,193,195,3,42,21,0,194,193,1,0,0,0,194,195,1,0,0,0,195,196,
  	1,0,0,0,196,197,5,20,0,0,197,41,1,0,0,0,198,203,3,44,22,0,199,200,5,1,
  	0,0,200,202,3,44,22,0,201,199,1,0,0,0,202,205,1,0,0,0,203,201,1,0,0,0,
  	203,204,1,0,0,0,204,43,1,0,0,0,205,203,1,0,0,0,206,209,3,38,19,0,207,
  	208,5,35,0,0,208,210,3,64,32,0,209,207,1,0,0,0,209,210,1,0,0,0,210,45,
  	1,0,0,0,211,212,5,50,0,0,212,213,3,48,24,0,213,47,1,0,0,0,214,216,5,19,
  	0,0,215,217,3,50,25,0,216,215,1,0,0,0,216,217,1,0,0,0,217,218,1,0,0,0,
  	218,219,5,20,0,0,219,49,1,0,0,0,220,225,3,52,26,0,221,222,5,1,0,0,222,
  	224,3,52,26,0,223,221,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,226,
  	1,0,0,0,226,51,1,0,0,0,227,225,1,0,0,0,228,229,5,50,0,0,229,231,5,35,
  	0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,232,1,0,0,0,232,233,3,64,32,0,
  	233,53,1,0,0,0,234,235,7,2,0,0,235,55,1,0,0,0,236,237,3,34,17,0,237,238,
  	3,54,27,0,238,239,5,50,0,0,239,240,5,35,0,0,240,241,3,64,32,0,241,57,
  	1,0,0,0,242,243,3,34,17,0,243,244,3,54,27,0,244,245,5,50,0,0,245,246,
  	5,23,0,0,246,255,3,2,1,0,247,251,5,35,0,0,248,250,5,24,0,0,249,248,1,
  	0,0,0,250,253,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,254,1,0,0,0,
  	253,251,1,0,0,0,254,256,3,64,32,0,255,247,1,0,0,0,255,256,1,0,0,0,256,
  	59,1,0,0,0,257,258,5,25,0,0,258,259,5,50,0,0,259,61,1,0,0,0,260,261,5,
  	25,0,0,261,262,3,46,23,0,262,63,1,0,0,0,263,264,6,32,-1,0,264,280,3,46,
  	23,0,265,280,3,58,29,0,266,280,3,56,28,0,267,268,5,19,0,0,268,269,3,64,
  	32,0,269,270,5,20,0,0,270,280,1,0,0,0,271,280,3,8,4,0,272,280,5,46,0,
  	0,273,280,5,47,0,0,274,280,5,50,0,0,275,280,5,49,0,0,276,280,5,48,0,0,
  	277,280,5,44,0,0,278,280,5,45,0,0,279,263,1,0,0,0,279,265,1,0,0,0,279,
  	266,1,0,0,0,279,267,1,0,0,0,279,271,1,0,0,0,279,272,1,0,0,0,279,273,1,
  	0,0,0,279,274,1,0,0,0,279,275,1,0,0,0,279,276,1,0,0,0,279,277,1,0,0,0,
  	279,278,1,0,0,0,280,332,1,0,0,0,281,282,10,26,0,0,282,283,5,31,0,0,283,
  	331,3,64,32,27,284,285,10,25,0,0,285,286,5,32,0,0,286,331,3,64,32,26,
  	287,288,10,24,0,0,288,289,5,33,0,0,289,331,3,64,32,25,290,291,10,23,0,
  	0,291,292,5,29,0,0,292,331,3,64,32,24,293,294,10,22,0,0,294,295,5,30,
  	0,0,295,331,3,64,32,23,296,297,10,21,0,0,297,298,5,36,0,0,298,331,3,64,
  	32,22,299,300,10,20,0,0,300,301,5,37,0,0,301,331,3,64,32,21,302,303,10,
  	19,0,0,303,304,5,38,0,0,304,331,3,64,32,20,305,306,10,18,0,0,306,307,
  	5,39,0,0,307,331,3,64,32,19,308,309,10,17,0,0,309,310,5,40,0,0,310,331,
  	3,64,32,18,311,312,10,16,0,0,312,313,5,41,0,0,313,331,3,64,32,17,314,
  	315,10,15,0,0,315,316,5,42,0,0,316,331,3,64,32,16,317,318,10,14,0,0,318,
  	319,5,43,0,0,319,331,3,64,32,15,320,321,10,13,0,0,321,322,5,35,0,0,322,
  	331,3,64,32,14,323,324,10,29,0,0,324,331,3,60,30,0,325,326,10,28,0,0,
  	326,331,3,62,31,0,327,328,10,27,0,0,328,329,5,28,0,0,329,331,5,50,0,0,
  	330,281,1,0,0,0,330,284,1,0,0,0,330,287,1,0,0,0,330,290,1,0,0,0,330,293,
  	1,0,0,0,330,296,1,0,0,0,330,299,1,0,0,0,330,302,1,0,0,0,330,305,1,0,0,
  	0,330,308,1,0,0,0,330,311,1,0,0,0,330,314,1,0,0,0,330,317,1,0,0,0,330,
  	320,1,0,0,0,330,323,1,0,0,0,330,325,1,0,0,0,330,327,1,0,0,0,331,334,1,
  	0,0,0,332,330,1,0,0,0,332,333,1,0,0,0,333,65,1,0,0,0,334,332,1,0,0,0,
  	335,337,5,24,0,0,336,335,1,0,0,0,337,340,1,0,0,0,338,336,1,0,0,0,338,
  	339,1,0,0,0,339,67,1,0,0,0,340,338,1,0,0,0,341,343,7,3,0,0,342,341,1,
  	0,0,0,343,344,1,0,0,0,344,342,1,0,0,0,344,345,1,0,0,0,345,69,1,0,0,0,
  	24,73,82,89,110,116,145,149,167,178,181,184,194,203,209,216,225,230,251,
  	255,279,330,332,338,344
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fscParserStaticData = staticData.release();
}

}

FscParser::FscParser(TokenStream *input) : FscParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FscParser::FscParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FscParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *fscParserStaticData->atn, fscParserStaticData->decisionToDFA, fscParserStaticData->sharedContextCache, options);
}

FscParser::~FscParser() {
  delete _interpreter;
}

const atn::ATN& FscParser::getATN() const {
  return *fscParserStaticData->atn;
}

std::string FscParser::getGrammarFileName() const {
  return "Fsc.g4";
}

const std::vector<std::string>& FscParser::getRuleNames() const {
  return fscParserStaticData->ruleNames;
}

const dfa::Vocabulary& FscParser::getVocabulary() const {
  return fscParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FscParser::getSerializedATN() const {
  return fscParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

FscParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::StmtContext *> FscParser::ProgramContext::stmt() {
  return getRuleContexts<FscParser::StmtContext>();
}

FscParser::StmtContext* FscParser::ProgramContext::stmt(size_t i) {
  return getRuleContext<FscParser::StmtContext>(i);
}


size_t FscParser::ProgramContext::getRuleIndex() const {
  return FscParser::RuleProgram;
}


std::any FscParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ProgramContext* FscParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FscParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2234207852623084) != 0) {
      setState(70);
      stmt();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FscParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::TypeContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

tree::TerminalNode* FscParser::TypeContext::LESS() {
  return getToken(FscParser::LESS, 0);
}

FscParser::Templated_typesContext* FscParser::TypeContext::templated_types() {
  return getRuleContext<FscParser::Templated_typesContext>(0);
}

tree::TerminalNode* FscParser::TypeContext::GREATER() {
  return getToken(FscParser::GREATER, 0);
}


size_t FscParser::TypeContext::getRuleIndex() const {
  return FscParser::RuleType;
}


std::any FscParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FscParser::TypeContext* FscParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, FscParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      match(FscParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(77);
      match(FscParser::IDENTIFIER);
      setState(78);
      match(FscParser::LESS);
      setState(79);
      templated_types();
      setState(80);
      match(FscParser::GREATER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Templated_typesContext ------------------------------------------------------------------

FscParser::Templated_typesContext::Templated_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::TypeContext *> FscParser::Templated_typesContext::type() {
  return getRuleContexts<FscParser::TypeContext>();
}

FscParser::TypeContext* FscParser::Templated_typesContext::type(size_t i) {
  return getRuleContext<FscParser::TypeContext>(i);
}


size_t FscParser::Templated_typesContext::getRuleIndex() const {
  return FscParser::RuleTemplated_types;
}


std::any FscParser::Templated_typesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitTemplated_types(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Templated_typesContext* FscParser::templated_types() {
  Templated_typesContext *_localctx = _tracker.createInstance<Templated_typesContext>(_ctx, getState());
  enterRule(_localctx, 4, FscParser::RuleTemplated_types);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    type();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__0) {
      setState(85);
      match(FscParser::T__0);
      setState(86);
      type();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

FscParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::FunctionContext* FscParser::StmtContext::function() {
  return getRuleContext<FscParser::FunctionContext>(0);
}

FscParser::ExprContext* FscParser::StmtContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::Stmt_endContext* FscParser::StmtContext::stmt_end() {
  return getRuleContext<FscParser::Stmt_endContext>(0);
}

FscParser::ClassContext* FscParser::StmtContext::class_() {
  return getRuleContext<FscParser::ClassContext>(0);
}

FscParser::If_stmtContext* FscParser::StmtContext::if_stmt() {
  return getRuleContext<FscParser::If_stmtContext>(0);
}

FscParser::While_loopContext* FscParser::StmtContext::while_loop() {
  return getRuleContext<FscParser::While_loopContext>(0);
}


size_t FscParser::StmtContext::getRuleIndex() const {
  return FscParser::RuleStmt;
}


std::any FscParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

FscParser::StmtContext* FscParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, FscParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      expr(0);
      setState(94);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(96);
      class_();
      setState(97);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(99);
      match(FscParser::T__1);
      setState(100);
      expr(0);
      setState(101);
      stmt_end();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(103);
      if_stmt();
      setState(104);
      stmt_end();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(106);
      while_loop();
      setState(107);
      stmt_end();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(109);
      stmt_end();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

FscParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::StmtContext *> FscParser::BodyContext::stmt() {
  return getRuleContexts<FscParser::StmtContext>();
}

FscParser::StmtContext* FscParser::BodyContext::stmt(size_t i) {
  return getRuleContext<FscParser::StmtContext>(i);
}


size_t FscParser::BodyContext::getRuleIndex() const {
  return FscParser::RuleBody;
}


std::any FscParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

FscParser::BodyContext* FscParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 8, FscParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(FscParser::T__2);
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2234207852623084) != 0) {
      setState(113);
      stmt();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(FscParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassContext ------------------------------------------------------------------

FscParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::ClassContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

FscParser::New_lineContext* FscParser::ClassContext::new_line() {
  return getRuleContext<FscParser::New_lineContext>(0);
}

FscParser::BodyContext* FscParser::ClassContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::ClassContext::getRuleIndex() const {
  return FscParser::RuleClass;
}


std::any FscParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ClassContext* FscParser::class_() {
  ClassContext *_localctx = _tracker.createInstance<ClassContext>(_ctx, getState());
  enterRule(_localctx, 10, FscParser::RuleClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(FscParser::T__4);
    setState(122);
    match(FscParser::IDENTIFIER);
    setState(123);
    new_line();
    setState(124);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

FscParser::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::New_lineContext *> FscParser::While_loopContext::new_line() {
  return getRuleContexts<FscParser::New_lineContext>();
}

FscParser::New_lineContext* FscParser::While_loopContext::new_line(size_t i) {
  return getRuleContext<FscParser::New_lineContext>(i);
}

FscParser::ExprContext* FscParser::While_loopContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::BodyContext* FscParser::While_loopContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::While_loopContext::getRuleIndex() const {
  return FscParser::RuleWhile_loop;
}


std::any FscParser::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

FscParser::While_loopContext* FscParser::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 12, FscParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(FscParser::T__5);
    setState(127);
    new_line();
    setState(128);
    expr(0);
    setState(129);
    new_line();
    setState(130);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

FscParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::IfContext* FscParser::If_stmtContext::if_() {
  return getRuleContext<FscParser::IfContext>(0);
}

FscParser::ElifContext* FscParser::If_stmtContext::elif() {
  return getRuleContext<FscParser::ElifContext>(0);
}

FscParser::ElseContext* FscParser::If_stmtContext::else_() {
  return getRuleContext<FscParser::ElseContext>(0);
}


size_t FscParser::If_stmtContext::getRuleIndex() const {
  return FscParser::RuleIf_stmt;
}


std::any FscParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

FscParser::If_stmtContext* FscParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, FscParser::RuleIf_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    if_();
    setState(133);
    elif();
    setState(134);
    else_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

FscParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::ExprContext* FscParser::IfContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

std::vector<FscParser::New_lineContext *> FscParser::IfContext::new_line() {
  return getRuleContexts<FscParser::New_lineContext>();
}

FscParser::New_lineContext* FscParser::IfContext::new_line(size_t i) {
  return getRuleContext<FscParser::New_lineContext>(i);
}

FscParser::BodyContext* FscParser::IfContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::IfContext::getRuleIndex() const {
  return FscParser::RuleIf;
}


std::any FscParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}

FscParser::IfContext* FscParser::if_() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 16, FscParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(FscParser::T__6);
    setState(137);
    expr(0);
    setState(138);
    new_line();
    setState(139);
    body();
    setState(140);
    new_line();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElifContext ------------------------------------------------------------------

FscParser::ElifContext::ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::Elif_defContext *> FscParser::ElifContext::elif_def() {
  return getRuleContexts<FscParser::Elif_defContext>();
}

FscParser::Elif_defContext* FscParser::ElifContext::elif_def(size_t i) {
  return getRuleContext<FscParser::Elif_defContext>(i);
}


size_t FscParser::ElifContext::getRuleIndex() const {
  return FscParser::RuleElif;
}


std::any FscParser::ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitElif(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ElifContext* FscParser::elif() {
  ElifContext *_localctx = _tracker.createInstance<ElifContext>(_ctx, getState());
  enterRule(_localctx, 18, FscParser::RuleElif);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__7) {
      setState(142);
      elif_def();
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseContext ------------------------------------------------------------------

FscParser::ElseContext::ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Else_defContext* FscParser::ElseContext::else_def() {
  return getRuleContext<FscParser::Else_defContext>(0);
}


size_t FscParser::ElseContext::getRuleIndex() const {
  return FscParser::RuleElse;
}


std::any FscParser::ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitElse(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ElseContext* FscParser::else_() {
  ElseContext *_localctx = _tracker.createInstance<ElseContext>(_ctx, getState());
  enterRule(_localctx, 20, FscParser::RuleElse);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__8) {
      setState(148);
      else_def();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Elif_defContext ------------------------------------------------------------------

FscParser::Elif_defContext::Elif_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::ExprContext* FscParser::Elif_defContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

std::vector<FscParser::New_lineContext *> FscParser::Elif_defContext::new_line() {
  return getRuleContexts<FscParser::New_lineContext>();
}

FscParser::New_lineContext* FscParser::Elif_defContext::new_line(size_t i) {
  return getRuleContext<FscParser::New_lineContext>(i);
}

FscParser::BodyContext* FscParser::Elif_defContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::Elif_defContext::getRuleIndex() const {
  return FscParser::RuleElif_def;
}


std::any FscParser::Elif_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitElif_def(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Elif_defContext* FscParser::elif_def() {
  Elif_defContext *_localctx = _tracker.createInstance<Elif_defContext>(_ctx, getState());
  enterRule(_localctx, 22, FscParser::RuleElif_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(FscParser::T__7);
    setState(152);
    expr(0);
    setState(153);
    new_line();
    setState(154);
    body();
    setState(155);
    new_line();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_defContext ------------------------------------------------------------------

FscParser::Else_defContext::Else_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::BodyContext* FscParser::Else_defContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::Else_defContext::getRuleIndex() const {
  return FscParser::RuleElse_def;
}


std::any FscParser::Else_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitElse_def(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Else_defContext* FscParser::else_def() {
  Else_defContext *_localctx = _tracker.createInstance<Else_defContext>(_ctx, getState());
  enterRule(_localctx, 24, FscParser::RuleElse_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(FscParser::T__8);
    setState(158);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FscParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Function_attibutesContext* FscParser::FunctionContext::function_attibutes() {
  return getRuleContext<FscParser::Function_attibutesContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::FunctionContext::IDENTIFIER() {
  return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode* FscParser::FunctionContext::IDENTIFIER(size_t i) {
  return getToken(FscParser::IDENTIFIER, i);
}

FscParser::Function_templatesContext* FscParser::FunctionContext::function_templates() {
  return getRuleContext<FscParser::Function_templatesContext>(0);
}

FscParser::ParametersContext* FscParser::FunctionContext::parameters() {
  return getRuleContext<FscParser::ParametersContext>(0);
}

FscParser::New_lineContext* FscParser::FunctionContext::new_line() {
  return getRuleContext<FscParser::New_lineContext>(0);
}

FscParser::BodyContext* FscParser::FunctionContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::FunctionContext::getRuleIndex() const {
  return FscParser::RuleFunction;
}


std::any FscParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

FscParser::FunctionContext* FscParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 26, FscParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    function_attibutes();
    setState(161);
    match(FscParser::T__9);
    setState(162);
    match(FscParser::IDENTIFIER);
    setState(163);
    function_templates();
    setState(164);
    parameters();
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__10) {
      setState(165);
      match(FscParser::T__10);
      setState(166);
      match(FscParser::IDENTIFIER);
    }
    setState(169);
    new_line();
    setState(170);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VisibilityContext ------------------------------------------------------------------

FscParser::VisibilityContext::VisibilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FscParser::VisibilityContext::getRuleIndex() const {
  return FscParser::RuleVisibility;
}


std::any FscParser::VisibilityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitVisibility(this);
  else
    return visitor->visitChildren(this);
}

FscParser::VisibilityContext* FscParser::visibility() {
  VisibilityContext *_localctx = _tracker.createInstance<VisibilityContext>(_ctx, getState());
  enterRule(_localctx, 28, FscParser::RuleVisibility);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 61440) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_templatesContext ------------------------------------------------------------------

FscParser::Function_templatesContext::Function_templatesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::Function_templatesContext::LESS() {
  return getToken(FscParser::LESS, 0);
}

FscParser::Templated_typesContext* FscParser::Function_templatesContext::templated_types() {
  return getRuleContext<FscParser::Templated_typesContext>(0);
}

tree::TerminalNode* FscParser::Function_templatesContext::GREATER() {
  return getToken(FscParser::GREATER, 0);
}


size_t FscParser::Function_templatesContext::getRuleIndex() const {
  return FscParser::RuleFunction_templates;
}


std::any FscParser::Function_templatesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_templates(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_templatesContext* FscParser::function_templates() {
  Function_templatesContext *_localctx = _tracker.createInstance<Function_templatesContext>(_ctx, getState());
  enterRule(_localctx, 30, FscParser::RuleFunction_templates);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::LESS) {
      setState(174);
      match(FscParser::LESS);
      setState(175);
      templated_types();
      setState(176);
      match(FscParser::GREATER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_attibutesContext ------------------------------------------------------------------

FscParser::Function_attibutesContext::Function_attibutesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::VisibilityContext* FscParser::Function_attibutesContext::visibility() {
  return getRuleContext<FscParser::VisibilityContext>(0);
}


size_t FscParser::Function_attibutesContext::getRuleIndex() const {
  return FscParser::RuleFunction_attibutes;
}


std::any FscParser::Function_attibutesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_attibutes(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_attibutesContext* FscParser::function_attibutes() {
  Function_attibutesContext *_localctx = _tracker.createInstance<Function_attibutesContext>(_ctx, getState());
  enterRule(_localctx, 32, FscParser::RuleFunction_attibutes);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 61440) != 0) {
      setState(180);
      visibility();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_attributesContext ------------------------------------------------------------------

FscParser::Variable_attributesContext::Variable_attributesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::VisibilityContext* FscParser::Variable_attributesContext::visibility() {
  return getRuleContext<FscParser::VisibilityContext>(0);
}


size_t FscParser::Variable_attributesContext::getRuleIndex() const {
  return FscParser::RuleVariable_attributes;
}


std::any FscParser::Variable_attributesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitVariable_attributes(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Variable_attributesContext* FscParser::variable_attributes() {
  Variable_attributesContext *_localctx = _tracker.createInstance<Variable_attributesContext>(_ctx, getState());
  enterRule(_localctx, 34, FscParser::RuleVariable_attributes);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 61440) != 0) {
      setState(183);
      visibility();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_passing_typeContext ------------------------------------------------------------------

FscParser::Argument_passing_typeContext::Argument_passing_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FscParser::Argument_passing_typeContext::getRuleIndex() const {
  return FscParser::RuleArgument_passing_type;
}


std::any FscParser::Argument_passing_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitArgument_passing_type(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Argument_passing_typeContext* FscParser::argument_passing_type() {
  Argument_passing_typeContext *_localctx = _tracker.createInstance<Argument_passing_typeContext>(_ctx, getState());
  enterRule(_localctx, 36, FscParser::RuleArgument_passing_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_definitionContext ------------------------------------------------------------------

FscParser::Argument_definitionContext::Argument_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Argument_passing_typeContext* FscParser::Argument_definitionContext::argument_passing_type() {
  return getRuleContext<FscParser::Argument_passing_typeContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::Argument_definitionContext::IDENTIFIER() {
  return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode* FscParser::Argument_definitionContext::IDENTIFIER(size_t i) {
  return getToken(FscParser::IDENTIFIER, i);
}


size_t FscParser::Argument_definitionContext::getRuleIndex() const {
  return FscParser::RuleArgument_definition;
}


std::any FscParser::Argument_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitArgument_definition(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Argument_definitionContext* FscParser::argument_definition() {
  Argument_definitionContext *_localctx = _tracker.createInstance<Argument_definitionContext>(_ctx, getState());
  enterRule(_localctx, 38, FscParser::RuleArgument_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    argument_passing_type();
    setState(189);
    match(FscParser::IDENTIFIER);
    setState(190);
    match(FscParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

FscParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Typed_arguments_listContext* FscParser::ParametersContext::typed_arguments_list() {
  return getRuleContext<FscParser::Typed_arguments_listContext>(0);
}


size_t FscParser::ParametersContext::getRuleIndex() const {
  return FscParser::RuleParameters;
}


std::any FscParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ParametersContext* FscParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 40, FscParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(FscParser::T__18);
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0) {
      setState(193);
      typed_arguments_list();
    }
    setState(196);
    match(FscParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typed_arguments_listContext ------------------------------------------------------------------

FscParser::Typed_arguments_listContext::Typed_arguments_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::ArgumentContext *> FscParser::Typed_arguments_listContext::argument() {
  return getRuleContexts<FscParser::ArgumentContext>();
}

FscParser::ArgumentContext* FscParser::Typed_arguments_listContext::argument(size_t i) {
  return getRuleContext<FscParser::ArgumentContext>(i);
}


size_t FscParser::Typed_arguments_listContext::getRuleIndex() const {
  return FscParser::RuleTyped_arguments_list;
}


std::any FscParser::Typed_arguments_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitTyped_arguments_list(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Typed_arguments_listContext* FscParser::typed_arguments_list() {
  Typed_arguments_listContext *_localctx = _tracker.createInstance<Typed_arguments_listContext>(_ctx, getState());
  enterRule(_localctx, 42, FscParser::RuleTyped_arguments_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    argument();
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__0) {
      setState(199);
      match(FscParser::T__0);
      setState(200);
      argument();
      setState(205);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

FscParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Argument_definitionContext* FscParser::ArgumentContext::argument_definition() {
  return getRuleContext<FscParser::Argument_definitionContext>(0);
}

tree::TerminalNode* FscParser::ArgumentContext::ASSIGN() {
  return getToken(FscParser::ASSIGN, 0);
}

FscParser::ExprContext* FscParser::ArgumentContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}


size_t FscParser::ArgumentContext::getRuleIndex() const {
  return FscParser::RuleArgument;
}


std::any FscParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

FscParser::ArgumentContext* FscParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 44, FscParser::RuleArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    argument_definition();
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::ASSIGN) {
      setState(207);
      match(FscParser::ASSIGN);
      setState(208);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

FscParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::Function_callContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

FscParser::Function_parameterContext* FscParser::Function_callContext::function_parameter() {
  return getRuleContext<FscParser::Function_parameterContext>(0);
}


size_t FscParser::Function_callContext::getRuleIndex() const {
  return FscParser::RuleFunction_call;
}


std::any FscParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_callContext* FscParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 46, FscParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(FscParser::IDENTIFIER);
    setState(212);
    function_parameter();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_parameterContext ------------------------------------------------------------------

FscParser::Function_parameterContext::Function_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Function_typed_arguments_listContext* FscParser::Function_parameterContext::function_typed_arguments_list() {
  return getRuleContext<FscParser::Function_typed_arguments_listContext>(0);
}


size_t FscParser::Function_parameterContext::getRuleIndex() const {
  return FscParser::RuleFunction_parameter;
}


std::any FscParser::Function_parameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_parameter(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_parameterContext* FscParser::function_parameter() {
  Function_parameterContext *_localctx = _tracker.createInstance<Function_parameterContext>(_ctx, getState());
  enterRule(_localctx, 48, FscParser::RuleFunction_parameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(FscParser::T__18);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2234207634518024) != 0) {
      setState(215);
      function_typed_arguments_list();
    }
    setState(218);
    match(FscParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_typed_arguments_listContext ------------------------------------------------------------------

FscParser::Function_typed_arguments_listContext::Function_typed_arguments_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FscParser::Function_argumentContext *> FscParser::Function_typed_arguments_listContext::function_argument() {
  return getRuleContexts<FscParser::Function_argumentContext>();
}

FscParser::Function_argumentContext* FscParser::Function_typed_arguments_listContext::function_argument(size_t i) {
  return getRuleContext<FscParser::Function_argumentContext>(i);
}


size_t FscParser::Function_typed_arguments_listContext::getRuleIndex() const {
  return FscParser::RuleFunction_typed_arguments_list;
}


std::any FscParser::Function_typed_arguments_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_typed_arguments_list(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_typed_arguments_listContext* FscParser::function_typed_arguments_list() {
  Function_typed_arguments_listContext *_localctx = _tracker.createInstance<Function_typed_arguments_listContext>(_ctx, getState());
  enterRule(_localctx, 50, FscParser::RuleFunction_typed_arguments_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    function_argument();
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__0) {
      setState(221);
      match(FscParser::T__0);
      setState(222);
      function_argument();
      setState(227);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_argumentContext ------------------------------------------------------------------

FscParser::Function_argumentContext::Function_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::ExprContext* FscParser::Function_argumentContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

tree::TerminalNode* FscParser::Function_argumentContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

tree::TerminalNode* FscParser::Function_argumentContext::ASSIGN() {
  return getToken(FscParser::ASSIGN, 0);
}


size_t FscParser::Function_argumentContext::getRuleIndex() const {
  return FscParser::RuleFunction_argument;
}


std::any FscParser::Function_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitFunction_argument(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Function_argumentContext* FscParser::function_argument() {
  Function_argumentContext *_localctx = _tracker.createInstance<Function_argumentContext>(_ctx, getState());
  enterRule(_localctx, 52, FscParser::RuleFunction_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(228);
      match(FscParser::IDENTIFIER);
      setState(229);
      match(FscParser::ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(232);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_prefixContext ------------------------------------------------------------------

FscParser::Variable_prefixContext::Variable_prefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FscParser::Variable_prefixContext::getRuleIndex() const {
  return FscParser::RuleVariable_prefix;
}


std::any FscParser::Variable_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitVariable_prefix(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Variable_prefixContext* FscParser::variable_prefix() {
  Variable_prefixContext *_localctx = _tracker.createInstance<Variable_prefixContext>(_ctx, getState());
  enterRule(_localctx, 54, FscParser::RuleVariable_prefix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    _la = _input->LA(1);
    if (!(_la == FscParser::T__20

    || _la == FscParser::T__21)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Auto_variable_definitionContext ------------------------------------------------------------------

FscParser::Auto_variable_definitionContext::Auto_variable_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Variable_attributesContext* FscParser::Auto_variable_definitionContext::variable_attributes() {
  return getRuleContext<FscParser::Variable_attributesContext>(0);
}

FscParser::Variable_prefixContext* FscParser::Auto_variable_definitionContext::variable_prefix() {
  return getRuleContext<FscParser::Variable_prefixContext>(0);
}

tree::TerminalNode* FscParser::Auto_variable_definitionContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

tree::TerminalNode* FscParser::Auto_variable_definitionContext::ASSIGN() {
  return getToken(FscParser::ASSIGN, 0);
}

FscParser::ExprContext* FscParser::Auto_variable_definitionContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}


size_t FscParser::Auto_variable_definitionContext::getRuleIndex() const {
  return FscParser::RuleAuto_variable_definition;
}


std::any FscParser::Auto_variable_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitAuto_variable_definition(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Auto_variable_definitionContext* FscParser::auto_variable_definition() {
  Auto_variable_definitionContext *_localctx = _tracker.createInstance<Auto_variable_definitionContext>(_ctx, getState());
  enterRule(_localctx, 56, FscParser::RuleAuto_variable_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    variable_attributes();
    setState(237);
    variable_prefix();
    setState(238);
    match(FscParser::IDENTIFIER);
    setState(239);
    match(FscParser::ASSIGN);
    setState(240);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_definitionContext ------------------------------------------------------------------

FscParser::Variable_definitionContext::Variable_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Variable_attributesContext* FscParser::Variable_definitionContext::variable_attributes() {
  return getRuleContext<FscParser::Variable_attributesContext>(0);
}

FscParser::Variable_prefixContext* FscParser::Variable_definitionContext::variable_prefix() {
  return getRuleContext<FscParser::Variable_prefixContext>(0);
}

tree::TerminalNode* FscParser::Variable_definitionContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

FscParser::TypeContext* FscParser::Variable_definitionContext::type() {
  return getRuleContext<FscParser::TypeContext>(0);
}

FscParser::ExprContext* FscParser::Variable_definitionContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

tree::TerminalNode* FscParser::Variable_definitionContext::ASSIGN() {
  return getToken(FscParser::ASSIGN, 0);
}


size_t FscParser::Variable_definitionContext::getRuleIndex() const {
  return FscParser::RuleVariable_definition;
}


std::any FscParser::Variable_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitVariable_definition(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Variable_definitionContext* FscParser::variable_definition() {
  Variable_definitionContext *_localctx = _tracker.createInstance<Variable_definitionContext>(_ctx, getState());
  enterRule(_localctx, 58, FscParser::RuleVariable_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    variable_attributes();
    setState(243);
    variable_prefix();
    setState(244);
    match(FscParser::IDENTIFIER);
    setState(245);
    match(FscParser::T__22);
    setState(246);
    type();
    setState(255);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(247);
      match(FscParser::ASSIGN);
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FscParser::T__23) {
        setState(248);
        match(FscParser::T__23);
        setState(253);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(254);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_variable_accessContext ------------------------------------------------------------------

FscParser::Member_variable_accessContext::Member_variable_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::Member_variable_accessContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}


size_t FscParser::Member_variable_accessContext::getRuleIndex() const {
  return FscParser::RuleMember_variable_access;
}


std::any FscParser::Member_variable_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitMember_variable_access(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Member_variable_accessContext* FscParser::member_variable_access() {
  Member_variable_accessContext *_localctx = _tracker.createInstance<Member_variable_accessContext>(_ctx, getState());
  enterRule(_localctx, 60, FscParser::RuleMember_variable_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(FscParser::T__24);
    setState(258);
    match(FscParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_callContext ------------------------------------------------------------------

FscParser::Method_callContext::Method_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Function_callContext* FscParser::Method_callContext::function_call() {
  return getRuleContext<FscParser::Function_callContext>(0);
}


size_t FscParser::Method_callContext::getRuleIndex() const {
  return FscParser::RuleMethod_call;
}


std::any FscParser::Method_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitMethod_call(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Method_callContext* FscParser::method_call() {
  Method_callContext *_localctx = _tracker.createInstance<Method_callContext>(_ctx, getState());
  enterRule(_localctx, 62, FscParser::RuleMethod_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(FscParser::T__24);
    setState(261);
    function_call();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FscParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Function_callContext* FscParser::ExprContext::function_call() {
  return getRuleContext<FscParser::Function_callContext>(0);
}

FscParser::Variable_definitionContext* FscParser::ExprContext::variable_definition() {
  return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Auto_variable_definitionContext* FscParser::ExprContext::auto_variable_definition() {
  return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
}

std::vector<FscParser::ExprContext *> FscParser::ExprContext::expr() {
  return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext* FscParser::ExprContext::expr(size_t i) {
  return getRuleContext<FscParser::ExprContext>(i);
}

FscParser::BodyContext* FscParser::ExprContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
}

tree::TerminalNode* FscParser::ExprContext::INT() {
  return getToken(FscParser::INT, 0);
}

tree::TerminalNode* FscParser::ExprContext::FLOAT() {
  return getToken(FscParser::FLOAT, 0);
}

tree::TerminalNode* FscParser::ExprContext::IDENTIFIER() {
  return getToken(FscParser::IDENTIFIER, 0);
}

tree::TerminalNode* FscParser::ExprContext::STRING() {
  return getToken(FscParser::STRING, 0);
}

tree::TerminalNode* FscParser::ExprContext::CHAR() {
  return getToken(FscParser::CHAR, 0);
}

tree::TerminalNode* FscParser::ExprContext::TRUE() {
  return getToken(FscParser::TRUE, 0);
}

tree::TerminalNode* FscParser::ExprContext::FALSE() {
  return getToken(FscParser::FALSE, 0);
}

tree::TerminalNode* FscParser::ExprContext::MUL() {
  return getToken(FscParser::MUL, 0);
}

tree::TerminalNode* FscParser::ExprContext::DIV() {
  return getToken(FscParser::DIV, 0);
}

tree::TerminalNode* FscParser::ExprContext::MOD() {
  return getToken(FscParser::MOD, 0);
}

tree::TerminalNode* FscParser::ExprContext::ADD() {
  return getToken(FscParser::ADD, 0);
}

tree::TerminalNode* FscParser::ExprContext::SUB() {
  return getToken(FscParser::SUB, 0);
}

tree::TerminalNode* FscParser::ExprContext::LESS() {
  return getToken(FscParser::LESS, 0);
}

tree::TerminalNode* FscParser::ExprContext::GREATER() {
  return getToken(FscParser::GREATER, 0);
}

tree::TerminalNode* FscParser::ExprContext::LESS_EQ() {
  return getToken(FscParser::LESS_EQ, 0);
}

tree::TerminalNode* FscParser::ExprContext::GREATER_EQ() {
  return getToken(FscParser::GREATER_EQ, 0);
}

tree::TerminalNode* FscParser::ExprContext::EQUALITY() {
  return getToken(FscParser::EQUALITY, 0);
}

tree::TerminalNode* FscParser::ExprContext::INEQUALITY() {
  return getToken(FscParser::INEQUALITY, 0);
}

tree::TerminalNode* FscParser::ExprContext::LOGICAL_AND() {
  return getToken(FscParser::LOGICAL_AND, 0);
}

tree::TerminalNode* FscParser::ExprContext::LOGICAL_OR() {
  return getToken(FscParser::LOGICAL_OR, 0);
}

tree::TerminalNode* FscParser::ExprContext::ASSIGN() {
  return getToken(FscParser::ASSIGN, 0);
}

FscParser::Member_variable_accessContext* FscParser::ExprContext::member_variable_access() {
  return getRuleContext<FscParser::Member_variable_accessContext>(0);
}

FscParser::Method_callContext* FscParser::ExprContext::method_call() {
  return getRuleContext<FscParser::Method_callContext>(0);
}

tree::TerminalNode* FscParser::ExprContext::AS() {
  return getToken(FscParser::AS, 0);
}


size_t FscParser::ExprContext::getRuleIndex() const {
  return FscParser::RuleExpr;
}


std::any FscParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


FscParser::ExprContext* FscParser::expr() {
   return expr(0);
}

FscParser::ExprContext* FscParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FscParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FscParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, FscParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(264);
      function_call();
      break;
    }

    case 2: {
      setState(265);
      variable_definition();
      break;
    }

    case 3: {
      setState(266);
      auto_variable_definition();
      break;
    }

    case 4: {
      setState(267);
      match(FscParser::T__18);
      setState(268);
      expr(0);
      setState(269);
      match(FscParser::T__19);
      break;
    }

    case 5: {
      setState(271);
      body();
      break;
    }

    case 6: {
      setState(272);
      match(FscParser::INT);
      break;
    }

    case 7: {
      setState(273);
      match(FscParser::FLOAT);
      break;
    }

    case 8: {
      setState(274);
      match(FscParser::IDENTIFIER);
      break;
    }

    case 9: {
      setState(275);
      match(FscParser::STRING);
      break;
    }

    case 10: {
      setState(276);
      match(FscParser::CHAR);
      break;
    }

    case 11: {
      setState(277);
      match(FscParser::TRUE);
      break;
    }

    case 12: {
      setState(278);
      match(FscParser::FALSE);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(332);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(330);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(281);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(282);
          match(FscParser::MUL);
          setState(283);
          expr(27);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(284);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(285);
          match(FscParser::DIV);
          setState(286);
          expr(26);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(287);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(288);
          match(FscParser::MOD);
          setState(289);
          expr(25);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(290);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(291);
          match(FscParser::ADD);
          setState(292);
          expr(24);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(293);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(294);
          match(FscParser::SUB);
          setState(295);
          expr(23);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(296);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(297);
          match(FscParser::LESS);
          setState(298);
          expr(22);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(299);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(300);
          match(FscParser::GREATER);
          setState(301);
          expr(21);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(302);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(303);
          match(FscParser::LESS_EQ);
          setState(304);
          expr(20);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(305);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(306);
          match(FscParser::GREATER_EQ);
          setState(307);
          expr(19);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(308);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(309);
          match(FscParser::EQUALITY);
          setState(310);
          expr(18);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(311);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(312);
          match(FscParser::INEQUALITY);
          setState(313);
          expr(17);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(314);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(315);
          match(FscParser::LOGICAL_AND);
          setState(316);
          expr(16);
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(317);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(318);
          match(FscParser::LOGICAL_OR);
          setState(319);
          expr(15);
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(320);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(321);
          match(FscParser::ASSIGN);
          setState(322);
          expr(14);
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(323);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(324);
          member_variable_access();
          break;
        }

        case 16: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(325);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(326);
          method_call();
          break;
        }

        case 17: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(327);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(328);
          match(FscParser::AS);
          setState(329);
          match(FscParser::IDENTIFIER);
          break;
        }

        default:
          break;
        } 
      }
      setState(334);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- New_lineContext ------------------------------------------------------------------

FscParser::New_lineContext::New_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FscParser::New_lineContext::getRuleIndex() const {
  return FscParser::RuleNew_line;
}


std::any FscParser::New_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitNew_line(this);
  else
    return visitor->visitChildren(this);
}

FscParser::New_lineContext* FscParser::new_line() {
  New_lineContext *_localctx = _tracker.createInstance<New_lineContext>(_ctx, getState());
  enterRule(_localctx, 66, FscParser::RuleNew_line);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(335);
        match(FscParser::T__23); 
      }
      setState(340);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stmt_endContext ------------------------------------------------------------------

FscParser::Stmt_endContext::Stmt_endContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FscParser::Stmt_endContext::getRuleIndex() const {
  return FscParser::RuleStmt_end;
}


std::any FscParser::Stmt_endContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitStmt_end(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Stmt_endContext* FscParser::stmt_end() {
  Stmt_endContext *_localctx = _tracker.createInstance<Stmt_endContext>(_ctx, getState());
  enterRule(_localctx, 68, FscParser::RuleStmt_end);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(342); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(341);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 218103808) != 0)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(344); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FscParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 32: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 26);
    case 1: return precpred(_ctx, 25);
    case 2: return precpred(_ctx, 24);
    case 3: return precpred(_ctx, 23);
    case 4: return precpred(_ctx, 22);
    case 5: return precpred(_ctx, 21);
    case 6: return precpred(_ctx, 20);
    case 7: return precpred(_ctx, 19);
    case 8: return precpred(_ctx, 18);
    case 9: return precpred(_ctx, 17);
    case 10: return precpred(_ctx, 16);
    case 11: return precpred(_ctx, 15);
    case 12: return precpred(_ctx, 14);
    case 13: return precpred(_ctx, 13);
    case 14: return precpred(_ctx, 29);
    case 15: return precpred(_ctx, 28);
    case 16: return precpred(_ctx, 27);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
