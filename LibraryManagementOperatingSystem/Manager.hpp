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
#include <memory>

/** === Region: class Manager ===
 * @class Manager
 * @todo 管理员菜单包括图书和读者信息录入、修改和删除。
 * @param m_number string 编号
 */
class Manager: public AbstractUser
{
private:

public:
    bool addBook()
    {
        std::string t_id = "114514", t_name = "三体";
        int t_quantity = 0;
        std::cout << "请输入编号" << std::endl;
        std::cin >> t_id;
        std::cout << "请输入姓名" << std::endl;
        std::cin >> t_name;
        std::cout << "请输入书籍数量" << std::endl;
        std::cin >> t_quantity;
        std::unique_ptr<Book>uptr_book(new Book(t_id, t_name, t_quantity));
        if (uptr_book != 0)
        {
            std::cout << "添加成功" << std::endl;
            return true;
        }
        else
        {
            std::cout << "添加失败" << std::endl;
            return false;
        }

        return false;
    }


};

#endif //_Manager_HPP
