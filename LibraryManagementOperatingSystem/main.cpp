/**
 * @file main.cpp
 * @author lil_DengZi
 * @brief ͼ��ݹ���ϵͳ
 * @version 0.1
 * @date 2023-04-10
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

// === Region: Headers ===
// Do not include extra header files
// =======================
#include "LibManageOS.h"
#include <iostream>
#include <memory>
using namespace std;

/**
 * @brief ������
 * @details ����Ψһ���
 *
 * @param[in] argc �����������
 * @param[in] argv �������ָ������
 * @return ����ִ�гɹ����
 *     @retval 0 ����ִ�гɹ�
 *     @retval 1 ����ִ��ʧ��
 * @note ����ֻ��һ���򵥵�����
 */
int main(int argc, char* argv[])
{
    LibManageOS *os = new LibManageOS;
	string str = *argv;
	/**
	 * @code {.Libsim -a 2203}
	 * if(strcmp("Libsim", argv[0]))
	 * {
	 * 		for(int i = 1; i < argc; i++)
	 * 		{
	 * 			if(strcmp("-a", argv[i]))
	 * 			{
	 * 				
	 * 			}
	 * 			...
	 * 		}
	 * }
	 * else if(strcmp("exit", argv[0]))
	 * {
	 * 	...
	 * }
	 * else
	 * {
	 * 		cerr << "ERROR" << endl;
	 * }
	 * 
	 * cout << "~su username >>>";
	 * @endcode
	 */
	while (true)
	{
		os->helpMenu();
		switch (os->command.receiveCommand(str))//��ȡ�����Ӧ����ֵ
		{
		case 0: //�˳�
			os->exitMenu();
			break;
		case 1: //�����ĵ�
			os->helpMenu();
			break;
		case 2://���߲˵�
			os->readerSystem();
			break;
		case 3://����Ա�˵�
			os->manageSystem();
			break;
		default:
			cout << "����������" << endl;
			break;
		}
		system("pause");
	}

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
