import java.util.Scanner;
import java.math.*;

class Main{
	public static void main(String[] args){

		BigInteger[] fib = new BigInteger[5001];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;

		for(int i = 2 ; i < 5001 ; ++i){
			fib[i] = fib[i-1].add(fib[i-2]);			
		}

		Scanner sc = new Scanner(System.in);

		while(sc.hasNext()){
			int n = sc.nextInt();
			System.out.print("The Fibonacci number for "+n+" is "+fib[n]+"\n");
		}
	}
}