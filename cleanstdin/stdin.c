#include <stdio.h>

int main(int argc, char* argv[])
{
	char chInput = '0';
	printf("本程序功能：\n	1 验证字符输入 ，不满足要求时循环输入；\n	2 清空输入缓冲区fflush(stdin)的演示\n\n");
	printf("请输入a-z之间字符：");
	scanf("%c",&chInput);
	while(chInput >'z' || chInput < 'a')
	{
		fflush(stdin);									//清空输入缓冲区
		printf("\n输入字符不在 a-z之间，请重新输入");
		printf("请输入a-z之间字符：");
		scanf("%c",&chInput);
	}

	printf("输入正确!\n");
    fflush(stdin);	
    getchar();
	return 0;
}