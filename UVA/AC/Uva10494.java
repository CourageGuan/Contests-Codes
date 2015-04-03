import java.io.*;
import java.util.*;
import java.math.*;

class Main{

	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			BigInteger a,b;
			String s;
			a=in.nextBigInteger();
			s=in.next();
			b=in.nextBigInteger();
			char ch=s.charAt(0);
			if(ch=='/')
				System.out.println(a.divide(b));
			else
				System.out.println(a.mod(b));
		}
	}
}
