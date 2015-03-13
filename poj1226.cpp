#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

vector<string> list;
int sub_next[105],inv_next[105];
bool cmp(string a,string b)
{
	if(a.size()<b.size())
		return true;
	else
		return false;
}
void find_next(string str)
{
	int i,j,len;
	len=str.size();
	i=0;
	j=-1;
	sub_next[0]=-1;
	while(i<len)
	{
		if(j==-1 || str[i]==str[j])
		{
			i++;
			j++;
			sub_next[i]=j;
		}
		else
			j=sub_next[j];
	}
}
void find_inv_next(string str)
{
	int i,j,len;
	len=str.size();
	i=0;
	j=-1;
	inv_next[0]=-1;
	while(i<len)
	{
		if(j==-1 || str[i]==str[j])
		{
			i++;
			j++;
			inv_next[i]=j;
		}
		else
			j=inv_next[j];
	}
}
bool KMP_str(string str,int k)
{
	int q=-1,i;
	for(i=0;i<list[k].size();i++)
	{
		while(q >= 0 && str[q+1]!= list[k][i])
			q=sub_next[q];
		if(str[q+1]==list[k][i])
			++q;
		if(q==str.size()-1)
			return true;
	}
	//cout << "KMP_str false" << endl;
	return false;
}
bool KMP_inv(string str,int k)
{
	int q=-1,i;
	for(i=0;i<list[k].size();i++)
	{
		while(q >= 0 && str[q+1]!= list[k][i])
			q=inv_next[q];
		if(str[q+1]==list[k][i])
			++q;
		if(q==str.size()-1)
			return true;
	}
	//cout << "KMP_inv false" << endl;
	return false;
}
int main()
{
	int T,i,n,ans,k;
	string str,sub_str,sub_inv;
	bool find_ans,str_exist;
	scanf("%d",&T);
	while(T--)
	{
		list.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin >> str;
			list.push_back(str);
		}
		sort(list.begin(),list.end(),cmp);//依據string長度 由小排到大
		//枚舉最短的string 的所有組合可能
		str=list[0];
		for(ans=str.size();ans>=0;ans--)//從最長的組合開始找 找到符合的就會是答案了
		{
			find_ans=false;//未找到答案
			for(i=0;i+ans<=list[0].size() && !find_ans;i++)//起點不同
			{
				sub_str=list[0].substr(i,ans);//取子字串 從第i位開始取ans個單位長
				sub_inv=sub_str;//reverse的子字串
				reverse(sub_inv.begin(),sub_inv.end());
				
				//cout << "sub_str " << sub_str << endl;
				//使用KMP來找有沒有相同的子字串
				//建立next
				find_next(sub_str);
				find_inv_next(sub_inv);
				
				str_exist=true;
				//判斷 sub_str 或是 inv_str 有沒有存在於每一個string中(有的話就是答案)
				for(k=1;k<list.size() && str_exist;k++)
				{
					if(!KMP_str(sub_str,k) && !KMP_inv(sub_inv,k))//sub_str不存在 && inv_str也不存在string中
						str_exist=false;
				}
				//找到答案了
				if(str_exist)
					find_ans=true;
			}
			if(find_ans)
			{
				cout << ans << endl;
				break;
			}
		}
	}
	return 0;
}