// 80_1_다익스트라_최소힙.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

/*
(최소힙으로 풀기)
아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로
그램을 작성하세요. (경로가 없으면 Impossible를 출력한다)
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보와 거리비용이 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.
▣ 입력예제 1
    6 9
    1 2 12
    1 3 4
    2 1 2
    2 3 5
    2 5 5
    3 4 5
    4 2 2
    4 5 5
    6 4 5
▣ 출력예제 1
    2 : 11
    3 : 4
    4 : 9
    5 : 14
    6 : impossible
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct toNode
{
    int _node;
    int _value;

    toNode(int node, int value) :_node(node), _value(value) {}

    //최소힙
    bool operator<(const toNode& ref) const
    {
        //최소힙 기준 오름차순
        return _value > ref._value;
    }
};


int main()
{
    int n;
    int line;
    int fromN, toN, value;
    cin >> n >> line;

    priority_queue<toNode> q;
    vector<int> answer(n + 1, 2147000000);
    vector<vector<toNode>> map(n, vector<toNode>());

    for (int i = 0; i < line; i++)
    {
        cin >> fromN >> toN >> value;
        map[fromN].emplace_back(toNode(toN, value));
    }

    q.push(1, 0);
    answer[1] = 0;

    while (!q.empty())
    {
        int minN = q.top()._node;   //1
        int minV = q.top()._value;  //0
        q.pop();
        if (answer[minN] < minV) continue;
        for (int i = 0; i < map[minN].size(); i++)
        {
            
            if (answer[map[minN][i]._node] > minV + map[minN][i]._value)
            {
                answer[map[minN][i]._node] = minV + map[minN][i]._value;
            }
        }           
    }

    for (int i = 2; i < n+1; i++)
    {
        cout << i << " : " << answer[i] << endl;
    }
                                                                                                                                                                     
}
