#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> map[30];
int ch[30];
int N; //정점 수
int M; //간선 수
int min;

void DFS(int v, int sum)
{
	//마지막 정점
	if (v == N)
	{
		if (min > sum)
			min = sum;
	}
	else
	{
		for (int i = 1; i <= map[v].size(); i++)
		{
			if (ch[map[v][i].first] == 0)
			{
				ch[map[v][i].first] = 1;
				DFS(map[v][i].first, sum + map[v][i].first);
				ch[map[v][i].first] = 0;
			}
		}
	}
}

int main()
{
	
	int n1, n2, cnt;
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> n1;
		cin >> n2;
		cin >> cnt;
		map[n1].emplace_back(make_pair(n2, cnt));
	}

	ch[1] = 1;
	DFS(1, 0);
}

