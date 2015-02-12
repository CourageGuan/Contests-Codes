import java.io.*;
import java.util.*;
import java.math.*;

public class Sgu112{
	public static void main(String[] argc){
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		BigInteger x,y,ans;
		x=BigInteger.valueOf(a);
		y=BigInteger.valueOf(b);
		ans=x.pow(b).subtract(y.pow(a));
		System.out.println(ans);
	}
}
			
