// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _ABSTRACTUSER_HPP
#define _ABSTRACTUSER_HPP

#include <iostream>
#include <string>

/** === Region: class AbstractUser ===
 * @todo 管理员和读者共有功能
 * @param m_number string [读者 | 管理员] id
 * @param m_name string [读者 | 管理员] 名字
 */
class AbstractUser
{
public:
    std::string m_number;
    std::string m_name;
public:
    virtual ~AbstractUser() = 0;
    virtual bool findBook(const std::string& t_bookNameOrId) = 0;

    virtual void showInfo() = 0;
};

#endif //_ABSTRACTUSER_HPP

