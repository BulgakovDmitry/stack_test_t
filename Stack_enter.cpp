#include "Stack_enter.h"
#include <string.h>

/*---------------ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА СТЕКА-------------------------------------------------------------------------------------------*/
void StackPush(Stack_t* stk, StackElem_t elem)
{
    STACK_ASSERT(stk);
    if (stk->size >= stk->capacity)
    {    
        stk->data[0] = POISON;                  // УДАЛЕНИЕ СТАРОЙ ЛЕВОЙ КАНАРЕЙКИ
        stk->data[stk->capacity + 1] = POISON;  // УДАЛЕНИЕ СТРОЙ ПРАВОЙ КАНАРЕЙКИ (ИЗМЕНЕНИЕ НА POISON)

        stk->capacity = stk->capacity * stk->koef_capacity;
        stk->data = (StackElem_t*)realloc(stk->data, (stk->capacity + 2)* sizeof(StackElem_t) + 2);
    }    
    
    stk->data[0] = L_DATA_KANAR;  // УСТАНОВКА НОВОЙ ЛЕВОЙ КАНАРЕЙКИ
    stk->data[stk->capacity + 1] = R_DATA_KANAR;    // УСТАНОВКА НОВОЙ ПРАВОЙ КАНАРЕЙКИ

    stk->data[stk->size + 1] = elem;
    stk->size++;
    STACK_ASSERT(stk);
}

/*---------------ФУНКЦИЯ ДЛЯ УДАЛЕНИЯ ЭЛЕМЕНТА СТЕКА---------------------------------------------------------------------------------------------*/
StackElem_t StackPop(Stack_t* stk)
{
    //printf("%s   NO ERRORS!   %s\n", RED, RESET);                                                                                                                                                                           //STACK_ASSERT(stk);
    if ((stk->size < (0.5 * stk->capacity)) && stk->size > 1)
    {
        if (stk->capacity > START_SIZE)
        {
            stk->data[0]                 = POISON; 
            stk->data[stk->capacity + 1] = POISON;  
            stk->capacity = stk->capacity / stk->koef_capacity; // УМЕНЬШЕНИЕ capacity

            stk->data = (StackElem_t*)realloc(stk->data, (stk->capacity + 2) * sizeof(StackElem_t));
            stk->data[0] = L_DATA_KANAR;                
        }
        else
        {
            //printf("%scapacity < START_SIZE\n%s", RED, RESET);
        }
            
    }  

    if (stk->size < 1)
    {
        printf("%s ERROR: size < 1\n%s", RED, RESET);
        return 1;
    }  

    StackElem_t temp = stk->data[stk->size - 1];   
    stk->data[stk->size] = 0;   
    stk->size--;
    //                                                                                                                                                                         /STACK_ASSERT(stk);
    return temp;
}