#pragma once
#include <iostream>


/** === Region: class LibManageOS ===
 * @class LibManageOS
 * @todo 命令行参数如下：
         Libsim –a(-u) xxxx
         第一个参数为可执行程序名称；第二个参数为用户身份，-a表示管理员，-u表示读者；第三个参数为用户名
 * @brief 命令类
 * @param command 操作指令集
 */
class Command
{
public:
    const char* command[10];
public:
    Command() 
    {
        this->command[0] = "Libsim";
        this->command[1] = "-a";
        this->command[2] = "-u";
        this->command[3] = "exit";
        this->command[4] = "help";
    }

    int toString(const char* str)
    {
        return str[0] + (str[1] ? toString(str + 1) : 0);
    }

    constexpr inline int selfCommand(const char* str)
    {
        return str[0] + (str[1] ? selfCommand(str + 1) : 0);
    }
};