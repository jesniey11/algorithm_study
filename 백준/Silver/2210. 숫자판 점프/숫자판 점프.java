import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static char[][] pad;
	static List<String> list;

	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력
		pad = new char[5][5];
		list = new ArrayList<>();
		
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < 5; j++) {pad[i][j] = st.nextToken().charAt(0);}
		}
		
        // str에 숫자를 덧붙여야 하므로 null 말고 ""
		String str = "";
		
        // 시작점 지정
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {MakeNum(0, i, j, str);}
		}
		
		System.out.println(list.size());
		
	}
	
    // DFS 4방탐색 - visit 없이 depth = 6에서 종료
	static void MakeNum(int depth, int x, int y, String str) {
		
		if(depth == 6) {
            //depth = 6이면 만들어진 숫자를 리스트에 있는 숫자와 비교
			if (!list.contains(str)) {list.add(str);}
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || 5 <= nx || 5 <= ny) continue;
			MakeNum(depth+1, nx, ny, str + pad[nx][ny]);
		}
	}

}