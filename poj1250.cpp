//tanning salong �ƶ����D
//1 ABCCAB  1��2�H���}���׳���
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
			bed=num;//�ɦ��
			go=0;//�������X�H�ͮ����}
			stand=0;
			Q="0";
			if(str.size()%2)
				go=-1;
			for(int a=0;a<str.size();a++){//�N�r��@�Ӥ@�ө�ѥh���
				same=0;
				for(int b=0;b<a;b++){//��靈�S����ۤv���e���r���@��
					if(str[a]==str[b]){//�����ܫh��ܦ��H�n���} ���٤����D�O���ɺ��٬O�S�o�Ϊ��H
						same=1;
						if(!away(b)) //�qaway()�i�H���D�O���@�ؤH�n���}  �ǹL�h��b��ܥL�bstr�Ĥ@���X�{�ɪ���m
							del();//���ɺΪ��H�n���} 
						b=a;//���L�i�H���W���X�j��
					}	
				}
				if(!same)
					add(a);//check in�H��+1
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
	if(!bed)//�p�G�S�ɺΤF �h�N�S�ɺΤ��H�bstr�Ĥ@���X�{����m�O���bQ[] stand��ܦ��X�H�S�ɺ�
		Q[++stand]=a;
	else
		bed--;//�ɦ�֤@
}
void del()
{
	int q=1;
	bed++;//���H���}�ɦ�[�@
	if(stand){//�Y���ɦ��H�٦b����  �h�i��
		bed--;
		stand--;
		while(q<=stand){ //�N���ݪ����X�P���e��
			Q[q]=Q[q+1];
			q++;
		}
	}
}
int away(int b)
{
	int q=1;
	for(int t=1;t<=stand;t++){
		if(Q[t]==b){ //�p�G�@��  ��ܳo�ӭn�����H�S���Ψ��
			q=t;
			t=--stand;//��t�న�W���Xfor�j��stand���ݤH�Ƥ֤@
			while(q<=stand){ //�N���ݪ����X�P���e��
				Q[q]=Q[q+1];
				q++;
			}
			go++;//�S����tanning�N���}���H��
			return 1;//��ܬO���ݤ����H���}
		}
	}
	return 0;//��ܬO���b��tanning���H�n���}
}