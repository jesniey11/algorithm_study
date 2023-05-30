import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, sh, ta, ans;
	static boolean[][] student;
	static boolean[] visit;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		ans = 0;
		
		student = new boolean[N][N];
		for (int m = 0; m < M; m++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			student[a][b] = true;
		}
		
		for (int x = 0; x < N; x++) {
			// x보다 키가 작은/큰 사람의 수를 구한다
			// shorter + taller == N-1 일때 +1.
			
			visit = new boolean[N];	sh = 0;
			shorter(x);
			
			visit = new boolean[N];	ta = 0;
			taller(x);
			
			if (sh + ta == N-1) {ans++;}
		}
		
		System.out.println(ans);		
	}
	
	// x보다 키가 작은/큰 사람의 수를 구한다
	
	// shorter than x
	static void shorter(int x) {
		
		visit[x] = true;
		
		for (int i = 0; i < N; i++) {
			if(i == x) continue;
			if(student[i][x] && !visit[i]) {shorter(i); sh++;}
		}
	}
	
	// taller than x
	static void taller(int x) {
		
		visit[x] = true;
		
		for (int i = 0; i < N; i++) {
			if(i == x) continue;
			if(student[x][i] && !visit[i]) {taller(i); ta++;}
		}
	}
}