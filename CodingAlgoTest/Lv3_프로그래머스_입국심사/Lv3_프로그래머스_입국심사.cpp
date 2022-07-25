// Lv3_프로그래머스_입국심사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    //여기 중요 long =  int * int는 먼저 int로 곱하기 때문에 여기서 곱한 결과가 int의 max값을 넘어가게되면 오버플로우가 발생한다.
    //이를 방지하기 위해 하나는 long long값으로 변환하여 곱셈 자체를 long long으로 바꾸고 곱셈을 해서 오버플로우를 방지시키자.
    long long max = times[times.size() - 1] * static_cast<long long>(n);
    long long min = 1;
    long long answer = max;

    while (min <= max)
    {
        long long mid = (max + min) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++)
        {
            sum += (mid / times[i]);
        }

        //해당 시간으로 가능하면 더 최적화된 값이 있는지 확인을 위해 max값을 낮춰줌
        if (sum >= n)
        {
            //여기 들어올때마다 최적의 값을 찾았다는 것이기에 최소값인지 비교해줄필요가 없음 그냥 바로 해주면됨 
            max = mid - 1;
            answer = mid;
        }
        else
            min = mid + 1;
    }

    return answer;
}

int main()
{
    std::cout << solution(6, { 7, 10 });
}