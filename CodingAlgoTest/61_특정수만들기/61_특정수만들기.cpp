#include <iostream>
using namespace std;

int s[11];
int sum;
int n;
int cnt = 0;

void DFS(int level, int m)
{
	if (level == n + 1)
	{
		if (m == sum)
			cnt++;
		return;
	}

	DFS(level + 1, m);
	DFS(level + 1, m + s[level]);
	DFS(level + 1, m - s[level]);



}


int main()
{
	cin >> n;
	cin >> sum;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	DFS(1,0);

	if(cnt > 0)
		cout << cnt << endl;
	else
		cout << -1 << endl;
}
