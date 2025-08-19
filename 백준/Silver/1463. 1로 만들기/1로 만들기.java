import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[] calc = new int[N+1];
		
		calc[1] = 0;
		for (int i = 2; i < N+1; i++) {
			calc[i] = calc[i-1]+1;
			if(i%2 == 0) {calc[i] = Math.min(calc[i], calc[i/2] + 1);}
			if(i%3 == 0) {calc[i] = Math.min(calc[i], calc[i/3] + 1);}
		}
		
		System.out.println(calc[N]);
	}

}