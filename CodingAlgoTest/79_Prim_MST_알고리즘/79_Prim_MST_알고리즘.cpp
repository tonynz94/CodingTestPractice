// 79_Prim_MST_알고리즘.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
/*
78. 원더랜드(Kruskal MST 알고리즘 : Union&Find 활용)
원더랜드에 문제가 생겼다. 원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.
원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지
도로는 폐쇄하려고 한다. 어떤 도로는 도로를 유지보수하면 재정에 도움이 되는 도로도 존재
한다. 재정에 도움이 되는 도로는 비용을 음수로 표현했다.
아래의 그림은 그 한 예를 설명하는 그림이다.
위의 지도는 각 도시가 1부터 9로 표현되었고, 지도의 오른쪽은 최소비용 196으로 모든 도시
를 연결하는 방법을 찾아낸 것이다.
▣ 입력설명
첫째 줄에 도시의 개수 V(1≤V≤100)와 도로의 개수 E(1≤E≤1,000)가 주어진다. 다음 E개의
줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 도시와 B번
도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이
1,000,000을 넘지 않는다.
▣ 출력설명
모든 도시를 연결하면서 드는 최소비용을 출려한다.
[C++를 이용한 창의적 문제 해결]
- 84 -
▣ 입력예제 1
    9 12
    1 2 12
    1 9 25
    2 3 10
    2 8 17
    2 9 8
    3 4 18
    3 7 55
    4 5 44
    5 6 60
    5 7 38
    7 8 35
    8 9 15
▣ 출력예제 1
    196
*/

#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ch[30];

class Edge
{
public:
    int nodeNum;
    int cost;
    Edge(int a, int b) :nodeNum(a), cost(b)
    {}

    bool operator<(const Edge& res) const
    {
        return cost > res.cost;
    }
};

int main()
{
    int n, cnt;
    int a, b, c;
    int answer = 0;
    cin >> n;
    cin >> cnt;

    priority_queue<Edge> q;
    vector<vector<Edge>> map(n,vector<Edge>());

    for (int i = 0; i < cnt; i++)
    {
        cin >> a >> b >> c;
        map[a].emplace_back(Edge(a, b));
    }

    ch[1] = 1;
    q.push(Edge(1,0));
    while (!q.empty())
    {
       Edge tmp = q.top();
       q.pop();
       int v = tmp.nodeNum;
       int value = tmp.cost;
       if (ch[v] == 0)  //연결되어 있지 않은 노드라면
       {
           answer += value;
           ch[v] = 1;
           for (int i = 0; i < map[v].size(); i++)
           {
               q.push(map[v][i]);
           }
       }
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
