import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
 public void solve () throws IOException
 {
  BigInteger one = new BigInteger ("1"), zero = new BigInteger ("0");
  File IN = new File ("input.txt"), OUT = new File ("output.txt");
  Scanner sc = new Scanner (IN);
  PrintWriter pr = new PrintWriter (OUT);
  int k = sc.nextInt(), n = sc.nextInt();
  BigInteger d[] = new BigInteger[333];
  d[0] = one;
  for (int i = 1; i <= n; i++)
  {
   d[i] = zero; 
   for (int j = Math.max(0, i - k); j < i; j++)
    d[i] = d[i].add(d[j]);
  }
  pr.println (d[n]);
  pr.close();
  sc.close();
 }

 public static void main (String argc[]) throws IOException
 {
  new Main().solve();
 }
}
