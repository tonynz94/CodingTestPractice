// 92_동적계획법응용.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;


    int _measure;
    int arr[45] = {0};
    int Recu(int measure)
    {
        if (measure <= 2)
        {
            return measure;
        }
        else
        {
            return arr[measure] = Recu(measure - 1) + Recu(measure - 2);
        }
    }

    void main()
    {
        cin >> _measure;
        Recu(_measure);
        cout << arr[mea]
    }