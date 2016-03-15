#include <stdio.h>
#include <regex.h>
#include <dirent.h>
#include <string.h>

#define MAXMATCH 200

void lookInFile (char *filename, char* pattern);

int toolazytowrite(int argc, char * argv[]);