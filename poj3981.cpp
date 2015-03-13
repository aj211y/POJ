#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char buf[1000];
	char *token;
	string a;
	int flag=0;
	while(fgets(buf,sizeof(buf),stdin)!=0){
		flag=0;
		for(token=strtok(buf," \n\r");token!=NULL;token=strtok(NULL," \n\r")){
			if(flag) printf(" ");
			a=token;
			if(a=="you")
				printf("we");
			else
				printf("%s",token);
			flag=1;
		}
		printf("\n");
	}
	return 0;
}
