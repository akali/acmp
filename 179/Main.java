import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public void go () throws IOException {
		Scanner in = new Scanner (System.in);
		int n = in.nextInt();
		if (n == 0) {
			out.print ("2");
			return;
		}
		BigInteger D = new BigInteger ("4"), A = new BigInteger ("2");
		for (int i = 2; i <= n; i++) {
			A = A.multiply (new BigInteger ("3"));
			D = D.add (A);
		}
		System.out.print (D);
	}
	
	public static void main (String argv[]) throws IOException {
		new Main().go();
	}
}
