//���A���M�k�A����
#include<iostream>
#include<string>
using namespace std;

string str;//�������k�A�����ǦC
long int b=0,a=0;//b����p�ǦC�����W�@�Ӽ�  a����str�s��ĴX��F
void build(long int x);//�إߥ��A��(l�N��)�Υk�A��(r�N��)�b�r�ꤤ���ǦC
void check(long int c);//�ഫ��w�ǦC
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
		if(r==0){  //���P�k�A�����������A��
			cout << count << " "; //�L�X�Ʀr
			d=0;
		}
	}
}
void build(long int x)//�إߥ��k�A�����ǦC
{
	for(long int c=0;c<(x-b);c++){
		str+='l';//string�n�o�˴��J(�p�G�@�}�l��l�ƥu��string str�A�ӨS��str[]�A�h���J�ɤ����[])
		a++;
	}
	str+='r';
	a++;
	b=x; //����p�ǦC���W�@�Ӽ�
}