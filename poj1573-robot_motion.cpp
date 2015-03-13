#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	bool flag=0;
	int row,col,start,step[10][10]={0},i,j,count=0;
	char map[10][10];
	while(scanf("%d %d %d",&row,&col,&start)!=EOF){
		if(!(row|col|start))//若三者皆為零則結束
			break;
		count=0;
		flag=0;
		for(i=0;i<row;i++){//設置地圖
			getchar();//scanf("%c")會把換行符號讀進去，所以用getchar()把換行符號拿掉
			for(j=0;j<col;j++){
				scanf("%c",&map[i][j]);
			}
		}
		i=0;
		j=start-1;
		while(i>=0 && i<row && j>=0 && j<col){
			if(step[i][j]){//碰到有迴圈的狀況
				flag=1;
				count++;
				break;
			}
			step[i][j]=++count;
			switch(map[i][j]){
				case 'E': j++; break;
				case 'S': i++; break;
				case 'W': j--; break;
				case 'N': i--; break;
				default :break;
			}
		}
		if(flag)//表示有迴圈產生
			printf("%d step(s) before a loop of %d step(s)\n",step[i][j]-1,count-step[i][j]);
		else//找到出路
			printf("%d step(s) to exit\n",count);
		for(i=0;i<row;i++){//清空
			for(j=0;j<col;j++){
				step[i][j]=0;
				map[i][j]=' ';
			}
		}
	}
	return 0;
}
