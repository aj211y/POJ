//ī�G���L�l�A���j
#include<iostream>
#include<cstdio>
using namespace std;

int count(int apple,int plate);
int main()
{
	int test,apple,plate,result;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&apple,&plate);
		result=count(apple,plate);
		printf("%d\n",result);
	}
	return 0;
}
int count(int apple,int plate)
{
	if(apple<0)
		return 0;//�S���o�إi��
	if(apple==0 || plate==1)//�p�G�S��ī�G�F�A�u���@�إi��A���N�O�������ŽL     �L�l�u�Ѥ@�Ӫ��ɭԡA�u���@�ӥi��A�Ҧ���ī�G���n��b���@�ӤW��
		return 1;
	return count(apple-plate,plate)+count(apple,plate-1);//apple-plate���C�@�ӽL�l����@���A���Ѿl��ī�G�A�h��L�l�Q���X�رƪk
}															//ī�G�Ƥ��ܡA�L�ƴ�@�A��ܦ��@�ӽL�l�O�Ū��A���Ѿl���L�l�A�h��ī�G�Q���X�رƪk
