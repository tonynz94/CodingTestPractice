/*
▣ 입력예제 1
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
▣ 출력예제 1
25
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xx[] = { -1, 0, 1, 0 };
int yy[] = { 0 ,-1, 0, 1 };

int main()
{
    int num;
    cin >> num;
    vector<vector<int>> map(num, vector<int>(num, 0));
    vector<vector<int>> answer(num, vector<int>(num, INT32_MAX));
    vector<vector<int>> check(num, vector<int>(num, 0));

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> map[i][j];
        }
    }
    

    answer[0][0] = map[0][0];
    for (int i = 0; i < num*num; i++)
    {
        int minCost = INT32_MAX;
        int minX = 0;
        int minY = 0;
        for (int a = 0; a < num; a++)
        {
            for (int b = 0; b < num; b++)
            {
                if (answer[a][b] < minCost && check[a][b] == 0) {
                    minCost = answer[a][b];
                    minX = a;
                    minY = b;
                }
            }
        }
        
        check[minX][minY] = 1;

        for (int dir = 0; dir < 4; dir++)
        {
            int desX = minX + xx[dir];
            int desY = minY + yy[dir];

            if (desX >= num || desY >= num || desX < 0 || desY < 0)
            {
                continue;
            }

            int costValue = answer[minX][minY] + map[desX][desY];
            if(answer[desX][desY] > costValue)
                answer[desX][desY] = answer[minX][minY] + map[desX][desY];
        }

        
    }
    cout << answer[num - 1][num - 1];
}
