// 89_토마토BFS활용.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
현수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림
과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수
있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은
토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향
에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토
가 혼자 저절로 익는 경우는 없다고 가정한다. 현수는 창고에 보관된 토마토들이 며칠이 지나
면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들
의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로
그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
▣ 입력설명
첫 줄에는 상자의 크기를 나타내는 두 정수 M, N이 주어진다. M은 상자의 가로 칸의 수, N
은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M, N ≤ 1,000 이다.
둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄
에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토
의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수
-1은 토마토가 들어있지 않은 칸을 나타낸다.
▣ 출력설명
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든
토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을
출력해야 한다.
[C++를 이용한 창의적 문제 해결]
- 97 -
▣ 입력예제 1
    6 4
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 1
출력예제 1
    8
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, -1, 0, 1};
int dy[] = {-1,  0, 1, 0};

class Pos
{
public:
    int _x;
    int _y;
    Pos(int y, int x) : _x(x), _y(y) {}
};

int main()
{
    int m, n , max = 0;
    cin >> m >> n;  //6 4

    vector<vector<int>> map(n+2, vector<int>(m+2,1));
    vector<vector<int>> count(n+2, vector<int>(m+2,0));
    queue<Pos> onePos;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            
            if (map[i][j] == 1)
            {
                onePos.push(Pos(i, j));
            }
        }
        cout << endl;
    }

    cout << onePos.size() << endl; 

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j <map[0].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    queue<Pos> q;
    int size = onePos.size();
    for (int i = 0; i < size; i++)
    {
        q.push(onePos.front());
        onePos.pop();
    }

    while (!q.empty())
    {
        Pos temp = q.front();
        q.pop();

        cout << temp._y << "," << temp._x << endl;

        for (int i = 0; i < 4; i++)
        {
            if (map[temp._y + dy[i]][temp._x + dx[i]] == 0)
            {
                q.push(Pos(temp._y + dy[i], temp._x + dx[i]));
                map[temp._y + dy[i]][temp._x + dx[i]] = 1;
                count[temp._y + dy[i]][temp._x + dx[i]] = count[temp._y][temp._x] + 1;
                if (max < count[temp._y + dy[i]][temp._x + dx[i]])
                    max = count[temp._y + dy[i]][temp._x + dx[i]];
            }   
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << count[i][j] << " ";
        }
        cout << endl;
    }

    cout << max;
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
