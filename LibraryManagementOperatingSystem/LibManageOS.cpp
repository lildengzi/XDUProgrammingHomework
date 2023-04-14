#include "LibManageOS.h"

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 书籍借阅记录保存文件
 */
constexpr auto FILENAME = "BookBorrowingRecords.txt";

LibManageOS::LibManageOS()
{
    this->init();
    this->book = nullptr;
    this->reader = nullptr;
    this->manager = nullptr;
}

LibManageOS::~LibManageOS()
{

}

void LibManageOS::exitMenu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

inline void LibManageOS::helpMenu()
{
    cout << "------------" << endl;
    cout << "Libsim (use this system)" << endl;
    cout << "-a xxx (use reader id log in, xxx is your id)" << endl;
    cout << "-u xxx (use manager id log in, xxx is your id)" << endl;
    cout << "more command dev now" << endl;
    cout << "------------" << endl;
}

inline void LibManageOS::readerMenu()
{
    cout << "---------------" << endl;
    cout << "-BTM (退至菜单)" << endl;
    cout << "-BB (借书)" << endl;
    cout << "-RB (还书)" << endl;
    cout << "-CB (查询书籍)" << endl;
    cout << "---------------" << endl;
}

inline void LibManageOS::managerMenu()
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
    
    for (auto &&[key, val] : m_reader_map)
    {
        reader_ofs << key << "\t" << val.m_number << "\t" << val.m_name << "\t";
        for (auto &&i : val.m_borrowBook_vec)
        {
            reader_ofs << i.m_id << "\t" << i.m_name << "\t";
        }
        reader_ofs << endl;
    }
	system_ofs.close();
    reader_ofs.close();
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

	system_ifs.close();
    reader_ifs.close();
}

void LibManageOS::readerSystem()
{
    string str;
    while (1)
    {
        this->readerMenu();
        getline(cin, str);
        switch (command.receiveCommand(str, 114514))
        {
        case 0://退至主菜单
            return;
        case 1://注册
            signUp();
            break;
        case 2://借书
            reader->borrowBook();
            break;
        case 3://还书
            reader->returnBook();
            break;
        case 4://查询
            if (reader->findBook())
            {
                cout << "为你查找成功" << endl;
            }
            else
            {
                cout << "没有找到" << endl;
            }
            break;
        default:
            cout << "你的输入有误" << endl;
            break;
        }
    }
}

void LibManageOS::signUp()
{

}

void LibManageOS::manageSystem()
{
    string str;
    while (1)
    {
        this->managerMenu();
        getline(cin, str);
        switch (command.receiveCommand(str, true))
        {
        case 0://退至主菜单
            return;
        case 1://添加书籍
            if (this->addBook())
                {cout << "添加书籍成功" << endl;}
            else
                {cout << "添加书籍失败" << endl;}
            break;
        case 2://添加读者
            if (manager->addReader())
                {cout << "添加读者成功" << endl;}
            else
                {cout << "添加读者失败" << endl;}
            break;
        case 3://查询书籍
            if (manager->findBook())
            {
                cout << "为你查找成功" << endl;
            }
            else
            {
                cout << "没有找到" << endl;
            }
            break;
        default:
            cout << "你的输入有误" << endl;
            break;
        }
    }    
}

bool LibManageOS::addBook()
{
    string t_id;
    string t_name;
    int t_quantity;
    cout << "请输入你想添加的书籍id和书籍名" << endl;
    cin >> t_id >> t_name >> t_quantity;
    unique_ptr<Book>book(new Book(t_id, t_name, t_quantity));
    if (book != nullptr)
    {
        this->m_book_vec.push_back(book);
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool LibManageOS::addReader()
{
    string t_id;
    string t_name;
    cout << "请输入你想添加的读者id和读者名" << endl;
    cin >> t_id >> t_name;
    unique_ptr<Reader>reader(new Reader(t_id, t_name));
    if (reader != nullptr)
    {
        cout << "请输入pin" << endl;
        this->m_reader_map;
        return true;
    }
    else
    {
        return false;
    }
    return false;
}