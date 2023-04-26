#pragma once
#ifndef _CSTACK_H
#define _CSTACK_H

#include <stdio.h>
#include <malloc.h>
/**
 * @brief ��ջֵ��
 * @param m_elem ��ŵ�ֵ
 */
typedef struct Stack_range
{
    //ջֵ
    int m_elem;
    struct Stack_range *prev;
}Stack_range;
/**
 * @brief ��ջ
 * @param top ջ��Ԫ��
 * @param count ջλ����
 * @param next ջֵ��
 * @param head ͷ�ڵ�
 */
typedef struct
{
    //ջ��Ԫ��
    int top;
    //ջλ����
    int count;
    //ջֵ��
    struct Stack_range *curr;
    struct Stack_range *head;
}Stack;
/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * 
 * @param S ����ջ
 * @return int 
 *      @retval 1 ��
 *      @retval 0 ��
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
 * @brief �ж�ջ�Ƿ�Ϊ��
 * 
 * @param S ����ջ
 * @return int 
 *      @retval 1 ��
 *      @retval 0 ��
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
 * @brief �ж�ջ�Ƿ�Ϊ��
 * 
 * @param S ����ջ
 * @param elem ѹ��Ԫ��
 * @return void
 */
void push(Stack *S, int elem)
{
    if (isFull(*S))
    {
        printf("ѹ��ʧ�ܣ�ջ����");
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
 * @brief ɾ��������S��ջ��Ԫ��
 * 
 * @param S ����ջ
 * @return int ջ��Ԫ��
 */
int pop(Stack *S)
{
    if (isEmpty(*S))
    {
        printf("ɾ��ʧ��");
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
