import java.util.*;
import java.io.*;
import java.math.*;
	
public class Main {
	Scanner sc;
	PrintWriter pr;
	void Go() throws Exception {
		sc = new Scanner(new File("input.txt"));
		pr = new PrintWriter(new File("output.txt"));
		int n = sc.nextInt();
		BigInteger[][] d = new BigInteger[1000][1000];
		for (int i = 0; i <= 100; i++)
			Arrays.fill(d[i], new BigInteger("0"));
	
		for (int i = 0; i <= 9; i++)
			d[1][i] = new BigInteger("1");
	
		for(int i = 2; i <= n / 2; i++)
			for(int j = 0; j <= i * 9; j++)
				for(int k = 0; k <= 9; k++) {
					BigInteger T = new BigInteger("0");
					T = d[i][j];
					if(j - k >= 0)
						T = T.add(d[i - 1][j - k]);
					d[i][j] = T;
				}
		BigInteger C = new BigInteger("0");
		for(int j = 0; j <= 9 * (n / 2); j++)
			C = C.add(d[n / 2][j].multiply(d[n / 2][j]));
		
		pr.print(C);
		pr.close();
	}
	
	public static void main(String argc[]) throws Exception {
		new Main().Go();
	}
}