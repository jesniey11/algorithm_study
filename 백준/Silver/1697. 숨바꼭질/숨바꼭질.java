import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[] visited;
	static int N, K, ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		visited = new int[100001];
		
		if(N != K) {ans = BFS(N, K);}
		else ans = 0;
		
		bw.write(ans + "");
		bw.close();
	}
	
	public static int BFS(int n, int k) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(n);
		visited[n] = 1;
		
		while(!q.isEmpty()) {
			int tmp = q.poll();

			for (int i = 0; i < 3; i++) {
				
				int t;
				
				if (i == 0) {t = tmp-1;}
				else if (i == 1) {t = tmp+1;}
				else t = tmp*2;
				
				if(t == K) {return visited[tmp];}
				if(0 <= t && t < 100001 && visited[t] == 0) {visited[t] = visited[tmp] + 1; q.add(t);}
			}
		}
		return 0;
	}
}