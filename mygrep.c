//
//  main.c
//  Cgrep
//
//  Created by Jason Hu on 3/14/16.
//  Copyright © 2016 Jason Hu. All rights reserved.
//


//  Note: Case-sensitive

#include <stdio.h>
#include <regex.h>
#include <dirent.h>
#include <string.h>
#define MAXMATCH 300

int main(int argc, char * argv[]){
    
    DIR *yomom = NULL;
    struct dirent *dir;
    regex_t testexpression;
    int status;
    regmatch_t matches[MAXMATCH];
    FILE * opened;
    char * line;
    size_t len = 200;
    int i =0;

    
    for (i=2; i<argc; i++) {
        status=regcomp(&testexpression, argv[i], REG_EXTENDED);
        if (status ==1){
            printf("argv %d is not a valid regular expression",i);
            return 1;
        }
        
        yomom=opendir(".");
        
        if (yomom){
            
            while ((dir=readdir(yomom))!=NULL){
                status = regexec(&testexpression,dir->d_name,MAXMATCH,matches,0);
                if (status==0) { //match by regex
                    if (!strcmp(dir->d_name,".")) {
                        continue;
                    }
                    if (!strcmp(dir->d_name,"..")) {
                        continue;
                    }
                    opened=fopen(dir->d_name, "r");
                    
                    if (opened==NULL) {
                        printf("No permission to access file %s\n", dir->d_name);
                        continue; //to a new while loop
                    }
                    while (getline(&line, &len, opened)!=-1) {
                        if (strstr(line, argv[1])!=NULL) {
                            printf("%s:%s",dir->d_name,line);
                        }
                    }
                }
            }
        }
        
        closedir(yomom);
        
    }
    return 0;
}


