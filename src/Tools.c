/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

/*** includes ***/

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#include <Edifor.h>
#include <Tools.h>

/* from ExecuteC (aka ExecutePlusPlus library) */
#include <executeplusplus.h>
#include <filesystemplusplus.h>

char* edifor_get_branch() {
	/* get current working dir */
	char *cwd;
   	
	if(is_exist(".git") == _true) {
			cwd = ExecWithOutput("git branch | grep \"^\*\" | sed 's/^..//'");
			
			cwd[strlen(cwd) - 1] = '\0';
			
			return cwd;
	}
		
	return "";
}

