#include<iostream>
#include<string>
using namespace std;

int result[105]={0};
void count(string str);
int main()
{
	int b=0;
	string str;
	while(cin >> str){
		if(str=="0")
			break;
		count(str);
	}
	while(!result[b++]){}
	for(int a=b-1;a<105;a++){
		cout << result[a];
	}
	return 0;
}
void count(string str)
{
	for(int a=str.size()-1,b=104;a>=0;a--,b--){
		result[b]=result[b]+(str[a]-48);
		if(result[b]>=10){
			result[b-1]=result[b-1]+result[b]/10;
			result[b]=result[b]%10;
		}
	}
	
}