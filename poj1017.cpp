#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a[6],box,i,left;
	while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5])&&(a[0]|a[1]|a[2]|a[3]|a[4]|a[5])){
		box=0;
		for(i=5;i>=0;i--){
			if(a[i]){//���Ȥ~�n�i�Ӻ�box�ƶq
				switch(i){
					case 5:box=a[5]; break;//6*6
					case 4:
						if(a[0]>a[4]*11)//�����뺡�H���٦���1*1��
							a[0]-=a[4]*11;
						else
							a[0]=0;
						box+=a[4];
						break;//5*5
					case 3:
						if(a[1]>a[3]*5)//�����뺡�٦���2*2��
							a[1]-=a[3]*5;
						else{//�����맹�٦��Ŷ��A���۶�1*1��
							left=(a[3]-a[1]/5)*20-(a[1]%5)*4;//a[1]/5�맹�X�� (a[3]-a[1]/5)*20�Ѿl�`��l�� (a[1]%5)*4�Ѿl2*2�Ҧ�����l��
							if(a[0]>left)
								a[0]-=left;
							else
								a[0]=0;
							a[1]=0;
						}
						box+=a[3];
						break;//4*4
					case 2:
						if(a[2]%4){
							box++;
							switch(a[2]%4){
								case 1:
									if(a[1]>5){
										a[1]-=5;
										if(a[0]>7)
											a[0]-=7;
										else
											a[0]=0;
									}
									else{
										left=27-a[1]*4;
										if(a[0]>left)
											a[0]-=left;
										else
											a[0]=0;
										a[1]=0;
									}
									break;
								case 2:
									if(a[1]>3){
										a[1]-=3;
										if(a[0]>6)
											a[0]-=6;
										else
											a[0]=0;
									}
									else{
										left=18-a[1]*4;
										if(a[0]>left)
											a[0]-=left;
										else
											a[0]=0;
										a[1]=0;
									}
									break;
								case 3:
									if(a[1]>1){
										a[1]-=1;
										if(a[0]>5)
											a[0]-=5;
										else
											a[0]=0;
									}
									else{
										left=9-a[1]*4;
										if(a[0]>left)
											a[0]-=left;
										else
											a[0]=0;
										a[1]=0;
									}
									break;
							}
						}
						box+=a[2]/4;
						break;//3*3
					default:
						if(a[0]|a[1]){
							a[0]+=a[1]*4;
							box+=a[0]/36;
							if(a[0]%36)
								box++;
							a[0]=a[1]=0;
						}	
						break;//2*2�M1*1
				}
			}
		}
		printf("%d\n",box);
	}
	return 0;
}