//������̤j�ȩM�Ҧ����`�M�A��binery search�M��i�઺���s�̤p��
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int canbe(int mid,vector<int> money);
int main()
{
	int n,m,dayspend,beg=0,mid,end=0;
	vector<int> money;
	scanf("%d %d",&n,&m);
	while(n--){
		scanf("%d",&dayspend);
		money.push_back(dayspend);
		if(dayspend>beg)
			beg=dayspend; //begin�O�`�M���i��̤p��
		end=end+dayspend; //end�O�`�M���i��̤j��
	}
	while(beg<end){
		mid=(beg+end)/2;
		if(canbe(mid,money)<m)//�p�G��m�p��ܥi�H�A���U��
			end=mid;
		else
			beg=mid+1;//�n�Y�p�d��
	}
	printf("%d\n",beg);
	return 0;
}
int canbe(int mid,vector<int> money)
{
	int i=-1,group=0,div=0;
	while(++i<money.size()){
		group=group+money[i];
		if(group>mid){
			group=0;
			div++;
			i--;
		}
	}
	return div; //�����X��
}