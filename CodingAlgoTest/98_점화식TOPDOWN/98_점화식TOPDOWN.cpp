// 98_점화식TOPDOWN.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
* 
▣ 입력예제 1
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
▣ 출력예제 1
25
*/

#include <iostream>
#include <vector>

using namespace std;
int dirX[]{ 0 , -1 };
int dirY[]{ -1 , 0 };
int map[21][21] = {0};
int answer[21][21] = {0};


int DFS(int yy, int xx)
{
	if (answer[yy][xx] != -1)
	{
		return answer[yy][xx];
	}
	else if (yy == 0 && xx == 0)
	{
		return map[0][0];
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			if (yy + dirY[i] < 0 || xx + dirX[i] < 0)
				continue;

			int cost = map[yy][xx] + DFS(yy + dirY[i], xx + dirX[i]);
			if (answer[yy][xx] != -1) {
				answer[yy][xx] = answer[yy][xx] < cost ? answer[yy][xx] : cost;
			}
			else
			{
				answer[yy][xx] = cost;
			}
		}

		return answer[yy][xx];
	}
}

int main()
{
	int count;
	cin >> count;
	

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cin >> map[i][j];
			answer[i][j] = -1;
		}
	}
	answer[0][0] = map[0][0];
	DFS(count - 1, count - 1);

	cout << answer[count - 1][count - 1];
}

