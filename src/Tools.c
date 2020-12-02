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
	/* get branch name (git)
	   TODO: Add mercurial support. */
	char *branch;
   	
	if(is_exist(".git") == _true) {
		branch = ExecWithOutput("git branch | grep \"^\*\" | sed 's/^..//'");
			
		branch[strlen(branch) - 1] = '\0';
		
		return branch;
	}
		
	return "";
}

