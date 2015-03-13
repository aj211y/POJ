//ncku17 尋找牛隻中生產牛奶數量最中間的牛
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int num,milk,result,tmp;
	scanf("%d",&num);
	vector<int> line;
	tmp=num;
	while(tmp--){
		scanf("%d",&milk);
		line.push_back(milk);
	}
	sort(line.begin(),line.end());
	result=line[num/2];
	cout << result << endl;
	return 0;
}