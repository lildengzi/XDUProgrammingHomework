/**
 * @file CStack.c
 * @author lil_DengZi
 * @brief c语言模拟stack
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
        printf("请选择,1:入栈,2:出栈,0:退出程序\n");
        
        scanf("%d", &selection); // 输入用户的选择
        switch (selection) // 0退出
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("请输入进栈元素:\n");
            scanf("%d", &elem); // 输入入栈元素
            push(&s, elem);
            showStack(s);
            break;
        case 2:
            printf("删除了%d元素\n", pop(&s));
            showStack(s);
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }
    return 0;
}