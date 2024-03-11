/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   kvstore.h
 * Author: student
 *
 * Created on March 10, 2024, 7:09 PM
 */

#ifndef KVSTORE_H
#define KVSTORE_H

#ifdef __cplusplus
extern "C" {
#endif

    void kvput(int key,char* value);
    void kvget(int key);
    void kvdelete(int key);
    void kvclear();
    void kvall();


#ifdef __cplusplus
}
#endif

#endif /* KVSTORE_H */

