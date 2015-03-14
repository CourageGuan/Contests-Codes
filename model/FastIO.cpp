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

int buf[10];
inline void Writeint(int i){
	if(i<0){
		putchar('-');
		i=-i;
	}
	int p=0;
	if(i==0) p++;
	else while(i){
		buf[p++]=i%10;
		i/=10;
	}
	for(int j=p-1;j>=0;--j) putchar('0'+buf[j]);
}

int main()
{
	int a,b;
	a=Nextint();
	b=Nextint();
	Writeint(a+b);
}

