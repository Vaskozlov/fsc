
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
      "program", "stmt", "if_stmt", "if", "elif", "else", "elif_def", "else_def", 
      "new_line", "stmt_end", "function", "visibility", "function_attibutes", 
      "variable_attributes", "argument_definition", "argument_passing_type", 
      "parameters", "typed_arguments_list", "argument", "class", "function_call", 
      "function_parameter", "function_typed_arguments_list", "function_argument", 
      "variable_definition", "auto_variable_definition", "variable_prefix", 
      "body", "expr"
    },
    std::vector<std::string>{
      "", "'return'", "'if'", "'elif'", "'else'", "'\\n'", "'\\r'", "';'", 
      "'func'", "'->'", "'public'", "'private'", "'protected'", "'fileprivae'", 
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
  	4,1,44,279,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,80,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,4,5,4,93,8,4,10,4,12,4,96,9,4,1,5,3,5,99,8,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,8,5,8,111,8,8,10,8,12,8,114,9,8,1,9,4,9,117,8,
  	9,11,9,12,9,118,1,10,1,10,1,10,1,10,1,10,1,10,3,10,127,8,10,1,10,1,10,
  	1,10,1,11,1,11,1,12,3,12,135,8,12,1,13,3,13,138,8,13,1,14,1,14,1,14,1,
  	14,1,15,1,15,1,16,1,16,3,16,148,8,16,1,16,1,16,1,17,1,17,1,17,5,17,155,
  	8,17,10,17,12,17,158,9,17,1,18,1,18,1,18,3,18,163,8,18,1,19,1,19,1,19,
  	1,19,1,19,1,20,1,20,1,20,1,21,1,21,3,21,175,8,21,1,21,1,21,1,22,1,22,
  	1,22,5,22,182,8,22,10,22,12,22,185,9,22,1,23,1,23,3,23,189,8,23,1,23,
  	1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,200,8,24,10,24,12,24,203,
  	9,24,1,24,3,24,206,8,24,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,27,
  	1,27,5,27,218,8,27,10,27,12,27,221,9,27,1,27,1,27,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,239,8,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,5,28,274,8,28,10,28,12,28,277,9,28,1,28,0,1,56,29,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,56,0,4,1,0,5,7,1,0,10,13,1,0,14,16,1,0,23,24,291,0,61,1,0,0,
  	0,2,79,1,0,0,0,4,81,1,0,0,0,6,85,1,0,0,0,8,94,1,0,0,0,10,98,1,0,0,0,12,
  	100,1,0,0,0,14,106,1,0,0,0,16,112,1,0,0,0,18,116,1,0,0,0,20,120,1,0,0,
  	0,22,131,1,0,0,0,24,134,1,0,0,0,26,137,1,0,0,0,28,139,1,0,0,0,30,143,
  	1,0,0,0,32,145,1,0,0,0,34,151,1,0,0,0,36,159,1,0,0,0,38,164,1,0,0,0,40,
  	169,1,0,0,0,42,172,1,0,0,0,44,178,1,0,0,0,46,188,1,0,0,0,48,192,1,0,0,
  	0,50,207,1,0,0,0,52,213,1,0,0,0,54,215,1,0,0,0,56,238,1,0,0,0,58,60,3,
  	2,1,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,1,1,
  	0,0,0,63,61,1,0,0,0,64,80,3,20,10,0,65,66,3,56,28,0,66,67,3,18,9,0,67,
  	80,1,0,0,0,68,69,3,38,19,0,69,70,3,18,9,0,70,80,1,0,0,0,71,72,5,1,0,0,
  	72,73,3,56,28,0,73,74,3,18,9,0,74,80,1,0,0,0,75,76,3,4,2,0,76,77,3,18,
  	9,0,77,80,1,0,0,0,78,80,3,18,9,0,79,64,1,0,0,0,79,65,1,0,0,0,79,68,1,
  	0,0,0,79,71,1,0,0,0,79,75,1,0,0,0,79,78,1,0,0,0,80,3,1,0,0,0,81,82,3,
  	6,3,0,82,83,3,8,4,0,83,84,3,10,5,0,84,5,1,0,0,0,85,86,5,2,0,0,86,87,3,
  	56,28,0,87,88,3,16,8,0,88,89,3,54,27,0,89,90,3,16,8,0,90,7,1,0,0,0,91,
  	93,3,12,6,0,92,91,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,
  	9,1,0,0,0,96,94,1,0,0,0,97,99,3,14,7,0,98,97,1,0,0,0,98,99,1,0,0,0,99,
  	11,1,0,0,0,100,101,5,3,0,0,101,102,3,56,28,0,102,103,3,16,8,0,103,104,
  	3,54,27,0,104,105,3,16,8,0,105,13,1,0,0,0,106,107,5,4,0,0,107,108,3,54,
  	27,0,108,15,1,0,0,0,109,111,5,5,0,0,110,109,1,0,0,0,111,114,1,0,0,0,112,
  	110,1,0,0,0,112,113,1,0,0,0,113,17,1,0,0,0,114,112,1,0,0,0,115,117,7,
  	0,0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,
  	119,19,1,0,0,0,120,121,3,24,12,0,121,122,5,8,0,0,122,123,5,43,0,0,123,
  	126,3,32,16,0,124,125,5,9,0,0,125,127,5,43,0,0,126,124,1,0,0,0,126,127,
  	1,0,0,0,127,128,1,0,0,0,128,129,3,16,8,0,129,130,3,54,27,0,130,21,1,0,
  	0,0,131,132,7,1,0,0,132,23,1,0,0,0,133,135,3,22,11,0,134,133,1,0,0,0,
  	134,135,1,0,0,0,135,25,1,0,0,0,136,138,3,22,11,0,137,136,1,0,0,0,137,
  	138,1,0,0,0,138,27,1,0,0,0,139,140,3,30,15,0,140,141,5,43,0,0,141,142,
  	5,43,0,0,142,29,1,0,0,0,143,144,7,2,0,0,144,31,1,0,0,0,145,147,5,17,0,
  	0,146,148,3,34,17,0,147,146,1,0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,
  	150,5,18,0,0,150,33,1,0,0,0,151,156,3,36,18,0,152,153,5,19,0,0,153,155,
  	3,36,18,0,154,152,1,0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,
  	0,0,157,35,1,0,0,0,158,156,1,0,0,0,159,162,3,28,14,0,160,161,5,20,0,0,
  	161,163,3,56,28,0,162,160,1,0,0,0,162,163,1,0,0,0,163,37,1,0,0,0,164,
  	165,5,21,0,0,165,166,5,43,0,0,166,167,3,16,8,0,167,168,3,54,27,0,168,
  	39,1,0,0,0,169,170,5,43,0,0,170,171,3,42,21,0,171,41,1,0,0,0,172,174,
  	5,17,0,0,173,175,3,44,22,0,174,173,1,0,0,0,174,175,1,0,0,0,175,176,1,
  	0,0,0,176,177,5,18,0,0,177,43,1,0,0,0,178,183,3,46,23,0,179,180,5,19,
  	0,0,180,182,3,46,23,0,181,179,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,
  	183,184,1,0,0,0,184,45,1,0,0,0,185,183,1,0,0,0,186,187,5,43,0,0,187,189,
  	5,20,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,191,3,56,
  	28,0,191,47,1,0,0,0,192,193,3,26,13,0,193,194,3,52,26,0,194,195,5,43,
  	0,0,195,196,5,22,0,0,196,205,5,43,0,0,197,201,5,20,0,0,198,200,5,5,0,
  	0,199,198,1,0,0,0,200,203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,
  	204,1,0,0,0,203,201,1,0,0,0,204,206,3,56,28,0,205,197,1,0,0,0,205,206,
  	1,0,0,0,206,49,1,0,0,0,207,208,3,26,13,0,208,209,3,52,26,0,209,210,5,
  	43,0,0,210,211,5,20,0,0,211,212,3,56,28,0,212,51,1,0,0,0,213,214,7,3,
  	0,0,214,53,1,0,0,0,215,219,5,25,0,0,216,218,3,2,1,0,217,216,1,0,0,0,218,
  	221,1,0,0,0,219,217,1,0,0,0,219,220,1,0,0,0,220,222,1,0,0,0,221,219,1,
  	0,0,0,222,223,5,26,0,0,223,55,1,0,0,0,224,225,6,28,-1,0,225,239,3,40,
  	20,0,226,239,3,48,24,0,227,239,3,50,25,0,228,229,5,17,0,0,229,230,3,56,
  	28,0,230,231,5,18,0,0,231,239,1,0,0,0,232,239,3,54,27,0,233,239,5,39,
  	0,0,234,239,5,40,0,0,235,239,5,43,0,0,236,239,5,42,0,0,237,239,5,41,0,
  	0,238,224,1,0,0,0,238,226,1,0,0,0,238,227,1,0,0,0,238,228,1,0,0,0,238,
  	232,1,0,0,0,238,233,1,0,0,0,238,234,1,0,0,0,238,235,1,0,0,0,238,236,1,
  	0,0,0,238,237,1,0,0,0,239,275,1,0,0,0,240,241,10,19,0,0,241,242,5,31,
  	0,0,242,274,3,56,28,20,243,244,10,18,0,0,244,245,5,32,0,0,245,274,3,56,
  	28,19,246,247,10,17,0,0,247,248,5,33,0,0,248,274,3,56,28,18,249,250,10,
  	16,0,0,250,251,5,29,0,0,251,274,3,56,28,17,252,253,10,15,0,0,253,254,
  	5,30,0,0,254,274,3,56,28,16,255,256,10,14,0,0,256,257,5,35,0,0,257,274,
  	3,56,28,15,258,259,10,13,0,0,259,260,5,36,0,0,260,274,3,56,28,14,261,
  	262,10,12,0,0,262,263,5,37,0,0,263,274,3,56,28,13,264,265,10,11,0,0,265,
  	266,5,38,0,0,266,274,3,56,28,12,267,268,10,21,0,0,268,269,5,27,0,0,269,
  	274,5,43,0,0,270,271,10,20,0,0,271,272,5,28,0,0,272,274,5,43,0,0,273,
  	240,1,0,0,0,273,243,1,0,0,0,273,246,1,0,0,0,273,249,1,0,0,0,273,252,1,
  	0,0,0,273,255,1,0,0,0,273,258,1,0,0,0,273,261,1,0,0,0,273,264,1,0,0,0,
  	273,267,1,0,0,0,273,270,1,0,0,0,274,277,1,0,0,0,275,273,1,0,0,0,275,276,
  	1,0,0,0,276,57,1,0,0,0,277,275,1,0,0,0,21,61,79,94,98,112,118,126,134,
  	137,147,156,162,174,183,188,201,205,219,238,273,275
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
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17042491194854) != 0) {
      setState(58);
      stmt();
      setState(63);
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
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(65);
      expr(0);
      setState(66);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(68);
      class_();
      setState(69);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(71);
      match(FscParser::T__0);
      setState(72);
      expr(0);
      setState(73);
      stmt_end();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(75);
      if_stmt();
      setState(76);
      stmt_end();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(78);
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
  enterRule(_localctx, 4, FscParser::RuleIf_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    if_();
    setState(82);
    elif();
    setState(83);
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
  enterRule(_localctx, 6, FscParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(FscParser::T__1);
    setState(86);
    expr(0);
    setState(87);
    new_line();
    setState(88);
    body();
    setState(89);
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
    enterOuterAlt(_localctx, 1);
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__2) {
      setState(91);
      elif_def();
      setState(96);
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
  enterRule(_localctx, 10, FscParser::RuleElse);
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
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__3) {
      setState(97);
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
  enterRule(_localctx, 12, FscParser::RuleElif_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(FscParser::T__2);
    setState(101);
    expr(0);
    setState(102);
    new_line();
    setState(103);
    body();
    setState(104);
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
  enterRule(_localctx, 14, FscParser::RuleElse_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(FscParser::T__3);
    setState(107);
    body();
   
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
  enterRule(_localctx, 16, FscParser::RuleNew_line);

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
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(109);
        match(FscParser::T__4); 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  enterRule(_localctx, 18, FscParser::RuleStmt_end);
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
    setState(116); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(115);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 224) != 0)) {
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
      setState(118); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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
  enterRule(_localctx, 20, FscParser::RuleFunction);
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
    setState(120);
    function_attibutes();
    setState(121);
    match(FscParser::T__7);
    setState(122);
    match(FscParser::NAME);
    setState(123);
    parameters();
    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__8) {
      setState(124);
      match(FscParser::T__8);
      setState(125);
      match(FscParser::NAME);
    }
    setState(128);
    new_line();
    setState(129);
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
  enterRule(_localctx, 22, FscParser::RuleVisibility);
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
    setState(131);
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
  enterRule(_localctx, 24, FscParser::RuleFunction_attibutes);
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
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15360) != 0) {
      setState(133);
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
  enterRule(_localctx, 26, FscParser::RuleVariable_attributes);
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
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15360) != 0) {
      setState(136);
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
  enterRule(_localctx, 28, FscParser::RuleArgument_definition);

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
    argument_passing_type();
    setState(140);
    match(FscParser::NAME);
    setState(141);
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
  enterRule(_localctx, 30, FscParser::RuleArgument_passing_type);
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
    setState(143);
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
  enterRule(_localctx, 32, FscParser::RuleParameters);
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
    match(FscParser::T__16);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0) {
      setState(146);
      typed_arguments_list();
    }
    setState(149);
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
  enterRule(_localctx, 34, FscParser::RuleTyped_arguments_list);
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
    argument();
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__18) {
      setState(152);
      match(FscParser::T__18);
      setState(153);
      argument();
      setState(158);
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
  enterRule(_localctx, 36, FscParser::RuleArgument);
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
    argument_definition();
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__19) {
      setState(160);
      match(FscParser::T__19);
      setState(161);
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
  enterRule(_localctx, 38, FscParser::RuleClass);

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
    match(FscParser::T__20);
    setState(165);
    match(FscParser::NAME);
    setState(166);
    new_line();
    setState(167);
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
  enterRule(_localctx, 40, FscParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(FscParser::NAME);
    setState(170);
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
  enterRule(_localctx, 42, FscParser::RuleFunction_parameter);
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
    match(FscParser::T__16);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17042489097216) != 0) {
      setState(173);
      function_typed_arguments_list();
    }
    setState(176);
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
  enterRule(_localctx, 44, FscParser::RuleFunction_typed_arguments_list);
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
    function_argument();
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__18) {
      setState(179);
      match(FscParser::T__18);
      setState(180);
      function_argument();
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
  enterRule(_localctx, 46, FscParser::RuleFunction_argument);

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
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(186);
      match(FscParser::NAME);
      setState(187);
      match(FscParser::T__19);
      break;
    }

    default:
      break;
    }
    setState(190);
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
  enterRule(_localctx, 48, FscParser::RuleVariable_definition);
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
    variable_attributes();
    setState(193);
    variable_prefix();
    setState(194);
    match(FscParser::NAME);
    setState(195);
    match(FscParser::T__21);
    setState(196);
    match(FscParser::NAME);
    setState(205);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(197);
      match(FscParser::T__19);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FscParser::T__4) {
        setState(198);
        match(FscParser::T__4);
        setState(203);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(204);
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
  enterRule(_localctx, 50, FscParser::RuleAuto_variable_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    variable_attributes();
    setState(208);
    variable_prefix();
    setState(209);
    match(FscParser::NAME);
    setState(210);
    match(FscParser::T__19);
    setState(211);
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
  enterRule(_localctx, 52, FscParser::RuleVariable_prefix);
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
    setState(213);
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
  enterRule(_localctx, 54, FscParser::RuleBody);
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
    setState(215);
    match(FscParser::T__24);
    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17042491194854) != 0) {
      setState(216);
      stmt();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
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

tree::TerminalNode* FscParser::ExprContext::STRING() {
  return getToken(FscParser::STRING, 0);
}

tree::TerminalNode* FscParser::ExprContext::CHAR() {
  return getToken(FscParser::CHAR, 0);
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
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, FscParser::RuleExpr, precedence);

    

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
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(225);
      function_call();
      break;
    }

    case 2: {
      setState(226);
      variable_definition();
      break;
    }

    case 3: {
      setState(227);
      auto_variable_definition();
      break;
    }

    case 4: {
      setState(228);
      match(FscParser::T__16);
      setState(229);
      expr(0);
      setState(230);
      match(FscParser::T__17);
      break;
    }

    case 5: {
      setState(232);
      body();
      break;
    }

    case 6: {
      setState(233);
      match(FscParser::INT);
      break;
    }

    case 7: {
      setState(234);
      match(FscParser::FLOAT);
      break;
    }

    case 8: {
      setState(235);
      match(FscParser::NAME);
      break;
    }

    case 9: {
      setState(236);
      match(FscParser::STRING);
      break;
    }

    case 10: {
      setState(237);
      match(FscParser::CHAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(275);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(273);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(240);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(241);
          match(FscParser::MUL);
          setState(242);
          expr(20);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(243);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(244);
          match(FscParser::DIV);
          setState(245);
          expr(19);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(246);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(247);
          match(FscParser::MOD);
          setState(248);
          expr(18);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(249);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(250);
          match(FscParser::ADD);
          setState(251);
          expr(17);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(252);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(253);
          match(FscParser::SUB);
          setState(254);
          expr(16);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(255);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(256);
          match(FscParser::EQUALITY);
          setState(257);
          expr(15);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(258);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(259);
          match(FscParser::INEQUALITY);
          setState(260);
          expr(14);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(261);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(262);
          match(FscParser::LOGICAL_AND);
          setState(263);
          expr(13);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(264);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(265);
          match(FscParser::LOGICAL_OR);
          setState(266);
          expr(12);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(267);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(268);
          match(FscParser::T__26);
          setState(269);
          match(FscParser::NAME);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(270);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(271);
          match(FscParser::AS);
          setState(272);
          match(FscParser::NAME);
          break;
        }

        default:
          break;
        } 
      }
      setState(277);
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

bool FscParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 28: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 19);
    case 1: return precpred(_ctx, 18);
    case 2: return precpred(_ctx, 17);
    case 3: return precpred(_ctx, 16);
    case 4: return precpred(_ctx, 15);
    case 5: return precpred(_ctx, 14);
    case 6: return precpred(_ctx, 13);
    case 7: return precpred(_ctx, 12);
    case 8: return precpred(_ctx, 11);
    case 9: return precpred(_ctx, 21);
    case 10: return precpred(_ctx, 20);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
