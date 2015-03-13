#include<iostream>
#include<string>
using namespace std;

int main()
{
	string x,y;
	int xsum=0,ysum=0;
	while(cin >> x >> y){
		for(int a=0;a<x.size();a++)
			xsum=xsum+(x[a]-48);
		for(int b=0;b<y.size();b++)
			ysum=ysum+(y[b]-48);
		cout << xsum*ysum << endl;
	}
	return 0;
}