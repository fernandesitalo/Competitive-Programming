import java.util.Scanner;
import java.io.*;
import java.math.*;

class Main{
	static public void main(String[] agrs){
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		//String invertida = new StringBuilder(s).reverse().toString();
		
		for(int i = 0 ; i < t ; ++i){
			
			String A = sc.next();
			String B = sc.next();
			
			String A1 = new StringBuilder(A).reverse().toString();
			String B1 = new StringBuilder(B).reverse().toString();
			
			BigInteger A11 = new BigInteger(A1);
			BigInteger B11 = new BigInteger(B1);
			
			BigInteger SUM = A11.add(B11);
			
			
			String TEMP = new StringBuilder(SUM.toString()).reverse().toString();
			
			BigInteger ANS = new BigInteger(TEMP);
			
			System.out.println(ANS);
			
			
			
			
		}
	}
}
