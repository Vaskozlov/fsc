
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
      "program", "global_stmt", "stmt", "stmt_end", "function", "argument_definition", 
      "argument_passing_type", "parameters", "typed_arguments_list", "function_call", 
      "function_parameter", "function_typed_arguments_list", "variable_definition", 
      "auto_variable_definition", "body", "expr"
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
  	4,1,29,191,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,5,0,34,8,0,10,0,12,0,37,9,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,3,1,47,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,3,2,63,8,2,1,3,4,3,66,8,3,11,3,12,3,67,1,4,1,4,1,4,1,4,1,4,3,4,
  	75,8,4,1,4,5,4,78,8,4,10,4,12,4,81,9,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,
  	6,1,6,1,7,1,7,3,7,94,8,7,1,7,1,7,1,8,1,8,1,8,3,8,101,8,8,1,8,1,8,1,8,
  	1,8,3,8,107,8,8,5,8,109,8,8,10,8,12,8,112,9,8,1,9,1,9,1,9,1,10,1,10,3,
  	10,119,8,10,1,10,1,10,1,11,1,11,3,11,125,8,11,1,11,1,11,1,11,1,11,3,11,
  	131,8,11,1,11,5,11,134,8,11,10,11,12,11,137,9,11,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,5,14,153,8,14,10,14,
  	12,14,156,9,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,169,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,5,15,186,8,15,10,15,12,15,189,9,15,1,15,0,1,30,16,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,0,2,1,0,1,3,1,0,6,8,203,0,
  	35,1,0,0,0,2,46,1,0,0,0,4,62,1,0,0,0,6,65,1,0,0,0,8,69,1,0,0,0,10,84,
  	1,0,0,0,12,89,1,0,0,0,14,91,1,0,0,0,16,97,1,0,0,0,18,113,1,0,0,0,20,116,
  	1,0,0,0,22,124,1,0,0,0,24,138,1,0,0,0,26,145,1,0,0,0,28,150,1,0,0,0,30,
  	168,1,0,0,0,32,34,3,2,1,0,33,32,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,35,
  	36,1,0,0,0,36,1,1,0,0,0,37,35,1,0,0,0,38,47,3,8,4,0,39,40,3,24,12,0,40,
  	41,3,6,3,0,41,47,1,0,0,0,42,43,3,26,13,0,43,44,3,6,3,0,44,47,1,0,0,0,
  	45,47,3,6,3,0,46,38,1,0,0,0,46,39,1,0,0,0,46,42,1,0,0,0,46,45,1,0,0,0,
  	47,3,1,0,0,0,48,49,3,30,15,0,49,50,3,6,3,0,50,63,1,0,0,0,51,52,5,25,0,
  	0,52,53,3,30,15,0,53,54,3,6,3,0,54,63,1,0,0,0,55,56,3,24,12,0,56,57,3,
  	6,3,0,57,63,1,0,0,0,58,59,3,26,13,0,59,60,3,6,3,0,60,63,1,0,0,0,61,63,
  	3,6,3,0,62,48,1,0,0,0,62,51,1,0,0,0,62,55,1,0,0,0,62,58,1,0,0,0,62,61,
  	1,0,0,0,63,5,1,0,0,0,64,66,7,0,0,0,65,64,1,0,0,0,66,67,1,0,0,0,67,65,
  	1,0,0,0,67,68,1,0,0,0,68,7,1,0,0,0,69,70,5,24,0,0,70,71,5,28,0,0,71,74,
  	3,14,7,0,72,73,5,4,0,0,73,75,5,28,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,
  	79,1,0,0,0,76,78,5,1,0,0,77,76,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,
  	80,1,0,0,0,80,82,1,0,0,0,81,79,1,0,0,0,82,83,3,28,14,0,83,9,1,0,0,0,84,
  	85,5,28,0,0,85,86,5,5,0,0,86,87,3,12,6,0,87,88,5,28,0,0,88,11,1,0,0,0,
  	89,90,7,1,0,0,90,13,1,0,0,0,91,93,5,9,0,0,92,94,3,16,8,0,93,92,1,0,0,
  	0,93,94,1,0,0,0,94,95,1,0,0,0,95,96,5,10,0,0,96,15,1,0,0,0,97,100,3,10,
  	5,0,98,99,5,11,0,0,99,101,3,30,15,0,100,98,1,0,0,0,100,101,1,0,0,0,101,
  	110,1,0,0,0,102,103,5,12,0,0,103,106,3,10,5,0,104,105,5,11,0,0,105,107,
  	3,30,15,0,106,104,1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,102,1,0,
  	0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,17,1,0,0,0,112,
  	110,1,0,0,0,113,114,5,28,0,0,114,115,3,20,10,0,115,19,1,0,0,0,116,118,
  	5,9,0,0,117,119,3,22,11,0,118,117,1,0,0,0,118,119,1,0,0,0,119,120,1,0,
  	0,0,120,121,5,10,0,0,121,21,1,0,0,0,122,123,5,28,0,0,123,125,5,11,0,0,
  	124,122,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,135,3,30,15,0,127,
  	130,5,12,0,0,128,129,5,28,0,0,129,131,5,11,0,0,130,128,1,0,0,0,130,131,
  	1,0,0,0,131,132,1,0,0,0,132,134,3,30,15,0,133,127,1,0,0,0,134,137,1,0,
  	0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,23,1,0,0,0,137,135,1,0,0,0,138,
  	139,5,13,0,0,139,140,5,28,0,0,140,141,5,5,0,0,141,142,5,28,0,0,142,143,
  	5,11,0,0,143,144,3,30,15,0,144,25,1,0,0,0,145,146,5,13,0,0,146,147,5,
  	28,0,0,147,148,5,11,0,0,148,149,3,30,15,0,149,27,1,0,0,0,150,154,5,14,
  	0,0,151,153,3,4,2,0,152,151,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,
  	155,1,0,0,0,155,157,1,0,0,0,156,154,1,0,0,0,157,158,5,15,0,0,158,29,1,
  	0,0,0,159,160,6,15,-1,0,160,169,3,18,9,0,161,162,5,9,0,0,162,163,3,30,
  	15,0,163,164,5,10,0,0,164,169,1,0,0,0,165,169,5,26,0,0,166,169,5,27,0,
  	0,167,169,5,28,0,0,168,159,1,0,0,0,168,161,1,0,0,0,168,165,1,0,0,0,168,
  	166,1,0,0,0,168,167,1,0,0,0,169,187,1,0,0,0,170,171,10,10,0,0,171,172,
  	5,18,0,0,172,186,3,30,15,11,173,174,10,9,0,0,174,175,5,19,0,0,175,186,
  	3,30,15,10,176,177,10,8,0,0,177,178,5,20,0,0,178,186,3,30,15,9,179,180,
  	10,7,0,0,180,181,5,16,0,0,181,186,3,30,15,8,182,183,10,6,0,0,183,184,
  	5,17,0,0,184,186,3,30,15,7,185,170,1,0,0,0,185,173,1,0,0,0,185,176,1,
  	0,0,0,185,179,1,0,0,0,185,182,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,
  	187,188,1,0,0,0,188,31,1,0,0,0,189,187,1,0,0,0,18,35,46,62,67,74,79,93,
  	100,106,110,118,124,130,135,154,168,185,187
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

std::vector<FscParser::Global_stmtContext *> FscParser::ProgramContext::global_stmt() {
  return getRuleContexts<FscParser::Global_stmtContext>();
}

FscParser::Global_stmtContext* FscParser::ProgramContext::global_stmt(size_t i) {
  return getRuleContext<FscParser::Global_stmtContext>(i);
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
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16785422) != 0) {
      setState(32);
      global_stmt();
      setState(37);
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

//----------------- Global_stmtContext ------------------------------------------------------------------

FscParser::Global_stmtContext::Global_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::FunctionContext* FscParser::Global_stmtContext::function() {
  return getRuleContext<FscParser::FunctionContext>(0);
}

FscParser::Variable_definitionContext* FscParser::Global_stmtContext::variable_definition() {
  return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Stmt_endContext* FscParser::Global_stmtContext::stmt_end() {
  return getRuleContext<FscParser::Stmt_endContext>(0);
}

FscParser::Auto_variable_definitionContext* FscParser::Global_stmtContext::auto_variable_definition() {
  return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
}


size_t FscParser::Global_stmtContext::getRuleIndex() const {
  return FscParser::RuleGlobal_stmt;
}


std::any FscParser::Global_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FscVisitor*>(visitor))
    return parserVisitor->visitGlobal_stmt(this);
  else
    return visitor->visitChildren(this);
}

FscParser::Global_stmtContext* FscParser::global_stmt() {
  Global_stmtContext *_localctx = _tracker.createInstance<Global_stmtContext>(_ctx, getState());
  enterRule(_localctx, 2, FscParser::RuleGlobal_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(38);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(39);
      variable_definition();
      setState(40);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(42);
      auto_variable_definition();
      setState(43);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(45);
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

//----------------- StmtContext ------------------------------------------------------------------

FscParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FscParser::ExprContext* FscParser::StmtContext::expr() {
  return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::Stmt_endContext* FscParser::StmtContext::stmt_end() {
  return getRuleContext<FscParser::Stmt_endContext>(0);
}

tree::TerminalNode* FscParser::StmtContext::RETURN() {
  return getToken(FscParser::RETURN, 0);
}

FscParser::Variable_definitionContext* FscParser::StmtContext::variable_definition() {
  return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Auto_variable_definitionContext* FscParser::StmtContext::auto_variable_definition() {
  return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
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
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      expr(0);
      setState(49);
      stmt_end();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      match(FscParser::RETURN);
      setState(52);
      expr(0);
      setState(53);
      stmt_end();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(55);
      variable_definition();
      setState(56);
      stmt_end();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(58);
      auto_variable_definition();
      setState(59);
      stmt_end();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(61);
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
  enterRule(_localctx, 6, FscParser::RuleStmt_end);
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
    setState(65); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(64);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 14) != 0)) {
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
      setState(67); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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

tree::TerminalNode* FscParser::FunctionContext::FUNC() {
  return getToken(FscParser::FUNC, 0);
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
  enterRule(_localctx, 8, FscParser::RuleFunction);
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
    match(FscParser::FUNC);
    setState(70);
    match(FscParser::NAME);
    setState(71);
    parameters();
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__3) {
      setState(72);
      match(FscParser::T__3);
      setState(73);
      match(FscParser::NAME);
    }

    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__0) {
      setState(76);
      match(FscParser::T__0);
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
    body();
   
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

std::vector<tree::TerminalNode *> FscParser::Argument_definitionContext::NAME() {
  return getTokens(FscParser::NAME);
}

tree::TerminalNode* FscParser::Argument_definitionContext::NAME(size_t i) {
  return getToken(FscParser::NAME, i);
}

FscParser::Argument_passing_typeContext* FscParser::Argument_definitionContext::argument_passing_type() {
  return getRuleContext<FscParser::Argument_passing_typeContext>(0);
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
  enterRule(_localctx, 10, FscParser::RuleArgument_definition);

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
    match(FscParser::NAME);
    setState(85);
    match(FscParser::T__4);
    setState(86);
    argument_passing_type();
    setState(87);
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
  enterRule(_localctx, 12, FscParser::RuleArgument_passing_type);
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
    setState(89);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 448) != 0)) {
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
  enterRule(_localctx, 14, FscParser::RuleParameters);
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
    setState(91);
    match(FscParser::T__8);
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::NAME) {
      setState(92);
      typed_arguments_list();
    }
    setState(95);
    match(FscParser::T__9);
   
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

std::vector<FscParser::Argument_definitionContext *> FscParser::Typed_arguments_listContext::argument_definition() {
  return getRuleContexts<FscParser::Argument_definitionContext>();
}

FscParser::Argument_definitionContext* FscParser::Typed_arguments_listContext::argument_definition(size_t i) {
  return getRuleContext<FscParser::Argument_definitionContext>(i);
}

std::vector<FscParser::ExprContext *> FscParser::Typed_arguments_listContext::expr() {
  return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext* FscParser::Typed_arguments_listContext::expr(size_t i) {
  return getRuleContext<FscParser::ExprContext>(i);
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
  enterRule(_localctx, 16, FscParser::RuleTyped_arguments_list);
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
    setState(97);
    argument_definition();
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__10) {
      setState(98);
      match(FscParser::T__10);
      setState(99);
      expr(0);
    }
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__11) {
      setState(102);
      match(FscParser::T__11);
      setState(103);
      argument_definition();
      setState(106);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FscParser::T__10) {
        setState(104);
        match(FscParser::T__10);
        setState(105);
        expr(0);
      }
      setState(112);
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
  enterRule(_localctx, 18, FscParser::RuleFunction_call);

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
    match(FscParser::NAME);
    setState(114);
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
  enterRule(_localctx, 20, FscParser::RuleFunction_parameter);
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
    setState(116);
    match(FscParser::T__8);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 469762560) != 0) {
      setState(117);
      function_typed_arguments_list();
    }
    setState(120);
    match(FscParser::T__9);
   
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

std::vector<FscParser::ExprContext *> FscParser::Function_typed_arguments_listContext::expr() {
  return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext* FscParser::Function_typed_arguments_listContext::expr(size_t i) {
  return getRuleContext<FscParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FscParser::Function_typed_arguments_listContext::NAME() {
  return getTokens(FscParser::NAME);
}

tree::TerminalNode* FscParser::Function_typed_arguments_listContext::NAME(size_t i) {
  return getToken(FscParser::NAME, i);
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
  enterRule(_localctx, 22, FscParser::RuleFunction_typed_arguments_list);
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
    setState(124);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(122);
      match(FscParser::NAME);
      setState(123);
      match(FscParser::T__10);
      break;
    }

    default:
      break;
    }
    setState(126);
    expr(0);
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__11) {
      setState(127);
      match(FscParser::T__11);
      setState(130);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(128);
        match(FscParser::NAME);
        setState(129);
        match(FscParser::T__10);
        break;
      }

      default:
        break;
      }
      setState(132);
      expr(0);
      setState(137);
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

//----------------- Variable_definitionContext ------------------------------------------------------------------

FscParser::Variable_definitionContext::Variable_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 24, FscParser::RuleVariable_definition);

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
    match(FscParser::T__12);
    setState(139);
    match(FscParser::NAME);
    setState(140);
    match(FscParser::T__4);
    setState(141);
    match(FscParser::NAME);
    setState(142);
    match(FscParser::T__10);
    setState(143);
    expr(0);
   
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
  enterRule(_localctx, 26, FscParser::RuleAuto_variable_definition);

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
    match(FscParser::T__12);
    setState(146);
    match(FscParser::NAME);
    setState(147);
    match(FscParser::T__10);
    setState(148);
    expr(0);
   
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
  enterRule(_localctx, 28, FscParser::RuleBody);
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
    setState(150);
    match(FscParser::T__13);
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 503325198) != 0) {
      setState(151);
      stmt();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(157);
    match(FscParser::T__14);
   
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

std::vector<FscParser::ExprContext *> FscParser::ExprContext::expr() {
  return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext* FscParser::ExprContext::expr(size_t i) {
  return getRuleContext<FscParser::ExprContext>(i);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, FscParser::RuleExpr, precedence);

    

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
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(160);
      function_call();
      break;
    }

    case 2: {
      setState(161);
      match(FscParser::T__8);
      setState(162);
      expr(0);
      setState(163);
      match(FscParser::T__9);
      break;
    }

    case 3: {
      setState(165);
      match(FscParser::INT);
      break;
    }

    case 4: {
      setState(166);
      match(FscParser::FLOAT);
      break;
    }

    case 5: {
      setState(167);
      match(FscParser::NAME);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(185);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(171);
          match(FscParser::MUL);
          setState(172);
          expr(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(173);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(174);
          match(FscParser::DIV);
          setState(175);
          expr(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(176);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(177);
          match(FscParser::MOD);
          setState(178);
          expr(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(179);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(180);
          match(FscParser::ADD);
          setState(181);
          expr(8);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(182);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(183);
          match(FscParser::SUB);
          setState(184);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
