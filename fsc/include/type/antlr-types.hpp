#ifndef FSC_ANTLR_TYPES_HPP
#define FSC_ANTLR_TYPES_HPP

#include <FscParser.h>

namespace fsc
{
    using BasicContextPtr = antlr4::ParserRuleContext *;

    using FunctionContext = FscParser::FunctionContext;
    using ParametersContext = FscParser::ParametersContext;
    using TemplateContext = FscParser::Function_templatesContext;
    using FunctionAttributeContext = FscParser::Function_attibutesContext;
    using FunctionTypedArgumentsListContext = FscParser::Function_typed_arguments_listContext;

    using FunctionCallContext = FscParser::Function_callContext;
    using FunctionArgumentContext = FscParser::Function_argumentContext;
    using FunctionParameterContext = FscParser::Function_parameterContext;

    using ExpressionContext = FscParser::ExprContext;
    using StatementContext = FscParser::StmtContext;
    using ProgramContext = FscParser::ProgramContext;
    using ClassContext = FscParser::ClassContext;

    using BodyContext = FscParser::BodyContext;
    using WhileContext = FscParser::While_loopContext;

    using IfContext = FscParser::IfContext;
    using ElifContext = FscParser::ElifContext;
    using ElseContext = FscParser::ElseContext;
    using IfStatementContext = FscParser::If_stmtContext;

    using VariableDefinitionContext = FscParser::Variable_definitionContext;
    using AutoVariableDefinitionContext = FscParser::Auto_variable_definitionContext;
}// namespace fsc

#endif /* FSC_ANTLR_TYPES_HPP */
