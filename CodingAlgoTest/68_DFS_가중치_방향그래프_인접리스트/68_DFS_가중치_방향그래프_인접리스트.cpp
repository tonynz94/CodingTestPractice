#include <iostream>
#include <vector>

/*
    가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그램을 작성하세요.

▣ 입력설명
    첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
    결정보가 주어진다.
▣ 출력설명
    총 가지수와 최소값 경로를 출력한다

▣ 입력예제 1
5 8
1 2 12
1 3 6
1 4 10
2 3 2
2 5 2
3 4 3
4 2 2
4 5 5
*/

using namespace std;

vector<pair<int, int>> map[30];
int ch[30] = { 0 };
int min = 2147000000; //최소경로값
int answer = 0; //총 가지수
int N;  //정점 수
int M;  //간선 수


void DFS(int v, int sum)
{
    if (v == N)
    {
        answer++;
        if (min > sum)
            min = sum;
    }
    else
    {
        for (int i = 0; i < map[v].size(); i++)
        {
            if (ch[map[v][i].first] != 1)
            {
                ch[map[v][i].first] = 1;
                DFS(map[v][i].first, sum + ch[map[v][i].second]);
                ch[map[v][i].first] = 0;
            }
        }
    }
}


int main()
{
    cin >> N;
    cin >> M;

    int n1, n2, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> n1;
        cin >> n2;
        cin >> cost;
        map[n1].emplace_back(make_pair(n2, cost));
    }

    ch[1] = 1;
    DFS(1, 0);

    cout << answer << endl;
    cout << min;
}
