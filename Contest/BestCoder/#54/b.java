import java.math.*;
import java.io.*;
import java.util.*;

public class Main
{
	static int n;
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] argc)
	{
		int T = in.nextInt();
		for(int i=0;i<T;++i)
		{
			if(solve()) System.out.println("Yes");	
			else System.out.println("No");	
		}
	}

	static boolean solve()
	{
		BigInteger zero = BigInteger.ZERO,one = BigInteger.ONE;
		BigInteger[] save = new BigInteger[111];
		int n = in.nextInt();
		for(int i=0;i<n;++i) save[i] = in.nextBigInteger();
		if(n<=1) return true;
		if(save[0].equals(zero)){
			for(int i=1;i<n;++i)
			{
				if(save[i].equals(zero)) continue;
				return false;
			}
		}
		else{
			for(int i=0;i<n;++i)
			{
				if(save[i].equals(zero)) return false;
			}
		}
		for(int i=1;i<n-1;++i)
		{
			if(save[i-1].multiply(save[i+1]).compareTo(save[i].multiply(save[i])) == 0 ) continue;
			return false;
		}
		return true;
	}
}

