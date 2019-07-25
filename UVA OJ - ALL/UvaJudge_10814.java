import java.util.Scanner;
import java.io.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		while (N-- > 0) {
			
			BigInteger Numerador = sc.nextBigInteger();
			String barra = sc.next();	// so para ler a barra 
			BigInteger Denominador = sc.nextBigInteger(); 
			
			BigInteger gcd = Numerador.gcd(Denominador); // maximom divisor comum
			
			System.out.println(Numerador.divide(gcd) + " / " + Denominador.divide(gcd));
		} 
	} 
}
