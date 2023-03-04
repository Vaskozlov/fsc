
// Generated from Fsc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  FscLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, AS = 28, ADD = 29, SUB = 30, MUL = 31, DIV = 32, MOD = 33, 
    DOT = 34, ASSIGN_ADD = 35, ASSIGN_SUB = 36, ASSIGN_MUL = 37, ASSIGN_DIV = 38, 
    ASSIGN_MOD = 39, ASSIGN = 40, LESS = 41, GREATER = 42, LESS_EQ = 43, 
    GREATER_EQ = 44, EQUALITY = 45, INEQUALITY = 46, LOGICAL_AND = 47, LOGICAL_OR = 48, 
    TRUE = 49, FALSE = 50, INT = 51, FLOAT = 52, CHAR = 53, STRING = 54, 
    IDENTIFIER = 55, LAYOUT = 56
  };

  explicit FscLexer(antlr4::CharStream *input);

  ~FscLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

