// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _Reader_HPP
#define _Reader_HPP

#include "Book.hpp"
#include <iostream>
#include <string>
#include <vector>

/** === Region: class Reader ===
 * @param m_number string 编号
 * @param m_name string 姓名
 * @param book_vec vector 借走的书
 * @todo 读者信息至少应包括：编号、姓名、所借图书。
 * @todo 读者菜单包括借书、还书、查询等功能。
 */
class Reader
{
private:
    std::string m_number;
    std::string m_name;
    std::vector<Book> book_vec;
public:
    Reader(/* args */);
    ~Reader();
};

Reader::Reader(/* args */)
{
}

Reader::~Reader()
{
}

#endif //_Reader_HPP
