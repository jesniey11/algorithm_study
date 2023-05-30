import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int R, C, minR, minC, maxR, maxC;
	static char[][] map, map50;
	
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		R = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
		map = new char[R][C];	map50 = new char[R][C];
		
		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			map[i] = str.toCharArray();
			map50[i] = str.toCharArray();
		}
		
		minR = R; minC = C;
		maxR = -1; maxC = -1;
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {if (map[i][j] == 'X') After50(i, j);}
		}
		
		for (int i = minR; i < maxR+1; i++) {;
			for (int j = minC; j < maxC+1; j++) {bw.write(map50[i][j]+"");}
			bw.write("\n");
		}
		
		bw.close();
	}
	
	static void After50(int x, int y) {
		
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];	int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || R <= nx || C <= ny) cnt++;
			else if (map[nx][ny] != 'X') cnt++;
		}
		
		if (cnt >= 3) map50[x][y] = '.';
		else {
			minR = Math.min(minR, x); minC = Math.min(minC, y);
			maxR = Math.max(maxR, x); maxC = Math.max(maxC, y);
		}
	}
}