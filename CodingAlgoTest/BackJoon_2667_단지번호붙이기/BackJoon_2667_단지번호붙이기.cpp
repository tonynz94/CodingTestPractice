// BackJoon_2667_단지번호붙이기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int xx[] = {-1,1,  0, 0};
int yy[] = {0, 0, -1, 1};

class Pos
{
public:
    int x;
    int y;
    Pos(int yy, int xx):x(xx),y(yy){}
};

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N, 0));
    queue<Pos> emptySpace;
    queue<Pos> bfsQueue;
    vector<int> apart;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            if (str[j] == '0')
                paper[i][j] = 0;
            else
                paper[i][j] = 1;

            if (paper[i][j] == 1)
                emptySpace.push(Pos(i, j));
        }
    }

    while (!emptySpace.empty())
    {
        Pos startPos = emptySpace.front();
        emptySpace.pop();

        if (paper[startPos.y][startPos.x] == 0)
            continue;
        paper[startPos.y][startPos.x] = 0;
        bfsQueue.push(startPos);
        apart.push_back(1);

        while (!bfsQueue.empty())
        {
            Pos tempPos = bfsQueue.front();
            bfsQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int sideX = xx[i] + tempPos.x;
                int sideY = yy[i] + tempPos.y;
                //cout << sideY;
                //cout << sideX;
                //cout << endl;
                //cout << "@";
                //끝쪽 검사
                if (sideX < 0) continue;
                if (sideX >= N) continue;
                if (sideY < 0) continue;
                if (sideY >= N) continue;
                if (paper[sideY][sideX] == 0) continue;
                

                bfsQueue.push(Pos(sideY, sideX));
                paper[sideY][sideX] = 0;
                apart[apart.size() - 1]++;
            }
        }
    }

    sort(apart.begin(), apart.end());

    std::cout << apart.size() << endl;
    for (int i = 0; i < apart.size(); i++)
    {
        std::cout << apart[i] << endl;
    }
}

/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0

*/
