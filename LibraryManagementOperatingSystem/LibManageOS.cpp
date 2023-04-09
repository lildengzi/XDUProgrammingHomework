#include "Manager.hpp"
#include "Book.hpp"
#include "Reader.hpp"
#include "LibManageOS.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LibManageOS::helpMenu()
{
    cout << "------------" << endl;
    cout << "---0.退出---" << endl;
    cout << "---1.登录---" << endl;
}

void LibManageOS::readerMenu()
{
    cout << "---------------" << endl;
    cout << "---0.退至菜单---" << endl;
    cout << "---1.借书------" << endl;
    cout << "---2.还书------" << endl;
    cout << "---3.查询书籍---" << endl;
}

void LibManageOS::managerMenu()
{
    cout << "---------------" << endl;
    cout << "---0.退至菜单---" << endl;
    cout << "---1.添加书籍---" << endl;
    cout << "---2.修改书籍信息--" << endl;
    cout << "---3.查询书籍---" << endl;
}

void LibManageOS::save()
{

}

void LibManageOS::init()
{

}

void LibManageOS::run()
{

}

void LibManageOS::addReader()
{

}

void LibManageOS::addBook()
{

}
