// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _Reader_HPP
#define _Reader_HPP

#include "AbstractUser.hpp"
#include "Book.hpp"

#include <iostream>
#include <string>
#include <vector>

/** === Region: class Reader ===
 * @param m_number string 编号
 * @param m_name string 姓名
 * @param book_vec vector<Book> 借走的书
 * @todo 读者信息至少应包括：编号、姓名、所借图书。
 * @todo 读者菜单包括借书、还书、查询等功能。
 */
class Reader: public AbstractUser
{
public:
    std::string m_number;
    std::string m_name;
    std::vector<Book> m_book_vec;
public:

    /**
     * @brief Construct a new Reader object
     * 
     * @param number 
     * @param name 
     */
    Reader(const std::string& number, const std::string& name): m_number(number), m_name(name)
    {
        m_book_vec{0};
    }

    bool borrowBook()
    {
        std::string t_bookName;
        std::cout << "请输入你想要借的书籍名" << std::endl;
        std::cin >> t_bookName;
        
        for (int i = 0; i < count; i++) // 不同书籍数量
        {
            unique_ptr<Book>u_ptr_book(nullptr);
            if (book->isBookExit(t_bookName))
            {
                
                if (book->isFullyBorrowed())
                {
                    /* code */
                }
                
            }
            
        }
        
        
        return false;
    }

    bool returnBook()
    {
        return false;
    }

};

#endif //_Reader_HPP
