/*** includes ***/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdio.h>


/* C Template */
char *C_HL_extensions[] = { ".c", ".h", NULL }; 
char *C_HL_keywords[] = {
  "switch", "if", "while", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "static", "enum", "case",

  "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
  "void|", NULL
};

/* C++ Template */
char *Cpp_HL_extensions[] = { ".cpp", ".hpp", ".cc", ".hh", NULL }; 
char *Cpp_HL_keywords[] = {
  "switch", "if", "while", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "namespace", "static", "virtual", "try", "class", "enum", "case",

  "int|", "long|", "double|", "auto|", "goto|", "float|", "volatile|" , "asm|", "string|", "char|", "unsigned|", "signed|",
  "void|", NULL
};



#endif // LANGUAGE_H
