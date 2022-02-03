#include <iostream>

int n;
int s[11];
bool isTrue = false;

void DFS(int level, int ASum, int BSum)
{
    //이미 넘어 오던게 있었다면.
    if (isTrue)
        return;

    if (level == n + 1)
    {
        if (ASum == BSum) {
            std::cout << ASum << " : " << BSum << std::endl;
            isTrue = true;
        }
        return;
    }

    DFS(level + 1, ASum + s[level], BSum);
    DFS(level + 1, ASum, BSum + s[level]);

}


int main()
{
    std::cin >> n;
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        std::cin >> s[i];
    }
    DFS(1, 0, 0);

    if (isTrue)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
