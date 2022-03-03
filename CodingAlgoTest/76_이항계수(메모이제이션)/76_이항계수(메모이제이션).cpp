// 76_이항계수(메모이제이션).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 경우의 수
를 의미한다. 5C3
N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)과 R(0<=R<=20)이 주어진다. 단 (N>=R)
▣ 출력설명
첫 번째 줄에 이항계수 값을 출력한다.
▣ 입력예제 1
    5 3
▣ 출력예제 1
    10
*/

#include <iostream>
using namespace std;
int mem[20][20];
int C(int n, int r)
{
    if(mem[n][r] != 0)
        return mem[n][r];
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return mem[n][r] = C(n - 1, r - 1) + C(n - 1, r);
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << C(n, r);
}