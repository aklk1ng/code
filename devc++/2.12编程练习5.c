#include <stdio.h>
int br(void); //��������                    //intҲ����void 
int ic(void); //��������                    //intҲ����void 

int br(void) //���庯��                     //intҲ����void 
{
	printf("Brazil,Russia,\n");
}
int  ic(void) //���庯��                     //intҲ����void 
{
	printf("India,China\n");
}
int main()
{
	system("color 0a");
	br(); //�������� 
	ic(); //�������� 
	ic(); //�������� 
	br(); //�������� 
	
	getchar();
	return 0;
	
}
