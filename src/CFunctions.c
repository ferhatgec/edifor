/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>

#include <Edifor.h>
#include <CFunctions.h>

char *substring(char *str, unsigned pos, unsigned len) {
	char *p;
   	unsigned c;
 
   	p = malloc(len + 1);
   
   	if (p == NULL) { return ""; }
 
   	for (c = 0; c < len; c++) {
		*(p+c) = *(str + pos - 1);      
      	str++;  
   	}
 
   	*(p + c) = '\0';
 
   	return p;
}
