// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _Manager_HPP
#define _Manager_HPP

#include <iostream>
#include <string>

/** === Region: class Manager ===
 * @class Manager
 * @todo 管理员菜单包括图书和读者信息录入、修改和删除。
 * @param m_number string 编号
 */
class Manager
{
private:
   std::string m_number;

public:
    Manager(/* args */);
    ~Manager();
};

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}

#endif //_Manager_HPP
