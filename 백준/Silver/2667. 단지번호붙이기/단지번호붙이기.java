import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n, danzi, house;
    static char[][] map;
    static boolean[][] visit;
    static List<Integer> houselist;
    static Queue<Point> q;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {1,-1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        danzi = 0;

        map = new char[n][n];
        visit = new boolean[n][n];
        houselist = new ArrayList<>();
        q = new LinkedList<>();

        for(int i = 0; i < n; i++) {
            map[i] = br.readLine().toCharArray();
        }

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] == '1' && !visit[i][j]){
                    house = 0;
                    danzi++;
                    DFS(i,j);
                    //BFS(new Point(i,j));
                    houselist.add(house);
                }
            }
        }

        Collections.sort(houselist);

        System.out.println(danzi);
        for (int i = 0; i < houselist.size(); i++) {
            System.out.println(houselist.get(i));
        }
    }

    static void DFS(int y, int x) {
        visit[y][x] = true;
        map[y][x] = (char) danzi;
        house++;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(map[ny][nx] == '1' && !visit[ny][nx]){
                    map[ny][nx] = (char) danzi;
                    //visit[ny][nx] = true;
                    DFS(ny, nx);
                }
            }
        }
    }

    static void BFS(int y, int x) {

    }

    static class Point{
        int y,x;
        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
