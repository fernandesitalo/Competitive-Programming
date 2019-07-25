import java.util.Scanner;
import java.io.*;
import java.math.*;


class uva10238{

  public static BigInteger pd[][] = new BigInteger[51][4001];
  public static int F,N,S;

  public static BigInteger func(int lanc, int soma){


    if(soma > S) return BigInteger.valueOf(0);

    if(lanc == N){
      if(soma == S) return BigInteger.valueOf(1);
      return BigInteger.valueOf(0);
    }

    if(pd[lanc][soma].compareTo(BigInteger.valueOf(-1)) != 0) return pd[lanc][soma];

    pd[lanc][soma] = BigInteger.ZERO;

    for(int i = 1 ; i <= F ; ++i){
      pd[lanc][soma] = pd[lanc][soma].add(func(lanc+1,soma+i));
    }
    return pd[lanc][soma];
  }


  public static void main(String[] Args){

    Scanner sc = new Scanner(System.in);

    while(sc.hasNext() == true){
      F = sc.nextInt();
      N = sc.nextInt();
      S = sc.nextInt();

      for(int i = 0 ; i <= N ; ++i){
        for(int j = 0 ; j <= S ; ++j){
          pd[i][j] = BigInteger.valueOf(-1);
        }
      }

      BigInteger num = func(0,0), den = BigInteger.valueOf(F).pow(N);
      System.out.println(num + "/"+ den);
    }
  }
}
