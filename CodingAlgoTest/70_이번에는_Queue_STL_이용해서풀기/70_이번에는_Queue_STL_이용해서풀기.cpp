// 70_이번에는_Queue_STL_이용해서풀기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
70. 그래프 최단거리(BFS)
다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.
(pdf 이미지 참조)
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.

-방향 그래프-
▣ 입력예제 1
`   6 9	 (정점수, 간선 수)
`   1 3 (정점 -> 정점)
`   1 4
`   2 1
`   2 5
`   3 4
`   4 5
`   4 6
`   6 2
`   6 5
▣ 출력예제 1
`   2 : 3
`   3 : 1
`   4 : 1
`   5 : 2
`   6 : 2
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int M, N , a, b;
	queue<int> q;

	cin >> N;
	cin >> M;
	

	vector<vector<int> > map(N+1);
	vector<int> check(N + 1);

	for (int i = 1; i <= M; i++)
	{
		cin >> a;
		cin >> b;
		map[a].push_back(b);
	}

	q.push(1);
	check[1] = 1;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (int i = 0; i < map[temp].size(); i++)
		{
			if (check[map[temp][i]] == 0)
			{
				check[map[temp][i]] = check[temp] + 1;
				q.push(map[temp][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << i << " : " << check[i]-1 << endl;
	}

}