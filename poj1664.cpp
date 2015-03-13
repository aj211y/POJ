//蘋果分盤子，遞迴
#include<iostream>
#include<cstdio>
using namespace std;

int count(int apple,int plate);
int main()
{
	int test,apple,plate,result;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&apple,&plate);
		result=count(apple,plate);
		printf("%d\n",result);
	}
	return 0;
}
int count(int apple,int plate)
{
	if(apple<0)
		return 0;//沒有這種可能
	if(apple==0 || plate==1)//如果沒有蘋果了，只有一種可能，那就是全部都空盤     盤子只剩一個的時候，只有一個可能，所有的蘋果都要放在那一個上面
		return 1;
	return count(apple-plate,plate)+count(apple,plate-1);//apple-plate表式每一個盤子都放一顆，那剩餘的蘋果再去跟盤子想有幾種排法
}															//蘋果數不變，盤數減一，表示有一個盤子是空的，那剩餘的盤子再去跟蘋果想有幾種排法
