#include<cstdio>

void plus(int &n,char ch)
{
	switch(ch){
		case 'q':n+=9;break;
		case 'r':n+=5;break;
		case 'b':n+=3;break;
		case 'n':n+=3;break;
		case 'p':++n;break;
	}
}

int main()
{
	int w,b;
	w=b=0;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			char ch=getchar();
			if (ch == '.') continue;
			if(ch>95) plus(b,ch);
			else plus(w,ch+32);
		}
		getchar();
	}
	//printf("%d %d\n",w,b);
	if(w==b){
		puts("Draw");
		return 0;
	}
	puts(w>b?"White":"Black");
	return 0;
}
