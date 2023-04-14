// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _Manager_HPP
#define _Manager_HPP

#include "Book.hpp"
#include "AbstractUser.hpp"

#include <iostream>
#include <string>

/** === Region: class Manager ===
 * @class AbstractUser
 * @brief 管理员菜单包括图书和读者信息录入、修改和删除。
 * @param m_number string 编号 (from AbstractUser)
 * @param m_name string 姓名 (from AbstractUser)
 */
class Manager: public AbstractUser
{
private:

public:
    
    /**
     * @brief 管理员找书
     * @todo 
     * @param t_bookNameOrId 书名或id
     * @return bool 
     *      @retval true 添加成功
     *      @retval false 添加失败
     */
    bool findBook()
    {
        return false;
    }
    /**
     * @brief 展示管理员信息
     */
    void showInfo()
    {
        std::cout << this->m_number << "\t" << this->m_name;
        std::cout << std::endl;
    }
};

#endif //_Manager_HPP
