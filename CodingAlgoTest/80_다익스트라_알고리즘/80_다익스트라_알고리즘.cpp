// 80_다익스트라_알고리즘.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

/*
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

using namespace std;

struct Node
{
    int _node;
    int _value;
    Node(int n, int value) : _node(n), _value(value) {}

    bool operator<(const Node& ref) const
    {
        return _value < ref._value;
    }
};

int main()
{
    int n;
    int line;

    int a, b, v;

    cin >> n >> line;

    vector<vector<Node>> graph(n+1, vector<Node>());
    vector<int> minPath(n+1 , 2147000000);
    vector<int> ch(n + 1, 0);

    int minValue = 2147000000;
    
    
    for (int i = 0; i < line; i++)
    {
        cin >> a >> b >> v;
        graph[a].emplace_back(Node(b,v));
    }
    
    //1번노드를 시작으로
    int indexNode = 1;
    minPath[1] = 0;
    ch[indexNode] = 1;

    for (int i = 2; i <= n; i++)
    {
        minValue = 2147000000;
        for (int i = 1; i < minPath.size(); i++)
        {
            //지나가지 않은 것 들 중에 최소값 선택하기
            if (ch[i] == 0)
            {
                if (minValue > minPath[i])
                {
                    minValue = minPath[i]; //0
                    indexNode = i; //1
                }
            }
        }
        //최소값을 찾았으면 들렸다는걸 체크해준다.
        ch[indexNode] = 1; //ch[1] = 1

        for (int j = 0; j < graph[indexNode].size(); j++)
        {
            if (minPath[graph[indexNode][j]._node] > minPath[indexNode] + graph[indexNode][j]._value) {
                minPath[graph[indexNode][j]._node] = minPath[indexNode] + graph[indexNode][j]._value;
                cout << "minPath[" << graph[indexNode][j]._node << "] = " << "minPath[" << indexNode << "] + " << graph[indexNode][j]._node << " : " << graph[indexNode][j]._value << endl;
            }
        }
    }

    for (int i = 2; i < minPath.size(); i++)
    {
        cout << i << " : " << minPath[i] << endl;
    }
}
