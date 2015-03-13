//左括弧和右括弧數
#include<iostream>
#include<string>
using namespace std;

string str;//紀錄左右括弧的序列
long int b=0,a=0;//b紀錄p序列中的上一個數  a紀錄str存到第幾位了
void build(long int x);//建立左括弧(l代表)及右括弧(r代表)在字串中的序列
void check(long int c);//轉換成w序列
int main()
{
	int t,n,tmp=0;
	long int x;
	cin >> t;
		while(t){
			cin >> n;
			str="0";
			b=0;
			a=0;
			tmp=0;
			while(tmp<n){
				cin >> x;
				build(x);
				tmp++;
			}
			for(long int c=0;c<=a;c++){
				if(str[c]=='r')
					check(c);
			}
			cout << endl;
			t--;
		}
	return 0;
}
void check(long int c)
{
	long int count=1,r=-1;
	for(long int d=c-1;d>=0;d--){
		if(str[d]=='l')
			r++;
		else if(str[d]=='r'){
			r--;
			count++;
		}
		if(r==0){  //找到與右括弧對應的左括弧
			cout << count << " "; //印出數字
			d=0;
		}
	}
}
void build(long int x)//建立左右括弧的序列
{
	for(long int c=0;c<(x-b);c++){
		str+='l';//string要這樣插入(如果一開始初始化只有string str，而沒有str[]，則插入時不能用[])
		a++;
	}
	str+='r';
	a++;
	b=x; //紀錄p序列中上一個數
}