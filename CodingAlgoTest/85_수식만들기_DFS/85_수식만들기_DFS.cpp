/*
85. 수식만들기(삼성 SW역량평가 기출문제 : DFS활용)
길이가 N인 자연수로 이루어진 수열이 주어집니다. 수열의 각 항 사이에 끼워넣을 N-1개의
연산자가 주어집니다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있습니
다.
수열의 순서는 그대로 유지한 채 각 항사이에 N-1개의 연산자를 적절히 배치하면 다양한 수
식이 나옵니다.
예를 들면
수열이 1 2 3 4 5이고 덧셈(+) 1개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 일 때
만들 수 있는 수식은 많은 경우가 존재한다.
그 중 1+2*3-4/5와 같이 수식을 만들었다면 수식을 계산하는 결과는 연산자 우선순위를 따지
지 않고 맨 앞쪽 연산자부터 차례로 계산한다. 수식을 계산한 결과는 1이다.
N길이의 수열과 N-1개의 연산자가 주어지면 만들 수 있는 수식들 중에서 연산한 결과가 최대
인것과 최소인것을 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫째 줄에 수의 개수 N(2 ≤ N ≤ 10)가 주어진다. 둘째 줄에 수열이 주어진다. 수열의 값은
100까지이다. 셋째 줄에는 연산자의 각 개수가 차례대로 덧셈(+) 개수, 뺄셈(-) 개수, 곱셈(×)
개수, 나눗셈(÷) 개수로 주어진다. 연산자의 총 개수는 N-1이다.
▣ 출력설명
첫째 줄에는 최댓값을, 둘째 줄에는 최솟값을 출력한다.
▣ 입력예제 1
    3
    5 3 8
    1 0 1 0
▣ 출력예제 1
    64
    23
*/
#include <iostream>
#include <vector>

using namespace std;

int cnt;
vector<int> v;
vector<int> a;
vector<int> ch;
vector<int> res;
int Arit[4] = { 0, 0, 0, 0 };
int max = -2147000000;
int min = 2147000000;

float cal()
{
    //0 2
    //2 0
    int result = v[0];  //8
    int i, j;
    for (i = 1, j = 0; i < cnt; i++,j++)
    {
        switch (res[j]) {   //1 => 2
        case 0:
            result = result + v[i];
            break;
        case 1:
            result = result - v[i];
            break;
        case 2:
            result = result * v[i]; //8 * 
            break;
        case 3:
            result = result / v[i];
            break;
        }
    }
    return result;
}

void DFS(int level) //0 1 2 
{
    if (level == cnt-1)   
    {
        vector<int>::iterator iter;
        //for (iter = res.begin(); iter != res.end(); iter++)
        //{
        //    cout << *iter << " ";
        //}
        //cout << endl;
        int result = cal();

        if (result > max)
            max = result;
        if (result < min)
            min = result;
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (ch[i] != 1)
            {
                ch[i] = 1;
                res[level] = a[i];
                DFS(level + 1);
                ch[i] = 0;
            }
        }
    }
}

int main()
{
    int num = 0;
    cin >> cnt;
    
    for (int i = 0; i < cnt; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            a.push_back(i);
            ch.push_back(0); 
            res.push_back(0);
        }
    }

    vector<int>::iterator iter;
   /* for (iter = a.begin(); iter != a.end(); iter++)
    {
        cout << *iter << " ";
    }*/
    cout << endl;
    cout << endl;

    DFS(0);

    cout << min << "\n" << max;
}
