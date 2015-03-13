#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int N,S,i,j,L[20500],pair=0;
	memset(L,0,sizeof(L));
	scanf("%d%d",&N,&S);
	for(i=0;i<N;i++)
	{
		scanf("%d",&L[i]);
	}
	sort(L,L+N);
	for(i=0,j=N-1;i<j;i++)
	{
		while((L[i]+L[j]) > S)
			j--;
		if(j<=i)
			break;
		pair+=j-i;
	}
	printf("%d\n",pair);
	return 0;
}
