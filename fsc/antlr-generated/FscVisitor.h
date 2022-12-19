
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

    virtual std::any visitType(FscParser::TypeContext *context) = 0;

    virtual std::any visitStmt(FscParser::StmtContext *context) = 0;

    virtual std::any visitBody(FscParser::BodyContext *context) = 0;

    virtual std::any visitClass(FscParser::ClassContext *context) = 0;

    virtual std::any visitIf_stmt(FscParser::If_stmtContext *context) = 0;

    virtual std::any visitIf(FscParser::IfContext *context) = 0;

    virtual std::any visitElif(FscParser::ElifContext *context) = 0;

    virtual std::any visitElse(FscParser::ElseContext *context) = 0;

    virtual std::any visitElif_def(FscParser::Elif_defContext *context) = 0;

    virtual std::any visitElse_def(FscParser::Else_defContext *context) = 0;

    virtual std::any visitFunction(FscParser::FunctionContext *context) = 0;

    virtual std::any visitVisibility(FscParser::VisibilityContext *context) = 0;

    virtual std::any visitFunction_attibutes(FscParser::Function_attibutesContext *context) = 0;

    virtual std::any visitVariable_attributes(FscParser::Variable_attributesContext *context) = 0;

    virtual std::any visitArgument_passing_type(FscParser::Argument_passing_typeContext *context) = 0;

    virtual std::any visitArgument_definition(FscParser::Argument_definitionContext *context) = 0;

    virtual std::any visitParameters(FscParser::ParametersContext *context) = 0;

    virtual std::any visitTyped_arguments_list(FscParser::Typed_arguments_listContext *context) = 0;

    virtual std::any visitArgument(FscParser::ArgumentContext *context) = 0;

    virtual std::any visitFunction_call(FscParser::Function_callContext *context) = 0;

    virtual std::any visitFunction_parameter(FscParser::Function_parameterContext *context) = 0;

    virtual std::any visitFunction_typed_arguments_list(FscParser::Function_typed_arguments_listContext *context) = 0;

    virtual std::any visitFunction_argument(FscParser::Function_argumentContext *context) = 0;

    virtual std::any visitVariable_prefix(FscParser::Variable_prefixContext *context) = 0;

    virtual std::any visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *context) = 0;

    virtual std::any visitVariable_definition(FscParser::Variable_definitionContext *context) = 0;

    virtual std::any visitMember_variable_access(FscParser::Member_variable_accessContext *context) = 0;

    virtual std::any visitMethod_call(FscParser::Method_callContext *context) = 0;

    virtual std::any visitExpr(FscParser::ExprContext *context) = 0;

    virtual std::any visitNew_line(FscParser::New_lineContext *context) = 0;

    virtual std::any visitStmt_end(FscParser::Stmt_endContext *context) = 0;


};

