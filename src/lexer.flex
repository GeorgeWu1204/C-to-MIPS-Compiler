%option noyywrap


%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%%

"auto"			  { return(AUTO); }
"break"			  { return(BREAK); }
"case"			  { return(CASE); }
"char"			  { return(CHAR); }
"const"			  { return(CONST); }
"continue"		{ return(CONTINUE); }
"default"		  { return(DEFAULT); }
"do"			    { return(DO); }
"double"		  { return(DOUBLE); }
"else"			  { return(ELSE); }
"enum"			  { return(ENUM); }
"extern"		  { return(EXTERN); }
"float"			  { return(FLOAT); }
"for"			    { printf("Token Type: FOR VALUE:[%s]", yytext); return(FOR); }
"goto"			  { return(GOTO); }
"if"			    { return(IF); }
"int"			    { printf("Token Type: INT VALUE:[%s]", yytext); return(INT); }
"long"			  { return(LONG); }
"register"		{ return(REGISTER); }
"return"		  { printf("Token Type: RETURN VALUE:[%s]", yytext); return(RETURN); }
"short"			  { return(SHORT); }
"signed"		  { return(SIGNED); }
"sizeof"		  { return(SIZEOF); }
"static"		  { return(STATIC); }
"struct"		  { return(STRUCT); }
"switch"		  { return(SWITCH); }
"typedef"		  { return(TYPEDEF); }
"union"			  { return(UNION); }
"unsigned"		{ return(UNSIGNED); }
"void"			  { return(VOID); }
"volatile"		{ return(VOLATILE); }
"while"			  { printf("Token Type: WHILE VALUE:[%s]", yytext);return(WHILE); }

{L}({L}|{D})*		        { printf("Token Type: INDENTIFIER VALUE:[%s]", yytext); yylval.string = new std::string(yytext);  return IDENTIFIER; }
0[xX]{H}+{IS}?		      { return(CONSTANT); }
0{D}+{IS}?		          {  return(CONSTANT); }
{D}+{IS}?		            {  printf("Token Type: INT_CONSTANT VALUE:[%s]", yytext);yylval.int_number = (int)strtol(yytext, NULL, 0); return(INT_CONSTANT); }
L?'(\\.|[^\\'])+'	      {  return(INT_CONSTANT); }

{D}+{E}{FS}?		        {  return(FLOAT_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{  return(FLOAT_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{  return(FLOAT_CONSTANT); }

L?\"(\\.|[^\\"])*\"	    {  return(STRING_LITERAL); }

"..."			    {  return(ELLIPSIS); }
">>="			    {  return(RIGHT_ASSIGN); }
"<<="			    {  return(LEFT_ASSIGN); }
"+="			    {  return(ADD_ASSIGN); }
"-="			    {  return(SUB_ASSIGN); }
"*="			    {  return(MUL_ASSIGN); }
"/="			    {  return(DIV_ASSIGN); }
"%="			    {  return(MOD_ASSIGN); }
"&="			    {  return(AND_ASSIGN); }
"^="			    {  return(XOR_ASSIGN); }
"|="			    {  return(OR_ASSIGN); }
">>"		    	{  return(RIGHT_OP); }
"<<"			    {  return(LEFT_OP); }
"++"			    {  return(INC_OP); }
"--"			    {  return(DEC_OP); }
"->"			    {  return(PTR_OP); }
"&&"			    {  return(AND_OP); }
"||"			    {  return(OR_OP); }
"<="			    {  return(LE_OP); }
">="			    {  return(GE_OP); }
"=="			    {  return(EQ_OP); }
"!="			    {  return(NE_OP); }
";"			      {  printf("Token Type: ; VALUE:[%s]", yytext); return(';'); }
("{"|"<%")		{  printf("Token Type: { VALUE:[%s]", yytext); return('{'); }
("}"|"%>")		{  printf("Token Type: } VALUE:[%s]", yytext); return('}'); }
","			      {  return(','); }
":"			      {  return(':'); }
"="			      {  return('='); }
"("			      {  printf("Token Type: ( VALUE:[%s]", yytext); return('('); }
")"			      {  printf("Token Type: ) VALUE:[%s]", yytext); return(')'); }
("["|"<:")		{  return('['); }
("]"|":>")		{  return(']'); }
"."			      {  return('.'); }
"&"			      {  return('&'); }
"!"			      {  return('!'); }
"~"			      {  return('~'); }
"-"			      {  return('-'); }
"+"			      {  return('+'); }
"*"			      {  return('*'); }
"/"			      {  return('/'); }
"%"			      {  return('%'); }
"<"			      {  return('<'); }
">"			      {  return('>'); }
"^"			      {  return('^'); }
"|"			      {  return('|'); }
"?"			      {  return('?'); }

[ \t\v\n\f]		{  }
.			{ printf("ignore bad characters VALUE:[%s]", yytext);  }

%%

void yyerror (char const *s)
{
  fprintf(stderr, "Lexing error: %s\n", s);
  exit(1);
}