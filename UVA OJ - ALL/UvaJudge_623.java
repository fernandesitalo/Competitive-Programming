import java.util.Scanner;
import java.io.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		BigInteger[] fat = new BigInteger[1001];
		fat[0] = BigInteger.ONE;
		fat[1] = BigInteger.ONE;
		
		for(int i = 2 ; i < 1001 ; ++i){
			fat[i] = fat[i-1].multiply(BigInteger.valueOf(i));
		}
		
		while (sc.hasNext()) {			
			int n = sc.nextInt();
			System.out.println(n+"!"+"\n"+fat[n]);
		} 
	} 
}
