/**
 * @file LibMangeOS.hpp
 * @author lil_DengZi
 * @brief 
 * @version 0.1beta
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

// === Region: Headers ===
// iostream, string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _LIBMANAGEOS_HPP
#define _LIBMANAGEOS_HPP

#include "Manager.hpp"
#include "Book.hpp"
#include "Reader.hpp"
#include "command.hpp"

#include <iostream>
#include <string>

/** === Region: class LibManageOS ===
 * @todo helpMenu 帮助菜单
 *       readerMenu 读者菜单
 *       managerMenu 管理员菜单  
 * @brief 图书馆操作系统,用户分为管理员和读者两类，分别显示不同文本格式菜单，
 * 通过菜单项对应数字进行选择。可根据图书名称或编号进行图书信息查询，可查询某本书现在被哪些读者借走。
 * @param m_book_vec 保存书籍信息
 * @param m_reader_map 保存读者信息和密码
 */
class LibManageOS
{
    friend class Command;
public:
    std::vector<Book> m_book_vec;
    std::map<Reader, std::string> m_reader_map;
public:

    /**
     * @brief 退出程序
     */
    inline void exitMenu();
    /**
    * @brief 主函数
    * @details 程序唯一入口
    *
    * @param argc 命令参数个数
    * @param argv 命令参数指针数组
    * @return 程序执行成功与否
    *     @retval 0 程序执行成功
    *     @retval 1 程序执行失败
    * @note 这里只是一个简单的例子
    */
    inline void helpMenu();
    void readerMenu();
    void managerMenu();
    /**
     * @brief 保存文件
     * 保存内容包含
     */
    void save();
    /**
     * @brief 初始化文件
     * 
     */
    void init();
    /**
     * @brief 读者信息
     * 
     */
    void readerSystem();
    void manageSystem();
};

#endif //_LIBMANAGEOS_HPP
