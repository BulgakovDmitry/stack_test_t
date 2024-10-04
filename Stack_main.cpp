#include "Stack_main.h"
#include "Stack_enter.h"
#include "Stack_check.h"
#include "Stack_func.h"

int main(void)
{
    Stack_t stk = {ON_DEBUG({stk.info_Stack_t = INFO()})};
    //-------------------------------------------------------STACK_CTOR(&stk);
    StackCtor(&stk);
    StackPush(&stk, 1);
    StackPush(&stk, 2);
    StackPop(&stk);

    //for (int q = 0; q < 15; q++) {StackPush(&stk, q + 3);}
    ON_DEBUG(StackDump(&stk, INFO());)

    //for (int i = 0; i < 3; i++) {StackPop(&stk);}
    //ON_DEBUG(StackDump(&stk, INFO());)

    StackDtor(&stk);
    ON_DEBUG(printf("\n%s\tfinished without SigFault%s", RED, RESET);)
    return 0;
}
