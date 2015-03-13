#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int N,M,i,person,max,sec;
	map<int,int> people;
	map<int,int>::iterator it;
	vector<int> final;
	while(scanf("%d %d",&N,&M)!=EOF){
		max=sec=0;
		if(N==M&&N==0)
			break;
		for(i=0;i<M*N;i++){
			scanf("%d",&person);
			if(people.find(person)==people.end())//不在其中
				people[person]=1;
			else//剛剛出現過囉
				people[person]++;
		}
		for(it=people.begin();it!=people.end();it++){
			if((*it).second>max){
				sec=max;
				max=(*it).second;
			}else if((*it).second<max && (*it).second>sec)
				sec=(*it).second;
		}
		for(it=people.begin();it!=people.end();it++){
			if((*it).second==sec)
				final.push_back((*it).first);
		}
		sort(final.begin(),final.end());
		for(i=0;i<final.size();i++){
			printf("%d ",final[i]);
		}
		printf("\n");
		people.clear();
		final.clear();
	}
	return 0;
}