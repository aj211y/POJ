#include<iostream>
#include<cstdio>
using namespace std;
int memory[21][21][21]={0};

int funcw(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(a>20 || b>20 || c>20)
		return funcw(20,20,20);
	if(memory[a][b][c])
		return memory[a][b][c];
	if(a<b && b<c)
		memory[a][b][c]=funcw(a,b,c-1)+funcw(a,b-1,c-1)-funcw(a,b-1,c);
	else
		memory[a][b][c]=funcw(a-1,b,c)+funcw(a-1,b-1,c)+funcw(a-1,b,c-1)-funcw(a-1,b-1,c-1);
	return memory[a][b][c];
}
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		if(a==b&&b==c&&a==-1)
			break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,funcw(a,b,c));
	}
	return 0;
}