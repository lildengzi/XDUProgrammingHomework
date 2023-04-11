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
};

#endif //_ABSTRACTUSER_HPP

