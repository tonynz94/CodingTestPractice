/*
88. 미로의 최단거리 통로(BFS 활용)
7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을 작성하세요. 경로수는
출발점에서 도착점까지 가는데 이동한 횟수를 의미한다. 출발점은 격자의 (1, 1) 좌표이고, 탈
출 도착점은 (7, 7)좌표이다. 격자판의 1은 벽이고, 0은 도로이다.
격자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면
x -> D 까지의 경로 갯수
	X 0 0 0 0 0 0
	0 1 1 1 1 1 0
	0 0 0 1 0 0 0
	1 1 0 1 0 1 1
	1 1 0 1 0 0 0
	1 0 0 0 1 0 0
	1 0 1 0 0 0 D
위와 같은 경로가 최단 경로이며 경로수는 12이다.
▣ 입력설명
첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
▣ 출력설명
첫 번째 줄에 최단으로 움직인 칸의 수를 출력한다. 도착할 수 없으면 -1를 출력한다.
▣ 입력예제 1
	0 0 0 0 0 0 0
	0 1 1 1 1 1 0
	0 0 0 1 0 0 0
	1 1 0 1 0 1 1
	1 1 0 1 0 0 0
	1 0 0 0 1 0 0
	1 0 1 0 0 0 0
▣ 출력예제 1
12
*/
#include <iostream>
#include <queue>

using namespace std;

int xx[] = {0,0,-1,1};
int yy[] = {1,-1,0,0};

class Pos
{
public:
	int _x;
	int _y;

public:
	Pos(int x, int y):_x(x),_y(y){}
};

int main()
{
	//전체 0으로 초기화됨
	vector<vector<int>> map(9, vector<int>(9, 1));
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<Pos> q;
	//시작점 삽입
	map[1][1] = -1;
	q.push(Pos(1, 1));
	int answer = 0;
	
	while (!q.empty())
	{
		Pos pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = pos._x + xx[i];
			int y = pos._y + yy[i];
	
			if (x == 7 && y == 7)
			{
			    cout << -map[pos._x][pos._y];
				return -1;
			}

			//갈 수 있는 경로라면
			if (map[pos._x + xx[i]][pos._y + yy[i]] == 0)
			{
				q.push(Pos(pos._x + xx[i], pos._y + yy[i]));
				map[pos._x + xx[i]][pos._y + yy[i]] = map[pos._x][pos._y] - 1;
			}
		}
		
	}
	cout << "-1";
}

