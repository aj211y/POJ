#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	bool flag=0;
	int i,N;
	string dic[105],tmp[105],str;
	for(i=0;;i++){//�ئr��
		cin >> dic[i];
		if(dic[i][0]=='X')
			break;
	}
	N=i;
	sort(dic,dic+i);//�}�Csort �r��Ƨ�
	for(i=0;i<N;i++){
		//cout<<dic[i]<<endl;
		tmp[i]=dic[i];
		sort(dic[i].begin(),dic[i].end());//��r���Ƨ�
		//cout<<dic[i]<<endl;
	}
	while(cin >> str){
		flag=0;
		if(str[0]=='X')
			break;
		sort(str.begin(),str.end());
		for(i=0;i<N;i++){
			if(str==dic[i]){
				flag=1;
				cout << tmp[i] << endl;
			}
		}
		if(!flag)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}