import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, ans;
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	static int[][] Box;
	static Queue<Grow> q;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		Box = new int[N][M];
		q = new LinkedList<Grow>();
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				
				Box[i][j] = Integer.parseInt(st.nextToken());
				if (Box[i][j] == 1) {q.add(new Grow(i, j));}

			}
		}
		ans = BFS();
		
		bw.write(ans + "");
		bw.close();
	}

	public static int BFS() {
		
		while(!q.isEmpty()) {
			
			Grow now = q.poll();
			
			for (int n = 0; n < 4; n++) {
				
				int nx = now.x + dx[n];
				int ny = now.y + dy[n];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					
					if(Box[nx][ny] == 0) {
						Box[nx][ny] = Box[now.x][now.y] + 1;
						q.add(new Grow(nx, ny));
					}
					
				}
				
			}
		}

		int res = -100;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Box[i][j] == 0) {return -1;}
				res = Math.max(res, Box[i][j]);
			}
		}
		
		if (res == 1) {return 0;}
		else return res - 1;
	}
	
	static class Grow {
		
		int x; int y;
		public Grow(int x, int y) {super();	this.x = x;	this.y = y;}
	
	}
}