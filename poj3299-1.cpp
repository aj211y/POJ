#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	float h,x,num1,num2,T,D,H,e;
	char cha1,cha2;
	while(scanf("%c",&cha1)!=EOF){
		if(cha1=='E')
			break;
		scanf("%f %c %f",&num1,&cha2,&num2);
		getchar();
		if(cha1=='T'&&cha2=='D'){
			T=num1;
			D=num2;
			e=6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
			h=0.5555*(e-10.0);
			H=T+h;
		}else if(cha1=='D'&&cha2=='T'){
			T=num2;
			D=num1;
			e=6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
			h=0.5555*(e-10.0);
			H=T+h;
		}else if(cha1=='T'&&cha2=='H'){
			T=num1;
			H=num2;
			h=H-T;
			e=h/0.5555+10.0;
			D=1/((1/273.16)-(log(e/6.11)/5417.7530))-273.16;
		}else if(cha1=='H'&&cha2=='T'){
			T=num2;
			H=num1;
			h=H-T;
			e=h/0.5555+10.0;
			D=1/((1/273.16)-(log(e/6.11)/5417.7530))-273.16;
		}else if(cha1=='D'&&cha2=='H'){
			D=num1;
			H=num2;
			e=6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
			h=0.5555*(e-10.0);
			T=H-h;
		}else if(cha1=='H'&&cha2=='D'){
			D=num2;
			H=num1;
			e=6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
			h=0.5555*(e-10.0);
			T=H-h;
		}else{}
		printf("T %.1f D %.1f H %.1f\n",T,D,H);
	}
	return 0;
}