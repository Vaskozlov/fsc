
// Generated from Fsc.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "FscParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FscParser.
 */
class  FscVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FscParser.
   */
    virtual std::any visitProgram(FscParser::ProgramContext *context) = 0;

    virtual std::any visitGlobal_stmt(FscParser::Global_stmtContext *context) = 0;

    virtual std::any visitStmt(FscParser::StmtContext *context) = 0;

    virtual std::any visitStmt_end(FscParser::Stmt_endContext *context) = 0;

    virtual std::any visitFunction(FscParser::FunctionContext *context) = 0;

    virtual std::any visitArgument_definition(FscParser::Argument_definitionContext *context) = 0;

    virtual std::any visitArgument_passing_type(FscParser::Argument_passing_typeContext *context) = 0;

    virtual std::any visitParameters(FscParser::ParametersContext *context) = 0;

    virtual std::any visitTyped_arguments_list(FscParser::Typed_arguments_listContext *context) = 0;

    virtual std::any visitFunction_call(FscParser::Function_callContext *context) = 0;

    virtual std::any visitFunction_parameter(FscParser::Function_parameterContext *context) = 0;

    virtual std::any visitFunction_typed_arguments_list(FscParser::Function_typed_arguments_listContext *context) = 0;

    virtual std::any visitVariable_definition(FscParser::Variable_definitionContext *context) = 0;

    virtual std::any visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *context) = 0;

    virtual std::any visitBody(FscParser::BodyContext *context) = 0;

    virtual std::any visitExpr(FscParser::ExprContext *context) = 0;


};

