// 91_동적계획법.cpp :
/*
네트워크 선 자르기
현수는 네트워크 선을 1m, 2m의 길이를 갖는 선으로 자르려고 합니다.
예를 들어 4m의 네트워크 선이 주어진다면
1) 1m+1m+1m+1m
2) 2m+1m+1m
3) 1m+2m+1m
4) 1m+1m+2m
5) 2m+2m
의 5가지 방법을 생각할 수 있습니다. (2)와 (3)과 (4)의 경우 왼쪽을 기준으로 자르는 위치가
다르면 다른 경우로 생각한다.
그렇다면 네트워크 선의 길이가 Nm라면 몇 가지의 자르는 방법을 생각할 수 있나요?
▣ 입력설명
첫째 줄은 네트워크 선의 총 길이인 자연수 N(3≤N≤45)이 주어집니다.
▣ 출력설명
첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int measure;
int answer = 0;


//방법1 점화식 이용 (피보나치 수열과 같은 방식)
//f(n) = f(n-2) + f(n-1)

//1m 를 자를 수 있는 횟수 : 1											   = a
//2m 를 자를 수 있는 횟수 : 2 (	(1m,1m) , (2m)	)					   = b
//3m 를 자를 수 있는 횟수 : 3 (	(1m, 1m, 1m) , (2m, 1m), (1m, 2m)	)  = a + b = c
//4m 를 자를 수 있는 횟수 : b + c 

void main()
{
	cin >> measure;
	vector<int> v(measure+1, 0);
	
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i <= measure; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[measure];
}


//방법2 DFS 이용 
// |-|-|-|-|
//void DFS(int level)
//{
//    if (level == measure)
//    {
//        answer++;
//    }
//    else if (level > measure)
//    {
//        return;
//    }
//    else 
//    {
//        for (int i = 1; i <= 2; i++)
//        {
//            DFS(level + i);
//        }
//    }
//}
//
//int main()
//{
//    cin >> measure;
//    DFS(0);
//
//    cout << answer;
//}

//방법 2

