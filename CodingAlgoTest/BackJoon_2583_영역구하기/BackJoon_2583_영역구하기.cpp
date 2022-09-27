#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Pos
{
public:
    int x;
    int y;
    Pos(int xx, int yy) : x(xx), y(yy)
    {

    }
};
//상하좌우
int xx[] = {-1,1,0, 0};
int yy[] = { 0,0,1,-1};

Pos FoundSpace(vector<vector<int>> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p[0].size(); j++)
        {
            if (p[i][j] == 0)
            {
                return Pos(j, i);
            }
        }
    }
    return Pos(-1, -1);
}


int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    
    vector<vector<int>> vec(K, vector<int>(4, 0));

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> vec[i][j];
        }
    }

    //색칠 부분 풀이 시작
    vector<vector<int>> paper(M, vector<int>(N, 0));

    for (int i = 0; i < K; i++)
    {
        int minX = vec[i][0];   //0
        int minY = vec[i][1];   //2
        int maxX = vec[i][2]-1;   //4
        int maxY = vec[i][3]-1;   //4

        for (int b = minY; b <= maxY; b++) {
            for (int a = minX; a <= maxX; a++)
            {
                paper[b][a] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << paper[i][j] << " ";
        }
        cout << endl;
    }

    int StartX = 0;
    int StartY = 0;

    queue<Pos> q;
    vector<int> sepSpaceArea;
    int sepSpace = 0;

    Pos startPos(0,0);

    while ((startPos = FoundSpace(paper)).x != -1) {
        paper[startPos.y][startPos.x] = 1;
        sepSpaceArea.push_back(1);  //섬별로 면적
        q.push(startPos);

        while (!q.empty())
        {
            Pos pos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int sideX = pos.x + xx[i];
                int sideY = pos.y + yy[i];

                if (sideX < 0) continue;
                if (sideX >= N) continue;
                if (sideY < 0) continue;
                if (sideY >= M) continue;
                if (paper[sideY][sideX] == 0)
                {
                    paper[sideY][sideX] = 1;
                    sepSpaceArea[sepSpaceArea.size()-1]++;
                    q.push(Pos(sideX, sideY));
                }
            }
        }
    }

    cout << sepSpaceArea.size() << endl;
    sort(sepSpaceArea.begin(), sepSpaceArea.end());
    for (int i = 0; i < sepSpaceArea.size(); i++)
    {
        cout << sepSpaceArea[i] << " ";
    } 
}


