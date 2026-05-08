//write a app that takes 2 variable file path and string and writes the string in the file. use syslog for logging
#include<stdio.h>
#include <stdlib.h>
#include<syslog.h>
int main(int argc, char *argv[]){
    openlog(NULL,0,LOG_USER);
    if (argc < 3) {
        syslog(LOG_ERR,"Not enough arguments , their should be 2 parameters");
        return 1;
    }else if (argc > 4){
        syslog(LOG_ERR,"Too Many Args , should be only 2");
        return 1;
    }else{
        FILE* fptr;
        fptr = fopen(argv[1],"a");
        if (fptr == NULL){
            syslog(LOG_ERR , "File Path is incorrect or file doesn't exist");
        }
        else{
            syslog(LOG_DEBUG , "Writing %s to %s",argv[2],argv[1]);
            fputs(argv[2],fptr);
        }
    }
    return 0;
}