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
		sort(list.begin(),list.end(),cmp);//�̾�string���� �Ѥp�ƨ�j
		//�T�|�̵u��string ���Ҧ��զX�i��
		str=list[0];
		for(ans=str.size();ans>=0;ans--)//�q�̪����զX�}�l�� ���ŦX���N�|�O���פF
		{
			find_ans=false;//����쵪��
			for(i=0;i+ans<=list[0].size() && !find_ans;i++)//�_�I���P
			{
				sub_str=list[0].substr(i,ans);//���l�r�� �q��i��}�l��ans�ӳ���
				sub_inv=sub_str;//reverse���l�r��
				reverse(sub_inv.begin(),sub_inv.end());
				
				//cout << "sub_str " << sub_str << endl;
				//�ϥ�KMP�ӧ䦳�S���ۦP���l�r��
				//�إ�next
				find_next(sub_str);
				find_inv_next(sub_inv);
				
				str_exist=true;
				//�P�_ sub_str �άO inv_str ���S���s�b��C�@��string��(�����ܴN�O����)
				for(k=1;k<list.size() && str_exist;k++)
				{
					if(!KMP_str(sub_str,k) && !KMP_inv(sub_inv,k))//sub_str���s�b && inv_str�]���s�bstring��
						str_exist=false;
				}
				//��쵪�פF
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