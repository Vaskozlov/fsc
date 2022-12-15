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

INT     :  [0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;
FLOAT   :  [0-9]*[.][0-9]+([a-zA-Z_][a-zA-Z0-9_]*)?;

NAME      : [a-zA-Z_][a-zA-Z0-9_]*;

LAYOUT  : [ \t] -> skip;

program: (stmt)*;

stmt:   function
    |   expr stmt_end
    |   class stmt_end
    |   'return' expr stmt_end
    |   if_stmt stmt_end
    |   stmt_end
    ;

if_stmt: if elif* else?;
if: 'if' expr ('\n'*) body ('\n'*);
elif: 'elif' expr ('\n'*) body ('\n'*);
else: 'else' body;

stmt_end: ('\n' | '\r' | ';')+;

function: function_attibutes 'func' NAME parameters ('->' NAME) ? ('\n'*) body;
visibility: 'public'
            | 'private'
            | 'protected'
            | 'fileprivae';

function_attibutes: visibility?;
variable_attributes: visibility?;

argument_definition: argument_passing_type NAME NAME;
argument_passing_type: 'in' | 'out' | 'inout';
parameters: '(' (typed_arguments_list)? ')';
typed_arguments_list: argument ( ',' argument )*;
argument: argument_definition ('=' expr)?;

class: 'class' NAME ('\n')* body;

function_call: NAME function_parameter;

function_parameter: '(' (function_typed_arguments_list)? ')';
function_typed_arguments_list: function_argument ( ',' function_argument)*;
function_argument : (NAME '=') ? expr;

variable_definition: variable_attributes variable_prefix NAME ':' NAME (('=' '\n'*) expr)?;
auto_variable_definition: variable_attributes variable_prefix NAME '=' expr;

variable_prefix: 'let' | 'var';

body: '{' (stmt)* '}';

expr:   expr '.' NAME
    |   expr AS NAME
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
    |   NAME
    ;
