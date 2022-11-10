
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
      "program", "stmt", "stmt_end", "function", "visibility", "function_attibutes", 
      "argument_definition", "argument_passing_type", "parameters", "typed_arguments_list", 
      "argument", "class", "function_call", "function_parameter", "function_typed_arguments_list", 
      "function_argument", "variable_definition", "auto_variable_definition", 
      "variable_prefix", "body", "expr"
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
  	4,1,37,226,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,5,
  	0,44,8,0,10,0,12,0,47,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,3,1,61,8,1,1,2,4,2,64,8,2,11,2,12,2,65,1,3,1,3,1,3,1,3,1,3,1,3,3,
  	3,74,8,3,1,3,5,3,77,8,3,10,3,12,3,80,9,3,1,3,1,3,1,4,1,4,1,5,3,5,87,8,
  	5,1,6,1,6,1,6,1,6,1,7,1,7,1,8,1,8,3,8,97,8,8,1,8,1,8,1,9,1,9,1,9,5,9,
  	104,8,9,10,9,12,9,107,9,9,1,10,1,10,1,10,3,10,112,8,10,1,11,1,11,1,11,
  	5,11,117,8,11,10,11,12,11,120,9,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,
  	3,13,129,8,13,1,13,1,13,1,14,1,14,1,14,5,14,136,8,14,10,14,12,14,139,
  	9,14,1,15,1,15,3,15,143,8,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,
  	5,16,153,8,16,10,16,12,16,156,9,16,1,16,3,16,159,8,16,1,17,1,17,1,17,
  	1,17,1,17,1,18,1,18,1,19,1,19,5,19,170,8,19,10,19,12,19,173,9,19,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	189,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,5,20,221,8,20,10,20,12,20,224,9,20,1,20,0,1,40,21,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,4,1,0,2,4,
  	1,0,7,10,1,0,11,13,1,0,20,21,240,0,45,1,0,0,0,2,60,1,0,0,0,4,63,1,0,0,
  	0,6,67,1,0,0,0,8,83,1,0,0,0,10,86,1,0,0,0,12,88,1,0,0,0,14,92,1,0,0,0,
  	16,94,1,0,0,0,18,100,1,0,0,0,20,108,1,0,0,0,22,113,1,0,0,0,24,123,1,0,
  	0,0,26,126,1,0,0,0,28,132,1,0,0,0,30,142,1,0,0,0,32,146,1,0,0,0,34,160,
  	1,0,0,0,36,165,1,0,0,0,38,167,1,0,0,0,40,188,1,0,0,0,42,44,3,2,1,0,43,
  	42,1,0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,45,46,1,0,0,0,46,1,1,0,0,0,47,
  	45,1,0,0,0,48,61,3,6,3,0,49,50,3,40,20,0,50,51,3,4,2,0,51,61,1,0,0,0,
  	52,53,3,22,11,0,53,54,3,4,2,0,54,61,1,0,0,0,55,56,5,1,0,0,56,57,3,40,
  	20,0,57,58,3,4,2,0,58,61,1,0,0,0,59,61,3,4,2,0,60,48,1,0,0,0,60,49,1,
  	0,0,0,60,52,1,0,0,0,60,55,1,0,0,0,60,59,1,0,0,0,61,3,1,0,0,0,62,64,7,
  	0,0,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,5,1,
  	0,0,0,67,68,3,10,5,0,68,69,5,5,0,0,69,70,5,36,0,0,70,73,3,16,8,0,71,72,
  	5,6,0,0,72,74,5,36,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,78,1,0,0,0,75,77,
  	5,2,0,0,76,75,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,81,
  	1,0,0,0,80,78,1,0,0,0,81,82,3,38,19,0,82,7,1,0,0,0,83,84,7,1,0,0,84,9,
  	1,0,0,0,85,87,3,8,4,0,86,85,1,0,0,0,86,87,1,0,0,0,87,11,1,0,0,0,88,89,
  	3,14,7,0,89,90,5,36,0,0,90,91,5,36,0,0,91,13,1,0,0,0,92,93,7,2,0,0,93,
  	15,1,0,0,0,94,96,5,14,0,0,95,97,3,18,9,0,96,95,1,0,0,0,96,97,1,0,0,0,
  	97,98,1,0,0,0,98,99,5,15,0,0,99,17,1,0,0,0,100,105,3,20,10,0,101,102,
  	5,16,0,0,102,104,3,20,10,0,103,101,1,0,0,0,104,107,1,0,0,0,105,103,1,
  	0,0,0,105,106,1,0,0,0,106,19,1,0,0,0,107,105,1,0,0,0,108,111,3,12,6,0,
  	109,110,5,17,0,0,110,112,3,40,20,0,111,109,1,0,0,0,111,112,1,0,0,0,112,
  	21,1,0,0,0,113,114,5,18,0,0,114,118,5,36,0,0,115,117,5,2,0,0,116,115,
  	1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,121,1,0,0,
  	0,120,118,1,0,0,0,121,122,3,38,19,0,122,23,1,0,0,0,123,124,5,36,0,0,124,
  	125,3,26,13,0,125,25,1,0,0,0,126,128,5,14,0,0,127,129,3,28,14,0,128,127,
  	1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,5,15,0,0,131,27,1,0,0,
  	0,132,137,3,30,15,0,133,134,5,16,0,0,134,136,3,30,15,0,135,133,1,0,0,
  	0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,29,1,0,0,0,139,
  	137,1,0,0,0,140,141,5,36,0,0,141,143,5,17,0,0,142,140,1,0,0,0,142,143,
  	1,0,0,0,143,144,1,0,0,0,144,145,3,40,20,0,145,31,1,0,0,0,146,147,3,36,
  	18,0,147,148,5,36,0,0,148,149,5,19,0,0,149,158,5,36,0,0,150,154,5,17,
  	0,0,151,153,5,2,0,0,152,151,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,
  	155,1,0,0,0,155,157,1,0,0,0,156,154,1,0,0,0,157,159,3,40,20,0,158,150,
  	1,0,0,0,158,159,1,0,0,0,159,33,1,0,0,0,160,161,3,36,18,0,161,162,5,36,
  	0,0,162,163,5,17,0,0,163,164,3,40,20,0,164,35,1,0,0,0,165,166,7,3,0,0,
  	166,37,1,0,0,0,167,171,5,22,0,0,168,170,3,2,1,0,169,168,1,0,0,0,170,173,
  	1,0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,174,1,0,0,0,173,171,1,0,0,
  	0,174,175,5,23,0,0,175,39,1,0,0,0,176,177,6,20,-1,0,177,189,3,24,12,0,
  	178,189,3,32,16,0,179,189,3,34,17,0,180,181,5,14,0,0,181,182,3,40,20,
  	0,182,183,5,15,0,0,183,189,1,0,0,0,184,189,3,38,19,0,185,189,5,34,0,0,
  	186,189,5,35,0,0,187,189,5,36,0,0,188,176,1,0,0,0,188,178,1,0,0,0,188,
  	179,1,0,0,0,188,180,1,0,0,0,188,184,1,0,0,0,188,185,1,0,0,0,188,186,1,
  	0,0,0,188,187,1,0,0,0,189,222,1,0,0,0,190,191,10,17,0,0,191,192,5,27,
  	0,0,192,221,3,40,20,18,193,194,10,16,0,0,194,195,5,28,0,0,195,221,3,40,
  	20,17,196,197,10,15,0,0,197,198,5,29,0,0,198,221,3,40,20,16,199,200,10,
  	14,0,0,200,201,5,25,0,0,201,221,3,40,20,15,202,203,10,13,0,0,203,204,
  	5,26,0,0,204,221,3,40,20,14,205,206,10,12,0,0,206,207,5,30,0,0,207,221,
  	3,40,20,13,208,209,10,11,0,0,209,210,5,31,0,0,210,221,3,40,20,12,211,
  	212,10,10,0,0,212,213,5,32,0,0,213,221,3,40,20,11,214,215,10,9,0,0,215,
  	216,5,33,0,0,216,221,3,40,20,10,217,218,10,18,0,0,218,219,5,24,0,0,219,
  	221,5,36,0,0,220,190,1,0,0,0,220,193,1,0,0,0,220,196,1,0,0,0,220,199,
  	1,0,0,0,220,202,1,0,0,0,220,205,1,0,0,0,220,208,1,0,0,0,220,211,1,0,0,
  	0,220,214,1,0,0,0,220,217,1,0,0,0,221,224,1,0,0,0,222,220,1,0,0,0,222,
  	223,1,0,0,0,223,41,1,0,0,0,224,222,1,0,0,0,19,45,60,65,73,78,86,96,105,
  	111,118,128,137,142,154,158,171,188,220,222
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
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120266704830) != 0) {
      setState(42);
      stmt();
      setState(47);
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
    setState(60);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FscParser::T__4:
      case FscParser::T__6:
      case FscParser::T__7:
      case FscParser::T__8:
      case FscParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(48);
        function();
        break;
      }

      case FscParser::T__13:
      case FscParser::T__19:
      case FscParser::T__20:
      case FscParser::T__21:
      case FscParser::INT:
      case FscParser::FLOAT:
      case FscParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(49);
        expr(0);
        setState(50);
        stmt_end();
        break;
      }

      case FscParser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(52);
        class_();
        setState(53);
        stmt_end();
        break;
      }

      case FscParser::T__0: {
        enterOuterAlt(_localctx, 4);
        setState(55);
        match(FscParser::T__0);
        setState(56);
        expr(0);
        setState(57);
        stmt_end();
        break;
      }

      case FscParser::T__1:
      case FscParser::T__2:
      case FscParser::T__3: {
        enterOuterAlt(_localctx, 5);
        setState(59);
        stmt_end();
        break;
      }

    default:
      throw NoViableAltException(this);
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
  enterRule(_localctx, 4, FscParser::RuleStmt_end);
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
    setState(63); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(62);
              _la = _input->LA(1);
              if (!(((_la & ~ 0x3fULL) == 0) &&
                ((1ULL << _la) & 28) != 0)) {
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
      setState(65); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
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
  enterRule(_localctx, 6, FscParser::RuleFunction);
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
    setState(67);
    function_attibutes();
    setState(68);
    match(FscParser::T__4);
    setState(69);
    match(FscParser::NAME);
    setState(70);
    parameters();
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__5) {
      setState(71);
      match(FscParser::T__5);
      setState(72);
      match(FscParser::NAME);
    }

    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__1) {
      setState(75);
      match(FscParser::T__1);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
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
  enterRule(_localctx, 8, FscParser::RuleVisibility);
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
    setState(83);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1920) != 0)) {
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
  enterRule(_localctx, 10, FscParser::RuleFunction_attibutes);
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
    setState(86);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1920) != 0) {
      setState(85);
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
  enterRule(_localctx, 12, FscParser::RuleArgument_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    argument_passing_type();
    setState(89);
    match(FscParser::NAME);
    setState(90);
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
  enterRule(_localctx, 14, FscParser::RuleArgument_passing_type);
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
    setState(92);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0)) {
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
  enterRule(_localctx, 16, FscParser::RuleParameters);
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
    match(FscParser::T__13);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0) {
      setState(95);
      typed_arguments_list();
    }
    setState(98);
    match(FscParser::T__14);
   
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
  enterRule(_localctx, 18, FscParser::RuleTyped_arguments_list);
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
    setState(100);
    argument();
    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__15) {
      setState(101);
      match(FscParser::T__15);
      setState(102);
      argument();
      setState(107);
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
  enterRule(_localctx, 20, FscParser::RuleArgument);
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
    setState(108);
    argument_definition();
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FscParser::T__16) {
      setState(109);
      match(FscParser::T__16);
      setState(110);
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
  enterRule(_localctx, 22, FscParser::RuleClass);
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
    setState(113);
    match(FscParser::T__17);
    setState(114);
    match(FscParser::NAME);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__1) {
      setState(115);
      match(FscParser::T__1);
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
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
  enterRule(_localctx, 24, FscParser::RuleFunction_call);

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
    match(FscParser::NAME);
    setState(124);
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
  enterRule(_localctx, 26, FscParser::RuleFunction_parameter);
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
    setState(126);
    match(FscParser::T__13);
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120266440704) != 0) {
      setState(127);
      function_typed_arguments_list();
    }
    setState(130);
    match(FscParser::T__14);
   
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
  enterRule(_localctx, 28, FscParser::RuleFunction_typed_arguments_list);
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
    function_argument();
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FscParser::T__15) {
      setState(133);
      match(FscParser::T__15);
      setState(134);
      function_argument();
      setState(139);
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
  enterRule(_localctx, 30, FscParser::RuleFunction_argument);

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

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(140);
      match(FscParser::NAME);
      setState(141);
      match(FscParser::T__16);
      break;
    }

    default:
      break;
    }
    setState(144);
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
  enterRule(_localctx, 32, FscParser::RuleVariable_definition);
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
    setState(146);
    variable_prefix();
    setState(147);
    match(FscParser::NAME);
    setState(148);
    match(FscParser::T__18);
    setState(149);
    match(FscParser::NAME);
    setState(158);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(150);
      match(FscParser::T__16);
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FscParser::T__1) {
        setState(151);
        match(FscParser::T__1);
        setState(156);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(157);
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
  enterRule(_localctx, 34, FscParser::RuleAuto_variable_definition);

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
    variable_prefix();
    setState(161);
    match(FscParser::NAME);
    setState(162);
    match(FscParser::T__16);
    setState(163);
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
  enterRule(_localctx, 36, FscParser::RuleVariable_prefix);
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
    setState(165);
    _la = _input->LA(1);
    if (!(_la == FscParser::T__19

    || _la == FscParser::T__20)) {
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
  enterRule(_localctx, 38, FscParser::RuleBody);
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
    match(FscParser::T__21);
    setState(171);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120266704830) != 0) {
      setState(168);
      stmt();
      setState(173);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(174);
    match(FscParser::T__22);
   
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, FscParser::RuleExpr, precedence);

    

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
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(177);
      function_call();
      break;
    }

    case 2: {
      setState(178);
      variable_definition();
      break;
    }

    case 3: {
      setState(179);
      auto_variable_definition();
      break;
    }

    case 4: {
      setState(180);
      match(FscParser::T__13);
      setState(181);
      expr(0);
      setState(182);
      match(FscParser::T__14);
      break;
    }

    case 5: {
      setState(184);
      body();
      break;
    }

    case 6: {
      setState(185);
      match(FscParser::INT);
      break;
    }

    case 7: {
      setState(186);
      match(FscParser::FLOAT);
      break;
    }

    case 8: {
      setState(187);
      match(FscParser::NAME);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(222);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(220);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(191);
          match(FscParser::MUL);
          setState(192);
          expr(18);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(193);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(194);
          match(FscParser::DIV);
          setState(195);
          expr(17);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(196);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(197);
          match(FscParser::MOD);
          setState(198);
          expr(16);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(200);
          match(FscParser::ADD);
          setState(201);
          expr(15);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(203);
          match(FscParser::SUB);
          setState(204);
          expr(14);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(205);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(206);
          match(FscParser::EQUALITY);
          setState(207);
          expr(13);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(208);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(209);
          match(FscParser::INEQUALITY);
          setState(210);
          expr(12);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(211);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(212);
          match(FscParser::LOGICAL_AND);
          setState(213);
          expr(11);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(214);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(215);
          match(FscParser::LOGICAL_OR);
          setState(216);
          expr(10);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(217);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(218);
          match(FscParser::AS);
          setState(219);
          match(FscParser::NAME);
          break;
        }

        default:
          break;
        } 
      }
      setState(224);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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
    case 20: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
    case 9: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

void FscParser::initialize() {
  ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
