// 94_부분증가수열_탑다운메모제이션.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
N개의 자연수로 이루어진 수열이 주어졌을 때, 그 중에서 가장 길게 증가하는
(작은 수에서 큰수로) 원소들의 집합을 찾는 프로그램을 작성하라. 예를 들어, 원소가 2, 7, 5, 8, 6, 4, 7, 12, 3 이면 
가장 길게 증가하도록 원소들을 차례대로 뽑아내면 2, 5, 6, 7, 12를 뽑아내어 길이가 5인 
최대 부분 증가수열을 만들 수 있다.

▣ 입력설명
첫째 줄은 입력되는 데이터의 수 N(2≤N≤1,000, 자연수)를 의미하고,
둘째 줄은 N개의 입력데이터들이 주어진다.

▣ 출력설명
첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.

▣ 입력예제 1
	8
	5 3 7 8 6 2 9 4

▣ 출력예제 1
	4

*/



#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int num;
	cin >> num;

	vector<int> v(num + 1, 0);
	map<int,int> answer;

	/*answer[0] += 3;
	answer[0] += 3;

	cout << answer[0];*/

	for (int i = 1; i < v.size(); i++)
		cin >> v[i];
	
	answer[v[1]] = 1;
	int max = 1;
	int realAnswer = 0;
	//5 3 7
	for (int i = 2; i < v.size(); i++)
	{

		int pivot = v[i]; //7
		answer[pivot] = 1;
		max = 1;
		for (int j = 1; j < i; j++)
		{
			if (pivot > v[j]) { //7>=5	7>=3
				if (answer[pivot] + answer[v[j]] > max)
					max = answer[pivot] + answer[v[j]];
			}
		}
		answer[pivot] = max;
		if (realAnswer < max)
			realAnswer = max;
	}

	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}

	cout << realAnswer << endl;

}

