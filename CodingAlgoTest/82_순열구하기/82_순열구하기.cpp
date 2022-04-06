#include <iostream>
#include <map>
#include <vector>

using namespace std;

int cnt, m;
vector<int> b(5);
vector<int> ch(5, 0);
vector<int> answer(3);

void DFS(int n)
{
	if (n == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i < b.size(); i++)	
		{
			if (ch[i] == 0)
			{
				answer[n] = b[i];
				ch[i] = 1;
				DFS(n + 1);
				ch[i] = 0;
			}
		}
	}
}


int main()
{
	cin >> cnt >> m;	//4 3

	for (int i = 1; i <= cnt; i++)	//4
	{
		cin >> b[i];
	}

	ch[0] = 1;
	DFS(0);
}