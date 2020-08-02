/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdio.h>

/* C Template */
char *C_HL_extensions[] = { ".c", ".h", NULL }; 
char *C_HL_keywords[] = {
  "switch", "if", "while", "#ifndef", "#define", "#endif", "#include" ,"for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "static", "enum", "case",

  "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
  "void|", NULL
};

/* C++ Template */
char *Cpp_HL_extensions[] = { ".cpp", ".hpp", ".cc", ".hh", NULL }; 
char *Cpp_HL_keywords[] = {
  "switch", "if", "while", "#ifndef", "#define", "#endif", "#include", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "namespace", "static", "virtual", "try", "class", "enum", "case",

  "int|", "long|", "double|", "auto|", "goto|", "float|", "volatile|" , "asm|", "string|", "char|", "unsigned|", "signed|",
  "void|", NULL
};

/* FlaScript Template */
char *FlaScript_HL_extensions[] = { ".fls", ".flsh", NULL }; 
char *FlaScript_HL_keywords[] = {
  "import", "if", "env", "EraseAllSubstring", "exec", "system", "executepp", "func", "ifdef", "endif}", "input", "var",
  "newline", "main()", "main", "random", "print", "[this]", "read", "arch", "osname", "uptime", "username",

  "int|", "int&|", "string&|", "get|", "float|", "volatile|" , "asm|", "string|", "colorized|", "rcolorized|", "signed|",
  "type|", NULL
};

#endif // LANGUAGE_H
