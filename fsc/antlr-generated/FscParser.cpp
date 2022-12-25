
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
      "program", "type", "stmt", "body", "class", "while_loop", "if_stmt", 
      "if", "elif", "else", "elif_def", "else_def", "function", "visibility", 
      "function_attibutes", "variable_attributes", "argument_passing_type", 
      "argument_definition", "parameters", "typed_arguments_list", "argument", 
      "function_call", "function_parameter", "function_typed_arguments_list", 
      "function_argument", "variable_prefix", "auto_variable_definition", 
      "variable_definition", "member_variable_access", "method_call", "expr", 
      "new_line", "stmt_end"
    },
    std::vector<std::string>{
      "", "'<'", "'>'", "'return'", "'{'", "'}'", "'class'", "'while'", 
      "'if'", "'elif'", "'else'", "'func'", "'->'", "'public'", "'private'", 
      "'protected'", "'fileprivae'", "'in'", "'out'", "'inout'", "'('", 
      "')'", "','", "'let'", "'var'", "':'", "'\\n'", "'.'", "'\\r'", "';'", 
      "'as'", "", "", "", "", "", "", "'='", "'=='", "'!='", "'&&'", "'||'", 
      "'true'", "'false'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "AS", "ADD", "SUB", 
      "MUL", "DIV", "MOD", "DOT", "ASSIGN", "EQUALITY", "INEQUALITY", "LOGICAL_AND", 
      "LOGICAL_OR", "TRUE", "FALSE", "INT", "FLOAT", "CHAR", "STRING", "IDENTIFIER", 
      "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,49,315,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,5,0,68,8,0,10,0,12,0,71,
  	9,0,1,1,1,1,1,1,1,1,1,1,3,1,78,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,98,8,2,1,3,1,3,5,3,102,8,3,
  	10,3,12,3,105,9,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,5,8,131,8,8,10,8,12,8,134,
  	9,8,1,9,3,9,137,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,154,8,12,1,12,1,12,1,12,1,13,1,13,1,14,
  	3,14,162,8,14,1,15,3,15,165,8,15,1,16,1,16,1,17,1,17,1,17,1,17,1,18,1,
  	18,3,18,175,8,18,1,18,1,18,1,19,1,19,1,19,5,19,182,8,19,10,19,12,19,185,
  	9,19,1,20,1,20,1,20,3,20,190,8,20,1,21,1,21,1,21,1,22,1,22,3,22,197,8,
  	22,1,22,1,22,1,23,1,23,1,23,5,23,204,8,23,10,23,12,23,207,9,23,1,24,1,
  	24,3,24,211,8,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,5,27,230,8,27,10,27,12,27,233,9,27,1,
  	27,3,27,236,8,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,
  	30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,260,8,
  	30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,
  	30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,
  	30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,5,30,299,8,30,10,30,12,
  	30,302,9,30,1,31,5,31,305,8,31,10,31,12,31,308,9,31,1,32,4,32,311,8,32,
  	11,32,12,32,312,1,32,0,1,60,33,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,0,4,1,0,13,16,1,
  	0,17,19,1,0,23,24,2,0,26,26,28,29,329,0,69,1,0,0,0,2,77,1,0,0,0,4,97,
  	1,0,0,0,6,99,1,0,0,0,8,108,1,0,0,0,10,113,1,0,0,0,12,119,1,0,0,0,14,123,
  	1,0,0,0,16,132,1,0,0,0,18,136,1,0,0,0,20,138,1,0,0,0,22,144,1,0,0,0,24,
  	147,1,0,0,0,26,158,1,0,0,0,28,161,1,0,0,0,30,164,1,0,0,0,32,166,1,0,0,
  	0,34,168,1,0,0,0,36,172,1,0,0,0,38,178,1,0,0,0,40,186,1,0,0,0,42,191,
  	1,0,0,0,44,194,1,0,0,0,46,200,1,0,0,0,48,210,1,0,0,0,50,214,1,0,0,0,52,
  	216,1,0,0,0,54,222,1,0,0,0,56,237,1,0,0,0,58,240,1,0,0,0,60,259,1,0,0,
  	0,62,306,1,0,0,0,64,310,1,0,0,0,66,68,3,4,2,0,67,66,1,0,0,0,68,71,1,0,
  	0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,1,1,0,0,0,71,69,1,0,0,0,72,78,5,48,
  	0,0,73,74,5,48,0,0,74,75,5,1,0,0,75,76,5,48,0,0,76,78,5,2,0,0,77,72,1,
  	0,0,0,77,73,1,0,0,0,78,3,1,0,0,0,79,98,3,24,12,0,80,81,3,60,30,0,81,82,
  	3,64,32,0,82,98,1,0,0,0,83,84,3,8,4,0,84,85,3,64,32,0,85,98,1,0,0,0,86,
  	87,5,3,0,0,87,88,3,60,30,0,88,89,3,64,32,0,89,98,1,0,0,0,90,91,3,12,6,
  	0,91,92,3,64,32,0,92,98,1,0,0,0,93,94,3,10,5,0,94,95,3,64,32,0,95,98,
  	1,0,0,0,96,98,3,64,32,0,97,79,1,0,0,0,97,80,1,0,0,0,97,83,1,0,0,0,97,
  	86,1,0,0,0,97,90,1,0,0,0,97,93,1,0,0,0,97,96,1,0,0,0,98,5,1,0,0,0,99,
  	103,5,4,0,0,100,102,3,4,2,0,101,100,1,0,0,0,102,105,1,0,0,0,103,101,1,
  	0,0,0,103,104,1,0,0,0,104,106,1,0,0,0,105,103,1,0,0,0,106,107,5,5,0,0,
  	107,7,1,0,0,0,108,109,5,6,0,0,109,110,5,48,0,0,110,111,3,62,31,0,111,
  	112,3,6,3,0,112,9,1,0,0,0,113,114,5,7,0,0,114,115,3,62,31,0,115,116,3,
  	60,30,0,116,117,3,62,31,0,117,118,3,6,3,0,118,11,1,0,0,0,119,120,3,14,
  	7,0,120,121,3,16,8,0,121,122,3,18,9,0,122,13,1,0,0,0,123,124,5,8,0,0,
  	124,125,3,60,30,0,125,126,3,62,31,0,126,127,3,6,3,0,127,128,3,62,31,0,
  	128,15,1,0,0,0,129,131,3,20,10,0,130,129,1,0,0,0,131,134,1,0,0,0,132,
  	130,1,0,0,0,132,133,1,0,0,0,133,17,1,0,0,0,134,132,1,0,0,0,135,137,3,
  	22,11,0,136,135,1,0,0,0,136,137,1,0,0,0,137,19,1,0,0,0,138,139,5,9,0,
  	0,139,140,3,60,30,0,140,141,3,62,31,0,141,142,3,6,3,0,142,143,3,62,31,
  	0,143,21,1,0,0,0,144,145,5,10,0,0,145,146,3,6,3,0,146,23,1,0,0,0,147,
  	148,3,28,14,0,148,149,5,11,0,0,149,150,5,48,0,0,150,153,3,36,18,0,151,
  	152,5,12,0,0,152,154,5,48,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,155,
  	1,0,0,0,155,156,3,62,31,0,156,157,3,6,3,0,157,25,1,0,0,0,158,159,7,0,
  	0,0,159,27,1,0,0,0,160,162,3,26,13,0,161,160,1,0,0,0,161,162,1,0,0,0,
  	162,29,1,0,0,0,163,165,3,26,13,0,164,163,1,0,0,0,164,165,1,0,0,0,165,
  	31,1,0,0,0,166,167,7,1,0,0,167,33,1,0,0,0,168,169,3,32,16,0,169,170,5,
  	48,0,0,170,171,5,48,0,0,171,35,1,0,0,0,172,174,5,20,0,0,173,175,3,38,
  	19,0,174,173,1,0,0,0,174,175,1,0,0,0,175,176,1,0,0,0,176,177,5,21,0,0,
  	177,37,1,0,0,0,178,183,3,40,20,0,179,180,5,22,0,0,180,182,3,40,20,0,181,
  	179,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,39,1,
  	0,0,0,185,183,1,0,0,0,186,189,3,34,17,0,187,188,5,37,0,0,188,190,3,60,
  	30,0,189,187,1,0,0,0,189,190,1,0,0,0,190,41,1,0,0,0,191,192,5,48,0,0,
  	192,193,3,44,22,0,193,43,1,0,0,0,194,196,5,20,0,0,195,197,3,46,23,0,196,
  	195,1,0,0,0,196,197,1,0,0,0,197,198,1,0,0,0,198,199,5,21,0,0,199,45,1,
  	0,0,0,200,205,3,48,24,0,201,202,5,22,0,0,202,204,3,48,24,0,203,201,1,
  	0,0,0,204,207,1,0,0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,47,1,0,0,0,
  	207,205,1,0,0,0,208,209,5,48,0,0,209,211,5,37,0,0,210,208,1,0,0,0,210,
  	211,1,0,0,0,211,212,1,0,0,0,212,213,3,60,30,0,213,49,1,0,0,0,214,215,
  	7,2,0,0,215,51,1,0,0,0,216,217,3,30,15,0,217,218,3,50,25,0,218,219,5,
  	48,0,0,219,220,5,37,0,0,220,221,3,60,30,0,221,53,1,0,0,0,222,223,3,30,
  	15,0,223,224,3,50,25,0,224,225,5,48,0,0,225,226,5,25,0,0,226,235,5,48,
  	0,0,227,231,5,37,0,0,228,230,5,26,0,0,229,228,1,0,0,0,230,233,1,0,0,0,
  	231,229,1,0,0,0,231,232,1,0,0,0,232,234,1,0,0,0,233,231,1,0,0,0,234,236,
  	3,60,30,0,235,227,1,0,0,0,235,236,1,0,0,0,236,55,1,0,0,0,237,238,5,27,
  	0,0,238,239,5,48,0,0,239,57,1,0,0,0,240,241,5,27,0,0,241,242,3,42,21,
  	0,242,59,1,0,0,0,243,244,6,30,-1,0,244,260,3,42,21,0,245,260,3,54,27,
  	0,246,260,3,52,26,0,247,248,5,20,0,0,248,249,3,60,30,0,249,250,5,21,0,
  	0,250,260,1,0,0,0,251,260,3,6,3,0,252,260,5,44,0,0,253,260,5,45,0,0,254,
  	260,5,48,0,0,255,260,5,47,0,0,256,260,5,46,0,0,257,260,5,42,0,0,258,260,
  	5,43,0,0,259,243,1,0,0,0,259,245,1,0,0,0,259,246,1,0,0,0,259,247,1,0,
  	0,0,259,251,1,0,0,0,259,252,1,0,0,0,259,253,1,0,0,0,259,254,1,0,0,0,259,
  	255,1,0,0,0,259,256,1,0,0,0,259,257,1,0,0,0,259,258,1,0,0,0,260,300,1,
  	0,0,0,261,262,10,22,0,0,262,263,5,33,0,0,263,299,3,60,30,23,264,265,10,
  	21,0,0,265,266,5,34,0,0,266,299,3,60,30,22,267,268,10,20,0,0,268,269,
  	5,35,0,0,269,299,3,60,30,21,270,271,10,19,0,0,271,272,5,31,0,0,272,299,
  	3,60,30,20,273,274,10,18,0,0,274,275,5,32,0,0,275,299,3,60,30,19,276,
  	277,10,17,0,0,277,278,5,38,0,0,278,299,3,60,30,18,279,280,10,16,0,0,280,
  	281,5,39,0,0,281,299,3,60,30,17,282,283,10,15,0,0,283,284,5,40,0,0,284,
  	299,3,60,30,16,285,286,10,14,0,0,286,287,5,41,0,0,287,299,3,60,30,15,
  	288,289,10,13,0,0,289,290,5,37,0,0,290,299,3,60,30,14,291,292,10,25,0,
  	0,292,299,3,56,28,0,293,294,10,24,0,0,294,299,3,58,29,0,295,296,10,23,
  	0,0,296,297,5,30,0,0,297,299,5,48,0,0,298,261,1,0,0,0,298,264,1,0,0,0,
  	298,267,1,0,0,0,298,270,1,0,0,0,298,273,1,0,0,0,298,276,1,0,0,0,298,279,
  	1,0,0,0,298,282,1,0,0,0,298,285,1,0,0,0,298,288,1,0,0,0,298,291,1,0,0,
  	0,298,293,1,0,0,0,298,295,1,0,0,0,299,302,1,0,0,0,300,298,1,0,0,0,300,
  	301,1,0,0,0,301,61,1,0,0,0,302,300,1,0,0,0,303,305,5,26,0,0,304,303,1,
  	0,0,0,305,308,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,63,1,0,0,0,
  	308,306,1,0,0,0,309,311,7,3,0,0,310,309,1,0,0,0,311,312,1,0,0,0,312,310,
  	1,0,0,0,312,313,1,0,0,0,313,65,1,0,0,0,22,69,77,97,103,132,136,153,161,
  	164,174,183,189,196,205,210,231,235,259,298,300,306,312
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
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 558552805665240) != 0) {
      setState(66);
      stmt();
      setState(71);
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

std::vector<tree::TerminalNode *> FscParser::TypeContext::IDENTIFIER() {
  return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode* FscParser::TypeContext::IDENTIFIER(size_t i) {
  return getToken(FscParser::IDENTIFIER, i);
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
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      match(FscParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      match(FscParser::IDENTIFIER);
      setState(74);
      match(FscParser::T__0);
      setState(75);
      match(FscParser::IDENTIFIER);
      setState(76);
      match(FscParser::T__1);
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
  enterRule(_localctx, 4, FscParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(79);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(80);
      expr(0);
      setState(81);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(83);
      class_();
      setState(84);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(86);
      match(FscParser::T__2);
      setState(87);
      expr(0);
      setState(88);
      stmt_end();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(90);
      if_stmt();
      setState(91);
      stmt_end();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(93);
      while_loop();
      setState(94);
      stmt_end();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(96);
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
  enterRule(_localctx, 6, FscParser::RuleBody);
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
    setState(99);
    match(FscParser::T__3);
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 558552805665240) != 0) {
      setState(100);
      stmt();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
    match(FscParser::T__4);
   
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
  enterRule(_localctx, 8, FscParser::RuleClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(FscParser::T__5);
    setState(109);
    match(FscParser::IDENTIFIER);
    setState(110);
    new_line();
    setState(111);
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
  enterRule(_localctx, 10, FscParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(FscParser::T__6);
    setState(114);
    new_line();
    setState(115);
    expr(0);
    setState(116);
    new_line();
    setState(117);
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
  enterRule(_localctx, 12, FscParser::RuleIf_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    if_();
    setState(120);
    elif();
    setState(121);
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
  enterRule(_localctx, 14, FscParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(FscParser::T__7);
    setState(124);
    expr(0);
    setState(125);
    new_line();
    setState(126);
    body();
    setState(127);
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
  enterRule(_localctx, 16, FscParser::RuleElif);
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
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__8) {
      setState(129);
      elif_def();
      setState(134);
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
  enterRule(_localctx, 18, FscParser::RuleElse);
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
    setState(136);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__9) {
      setState(135);
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
  enterRule(_localctx, 20, FscParser::RuleElif_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(FscParser::T__8);
    setState(139);
    expr(0);
    setState(140);
    new_line();
    setState(141);
    body();
    setState(142);
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
  enterRule(_localctx, 22, FscParser::RuleElse_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(FscParser::T__9);
    setState(145);
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
  enterRule(_localctx, 24, FscParser::RuleFunction);
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
    setState(147);
    function_attibutes();
    setState(148);
    match(FscParser::T__10);
    setState(149);
    match(FscParser::IDENTIFIER);
    setState(150);
    parameters();
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__11) {
      setState(151);
      match(FscParser::T__11);
      setState(152);
      match(FscParser::IDENTIFIER);
    }
    setState(155);
    new_line();
    setState(156);
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
  enterRule(_localctx, 26, FscParser::RuleVisibility);
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
    setState(158);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 122880) != 0)) {
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
  enterRule(_localctx, 28, FscParser::RuleFunction_attibutes);
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
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 122880) != 0) {
      setState(160);
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
  enterRule(_localctx, 30, FscParser::RuleVariable_attributes);
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
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 122880) != 0) {
      setState(163);
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
  enterRule(_localctx, 32, FscParser::RuleArgument_passing_type);
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
    setState(166);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 917504) != 0)) {
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
  enterRule(_localctx, 34, FscParser::RuleArgument_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    argument_passing_type();
    setState(169);
    match(FscParser::IDENTIFIER);
    setState(170);
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
  enterRule(_localctx, 36, FscParser::RuleParameters);
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
    match(FscParser::T__19);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 917504) != 0) {
      setState(173);
      typed_arguments_list();
    }
    setState(176);
    match(FscParser::T__20);
   
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
  enterRule(_localctx, 38, FscParser::RuleTyped_arguments_list);
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
    argument();
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__21) {
      setState(179);
      match(FscParser::T__21);
      setState(180);
      argument();
      setState(185);
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
  enterRule(_localctx, 40, FscParser::RuleArgument);
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
    argument_definition();
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::ASSIGN) {
      setState(187);
      match(FscParser::ASSIGN);
      setState(188);
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
  enterRule(_localctx, 42, FscParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(FscParser::IDENTIFIER);
    setState(192);
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
  enterRule(_localctx, 44, FscParser::RuleFunction_parameter);
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
    setState(194);
    match(FscParser::T__19);
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 558551933247504) != 0) {
      setState(195);
      function_typed_arguments_list();
    }
    setState(198);
    match(FscParser::T__20);
   
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
  enterRule(_localctx, 46, FscParser::RuleFunction_typed_arguments_list);
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
    setState(200);
    function_argument();
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__21) {
      setState(201);
      match(FscParser::T__21);
      setState(202);
      function_argument();
      setState(207);
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
  enterRule(_localctx, 48, FscParser::RuleFunction_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(208);
      match(FscParser::IDENTIFIER);
      setState(209);
      match(FscParser::ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(212);
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
  enterRule(_localctx, 50, FscParser::RuleVariable_prefix);
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
    _la = _input->LA(1);
    if (!(_la == FscParser::T__22

    || _la == FscParser::T__23)) {
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
  enterRule(_localctx, 52, FscParser::RuleAuto_variable_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    variable_attributes();
    setState(217);
    variable_prefix();
    setState(218);
    match(FscParser::IDENTIFIER);
    setState(219);
    match(FscParser::ASSIGN);
    setState(220);
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

std::vector<tree::TerminalNode *> FscParser::Variable_definitionContext::IDENTIFIER() {
  return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode* FscParser::Variable_definitionContext::IDENTIFIER(size_t i) {
  return getToken(FscParser::IDENTIFIER, i);
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
  enterRule(_localctx, 54, FscParser::RuleVariable_definition);
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
    setState(222);
    variable_attributes();
    setState(223);
    variable_prefix();
    setState(224);
    match(FscParser::IDENTIFIER);
    setState(225);
    match(FscParser::T__24);
    setState(226);
    match(FscParser::IDENTIFIER);
    setState(235);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(227);
      match(FscParser::ASSIGN);
      setState(231);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FscParser::T__25) {
        setState(228);
        match(FscParser::T__25);
        setState(233);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(234);
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
  enterRule(_localctx, 56, FscParser::RuleMember_variable_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(FscParser::T__26);
    setState(238);
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
  enterRule(_localctx, 58, FscParser::RuleMethod_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(FscParser::T__26);
    setState(241);
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
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, FscParser::RuleExpr, precedence);

    

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
    setState(259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(244);
      function_call();
      break;
    }

    case 2: {
      setState(245);
      variable_definition();
      break;
    }

    case 3: {
      setState(246);
      auto_variable_definition();
      break;
    }

    case 4: {
      setState(247);
      match(FscParser::T__19);
      setState(248);
      expr(0);
      setState(249);
      match(FscParser::T__20);
      break;
    }

    case 5: {
      setState(251);
      body();
      break;
    }

    case 6: {
      setState(252);
      match(FscParser::INT);
      break;
    }

    case 7: {
      setState(253);
      match(FscParser::FLOAT);
      break;
    }

    case 8: {
      setState(254);
      match(FscParser::IDENTIFIER);
      break;
    }

    case 9: {
      setState(255);
      match(FscParser::STRING);
      break;
    }

    case 10: {
      setState(256);
      match(FscParser::CHAR);
      break;
    }

    case 11: {
      setState(257);
      match(FscParser::TRUE);
      break;
    }

    case 12: {
      setState(258);
      match(FscParser::FALSE);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(298);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(261);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(262);
          match(FscParser::MUL);
          setState(263);
          expr(23);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(264);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(265);
          match(FscParser::DIV);
          setState(266);
          expr(22);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(267);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(268);
          match(FscParser::MOD);
          setState(269);
          expr(21);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(270);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(271);
          match(FscParser::ADD);
          setState(272);
          expr(20);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(273);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(274);
          match(FscParser::SUB);
          setState(275);
          expr(19);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(276);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(277);
          match(FscParser::EQUALITY);
          setState(278);
          expr(18);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(279);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(280);
          match(FscParser::INEQUALITY);
          setState(281);
          expr(17);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(282);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(283);
          match(FscParser::LOGICAL_AND);
          setState(284);
          expr(16);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(285);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(286);
          match(FscParser::LOGICAL_OR);
          setState(287);
          expr(15);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(288);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(289);
          match(FscParser::ASSIGN);
          setState(290);
          expr(14);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(291);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(292);
          member_variable_access();
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(293);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(294);
          method_call();
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(295);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(296);
          match(FscParser::AS);
          setState(297);
          match(FscParser::IDENTIFIER);
          break;
        }

        default:
          break;
        } 
      }
      setState(302);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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
  enterRule(_localctx, 62, FscParser::RuleNew_line);

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
    setState(306);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(303);
        match(FscParser::T__25); 
      }
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
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
  enterRule(_localctx, 64, FscParser::RuleStmt_end);
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
    setState(310); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(309);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 872415232) != 0)) {
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
      setState(312); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
    case 30: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 22);
    case 1: return precpred(_ctx, 21);
    case 2: return precpred(_ctx, 20);
    case 3: return precpred(_ctx, 19);
    case 4: return precpred(_ctx, 18);
    case 5: return precpred(_ctx, 17);
    case 6: return precpred(_ctx, 16);
    case 7: return precpred(_ctx, 15);
    case 8: return precpred(_ctx, 14);
    case 9: return precpred(_ctx, 13);
    case 10: return precpred(_ctx, 25);
    case 11: return precpred(_ctx, 24);
    case 12: return precpred(_ctx, 23);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
