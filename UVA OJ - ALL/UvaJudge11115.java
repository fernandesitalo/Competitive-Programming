import java.util.*;
import java.math.*;
import java.io.*;


class UvaJudge11115{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(true){
			BigInteger N = sc.nextBigInteger();
			int M = sc.nextInt();
			if(N.compareTo(BigInteger.ZERO) == 0 && M == 0) break;
			System.out.println(N.pow(M)); 
		}
	}
}
