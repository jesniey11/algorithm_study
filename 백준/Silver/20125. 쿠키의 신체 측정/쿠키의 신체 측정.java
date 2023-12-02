import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n, heartX, heartY;

    //arm LR, waist, leg LR,
    static int[] output = new int[5];
    static char[][] a;
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        a = new char[n][n];

        heartX = -1;
        heartY = -1;

        for(int i = 0; i < n; i++) {
            a[i] = br.readLine().toCharArray();

            for(int j = 0; j < n; j++) {
                if(a[i][j] == '_') {continue;}
                //무조건 머리가 최초 발견됨, 머리 밑에 심장
                if(heartX == -1) {
                    heartX = j;
                    heartY = i+1;
                }
            }
        }

        // 심장에서 좌 탐색
        for(int i = heartX-1; i >= 0; i--) {
            if(a[heartY][i] == '_') {break;}
            output[0]++;
        }

        // 심장에서 우 탐색
        for(int i = heartX+1; i < n; i++) {
            if(a[heartY][i] == '_') {break;}
            output[1]++;
        }

        // 심장에서 아래로 탐색(허리)
        for(int i = heartY+1; i < n; i++) {
            if(a[i][heartX] == '_') {break;}
            output[2]++;
        }

        // 심장 왼쪽에서 아래로 탐색(왼다리)
        for(int i = heartY+output[2]+1; i < n; i++) {
            if(a[i][heartX-1] == '_') {break;}
            output[3]++;
        }

        // 심장 오른쪽에서 아래로 탐색(오른다리)
        for(int i = heartY+output[2]+1; i < n; i++) {
            if(a[i][heartX+1] == '_') {break;}
            output[4]++;
        }

        bw.write((heartY+1) + " " + (heartX+1) + "\n");
        for(int i = 0; i < output.length; i++) {
            bw.write(output[i] + " ");
        }
        bw.close();
    }
}
