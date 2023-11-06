import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, max;
	static int[] cards;
	static boolean[] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		max = 0;
		
		cards = new int[N];
		visited = new boolean[N];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {cards[i] = Integer.parseInt(st.nextToken());	}
		
		Combi(0, 3);
		
		bw.write(max + "");
		bw.close();
	}
	
	public static void Combi (int cnt, int r) {
		if(r == 0) {
			int sum = 0;
			for(int i = 0; i < N; i++) {
				if(visited[i]) {	sum += cards[i];}
				if(sum > M) {sum = 0; break;}
			}
			max = Math.max(max, sum);
			return;
		}
		
		for(int i = cnt; i < N; i++) {
			visited[i] = true;
			Combi(i+1, r-1);
			visited[i] = false;
		}
	}
}