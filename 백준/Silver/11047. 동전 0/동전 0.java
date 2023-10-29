import java.io.*;
import java.util.*;

public class Main {

    static int n, k, answer;
    static int[] value;
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        value = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            value[i] = Integer.parseInt(st.nextToken());
        }

        int i = n;
        while (true) {

            i--;  

            if (k <= 0) {break;}
            if(k < value[i]) {continue;}

            k -= value[i];
            i++;
            answer++;
        }

        System.out.println(answer);
    }
}