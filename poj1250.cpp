//tanning salong 排隊問題
//1 ABCCAB  1或2人離開答案都對
#include<iostream>
#include<cstring>
using namespace std;

int bed=0,stand=0,go=0;
string Q;
void add(int);
void del();
int away(int);
int main()
{
	int num,same=0;
	string str;
	
	while(cin >> num){
		if(num==0)
			break;
		else{
			cin >> str;
			bed=num;//床位數
			go=0;//紀錄有幾人生氣的離開
			stand=0;
			Q="0";
			if(str.size()%2)
				go=-1;
			for(int a=0;a<str.size();a++){//將字串一個一個拆解去比對
				same=0;
				for(int b=0;b<a;b++){//比對有沒有跟自己之前的字母一樣
					if(str[a]==str[b]){//有的話則表示有人要離開 但還不知道是有床睡還是沒得睡的人
						same=1;
						if(!away(b)) //從away()可以知道是哪一種人要離開  傳過去的b表示他在str第一次出現時的位置
							del();//有床睡的人要離開 
						b=a;//讓他可以馬上跳出迴圈
					}	
				}
				if(!same)
					add(a);//check in人數+1
			}
		}
		if(!go)
			cout << "All customers tanned successfully."<< endl;
		else if(go==-1)
			cout << "No one comes."<< endl;
		else
			cout << go <<" customer(s) walked away.\n";
	}
	return 0;
}
void add(int a)
{
	if(!bed)//如果沒床睡了 則將沒床睡之人在str第一次出現的位置記錄在Q[] stand表示有幾人沒床睡
		Q[++stand]=a;
	else
		bed--;//床位少一
}
void del()
{
	int q=1;
	bed++;//有人離開床位加一
	if(stand){//若此時有人還在等待  則進住
		bed--;
		stand--;
		while(q<=stand){ //將等待的號碼牌往前移
			Q[q]=Q[q+1];
			q++;
		}
	}
}
int away(int b)
{
	int q=1;
	for(int t=1;t<=stand;t++){
		if(Q[t]==b){ //如果一樣  表示這個要走的人沒有睡到床
			q=t;
			t=--stand;//讓t能馬上跳出for迴圈stand等待人數少一
			while(q<=stand){ //將等待的號碼牌往前移
				Q[q]=Q[q+1];
				q++;
			}
			go++;//沒有做tanning就離開的人數
			return 1;//表示是等待中的人離開
		}
	}
	return 0;//表示是正在做tanning的人要離開
}