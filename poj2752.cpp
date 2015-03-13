#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int next[400010];
string str;
void build_next()
{
	int i,j,len;
	i=0;
	j=-1;
	len=str.size();
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
}
int main()
{
	int i,len;
	vector<int> ans;
	bool space;
	while(cin >> str)
	{
		ans.clear();
		build_next();
		len=str.size();
		i=len;
		ans.push_back(len);
		while(next[i]>0)
		{
			ans.push_back(next[i]);
			i=next[i];
		}
		sort(ans.begin(),ans.end());
		space=false;
		for(i=0;i<ans.size();i++)
		{
			if(space)
				printf(" ");
			space =true;
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}