import java.io.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(br.readLine());
        int change = 1000 - input;
        int cnt = 0;

        int[] money = {500, 100, 50, 10, 5, 1};

        for(int i = 0; i < 6; i++) {
            if(change < money[i]) {continue;}
            change -= money[i];
            i--;
            cnt++;
        }

        System.out.println(cnt);
    }
}
