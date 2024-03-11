/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on March 10, 2024, 7:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "kvstore.h"
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    for(int i=1;i<=argc-1;i++){
        char* type=strtok(argv[i],",");
        fprintf(stdout,"---pass 0---\n");
        if(type==NULL){
            fprintf(stderr,"\nNO DETECTED INPUT\n");
        }
        else if(strcmp(type,"p")==0||strcmp(type,"P")==0){
            int key=atoi(strtok(NULL,","));
            char* value=strtok(NULL,"");
            kvput(key,value);
            fprintf(stdout,"---pass 1.2---\n");
        }
        else if(strcmp(type,"g")==0||strcmp(type,"G")==0){
            int key=atoi(strtok(NULL,""));
            kvget(key);
            fprintf(stdout,"---pass 2.2---\n");
        }
        else if(strcmp(type,"d")==0||strcmp(type,"D")==0){
            int key=atoi(strtok(NULL,""));
            kvdelete(key);
            fprintf(stdout,"---pass 3.9---\n");
        }
        else if(strcmp(type,"c")==0||strcmp(type,"C")==0){
            kvclear();
            fprintf(stdout,"---pass 4.2---\n");
        }
        else if(strcmp(type,"a")==0||strcmp(type,"A")==0){
            kvall();
            fprintf(stdout,"---pass 5.2---\n");
        }
        else{
            fprintf(stderr,"\nIMPROPER FORMAT\n");
        }
    }
    fprintf(stdout,"---pass 6---\n");
    return 0;
}

