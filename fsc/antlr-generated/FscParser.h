
// Generated from Fsc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  FscParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, ADD = 16, SUB = 17, MUL = 18, DIV = 19, MOD = 20, IF = 21, 
    FOR = 22, WHILE = 23, FUNC = 24, RETURN = 25, INT = 26, FLOAT = 27, 
    NAME = 28, LAYOUT = 29
  };

  enum {
    RuleProgram = 0, RuleGlobal_stmt = 1, RuleStmt = 2, RuleStmt_end = 3, 
    RuleFunction = 4, RuleArgument_definition = 5, RuleArgument_passing_type = 6, 
    RuleParameters = 7, RuleTyped_arguments_list = 8, RuleFunction_call = 9, 
    RuleFunction_parameter = 10, RuleFunction_typed_arguments_list = 11, 
    RuleVariable_definition = 12, RuleAuto_variable_definition = 13, RuleBody = 14, 
    RuleExpr = 15
  };

  explicit FscParser(antlr4::TokenStream *input);

  FscParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FscParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class Global_stmtContext;
  class StmtContext;
  class Stmt_endContext;
  class FunctionContext;
  class Argument_definitionContext;
  class Argument_passing_typeContext;
  class ParametersContext;
  class Typed_arguments_listContext;
  class Function_callContext;
  class Function_parameterContext;
  class Function_typed_arguments_listContext;
  class Variable_definitionContext;
  class Auto_variable_definitionContext;
  class BodyContext;
  class ExprContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Global_stmtContext *> global_stmt();
    Global_stmtContext* global_stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Global_stmtContext : public antlr4::ParserRuleContext {
  public:
    Global_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    Variable_definitionContext *variable_definition();
    Stmt_endContext *stmt_end();
    Auto_variable_definitionContext *auto_variable_definition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_stmtContext* global_stmt();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Stmt_endContext *stmt_end();
    antlr4::tree::TerminalNode *RETURN();
    Variable_definitionContext *variable_definition();
    Auto_variable_definitionContext *auto_variable_definition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  Stmt_endContext : public antlr4::ParserRuleContext {
  public:
    Stmt_endContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stmt_endContext* stmt_end();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    ParametersContext *parameters();
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  Argument_definitionContext : public antlr4::ParserRuleContext {
  public:
    Argument_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    Argument_passing_typeContext *argument_passing_type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_definitionContext* argument_definition();

  class  Argument_passing_typeContext : public antlr4::ParserRuleContext {
  public:
    Argument_passing_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_passing_typeContext* argument_passing_type();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Typed_arguments_listContext *typed_arguments_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  Typed_arguments_listContext : public antlr4::ParserRuleContext {
  public:
    Typed_arguments_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Argument_definitionContext *> argument_definition();
    Argument_definitionContext* argument_definition(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typed_arguments_listContext* typed_arguments_list();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    Function_parameterContext *function_parameter();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  Function_parameterContext : public antlr4::ParserRuleContext {
  public:
    Function_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_typed_arguments_listContext *function_typed_arguments_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_parameterContext* function_parameter();

  class  Function_typed_arguments_listContext : public antlr4::ParserRuleContext {
  public:
    Function_typed_arguments_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_typed_arguments_listContext* function_typed_arguments_list();

  class  Variable_definitionContext : public antlr4::ParserRuleContext {
  public:
    Variable_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_definitionContext* variable_definition();

  class  Auto_variable_definitionContext : public antlr4::ParserRuleContext {
  public:
    Auto_variable_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Auto_variable_definitionContext* auto_variable_definition();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BodyContext* body();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_callContext *function_call();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

