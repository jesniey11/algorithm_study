import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, cnt;
	static int[][] map;
	
	static int[] dirx = {-1, 0, 1, 0};
	static int[] diry = {0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine(), " ");
		
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		map = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {map[i][j] = Integer.parseInt(st.nextToken());}
		}
		
		cnt = 1;
		Clean(r, c, d);
		
		System.out.println(cnt);
		
	}
	
	static void Clean(int r, int c, int d) {
		
		map[r][c] = 2;
		
		for (int i = 0; i < 4; i++) {
			
			d = (d+3)%4;
			int nx = r + dirx[d];
			int ny = c + diry[d];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] == 0) {cnt++; Clean(nx, ny, d); return;}
		}
			
		int bd = (d+2) % 4;
		int bx = r + dirx[bd];
		int by = c + diry[bd];
		
		if(0 <= bx && bx < N && 0 <= by && by < M && map[bx][by] != 1) {Clean(bx, by, d);}
	}
	
}