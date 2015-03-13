//字母編譯成密碼  單一字母有分別對應到
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int a=-1,result=1,b=-1,f=0,cc=1,aa=1;
	string code,answer;
	vector<int> cod,co;
	vector<int> ans,an;
	while(getline(cin,code)){
		//getline(cin,code);
		getline(cin,answer);
		a=-1;
		result=1;
		if(code.size()!=answer.size())
			result=0;
		else{
			while(++a<code.size()){
				cod.push_back(code[a]-'\0');
				ans.push_back(answer[a]-'\0');
			}
			sort(cod.begin(),cod.end());
			sort(ans.begin(),ans.end());
			a=-1;
			while(++a<cod.size()){
				if(a==(cod.size()-1))
					co.push_back(cc);
				else if(cod[a]!=cod[a+1] && a+1!=cod.size()){
					co.push_back(cc);
					cc=1;
				}
				else
					cc++;
				if(a==(cod.size()-1))
					an.push_back(aa);
				else if(ans[a]!=ans[a+1] && a+1!=cod.size()){
					an.push_back(aa);
					aa=1;
				}
				else
					aa++;
			}
			sort(co.begin(),co.end());
			sort(an.begin(),an.end());
			a=-1;
			while(++a<co.size()){
				if(co[a]!=an[a]){
					result=0;
					break;
				}
			}
		}
		if(!result)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}