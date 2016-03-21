import java.io.*;
import java.math.*;
import java.util.*;

public class Sgu111{
	public static void main(String[] argc){
		Scanner in=new Scanner(System.in);
		BigInteger l,r,m,x;
		x=in.nextBigInteger();
		l=BigInteger.ZERO;r=x.add(BigInteger.ONE);
		while(l.add(BigInteger.ONE).compareTo(r)<0){
			m=l.add(r).shiftRight(1);
			if(m.multiply(m).compareTo(x)<=0) l=m; else r=m;
		}
		System.out.println(l);
	}
}
