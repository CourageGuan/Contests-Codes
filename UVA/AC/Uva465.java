//注意输入可能含前导0，所以按字符串输入
//此题可也可以用double解(精度丢失可以忽略)
import java.io.*;
import java.util.*;
import java.math.*;

class Main{

	static final BigInteger size=BigInteger.valueOf(2147483647);

	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger a,b;
		String s,sa,sb;
		char ch;
		while(in.hasNext()){
			sa=in.next();
			s=in.next();
			sb=in.next();
			System.out.println(sa+" "+s+" "+sb);
			
			a=new BigInteger(sa);
			b=new BigInteger(sb);
			ch=s.charAt(0);

			if(a.compareTo(size)>0) 
				System.out.println("first number too big");
			if(b.compareTo(size)>0)
				System.out.println("second number too big");

			if(ch=='+'){
				if(a.add(b).compareTo(size)>0)
					System.out.println("result too big");
			}else
				if(a.multiply(b).compareTo(size)>0)
					System.out.println("result too big");
		}
	}
}
