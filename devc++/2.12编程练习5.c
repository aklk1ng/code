#include <stdio.h>
int br(void); //声明函数                    //int也可用void 
int ic(void); //声明函数                    //int也可用void 

int br(void) //定义函数                     //int也可用void 
{
	printf("Brazil,Russia,\n");
}
int  ic(void) //定义函数                     //int也可用void 
{
	printf("India,China\n");
}
int main()
{
	system("color 0a");
	br(); //函数调用 
	ic(); //函数调用 
	ic(); //函数调用 
	br(); //函数调用 
	
	getchar();
	return 0;
	
}
