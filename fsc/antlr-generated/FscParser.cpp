
// Generated from Fsc.g4 by ANTLR 4.11.1


#include "FscVisitor.h"

#include "FscParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace
{

    struct FscParserStaticData final
    {
        FscParserStaticData(
            std::vector<std::string>
                ruleNames,
            std::vector<std::string>
                literalNames,
            std::vector<std::string>
                symbolicNames)
          : ruleNames(std::move(ruleNames))
          , literalNames(std::move(literalNames))
          , symbolicNames(std::move(symbolicNames))
          , vocabulary(this->literalNames, this->symbolicNames)
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
            std::vector<std::string>{
                "program",
                "type",
                "stmt",
                "body",
                "class",
                "if_stmt",
                "if",
                "elif",
                "else",
                "elif_def",
                "else_def",
                "function",
                "visibility",
                "function_attibutes",
                "variable_attributes",
                "argument_passing_type",
                "argument_definition",
                "parameters",
                "typed_arguments_list",
                "argument",
                "function_call",
                "function_parameter",
                "function_typed_arguments_list",
                "function_argument",
                "variable_prefix",
                "auto_variable_definition",
                "variable_definition",
                "member_variable_access",
                "method_call",
                "expr",
                "new_line",
                "stmt_end"},
            std::vector<std::string>{"",
                                     "'<'",
                                     "'>'",
                                     "'return'",
                                     "'{'",
                                     "'}'",
                                     "'class'",
                                     "'if'",
                                     "'elif'",
                                     "'else'",
                                     "'def'",
                                     "'->'",
                                     "'public'",
                                     "'private'",
                                     "'protected'",
                                     "'fileprivae'",
                                     "'in'",
                                     "'out'",
                                     "'inout'",
                                     "'('",
                                     "')'",
                                     "','",
                                     "'='",
                                     "'let'",
                                     "'var'",
                                     "':'",
                                     "'\\n'",
                                     "'.'",
                                     "'\\r'",
                                     "';'",
                                     "'as'",
                                     "",
                                     "",
                                     "",
                                     "",
                                     "",
                                     "",
                                     "'=='",
                                     "'!='",
                                     "'&&'",
                                     "'||'"},
            std::vector<std::string>{"",           "",      "",         "",           "",
                                     "",           "",      "",         "",           "",
                                     "",           "",      "",         "",           "",
                                     "",           "",      "",         "",           "",
                                     "",           "",      "",         "",           "",
                                     "",           "",      "",         "",           "",
                                     "AS",         "ADD",   "SUB",      "MUL",        "DIV",
                                     "MOD",        "DOT",   "EQUALITY", "INEQUALITY", "LOGICAL_AND",
                                     "LOGICAL_OR", "INT",   "FLOAT",    "CHAR",       "STRING",
                                     "IDENTIFIER", "LAYOUT"});
        static const int32_t serializedATNSegment[] = {
            4,   1,   46,  299, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,  2,   3,
            7,   3,   2,   4,   7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,  7,   7,
            2,   8,   7,   8,   2,   9,   7,   9,   2,   10,  7,   10,  2,   11,  7,   11, 2,   12,
            7,   12,  2,   13,  7,   13,  2,   14,  7,   14,  2,   15,  7,   15,  2,   16, 7,   16,
            2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20, 2,   21,
            7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25, 7,   25,
            2,   26,  7,   26,  2,   27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29, 2,   30,
            7,   30,  2,   31,  7,   31,  1,   0,   5,   0,   66,  8,   0,   10,  0,   12, 0,   69,
            9,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   1,   76,  8,  1,   1,
            2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,  2,   1,
            2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   3,   2,   93,  8,   2,  1,   3,
            1,   3,   5,   3,   97,  8,   3,   10,  3,   12,  3,   100, 9,   3,   1,   3,  1,   3,
            1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   5,   1,   5,   1,   5,  1,   5,
            1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   7,   5,   7,  120, 8,
            7,   10,  7,   12,  7,   123, 9,   7,   1,   8,   3,   8,   126, 8,   8,   1,  9,   1,
            9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   10,  1,   10,  1,   10,  1,  11,  1,
            11,  1,   11,  1,   11,  1,   11,  1,   11,  3,   11,  143, 8,   11,  1,   11, 1,   11,
            1,   11,  1,   12,  1,   12,  1,   13,  3,   13,  151, 8,   13,  1,   14,  3,  14,  154,
            8,   14,  1,   15,  1,   15,  1,   16,  1,   16,  1,   16,  1,   16,  1,   17, 1,   17,
            3,   17,  164, 8,   17,  1,   17,  1,   17,  1,   18,  1,   18,  1,   18,  5,  18,  171,
            8,   18,  10,  18,  12,  18,  174, 9,   18,  1,   19,  1,   19,  1,   19,  3,  19,  179,
            8,   19,  1,   20,  1,   20,  1,   20,  1,   21,  1,   21,  3,   21,  186, 8,  21,  1,
            21,  1,   21,  1,   22,  1,   22,  1,   22,  5,   22,  193, 8,   22,  10,  22, 12,  22,
            196, 9,   22,  1,   23,  1,   23,  3,   23,  200, 8,   23,  1,   23,  1,   23, 1,   24,
            1,   24,  1,   25,  1,   25,  1,   25,  1,   25,  1,   25,  1,   25,  1,   26, 1,   26,
            1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  5,   26,  219, 8,   26,  10, 26,  12,
            26,  222, 9,   26,  1,   26,  3,   26,  225, 8,   26,  1,   27,  1,   27,  1,  27,  1,
            28,  1,   28,  1,   28,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,  29,  1,
            29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  3,  29,  247,
            8,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29, 1,   29,
            1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29, 1,   29,
            1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29, 1,   29,
            1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29, 5,   29,
            283, 8,   29,  10,  29,  12,  29,  286, 9,   29,  1,   30,  5,   30,  289, 8,  30,  10,
            30,  12,  30,  292, 9,   30,  1,   31,  4,   31,  295, 8,   31,  11,  31,  12, 31,  296,
            1,   31,  0,   1,   58,  32,  0,   2,   4,   6,   8,   10,  12,  14,  16,  18, 20,  22,
            24,  26,  28,  30,  32,  34,  36,  38,  40,  42,  44,  46,  48,  50,  52,  54, 56,  58,
            60,  62,  0,   4,   1,   0,   12,  15,  1,   0,   16,  18,  1,   0,   23,  24, 2,   0,
            26,  26,  28,  29,  310, 0,   67,  1,   0,   0,   0,   2,   75,  1,   0,   0,  0,   4,
            92,  1,   0,   0,   0,   6,   94,  1,   0,   0,   0,   8,   103, 1,   0,   0,  0,   10,
            108, 1,   0,   0,   0,   12,  112, 1,   0,   0,   0,   14,  121, 1,   0,   0,  0,   16,
            125, 1,   0,   0,   0,   18,  127, 1,   0,   0,   0,   20,  133, 1,   0,   0,  0,   22,
            136, 1,   0,   0,   0,   24,  147, 1,   0,   0,   0,   26,  150, 1,   0,   0,  0,   28,
            153, 1,   0,   0,   0,   30,  155, 1,   0,   0,   0,   32,  157, 1,   0,   0,  0,   34,
            161, 1,   0,   0,   0,   36,  167, 1,   0,   0,   0,   38,  175, 1,   0,   0,  0,   40,
            180, 1,   0,   0,   0,   42,  183, 1,   0,   0,   0,   44,  189, 1,   0,   0,  0,   46,
            199, 1,   0,   0,   0,   48,  203, 1,   0,   0,   0,   50,  205, 1,   0,   0,  0,   52,
            211, 1,   0,   0,   0,   54,  226, 1,   0,   0,   0,   56,  229, 1,   0,   0,  0,   58,
            246, 1,   0,   0,   0,   60,  290, 1,   0,   0,   0,   62,  294, 1,   0,   0,  0,   64,
            66,  3,   4,   2,   0,   65,  64,  1,   0,   0,   0,   66,  69,  1,   0,   0,  0,   67,
            65,  1,   0,   0,   0,   67,  68,  1,   0,   0,   0,   68,  1,   1,   0,   0,  0,   69,
            67,  1,   0,   0,   0,   70,  76,  5,   45,  0,   0,   71,  72,  5,   45,  0,  0,   72,
            73,  5,   1,   0,   0,   73,  74,  5,   45,  0,   0,   74,  76,  5,   2,   0,  0,   75,
            70,  1,   0,   0,   0,   75,  71,  1,   0,   0,   0,   76,  3,   1,   0,   0,  0,   77,
            93,  3,   22,  11,  0,   78,  79,  3,   58,  29,  0,   79,  80,  3,   62,  31, 0,   80,
            93,  1,   0,   0,   0,   81,  82,  3,   8,   4,   0,   82,  83,  3,   62,  31, 0,   83,
            93,  1,   0,   0,   0,   84,  85,  5,   3,   0,   0,   85,  86,  3,   58,  29, 0,   86,
            87,  3,   62,  31,  0,   87,  93,  1,   0,   0,   0,   88,  89,  3,   10,  5,  0,   89,
            90,  3,   62,  31,  0,   90,  93,  1,   0,   0,   0,   91,  93,  3,   62,  31, 0,   92,
            77,  1,   0,   0,   0,   92,  78,  1,   0,   0,   0,   92,  81,  1,   0,   0,  0,   92,
            84,  1,   0,   0,   0,   92,  88,  1,   0,   0,   0,   92,  91,  1,   0,   0,  0,   93,
            5,   1,   0,   0,   0,   94,  98,  5,   4,   0,   0,   95,  97,  3,   4,   2,  0,   96,
            95,  1,   0,   0,   0,   97,  100, 1,   0,   0,   0,   98,  96,  1,   0,   0,  0,   98,
            99,  1,   0,   0,   0,   99,  101, 1,   0,   0,   0,   100, 98,  1,   0,   0,  0,   101,
            102, 5,   5,   0,   0,   102, 7,   1,   0,   0,   0,   103, 104, 5,   6,   0,  0,   104,
            105, 5,   45,  0,   0,   105, 106, 3,   60,  30,  0,   106, 107, 3,   6,   3,  0,   107,
            9,   1,   0,   0,   0,   108, 109, 3,   12,  6,   0,   109, 110, 3,   14,  7,  0,   110,
            111, 3,   16,  8,   0,   111, 11,  1,   0,   0,   0,   112, 113, 5,   7,   0,  0,   113,
            114, 3,   58,  29,  0,   114, 115, 3,   60,  30,  0,   115, 116, 3,   6,   3,  0,   116,
            117, 3,   60,  30,  0,   117, 13,  1,   0,   0,   0,   118, 120, 3,   18,  9,  0,   119,
            118, 1,   0,   0,   0,   120, 123, 1,   0,   0,   0,   121, 119, 1,   0,   0,  0,   121,
            122, 1,   0,   0,   0,   122, 15,  1,   0,   0,   0,   123, 121, 1,   0,   0,  0,   124,
            126, 3,   20,  10,  0,   125, 124, 1,   0,   0,   0,   125, 126, 1,   0,   0,  0,   126,
            17,  1,   0,   0,   0,   127, 128, 5,   8,   0,   0,   128, 129, 3,   58,  29, 0,   129,
            130, 3,   60,  30,  0,   130, 131, 3,   6,   3,   0,   131, 132, 3,   60,  30, 0,   132,
            19,  1,   0,   0,   0,   133, 134, 5,   9,   0,   0,   134, 135, 3,   6,   3,  0,   135,
            21,  1,   0,   0,   0,   136, 137, 3,   26,  13,  0,   137, 138, 5,   10,  0,  0,   138,
            139, 5,   45,  0,   0,   139, 142, 3,   34,  17,  0,   140, 141, 5,   11,  0,  0,   141,
            143, 5,   45,  0,   0,   142, 140, 1,   0,   0,   0,   142, 143, 1,   0,   0,  0,   143,
            144, 1,   0,   0,   0,   144, 145, 3,   60,  30,  0,   145, 146, 3,   6,   3,  0,   146,
            23,  1,   0,   0,   0,   147, 148, 7,   0,   0,   0,   148, 25,  1,   0,   0,  0,   149,
            151, 3,   24,  12,  0,   150, 149, 1,   0,   0,   0,   150, 151, 1,   0,   0,  0,   151,
            27,  1,   0,   0,   0,   152, 154, 3,   24,  12,  0,   153, 152, 1,   0,   0,  0,   153,
            154, 1,   0,   0,   0,   154, 29,  1,   0,   0,   0,   155, 156, 7,   1,   0,  0,   156,
            31,  1,   0,   0,   0,   157, 158, 3,   30,  15,  0,   158, 159, 5,   45,  0,  0,   159,
            160, 5,   45,  0,   0,   160, 33,  1,   0,   0,   0,   161, 163, 5,   19,  0,  0,   162,
            164, 3,   36,  18,  0,   163, 162, 1,   0,   0,   0,   163, 164, 1,   0,   0,  0,   164,
            165, 1,   0,   0,   0,   165, 166, 5,   20,  0,   0,   166, 35,  1,   0,   0,  0,   167,
            172, 3,   38,  19,  0,   168, 169, 5,   21,  0,   0,   169, 171, 3,   38,  19, 0,   170,
            168, 1,   0,   0,   0,   171, 174, 1,   0,   0,   0,   172, 170, 1,   0,   0,  0,   172,
            173, 1,   0,   0,   0,   173, 37,  1,   0,   0,   0,   174, 172, 1,   0,   0,  0,   175,
            178, 3,   32,  16,  0,   176, 177, 5,   22,  0,   0,   177, 179, 3,   58,  29, 0,   178,
            176, 1,   0,   0,   0,   178, 179, 1,   0,   0,   0,   179, 39,  1,   0,   0,  0,   180,
            181, 5,   45,  0,   0,   181, 182, 3,   42,  21,  0,   182, 41,  1,   0,   0,  0,   183,
            185, 5,   19,  0,   0,   184, 186, 3,   44,  22,  0,   185, 184, 1,   0,   0,  0,   185,
            186, 1,   0,   0,   0,   186, 187, 1,   0,   0,   0,   187, 188, 5,   20,  0,  0,   188,
            43,  1,   0,   0,   0,   189, 194, 3,   46,  23,  0,   190, 191, 5,   21,  0,  0,   191,
            193, 3,   46,  23,  0,   192, 190, 1,   0,   0,   0,   193, 196, 1,   0,   0,  0,   194,
            192, 1,   0,   0,   0,   194, 195, 1,   0,   0,   0,   195, 45,  1,   0,   0,  0,   196,
            194, 1,   0,   0,   0,   197, 198, 5,   45,  0,   0,   198, 200, 5,   22,  0,  0,   199,
            197, 1,   0,   0,   0,   199, 200, 1,   0,   0,   0,   200, 201, 1,   0,   0,  0,   201,
            202, 3,   58,  29,  0,   202, 47,  1,   0,   0,   0,   203, 204, 7,   2,   0,  0,   204,
            49,  1,   0,   0,   0,   205, 206, 3,   28,  14,  0,   206, 207, 3,   48,  24, 0,   207,
            208, 5,   45,  0,   0,   208, 209, 5,   22,  0,   0,   209, 210, 3,   58,  29, 0,   210,
            51,  1,   0,   0,   0,   211, 212, 3,   28,  14,  0,   212, 213, 3,   48,  24, 0,   213,
            214, 5,   45,  0,   0,   214, 215, 5,   25,  0,   0,   215, 224, 5,   45,  0,  0,   216,
            220, 5,   22,  0,   0,   217, 219, 5,   26,  0,   0,   218, 217, 1,   0,   0,  0,   219,
            222, 1,   0,   0,   0,   220, 218, 1,   0,   0,   0,   220, 221, 1,   0,   0,  0,   221,
            223, 1,   0,   0,   0,   222, 220, 1,   0,   0,   0,   223, 225, 3,   58,  29, 0,   224,
            216, 1,   0,   0,   0,   224, 225, 1,   0,   0,   0,   225, 53,  1,   0,   0,  0,   226,
            227, 5,   27,  0,   0,   227, 228, 5,   45,  0,   0,   228, 55,  1,   0,   0,  0,   229,
            230, 5,   27,  0,   0,   230, 231, 3,   40,  20,  0,   231, 57,  1,   0,   0,  0,   232,
            233, 6,   29,  -1,  0,   233, 247, 3,   40,  20,  0,   234, 247, 3,   52,  26, 0,   235,
            247, 3,   50,  25,  0,   236, 237, 5,   19,  0,   0,   237, 238, 3,   58,  29, 0,   238,
            239, 5,   20,  0,   0,   239, 247, 1,   0,   0,   0,   240, 247, 3,   6,   3,  0,   241,
            247, 5,   41,  0,   0,   242, 247, 5,   42,  0,   0,   243, 247, 5,   45,  0,  0,   244,
            247, 5,   44,  0,   0,   245, 247, 5,   43,  0,   0,   246, 232, 1,   0,   0,  0,   246,
            234, 1,   0,   0,   0,   246, 235, 1,   0,   0,   0,   246, 236, 1,   0,   0,  0,   246,
            240, 1,   0,   0,   0,   246, 241, 1,   0,   0,   0,   246, 242, 1,   0,   0,  0,   246,
            243, 1,   0,   0,   0,   246, 244, 1,   0,   0,   0,   246, 245, 1,   0,   0,  0,   247,
            284, 1,   0,   0,   0,   248, 249, 10,  19,  0,   0,   249, 250, 5,   33,  0,  0,   250,
            283, 3,   58,  29,  20,  251, 252, 10,  18,  0,   0,   252, 253, 5,   34,  0,  0,   253,
            283, 3,   58,  29,  19,  254, 255, 10,  17,  0,   0,   255, 256, 5,   35,  0,  0,   256,
            283, 3,   58,  29,  18,  257, 258, 10,  16,  0,   0,   258, 259, 5,   31,  0,  0,   259,
            283, 3,   58,  29,  17,  260, 261, 10,  15,  0,   0,   261, 262, 5,   32,  0,  0,   262,
            283, 3,   58,  29,  16,  263, 264, 10,  14,  0,   0,   264, 265, 5,   37,  0,  0,   265,
            283, 3,   58,  29,  15,  266, 267, 10,  13,  0,   0,   267, 268, 5,   38,  0,  0,   268,
            283, 3,   58,  29,  14,  269, 270, 10,  12,  0,   0,   270, 271, 5,   39,  0,  0,   271,
            283, 3,   58,  29,  13,  272, 273, 10,  11,  0,   0,   273, 274, 5,   40,  0,  0,   274,
            283, 3,   58,  29,  12,  275, 276, 10,  22,  0,   0,   276, 283, 3,   54,  27, 0,   277,
            278, 10,  21,  0,   0,   278, 283, 3,   56,  28,  0,   279, 280, 10,  20,  0,  0,   280,
            281, 5,   30,  0,   0,   281, 283, 5,   45,  0,   0,   282, 248, 1,   0,   0,  0,   282,
            251, 1,   0,   0,   0,   282, 254, 1,   0,   0,   0,   282, 257, 1,   0,   0,  0,   282,
            260, 1,   0,   0,   0,   282, 263, 1,   0,   0,   0,   282, 266, 1,   0,   0,  0,   282,
            269, 1,   0,   0,   0,   282, 272, 1,   0,   0,   0,   282, 275, 1,   0,   0,  0,   282,
            277, 1,   0,   0,   0,   282, 279, 1,   0,   0,   0,   283, 286, 1,   0,   0,  0,   284,
            282, 1,   0,   0,   0,   284, 285, 1,   0,   0,   0,   285, 59,  1,   0,   0,  0,   286,
            284, 1,   0,   0,   0,   287, 289, 5,   26,  0,   0,   288, 287, 1,   0,   0,  0,   289,
            292, 1,   0,   0,   0,   290, 288, 1,   0,   0,   0,   290, 291, 1,   0,   0,  0,   291,
            61,  1,   0,   0,   0,   292, 290, 1,   0,   0,   0,   293, 295, 7,   3,   0,  0,   294,
            293, 1,   0,   0,   0,   295, 296, 1,   0,   0,   0,   296, 294, 1,   0,   0,  0,   296,
            297, 1,   0,   0,   0,   297, 63,  1,   0,   0,   0,   22,  67,  75,  92,  98, 121, 125,
            142, 150, 153, 163, 172, 178, 185, 194, 199, 220, 224, 246, 282, 284, 290, 296};
        staticData->serializedATN = antlr4::atn::SerializedATNView(
            serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

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
    _interpreter = new atn::ParserATNSimulator(
        this,
        *fscParserStaticData->atn,
        fscParserStaticData->decisionToDFA,
        fscParserStaticData->sharedContextCache,
        options);
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


//----------------- ProgramContext
//------------------------------------------------------------------

FscParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::StmtContext *> FscParser::ProgramContext::stmt()
{
    return getRuleContexts<FscParser::StmtContext>();
}

FscParser::StmtContext *FscParser::ProgramContext::stmt(size_t i)
{
    return getRuleContext<FscParser::StmtContext>(i);
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
        setState(67);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 68170619090136) != 0) {
            setState(64);
            stmt();
            setState(69);
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

//----------------- TypeContext ------------------------------------------------------------------

FscParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

std::vector<tree::TerminalNode *> FscParser::TypeContext::IDENTIFIER()
{
    return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode *FscParser::TypeContext::IDENTIFIER(size_t i)
{
    return getToken(FscParser::IDENTIFIER, i);
}


size_t FscParser::TypeContext::getRuleIndex() const
{
    return FscParser::RuleType;
}


std::any FscParser::TypeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitType(this);
    else
        return visitor->visitChildren(this);
}

FscParser::TypeContext *FscParser::type()
{
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
        setState(75);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(70);
            match(FscParser::IDENTIFIER);
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(71);
            match(FscParser::IDENTIFIER);
            setState(72);
            match(FscParser::T__0);
            setState(73);
            match(FscParser::IDENTIFIER);
            setState(74);
            match(FscParser::T__1);
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

FscParser::FunctionContext *FscParser::StmtContext::function()
{
    return getRuleContext<FscParser::FunctionContext>(0);
}

FscParser::ExprContext *FscParser::StmtContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}

FscParser::Stmt_endContext *FscParser::StmtContext::stmt_end()
{
    return getRuleContext<FscParser::Stmt_endContext>(0);
}

FscParser::ClassContext *FscParser::StmtContext::class_()
{
    return getRuleContext<FscParser::ClassContext>(0);
}

FscParser::If_stmtContext *FscParser::StmtContext::if_stmt()
{
    return getRuleContext<FscParser::If_stmtContext>(0);
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
        setState(92);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(77);
            function();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(78);
            expr(0);
            setState(79);
            stmt_end();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(81);
            class_();
            setState(82);
            stmt_end();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(84);
            match(FscParser::T__2);
            setState(85);
            expr(0);
            setState(86);
            stmt_end();
            break;
        }

        case 5: {
            enterOuterAlt(_localctx, 5);
            setState(88);
            if_stmt();
            setState(89);
            stmt_end();
            break;
        }

        case 6: {
            enterOuterAlt(_localctx, 6);
            setState(91);
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
        setState(94);
        match(FscParser::T__3);
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 68170619090136) != 0) {
            setState(95);
            stmt();
            setState(100);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(101);
        match(FscParser::T__4);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ClassContext ------------------------------------------------------------------

FscParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode *FscParser::ClassContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
}

FscParser::New_lineContext *FscParser::ClassContext::new_line()
{
    return getRuleContext<FscParser::New_lineContext>(0);
}

FscParser::BodyContext *FscParser::ClassContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::ClassContext::getRuleIndex() const
{
    return FscParser::RuleClass;
}


std::any FscParser::ClassContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitClass(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ClassContext *FscParser::class_()
{
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
        setState(103);
        match(FscParser::T__5);
        setState(104);
        match(FscParser::IDENTIFIER);
        setState(105);
        new_line();
        setState(106);
        body();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- If_stmtContext
//------------------------------------------------------------------

FscParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::IfContext *FscParser::If_stmtContext::if_()
{
    return getRuleContext<FscParser::IfContext>(0);
}

FscParser::ElifContext *FscParser::If_stmtContext::elif ()
{
    return getRuleContext<FscParser::ElifContext>(0);
}

FscParser::ElseContext *FscParser::If_stmtContext::else_()
{
    return getRuleContext<FscParser::ElseContext>(0);
}


size_t FscParser::If_stmtContext::getRuleIndex() const
{
    return FscParser::RuleIf_stmt;
}


std::any FscParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitIf_stmt(this);
    else
        return visitor->visitChildren(this);
}

FscParser::If_stmtContext *FscParser::if_stmt()
{
    If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
    enterRule(_localctx, 10, FscParser::RuleIf_stmt);

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
        if_();
        setState(109);
        elif ();
        setState(110);
        else_();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

FscParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::ExprContext *FscParser::IfContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}

std::vector<FscParser::New_lineContext *> FscParser::IfContext::new_line()
{
    return getRuleContexts<FscParser::New_lineContext>();
}

FscParser::New_lineContext *FscParser::IfContext::new_line(size_t i)
{
    return getRuleContext<FscParser::New_lineContext>(i);
}

FscParser::BodyContext *FscParser::IfContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::IfContext::getRuleIndex() const
{
    return FscParser::RuleIf;
}


std::any FscParser::IfContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitIf(this);
    else
        return visitor->visitChildren(this);
}

FscParser::IfContext *FscParser::if_()
{
    IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
    enterRule(_localctx, 12, FscParser::RuleIf);

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
        match(FscParser::T__6);
        setState(113);
        expr(0);
        setState(114);
        new_line();
        setState(115);
        body();
        setState(116);
        new_line();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ElifContext ------------------------------------------------------------------

FscParser::ElifContext::ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::Elif_defContext *> FscParser::ElifContext::elif_def()
{
    return getRuleContexts<FscParser::Elif_defContext>();
}

FscParser::Elif_defContext *FscParser::ElifContext::elif_def(size_t i)
{
    return getRuleContext<FscParser::Elif_defContext>(i);
}


size_t FscParser::ElifContext::getRuleIndex() const
{
    return FscParser::RuleElif;
}


std::any FscParser::ElifContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitElif(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ElifContext *FscParser::elif ()
{
    ElifContext *_localctx = _tracker.createInstance<ElifContext>(_ctx, getState());
    enterRule(_localctx, 14, FscParser::RuleElif);
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
        setState(121);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FscParser::T__7) {
            setState(118);
            elif_def();
            setState(123);
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

//----------------- ElseContext ------------------------------------------------------------------

FscParser::ElseContext::ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Else_defContext *FscParser::ElseContext::else_def()
{
    return getRuleContext<FscParser::Else_defContext>(0);
}


size_t FscParser::ElseContext::getRuleIndex() const
{
    return FscParser::RuleElse;
}


std::any FscParser::ElseContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitElse(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ElseContext *FscParser::else_()
{
    ElseContext *_localctx = _tracker.createInstance<ElseContext>(_ctx, getState());
    enterRule(_localctx, 16, FscParser::RuleElse);
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
        setState(125);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::T__8) {
            setState(124);
            else_def();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Elif_defContext
//------------------------------------------------------------------

FscParser::Elif_defContext::Elif_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::ExprContext *FscParser::Elif_defContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}

std::vector<FscParser::New_lineContext *> FscParser::Elif_defContext::new_line()
{
    return getRuleContexts<FscParser::New_lineContext>();
}

FscParser::New_lineContext *FscParser::Elif_defContext::new_line(size_t i)
{
    return getRuleContext<FscParser::New_lineContext>(i);
}

FscParser::BodyContext *FscParser::Elif_defContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::Elif_defContext::getRuleIndex() const
{
    return FscParser::RuleElif_def;
}


std::any FscParser::Elif_defContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitElif_def(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Elif_defContext *FscParser::elif_def()
{
    Elif_defContext *_localctx = _tracker.createInstance<Elif_defContext>(_ctx, getState());
    enterRule(_localctx, 18, FscParser::RuleElif_def);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(127);
        match(FscParser::T__7);
        setState(128);
        expr(0);
        setState(129);
        new_line();
        setState(130);
        body();
        setState(131);
        new_line();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Else_defContext
//------------------------------------------------------------------

FscParser::Else_defContext::Else_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::BodyContext *FscParser::Else_defContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}


size_t FscParser::Else_defContext::getRuleIndex() const
{
    return FscParser::RuleElse_def;
}


std::any FscParser::Else_defContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitElse_def(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Else_defContext *FscParser::else_def()
{
    Else_defContext *_localctx = _tracker.createInstance<Else_defContext>(_ctx, getState());
    enterRule(_localctx, 20, FscParser::RuleElse_def);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(133);
        match(FscParser::T__8);
        setState(134);
        body();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FunctionContext
//------------------------------------------------------------------

FscParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Function_attibutesContext *FscParser::FunctionContext::function_attibutes()
{
    return getRuleContext<FscParser::Function_attibutesContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::FunctionContext::IDENTIFIER()
{
    return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode *FscParser::FunctionContext::IDENTIFIER(size_t i)
{
    return getToken(FscParser::IDENTIFIER, i);
}

FscParser::ParametersContext *FscParser::FunctionContext::parameters()
{
    return getRuleContext<FscParser::ParametersContext>(0);
}

FscParser::New_lineContext *FscParser::FunctionContext::new_line()
{
    return getRuleContext<FscParser::New_lineContext>(0);
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
    enterRule(_localctx, 22, FscParser::RuleFunction);
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
        function_attibutes();
        setState(137);
        match(FscParser::T__9);
        setState(138);
        match(FscParser::IDENTIFIER);
        setState(139);
        parameters();
        setState(142);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::T__10) {
            setState(140);
            match(FscParser::T__10);
            setState(141);
            match(FscParser::IDENTIFIER);
        }
        setState(144);
        new_line();
        setState(145);
        body();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- VisibilityContext
//------------------------------------------------------------------

FscParser::VisibilityContext::VisibilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}


size_t FscParser::VisibilityContext::getRuleIndex() const
{
    return FscParser::RuleVisibility;
}


std::any FscParser::VisibilityContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitVisibility(this);
    else
        return visitor->visitChildren(this);
}

FscParser::VisibilityContext *FscParser::visibility()
{
    VisibilityContext *_localctx = _tracker.createInstance<VisibilityContext>(_ctx, getState());
    enterRule(_localctx, 24, FscParser::RuleVisibility);
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
        _la = _input->LA(1);
        if (!(((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 61440) != 0)) {
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

//----------------- Function_attibutesContext
//------------------------------------------------------------------

FscParser::Function_attibutesContext::Function_attibutesContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::VisibilityContext *FscParser::Function_attibutesContext::visibility()
{
    return getRuleContext<FscParser::VisibilityContext>(0);
}


size_t FscParser::Function_attibutesContext::getRuleIndex() const
{
    return FscParser::RuleFunction_attibutes;
}


std::any FscParser::Function_attibutesContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction_attibutes(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Function_attibutesContext *FscParser::function_attibutes()
{
    Function_attibutesContext *_localctx =
        _tracker.createInstance<Function_attibutesContext>(_ctx, getState());
    enterRule(_localctx, 26, FscParser::RuleFunction_attibutes);
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
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 61440) != 0) {
            setState(149);
            visibility();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Variable_attributesContext
//------------------------------------------------------------------

FscParser::Variable_attributesContext::Variable_attributesContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::VisibilityContext *FscParser::Variable_attributesContext::visibility()
{
    return getRuleContext<FscParser::VisibilityContext>(0);
}


size_t FscParser::Variable_attributesContext::getRuleIndex() const
{
    return FscParser::RuleVariable_attributes;
}


std::any FscParser::Variable_attributesContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitVariable_attributes(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Variable_attributesContext *FscParser::variable_attributes()
{
    Variable_attributesContext *_localctx =
        _tracker.createInstance<Variable_attributesContext>(_ctx, getState());
    enterRule(_localctx, 28, FscParser::RuleVariable_attributes);
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
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 61440) != 0) {
            setState(152);
            visibility();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Argument_passing_typeContext
//------------------------------------------------------------------

FscParser::Argument_passing_typeContext::Argument_passing_typeContext(
    ParserRuleContext *parent,
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
        setState(155);
        _la = _input->LA(1);
        if (!(((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 458752) != 0)) {
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

//----------------- Argument_definitionContext
//------------------------------------------------------------------

FscParser::Argument_definitionContext::Argument_definitionContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Argument_passing_typeContext *
    FscParser::Argument_definitionContext::argument_passing_type()
{
    return getRuleContext<FscParser::Argument_passing_typeContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::Argument_definitionContext::IDENTIFIER()
{
    return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode *FscParser::Argument_definitionContext::IDENTIFIER(size_t i)
{
    return getToken(FscParser::IDENTIFIER, i);
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
    enterRule(_localctx, 32, FscParser::RuleArgument_definition);

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
        argument_passing_type();
        setState(158);
        match(FscParser::IDENTIFIER);
        setState(159);
        match(FscParser::IDENTIFIER);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ParametersContext
//------------------------------------------------------------------

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
    enterRule(_localctx, 34, FscParser::RuleParameters);
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
        match(FscParser::T__18);
        setState(163);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 458752) != 0) {
            setState(162);
            typed_arguments_list();
        }
        setState(165);
        match(FscParser::T__19);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Typed_arguments_listContext
//------------------------------------------------------------------

FscParser::Typed_arguments_listContext::Typed_arguments_listContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::ArgumentContext *> FscParser::Typed_arguments_listContext::argument()
{
    return getRuleContexts<FscParser::ArgumentContext>();
}

FscParser::ArgumentContext *FscParser::Typed_arguments_listContext::argument(size_t i)
{
    return getRuleContext<FscParser::ArgumentContext>(i);
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
    enterRule(_localctx, 36, FscParser::RuleTyped_arguments_list);
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
        argument();
        setState(172);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FscParser::T__20) {
            setState(168);
            match(FscParser::T__20);
            setState(169);
            argument();
            setState(174);
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

//----------------- ArgumentContext
//------------------------------------------------------------------

FscParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Argument_definitionContext *FscParser::ArgumentContext::argument_definition()
{
    return getRuleContext<FscParser::Argument_definitionContext>(0);
}

FscParser::ExprContext *FscParser::ArgumentContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}


size_t FscParser::ArgumentContext::getRuleIndex() const
{
    return FscParser::RuleArgument;
}


std::any FscParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitArgument(this);
    else
        return visitor->visitChildren(this);
}

FscParser::ArgumentContext *FscParser::argument()
{
    ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
    enterRule(_localctx, 38, FscParser::RuleArgument);
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
        setState(175);
        argument_definition();
        setState(178);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FscParser::T__21) {
            setState(176);
            match(FscParser::T__21);
            setState(177);
            expr(0);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Function_callContext
//------------------------------------------------------------------

FscParser::Function_callContext::Function_callContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode *FscParser::Function_callContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
}

FscParser::Function_parameterContext *FscParser::Function_callContext::function_parameter()
{
    return getRuleContext<FscParser::Function_parameterContext>(0);
}


size_t FscParser::Function_callContext::getRuleIndex() const
{
    return FscParser::RuleFunction_call;
}


std::any FscParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction_call(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Function_callContext *FscParser::function_call()
{
    Function_callContext *_localctx =
        _tracker.createInstance<Function_callContext>(_ctx, getState());
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
        setState(180);
        match(FscParser::IDENTIFIER);
        setState(181);
        function_parameter();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Function_parameterContext
//------------------------------------------------------------------

FscParser::Function_parameterContext::Function_parameterContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Function_typed_arguments_listContext *
    FscParser::Function_parameterContext::function_typed_arguments_list()
{
    return getRuleContext<FscParser::Function_typed_arguments_listContext>(0);
}


size_t FscParser::Function_parameterContext::getRuleIndex() const
{
    return FscParser::RuleFunction_parameter;
}


std::any FscParser::Function_parameterContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction_parameter(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Function_parameterContext *FscParser::function_parameter()
{
    Function_parameterContext *_localctx =
        _tracker.createInstance<Function_parameterContext>(_ctx, getState());
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
        setState(183);
        match(FscParser::T__18);
        setState(185);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 68169746673680) != 0) {
            setState(184);
            function_typed_arguments_list();
        }
        setState(187);
        match(FscParser::T__19);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Function_typed_arguments_listContext
//------------------------------------------------------------------

FscParser::Function_typed_arguments_listContext::Function_typed_arguments_listContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

std::vector<FscParser::Function_argumentContext *>
    FscParser::Function_typed_arguments_listContext::function_argument()
{
    return getRuleContexts<FscParser::Function_argumentContext>();
}

FscParser::Function_argumentContext *
    FscParser::Function_typed_arguments_listContext::function_argument(size_t i)
{
    return getRuleContext<FscParser::Function_argumentContext>(i);
}


size_t FscParser::Function_typed_arguments_listContext::getRuleIndex() const
{
    return FscParser::RuleFunction_typed_arguments_list;
}


std::any FscParser::Function_typed_arguments_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction_typed_arguments_list(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Function_typed_arguments_listContext *FscParser::function_typed_arguments_list()
{
    Function_typed_arguments_listContext *_localctx =
        _tracker.createInstance<Function_typed_arguments_listContext>(_ctx, getState());
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
        setState(189);
        function_argument();
        setState(194);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FscParser::T__20) {
            setState(190);
            match(FscParser::T__20);
            setState(191);
            function_argument();
            setState(196);
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

//----------------- Function_argumentContext
//------------------------------------------------------------------

FscParser::Function_argumentContext::Function_argumentContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::ExprContext *FscParser::Function_argumentContext::expr()
{
    return getRuleContext<FscParser::ExprContext>(0);
}

tree::TerminalNode *FscParser::Function_argumentContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
}


size_t FscParser::Function_argumentContext::getRuleIndex() const
{
    return FscParser::RuleFunction_argument;
}


std::any FscParser::Function_argumentContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitFunction_argument(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Function_argumentContext *FscParser::function_argument()
{
    Function_argumentContext *_localctx =
        _tracker.createInstance<Function_argumentContext>(_ctx, getState());
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
        setState(199);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
            setState(197);
            match(FscParser::IDENTIFIER);
            setState(198);
            match(FscParser::T__21);
            break;
        }

        default:
            break;
        }
        setState(201);
        expr(0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Variable_prefixContext
//------------------------------------------------------------------

FscParser::Variable_prefixContext::Variable_prefixContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}


size_t FscParser::Variable_prefixContext::getRuleIndex() const
{
    return FscParser::RuleVariable_prefix;
}


std::any FscParser::Variable_prefixContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitVariable_prefix(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Variable_prefixContext *FscParser::variable_prefix()
{
    Variable_prefixContext *_localctx =
        _tracker.createInstance<Variable_prefixContext>(_ctx, getState());
    enterRule(_localctx, 48, FscParser::RuleVariable_prefix);
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
        setState(203);
        _la = _input->LA(1);
        if (!(_la == FscParser::T__22

              || _la == FscParser::T__23)) {
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

//----------------- Auto_variable_definitionContext
//------------------------------------------------------------------

FscParser::Auto_variable_definitionContext::Auto_variable_definitionContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Variable_attributesContext *
    FscParser::Auto_variable_definitionContext::variable_attributes()
{
    return getRuleContext<FscParser::Variable_attributesContext>(0);
}

FscParser::Variable_prefixContext *FscParser::Auto_variable_definitionContext::variable_prefix()
{
    return getRuleContext<FscParser::Variable_prefixContext>(0);
}

tree::TerminalNode *FscParser::Auto_variable_definitionContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
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
        setState(205);
        variable_attributes();
        setState(206);
        variable_prefix();
        setState(207);
        match(FscParser::IDENTIFIER);
        setState(208);
        match(FscParser::T__21);
        setState(209);
        expr(0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Variable_definitionContext
//------------------------------------------------------------------

FscParser::Variable_definitionContext::Variable_definitionContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Variable_attributesContext *FscParser::Variable_definitionContext::variable_attributes()
{
    return getRuleContext<FscParser::Variable_attributesContext>(0);
}

FscParser::Variable_prefixContext *FscParser::Variable_definitionContext::variable_prefix()
{
    return getRuleContext<FscParser::Variable_prefixContext>(0);
}

std::vector<tree::TerminalNode *> FscParser::Variable_definitionContext::IDENTIFIER()
{
    return getTokens(FscParser::IDENTIFIER);
}

tree::TerminalNode *FscParser::Variable_definitionContext::IDENTIFIER(size_t i)
{
    return getToken(FscParser::IDENTIFIER, i);
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
    enterRule(_localctx, 52, FscParser::RuleVariable_definition);
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
        setState(211);
        variable_attributes();
        setState(212);
        variable_prefix();
        setState(213);
        match(FscParser::IDENTIFIER);
        setState(214);
        match(FscParser::T__24);
        setState(215);
        match(FscParser::IDENTIFIER);
        setState(224);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
            setState(216);
            match(FscParser::T__21);
            setState(220);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == FscParser::T__25) {
                setState(217);
                match(FscParser::T__25);
                setState(222);
                _errHandler->sync(this);
                _la = _input->LA(1);
            }
            setState(223);
            expr(0);
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

//----------------- Member_variable_accessContext
//------------------------------------------------------------------

FscParser::Member_variable_accessContext::Member_variable_accessContext(
    ParserRuleContext *parent,
    size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode *FscParser::Member_variable_accessContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
}


size_t FscParser::Member_variable_accessContext::getRuleIndex() const
{
    return FscParser::RuleMember_variable_access;
}


std::any FscParser::Member_variable_accessContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitMember_variable_access(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Member_variable_accessContext *FscParser::member_variable_access()
{
    Member_variable_accessContext *_localctx =
        _tracker.createInstance<Member_variable_accessContext>(_ctx, getState());
    enterRule(_localctx, 54, FscParser::RuleMember_variable_access);

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
        match(FscParser::T__26);
        setState(227);
        match(FscParser::IDENTIFIER);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Method_callContext
//------------------------------------------------------------------

FscParser::Method_callContext::Method_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}

FscParser::Function_callContext *FscParser::Method_callContext::function_call()
{
    return getRuleContext<FscParser::Function_callContext>(0);
}


size_t FscParser::Method_callContext::getRuleIndex() const
{
    return FscParser::RuleMethod_call;
}


std::any FscParser::Method_callContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitMethod_call(this);
    else
        return visitor->visitChildren(this);
}

FscParser::Method_callContext *FscParser::method_call()
{
    Method_callContext *_localctx = _tracker.createInstance<Method_callContext>(_ctx, getState());
    enterRule(_localctx, 56, FscParser::RuleMethod_call);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(229);
        match(FscParser::T__26);
        setState(230);
        function_call();

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

FscParser::Function_callContext *FscParser::ExprContext::function_call()
{
    return getRuleContext<FscParser::Function_callContext>(0);
}

FscParser::Variable_definitionContext *FscParser::ExprContext::variable_definition()
{
    return getRuleContext<FscParser::Variable_definitionContext>(0);
}

FscParser::Auto_variable_definitionContext *FscParser::ExprContext::auto_variable_definition()
{
    return getRuleContext<FscParser::Auto_variable_definitionContext>(0);
}

std::vector<FscParser::ExprContext *> FscParser::ExprContext::expr()
{
    return getRuleContexts<FscParser::ExprContext>();
}

FscParser::ExprContext *FscParser::ExprContext::expr(size_t i)
{
    return getRuleContext<FscParser::ExprContext>(i);
}

FscParser::BodyContext *FscParser::ExprContext::body()
{
    return getRuleContext<FscParser::BodyContext>(0);
}

tree::TerminalNode *FscParser::ExprContext::INT()
{
    return getToken(FscParser::INT, 0);
}

tree::TerminalNode *FscParser::ExprContext::FLOAT()
{
    return getToken(FscParser::FLOAT, 0);
}

tree::TerminalNode *FscParser::ExprContext::IDENTIFIER()
{
    return getToken(FscParser::IDENTIFIER, 0);
}

tree::TerminalNode *FscParser::ExprContext::STRING()
{
    return getToken(FscParser::STRING, 0);
}

tree::TerminalNode *FscParser::ExprContext::CHAR()
{
    return getToken(FscParser::CHAR, 0);
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

tree::TerminalNode *FscParser::ExprContext::EQUALITY()
{
    return getToken(FscParser::EQUALITY, 0);
}

tree::TerminalNode *FscParser::ExprContext::INEQUALITY()
{
    return getToken(FscParser::INEQUALITY, 0);
}

tree::TerminalNode *FscParser::ExprContext::LOGICAL_AND()
{
    return getToken(FscParser::LOGICAL_AND, 0);
}

tree::TerminalNode *FscParser::ExprContext::LOGICAL_OR()
{
    return getToken(FscParser::LOGICAL_OR, 0);
}

FscParser::Member_variable_accessContext *FscParser::ExprContext::member_variable_access()
{
    return getRuleContext<FscParser::Member_variable_accessContext>(0);
}

FscParser::Method_callContext *FscParser::ExprContext::method_call()
{
    return getRuleContext<FscParser::Method_callContext>(0);
}

tree::TerminalNode *FscParser::ExprContext::AS()
{
    return getToken(FscParser::AS, 0);
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
    (void)previousContext;// Silence compiler, in case the context is not used by generated code.
    size_t startState = 58;
    enterRecursionRule(_localctx, 58, FscParser::RuleExpr, precedence);


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
        setState(246);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
            setState(233);
            function_call();
            break;
        }

        case 2: {
            setState(234);
            variable_definition();
            break;
        }

        case 3: {
            setState(235);
            auto_variable_definition();
            break;
        }

        case 4: {
            setState(236);
            match(FscParser::T__18);
            setState(237);
            expr(0);
            setState(238);
            match(FscParser::T__19);
            break;
        }

        case 5: {
            setState(240);
            body();
            break;
        }

        case 6: {
            setState(241);
            match(FscParser::INT);
            break;
        }

        case 7: {
            setState(242);
            match(FscParser::FLOAT);
            break;
        }

        case 8: {
            setState(243);
            match(FscParser::IDENTIFIER);
            break;
        }

        case 9: {
            setState(244);
            match(FscParser::STRING);
            break;
        }

        case 10: {
            setState(245);
            match(FscParser::CHAR);
            break;
        }

        default:
            break;
        }
        _ctx->stop = _input->LT(-1);
        setState(284);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                if (!_parseListeners.empty())
                    triggerExitRuleEvent();
                previousContext = _localctx;
                setState(282);
                _errHandler->sync(this);
                switch (
                    getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
                case 1: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(248);

                    if (!(precpred(_ctx, 19)))
                        throw FailedPredicateException(this, "precpred(_ctx, 19)");
                    setState(249);
                    match(FscParser::MUL);
                    setState(250);
                    expr(20);
                    break;
                }

                case 2: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(251);

                    if (!(precpred(_ctx, 18)))
                        throw FailedPredicateException(this, "precpred(_ctx, 18)");
                    setState(252);
                    match(FscParser::DIV);
                    setState(253);
                    expr(19);
                    break;
                }

                case 3: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(254);

                    if (!(precpred(_ctx, 17)))
                        throw FailedPredicateException(this, "precpred(_ctx, 17)");
                    setState(255);
                    match(FscParser::MOD);
                    setState(256);
                    expr(18);
                    break;
                }

                case 4: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(257);

                    if (!(precpred(_ctx, 16)))
                        throw FailedPredicateException(this, "precpred(_ctx, 16)");
                    setState(258);
                    match(FscParser::ADD);
                    setState(259);
                    expr(17);
                    break;
                }

                case 5: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(260);

                    if (!(precpred(_ctx, 15)))
                        throw FailedPredicateException(this, "precpred(_ctx, 15)");
                    setState(261);
                    match(FscParser::SUB);
                    setState(262);
                    expr(16);
                    break;
                }

                case 6: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(263);

                    if (!(precpred(_ctx, 14)))
                        throw FailedPredicateException(this, "precpred(_ctx, 14)");
                    setState(264);
                    match(FscParser::EQUALITY);
                    setState(265);
                    expr(15);
                    break;
                }

                case 7: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(266);

                    if (!(precpred(_ctx, 13)))
                        throw FailedPredicateException(this, "precpred(_ctx, 13)");
                    setState(267);
                    match(FscParser::INEQUALITY);
                    setState(268);
                    expr(14);
                    break;
                }

                case 8: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(269);

                    if (!(precpred(_ctx, 12)))
                        throw FailedPredicateException(this, "precpred(_ctx, 12)");
                    setState(270);
                    match(FscParser::LOGICAL_AND);
                    setState(271);
                    expr(13);
                    break;
                }

                case 9: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(272);

                    if (!(precpred(_ctx, 11)))
                        throw FailedPredicateException(this, "precpred(_ctx, 11)");
                    setState(273);
                    match(FscParser::LOGICAL_OR);
                    setState(274);
                    expr(12);
                    break;
                }

                case 10: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(275);

                    if (!(precpred(_ctx, 22)))
                        throw FailedPredicateException(this, "precpred(_ctx, 22)");
                    setState(276);
                    member_variable_access();
                    break;
                }

                case 11: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(277);

                    if (!(precpred(_ctx, 21)))
                        throw FailedPredicateException(this, "precpred(_ctx, 21)");
                    setState(278);
                    method_call();
                    break;
                }

                case 12: {
                    _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
                    pushNewRecursionContext(_localctx, startState, RuleExpr);
                    setState(279);

                    if (!(precpred(_ctx, 20)))
                        throw FailedPredicateException(this, "precpred(_ctx, 20)");
                    setState(280);
                    match(FscParser::AS);
                    setState(281);
                    match(FscParser::IDENTIFIER);
                    break;
                }

                default:
                    break;
                }
            }
            setState(286);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        }
    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }
    return _localctx;
}

//----------------- New_lineContext
//------------------------------------------------------------------

FscParser::New_lineContext::New_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState)
{}


size_t FscParser::New_lineContext::getRuleIndex() const
{
    return FscParser::RuleNew_line;
}


std::any FscParser::New_lineContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<FscVisitor *>(visitor))
        return parserVisitor->visitNew_line(this);
    else
        return visitor->visitChildren(this);
}

FscParser::New_lineContext *FscParser::new_line()
{
    New_lineContext *_localctx = _tracker.createInstance<New_lineContext>(_ctx, getState());
    enterRule(_localctx, 60, FscParser::RuleNew_line);

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
        setState(290);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(287);
                match(FscParser::T__25);
            }
            setState(292);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Stmt_endContext
//------------------------------------------------------------------

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
    enterRule(_localctx, 62, FscParser::RuleStmt_end);
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
        setState(294);
        _errHandler->sync(this);
        alt = 1;
        do {
            switch (alt) {
            case 1: {
                setState(293);
                _la = _input->LA(1);
                if (!(((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 872415232) != 0)) {
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
            setState(296);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);

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
    case 29:
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
        return precpred(_ctx, 19);
    case 1:
        return precpred(_ctx, 18);
    case 2:
        return precpred(_ctx, 17);
    case 3:
        return precpred(_ctx, 16);
    case 4:
        return precpred(_ctx, 15);
    case 5:
        return precpred(_ctx, 14);
    case 6:
        return precpred(_ctx, 13);
    case 7:
        return precpred(_ctx, 12);
    case 8:
        return precpred(_ctx, 11);
    case 9:
        return precpred(_ctx, 22);
    case 10:
        return precpred(_ctx, 21);
    case 11:
        return precpred(_ctx, 20);

    default:
        break;
    }
    return true;
}

void FscParser::initialize()
{
    ::antlr4::internal::call_once(fscParserOnceFlag, fscParserInitialize);
}
