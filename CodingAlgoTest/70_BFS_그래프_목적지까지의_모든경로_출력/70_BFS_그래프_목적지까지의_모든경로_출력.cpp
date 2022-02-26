// 70_BFS_그래프_목적지까지의_모든경로_출력.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
#include <vector>

using namespace std;

int main()
{
	int back = -1;
	int front = -1;

	int N, M,a,b;
	int arr[10];
	int answer[10] = { 0 };
	int num = 1;
	int ch[10] = {0};
	cin >> N;	//정점 수
	cin >> M;	//간선 수

	vector<int> map[10];

	//인접 리스트
	for (int i = 1; i <= M; i++)
	{
		cin >> a;
		cin >> b;
		map[a].push_back(b);
	}

	ch[1] = 1;
	arr[++back] = 1;
	while (back > front)
	{
		
		int temp = arr[++front];

		for (int i = 0; i < map[temp].size(); i++)
		{
			if (ch[map[temp][i]] == 0)
			{
				ch[map[temp][i]] = num;
				arr[++back] = map[temp][i];
			}		
		}
		num++;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << i +" + " + ch[i] << endl;
	}
}