/**
 * @file main.cpp
 * @author lil_DengZi
 * @brief 图书馆管理系统
 * @version 0.1
 * @date 2023-04-10
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

// === Region: Headers ===
// Do not include extra header files
// =======================
#include "LibManageOS.h"
#include <iostream>
#include <memory>
using namespace std;

/**
 * @brief 主函数
 * @details 程序唯一入口
 *
 * @param[in] argc 命令参数个数
 * @param[in] argv 命令参数指针数组
 * @return 程序执行成功与否
 *     @retval 0 程序执行成功
 *     @retval 1 程序执行失败
 * @note 这里只是一个简单的例子
 */
int main(int argc, char* argv[])
{
    LibManageOS *os = new LibManageOS;
	string str = *argv;
	/**
	 * @code {.Libsim -a 2203}
	 * if(strcmp("Libsim", argv[0]))
	 * {
	 * 		for(int i = 1; i < argc; i++)
	 * 		{
	 * 			if(strcmp("-a", argv[i]))
	 * 			{
	 * 				
	 * 			}
	 * 			...
	 * 		}
	 * }
	 * else if(strcmp("exit", argv[0]))
	 * {
	 * 	...
	 * }
	 * else
	 * {
	 * 		cerr << "ERROR" << endl;
	 * }
	 * 
	 * cout << "~su username >>>";
	 * @endcode
	 */
	while (true)
	{
		os->helpMenu();
		switch (os->command.receiveCommand(str))//获取命令对应整数值
		{
		case 0: //退出
			os->exitMenu();
			break;
		case 1: //帮助文档
			os->helpMenu();
			break;
		case 2://读者菜单
			os->readerSystem();
			break;
		case 3://管理员菜单
			os->manageSystem();
			break;
		default:
			cout << "你输入有误" << endl;
			break;
		}
		system("pause");
	}

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
