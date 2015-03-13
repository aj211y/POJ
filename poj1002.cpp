#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
	int cases,tele,i,flag=0;
	string str;
	map<char,int> num;
	map<int,int> count;
	map<int,int>::iterator cit;
	num['A']=2;num['B']=2;num['C']=2;	num['D']=3;num['E']=3;num['F']=3;	num['G']=4;num['H']=4;num['I']=4;
	num['J']=5;num['K']=5;num['L']=5;	num['M']=6;num['N']=6;num['O']=6;	num['P']=7;num['R']=7;num['S']=7;
	num['T']=8;num['U']=8;num['V']=8;	num['W']=9;num['X']=9;num['Y']=9;
	scanf("%d",&cases);
	getchar();
	while(cases--){
		tele=0;
		getline(cin,str);
		for(i=0;i<str.size();i++){
			if(str[i]>=48 && str[i]<=57)//是數字
				tele=tele*10+(str[i]-48);
			else if(str[i]>=65 && str[i]<=89 && str[i]!=81)
				tele=tele*10+num[str[i]];
			else
				continue;
		}
		if(count.find(tele)==count.end())
			count[tele]=1;
		else
			count[tele]++;
	}
	for(cit=count.begin();cit!=count.end();cit++){
		if((*cit).second > 1){
			flag=1;
			printf("%03d-%04d %d\n",(*cit).first/10000,(*cit).first%10000,(*cit).second);//要記得補零
		}
	}
	if(!flag)
		printf("No duplicates.\n");
	return 0;
}