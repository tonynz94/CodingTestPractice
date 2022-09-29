#include <iostream>
#include <vector>
using namespace std;
vector<char> vec(15,0);
vector<char> check(15,0);
int L, C;

void GolfMapLevelInfomation(int level, int startIndex)
{
    if (level == L)
    {
        for (int i = 0; i < C; i++)
        {
            if (check[i] == 1)
                cout << vec[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = startIndex; i < C; i++)
        {
            check[i] = 1;
            GolfMapLevelInfomation(level + 1, i + 1);
            check[i] = 0;
        }
        
    }
}

int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> vec[i];
    }

    GolfMapLevelInfomation(0, 0);
}
