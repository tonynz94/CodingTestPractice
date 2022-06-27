﻿// 93_동적계획법응용2(메모제이션).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
도전과제 : 계단오르기(Top-Down : 메모이제이션)
철수는 계단을 오를 때 한 번에 한 계단 또는 두 계단씩 올라간다. 만약 총 4계단을 오른다면
그 방법의 수는
1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2 로 5가지이다.
그렇다면 총 N계단일 때 철수가 올라갈 수 있는 방법의 수는 몇 가지인가?
▣ 입력설명
첫째 줄은 계단의 개수인 자연수 N(3≤N≤45)이 주어집니다.
▣ 출력설명
첫 번째 줄에 올라가는 방법의 수를 출력합니다.
▣ 입력예제 1
7
▣ 출력예제 1
21

*/

#include <iostream>

using namespace std;
int _stairs;
int arr[45] = { 0 };

int DFS(int level)
{
    if (level <= 2)
        return level;
    else
        return arr[level] = DFS(level-2) + DFS(level - 1);
}

int main()
{
    cin >> _stairs;
    cout << DFS(_stairs);
}
