import java.math.*;
import java.util.*;
import java.io.*;

class Uva10219{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			long n = sc.nextLong();
			long k = sc.nextLong();
			
			BigInteger ans = BigInteger.ONE;
			
			if(k > (n/2)) k = n - k;
			for(int i = 0 ; i < k ; ++i){
				ans = ans.multiply(BigInteger.valueOf(n-i));
				ans = ans.divide(BigInteger.valueOf(i+1));
			}
			System.out.println(ans.toString().length());
		}
	}
}
