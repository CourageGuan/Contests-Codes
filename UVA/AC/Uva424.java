import java.util.*;
import java.io.*;
import java.math.*;

class Main{

	public static void main(String argc[]){	
		BigInteger ans,b;
		ans=new BigInteger("0");
		Scanner in=new Scanner(System.in);

		while(in.hasNext()){
			b=in.nextBigInteger();
			ans=ans.add(b);
		}
		System.out.println(ans);
	}

}
