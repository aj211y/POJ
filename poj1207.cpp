//ÃD¥Ø¡G3n+1 
#include<iostream>
using namespace std;


int maxc=0;
int tree(int,int);
int main()
{
	int n,m,min,max,result;
	while(cin >> n >> m)
	{
		if(n==m&&n==0)
			break;
		if(n<m){
			max=m;
			min=n;
		}else{
			max=n;
			min=m;
		}
		result=tree(min,max);
		cout << n << " " << m << " " << result << "\n";
	}
	return 0;
}
int tree(int min,int max)
{
	int x,count,tmp;
	maxc=0;
	for(x=min;x<=max;x++){
		count=1;
		tmp=x;
		while(tmp!=1){
			if(tmp%2)
				tmp=tmp*3+1;
			else
				tmp=tmp/2;
			count++;
		}
		if(count>maxc)
			maxc=count;
	}
	return maxc;
}