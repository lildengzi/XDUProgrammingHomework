/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-05
 * @include LibManageOS.hpp Book.hpp Reader.hpp Manager.hpp
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#include "LibManageOS.hpp"
#include "command.hpp"
#include <iostream>
using namespace std;

/**
 * @brief 
 * @warning 该程序还不能运行
 */
int main(int argc, char* argv[])
{
    while (1)
    {
        string command[100];
        Command CMD;
        switch (argv[1])
        {
        case CMD.selfCommand(CMD.command[0]):
            cout << "a" << endl;
            // deviceOpen();
            break;
        case CMD.selfCommand(CMD.command[3]):
            cout << "b" << endl;
            // deviceClose();
            break;
        case CMD.selfCommand(CMD.command[0]):
            cout << "c" << endl;
            // deviceQuery();
            break;
        default:
            cout << "你输入的格式有误，请重新输入" << endl;
            break;
        }
    }
    
    getchar();
    return 0;
}

/*简单文件数据库-模拟图书馆管理系统

涉及知识点：文件读写、内存管理、结构体定义、基本数据结构、高级格式化输入输出

要求：

编写一个程序模拟图书管理系统。用户分为管理员和读者两类，分别显示不同文本格式菜单，
通过菜单项对应数字进行选择。
可根据图书名称或编号进行图书信息查询，可查询某本书现在被哪些读者借走。

重点：

程序框架：主菜单，子菜单，用户身份（读者、管理员）；

设计思想：结构化程序设计，自顶向下，先设计主模块，再设计子模块。模块用函数实现。

数据保存：文件保存。用户信息，图书信息按一定的格式保存在文件中。

链表操作： 头结点，尾结点，增加结点，删除结点，创建结点。*/