package boj10;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class lastFacto {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int fac = 1;
		int a = 0;
		
		for (int i = 2; i <= N; i++) {
			fac *= i;
			a = fac;
			
			int len = (int)(Math.log10(a)+1);
			if (i % 5 == 0) {a /= 10;}
			if (len > 2) {a %= 100;}
			
			System.out.println(a);
			
		}
	}
}
