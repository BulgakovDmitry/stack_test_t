#include "Stack_check.h"

/*---------------ФУНКЦИЯ ДЛЯ ASSERT--------------------------------------------------------------------------------------------------------------*/
void StackAssertFunk(Stack_t* stk, const char* FILE, const char* FUNC, size_t LINE)
{   
    if (!StackOk(stk))
    {
        printf("%s___ASSERT___~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
        printf("%s!!!   %sFile    %s%s%s\n", RED, MANG, BLUE, FILE, RESET);
        printf("%s!!!   %sLine    %s%zu%s\n", RED, MANG, BLUE, LINE, RESET);
        printf("%s!!!   %sfunc    %s%s%s\n", RED, MANG, BLUE, FUNC, RESET);
        printf("%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n", RED, RESET);
        assert(false);
        memset(stk->data, -666, 8);
    }
}

/*-------------ПОДФУНКЦИЯ ФУНКЦИИ ASSERT---------------------------------------------------------------------------------------------------------*/
bool StackOk(Stack_t* stk)
{
    if (stk != NULL && stk->data != NULL)
    {
        if (stk->size < 0)
            return false;
        else    
            return true;
    }    
    else 
        return false;  
}

/*-----------ФУНКЦИЯ ДЛЯ ХЕШИРОВАНИЯ-------------------------------------------------------------------------------------------------------------*/
hash_t Hash(const char* data, size_t size)
{
    hash_t hash = 0;
    for (size_t i = 0; i < size; i++)
    {
        hash = hash * 33 ^ data[i];
    }
    return hash;
}

// s1
// s2
// s3
// s4
// s5
// s6
//
// f(s) -> int
// f(s1)
// f(s2) == f(s1)
// f(s1) != f(s2) -> s1 != s2