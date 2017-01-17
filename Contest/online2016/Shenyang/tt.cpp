#include    <stdio.h>  
#include    <string.h>  
#include    <stdlib.h>  
#include    <time.h>  
#include    <math.h>  
typedef long long LL;
   
LL *primarr, *v;  
LL q = 1, p = 1;  
   
//π(n)  
LL pi(LL n, LL primarr[], LL len)  
{  
    LL i = 0, mark = 0;  
    for (i = len - 1; i > 0; i--) {  
        if (primarr[i] < n) {  
            mark = 1;  
            break;  
        }  
    }  
    if (mark)  
        return i + 1;  
    return 0;  
}  
   
//Φ(x,a)  
LL phi(LL x, LL a, LL m)  
{  
    if (a == m)  
        return (x / q) * p + v[x % q];  
    if (x < primarr[a - 1])  
        return 1;  
    return phi(x, a - 1, m) - phi(x / primarr[a - 1], a - 1, m);  
}  
   
LL prime(LL n)  
{  
    char *mark;  
    LL mark_len;  
    LL count = 0;  
    LL i, j, m = 7;  
    LL sum = 0, s = 0;  
    LL len, len2, len3;  
   
    mark_len = (n < 10000) ? 10002 : ((LL)exp(2.0 / 3 * log(n)) + 1);  
   
    //筛选n^(2/3)或n内的素数  
    mark = (char *)malloc(sizeof(char) * mark_len);  
    memset(mark, 0, sizeof(char) * mark_len);  
    for (i = 2; i < (LL)sqrt(mark_len); i++) {  
        if (mark[i])  
            continue;  
        for (j = i + i; j < mark_len; j += i)  
            mark[j] = 1;  
    }  
    mark[0] = mark[1] = 1;  
   
    //统计素数数目  
    for (i = 0; i < mark_len; i++)  
        if (!mark[i])  
            count++;  
   
    //保存素数  
    primarr = (LL *)malloc(sizeof(LL) * count);  
    j = 0;  
    for (i = 0; i < mark_len; i++)  
        if (!mark[i])  
            primarr[j++] = i;  
   
    if (n < 10000)  
        return pi(n, primarr, count);  
   
    //n^(1/3)内的素数数目  
    len = pi((LL)exp(1.0 / 3 * log(n)), primarr, count);  
    //n^(1/2)内的素数数目  
    len2 = pi((LL)sqrt(n), primarr, count);  
    //n^（2/3)内的素数数目  
    len3 = pi(mark_len - 1, primarr, count);  
   
    //乘积个数  
    j = mark_len - 2;  
    for (i = (LL)exp(1.0 / 3 * log(n)); i <= (LL)sqrt(n); i++) {  
        if (!mark[i]) {  
            while (i * j > n) {  
                if (!mark[j])  
                    s++;  
                j--;  
            }  
            sum += s;  
        }  
    }  
    free(mark);  
    sum = (len2 - len) * len3 - sum;  
    sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;  
   
    //欧拉函数  
    if (m > len)  
        m = len;  
    for (i = 0; i < m; i++) {  
        q *= primarr[i];  
        p *= primarr[i] - 1;  
    }  
    v = (LL *)malloc(sizeof(LL) * q);  
    for (i = 0; i < q; i++)  
        v[i] = i;  
    for (i = 0; i < m; i++)  
        for (j = q - 1; j >= 0; j--)  
            v[j] -= v[j / primarr[i]];  
   
    sum = phi(n, len, m) - sum + len - 1;  
    free(primarr);  
    free(v);  
    return sum;  
}  
   
int main()  
{  
	LL n;  
	LL count;  
	int h;  
	clock_t start, end;  
	n = 3LL;
	p=1;  
	q=1;  
	start = clock();  
	count = prime(n);  
	end = clock() - start;  
	printf("%lld(%d亿)内的素数个数为%lld\n",n,n/100000000,count);  
	printf("用时%lf毫秒\n",(double)end/1000);  
	return 0;  
}  

