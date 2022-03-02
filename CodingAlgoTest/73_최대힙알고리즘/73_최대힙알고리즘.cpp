﻿// 73_최대힙알고리즘.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
최대힙은 완전이진트리로 구현된 자료구조입니다. 그 구성은 부모 노드값이 왼쪽자식과 오른
쪽 자식노드의 값보다 크게 트리를 구성하는 것입니다. 그렇게 하면 트리의 루트(root)노드는
입력된 값들 중 가장 큰 값이 저장되어 있습니다. 예를 들어 5 3 2 1 4 6 7순으로 입력되면
최대힙 트리는 아래와 같이 구성됩니다.
        7
      /    |
    4      6
  /  |     /  |
 1   3   2   5
최대힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
1) 자연수가 입력되면 최대힙에 입력한다.
2) 숫자 0 이 입력되면 최대힙에서 최댓값을 꺼내어 출력한다.
 (출력할 자료가 없으면 -1를 출력한다.)
3) -1이 입력되면 프로그램 종료한다.
▣ 입력설명
첫 번째 줄부터 숫자가 입력된다. 입력되는 숫자는 100,000개 이하이며 각 숫자의 크기는 정
수형 범위에 있다.
▣ 출력설명
2) 연산을 한 결과를 보여준다.
[C++를 이용한 창의적 문제 해결]
▣ 입력예제 1
    5
    3
    6
    0
    5
    0
    2
    4
    0
    -1
▣ 출력예제 1
    6
    5
    5
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    
    int n = 0;

    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        else if(n == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
                pq.pop();
            }
            else
            {
                cout << "우선큐가 비어있습니다." << endl;
            }
        }
        else
        {
            pq.push(n);
        }
    }
}
