//TLE JAVA 再见
//d(i,j) 表示i根火柴能拼出的"除以m余数为j的最大数"
import java.io.*;
import java.util.*;
import java.math.*;

class Main{

	static final int MAXN=100 + 10;
	static final int MAXM=3000 + 10;
	static final int[] match={6,2,5,5,4,5,6,3,7,6};
	//static final long INF=0x3f3f3f3f;
	static final BigInteger NEG=BigInteger.ONE.negate();

	static BigInteger[][] d;
	static int n,m;

	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int kase=0;
		while(in.hasNext()){
			n=in.nextInt();
			if(n==0) break;
			m=in.nextInt();
			kase+=1;
			d=new BigInteger[MAXN][MAXM];
			d[0][0]=BigInteger.ZERO;
			System.out.println(d[0][0]);
			for(int i=0;i<=n;i++)
				for(int j=0;j<m;j++){
					if(d[i][j]==null) continue;
					for(int k=0;k<10;k++){
						if(i+match[k]>n) continue;
						d[i+match[k]][(j*10+k)%m]=d[i][j].multiply(BigInteger.TEN).add(BigInteger.valueOf(k));
					}
				}
			BigInteger ans=d[n][0];
			if (ans==null) ans=NEG;
			System.out.println("Case "+kase+":"+ans);
		}
	}
}



