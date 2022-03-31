
#include <iostream>
#include <map>

int main()
{
    std::cout << "Hello World!\n";
    std::map<int, int> m;
    std::cout << m.size();
    if (m[0] == 0)
    {
        std::cout << m[0];
        std::cout << m.size();
    }
}