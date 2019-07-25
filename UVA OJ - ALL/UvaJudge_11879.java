import java.util.Scanner;
import java.io.*;
import java.math.*;

class Main{
	static public void main(String[] agrs){
		
		Scanner sc = new Scanner(System.in);
		BigInteger M = BigInteger.valueOf(17);
		
		while(true){
			BigInteger N = sc.nextBigInteger();
			
			if(N.compareTo(BigInteger.ZERO) == 0) break;
			
			N = N.mod(M);
			
			if(N.compareTo(BigInteger.ZERO) == 0){
				System.out.println("1");
			}else{
				System.out.println("0");
			}
		}
	}
}
