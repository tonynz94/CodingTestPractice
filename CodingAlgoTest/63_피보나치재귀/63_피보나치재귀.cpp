//메모제이션
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int arr[45];
//
//int DFS(int index)
//{
//    if (arr[index] != 0)
//        return arr[index];
//    else if (index <= 1)
//        return index;
//    else {
//        return arr[index] = DFS(index - 1) + DFS(index - 2);
//    }
//}

int answer = 0;
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };
vector<vector<int>> map;

void DDFS(int yy, int xx)
{
    if (yy == map.size() - 1 && xx == map[0].size() - 1)
        answer++;
    else
    {
        for (int i = 0; i < 2; i++)
        {
            if (yy + dy[i] < 0 || 
                xx + dx[i] < 0 ||
                yy + dy[i] >= map.size() || 
                xx + dx[i] >= map[0].size() ||
                map[yy + dy[i]][xx + dx[i]] == 1)
                continue;
            DDFS(yy + dy[i], xx + dx[i]);
        }
    }

}

//m이 가로
//n이 높이
class Pos
{
public:
    int y;
    int x;
    Pos(int _y, int _x):y(_y),x(_x){}
};

void solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> _map(n, vector<int>(m, 0));
    queue<Pos> q;
    for (int i = 0; i < puddles.size(); i++)
    {
        _map[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }

    q.push(Pos(0, 0));
    _map[0][0] = 1;
    while (!q.empty())
    {
        Pos target = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            if (target.y + dy[i] < n && 
                target.x + dx[i] < m && 
                _map[target.y + dy[i]][target.x + dx[i]] != -1)
            {
                //0이 아니면 이미 큐에 들어갔다는 것
                if (_map[target.y + dy[i]][target.x + dx[i]] == 0)
                    q.push(Pos(target.y + dy[i], target.x + dx[i]));

                _map[target.y + dy[i]][target.x + dx[i]] = _map[target.y + dy[i]][target.x + dx[i]] + _map[target.y][target.x];
                
                
            }
        }
    }
 
    cout << _map[n-1][m-1];
}

int main()
{
    //int num = 0;
    //cout << "피보나치 몇번쨰의 값을 가져올까요 ?";
    //cin >> num;

    //cout << DFS(num);

    solution(5, 6, { {2,2} });
}


