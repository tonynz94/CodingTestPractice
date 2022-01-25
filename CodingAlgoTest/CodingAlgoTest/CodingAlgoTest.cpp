#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

}

//깊이 우선 탐색
//전위 순회
//중위 순회
//후위 순
void BFS(int level)
{
    if(level > 7)
        return;
    else
    {
        
        std::cout << level << std::endl; //전위

        //자식의 왼쪽으로 이동
        BFS(level*2);

        std::cout << level << std::endl; //중위

        //자식의 오른쪽으로 이동
        BFS(level*2 + 1);

        std::cout << level << std::endl; //후위
    }
}
