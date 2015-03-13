#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct DNA
{
	string str;
	int value,id;
};
bool cmp(DNA x,DNA y)
{
	if(x.value < y.value)
		return true;
	else if(x.value==y.value && x.id<y.id)
		return true;
	else
		return false;
}
int main()
{
	int n,m,i,j,A,C,G,T;
	DNA line[120];
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<m;i++)
	{
		A=0;
		C=0;
		G=0;
		T=0;
		line[i].value=0;
		line[i].id=i;
		getline(cin,line[i].str);
		for(j=n-1;j>=0;j--)
		{
			if(line[i].str[j]=='A')
				A++;
			else if(line[i].str[j]=='C')
			{
				C++;
				line[i].value+=A;
			}
			else if(line[i].str[j]=='G')
			{
				G++;
				line[i].value+=A+C;
			}
			else// if(line[i].str[j]=='T')
			{
				T++;
				line[i].value+=A+C+G;
			}
		}
	}
	sort(line,line+m,cmp);
	for(i=0;i<m;i++)
		cout << line[i].str << endl;
	return 0;
}