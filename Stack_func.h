#ifndef STACK_FUNC_H
#define STACK_FUNC_H

#include <stdio.h>
#include <stdlib.h>

#include "Stack_main.h"
#include "Stack_check.h"

int         StackCtor (Stack_t*    stk                                );
int         StackDtor (Stack_t*    stk                                );
void        StackDump (Stack_t*    stk,  Info_locate info_l           );
void        StackPrint(Stack_t*    stk                                );
Info_locate Info      (const char* FILE, size_t LINE, const char* FUNC);

    
#define FREE(ptr_) \
        do { free(ptr_); ptr_ = NULL; } while (false)

#define INFO() \
        Info(__FILE__, __LINE__, __func__)

#endif