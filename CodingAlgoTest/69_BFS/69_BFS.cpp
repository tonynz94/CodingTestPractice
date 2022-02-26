// 65_DFS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

/*
이진트리 넓이우선탐색(BFS)
아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세
요.
       1
      2 3
	4 5 6 7
넓이 우선 탐색 : 1 2 3 4 5 6 7

입력
1 2
1 3
2 4
2 5
3 6
3 7

*/

//

#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

vector<pair<int, int>> v[10];
int main() {
	int i, a, b, x;
	for (i = 1; i <= 6; i++) {
		cin >> a;
		cin >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	v[2].push_back(make_pair(10, 20));
	Q[++back] = 1;
	ch[1] = 1;
	while (front < back) {
		x = Q[++front];
		printf("%d ", x);
		for (i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {
				ch[map[x][i]] = 1;
				Q[++back] = map[x][i];
			}
		}
	}
	return 0;
}
