grammar Fsc;

AS          : 'as';
ADD         : [+];
SUB         : [-];
MUL         : [*];
DIV         : [/];
MOD         : [%];
DOT         : [.];

EQUALITY    : '==';
INEQUALITY  : '!=';
LOGICAL_AND : '&&';
LOGICAL_OR  : '||';

INT         :   [0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
FLOAT       :   [0-9]*[.][0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
CHAR        :   '\'' (~["\\\r\n] | '\\' (. | EOF)) '\'';
STRING      :   '"' (~["\\\r\n] | '\\' (. | EOF))* '"';
IDENTIFIER  :   [a-zA-Z_][a-zA-Z0-9_]*;

LAYOUT  : [ \t] -> skip;

program: (stmt)*;

stmt:   function
    |   expr stmt_end
    |   class stmt_end
    |   'return' expr stmt_end
    |   if_stmt stmt_end
    |   stmt_end
    ;

body: '{' (stmt)* '}';
class: 'class' IDENTIFIER new_line body;

if_stmt: if elif else;
if: 'if' expr new_line body new_line;
elif: elif_def*;
else: else_def?;

elif_def: 'elif' expr new_line body new_line;
else_def: 'else' body;

function: function_attibutes 'def' IDENTIFIER parameters ('->' IDENTIFIER) ? new_line body;
visibility: 'public'
            | 'private'
            | 'protected'
            | 'fileprivae';

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
variable_definition: variable_attributes variable_prefix IDENTIFIER ':' IDENTIFIER (('=' '\n'*) expr)?;

expr:   expr '.' IDENTIFIER
    |   expr AS IDENTIFIER
    |   expr MUL expr
    |   expr DIV expr
    |   expr MOD expr
    |   expr ADD expr
    |   expr SUB expr
    |   expr EQUALITY expr
    |   expr INEQUALITY expr
    |   expr LOGICAL_AND expr
    |   expr LOGICAL_OR expr
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
    ;

new_line: ('\n'*);
stmt_end: ('\n' | '\r' | ';')+;
