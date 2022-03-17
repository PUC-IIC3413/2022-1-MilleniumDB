parser grammar MDBParser;

options {
	tokenVocab = MDBLexer;
}

root: matchStatement whereStatement? groupByStatement? orderByStatement? returnStatement EOF
|     describeStatement EOF
;

describeStatement: K_DESCRIBE fixedNode;

matchStatement: K_MATCH graphPattern;

whereStatement: K_WHERE expr;

groupByStatement: K_GROUP K_BY groupByItem (',' groupByItem)*;

orderByStatement: K_ORDER K_BY orderByItem (',' orderByItem)*;

returnStatement: K_RETURN K_DISTINCT? returnItem (',' returnItem)* (K_LIMIT UNSIGNED_INTEGER)? # returnList
|                K_RETURN K_DISTINCT? '*' (K_LIMIT UNSIGNED_INTEGER)? # returnAll
;

returnItem: VARIABLE KEY? # returnItemVar
|           aggregateFunc '(' VARIABLE KEY? ')' # returnItemAgg
|           K_COUNT '(' K_DISTINCT? (VARIABLE KEY? | '*') ')' # returnItemCount
;

aggregateFunc: K_SUM
|              K_MAX
|              K_MIN
|              K_AVG
;

orderByItem: VARIABLE KEY? (K_ASC | K_DESC)? # orderByItemVar
|            aggregateFunc '(' VARIABLE KEY? ')' (K_ASC | K_DESC)? # orderByItemAgg
|            K_COUNT '(' K_DISTINCT? VARIABLE KEY? ')' (K_ASC | K_DESC)?  # orderByItemCount
;

groupByItem: VARIABLE KEY?;

graphPattern: basicPattern optionalPattern*;

optionalPattern: K_OPTIONAL '{' graphPattern '}';

basicPattern: linearPattern (',' linearPattern)*;

linearPattern: node ((edge | path) node)*;

path:'<=' '[' pathType? VARIABLE? pathAlternatives']' '=' # leftPath
|    '=' '[' pathType? VARIABLE? pathAlternatives']' '=' '>' # rightPath
;

pathAlternatives: pathSequence ('|' pathSequence)*;

pathSequence: pathAtom ('/' pathAtom)*;

pathAtom: '^'? TYPE pathSuffix? # pathAtomSimple
|         '^'? '(' pathAlternatives ')' pathSuffix? # pathAtomAlternatives
;

pathSuffix: op='*'
|           op='+'
|           op='?'
|           '{' min=UNSIGNED_INTEGER ',' max=UNSIGNED_INTEGER '}'
;

pathType: K_ANY | K_ALL;

node: fixedNode
|     varNode
;

fixedNode: named_node # nodeNamedNode
|          ANON_NODE  # nodeAnonNode
|          EDGE_NODE  # nodeEdgeNode
|          value      # nodeValue
;

edge: '<' ('-' edgeInside)? '-' # leftEdge
|     '-' (edgeInside '-')? '>' # rightEdge
;

edgeInside: '[' (VARIABLE | EDGE_ID)? (TYPE | TYPE_VAR)? properties? ']';

varNode: '(' VARIABLE? TYPE* properties? ')';

properties: '{' property (',' property)* '}';

property: identifier (':' value | TRUE_PROP | FALSE_PROP);

named_node: '(' identifier ')';

identifier: NAME | keyword;

boolValue: K_TRUE | K_FALSE;

numericValue: ('+' | '-')? (UNSIGNED_INTEGER | UNSIGNED_FLOAT);

value: numericValue | STRING | boolValue;

expr: conditionalOrExpr
;

conditionalOrExpr: conditionalAndExpr (K_OR conditionalAndExpr)*
;

conditionalAndExpr: comparisonExpr (K_AND comparisonExpr)*
;

comparisonExpr: aditiveExpr (op=('=='|'!='|'<'|'>'|'<='|'>=') aditiveExpr)? # comparisonExprOp
|               aditiveExpr K_IS K_NOT? exprTypename # comparisonExprIs
;

aditiveExpr: multiplicativeExpr (op+=('+'|'-') multiplicativeExpr)*
;

multiplicativeExpr: unaryExpr (op+=('*'|'/'|'%') unaryExpr)*
;

unaryExpr: K_NOT unaryExpr
|          '+' unaryExpr
|          '-' unaryExpr
|          atomicExpr
;

atomicExpr:  VARIABLE KEY? # exprVar
|            valueExpr # exprValueExpr
|            '(' expr ')' # exprParenthesis
|            TRUE_PARENTHESIS # exprTrueParenthesis
|            FALSE_PARENTHESIS # exprFalseParenthesis
;

valueExpr: UNSIGNED_INTEGER | UNSIGNED_FLOAT | STRING | boolValue;

exprTypename: K_NULL
|             K_STRING
|             K_BOOL
|             K_INTEGER
|             K_FLOAT
;

// it excludes keywords true and false
keyword: K_ALL
| 	     K_AND
| 	     K_AVG
| 	     K_ALL
| 	     K_ASC
| 	     K_BY
| 	     K_BOOL
| 	     K_COUNT
| 	     K_DESCRIBE
| 	     K_DESC
| 	     K_DISTINCT
| 	     K_IS
| 	     K_INTEGER
| 	     K_FLOAT
| 	     K_GROUP
| 	     K_LIMIT
| 	     K_MAX
| 	     K_MATCH
| 	     K_MIN
| 	     K_OPTIONAL
| 	     K_ORDER
| 	     K_OR
| 	     K_NOT
| 	     K_NULL
| 	     K_SUM
| 	     K_STRING
| 	     K_RETURN
| 	     K_WHERE
;
