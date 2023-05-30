import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, ans;
	static int[][] map;
	
	// 가로 0 세로 1 대각 2
	static int[] dx = {0, 1, 1};
	static int[] dy = {1, 0, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		ans = 0;
		
		map = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {map[i][j] = Integer.parseInt(st.nextToken());}
		}
		
		Move(0, 1, 0);
		System.out.println(ans);
	}
	
	static void Move(int x, int y, int d) {

		if (x == N-1 && y == N-1 && map[x][y] == 0) {ans++; return;}
		for (int i = 0; i < 3; i++) {
			
			if(d == 0) {if(i == 1) continue;}
			if(d == 1) {if(i == 0) continue;}
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (0 > nx || nx >= N || 0 > ny || ny >= N || map[nx][ny] == 1) continue;
			
			if (i == 2) {if(map[nx-1][ny] != 0 || map[nx][ny-1] != 0) continue;}
			
			Move(nx, ny, i);
		}
	}
	
	
}