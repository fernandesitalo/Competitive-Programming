import java.util.Scanner;
import java.io.*;
import java.math.*;




class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		BigInteger onze = BigInteger.valueOf(11);
		BigInteger zero = BigInteger.valueOf(0);
		
		String str;
		
		while(true){
			str = sc.next();
			
			BigInteger N = new BigInteger(str);
			
			if(N.compareTo(BigInteger.ZERO) == 0) break;
			
			if(zero.compareTo(N.mod(onze)) == 0)
				System.out.println(str+" is a multiple of 11.");
			else
				System.out.println(str+" is not a multiple of 11.");
		}			
	}
}
