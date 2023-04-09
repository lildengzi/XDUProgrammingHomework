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
    Book(/* args */);
    ~Book();
};

Book::Book(/* args */)
{
}

Book::~Book()
{
}

#endif //_Book_HPP
