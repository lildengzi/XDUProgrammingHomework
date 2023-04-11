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
 * @class AbstractUser
 * @param m_number string 编号
 * @param m_name string 姓名
 * @param book_vec vector<Book> 借走的书
 * @todo 读者信息至少应包括：编号、姓名、所借图书。
 * @todo 读者菜单包括借书、还书、查询等功能。
 */
template<class Book_attribute>
class Reader: public AbstractUser
{
public:
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
    /**
     * @brief 借书
     * 
     * @param t_bookNameOrId 传入书籍id或名字
     * @return bool
     *      @retval true 借书成功
     *      @retval false 借书失败
     */
    bool borrowBook(const Book_attribute& t_bookNameOrId)
    {        
        for (int i = 0; i < count; i++) // 不同书籍数量
        {
            
            if (book->isBookExit(t_bookNameOrId))
            {
                
                if (book->isFullyBorrowed())
                {
                    /* code */
                }
                
            }
            
        }
        return false;
    }
    /**
     * @brief 还书
     * 
     * @param t_bookNameOrId 传入书籍id或名字
     * @return bool
     *      @retval true 还书成功
     *      @retval false 还书失败
     */
    bool returnBook(const Book_attribute& t_bookNameOrId)
    {

        return false;
    }

};

#endif //_Reader_HPP
