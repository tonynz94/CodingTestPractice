// 97_위상정렬.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의
순서를 짜는 알고리즘입니다.
만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
1 4 //1번일을 하고 난 후 4번일을 해야한다.
5 4
4 3
2 5
2 3
6 2
1
5
6
4
2
3
전체 일의 순서는 1, 6, 2, 5, 4, 3과 같이 정할 수 있다. 전체 일의 순서는 여러 가지가 있습
니다 그 중에 하나입니다.
▣ 입력설명
첫 번째 줄에 전체 일의 개수 N과 일의 순서 정보의 개수 M이 주어집니다.
두 번째 줄부터 M개의 정보가 주어집니다.
▣ 출력설명
전체 일의 순서를 출력합니다.
▣ 입력예제 1
6 6
1 4
5 4
4 3
2 5
2 3
6 2
▣ 출력예제 1
1 6 2 5 4 3*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int node; //정점 수
    int path; //경로 수

    int start,end;

    cin >> node;
    cin >> path;

    //그래프에 대한 인접행렬로
    vector<vector<int>> graph(node + 1, vector<int>(node + 1 , 0));
    //다른 노드로부터 들어오는 경로의 수
    vector<int> incomingPath(node + 1, 0);

    for (int i = 0; i < path; i++)
    {
        cin >> start;
        cin >> end;
        incomingPath[end]++;
        graph[start][end] = 1;
    }
    for (int a = 1; a <= node; a++) {

        //들어오는 경로 0인 노드를 찾아줌
        int min = -1;
        for (int i = 1; i <= node; i++)
        {
            if (incomingPath[i] == 0)
            {
                //찾은건 -1로 표시하여 다시 선택안되도록 방지
                incomingPath[i] = -1;
                min = i;
                break;
            }
        }

        //다른 노드로 부터 들어오는 경로가 0인 노드 출력
        cout << min <<  " ";

        //min노드로 부터 들어오는 경로 갯수를 삭제
        for (int i = 1; i <= node; i++)
        {
            if (graph[min][i] >= 1)
                incomingPath[i]--;
        }
    }
}