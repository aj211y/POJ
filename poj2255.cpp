#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#define Max 700000
using namespace std;

char list[Max];
map<char,int> dic;
bool visited[30];
string inord,preord;
int now;
void rebuild_tree(char c,int id)
{
	int inord_id;
	list[id]=c;
	inord_id=dic[c];
	visited[inord_id]=true;
	if(!visited[inord_id-1])//左邊有點
		rebuild_tree(preord[++now],id*2);
	if(!visited[inord_id+1])//右邊有點
		rebuild_tree(preord[++now],id*2+1);
}
void print(int id)
{
	if(list[id*2]!='\0')//左邊還有
		print(id*2);
	if(list[id*2+1]!='\0')//右邊還有
		print(id*2+1);
	printf("%c",list[id]);
}
int main()
{
	
	int i;
	while(cin>>preord>>inord)
	{
		for(i=0;i<inord.size();i++)
			dic[inord[i]]=i+1;
		memset(visited,false,sizeof(visited));
		visited[0]=true;//begin
		visited[i+1]=true;//end
		memset(list,(int)'\0',sizeof(list));
		now=0;//preord's id
		rebuild_tree(preord[0],1);
		print(1);
		printf("\n");
		dic.clear();
	}
	return 0;
}