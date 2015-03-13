//uva10127 poj2551 p017
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x,sum,result;
	while(scanf("%d",&x)!=EOF){
		result=1%x;//用餘數來判斷
		sum=1;
		while(result){//有一點像直式除法，沒除盡就將下一位數的1又放進來繼續除
			result=(result*10+1)%x;
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}