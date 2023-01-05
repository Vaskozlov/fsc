grammar Fsc;

AS          : 'as';
ADD         : [+];
SUB         : [-];
MUL         : [*];
DIV         : [/];
MOD         : [%];
DOT         : [.];

ASSIGN      : '=';
LESS        : '<';
GREATER     : '>';
LESS_EQ     : '<=';
GREATER_EQ  : '>=';
EQUALITY    : '==';
INEQUALITY  : '!=';
LOGICAL_AND : '&&';
LOGICAL_OR  : '||';

TRUE        :   'true';
FALSE       :   'false';
INT         :   [0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
FLOAT       :   [0-9]*[.][0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
CHAR        :   '\'' (~["\\\r\n] | '\\' (. | EOF)) '\'';
STRING      :   '"' (~["\\\r\n] | '\\' (. | EOF))* '"';
IDENTIFIER  :   [a-zA-Z_][a-zA-Z0-9_]*;

LAYOUT  : [ \t] -> skip;

program: (stmt)*;

type:   IDENTIFIER
    |   IDENTIFIER LESS templated_types GREATER;

templated_types: type (',' type)*;

stmt:   function
    |   expr stmt_end
    |   class stmt_end
    |   'return' expr stmt_end
    |   if_stmt stmt_end
    |   while_loop stmt_end
    |   stmt_end
    ;

body: '{' (stmt)* '}';
class: 'class' IDENTIFIER new_line body;

while_loop: 'while' new_line expr new_line body;

if_stmt: if elif else;
if: 'if' expr new_line body new_line;
elif: elif_def*;
else: else_def?;

elif_def: 'elif' expr new_line body new_line;
else_def: 'else' body;

function: function_attibutes 'func' IDENTIFIER function_templates parameters ('->' IDENTIFIER) ? new_line body;
visibility: 'public'
            | 'private'
            | 'protected'
            | 'fileprivae';

function_templates: (LESS templated_types GREATER)?;
function_attibutes: visibility?;
variable_attributes: visibility?;

argument_passing_type: 'in' | 'out' | 'inout';
argument_definition: argument_passing_type IDENTIFIER IDENTIFIER;

parameters: '(' (typed_arguments_list)? ')';
typed_arguments_list: argument ( ',' argument )*;
argument: argument_definition ('=' expr)?;

function_call: IDENTIFIER function_parameter;

function_parameter: '(' (function_typed_arguments_list)? ')';
function_typed_arguments_list: function_argument ( ',' function_argument)*;
function_argument : (IDENTIFIER '=') ? expr;

variable_prefix: 'let' | 'var';
auto_variable_definition: variable_attributes variable_prefix IDENTIFIER '=' expr;
variable_definition: variable_attributes variable_prefix IDENTIFIER ':' type (('=' '\n'*) expr)?;

member_variable_access:  '.' IDENTIFIER;
method_call:  '.' function_call;

expr:   expr member_variable_access
    |   expr method_call
    |   expr AS IDENTIFIER
    |   expr MUL expr
    |   expr DIV expr
    |   expr MOD expr
    |   expr ADD expr
    |   expr SUB expr
    |   expr LESS expr
    |   expr GREATER expr
    |   expr LESS_EQ expr
    |   expr GREATER_EQ expr
    |   expr EQUALITY expr
    |   expr INEQUALITY expr
    |   expr LOGICAL_AND expr
    |   expr LOGICAL_OR expr
    |   expr ASSIGN expr
    |   function_call
    |   variable_definition
    |   auto_variable_definition
    |   '(' expr ')'
    |   body
    |   INT
    |   FLOAT
    |   IDENTIFIER
    |   STRING
    |   CHAR
    |   TRUE
    |   FALSE
    ;

new_line: ('\n'*);
stmt_end: ('\n' | '\r' | ';')+;
