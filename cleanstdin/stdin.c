#include <stdio.h>

int main(int argc, char* argv[])
{
	char chInput = '0';
	printf("�������ܣ�\n	1 ��֤�ַ����� ��������Ҫ��ʱѭ�����룻\n	2 ������뻺����fflush(stdin)����ʾ\n\n");
	printf("������a-z֮���ַ���");
	scanf("%c",&chInput);
	while(chInput >'z' || chInput < 'a')
	{
		fflush(stdin);									//������뻺����
		printf("\n�����ַ����� a-z֮�䣬����������");
		printf("������a-z֮���ַ���");
		scanf("%c",&chInput);
	}

	printf("������ȷ!\n");
    fflush(stdin);	
    getchar();
	return 0;
}