#include<cstdio>
#include<cctype>


inline int Nextint()
{
	int t=1;
	char c=getchar();
	while(!isdigit(c) && !(c=='-')) c=getchar();
	if(c=='-'){
		t=-1;
		c=getchar();
	}
	int x=0;
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*t;
}

int main()
{
	int a,b;
	a=Nextint();
	b=Nextint();
}

