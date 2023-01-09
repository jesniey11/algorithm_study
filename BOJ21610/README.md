# BOJ 21610: 마법사 상어와 비바라기

![Java](https://img.shields.io/badge/Java-007396.svg?&style=for-the-badge&logo=Java&logoColor=white)
![BOJ](https://img.shields.io/badge/BOJ-0079C5.svg?&style=for-the-badge&logo=Java&logoColor=white)
![Implementation](https://img.shields.io/badge/Implementation-4d377b.svg?&style=for-the-badge&logo=Java&logoColor=white)


## 😈 후기

아기상어 뚜루룻뚜루 마법사 뚜루룻뚜루 하지마 뚜루룻뚜루 때려쳐 (╯‵□′)╯︵┻━┻

1달 전에 풀다 때려친 문제였는데 스스로 쪼끔 대견해졌다 그치만 더러워… 어려워…

---

## 문제 요약

구름을 지정된 방향과 거리만큼 이동시킨다. 단, 구름은 범위 밖으로 나가면 반대쪽에서 돌아온다.
이동 후, 비를 내려 칸의 수에 +1 해준다.

그 다음, 모든 비가 왔던 칸의 대각선 4칸 값 = 0 T/F 체크,
0이 아닌 칸 수 만큼 비가 왔던 칸에 더해준다.

위 과정이 끝나면 칸의 값 ≥ 2 인 모든 칸을 -2 하고 구름을 생성한다.

---

## Code

▶▶ **Main**

```java
public class Main {
	
	static class pos {
		
		int x, y;
		
		public pos(int x, int y) {
			
			super();
			this.x = x;		this.y = y;
		}
	}

	static int N, M, sum;
	
	static int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
	static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
	
	static int[][] map, move;
	static boolean[][] visit;
	
	static Queue<pos> cloud = new LinkedList<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		// N : 맵 크기, M : 이동 수
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		sum = 0;
		
		// map : 맵 배열, move : 이동 방향/거리 배열
		map = new int[N][N];
		move = new int[M][2];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {map[i][j] = Integer.parseInt(st.nextToken());}
		}
	
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			
			// move[i][0] : 방향, move[i][1] : 거리
			move[i][0] = Integer.parseInt(st.nextToken()) - 1;
			move[i][1] = Integer.parseInt(st.nextToken());
		}
		
		// 초기 구름의 위치를 큐에 넣어준다
		cloud.offer(new pos(N-2, 0)); cloud.offer(new pos(N-2, 1));
		cloud.offer(new pos(N-1, 0)); cloud.offer(new pos(N-1, 1));
		
		for (int i = 0; i < M; i++) {
			
			int dir = move[i][0];
			int dist = move[i][1];
			
			// 매 이동마다 visit 초기화 필수!! - 구름 최종 위치는 매 이동마다 변하기 때문
			visit = new boolean[N][N];
			
			// Cloud로 구름 이동 및 비내리기, Copy로 물복사버그
			Cloud(i, dir, dist);
			Copy();
			
			// 새 구름 생성
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if(map[a][b] >= 2 && !visit[a][b]) {map[a][b] -= 2; cloud.offer(new pos(a, b));}
				}
			}
			
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {sum += map[i][j];}
		}
		
		bw.write(sum + "");
		bw.close();
	}
```

역대급 긴 Main🤔

구름의 위치가 큐에 담기므로 큐 이름을 cloud로 지었다. 초기 구름의 좌표를 큐에 담아주자.

그러고 나면 M번 구름 이동 <<**Cloud** 메소드 참조>>, 물복사 <<**Copy** 메소드 참조>>, 
구름 생성 -물의 양이 2 이상인 칸 중 직전에 비가 안 내린 칸에 새 구름을 생성한다- 을 실행한다.

이동을 모두 마치고, 모든 칸의 물의 양을 더해서 출력한다.

---

▶▶ **Cloud 메소드 - 부속 메소드 포함**

```java
static void Cloud(int num, int dir, int dist) {
		
		// 구름 있는 칸 수 만큼
		for (int i = 0; i < cloud.size(); i++) {
			
			pos now = cloud.poll();
			
			int nx = now.x + (dx[dir] * dist);
			int ny = now.y + (dy[dir] * dist);
			
			while(!isinBound(nx) || !isinBound(ny)) {
				if(!isinBound(nx)) nx = intoBound(nx);	
				if(!isinBound(ny)) ny = intoBound(ny);
			}
		
			cloud.offer(new pos(nx, ny));
			map[nx][ny]++;
			visit[nx][ny] = true;
		}
	}

static boolean isinBound(int xy) {
		
		if(xy < 0 || xy >= N) return false;
		return true;
	}
	
	static int intoBound(int xy) {
		
		if(xy < 0) {return xy + N;}
		else return xy - N;
		
	}
```

BFS 델타탐색 응용 코드이다. dx[i] 대신 방향*거리 를 해준다.

isinBound 는 배열 유효범위 안에 nx, ny가 있는지 체크하는 메소드

intoBound 는 isinBound == false 일때 배열 범위 안에 넣는 메소드이다.

반복문으로 돌린 이유는 dist가 커지면 한번으로는 안 들어가기 때문이다.
ex) dist = -13, N = 4 —→ 한번만 돌리면 -9임. 

---

▶▶ **Copy 메소드**

```java
static void Copy() {
		
		while(!cloud.isEmpty()) {
			pos now = cloud.poll();
			int cnt = 0;
			
			for (int i = 0; i < 8; i++) {
				if(i % 2 == 0) continue; // 짝수 칸은 상하좌우이므로 continue
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (map[nx][ny] != 0) cnt++;
			}
			
			map[now.x][now.y] += cnt;			
		}
		
	}
```

구름이 이동해서 비가 내렸으면 물복사를 해야 한다.

비가 내린 칸은 매 이동마다 visit를 새로 만들어 기억해주고 있으므로 visit[x][y] = true 라면 이번 이동에서 비가 내린 칸이다.

그 칸의 대각선에 위치한 칸 4개가 0인지 아닌지 체크하고, 0이 아닌 칸 수만큼 map[x][y] 에 더해준다.
