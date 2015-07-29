#积累一些题目恶心学妹(di)...

##随机斐波那契
hiho月赛11(by CLJ)
时间限制:5000ms
单点时限:1000ms
内存限制:256MB
###描述
大家对斐波那契数列想必都很熟悉:

a0 = 1, a1 = 1, ai = ai-1 + ai-2,(i > 1)。

现在考虑如下生成的斐波那契数列:

a0 = 1, ai = aj + ak, i > 0, j, k从[0, i-1]的整数中随机选出（j和k独立）。

现在给定n，要求求出E(an)，即各种可能的a数列中an的期望值。

###输入
一行一个整数n，表示第n项。(1<=n<=500)

###输出
一行一个实数，表示答案。你的输出和答案的绝对或者相对误差小于10-6时被视为正确答案。

###样例解释
共存在3种可能的数列

1,2,2  1/4

1,2,3  1/2

1,2,4  1/4

所以期望为3。

###样例输入
2
###样例输出
3.000000

###ps
结论题，(n+1).000000

###Code

	#include<bits/stdc++.h>
	using namespace std;
	
	int main()
	{
		freopen("test.txt","r",stdin);
		int T,kase=0;
		int n,m;
		while(scanf("%d",&n)==1){
			printf("%d.000000\n",n+1);
		}
		return 0;
	}


##Power of Cryptography
uva113/poj2109

Time Limit: 1000MS		Memory Limit: 30000K

###Description

Current work in cryptography involves (among other things) large prime numbers and computing powers of numbers among these primes. Work in this area has resulted in the practical use of results from number theory and other branches of mathematics once considered to be only of theoretical interest. 
This problem involves the efficient computation of integer roots of numbers. 
Given an integer n>=1 and an integer p>= 1 you have to write a program that determines the n th positive root of p. In this problem, given such integers n and p, p will always be of the form k to the nth. power, for an integer k (this integer is what your program must find).

###Input

The input consists of a sequence of integer pairs n and p with each integer on a line by itself. For all such pairs 1<=n<= 200, 1<=p<10101 and there exists an integer k, 1<=k<=109 such that kn = p.

###Output

For each integer pair n and p the value k should be printed, i.e., the number k such that k n =p.

###Sample Input

2 16
3 27
7 4357186184021382204544

###Sample Output

4
3
1234

###ps
看起来要用高精度，实则不然...

###Code

	#include<cstdio>
	#include<cmath>
	#include<iostream>
	
	double k,p,n;
	
	int main()
	{
		//freopen("test.txt","r",stdin);
		while(scanf("%lf %lf",&n,&p)==2){
			k=pow(p,1/n);	
			std::cout<<k<<std::endl;
		}
		return 0;
	}

##Babelfish
poj2503

Time Limit: 3000MS		Memory Limit: 65536K

###Description

You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language. Fortunately, you have a dictionary to help you understand them.

###Input

Input consists of up to 100,000 dictionary entries, followed by a blank line, followed by a message of up to 100,000 words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line. Each word in the input is a sequence of at most 10 lowercase letters.

###Output

Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as "eh".

###Sample Input

dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

###Sample Output

cat
eh
loops

###Hint

Huge input and output,scanf and printf are recommended.

###Source

Waterloo local 2001.09.22

###ps
输入相当恶心人

###code

	#include<cstdio>
	#include<iostream>
	#include<cstring>
	#include<string>
	#include<map>
	
	using namespace std;
	const int maxn=30;
	map<string,string> mp;
	char s[maxn];
	
	int main()
	{
		//freopen("test.txt","r",stdin);
		mp.clear();
		while(~scanf("%[^\n]%*c",s) && s[0]!='\0'){
			//printf("%s\n",s);
			string ss(s); 
			//cout<<ss<<endl;
			mp[ss.substr(ss.find(' ')+1,ss.size())]=ss.substr(0,ss.find(' '));
			s[0]='\0';
		}
		while(~scanf("%s",s)){
			string S(s);
			if(mp.count(S)) printf("%s\n",mp[S].c_str());
			else puts("eh");
		}
		return 0;
	}

##Friends
hdu5305

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)


###Problem Description
There are n people and m pairs of friends. For every pair of friends, they can choose to become online friends (communicating using online applications) or offline friends (mostly using face-to-face communication). However, everyone in these n people wants to have the same number of online and offline friends (i.e. If one person has x onine friends, he or she must have x offline friends too, but different people can have different number of online or offline friends). Please determine how many ways there are to satisfy their requirements. 
 

###Input
The first line of the input is a single integer T (T=100), indicating the number of testcases. 

For each testcase, the first line contains two integers n (1≤n≤8) and m (0≤m≤n(n−1)2), indicating the number of people and the number of pairs of friends, respectively. Each of the next m lines contains two numbers x and y, which mean x and y are friends. It is guaranteed that x≠y and every friend relationship will appear at most once. 
 

###Output
For each testcase, print one number indicating the answer.
 

###Sample Input
2
3 3
1 2
2 3
3 1
4 4
1 2
2 3
3 4
4 1
 

###Sample Output
0
2
 

###Source
2015 Multi-University Training Contest 2
 
###ps
多校的一道题，很考验搜索的基本功。

###code

	#include<cstdio>
	#include<cstring>
	
	const int maxn = 10;
	int n,m,ans;
	int e[maxn][maxn],d[maxn];
	
	void dfs(int u,int v)
	{
		if(u > n) ++ans;
		else if(v > n)
		{
			if(d[u]) return;
			dfs(u+1,u+2);	
		}
		else
		{
			if(e[u][v])
			{
				++d[u]; ++d[v];
				dfs(u,v+1);
				d[u] -= 2; d[v] -= 2;
				dfs(u,v+1);
				++d[u]; ++d[v];
			}
			else dfs(u,v+1);
		}
	}
	
	int main()
	{
		int T;
		scanf("%d",&T);
		while(T--)
		{
			scanf("%d %d",&n,&m);
			memset(e,0,sizeof e);
			memset(d,0,sizeof d);
			int u,v;
			for(int i=0;i<m;++i)
			{
				scanf("%d %d",&u,&v);
				e[u][v] = e[v][u] = 1;
			}
			ans = 0;
			dfs(1,2);
			printf("%d\n",ans);	
		}
	
	}

