#pragma once
#ifndef _CSTACK_H
#define _CSTACK_H

#include <stdio.h>
#include <malloc.h>
/**
 * @brief 堆栈值域
 * @param m_elem 存放的值
 */
typedef struct Stack_range
{
    //栈值
    int m_elem;
    struct Stack_range *prev;
}Stack_range;
/**
 * @brief 堆栈
 * @param top 栈顶元素
 * @param count 栈位上限
 * @param next 栈值域
 * @param head 头节点
 */
typedef struct
{
    //栈顶元素
    int top;
    //栈位上限
    int count;
    //栈值域
    struct Stack_range *curr;
    struct Stack_range *head;
}Stack;
/**
 * @brief 判断栈是否为满
 * 
 * @param S 传入栈
 * @return int 
 *      @retval 1 是
 *      @retval 0 否
 */
int isFull(Stack S)
{
    if (S.count == 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}
/**
 * @brief 判断栈是否为空
 * 
 * @param S 传入栈
 * @return int 
 *      @retval 1 是
 *      @retval 0 否
 */
int isEmpty(Stack S)
{
    if (S.count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    return 0;
}
/**
 * @brief 判断栈是否为满
 * 
 * @param S 传入栈
 * @param elem 压入元素
 * @return void
 */
void push(Stack *S, int elem)
{
    if (isFull(*S))
    {
        printf("压入失败，栈已满");
    }
    else if(S->head == NULL)
    {
        S->curr = (Stack_range*)malloc(sizeof(Stack_range));
        S->curr->m_elem = elem;
        S->head = S->curr;
        S->curr->prev = NULL;
        S->top = elem;
        S->count++;
    }
    else
    {
        S->curr->prev = (Stack_range*)malloc(sizeof(Stack_range));
        S->curr->prev->m_elem = elem;
        S->curr = S->curr->prev;
        S->curr->prev = NULL;
        S->top = elem;
        S->count++;
    }
}
/**
 * @brief 删除并返回S的栈顶元素
 * 
 * @param S 传入栈
 * @return int 栈顶元素
 */
int pop(Stack *S)
{
    if (isEmpty(*S))
    {
        printf("删除失败");
    }
    else if(S->head == S->curr)
    {
        int temp_top = S->top;
        free(S->curr);
        S->head = NULL;
        S->curr = NULL;
        return temp_top;
    }
    else
    {
        int temp_top = S->top;
        for (Stack_range* s = S->head; ; s = s->prev)
        {
            if (s->prev->prev == NULL)
            {
                S->curr = s;
                free(s->prev);
                s->prev = NULL; 
                break;
            }
        }
        return temp_top;
    }
    return 2147483647;
}

void showStack(Stack S)
{
    for (Stack_range *s = S.head; s != NULL; s = s->prev)
    {
        printf("%d \n", s->m_elem);
    }
}

#endif //_CSTACK_H
