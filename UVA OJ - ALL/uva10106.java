import java.util.*;
import java.math.*;
import java.io.*;


class uva10106{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext() == true){
      BigInteger a = sc.nextBigInteger();
      BigInteger b = sc.nextBigInteger();
      System.out.println(a.multiply(b));
    }
  }
}
