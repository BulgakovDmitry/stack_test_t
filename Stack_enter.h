#ifndef STACK_ENTER_H
#define STACK_ENTER_H

#include <stdlib.h>
#include <stdio.h>

#include "Stack_main.h"
#include "Stack_check.h"
#include "Stack_func.h"

void        StackPush       (Stack_t* stk, StackElem_t elem );
StackElem_t StackPop        (Stack_t* stk                   );


#endif