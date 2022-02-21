<<<<<<< Updated upstream
﻿#include <iostream>


void DDD()
{
    std::cout << "Hello World!\n";

}

//깊이 우선 탐색
//전위 순회
//중위 순회
//후위 순
void BFS(int level)
{
    if(level > 7)
        return;
    else
    {
        
        std::cout << level << std::endl; //전위

        //자식의 왼쪽으로 이동
        BFS(level*2);

        std::cout << level << std::endl; //중위

        //자식의 오른쪽으로 이동
        BFS(level*2 + 1);

        std::cout << level << std::endl; //후위
    }
}
=======
﻿#include<stdio.h>
#include<vector>
using namespace std;
int ch[30], cnt = 0, n, path[30];
vector<int> map[30];
void DFS(int v, int L) {
	int i, j;
	if (v == n) {
		cnt++;
		for (j = 0; j < L; j++) {
			printf("%d ", path[j]);
		}
		puts("");
	}
	else {
		for (i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i]] == 0) {
				ch[map[v][i]] = 1;
				path[L] = map[v][i];
				DFS(map[v][i], L + 1);
				ch[map[v][i]] = 0;
			}
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int m, i, j, a, b, c;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
	ch[1] = 1;
	path[0] = 1;
	DFS(1, 1);
	printf("%d\n", cnt);
	return 0;
}
>>>>>>> Stashed changes
