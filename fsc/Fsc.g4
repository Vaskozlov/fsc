grammar Fsc;

ADD     : [+];
SUB     : [-];
MUL     : [*];
DIV     : [/];
MOD     : [%];

IF      : 'if';
FOR     : 'for';
WHILE   : 'while';
FUNC    : 'func';
RETURN  : 'return';

INT     :  [0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
FLOAT   :  [0-9]*[.][0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;

NAME      : [a-zA-Z_][a-zA-Z0-9_]*;

LAYOUT  : [ \t] -> skip;

program: (global_stmt)*;

global_stmt:    function
            |   variable_definition stmt_end
            |   auto_variable_definition stmt_end
            |   stmt_end
            ;

stmt:   expr stmt_end
    |   'return' expr stmt_end
    |   variable_definition stmt_end
    |   auto_variable_definition stmt_end
    |   stmt_end
    ;

stmt_end: ('\n' | '\r' | ';')+;

function: 'func' NAME parameters ('->' NAME) ? ('\n'*) body;

argument_definition: NAME ':' argument_passing_type NAME;
argument_passing_type: 'in' | 'out' | 'inout';
parameters: '(' (typed_arguments_list)? ')';
typed_arguments_list: argument_definition ('=' expr)? ( ',' argument_definition ('=' expr)? )*;

function_call: NAME function_parameter;

function_parameter: '(' (function_typed_arguments_list)? ')';
function_typed_arguments_list: (NAME '=')? expr ( ',' (NAME '=')? expr)*;

variable_definition: 'var' NAME ':' NAME '=' expr;
auto_variable_definition: 'var' NAME '=' expr;

body: '{' (stmt)* '}';

parenthesized_expr: '(' expr ')';

expr:   expr MUL expr
    |   expr DIV expr
    |   expr MOD expr
    |   expr ADD expr
    |   expr SUB expr
    |   function_call
    |   parenthesized_expr
    |   INT
    |   FLOAT
    |   NAME
    ;
