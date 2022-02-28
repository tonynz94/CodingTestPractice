// 71_BFS_송아지_찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 현수의 위치와 송아
지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과
같은 방법으로 이동한다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수
있다. 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성
하세요.

▣ 입력설명
첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000
까지이다.

▣ 출력설명
점프의 최소횟수를 구한다.

▣ 입력예제 1
    5 14
▣ 출력예제 1
    3
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

int dx[] = { -1, 1, 5 };
int check[100];

using namespace std;

int main()
{
    int S;
    int M;
    int cnt = 0;
    bool flag = false;
    
    cin >> M;
    cin >> S;

    queue<int> Q;
    check[M] = 1;
    Q.push(M);

    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();

        for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
        {
            if (temp + dx[i] > 0 && check[temp + dx[i]] == 0) {
                Q.push(temp + dx[i]);
                check[temp + dx[i]] = check[temp] + 1;
            }
            else if (temp + dx[i] == S)
            {
                cout << check[temp + dx[i]] - 1;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
}

