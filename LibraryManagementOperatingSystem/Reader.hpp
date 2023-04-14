// === Region: Headers ===
// iostream,string and vector are included.
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
 * @brief 读者菜单包括借书、还书、查询等功能。
 * @param m_number string 编号 (from AbstractUser)
 * @param m_name string 姓名 (from AbstractUser)
 * @param m_borrowBook_vec vector<Book> 借走的书
 */
class Reader: public AbstractUser
{
public:
    std::vector<Book> m_borrowBook_vec;
public:
    /**
     * @brief Construct a new Reader object
     * @param number 
     * @param name 
     */
    Reader(const std::string& number, const std::string& name)
    {
        m_number = number;
        m_name = name;
        m_borrowBook_vec.clear();
    }
    /**
     * @brief 借书
     * @todo
     * @param t_bookNameOrId 传入书籍id或名字
     * @return bool
     *      @retval true 借书成功
     *      @retval false 借书失败
     */
    bool borrowBook(const std::string& t_bookNameOrId)
    {        
        // for (int i = 0; i < count; i++) // 不同书籍数量
        // {
            
        //     if (this->isBookExit(t_bookNameOrId))
        //     {
                
        //         if (book->isFullyBorrowed())
        //         {
        //             /* code */
        //         }
                
        //     }
            
        // }
        return false;
    }
    /**
     * @brief 还书
     * @todo
     * @param t_bookNameOrId 传入书籍id或名字
     * @return bool
     *      @retval true 还书成功
     *      @retval false 还书失败
     */
    bool returnBook(const std::string& t_bookNameOrId)
    {
        return false;
    }
    /**
     * @brief 查找书籍
     * @todo
     * @param t_bookNameOrId 传入书籍id或名字
     * @return bool 查找是否成功
     *      @retval true 查找成功
     *      @retval false 查找失败
     */
    bool findBook()
    {
        return false;
    }
    /**
     * @brief 展示读者信息以及读者借阅书籍
     */
    void showInfo()
    {
        std::cout << this->m_number << "\t" << this->m_name << "\t";
        for (auto &&i : m_borrowBook_vec)
        {
            std::cout << i.m_id << "\t" << i.m_name << "\t";
        }
        std::cout << std::endl;
    }
};

#endif //_Reader_HPP
