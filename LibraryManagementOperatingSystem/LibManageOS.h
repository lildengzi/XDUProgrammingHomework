/**
 * @file LibMangeOS.hpp
 * @author lil_DengZi
 * @brief 
 * @version 0.1beta
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// === Region: Headers ===
// iostream, string,  are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _LIBMANAGEOS_HPP
#define _LIBMANAGEOS_HPP

#include "Manager.hpp"
#include "Book.hpp"
#include "Reader.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

/** === Region: class LibManageOS ===
 * @class LibManageOS
 * @todo 编写一个程序模拟图书管理系统。用户分为管理员和读者两类，分别显示不同文本格式菜单，
 *       通过菜单项对应数字进行选择。
 *       可根据图书名称或编号进行图书信息查询，可查询某本书现在被哪些读者借走。
 * @todo anything
 * @brief 这是操作系统
 */
class LibManageOS
{
public:

    void helpMenu();
    void readerMenu();
    void managerMenu();
    void save();
    void init();
    void run();
    void addReader();
};

#endif //_LIBMANAGEOS_HPP
