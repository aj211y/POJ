//QuickSum  大寫的英文字母由A到Z分別代表1~26 ACM=1*1+2*3+3*13=46  A C M=1*1+2*0+3*3+4*0+5*13=75
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int result=0,a=0;
	while(getline(cin,str)){
		a=0;
		result=0;
		if(str=="#")
			break;
		else{
			while(a<str.size()){
				if(str[a]==' ')
					result=result+(a+1)*0;
				else
					result=result+(a+1)*(str[a]-'\0'-64);
				a++;
			}
		}
		cout << result << endl;
	}
	return 0;
}