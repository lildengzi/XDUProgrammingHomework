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
 * @class Book
 * @todo 图书信息至少应包括：编号、书名、数量，
 * @param m_id string 书的编号
 * @param m_name string 书名
 * @param m_quantity unsigned short int 书的数量
 */
class Book
{
private:
    std::string m_id;
    std::string m_name;
    unsigned short int m_quantity;
public:
    Book(const std::string& id, const std::string& name, const unsigned short int& quantity): m_id(id), m_name(name), m_quantity(quantity)
    {

    }

    isFullyBorrowed() const
    {
        return (this->m_quantity == 0);
    }

    
};

#endif //_Book_HPP
