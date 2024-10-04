#ifndef STACK_CHECK_H
#define STACK_CHECK_H

typedef unsigned long int hash_t;

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "Stack_main.h"
#include "color_list.h"

void StackAssertFunk (Stack_t* stk, const char* FILE, const char* FUNC, size_t LINE);
bool StackOk         (Stack_t* stk);
hash_t      Hash      (const char* data, size_t size                  );


enum Check_Params {STK = 1, ALL = 3};

#define STACK_ASSERT(stk) \
        StackAssertFunk((stk), __FILE__, __func__, __LINE__)

#endif