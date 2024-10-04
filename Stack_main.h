#ifndef STACK_MAIN_H
#define STACK_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    #define DEBUG

typedef double StackElem_t;
typedef long double Canary_t;

struct Info_locate
{
    const char*  file;
    const char*  func;
    size_t       line;
};

struct Stack_t
{
    Info_locate info_Stack_t;
    Canary_t L_STACK_KANAR;
    size_t koef_capacity;
    StackElem_t* data_for_free;

    StackElem_t* data;
    size_t       size;
    size_t       capacity;

    Canary_t R_STACK_KANAR;
};

const int START_SIZE    = 16;
//const int KOEF_CAPACITY = 2;

const StackElem_t POISON = -666;

const Canary_t L_DATA_KANAR  = 0xEDAA;
const Canary_t R_DATA_KANAR  = 0xF00D;
const Canary_t L_STACK_KANAR = 0xBEDA;
const Canary_t R_STACK_KANAR = 0x0DED;

    #ifdef DEBUG
        #define ON_DEBUG(code) code
    #else
        #define ON_DEBUG(code)
    #endif    

#endif