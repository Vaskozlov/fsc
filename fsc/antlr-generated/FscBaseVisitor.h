
// Generated from Fsc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "FscVisitor.h"


/**
 * This class provides an empty implementation of FscVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FscBaseVisitor : public FscVisitor {
public:

  virtual std::any visitProgram(FscParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_stmt(FscParser::Global_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(FscParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_end(FscParser::Stmt_endContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(FscParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument_definition(FscParser::Argument_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument_passing_type(FscParser::Argument_passing_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(FscParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyped_arguments_list(FscParser::Typed_arguments_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call(FscParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_parameter(FscParser::Function_parameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_typed_arguments_list(FscParser::Function_typed_arguments_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_definition(FscParser::Variable_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(FscParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(FscParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

