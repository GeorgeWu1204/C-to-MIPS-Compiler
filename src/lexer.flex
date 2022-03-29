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
"for"			    { return(FOR); }
"goto"			  { return(GOTO); }
"if"			    { return(IF); }
"int"			    { return(INT); }
"long"			  { return(LONG); }
"register"		{ return(REGISTER); }
"return"		  { return(RETURN); }
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
"while"			  { return(WHILE); }

{L}({L}|{D})*		        { yylval.string = new std::string(yytext);
                          return IDENTIFIER; 
                        }

0[xX]{H}+{IS}?		      { return(CONSTANT); }
0{D}+{IS}?		          {  return(CONSTANT); }
{D}+{IS}?		            {  yylval.int_number = (int)strtol(yytext, NULL, 0); return(INT_CONSTANT); }


{D}+{E}     		        {  yylval.double_number = strtod(yytext, NULL); return(DOUBLE_CONSTANT); }
{D}+{E}{FS}             {  yylval.float_number  = strtod(yytext, NULL); return(FLOAT_CONSTANT); }
{D}*"."{D}+({E})?     	{  yylval.double_number = strtod(yytext, NULL); return(DOUBLE_CONSTANT); }
{D}*"."{D}+({E})?{FS}   {  yylval.float_number  = strtod(yytext, NULL); return(FLOAT_CONSTANT); }
{D}+"."{D}*({E})?     	{  yylval.double_number = strtod(yytext, NULL); return(DOUBLE_CONSTANT); }
{D}+"."{D}*({E})?{FS}   {  yylval.float_number  = strtod(yytext, NULL); return(FLOAT_CONSTANT); }

L?\"(\\.|[^\\"])*\"	    { yylval.string = new std::string(yytext);return(STRING_LITERAL); }

'(\\.|[^'\\])' {  std::string tmp(yytext);
                  if(tmp.size() == 3)
                  {
                    yylval.int_number=(int)tmp[1]; 
                  }
                  else
                  {
                    switch(tmp[2])
                    {
                      case '0': yylval.int_number=0x00;
                      break;
                      case '\'': yylval.int_number=0x27;
                      break;
                      case '"': yylval.int_number=0x22;
                      break;
                      case '?': yylval.int_number=0x3f;
                      break;
                      case '\\': yylval.int_number=0x5c;
                      break;
                      case 'a': yylval.int_number=0x07;
                      break;
                      case 'b': yylval.int_number=0x08;
                      break;
                      case 'f': yylval.int_number=0x0c;
                      break;
                      case 'n': yylval.int_number=0x0a;
                      break;
                      case 'r': yylval.int_number=0x0d;
                      break;
                      case 't': yylval.int_number=0x09;
                      break;
                      case 'v': yylval.int_number=0x0b;
                      break;
                      default: std::cerr << "ERROR: I'm not sure how to manage escaped char" << std::endl;
                    }
                  }
                  return CHAR_LITERAL; }

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
";"			      {  return(';'); }
("{"|"<%")		{  return('{'); }
("}"|"%>")		{  return('}'); }
","			      {  return(','); }
":"			      {  return(':'); }
"="			      {  return('='); }
"("			      {  return('('); }
")"			      {  return(')'); }
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
.			{}

%%

void yyerror (char const *s)
{
  fprintf(stderr, "Lexing error: %s\n", s);
  exit(1);
}