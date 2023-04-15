/**
 * @file CStack.c
 * @author lil_DengZi
 * @brief c����ģ��stack
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "CStack.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int selection;
    int elem;
    Stack s;
    s.head = NULL;
    s.count = 0;

    while (1)
    {
        printf("��ѡ��,1:��ջ,2:��ջ,0:�˳�����\n");
        
        scanf("%d", &selection); // �����û���ѡ��
        switch (selection) // 0�˳�
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("�������ջԪ��:\n");
            scanf("%d", &elem); // ������ջԪ��
            push(&s, elem);
            showStack(s);
            break;
        case 2:
            printf("ɾ����%dԪ��\n", pop(&s));
            showStack(s);
            break;
        default:
            printf("�����������������\n");
            break;
        }
    }
    return 0;
}