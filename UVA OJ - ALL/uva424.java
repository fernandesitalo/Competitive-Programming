import java.util.*;
import java.math.*;
import java.io.*;


class uva424{

  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);

    BigInteger sum = BigInteger.valueOf(0);

    while(true){
      BigInteger parc = sc.nextBigInteger();

      if(parc.compareTo(BigInteger.valueOf(0)) == 0){
        break;
      }

      sum = sum.add(parc);
    }
    System.out.println(sum);
  }
}
