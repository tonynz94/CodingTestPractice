// 75_최대수입스케쥴(priority_queue_응용문제).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
현수는 유명한 강연자이다. N개이 기업에서 강연 요청을 해왔다. 각 기업은 D일 안에 와서 강
연을 해 주면 M만큼의 강연료를 주기로 했다.
각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10,000)이 주어지고, 다음 N개의 줄에 M(1<=M<=10,000)과
D(1<=D<=10,000)가 차례로 주어진다.
▣ 출력설명
첫 번째 줄에 최대로 벌 수 있는 수입을 출력한다.
▣ 입력예제 1
    6
    50 2
    20 1
    40 2
    60 3
    30 3
    30 1
▣ 출력예제 1
    150
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class A
{
public:
    int _money;
    int _day;

    A(int money, int day) :_money(money), _day(day) {}
    bool operator<(const A& temp) const
    {
        if (temp._day != _day)
            return _day > temp._day;

        return _money > temp._money;

    }
};

int main()
{
    int cnt;
    int m, d;
    int mDay;
    vector<A> v;
    priority_queue<int> pq;

    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> m >> d;
        v.push_back(A(m, d));     
    }
    sort(v.begin(), v.end());
    mDay = v[0]._day;

    int tempDay = mDay;
    int ptr = 0;
    int answer = 0;

    while (ptr < v.size())
    {        
            while (ptr < v.size() && v[ptr]._day == tempDay)
            {
                pq.push(v[ptr]._money);
                ptr++;
            }
            if (pq.empty() == false) {
                answer += pq.top();
                pq.pop();
            }

            tempDay--;
    }
    cout << answer;
}
