/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-05
 * @include LibManageOS.hpp Book.hpp Reader.hpp Manager.hpp
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#include "LibManageOS.hpp"
#include "command.hpp"
#include <iostream>
using namespace std;

/**
 * @brief 
 * @warning �ó��򻹲�������
 */
int main(int argc, char* argv[])
{
    while (1)
    {
        string command[100];
        Command CMD;
        switch (argv[1])
        {
        case CMD.selfCommand(CMD.command[0]):
            cout << "a" << endl;
            // deviceOpen();
            break;
        case CMD.selfCommand(CMD.command[3]):
            cout << "b" << endl;
            // deviceClose();
            break;
        case CMD.selfCommand(CMD.command[0]):
            cout << "c" << endl;
            // deviceQuery();
            break;
        default:
            cout << "������ĸ�ʽ��������������" << endl;
            break;
        }
    }
    
    getchar();
    return 0;
}

/*���ļ����ݿ�-ģ��ͼ��ݹ���ϵͳ

�漰֪ʶ�㣺�ļ���д���ڴ�����ṹ�嶨�塢�������ݽṹ���߼���ʽ���������

Ҫ��

��дһ������ģ��ͼ�����ϵͳ���û���Ϊ����Ա�Ͷ������࣬�ֱ���ʾ��ͬ�ı���ʽ�˵���
ͨ���˵����Ӧ���ֽ���ѡ��
�ɸ���ͼ�����ƻ��Ž���ͼ����Ϣ��ѯ���ɲ�ѯĳ�������ڱ���Щ���߽��ߡ�

�ص㣺

�����ܣ����˵����Ӳ˵����û���ݣ����ߡ�����Ա����

���˼�룺�ṹ��������ƣ��Զ����£��������ģ�飬�������ģ�顣ģ���ú���ʵ�֡�

���ݱ��棺�ļ����档�û���Ϣ��ͼ����Ϣ��һ���ĸ�ʽ�������ļ��С�

��������� ͷ��㣬β��㣬���ӽ�㣬ɾ����㣬������㡣*/