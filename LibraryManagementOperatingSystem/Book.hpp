// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _Book_HPP
#define _Book_HPP

#include <iostream>
#include <string>

/** === Region: class Book ===
 * @todo 图书信息至少应包括：编号、书名、数量，
 * @brief Book 书
 * @param m_id string 书的编号.
 * @param m_name string 书名.
 * @param m_quantity unsigned short int 书的数量.
 */
class Book
{
private:
    std::string m_id;
    std::string m_name;
    unsigned short int m_quantity;
public:
    /**
     * @brief Construct a new Book object
     * @param id 
     * @param name 
     * @param quantity
     */
    Book(const std::string& id, const std::string& name, const unsigned short int& quantity): m_id(id), m_name(name), m_quantity(quantity)
    {

    }

    /**
    * @brief isFullyBorrowed 书是否被借走
    * @details 程序唯一入口
    * @return bool
    *     @retval true 书被借完
    *     @retval false 书没被借完
    * @note None
    */
    bool isFullyBorrowed() const
    {
        return (this->m_quantity == 0);
    }
};

#endif //_Book_HPP
