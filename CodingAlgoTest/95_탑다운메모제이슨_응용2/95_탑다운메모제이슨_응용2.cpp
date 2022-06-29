// 95_탑다운메모제이슨_응용2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
* 왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다.
왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다.
오른쪽의 번호 정보가 위부터 아래 순서로 주어지만 서로 선이 겹치지 않고 최대 몇 개의 선
을 연결할 수 있는 지 구하는 프로그램을 작성하세요.
    1   4
    2   1
    3   2
    4   3
    5   9
    6   7
    7   5
    8   6
    9   10
    10   8
왼쪽 오른쪽
위의 그림은 오른쪽 번호 정보가 4 1 2 3 9 7 5 6 10 8 로 입력되었을 때 선이 서로 겹치지
않고 연결할 수 있는 최대 선을 개수 6을 구한 경우입니다.
▣ 입력설명
첫 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 1부터 N까지의 자연수 N개의 오른쪽 번호 정보가 주어집니다. 순서는 위쪽번호
부터 아래쪽번호 순으로입니다.
▣ 출력설명
첫 줄에 겹치지 않고 그을 수 있는 최대선의 개수를 출력합니다.
▣ 입력예제 1
10
4 1 2 3 9 7 5 6 10 8
▣ 출력예제 1
6
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int count;
    cin >> count;

    vector<int> v(count + 1, 0);
    map<int, int> answer;
    int realAnswer = 0;
    int max = 0;
    int pivot = 0;

    for (int i = 1; i <= count; i++)
        cin >> v[i];

    //4 1 2 3 9 7 5 6 10 8
    answer[v[1]] = 1;
    for (int i = 2; i <= count; i++)    //증가수열의 마지막 숫자
    {
        pivot = v[i];   //3
        max = 1;
        for (int j = 1; j < i; j++) //마지막의 2번쨰 숫자
        {
            if (pivot > v[j])   //(3 > 4) (3 > 1) (3 > 2)  
            {
                if (max < answer[v[j]] + 1)
                {
                    max = answer[v[j]] + 1;
                }
            }
        }
        answer[v[i]] = max;
        if (realAnswer > max)
            realAnswer = max;
    }

    cout << realAnswer << endl;

}
