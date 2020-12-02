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
#include <Tools.h>
#include <CFunctions.h>

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

char* edifor_clock_system() {
    char* time = substring(edifor_get_date(), 12, 2);

	//time[strlen(time) - 1] = '\0';    
    
    int _half_time = atoi(substring(edifor_get_date(), 15, 2));
	
	//sprintf(time, "%d", strlen(time));
	
	/* cliff of 'return' */
    if(strcmp(time, "01") == 0 || strcmp(time, "13") == 0)
        if(_half_time >= 30)
            return "🕜";
        else 
            return "🕐";
    else if(strcmp(time, "02") == 0 || strcmp(time, "14") == 0)
        if(_half_time >= 30)
            return "🕝";
        else 
            return "🕑";
    else if(strcmp(time, "03") == 0 || strcmp(time, "15") == 0)
        if(_half_time >= 30)
            return "🕞";
        else
            return "🕒";
    else if(strcmp(time, "04") == 0 || strcmp(time, "16") == 0)
        if(_half_time >= 30)
            return "🕟";
        else
            return "🕓";
    else if(strcmp(time, "05") == 0 || strcmp(time, "17") == 0)
        if(_half_time >= 30)
            return "🕠";
        else 
            return "🕔";
    else if(strcmp(time, "06") == 0 || strcmp(time, "18") == 0)
        if(_half_time >= 30)
            return "🕡";
        else 
            return "🕕";
    else if(strcmp(time, "07") == 0 || strcmp(time, "19") == 0)
        if(_half_time >= 30)
            return "🕢";
        else 
            return "🕖";
    else if(strcmp(time, "08") == 0 || strcmp(time, "20") == 0)
        if(_half_time >= 30)
            return "🕣";
        else 
            return "🕗";
    else if(strcmp(time, "09") == 0 || strcmp(time, "21") == 0)
        if(_half_time >= 30)
            return "🕤";
        else 
            return "🕘";
    else if(strcmp(time, "10") == 0 || strcmp(time, "22") == 0)
        if(_half_time >= 30)
            return "🕥";
        else 
            return "🕙";
    else if(strcmp(time, "11") == 0 || strcmp(time, "23") == 0)
        if(_half_time >= 30)
            return "🕦";
        else 
            return "🕚";
    else if(strcmp(time, "00") == 0 || strcmp(time, "12") == 0)
        if(_half_time >= 30)
            return "🕧";
        else 
            return "🕛";
    
    return time;
}

char* edifor_get_date() {
	time_t current_time = time(NULL);
    
    return ctime(&current_time);;
}
