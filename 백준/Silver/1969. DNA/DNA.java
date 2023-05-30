import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, hd;
	static String dna;
	static char[][] dnas;
	static int[][] ACGT;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());	M = Integer.parseInt(st.nextToken());
		dna = "";	hd = 0;

		dnas = new char[N][M];
		ACGT = new int[M][26];
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			dnas[i] = str.toCharArray();
			
			for (int j = 0; j < M; j++) {ACGT[j][dnas[i][j] - 'A'] ++;}
		}
		
		for (int i = 0; i < M; i++) {
			int max = 0;	char c = 'A';
			for (int j = 0; j < 26; j++) {
				if(max < ACGT[i][j]) {max = ACGT[i][j]; c = (char) (j + 'A');}			
			}
			
			sb.append(c);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dnas[i][j] != sb.charAt(j)) {hd++;}
			}
		}
		
		System.out.println(sb.toString());
		System.out.println(hd);
		
	}
}