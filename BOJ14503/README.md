# BOJ 14503: 로봇 청소기

![Java](https://img.shields.io/badge/Java-007396.svg?&style=for-the-badge&logo=Java&logoColor=white)
![BOJ](https://img.shields.io/badge/BOJ-0079C5.svg?&style=for-the-badge&logo=Java&logoColor=white)
![BFS](https://img.shields.io/badge/BFS-ffdd33.svg?&style=for-the-badge&logo=Java&logoColor=white)

## 😈 후기

이래서 이과놈들은 글쓰면 안됨 코드 짜는거보다 문제 읽는게 어려웠음🤬

문제만 읽어서는 로봇청소기 동작 순서가 이해가 안 갔다…

---

## 문제 요약

N×M 크기 map에 청소할 칸 0 과 벽 1 이 주어진다.

로봇청소기는 0인 칸 (r, c)에서 방향 d 를 보고 배치되어 있다.

d는 0(N), 1(E), 2(S), 3(W) 이다.

**[로봇청소기 동작 순서]**

1 현재 위치를 청소한다

2 현재 방향 기준 왼쪽 방향부터 탐색한다.

3 순서대로 수행한다.

- 왼쪽 방향에 청소할 공간 있음 - 해당 방향으로 회전하고 한칸 전진 후 청소
- 왼쪽 방향에 청소할 공간 없음 - 회전만 하고 다시 탐색한다

- 어느 방향에도 청소할 공간이 없으면 방향을 유지하고 후진 후 다시 탐색한다
- 벽이라서 후진도 못하면 작동 중지

---

## Code

▶▶ **Main**

```java
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

}
```

방향 d  를 인덱스로 하는  int[] dirx 와  int[] diry  배열을 생성한다. 4방탐색에 사용한다.

cnt 를 1부터 할 필요는 없다. 0부터 해도 좋지만 불필요한 연산 +1…

변수 정의가 완료되고 필요한 값을 모두 입력받으면 DFS 메소드인 **Clean 메소드**로 넘어간다.

---

▶▶ **Clean 메소드**

```java
static void Clean(int r, int c, int d) {
		
	map[r][c] = 2;
		
	for (int i = 0; i < 4; i++) {
			
		d = (d+3)%4; 
		int nx = r + dirx[d];
		int ny = c + diry[d];
			
		if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] == 0) {
			cnt++; Clean(nx, ny, d); return;
		}
	}
			
	int bd = (d+2) % 4;
	int bx = r + dirx[bd];
	int by = c + diry[bd];
		
	if(0 <= bx && bx < N && 0 <= by && by < M && map[bx][by] != 1) {Clean(bx, by, d);}
}
		
```

평범한 4방 탐색 BFS에 방향만 추가되었다고 생각하고 풀면 논리 오류를 보게 된다…😂

여기서 주의할 변수는 오직 d다!!

후진하기 전까지의 회전을 반영해야 하므로 별도의 nd 가 아닌 d 에 연산을 직접 넣어준다!!

(d+3)%4는 현재 d의 왼쪽 방향, (d+2)%4는 현재 d의 후진 방향이다.

만약 nd를 사용하고 싶다면  boolean check  변수를 사용해서 
4방향 탐색을 하는 동안 한 칸이라도 청소가 되지 않았을 경우 후진을 하게 하면 된다.

물론 변수가 늘어나므로 4ms 더 걸린다…
