#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	bool flag=0;
	int row,col,start,step[10][10]={0},i,j,count=0;
	char map[10][10];
	while(scanf("%d %d %d",&row,&col,&start)!=EOF){
		if(!(row|col|start))//�Y�T�̬Ҭ��s�h����
			break;
		count=0;
		flag=0;
		for(i=0;i<row;i++){//�]�m�a��
			getchar();//scanf("%c")�|�⴫��Ÿ�Ū�i�h�A�ҥH��getchar()�⴫��Ÿ�����
			for(j=0;j<col;j++){
				scanf("%c",&map[i][j]);
			}
		}
		i=0;
		j=start-1;
		while(i>=0 && i<row && j>=0 && j<col){
			if(step[i][j]){//�I�즳�j�骺���p
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
		if(flag)//��ܦ��j�鲣��
			printf("%d step(s) before a loop of %d step(s)\n",step[i][j]-1,count-step[i][j]);
		else//���X��
			printf("%d step(s) to exit\n",count);
		for(i=0;i<row;i++){//�M��
			for(j=0;j<col;j++){
				step[i][j]=0;
				map[i][j]=' ';
			}
		}
	}
	return 0;
}
