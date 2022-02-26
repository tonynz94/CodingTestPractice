// 65_DFS.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

/*
����Ʈ�� ���̿켱Ž��(BFS)
�Ʒ� �׸��� ���� ����Ʈ���� ���̿켱Ž���� ������. ���� ���� 6���� �Է¹޾� ó���غ���
��.
       1
      2 3
	4 5 6 7
���� �켱 Ž�� : 1 2 3 4 5 6 7

�Է�
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
