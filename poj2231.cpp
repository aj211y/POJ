#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,last,tmp,N;
	long long int data,sum=0;
	vector<long long int> list;
	scanf("%d",&N);
	tmp=N;
	while(tmp--){
		scanf("%lld",&data);
		list.push_back(data);
	}
	sort(list.begin(),list.end());
	last=list.size()-1;
	tmp=N-1;//���I��U�I���X���u
	for(i=0;i<list.size();i++){	
		sum=sum+(list[last]-list[i])*tmp;
		tmp=tmp-2;//�s�����I�Ҿ֦����I�ӼƷ|��1�A�ӳ̱`�@��(���I��̫�@�I���Z��)�H�Q�ιL�ҥH�٭n�A��1
	}
	printf("%lld\n",sum*2);
	return 0;
}