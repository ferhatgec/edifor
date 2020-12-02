/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef EXECUTE_PLUS_PLUS_H
#define EXECUTE_PLUS_PLUS_H

#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <pwd.h>

#define MAXCOM 1000 
#define MAXLIST 100 

char inputString[1000], *parsedArgs[100];
char* parsedArgsPiped[MAXLIST]; 
int execFlag = 0;
char* directory;

int ParsePipe(char* str, char** strpiped) { 
	int i; 
	for(i = 0; i < 2; i++) { 
		strpiped[i] = strsep(&str, "|"); 
		if(strpiped[i] == NULL) 
			break; 
	} 
  
	if (strpiped[1] == NULL) 
		return 0; // returns zero if no pipe is found. 
	else 
		return 1;  
} 

void ParseSpace(char* str, char** parsed) { 
	int i; 
	  
	for (i = 0; i < MAXLIST; i++) { 
		parsed[i] = strsep(&str, " "); 
	  
		if (parsed[i] == NULL) 
			break; 
	
		if (strlen(parsed[i]) == 0) 
			i--; 
	} 
} 

int ProcessString(char* str, char** parsed, char** parsedpipe) {   
	char* strpiped[2]; 
	int piped = 0; 
	  
	piped = ParsePipe(str, strpiped); 
  
	if(piped) { 
		ParseSpace(strpiped[0], parsed); 
		ParseSpace(strpiped[1], parsedpipe); 
	  
	} else ParseSpace(str, parsed);  
  
	return 1 + piped; 
} 

void ExecuteArgs(const char* name, char** parsed) { 
	// Forking a child 
	pid_t pid = fork();  
	  
	if (pid == -1) { 
		printf("%s : %s\n", name, " : Failed forking child.."); 
		return; 
	} else if (pid == 0) { 
		if (execvp(parsed[0], parsed) < 0) { 
			printf("%s : %s : %s\n", name, parsed[0], " : command not found.."); 
		} 

		exit(0); 
	} else { 
		// waiting for child to terminate 
		wait(NULL);  
		return; 
	} 
}
	
void ExecuteArgsPiped(const char* name, char** parsed, char** parsedpipe) { 
	// 0 is read end, 1 is write end 
	int pipefd[2];  
	pid_t p1, p2; 
	  
	if(pipe(pipefd) < 0) { 
		printf("%s : %s\n", name, " : Pipe could not be initialized");  
		return; 
	} 
	
	p1 = fork(); 

	if(p1 < 0) { 
		printf("%s : %s\n", name, " : Could not fork."); 
		return; 
	} 
	  
	if(p1 == 0) { 
		// Child 1 executing.. 
		// It only needs to write at the write end 
		close(pipefd[0]); 
		dup2(pipefd[1], STDOUT_FILENO); 
		close(pipefd[1]); 
	  
		if(execvp(parsed[0], parsed) < 0) { 
			printf("%s : %s : %s\n", name, parsed[0], " : first command not found..");
			exit(0); 
		} 
	} else { 
		// Parent executing 
		p2 = fork(); 
	  
		if(p2 < 0) { 
			printf("%s : %s\n", " : Could not fork.");  
			return; 
		} 
	  
		// Child 2 executing.. 
		// It only needs to read at the read end 
		if(p2 == 0) { 
			close(pipefd[1]); 
			dup2(pipefd[0], STDIN_FILENO); 
			close(pipefd[0]); 

			if(execvp(parsedpipe[0], parsedpipe) < 0) { 
				printf("%s : %s : %s\n", name, parsed[0], " : second command not found..");
				exit(0); 
			} 
		} else { 
			// parent executing, waiting for two children 
			wait(NULL); 
			wait(NULL); 
		} 
	} 
}
	
void RunFunction(const char* name, const char* exec) {
	strcpy(inputString, exec);
	
	execFlag = ProcessString(inputString, 
	        parsedArgs, parsedArgsPiped);

	if(execFlag == 1) {
		ExecuteArgs(name, parsedArgs); 
	}

	if(execFlag == 2) { 
		ExecuteArgsPiped(name, parsedArgs, parsedArgsPiped);
	}
}

void DefaultFunction(const char* exec) {
	system(exec);
}

/* mostly part from rosettacode */
char* ExecWithOutput(const char* command) {
	FILE *fd;
    fd = popen(command, "r");
    
    if (!fd) return "";
 
    char   buffer[256];
    size_t chread;
    
    /* String to store entire command contents in */
    size_t comalloc = 256;
    size_t comlen   = 0;
    char  *comout   = malloc(comalloc);
 
    /* Use fread so binary data is dealt with correctly */
    while((chread = fread(buffer, 1, sizeof(buffer), fd)) != 0) {
        if(comlen + chread >= comalloc) {
            comalloc *= 2;
            comout = realloc(comout, comalloc);
        }
        
        memmove(comout + comlen, buffer, chread);
        comlen += chread;
    }
 
	/* close */ 	
    pclose(fd);
    
 	return comout;
}

#endif // EXECUTE_PLUS_PLUS_H
