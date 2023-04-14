/**
 * @file LibManageOS.h
 * @author lil_DengZi
 * @brief 
 * @version v0.1beta
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
#include <map>
#include <vector>
#include <memory>
#include <fstream>

/** === Region: class LibManageOS ===
 * @brief 图书馆操作系统,用户分为管理员和读者两类，
 * 分别显示不同文本格式菜单，通过菜单项对应数字进行选择。
 * 可根据图书名称或编号进行图书信息查询，可查询某本书现在被哪些读者借走。
 * @param m_book_vec 保存书籍信息
 * @param m_reader_map 保存读者信息和密码
 */
class LibManageOS
{
private:
    std::vector<Book> m_book_vec;
    std::map<std::string, Reader> m_reader_map;
public:
    Command command;
public:
    LibManageOS();
    ~LibManageOS();

    /**
     * @brief 退出程序
     */
    void exitMenu();
    void helpMenu();
    /**
    * @brief 读者菜单
    */
    void readerMenu();
    /**
    * @brief 管理者菜单
    */
    void managerMenu();

    /**
     * @brief 保存文件
     * 保存内容
     * 读者信息 书籍信息
     */
    void save();
    /**
     * @brief 初始化文件
     * 初始化内容
     * 读者信息 书籍信息
     */
    void init();

    /**
     * @brief 读者系统
     */
    void readerSystem();
    /**
     * @brief 注册
     */
    void signUp();

    /**
     * @brief 管理者系统
     */
    void manageSystem();
    /**
     * @brief 添加书籍
     * @todo
     * @param t_id 书籍id
     * @param t_name 书籍名
     * @param t_quantity 进货数量
     * @return bool 
     *      @retval true 添加成功
     *      @retval false 添加失败
     */
    bool addBook();
    /**
     * @brief 添加读者
     * @todo
     * @param t_id 读者id
     * @param t_name 读者名
     * @return bool 
     *      @retval true 添加成功
     *      @retval false 添加失败
     */
    bool addReader();
};

#endif //_LIBMANAGEOS_HPP
