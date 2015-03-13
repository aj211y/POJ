#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char s[100000],t[100000];
int main()
{
	int i,j,s_len,t_len;
	while(scanf("%s",s)!=EOF)
	{
		scanf("%s",t);
		s_len=strlen(s);
		t_len=strlen(t);
		//printf("%d %d\n",s_len,t_len);
		for(i=0,j=0;i<t_len&&j<s_len;i++)
		{
			//printf("%c %c\n",s[j],t[i]);
			if(s[j]==t[i])
				j++;
		}
		if(j<s_len)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}