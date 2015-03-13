//從A室移動桌子到B室
//房間配置如下
// 1 3 5 7 9    奇數一排
// 2 4 6 8 10   偶數一排
#include<iostream>
using namespace std;

int str[401];
void move(int r1,int r2);
void check();
int main()
{
	int testcase,table,room1,room2;
	cin >> testcase;
	//while(cin >> testcase){
		while(testcase){
			for(int b=0;b<=400;b++)
				str[b]=0;
			cin >> table;
			for(int a=0;a<table;a++){
				cin >> room1 >> room2;
				if(room1 < room2)
					move(room1,room2);
				else
					move(room2,room1);
			}
			check();
			testcase--;
		}
	//}
	return 0;
}
void move(int r1,int r2)
{
	if(!r1%2)//若r1為偶數，則其對面的奇數房間也要算進去，因為走廊是共用的
		r1--;
	if(r2%2)
		r2++;
	for(int a=r1;a<=r2;a++)
		str[a]++;
}
void check()
{
	int count=0;
	for(int a=1;a<=400;a++){
		if(str[a]>count)//找經過最多次的
			count=str[a];
	}
	cout << count*10 << endl;//所花時間
}