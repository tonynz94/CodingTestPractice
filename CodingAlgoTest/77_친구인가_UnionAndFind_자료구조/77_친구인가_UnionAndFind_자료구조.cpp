﻿// 77_친구인가_UnionAndFind_자료구조.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*
오늘은 새 학기 새로운 반에서 처음 시작하는 날이다. 현수네 반 학생은 N명이다. 현수는 각
학생들의 친구관계를 알고 싶다.
모든 학생은 1부터 N까지 번호가 부여되어 있고, 현수에게는 각각 두 명의 학생은 친구 관계
가 번호로 표현된 숫자쌍이 주어진다. 만약 (1, 2), (2, 3), (3, 4)의 숫자쌍이 주어지면 1번 학
생과 2번 학생이 친구이고, 2번 학생과 3번 학생이 친구, 3번 학생과 4번 학생이 친구이다.
그리고 1번 학생과 4번 학생은 2번과 3번을 통해서 친구관계가 된다.
학생의 친구관계를 나타내는 숫자쌍이 주어지면 특정 두 명이 친구인지를 판별하는 프로그램
을 작성하세요. 두 학생이 친구이면 “YES"이고, 아니면 ”NO"를 출력한다.
▣ 입력설명
첫 번째 줄에 반 학생수인 자연수 N(1<=N<=1,000)과 숫자쌍의 개수인 M(1<=M<=3,000)이
주어지고, 다음 M개의 줄에 걸쳐 숫자쌍이 주어진다.
마지막 줄에는 두 학생이 친구인지 확인하는 숫자쌍이 주어진다.
▣ 출력설명
첫 번째 줄에 “YES"또는 "NO"를 출력한다.
▣ 입력예제 1
    9 7
    1 2
    2 3
    3 4
    4 5
    6 7
    7 8
    8 9
    3 8
▣ 출력예제 1
    NO
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;

int friends(int a, int b)
{
    //비어있다면
    if (m[a] == 0)
    {
        return m[a] = b;
    }
    else
    {
        return m[a] = friends(m[a], b);
    }
}

int Find(int a)
{
    if (m[a] == 0 || m[a] == a)
    {
        return a;
    }
    else
    {
        return Find(m[a]);
    }
}

int main()
{
    int cnt, n, a, b;
    cin >> cnt >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        friends(a, b);
    }

    cout << Find(3);
    cout << Find(8);

    std::map<int,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {

    }

    if (Find(3) == Find(8))
        cout << "YES";
    else
        cout << "NO";
}

