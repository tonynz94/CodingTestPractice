// 86_피자배달_삼성SW역량평가.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
86. 피자 배달 거리(삼성 SW역량평가 기출문제 : DFS활용)
N×N 크기의 도시지도가 있습니다. 도시지도는 1×1크기의 격자칸으로 이루어져 있습니다. 각
격자칸에는 0은 빈칸, 1은 집, 2는 피자집으로 표현됩니다. 각 격자칸은 좌표(행번호, 열 번호)
로 표현됩니다. 행번호는 1번부터 N번까지이고, 열 번호도 1부터 N까지입니다.
도시에는 각 집마다 “피자배달거리”가 았는데 각 집의 피자배달거리는 해당 집과 도시의 존재
하는 피자집들과의 거리 중 최소값을 해당 집의 “피자배달거리”라고 한다.
집과 피자집의 피자배달거리는 |x1-x2|+|y1-y2| 이다.
예를 들어, 도시의 지도가 아래와 같다면
    0 1 0 0
    0 0 2 1
    0 0 1 0
    1 2 0 2
(1, 2)에 있는 집과 (2, 3)에 있는 피자집과의 피자 배달 거리는 |1-2| + |2-3| = 2가 된다.
최근 도시가 불경기에 접어들어 우후죽순 생겼던 피자집들이 파산하고 있습니다. 도시 시장은
도시에 있는 피자집 중 M개만 살리고 나머지는 보조금을 주고 폐업시키려고 합니다.
시장은 살리고자 하는 피자집 M개를 선택하는 기준으로 도시의 피자배달거리가 최소가 되는
M개의 피자집을 선택하려고 합니다.
도시의 피자 배달 거리는 각 집들의 피자 배달 거리를 합한 것을 말합니다.
▣ 입력설명
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 12)이 주어진다.
둘째 줄부터 도시 정보가 입력된다.
▣ 출력설명
첫째 줄에 M개의 피자집이 선택되었을 때 도시의 최소 피자배달거리를 출력한다.
▣ 입력예제 1
    4 4
    0 1 2 0
    1 0 2 1
    0 2 1 2
    2 0 1 2
▣ 출력예제 1
    6
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Pos
{
public:
    int _x;
    int _y;
    Pos(int x, int y) : _x(x), _y(y) {}
};

vector<Pos> pizza;
vector<Pos> house;
vector<Pos> saver;
//vector<int> check;
int n, m;
int min = 2147000000;
int minSum = 0;
int answer = 2147000000;


void DFS(int start, int level)
{
    if (level == m)  //0 , 1, 2, 3 , (4)
    {       

        for (int i = 0; i < house.size(); i++)
        {
            //이 집에서 가장 가까운 피자집의 거리를 구함
            Pos housePos = house[i];
            min = 2147000000;
            for (int j = 0; j < m; j++)
            {
                int distance = abs(saver[j]._x - housePos._x) + abs(saver[j]._y - housePos._y);
                if (min > distance)
                    min = distance;
            }
            //여기 오면 가장 가까운 피자집 거리가 min에 들어가있음
            minSum += min;
            
        }
        if (answer > minSum)
            answer = minSum;

        minSum = 0;
    }
    else
    {
        for (int i = start; i < pizza.size(); i++) //0
        {
            saver[level] = pizza[i];
            DFS(i+1, level+1);
        }
    }
}

int main()
{
    int i, j, c;
    cin >> n >> m;

    saver.resize(m,Pos(0,0));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> c;
            //집
            if (c == 1)
            {
                house.push_back(Pos(i, j));
            }
            else if (c == 2)    //피자
            {
                pizza.push_back(Pos(i, j));
            }
        }
    }

    DFS(0, 0);

    cout << answer;
}


