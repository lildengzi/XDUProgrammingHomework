#pragma once

#include "LibManageOS.h"

#include <iostream>
#include <string>

/** === Region: class Command ===
 * @class Command
 * @todo 命令行参数如下：
         Libsim –a(-u) xxxx
         第一个参数为可执行程序名称；第二个参数为用户身份，-a表示管理员，-u表示读者；第三个参数为用户名
 * @brief 命令处理
 * @param command 操作指令集
 */
class Command
{
public:
    /**
     * @brief 从命令行中获取命令并解析
     * @todo 解析命令
     * @param t_command 字符串
     * @return int 命令行转化成整型
     *      @retval 0 退出系统
     *      @retval 1 帮助文档
     *      @retval 2 读者菜单
     *      @retval 3 管理员菜单    
     */
    int receiveCommand(const std::string& t_command)
    {
        if (t_command.compare("Libsim"))
        {
            if (t_command.compare("-u"))
            {
                return 1;
            }
            
            if (t_command.compare("-a"))
            {
                int pos = ;
                std::string t_str = t_command.substr(t_command.find("-u") + 2, t_command.length() - 1);
                if (t_str == "123456")
                {
                    std::cout << "user manager log in" << std::endl;
                    return 3;
                }
                else
                {
                    std::cout << "error" << std::endl;
                }
                return 114514;
            } 
            else if (t_command.find("-u") != -1)
            {
                int pos = t_command.find("-u");
                if (t_str == )
                {

                }
            }
        }
        else if (t_command.find("exit") != -1)
        {
            return 0;
        }
        else
        {
            return 114514;
        }
        return 114514;
    }
    /**
     * @brief 读者系统，从switch语句中获取命令并解析
     * @todo 解析命令
     * @param t_command 字符串
     * @return int 命令行转化成整型
     *      @retval 0 退出
     *      @retval 1 注册
     *      @retval 2 借书
     *      @retval 3 还书
     *      @retval 4 查询    
     */
    int receiveCommand(const std::string& t_command, int)
    {
        if (t_command.find(" "))
        {
            /* code */
        }
        
        return 114514;
    }
    /**
     * @brief 管理系统，从switch语句中获取命令并解析
     * @todo 解析命令
     * @param t_command 字符串
     * @return int 命令行转化成整型
     *      @retval 0 退出
     *      @retval 1 添加书籍
     *      @retval 2 添加读者
     *      @retval 3 查询书籍
     */
    int receiveCommand(const std::string& t_command, bool)
    {
        return 114514;
    }
};