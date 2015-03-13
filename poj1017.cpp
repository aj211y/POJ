#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a[6],box,i,left;
	while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5])&&(a[0]|a[1]|a[2]|a[3]|a[4]|a[5])){
		box=0;
		for(i=5;i>=0;i--){
			if(a[i]){//有值才要進來算box數量
				switch(i){
					case 5:box=a[5]; break;//6*6
					case 4:
						if(a[0]>a[4]*11)//全部塞滿以後還有剩1*1的
							a[0]-=a[4]*11;
						else
							a[0]=0;
						box+=a[4];
						break;//5*5
					case 3:
						if(a[1]>a[3]*5)//全部塞滿還有剩2*2的
							a[1]-=a[3]*5;
						else{//全部塞完還有空間，接著塞1*1的
							left=(a[3]-a[1]/5)*20-(a[1]%5)*4;//a[1]/5塞完幾盒 (a[3]-a[1]/5)*20剩餘總格子數 (a[1]%5)*4剩餘2*2所佔的格子數
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
						break;//2*2和1*1
				}
			}
		}
		printf("%d\n",box);
	}
	return 0;
}