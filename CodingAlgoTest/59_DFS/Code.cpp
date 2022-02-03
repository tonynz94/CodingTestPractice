#include <iostream>
#include <vector>

using namespace std;

int _level;
int ch[11] = {0};


void DFS(int depth)
{
	if (depth > _level)
	{
		for (int i = 1; i <= _level; i++)
		{
			if (ch[i] == 1)
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	ch[depth] = 1;
	DFS(depth + 1);

	ch[depth] = 0;
	DFS(depth + 1);
}


int main()
{
	
	cin >> _level;

	DFS(1);
}

