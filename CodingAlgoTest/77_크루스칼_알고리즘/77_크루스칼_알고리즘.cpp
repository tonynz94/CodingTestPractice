// 77_크루스칼_알고리즘.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다./

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
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> vec(30);

class Path
{
public:
    int _a;
    int _b;
    int _cost;

    Path(int a, int b, int cost) :_a(a), _b(b), _cost(cost)
    {}

    bool operator<(const Path& res) const
    {
        return _cost <= res._cost;
    }
};

//부모 찾기
int Find(int a)
{
    if (vec[a] == a)
    {
        return a;
    }
    else
    {
        return vec[a] = Find(vec[a]);
    }
}

bool ConnectPath(int a, int b)
{
    int an = Find(a);   
    int bn = Find(b);


    //연결되어 있지 않은 것
    if (an != bn)
    {
        vec[an] = bn;
        return true;
    }

    return false;
}

int main()
{
    vector<Path> v;
    int a, b, c;
    int n, m;
    int answer = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.emplace_back(Path(a, b, c));
    }
    
    for (int i = 1; i <= n; i++)
    {
        vec[i] = i;
    }

    sort(v.begin(), v.end());
    vector<Path>::iterator it;

    


    for (it = v.begin(); it != v.end(); it++)
    {
        if (ConnectPath(it->_a, it->_b))
            answer += it->_cost;
    }

    cout << answer;
}

