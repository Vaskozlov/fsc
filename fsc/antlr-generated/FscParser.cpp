
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
              vocabulary(this->literalNames, this->symbolicNames)
        {}

        FscParserStaticData(const FscParserStaticData &) = delete;
        FscParserStaticData(FscParserStaticData &&) = delete;
        FscParserStaticData &operator=(const FscParserStaticData &) = delete;
        FscParserStaticData &operator=(FscParserStaticData &&) = delete;

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

    void fscParserInitialize()
    {
        assert(fscParserStaticData == nullptr);
        auto staticData = std::make_unique<FscParserStaticData>(
                std::vector<std::string>{"program", "global_stmt", "stmt", "stmt_end", "function",
                                         "argument_definition", "argument_passing_type",
                                         "parameters", "typed_arguments_list",
                                         "variable_definition", "auto_variable_definition", "body",
                                         "expr"},
                std::vector<std::string>{"",       "'\\n'",   "'\\r'",   "';'",  "'->'",  "':'",
                                         "'in'",   "'out'",   "'inout'", "'('",  "')'",   "'='",
                                         "','",    "'var'",   "'{'",     "'}'",  "",      "",
                                         "",       "",        "",        "'if'", "'for'", "'while'",
                                         "'func'", "'return'"},
                std::vector<std::string>{"",     "",       "",    "",      "",     "",
                                         "",     "",       "",    "",      "",     "",
                                         "",     "",       "",    "",      "ADD",  "SUB",
                                         "MUL",  "DIV",    "MOD", "IF",    "FOR",  "WHILE",
                                         "FUNC", "RETURN", "INT", "FLOAT", "NAME", "LAYOUT"});
        static const int32_t serializedATNSegment[] = {
                4,   1,   29,  159, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,
                3,   7,   3,   2,   4,   7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,
                7,   7,   2,   8,   7,   8,   2,   9,   7,   9,   2,   10,  7,   10,  2,   11,  7,
                11,  2,   12,  7,   12,  1,   0,   5,   0,   28,  8,   0,   10,  0,   12,  0,   31,
                9,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
                1,   3,   1,   41,  8,   1,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,
                2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,
                3,   2,   57,  8,   2,   1,   3,   4,   3,   60,  8,   3,   11,  3,   12,  3,   61,
                1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   3,   4,   69,  8,   4,   1,   4,
                5,   4,   72,  8,   4,   10,  4,   12,  4,   75,  9,   4,   1,   4,   1,   4,   1,
                5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   6,   1,   6,   1,   7,   1,   7,
                3,   7,   88,  8,   7,   1,   7,   1,   7,   1,   8,   1,   8,   1,   8,   3,   8,
                95,  8,   8,   1,   8,   1,   8,   1,   8,   1,   8,   3,   8,   101, 8,   8,   5,
                8,   103, 8,   8,   10,  8,   12,  8,   106, 9,   8,   1,   9,   1,   9,   1,   9,
                1,   9,   1,   9,   1,   9,   1,   9,   1,   10,  1,   10,  1,   10,  1,   10,  1,
                10,  1,   11,  1,   11,  5,   11,  122, 8,   11,  10,  11,  12,  11,  125, 9,   11,
                1,   11,  1,   11,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,
                12,  1,   12,  3,   12,  137, 8,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,
                12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,  1,   12,
                1,   12,  1,   12,  5,   12,  154, 8,   12,  10,  12,  12,  12,  157, 9,   12,  1,
                12,  0,   1,   24,  13,  0,   2,   4,   6,   8,   10,  12,  14,  16,  18,  20,  22,
                24,  0,   2,   1,   0,   1,   3,   1,   0,   6,   8,   169, 0,   29,  1,   0,   0,
                0,   2,   40,  1,   0,   0,   0,   4,   56,  1,   0,   0,   0,   6,   59,  1,   0,
                0,   0,   8,   63,  1,   0,   0,   0,   10,  78,  1,   0,   0,   0,   12,  83,  1,
                0,   0,   0,   14,  85,  1,   0,   0,   0,   16,  91,  1,   0,   0,   0,   18,  107,
                1,   0,   0,   0,   20,  114, 1,   0,   0,   0,   22,  119, 1,   0,   0,   0,   24,
                136, 1,   0,   0,   0,   26,  28,  3,   2,   1,   0,   27,  26,  1,   0,   0,   0,
                28,  31,  1,   0,   0,   0,   29,  27,  1,   0,   0,   0,   29,  30,  1,   0,   0,
                0,   30,  1,   1,   0,   0,   0,   31,  29,  1,   0,   0,   0,   32,  41,  3,   8,
                4,   0,   33,  34,  3,   18,  9,   0,   34,  35,  3,   6,   3,   0,   35,  41,  1,
                0,   0,   0,   36,  37,  3,   20,  10,  0,   37,  38,  3,   6,   3,   0,   38,  41,
                1,   0,   0,   0,   39,  41,  3,   6,   3,   0,   40,  32,  1,   0,   0,   0,   40,
                33,  1,   0,   0,   0,   40,  36,  1,   0,   0,   0,   40,  39,  1,   0,   0,   0,
                41,  3,   1,   0,   0,   0,   42,  43,  3,   24,  12,  0,   43,  44,  3,   6,   3,
                0,   44,  57,  1,   0,   0,   0,   45,  46,  5,   25,  0,   0,   46,  47,  3,   24,
                12,  0,   47,  48,  3,   6,   3,   0,   48,  57,  1,   0,   0,   0,   49,  50,  3,
                18,  9,   0,   50,  51,  3,   6,   3,   0,   51,  57,  1,   0,   0,   0,   52,  53,
                3,   20,  10,  0,   53,  54,  3,   6,   3,   0,   54,  57,  1,   0,   0,   0,   55,
                57,  3,   6,   3,   0,   56,  42,  1,   0,   0,   0,   56,  45,  1,   0,   0,   0,
                56,  49,  1,   0,   0,   0,   56,  52,  1,   0,   0,   0,   56,  55,  1,   0,   0,
                0,   57,  5,   1,   0,   0,   0,   58,  60,  7,   0,   0,   0,   59,  58,  1,   0,
                0,   0,   60,  61,  1,   0,   0,   0,   61,  59,  1,   0,   0,   0,   61,  62,  1,
                0,   0,   0,   62,  7,   1,   0,   0,   0,   63,  64,  5,   24,  0,   0,   64,  65,
                5,   28,  0,   0,   65,  68,  3,   14,  7,   0,   66,  67,  5,   4,   0,   0,   67,
                69,  5,   28,  0,   0,   68,  66,  1,   0,   0,   0,   68,  69,  1,   0,   0,   0,
                69,  73,  1,   0,   0,   0,   70,  72,  5,   1,   0,   0,   71,  70,  1,   0,   0,
                0,   72,  75,  1,   0,   0,   0,   73,  71,  1,   0,   0,   0,   73,  74,  1,   0,
                0,   0,   74,  76,  1,   0,   0,   0,   75,  73,  1,   0,   0,   0,   76,  77,  3,
                22,  11,  0,   77,  9,   1,   0,   0,   0,   78,  79,  5,   28,  0,   0,   79,  80,
                5,   5,   0,   0,   80,  81,  3,   12,  6,   0,   81,  82,  5,   28,  0,   0,   82,
                11,  1,   0,   0,   0,   83,  84,  7,   1,   0,   0,   84,  13,  1,   0,   0,   0,
                85,  87,  5,   9,   0,   0,   86,  88,  3,   16,  8,   0,   87,  86,  1,   0,   0,
                0,   87,  88,  1,   0,   0,   0,   88,  89,  1,   0,   0,   0,   89,  90,  5,   10,
                0,   0,   90,  15,  1,   0,   0,   0,   91,  94,  3,   10,  5,   0,   92,  93,  5,
                11,  0,   0,   93,  95,  3,   24,  12,  0,   94,  92,  1,   0,   0,   0,   94,  95,
                1,   0,   0,   0,   95,  104, 1,   0,   0,   0,   96,  97,  5,   12,  0,   0,   97,
                100, 3,   10,  5,   0,   98,  99,  5,   11,  0,   0,   99,  101, 3,   24,  12,  0,
                100, 98,  1,   0,   0,   0,   100, 101, 1,   0,   0,   0,   101, 103, 1,   0,   0,
                0,   102, 96,  1,   0,   0,   0,   103, 106, 1,   0,   0,   0,   104, 102, 1,   0,
                0,   0,   104, 105, 1,   0,   0,   0,   105, 17,  1,   0,   0,   0,   106, 104, 1,
                0,   0,   0,   107, 108, 5,   13,  0,   0,   108, 109, 5,   28,  0,   0,   109, 110,
                5,   5,   0,   0,   110, 111, 5,   28,  0,   0,   111, 112, 5,   11,  0,   0,   112,
                113, 3,   24,  12,  0,   113, 19,  1,   0,   0,   0,   114, 115, 5,   13,  0,   0,
                115, 116, 5,   28,  0,   0,   116, 117, 5,   11,  0,   0,   117, 118, 3,   24,  12,
                0,   118, 21,  1,   0,   0,   0,   119, 123, 5,   14,  0,   0,   120, 122, 3,   4,
                2,   0,   121, 120, 1,   0,   0,   0,   122, 125, 1,   0,   0,   0,   123, 121, 1,
                0,   0,   0,   123, 124, 1,   0,   0,   0,   124, 126, 1,   0,   0,   0,   125, 123,
                1,   0,   0,   0,   126, 127, 5,   15,  0,   0,   127, 23,  1,   0,   0,   0,   128,
                129, 6,   12,  -1,  0,   129, 130, 5,   9,   0,   0,   130, 131, 3,   24,  12,  0,
                131, 132, 5,   10,  0,   0,   132, 137, 1,   0,   0,   0,   133, 137, 5,   26,  0,
                0,   134, 137, 5,   27,  0,   0,   135, 137, 5,   28,  0,   0,   136, 128, 1,   0,
                0,   0,   136, 133, 1,   0,   0,   0,   136, 134, 1,   0,   0,   0,   136, 135, 1,
                0,   0,   0,   137, 155, 1,   0,   0,   0,   138, 139, 10,  9,   0,   0,   139, 140,
                5,   18,  0,   0,   140, 154, 3,   24,  12,  10,  141, 142, 10,  8,   0,   0,   142,
                143, 5,   19,  0,   0,   143, 154, 3,   24,  12,  9,   144, 145, 10,  7,   0,   0,
                145, 146, 5,   20,  0,   0,   146, 154, 3,   24,  12,  8,   147, 148, 10,  6,   0,
                0,   148, 149, 5,   16,  0,   0,   149, 154, 3,   24,  12,  7,   150, 151, 10,  5,
                0,   0,   151, 152, 5,   17,  0,   0,   152, 154, 3,   24,  12,  6,   153, 138, 1,
                0,   0,   0,   153, 141, 1,   0,   0,   0,   153, 144, 1,   0,   0,   0,   153, 147,
                1,   0,   0,   0,   153, 150, 1,   0,   0,   0,   154, 157, 1,   0,   0,   0,   155,
                153, 1,   0,   0,   0,   155, 156, 1,   0,   0,   0,   156, 25,  1,   0,   0,   0,
                157, 155, 1,   0,   0,   0,   14,  29,  40,  56,  61,  68,  73,  87,  94,  100, 104,
                123, 136, 153, 155};
        staticData->serializedATN = antlr4::atn::SerializedATNView(
                serializedATNSegment,
                sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

        antlr4::atn::ATNDeserializer deserializer;
        staticData->atn = deserializer.deserialize(staticData->serializedATN);

        const size_t count = staticData->atn->getNumberOfDecisions();
        staticData->decisionToDFA.reserve(count);
        for (size_t i = 0; i < count; i++) {
            staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
        }
        fscParserStaticData = staticData.release();
    }

}// namespace

FscParser::FscParser(TokenStream *input)
    : FscParser(input, antlr4::atn::ParserATNSimulatorOptions())
{}

FscParser::FscParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options)
    : Parser(input)
{
    FscParser::initialize();
    _interpreter = new atn::ParserATNSimulator(this, *fscParserStaticData->atn,
                                               fscParserStaticData->decisionToDFA,
                                               fscParserStaticData->sharedContextCache, options);
}

FscParser::~FscParser()
{
    delete _interpreter;
}

const atn::ATN &FscParser::getATN() const
{
    return *fscParserStaticData->atn;
}

std::string FscParser::getGrammarFileName() const
{
    return "Fsc.g4";
}

const std::vector<std::string> &FscParser::getRuleNames() const
{
    return fscParserStaticData->ruleNames;
}

const dfa::Vocabulary &FscParser::getVocabulary() const
{
    return fscParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FscParser::getSerializedATN() const
{
    return fscParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

FscParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::Global_stmtContext *> FscParser::ProgramContext::global_stmt()
{
    return getRuleContexts<FscParser::Global_stmtContext>();
}

FscParser::Global_stmtContext *FscParser::ProgramContext::global_stmt(size_t i)
{
    return getRuleContext<FscParser::Global_stmtContext>(i);
}


size_t FscParser::ProgramContext::getRuleIndex() const
{
    return FscParser::RuleProgram;
}


std::any FscParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitProgram(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ProgramContext *FscParser::program()
{
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
        setState(29);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 16785422) != 0) {
            setState(26);
            global_stmt();
            setState(31);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Global_stmtContext ------------------------------------------------------------------

FscParser::Global_stmtContext::Global_stmtContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

FscParser::FunctionContext *FscParser::Global_stmtContext::function()
{
    return getRuleContext<FscParser::FunctionContext>(0);
}

FscParser::Variable_definitionContext *FscParser::Global_stmtContext::variable_definition()
{
    return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Stmt_endContext *FscParser::Global_stmtContext::stmt_end()
{
    return getRuleContext<FscParser::Stmt_endContext>(0);
}

FscParser::Auto_variable_definitionContext *
FscParser::Global_stmtContext::auto_variable_definition()
{
    return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
}


size_t FscParser::Global_stmtContext::getRuleIndex() const
{
    return FscParser::RuleGlobal_stmt;
}


std::any FscParser::Global_stmtContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitGlobal_stmt(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Global_stmtContext *FscParser::global_stmt()
{
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
        setState(40);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(32);
                function();
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(33);
                variable_definition();
                setState(34);
                stmt_end();
                break;
            }

            case 3: {
                enterOuterAlt(_localctx, 3);
                setState(36);
                auto_variable_definition();
                setState(37);
                stmt_end();
                break;
            }

            case 4: {
                enterOuterAlt(_localctx, 4);
                setState(39);
                stmt_end();
                break;
            }

            default:
                break;
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

FscParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

FscParser::ExprContext *FscParser::StmtContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::Stmt_endContext *FscParser::StmtContext::stmt_end()
{
    return getRuleContext<FscParser::Stmt_endContext>(0);
}

tree::TerminalNode *FscParser::StmtContext::RETURN()
{
    return getToken(FscParser::RETURN, 0);
}

FscParser::Variable_definitionContext *FscParser::StmtContext::variable_definition()
{
    return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Auto_variable_definitionContext *FscParser::StmtContext::auto_variable_definition()
{
    return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
}


size_t FscParser::StmtContext::getRuleIndex() const
{
    return FscParser::RuleStmt;
}


std::any FscParser::StmtContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitStmt(this);
    else
        return visitor->visitChildren(this);
}

FscParser::StmtContext *FscParser::stmt()
{
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
        setState(56);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(42);
                expr(0);
                setState(43);
                stmt_end();
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(45);
                match(FscParser::RETURN);
                setState(46);
                expr(0);
                setState(47);
                stmt_end();
                break;
            }

            case 3: {
                enterOuterAlt(_localctx, 3);
                setState(49);
                variable_definition();
                setState(50);
                stmt_end();
                break;
            }

            case 4: {
                enterOuterAlt(_localctx, 4);
                setState(52);
                auto_variable_definition();
                setState(53);
                stmt_end();
                break;
            }

            case 5: {
                enterOuterAlt(_localctx, 5);
                setState(55);
                stmt_end();
                break;
            }

            default:
                break;
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Stmt_endContext ------------------------------------------------------------------

FscParser::Stmt_endContext::Stmt_endContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}


size_t FscParser::Stmt_endContext::getRuleIndex() const
{
    return FscParser::RuleStmt_end;
}


std::any FscParser::Stmt_endContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitStmt_end(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Stmt_endContext *FscParser::stmt_end()
{
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
        setState(59);
        _errHandler->sync(this);
        alt = 1;
        do {
            switch (alt) {
                case 1: {
                    setState(58);
                    _la = _input->LA(1);
                    if (!(((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 14) != 0)) {
                        _errHandler->recoverInline(this);
                    } else {
                        _errHandler->reportMatch(this);
                        consume();
                    }
                    break;
                }

                default:
                    throw NoViableAltException(this);
            }
            setState(61);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FscParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode *FscParser::FunctionContext::FUNC()
{
    return getToken(FscParser::FUNC, 0);
}

std::vector<tree::TerminalNode *> FscParser::FunctionContext::NAME()
{
    return getTokens(FscParser::NAME);
}

tree::TerminalNode *FscParser::FunctionContext::NAME(size_t i)
{
    return getToken(FscParser::NAME, i);
}

FscParser::ParametersContext *FscParser::FunctionContext::parameters()
{
    return getRuleContext<FscParser::ParametersContext>(0);
}

FscParser::BodyContext *FscParser::FunctionContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::FunctionContext::getRuleIndex() const
{
    return FscParser::RuleFunction;
}


std::any FscParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction(this);
    else
        return visitor->visitChildren(this);
}

FscParser::FunctionContext *FscParser::function()
{
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
        setState(63);
        match(FscParser::FUNC);
        setState(64);
        match(FscParser::NAME);
        setState(65);
        parameters();
        setState(68);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::T__3) {
            setState(66);
            match(FscParser::T__3);
            setState(67);
            match(FscParser::NAME);
        }

        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FscParser::T__0) {
            setState(70);
            match(FscParser::T__0);
            setState(75);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(76);
        body();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Argument_definitionContext ------------------------------------------------------------------

FscParser::Argument_definitionContext::Argument_definitionContext(ParserRuleContext *parent,
                                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<tree::TerminalNode *> FscParser::Argument_definitionContext::NAME()
{
    return getTokens(FscParser::NAME);
}

tree::TerminalNode *FscParser::Argument_definitionContext::NAME(size_t i)
{
    return getToken(FscParser::NAME, i);
}

FscParser::Argument_passing_typeContext *
FscParser::Argument_definitionContext::argument_passing_type()
{
    return getRuleContext<FscParser::Argument_passing_typeContext>(0);
}


size_t FscParser::Argument_definitionContext::getRuleIndex() const
{
    return FscParser::RuleArgument_definition;
}


std::any FscParser::Argument_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitArgument_definition(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Argument_definitionContext *FscParser::argument_definition()
{
    Argument_definitionContext *_localctx =
            _tracker.createInstance<Argument_definitionContext>(_ctx, getState());
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
        setState(78);
        match(FscParser::NAME);
        setState(79);
        match(FscParser::T__4);
        setState(80);
        argument_passing_type();
        setState(81);
        match(FscParser::NAME);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Argument_passing_typeContext ------------------------------------------------------------------

FscParser::Argument_passing_typeContext::Argument_passing_typeContext(ParserRuleContext *parent,
                                                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}


size_t FscParser::Argument_passing_typeContext::getRuleIndex() const
{
    return FscParser::RuleArgument_passing_type;
}


std::any FscParser::Argument_passing_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitArgument_passing_type(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Argument_passing_typeContext *FscParser::argument_passing_type()
{
    Argument_passing_typeContext *_localctx =
            _tracker.createInstance<Argument_passing_typeContext>(_ctx, getState());
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
        setState(83);
        _la = _input->LA(1);
        if (!(((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 448) != 0)) {
            _errHandler->recoverInline(this);
        } else {
            _errHandler->reportMatch(this);
            consume();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

FscParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

FscParser::Typed_arguments_listContext *FscParser::ParametersContext::typed_arguments_list()
{
    return getRuleContext<FscParser::Typed_arguments_listContext>(0);
}


size_t FscParser::ParametersContext::getRuleIndex() const
{
    return FscParser::RuleParameters;
}


std::any FscParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitParameters(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ParametersContext *FscParser::parameters()
{
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
        setState(85);
        match(FscParser::T__8);
        setState(87);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::NAME) {
            setState(86);
            typed_arguments_list();
        }
        setState(89);
        match(FscParser::T__9);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Typed_arguments_listContext ------------------------------------------------------------------

FscParser::Typed_arguments_listContext::Typed_arguments_listContext(ParserRuleContext *parent,
                                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::Argument_definitionContext *>
FscParser::Typed_arguments_listContext::argument_definition()
{
    return getRuleContexts<FscParser::Argument_definitionContext>();
}

FscParser::Argument_definitionContext *
FscParser::Typed_arguments_listContext::argument_definition(size_t i)
{
    return getRuleContext<FscParser::Argument_definitionContext>(i);
}

std::vector<FscParser::ExprContext *> FscParser::Typed_arguments_listContext::expr()
{
    return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext *FscParser::Typed_arguments_listContext::expr(size_t i)
{
    return getRuleContext<FscParser::ExprContext>(i);
}


size_t FscParser::Typed_arguments_listContext::getRuleIndex() const
{
    return FscParser::RuleTyped_arguments_list;
}


std::any FscParser::Typed_arguments_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitTyped_arguments_list(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Typed_arguments_listContext *FscParser::typed_arguments_list()
{
    Typed_arguments_listContext *_localctx =
            _tracker.createInstance<Typed_arguments_listContext>(_ctx, getState());
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
        setState(91);
        argument_definition();
        setState(94);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::T__10) {
            setState(92);
            match(FscParser::T__10);
            setState(93);
            expr(0);
        }
        setState(104);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FscParser::T__11) {
            setState(96);
            match(FscParser::T__11);
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
            setState(106);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Variable_definitionContext ------------------------------------------------------------------

FscParser::Variable_definitionContext::Variable_definitionContext(ParserRuleContext *parent,
                                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<tree::TerminalNode *> FscParser::Variable_definitionContext::NAME()
{
    return getTokens(FscParser::NAME);
}

tree::TerminalNode *FscParser::Variable_definitionContext::NAME(size_t i)
{
    return getToken(FscParser::NAME, i);
}

FscParser::ExprContext *FscParser::Variable_definitionContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}


size_t FscParser::Variable_definitionContext::getRuleIndex() const
{
    return FscParser::RuleVariable_definition;
}


std::any FscParser::Variable_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitVariable_definition(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Variable_definitionContext *FscParser::variable_definition()
{
    Variable_definitionContext *_localctx =
            _tracker.createInstance<Variable_definitionContext>(_ctx, getState());
    enterRule(_localctx, 18, FscParser::RuleVariable_definition);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(107);
        match(FscParser::T__12);
        setState(108);
        match(FscParser::NAME);
        setState(109);
        match(FscParser::T__4);
        setState(110);
        match(FscParser::NAME);
        setState(111);
        match(FscParser::T__10);
        setState(112);
        expr(0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Auto_variable_definitionContext ------------------------------------------------------------------

FscParser::Auto_variable_definitionContext::Auto_variable_definitionContext(
        ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode *FscParser::Auto_variable_definitionContext::NAME()
{
    return getToken(FscParser::NAME, 0);
}

FscParser::ExprContext *FscParser::Auto_variable_definitionContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}


size_t FscParser::Auto_variable_definitionContext::getRuleIndex() const
{
    return FscParser::RuleAuto_variable_definition;
}


std::any FscParser::Auto_variable_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitAuto_variable_definition(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Auto_variable_definitionContext *FscParser::auto_variable_definition()
{
    Auto_variable_definitionContext *_localctx =
            _tracker.createInstance<Auto_variable_definitionContext>(_ctx, getState());
    enterRule(_localctx, 20, FscParser::RuleAuto_variable_definition);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(114);
        match(FscParser::T__12);
        setState(115);
        match(FscParser::NAME);
        setState(116);
        match(FscParser::T__10);
        setState(117);
        expr(0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

FscParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::StmtContext *> FscParser::BodyContext::stmt()
{
    return getRuleContexts<FscParser::StmtContext>();
}

FscParser::StmtContext *FscParser::BodyContext::stmt(size_t i)
{
    return getRuleContext<FscParser::StmtContext>(i);
}


size_t FscParser::BodyContext::getRuleIndex() const
{
    return FscParser::RuleBody;
}


std::any FscParser::BodyContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitBody(this);
    else
        return visitor->visitChildren(this);
}

FscParser::BodyContext *FscParser::body()
{
    BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
    enterRule(_localctx, 22, FscParser::RuleBody);
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
        setState(119);
        match(FscParser::T__13);
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 503325198) != 0) {
            setState(120);
            stmt();
            setState(125);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(126);
        match(FscParser::T__14);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FscParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::ExprContext *> FscParser::ExprContext::expr()
{
    return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext *FscParser::ExprContext::expr(size_t i)
{
    return getRuleContext<FscParser::ExprContext>(i);
}

tree::TerminalNode *FscParser::ExprContext::INT()
{
    return getToken(FscParser::INT, 0);
}

tree::TerminalNode *FscParser::ExprContext::FLOAT()
{
    return getToken(FscParser::FLOAT, 0);
}

tree::TerminalNode *FscParser::ExprContext::NAME()
{
    return getToken(FscParser::NAME, 0);
}

tree::TerminalNode *FscParser::ExprContext::MUL()
{
    return getToken(FscParser::MUL, 0);
}

tree::TerminalNode *FscParser::ExprContext::DIV()
{
    return getToken(FscParser::DIV, 0);
}

tree::TerminalNode *FscParser::ExprContext::MOD()
{
    return getToken(FscParser::MOD, 0);
}

tree::TerminalNode *FscParser::ExprContext::ADD()
{
    return getToken(FscParser::ADD, 0);
}

tree::TerminalNode *FscParser::ExprContext::SUB()
{
    return getToken(FscParser::SUB, 0);
}


size_t FscParser::ExprContext::getRuleIndex() const
{
    return FscParser::RuleExpr;
}


std::any FscParser::ExprContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitExpr(this);
    else
        return visitor->visitChildren(this);
}


FscParser::ExprContext *FscParser::expr()
{
    return expr(0);
}

FscParser::ExprContext *FscParser::expr(int precedence)
{
    ParserRuleContext *parentContext = _ctx;
    size_t parentState = getState();
    FscParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
    FscParser::ExprContext *previousContext = _localctx;
    (void) previousContext;// Silence compiler, in case the context is not used by generated code.
    size_t startState = 24;
    enterRecursionRule(_localctx, 24, FscParser::RuleExpr, precedence);


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
        setState(136);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
            case FscParser::T__8: {
                setState(129);
                match(FscParser::T__8);
                setState(130);
                expr(0);
                setState(131);
                match(FscParser::T__9);
                break;
            }

            case FscParser::INT: {
                setState(133);
                match(FscParser::INT);
                break;
            }

            case FscParser::FLOAT: {
                setState(134);
                match(FscParser::FLOAT);
                break;
            }

            case FscParser::NAME: {
                setState(135);
                match(FscParser::NAME);
                break;
            }

            default:
                throw NoViableAltException(this);
        }
        _ctx->stop = _input->LT(-1);
        setState(155);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                if (!_parseListeners.empty())
                    triggerExitRuleEvent();
                previousContext = _localctx;
                setState(153);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12,
                                                                                   _ctx)) {
                    case 1: {
                        _localctx =
                                _tracker.createInstance<ExprContext>(parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState, RuleExpr);
                        setState(138);

                        if (!(precpred(_ctx, 9)))
                            throw FailedPredicateException(this, "precpred(_ctx, 9)");
                        setState(139);
                        match(FscParser::MUL);
                        setState(140);
                        expr(10);
                        break;
                    }

                    case 2: {
                        _localctx =
                                _tracker.createInstance<ExprContext>(parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState, RuleExpr);
                        setState(141);

                        if (!(precpred(_ctx, 8)))
                            throw FailedPredicateException(this, "precpred(_ctx, 8)");
                        setState(142);
                        match(FscParser::DIV);
                        setState(143);
                        expr(9);
                        break;
                    }

                    case 3: {
                        _localctx =
                                _tracker.createInstance<ExprContext>(parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState, RuleExpr);
                        setState(144);

                        if (!(precpred(_ctx, 7)))
                            throw FailedPredicateException(this, "precpred(_ctx, 7)");
                        setState(145);
                        match(FscParser::MOD);
                        setState(146);
                        expr(8);
                        break;
                    }

                    case 4: {
                        _localctx =
                                _tracker.createInstance<ExprContext>(parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState, RuleExpr);
                        setState(147);

                        if (!(precpred(_ctx, 6)))
                            throw FailedPredicateException(this, "precpred(_ctx, 6)");
                        setState(148);
                        match(FscParser::ADD);
                        setState(149);
                        expr(7);
                        break;
                    }

                    case 5: {
                        _localctx =
                                _tracker.createInstance<ExprContext>(parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState, RuleExpr);
                        setState(150);

                        if (!(precpred(_ctx, 5)))
                            throw FailedPredicateException(this, "precpred(_ctx, 5)");
                        setState(151);
                        match(FscParser::SUB);
                        setState(152);
                        expr(6);
                        break;
                    }

                    default:
                        break;
                }
            }
            setState(157);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
        }
    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }
    return _localctx;
}

bool FscParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex)
{
    switch (ruleIndex) {
        case 12:
            return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

        default:
            break;
    }
    return true;
}

bool FscParser::exprSempred(ExprContext *_localctx, size_t predicateIndex)
{
    switch (predicateIndex) {
        case 0:
            return precpred(_ctx, 9);
        case 1:
            return precpred(_ctx, 8);
        case 2:
            return precpred(_ctx, 7);
        case 3:
            return precpred(_ctx, 6);
        case 4:
            return precpred(_ctx, 5);

        default:
            break;
    }
    return true;
}

void FscParser::initialize()
{
    ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
