import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int K;
	static int[] S;
	
	static boolean[] visit;
	
	public static void main(String[] args) throws Exception{
		
		StringTokenizer st;
		
		while(true) {
			
			st = new StringTokenizer(br.readLine(), " ");
			
			K = Integer.parseInt(st.nextToken());
			if (K == 0) {break;}
			
			S = new int[K];
			for (int i = 0; i < K; i++) {S[i] = Integer.parseInt(st.nextToken());}
			
			visit = new boolean[K];
			Combi(0, 0);
			
			bw.write("\n");
		}
		bw.close();
	}	
	
	//KC6
	static void Combi(int s, int depth) throws Exception {
		
		if (depth == 6) {
			for (int i = 0; i < K; i++) {
				if (visit[i]) {bw.write(S[i] + " ");}
			}
			
			bw.write("\n");
			return;
		}
		
		for (int i = s; i < K; i++) {
			visit[i] = true;
			Combi(i+1, depth+1);
			visit[i] = false;
		}
	}
}