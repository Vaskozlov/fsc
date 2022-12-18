
// Generated from Fsc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  FscParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, AS = 28, ADD = 29, SUB = 30, MUL = 31, DIV = 32, MOD = 33, 
    DOT = 34, EQUALITY = 35, INEQUALITY = 36, LOGICAL_AND = 37, LOGICAL_OR = 38, 
    INT = 39, FLOAT = 40, CHAR = 41, STRING = 42, NAME = 43, LAYOUT = 44
  };

  enum {
    RuleProgram = 0, RuleStmt = 1, RuleIf_stmt = 2, RuleIf = 3, RuleElif = 4, 
    RuleElse = 5, RuleElif_def = 6, RuleElse_def = 7, RuleNew_line = 8, 
    RuleStmt_end = 9, RuleFunction = 10, RuleVisibility = 11, RuleFunction_attibutes = 12, 
    RuleVariable_attributes = 13, RuleArgument_definition = 14, RuleArgument_passing_type = 15, 
    RuleParameters = 16, RuleTyped_arguments_list = 17, RuleArgument = 18, 
    RuleClass = 19, RuleFunction_call = 20, RuleFunction_parameter = 21, 
    RuleFunction_typed_arguments_list = 22, RuleFunction_argument = 23, 
    RuleVariable_definition = 24, RuleAuto_variable_definition = 25, RuleVariable_prefix = 26, 
    RuleBody = 27, RuleExpr = 28
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
  class StmtContext;
  class If_stmtContext;
  class IfContext;
  class ElifContext;
  class ElseContext;
  class Elif_defContext;
  class Else_defContext;
  class New_lineContext;
  class Stmt_endContext;
  class FunctionContext;
  class VisibilityContext;
  class Function_attibutesContext;
  class Variable_attributesContext;
  class Argument_definitionContext;
  class Argument_passing_typeContext;
  class ParametersContext;
  class Typed_arguments_listContext;
  class ArgumentContext;
  class ClassContext;
  class Function_callContext;
  class Function_parameterContext;
  class Function_typed_arguments_listContext;
  class Function_argumentContext;
  class Variable_definitionContext;
  class Auto_variable_definitionContext;
  class Variable_prefixContext;
  class BodyContext;
  class ExprContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    ExprContext *expr();
    Stmt_endContext *stmt_end();
    ClassContext *class_();
    If_stmtContext *if_stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfContext *if_();
    ElifContext *elif();
    ElseContext *else_();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_stmtContext* if_stmt();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<New_lineContext *> new_line();
    New_lineContext* new_line(size_t i);
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfContext* if_();

  class  ElifContext : public antlr4::ParserRuleContext {
  public:
    ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Elif_defContext *> elif_def();
    Elif_defContext* elif_def(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElifContext* elif();

  class  ElseContext : public antlr4::ParserRuleContext {
  public:
    ElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Else_defContext *else_def();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElseContext* else_();

  class  Elif_defContext : public antlr4::ParserRuleContext {
  public:
    Elif_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<New_lineContext *> new_line();
    New_lineContext* new_line(size_t i);
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elif_defContext* elif_def();

  class  Else_defContext : public antlr4::ParserRuleContext {
  public:
    Else_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_defContext* else_def();

  class  New_lineContext : public antlr4::ParserRuleContext {
  public:
    New_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  New_lineContext* new_line();

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
    Function_attibutesContext *function_attibutes();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    ParametersContext *parameters();
    New_lineContext *new_line();
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  VisibilityContext : public antlr4::ParserRuleContext {
  public:
    VisibilityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VisibilityContext* visibility();

  class  Function_attibutesContext : public antlr4::ParserRuleContext {
  public:
    Function_attibutesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VisibilityContext *visibility();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_attibutesContext* function_attibutes();

  class  Variable_attributesContext : public antlr4::ParserRuleContext {
  public:
    Variable_attributesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VisibilityContext *visibility();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_attributesContext* variable_attributes();

  class  Argument_definitionContext : public antlr4::ParserRuleContext {
  public:
    Argument_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Argument_passing_typeContext *argument_passing_type();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);


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
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typed_arguments_listContext* typed_arguments_list();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Argument_definitionContext *argument_definition();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  ClassContext : public antlr4::ParserRuleContext {
  public:
    ClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    New_lineContext *new_line();
    BodyContext *body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassContext* class_();

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
    std::vector<Function_argumentContext *> function_argument();
    Function_argumentContext* function_argument(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_typed_arguments_listContext* function_typed_arguments_list();

  class  Function_argumentContext : public antlr4::ParserRuleContext {
  public:
    Function_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *NAME();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_argumentContext* function_argument();

  class  Variable_definitionContext : public antlr4::ParserRuleContext {
  public:
    Variable_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_attributesContext *variable_attributes();
    Variable_prefixContext *variable_prefix();
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
    Variable_attributesContext *variable_attributes();
    Variable_prefixContext *variable_prefix();
    antlr4::tree::TerminalNode *NAME();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Auto_variable_definitionContext* auto_variable_definition();

  class  Variable_prefixContext : public antlr4::ParserRuleContext {
  public:
    Variable_prefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_prefixContext* variable_prefix();

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
    Variable_definitionContext *variable_definition();
    Auto_variable_definitionContext *auto_variable_definition();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    BodyContext *body();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *EQUALITY();
    antlr4::tree::TerminalNode *INEQUALITY();
    antlr4::tree::TerminalNode *LOGICAL_AND();
    antlr4::tree::TerminalNode *LOGICAL_OR();
    antlr4::tree::TerminalNode *AS();


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

