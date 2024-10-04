#include "Stack_func.h"

/*---------------ФУНКЦИЯ КОНСТРУКТОР ДЛЯ СОЗДАНИЯ СТЕКА------------------------------------------------------------------------------------------*/
int StackCtor(Stack_t* stk)
{
    if (stk == NULL)
    {
        Info_locate StackCtor_info = INFO();
        //return err  
        printf("%s___ASSERT___~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
        printf("%s!!!   %sFile    %s%s%s\n", RED, MANG, BLUE, StackCtor_info.file, RESET);
        printf("%s!!!   %sLine    %s%zu%s\n", RED, MANG, BLUE, StackCtor_info.line, RESET);
        printf("%s!!!   %sFunc    %s%s%s\n", RED, MANG, BLUE, StackCtor_info.func, RESET);
        printf("%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
        assert(1);
    }
    stk->L_STACK_KANAR = L_STACK_KANAR;
    stk->koef_capacity = 1;
    stk->size = 0;
    stk->capacity = START_SIZE;

    stk->data = 0;
    stk->data = (StackElem_t*)calloc(stk->capacity + 2, sizeof(StackElem_t));
    stk->data[0] = L_DATA_KANAR;                  // УСТАНОВКА ЛЕВОЙ  КАНАРЕЙКИ НА data
    stk->data[stk->capacity + 1] = R_DATA_KANAR;  // УСТАНОВКА ПРАВОЙ КАНАРЕЙКИ НА data
    
    stk->R_STACK_KANAR = R_STACK_KANAR;
    STACK_ASSERT(stk);
    return 0;
}

/*--------------ФУНКЦИЯ ДЛЯ ЧИСТКИ ПАМЯТИ СТЕКА--------------------------------------------------------------------------------------------------*/
int StackDtor(Stack_t* stk)
{
    //                                                                                                                                                                                              STACK_ASSERT(stk);
    FREE(stk->data);
    return 0;
}

/*------------ФУНКЦИЯ ДЛЯ ДЕБАГА (РАСПЕЧАТКИ)----------------------------------------------------------------------------------------------------*/
void StackDump(Stack_t* stk, Info_locate info_l)
{
    STACK_ASSERT(stk);
    printf("%s___StackDump___~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
    printf("%sStack_t %s[%s%p%s]%s\n", CEAN, GREEN, MANG, stk, GREEN, RESET);
    printf("%sCalled from %s%s %s: %s%zu %s(%s%s%s)  %s\n", CEAN, MANG, info_l.file, GREEN, RED, info_l.line, GREEN, BLUE, info_l.func, GREEN, RESET);
    printf("%sname 'stk' born at %s%s %s:%s %zu %s(%s%s%s)%s\n", CEAN, MANG, stk->info_Stack_t.file, GREEN, RED, stk->info_Stack_t.line, GREEN, BLUE, stk->info_Stack_t.func, GREEN, RESET);
    printf("%s{%sL_STACK_KANAR %s= %s%p%s", GREEN, BLUE, GREEN, RED, stk->L_STACK_KANAR, RESET);
    printf("%s, %sR_STACK_KANAR %s= %s%p%s}%s\n", GREEN, BLUE, GREEN, RED, stk->R_STACK_KANAR, GREEN, RESET);

    printf("%s{%sL_DATA_KANAR %s = %s%p%s", GREEN, BLUE, GREEN, RED, stk->data[0], RESET);
    printf("%s, %sR_DATA_KANAR %s = %s%p%s}%s\n", GREEN, BLUE, GREEN, RED, stk->data[stk->capacity + 1], GREEN, RESET);

    printf("%scapasity %s= %s%zu%s\n", BLUE, GREEN, RED, stk->capacity, RESET);
    printf("%ssize %s= %s%zu%s\n", BLUE, GREEN, RED, stk->size, RESET);
    printf("%sdata %s[%s%p%s]%s\n", CEAN, GREEN, MANG, stk->data, GREEN, RESET);
    StackPrint(stk);
    printf("%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
    STACK_ASSERT(stk);
}

/*-----------ФУНКЦИЯ ДЛЯ СОЗДАНИЯ МАКРОСА INFO, КОТОРЫЙ ПОЛУЧАЕТ ИНФОРМАЦИЮ О МЕСТЕ ВЫЗОВА-------------------------------------------------------*/
Info_locate Info(const char* FILE, size_t LINE, const char* FUNC)
{
    Info_locate info_l = {};
    info_l.file = FILE;
    info_l.line = LINE;
    info_l.func = FUNC;
    return info_l;
}

/*-----------ФУНКЦИЯ ДЛЯ ПЕЧАТИ СТЕКА (ПОДФУНКЦИЯ ФУНКЦИИ StackDump)-----------------------------------------------------------------------------*/
void StackPrint(Stack_t* stk)
{
    STACK_ASSERT(stk);
    printf("%s{%s\n", GREEN, RESET);
    printf("  %sk%s[%s%3d%s]   = %s  %3lg%s\n", YELLOW, GREEN, MANG, 0, GREEN, RED, stk->data[0], RESET);
    for (size_t i = 1; i < stk->size + 1; i++) 
    {
        printf("  %s*%s[%s%3zu%s]   = %s%3lg%s\n", YELLOW, GREEN, MANG, i, GREEN, RED, stk->data[i], RESET);
    }
    
    for (size_t j = 1; j < stk->capacity - stk->size + 1; j++) 
    {
        printf("   %s[%s%3zu%s]   = %s%5lg %s (%sPOISON%s)%s\n", GREEN, MANG, j + stk->size, GREEN, RED, POISON, GREEN, YELLOW, GREEN, RESET);
    }
    printf("  %sk%s[%s%3zu%s]   = %s  %5lg %s \n", YELLOW, GREEN, MANG, stk->capacity + 1, GREEN, RED, stk->data[stk->capacity+1], RESET);
    printf("%s}%s\n", GREEN, RESET);
    STACK_ASSERT(stk);
}

