
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
      "program", "stmt", "if_stmt", "if", "elif", "else", "stmt_end", "function", 
      "visibility", "function_attibutes", "variable_attributes", "argument_definition", 
      "argument_passing_type", "parameters", "typed_arguments_list", "argument", 
      "class", "function_call", "function_parameter", "function_typed_arguments_list", 
      "function_argument", "variable_definition", "auto_variable_definition", 
      "variable_prefix", "body", "expr"
    },
    std::vector<std::string>{
      "", "'return'", "'if'", "'\\n'", "'elif'", "'else'", "'\\r'", "';'", 
      "'func'", "'->'", "'public'", "'private'", "'protected'", "'fileprivae'", 
      "'in'", "'out'", "'inout'", "'('", "')'", "','", "'='", "'class'", 
      "':'", "'let'", "'var'", "'{'", "'}'", "'.'", "'as'", "", "", "", 
      "", "", "", "'=='", "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "AS", "ADD", "SUB", "MUL", 
      "DIV", "MOD", "DOT", "EQUALITY", "INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", 
      "INT", "FLOAT", "NAME", "LAYOUT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,290,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,5,0,54,8,0,10,0,12,0,57,
  	9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,74,
  	8,1,1,2,1,2,5,2,78,8,2,10,2,12,2,81,9,2,1,2,3,2,84,8,2,1,3,1,3,1,3,5,
  	3,89,8,3,10,3,12,3,92,9,3,1,3,1,3,5,3,96,8,3,10,3,12,3,99,9,3,1,4,1,4,
  	1,4,5,4,104,8,4,10,4,12,4,107,9,4,1,4,1,4,5,4,111,8,4,10,4,12,4,114,9,
  	4,1,5,1,5,1,5,1,6,4,6,120,8,6,11,6,12,6,121,1,7,1,7,1,7,1,7,1,7,1,7,3,
  	7,130,8,7,1,7,5,7,133,8,7,10,7,12,7,136,9,7,1,7,1,7,1,8,1,8,1,9,3,9,143,
  	8,9,1,10,3,10,146,8,10,1,11,1,11,1,11,1,11,1,12,1,12,1,13,1,13,3,13,156,
  	8,13,1,13,1,13,1,14,1,14,1,14,5,14,163,8,14,10,14,12,14,166,9,14,1,15,
  	1,15,1,15,3,15,171,8,15,1,16,1,16,1,16,5,16,176,8,16,10,16,12,16,179,
  	9,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,3,18,188,8,18,1,18,1,18,1,19,
  	1,19,1,19,5,19,195,8,19,10,19,12,19,198,9,19,1,20,1,20,3,20,202,8,20,
  	1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,213,8,21,10,21,12,21,
  	216,9,21,1,21,3,21,219,8,21,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,
  	24,1,24,5,24,231,8,24,10,24,12,24,234,9,24,1,24,1,24,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,250,8,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,5,25,285,8,25,10,25,12,25,288,9,25,1,25,0,1,50,26,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,0,
  	4,2,0,3,3,6,7,1,0,10,13,1,0,14,16,1,0,23,24,308,0,55,1,0,0,0,2,73,1,0,
  	0,0,4,75,1,0,0,0,6,85,1,0,0,0,8,100,1,0,0,0,10,115,1,0,0,0,12,119,1,0,
  	0,0,14,123,1,0,0,0,16,139,1,0,0,0,18,142,1,0,0,0,20,145,1,0,0,0,22,147,
  	1,0,0,0,24,151,1,0,0,0,26,153,1,0,0,0,28,159,1,0,0,0,30,167,1,0,0,0,32,
  	172,1,0,0,0,34,182,1,0,0,0,36,185,1,0,0,0,38,191,1,0,0,0,40,201,1,0,0,
  	0,42,205,1,0,0,0,44,220,1,0,0,0,46,226,1,0,0,0,48,228,1,0,0,0,50,249,
  	1,0,0,0,52,54,3,2,1,0,53,52,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,
  	1,0,0,0,56,1,1,0,0,0,57,55,1,0,0,0,58,74,3,14,7,0,59,60,3,50,25,0,60,
  	61,3,12,6,0,61,74,1,0,0,0,62,63,3,32,16,0,63,64,3,12,6,0,64,74,1,0,0,
  	0,65,66,5,1,0,0,66,67,3,50,25,0,67,68,3,12,6,0,68,74,1,0,0,0,69,70,3,
  	4,2,0,70,71,3,12,6,0,71,74,1,0,0,0,72,74,3,12,6,0,73,58,1,0,0,0,73,59,
  	1,0,0,0,73,62,1,0,0,0,73,65,1,0,0,0,73,69,1,0,0,0,73,72,1,0,0,0,74,3,
  	1,0,0,0,75,79,3,6,3,0,76,78,3,8,4,0,77,76,1,0,0,0,78,81,1,0,0,0,79,77,
  	1,0,0,0,79,80,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,82,84,3,10,5,0,83,82,
  	1,0,0,0,83,84,1,0,0,0,84,5,1,0,0,0,85,86,5,2,0,0,86,90,3,50,25,0,87,89,
  	5,3,0,0,88,87,1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,
  	1,0,0,0,92,90,1,0,0,0,93,97,3,48,24,0,94,96,5,3,0,0,95,94,1,0,0,0,96,
  	99,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,7,1,0,0,0,99,97,1,0,0,0,100,
  	101,5,4,0,0,101,105,3,50,25,0,102,104,5,3,0,0,103,102,1,0,0,0,104,107,
  	1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,107,105,1,0,0,
  	0,108,112,3,48,24,0,109,111,5,3,0,0,110,109,1,0,0,0,111,114,1,0,0,0,112,
  	110,1,0,0,0,112,113,1,0,0,0,113,9,1,0,0,0,114,112,1,0,0,0,115,116,5,5,
  	0,0,116,117,3,48,24,0,117,11,1,0,0,0,118,120,7,0,0,0,119,118,1,0,0,0,
  	120,121,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,13,1,0,0,0,123,124,
  	3,18,9,0,124,125,5,8,0,0,125,126,5,41,0,0,126,129,3,26,13,0,127,128,5,
  	9,0,0,128,130,5,41,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,134,1,0,0,
  	0,131,133,5,3,0,0,132,131,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,
  	135,1,0,0,0,135,137,1,0,0,0,136,134,1,0,0,0,137,138,3,48,24,0,138,15,
  	1,0,0,0,139,140,7,1,0,0,140,17,1,0,0,0,141,143,3,16,8,0,142,141,1,0,0,
  	0,142,143,1,0,0,0,143,19,1,0,0,0,144,146,3,16,8,0,145,144,1,0,0,0,145,
  	146,1,0,0,0,146,21,1,0,0,0,147,148,3,24,12,0,148,149,5,41,0,0,149,150,
  	5,41,0,0,150,23,1,0,0,0,151,152,7,2,0,0,152,25,1,0,0,0,153,155,5,17,0,
  	0,154,156,3,28,14,0,155,154,1,0,0,0,155,156,1,0,0,0,156,157,1,0,0,0,157,
  	158,5,18,0,0,158,27,1,0,0,0,159,164,3,30,15,0,160,161,5,19,0,0,161,163,
  	3,30,15,0,162,160,1,0,0,0,163,166,1,0,0,0,164,162,1,0,0,0,164,165,1,0,
  	0,0,165,29,1,0,0,0,166,164,1,0,0,0,167,170,3,22,11,0,168,169,5,20,0,0,
  	169,171,3,50,25,0,170,168,1,0,0,0,170,171,1,0,0,0,171,31,1,0,0,0,172,
  	173,5,21,0,0,173,177,5,41,0,0,174,176,5,3,0,0,175,174,1,0,0,0,176,179,
  	1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,
  	0,180,181,3,48,24,0,181,33,1,0,0,0,182,183,5,41,0,0,183,184,3,36,18,0,
  	184,35,1,0,0,0,185,187,5,17,0,0,186,188,3,38,19,0,187,186,1,0,0,0,187,
  	188,1,0,0,0,188,189,1,0,0,0,189,190,5,18,0,0,190,37,1,0,0,0,191,196,3,
  	40,20,0,192,193,5,19,0,0,193,195,3,40,20,0,194,192,1,0,0,0,195,198,1,
  	0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,39,1,0,0,0,198,196,1,0,0,0,
  	199,200,5,41,0,0,200,202,5,20,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,
  	203,1,0,0,0,203,204,3,50,25,0,204,41,1,0,0,0,205,206,3,20,10,0,206,207,
  	3,46,23,0,207,208,5,41,0,0,208,209,5,22,0,0,209,218,5,41,0,0,210,214,
  	5,20,0,0,211,213,5,3,0,0,212,211,1,0,0,0,213,216,1,0,0,0,214,212,1,0,
  	0,0,214,215,1,0,0,0,215,217,1,0,0,0,216,214,1,0,0,0,217,219,3,50,25,0,
  	218,210,1,0,0,0,218,219,1,0,0,0,219,43,1,0,0,0,220,221,3,20,10,0,221,
  	222,3,46,23,0,222,223,5,41,0,0,223,224,5,20,0,0,224,225,3,50,25,0,225,
  	45,1,0,0,0,226,227,7,3,0,0,227,47,1,0,0,0,228,232,5,25,0,0,229,231,3,
  	2,1,0,230,229,1,0,0,0,231,234,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,
  	233,235,1,0,0,0,234,232,1,0,0,0,235,236,5,26,0,0,236,49,1,0,0,0,237,238,
  	6,25,-1,0,238,250,3,34,17,0,239,250,3,42,21,0,240,250,3,44,22,0,241,242,
  	5,17,0,0,242,243,3,50,25,0,243,244,5,18,0,0,244,250,1,0,0,0,245,250,3,
  	48,24,0,246,250,5,39,0,0,247,250,5,40,0,0,248,250,5,41,0,0,249,237,1,
  	0,0,0,249,239,1,0,0,0,249,240,1,0,0,0,249,241,1,0,0,0,249,245,1,0,0,0,
  	249,246,1,0,0,0,249,247,1,0,0,0,249,248,1,0,0,0,250,286,1,0,0,0,251,252,
  	10,17,0,0,252,253,5,31,0,0,253,285,3,50,25,18,254,255,10,16,0,0,255,256,
  	5,32,0,0,256,285,3,50,25,17,257,258,10,15,0,0,258,259,5,33,0,0,259,285,
  	3,50,25,16,260,261,10,14,0,0,261,262,5,29,0,0,262,285,3,50,25,15,263,
  	264,10,13,0,0,264,265,5,30,0,0,265,285,3,50,25,14,266,267,10,12,0,0,267,
  	268,5,35,0,0,268,285,3,50,25,13,269,270,10,11,0,0,270,271,5,36,0,0,271,
  	285,3,50,25,12,272,273,10,10,0,0,273,274,5,37,0,0,274,285,3,50,25,11,
  	275,276,10,9,0,0,276,277,5,38,0,0,277,285,3,50,25,10,278,279,10,19,0,
  	0,279,280,5,27,0,0,280,285,5,41,0,0,281,282,10,18,0,0,282,283,5,28,0,
  	0,283,285,5,41,0,0,284,251,1,0,0,0,284,254,1,0,0,0,284,257,1,0,0,0,284,
  	260,1,0,0,0,284,263,1,0,0,0,284,266,1,0,0,0,284,269,1,0,0,0,284,272,1,
  	0,0,0,284,275,1,0,0,0,284,278,1,0,0,0,284,281,1,0,0,0,285,288,1,0,0,0,
  	286,284,1,0,0,0,286,287,1,0,0,0,287,51,1,0,0,0,288,286,1,0,0,0,26,55,
  	73,79,83,90,97,105,112,121,129,134,142,145,155,164,170,177,187,196,201,
  	214,218,232,249,284,286
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
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848351661518) != 0) {
      setState(52);
      stmt();
      setState(57);
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
  enterRule(_localctx, 2, FscParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(58);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(59);
      expr(0);
      setState(60);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(62);
      class_();
      setState(63);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(65);
      match(FscParser::T__0);
      setState(66);
      expr(0);
      setState(67);
      stmt_end();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(69);
      if_stmt();
      setState(70);
      stmt_end();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(72);
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

//----------------- If_stmtContext ------------------------------------------------------------------

FscParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::IfContext* FscParser::If_stmtContext::if_() {
  return getRuleContext<FscParser::IfContext>(0);
}

std::vector<FscParser::ElifContext *> FscParser::If_stmtContext::elif() {
  return getRuleContexts<FscParser::ElifContext>();
}

FscParser::ElifContext* FscParser::If_stmtContext::elif(size_t i) {
  return getRuleContext<FscParser::ElifContext>(i);
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
  enterRule(_localctx, 4, FscParser::RuleIf_stmt);
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
    setState(75);
    if_();
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__3) {
      setState(76);
      elif();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(83);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__4) {
      setState(82);
      else_();
    }
   
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
  enterRule(_localctx, 6, FscParser::RuleIf);
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
    setState(85);
    match(FscParser::T__1);
    setState(86);
    expr(0);

    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__2) {
      setState(87);
      match(FscParser::T__2);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    body();

    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(94);
        match(FscParser::T__2); 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
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

FscParser::ExprContext* FscParser::ElifContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::BodyContext* FscParser::ElifContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
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
  enterRule(_localctx, 8, FscParser::RuleElif);
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
    setState(100);
    match(FscParser::T__3);
    setState(101);
    expr(0);

    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__2) {
      setState(102);
      match(FscParser::T__2);
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(108);
    body();

    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(109);
        match(FscParser::T__2); 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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

FscParser::BodyContext* FscParser::ElseContext::body() {
  return getRuleContext<FscParser::BodyContext>(0);
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
  enterRule(_localctx, 10, FscParser::RuleElse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(FscParser::T__4);
    setState(116);
    body();
   
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
  enterRule(_localctx, 12, FscParser::RuleStmt_end);
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
    setState(119); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(118);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 200) != 0)) {
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
      setState(121); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

std::vector<tree::TerminalNode *> FscParser::FunctionContext::NAME() {
  return getTokens(FscParser::NAME);
}

tree::TerminalNode* FscParser::FunctionContext::NAME(size_t i) {
  return getToken(FscParser::NAME, i);
}

FscParser::ParametersContext* FscParser::FunctionContext::parameters() {
  return getRuleContext<FscParser::ParametersContext>(0);
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
  enterRule(_localctx, 14, FscParser::RuleFunction);
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
    setState(123);
    function_attibutes();
    setState(124);
    match(FscParser::T__7);
    setState(125);
    match(FscParser::NAME);
    setState(126);
    parameters();
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__8) {
      setState(127);
      match(FscParser::T__8);
      setState(128);
      match(FscParser::NAME);
    }

    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__2) {
      setState(131);
      match(FscParser::T__2);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
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
  enterRule(_localctx, 16, FscParser::RuleVisibility);
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
    setState(139);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15360) != 0)) {
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
  enterRule(_localctx, 18, FscParser::RuleFunction_attibutes);
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
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15360) != 0) {
      setState(141);
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
  enterRule(_localctx, 20, FscParser::RuleVariable_attributes);
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
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15360) != 0) {
      setState(144);
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

//----------------- Argument_definitionContext ------------------------------------------------------------------

FscParser::Argument_definitionContext::Argument_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::Argument_passing_typeContext* FscParser::Argument_definitionContext::argument_passing_type() {
  return getRuleContext<FscParser::Argument_passing_typeContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::Argument_definitionContext::NAME() {
  return getTokens(FscParser::NAME);
}

tree::TerminalNode* FscParser::Argument_definitionContext::NAME(size_t i) {
  return getToken(FscParser::NAME, i);
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
  enterRule(_localctx, 22, FscParser::RuleArgument_definition);

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
    argument_passing_type();
    setState(148);
    match(FscParser::NAME);
    setState(149);
    match(FscParser::NAME);
   
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
  enterRule(_localctx, 24, FscParser::RuleArgument_passing_type);
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
    setState(151);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
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
  enterRule(_localctx, 26, FscParser::RuleParameters);
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
    setState(153);
    match(FscParser::T__16);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0) {
      setState(154);
      typed_arguments_list();
    }
    setState(157);
    match(FscParser::T__17);
   
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
  enterRule(_localctx, 28, FscParser::RuleTyped_arguments_list);
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
    setState(159);
    argument();
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__18) {
      setState(160);
      match(FscParser::T__18);
      setState(161);
      argument();
      setState(166);
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
  enterRule(_localctx, 30, FscParser::RuleArgument);
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
    setState(167);
    argument_definition();
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__19) {
      setState(168);
      match(FscParser::T__19);
      setState(169);
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

//----------------- ClassContext ------------------------------------------------------------------

FscParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FscParser::ClassContext::NAME() {
  return getToken(FscParser::NAME, 0);
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
  enterRule(_localctx, 32, FscParser::RuleClass);
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
    match(FscParser::T__20);
    setState(173);
    match(FscParser::NAME);
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__2) {
      setState(174);
      match(FscParser::T__2);
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(180);
    body();
   
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

tree::TerminalNode* FscParser::Function_callContext::NAME() {
  return getToken(FscParser::NAME, 0);
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
  enterRule(_localctx, 34, FscParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(FscParser::NAME);
    setState(183);
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
  enterRule(_localctx, 36, FscParser::RuleFunction_parameter);
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
    setState(185);
    match(FscParser::T__16);
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848349563904) != 0) {
      setState(186);
      function_typed_arguments_list();
    }
    setState(189);
    match(FscParser::T__17);
   
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
  enterRule(_localctx, 38, FscParser::RuleFunction_typed_arguments_list);
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
    setState(191);
    function_argument();
    setState(196);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__18) {
      setState(192);
      match(FscParser::T__18);
      setState(193);
      function_argument();
      setState(198);
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

tree::TerminalNode* FscParser::Function_argumentContext::NAME() {
  return getToken(FscParser::NAME, 0);
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
  enterRule(_localctx, 40, FscParser::RuleFunction_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(199);
      match(FscParser::NAME);
      setState(200);
      match(FscParser::T__19);
      break;
    }

    default:
      break;
    }
    setState(203);
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

std::vector<tree::TerminalNode *> FscParser::Variable_definitionContext::NAME() {
  return getTokens(FscParser::NAME);
}

tree::TerminalNode* FscParser::Variable_definitionContext::NAME(size_t i) {
  return getToken(FscParser::NAME, i);
}

FscParser::ExprContext* FscParser::Variable_definitionContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
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
  enterRule(_localctx, 42, FscParser::RuleVariable_definition);
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
    setState(205);
    variable_attributes();
    setState(206);
    variable_prefix();
    setState(207);
    match(FscParser::NAME);
    setState(208);
    match(FscParser::T__21);
    setState(209);
    match(FscParser::NAME);
    setState(218);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(210);
      match(FscParser::T__19);
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FscParser::T__2) {
        setState(211);
        match(FscParser::T__2);
        setState(216);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(217);
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

tree::TerminalNode* FscParser::Auto_variable_definitionContext::NAME() {
  return getToken(FscParser::NAME, 0);
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
  enterRule(_localctx, 44, FscParser::RuleAuto_variable_definition);

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
    variable_attributes();
    setState(221);
    variable_prefix();
    setState(222);
    match(FscParser::NAME);
    setState(223);
    match(FscParser::T__19);
    setState(224);
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
  enterRule(_localctx, 46, FscParser::RuleVariable_prefix);
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
    setState(226);
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
  enterRule(_localctx, 48, FscParser::RuleBody);
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
    setState(228);
    match(FscParser::T__24);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848351661518) != 0) {
      setState(229);
      stmt();
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    match(FscParser::T__25);
   
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

tree::TerminalNode* FscParser::ExprContext::NAME() {
  return getToken(FscParser::NAME, 0);
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
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, FscParser::RuleExpr, precedence);

    

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
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(238);
      function_call();
      break;
    }

    case 2: {
      setState(239);
      variable_definition();
      break;
    }

    case 3: {
      setState(240);
      auto_variable_definition();
      break;
    }

    case 4: {
      setState(241);
      match(FscParser::T__16);
      setState(242);
      expr(0);
      setState(243);
      match(FscParser::T__17);
      break;
    }

    case 5: {
      setState(245);
      body();
      break;
    }

    case 6: {
      setState(246);
      match(FscParser::INT);
      break;
    }

    case 7: {
      setState(247);
      match(FscParser::FLOAT);
      break;
    }

    case 8: {
      setState(248);
      match(FscParser::NAME);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(286);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(284);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(251);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(252);
          match(FscParser::MUL);
          setState(253);
          expr(18);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(254);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(255);
          match(FscParser::DIV);
          setState(256);
          expr(17);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(257);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(258);
          match(FscParser::MOD);
          setState(259);
          expr(16);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(260);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(261);
          match(FscParser::ADD);
          setState(262);
          expr(15);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(263);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(264);
          match(FscParser::SUB);
          setState(265);
          expr(14);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(266);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(267);
          match(FscParser::EQUALITY);
          setState(268);
          expr(13);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(269);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(270);
          match(FscParser::INEQUALITY);
          setState(271);
          expr(12);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(272);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(273);
          match(FscParser::LOGICAL_AND);
          setState(274);
          expr(11);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(275);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(276);
          match(FscParser::LOGICAL_OR);
          setState(277);
          expr(10);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(278);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(279);
          match(FscParser::T__26);
          setState(280);
          match(FscParser::NAME);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(281);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(282);
          match(FscParser::AS);
          setState(283);
          match(FscParser::NAME);
          break;
        }

        default:
          break;
        } 
      }
      setState(288);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
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
    case 25: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);
    case 6: return precpred(_ctx, 11);
    case 7: return precpred(_ctx, 10);
    case 8: return precpred(_ctx, 9);
    case 9: return precpred(_ctx, 19);
    case 10: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
