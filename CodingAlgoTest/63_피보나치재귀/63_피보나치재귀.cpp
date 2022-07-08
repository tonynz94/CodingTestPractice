//메모제이션
#include <iostream>
#include <vector>

using namespace std;

int arr[45];

int DFS(int index)
{
    if (arr[index] != 0)
        return arr[index];
    else if (index <= 1)
        return index;
    else {
        return arr[index] = DFS(index - 1) + DFS(index - 2);
    }
}

int main()
{
    int num = 0;
    cout << "피보나치 몇번쨰의 값을 가져올까요 ?";
    cin >> num;

    cout << DFS(num);
}
