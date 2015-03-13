#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	char word[15];
	char *w;
	bool flag=false;
	string eng,code;
	map<string,string> dic;
	while(gets(word))
	{
		if(word[0]=='\0')
		{
			flag=true;
			continue;
		}
		if(flag)//print
		{
			//printf("print\n");
			code=word;
			if(dic.find(code)==dic.end())
				printf("eh\n");
			else
				cout << dic[code] << endl;
		}
		else
		{
			//printf("input\n");
			w=strtok(word," ");
			strcpy(word,w);
			eng=word;
			//cout << eng << endl;
			if(w!=NULL)
				w=strtok(NULL," ");
			strcpy(word,w);
			code=word;
			//cout << word << endl;
			dic[code]=eng;
		}
	}
	return 0;
}