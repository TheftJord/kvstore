/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define databaseFile "database.txt"
#define deleteFile "delete.txt"


char size[1024];
int sizeCheck(int key){
    if(key<10&&key>-1){
        return 1;
    }
    else if(key<100&&key>=10){
        return 2;
    }
    else if(key<1000&&key>=100){
        return 3;
    }
    else if(key<10000&&key>=1000){
        return 4;
    }
    else if(key<100000&&key>=10000){
        return 5;
    }
}

void kvput(int key,char* value){
    fprintf(stdout,"---pass 1.1---\n");
    FILE* open=fopen(databaseFile,"r+");
    char* buffer;
    int n = sprintf(buffer,"Key: %d",key);
    while(fgets(size, sizeof(size), open)){
        if(strspn(size,buffer)==n){
            fprintf(stderr,"\nKEY ALREADY EXISTS, ENTER NEW KEY\n");
            return;
        }
        else{
            continue;
        }
    }
    fprintf(open, "Key: %d, Value: %s\n",key,value);
    fclose(open);
}

void kvget(int key){
    fprintf(stdout,"---pass 2.1---\n");
    FILE* open=fopen(databaseFile,"r");
    char* buffer;
    int counter=0;
    int n = sprintf(buffer,"%d",key);
    while(fgets(size, sizeof(size), open)){
        if(strstr(size,buffer)!=NULL){
            printf("%s",size);
            return;
        }
        else{
            continue;
            counter++;
        }
    }
    fprintf(stderr,"KEY NOT FOUND");
}

void kvdelete(int key){
    fprintf(stdout,"---pass 3.1---\n");
    FILE* open=fopen(databaseFile,"r");
    FILE* temp=fopen(deleteFile,"w");
    int h=0;
    h=sizeCheck(key);
    char* buffer;
    int t = sprintf(buffer,"%d",key);
    fprintf(stdout,"test\n");
    while(fgets(size, sizeof(size), open)!=NULL){
        if(strstr(size,buffer)!=NULL){
            fprintf(stdout,"---pass 3.2---\n");
            continue;
        }
        else{
            fprintf(stdout,"---pass 3.3---\n");
            fprintf(temp,"%s",size);
        }
    }
    fclose(open);
    fclose(temp);
    fprintf(stdout,"---pass 3.4---\n");
    FILE* open2=fopen(databaseFile,"w");
    FILE* temp2=fopen(deleteFile,"r");
    while(fgets(size, sizeof(size), temp2)){
        fprintf(stdout,"---pass 3.5---\n");
        fprintf(open2,"%s",size);
    }
    fclose(open2);
    fclose(temp2);
    fprintf(stdout,"---pass 3.6---\n");
}

void kvclear(){
    fprintf(stdout,"---pass 4.1---\n");
    FILE* open=fopen(databaseFile,"w");
    fclose(open);
}

void kvall(){
    fprintf(stdout,"---pass 5.1---\n");
    FILE* open=fopen(databaseFile,"r");
    while(fgets(size, sizeof(size), open)){
        fprintf(stdout,"%s",size);
    }
    fclose(open);
}

