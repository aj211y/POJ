/*
KMP
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char str[1000050];
int next[1000050];
int main()
{
	int i,j,len;
	while(scanf("%s",str)!=EOF)
	{
		if(str[0]=='.')
			break;
		len=strlen(str);
		i=0;
		j=-1;
		next[0]=-1;
		while(i<len)
		{
			if(j==-1 || str[i]==str[j])
			{
				i++;
				j++;
				next[i]=j;
			}
			else
				j=next[j];
		}
		//求原本的string可以由幾個substring(要最多個)組成
		if(len%(len-next[len])==0)
			printf("%d\n",len/(len-next[len]));
		else
			printf("1\n");
	}
	return 0;
}