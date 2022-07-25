// Lv3_프로그래머스_네트워크.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

void solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> node;
    vector<int> check(n, 0);
    int island = 0;
    int startNode = -1;

    startNode = -1;

    for (int j = 0; j < n; j++) {

        for (int i = 0; i < n; i++)
        {
            if (check[i] == 0) {
                check[i] = 1;
                startNode = i;

                island++;
                node.push(startNode);

                while (!node.empty())
                {
                    int tempNode = node.front();
                    node.pop();

                    //양방향이기에 나가는것뿐만 아니라 자기 자신으로 들어가는것도 검사를 해줘야한다. 
                    for (int i = 0; i < n; i++)
                    {
                        if (computers[tempNode][i] == 1 && check[i] != 1) {
                            node.push(i);
                            check[i] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << island;
}


int main()
{
    solution(4, { {1, 1, 0, 1},{1, 1, 0, 0},{0, 0, 1, 1},{1, 0, 1, 1} });
}
