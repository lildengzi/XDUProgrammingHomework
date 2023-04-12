#pragma once
#include <iostream>
#include <map>

/** === Region: class LibManageOS ===
 * @class LibManageOS
 * @todo 命令行参数如下：
         Libsim –a(-u) xxxx
         第一个参数为可执行程序名称；第二个参数为用户身份，-a表示管理员，-u表示读者；第三个参数为用户名
 * @brief 命令处理
 * @param command 操作指令集
 */
class Command
{
public:

public:
    /**
     * @brief 从命令行中获取命令并解析
     * @todo 解析命令
     * @param command 字符串
     * @return int 命令行转化成整型
     *      @retval 0 退出系统
     *      @retval 1 帮助文档
     *      @retval 2 读者菜单
     *      @retval 3 管理员菜单    
     */
    int receiveCommand(const std::string& command)
    {
        return 0;
    }
    /**
     * @brief 从switch语句中获取命令并解析
     * @todo 解析命令
     * @param command 字符串
     * @return int 命令行转化成整型
     *      @retval 0 退出系统
     *      @retval 1 帮助文档
     *      @retval 2 读者菜单
     *      @retval 3 管理员菜单    
     */
    int receiveCommand(const std::string& command, int)
    {
        return 114514;
    }

    int receiveCommand(const std::string& command, bool)
    {
        return 114514;
    }
};