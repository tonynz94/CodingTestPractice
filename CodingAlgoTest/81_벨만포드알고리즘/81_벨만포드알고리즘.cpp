#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

/*
5 7
1 2 5
1 3 4
2 3 -9
2 5 13
3 4 5
4 2 3
4 5 7
1 5

*/

using namespace std;

class toNode
{
public :
	int _toN;
	int _value;

	toNode(int toN, int value) : _toN(toN), _value(value){}
};

int main() 
{
	int n; //노드 수
	int cnt;

	int n1, n2, value;
	int to, from;

	cin >> n >> cnt;

	vector<vector<int>> map(n+1, vector<int>(n+1, 0));
	vector<int> answer(n+1 , 2147000000);

	for (int i = 0; i < cnt; i++)
	{
		cin >> n1 >> n2 >> value;
		map[n1][n2] = value;
	}

	cin >> to >> from;
	answer[to] = 0;

	cout << "==";

	for (int i = 1; i <= n; i++)
	{
		int node = i;
		for (int j = 1; j <= n; j++)
		{
			if (map[j][node] != 0)
			{
				if (answer[j] + map[j][node] < answer[node])
					answer[node] = answer[j] + map[j][node];
			}
		}
	}

	//싸이클 검사
	for (int i = 1; i <= n; i++)
	{
		int node = i;
		for (int j = 1; j <= n; j++)
		{
			if (map[j][node] != 0)
			{
				if (answer[j] + map[j][node] < answer[node]) {
					cout << "싸이클 존재";

					return 1;
				}
			}
		}
	}

	cout << answer[from];
	
}