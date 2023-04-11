#include "Manager.hpp"
#include "Book.hpp"
#include "Reader.hpp"
#include "LibManageOS.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief 书籍借阅记录保存文件
 */
constexpr auto FILENAME = "BookBorrowingRecords.txt";

void LibManageOS::exitMenu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void LibManageOS::helpMenu()
{
    cout << "------------" << endl;
    cout << "Libsim (use this system)" << endl;
    cout << "-a xxx (use reader id log in, xxx is your id)" << endl;
    cout << "-u xxx (use manager id log in, xxx is your id)" << endl;
    cout << "more command dev now" << endl;
    cout << "------------" << endl;
}

void LibManageOS::readerMenu()
{
    cout << "---------------" << endl;
    cout << "-BTM (退至菜单)" << endl;
    cout << "-BB (借书)" << endl;
    cout << "-RB (还书)" << endl;
    cout << "-CB (查询书籍)" << endl;
    cout << "---------------" << endl;
}

void LibManageOS::managerMenu()
{
    cout << "---------------" << endl;
    cout << "-BTM (退至菜单)" << endl;
    cout << "-AB (添加书籍)" << endl;
    cout << "-AR (添加读者)" << endl;
    cout << "---------------" << endl;
}

void LibManageOS::save()
{
    ofstream system_ofs;
    ofstream reader_ofs;
	system_ofs.open(FILENAME, ios::out);
    reader_ofs.open("reader.txt", ios::out);
    for (auto &&attribute : m_book_vec)
    {
        system_ofs << attribute.m_id << "\t" << attribute.m_name << "\t" << attribute.m_quantity << endl;
    }
    
    for (auto &&attribute : m_reader_map)
    {
        reader_ofs << attribute.first.m_number << "\t" << attribute.first.m_name << "\t";
        for (auto &&t_vec : attribute.first.m_book_vec)
        {
            reader_ofs << t_vec.m_id << "\t" << t_vec.m_name << "\t";
        }
        reader_ofs << attribute.second << endl;
    }
    
	ofs.close();
}

void LibManageOS::init()
{
    ifstream system_ifs;
    ofstream reader_ifs;
	system_ifs.open(FILENAME, ios::in);
    reader_ifs.open("reader.txt", ios::out);

    for (auto &&attribute : m_book_vec)
    {
        system_ifs >> attribute.m_id >> attribute.m_name >> attribute.m_quantity;
    }
    for (auto &&attribute : m_reader_map)
    {
        reader_ifs >> attribute.first.m_number >> attribute.first.m_name;
        for (auto &&t_vec : attribute.first.m_book_vec)
        {
            reader_ifs >> t_vec.m_id >> t_vec.m_name;
        }
        reader_ifs >> attribute.second;
    }
    
	ifs.close();
}

void LibManageOS::readerSystem()
{

}

void LibManageOS::manageSystem()
{
    string str;
    while (1)
    {
        this->managerMenu();
        getline(cin, str);
        
    }
    
}
