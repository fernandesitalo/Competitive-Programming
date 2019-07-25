import java.util.Scanner;
import java.io.*;
import java.math.*;


class UvaJudge11344{
	public static void main(String[] args) throws Exception {	
			
		//~ System.setIn(new FileInputStream(new File("in")));
		
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		String str;
		
		for(int h = 0 ; h < t ; ++h){
			
			str = sc.next();
			
			BigInteger N = new BigInteger(str);
			BigInteger zero = new BigInteger("0");
			
			
			
			int q = sc.nextInt();
			
			
			
			boolean ans = true;
			
			for(int i = 0 ; i < q ; ++i){
				BigInteger A = sc.nextBigInteger();
				if(ans){
					if(zero.compareTo(N.mod(A)) != 0 ){
						ans = false;
					}
				}
			}
			
			if(ans) System.out.println(str+" - Wonderful.");
			else System.out.println(str+" - Simple.");
			
			
		
		}
	}
}
