//후위연산을 통해 우선순위를 고려하여 계산하기
//0으로 나누어지는게 있으면 불가 출력하기
// 2 * 3 + 6 / 2 * 2
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

enum Oper
{
    ePlus,
    eSub,
    eMult,
    eDiv
};

class Cal
{
public:
    Oper _n;  //종류
    int _priority;   //우선순위

public:
    Cal(Oper n)
    {
        _n = n;
        switch (n)
        {
        case ePlus:
            _priority = 1;
            break;
        case eSub:
            _priority = 1;
            break;
        case eMult:
            _priority = 2;
            break;
        case eDiv:
            _priority = 2;
            break;
        }
    }
};

stack<Cal> s;    //후위연산표기를 위한 스택
stack<int> calu; //후위연산 계산을 위한 스택
queue<string> postOrder;

string GetOperator(Oper n)
{
    string c;
    switch (n) {
    case ePlus: c = "+"; break;
    case eSub:  c = "-"; break;
    case eMult: c = "*"; break;
    case eDiv:  c = "/"; break;
    }

    return c;
}

int main()
{
    //1+2*3+12
    //123*+
    string f = "-3*3+6/2*2";
    Cal cal(ePlus);
    string sss = "";

    if (f[0] == '-' || f[0] == '+')
        f.insert(0,"0");

    for (int a = 0; f[a] != '\0'; a++)
    {
        if ('0' <= f[a] && f[a] <= '9')
        {
            sss.push_back(f[a]);
        }
        else
        {
            postOrder.push(sss);
            sss.clear();

            switch (f[a]){
                case '+': cal = Cal(ePlus); break;
                case '-': cal = Cal(eSub);  break;
                case '*': cal = Cal(eMult); break;
                case '/': cal = Cal(eDiv);  break;
            }
           
            while (!s.empty() && (s.top()._priority >= cal._priority))
            {
                postOrder.push(GetOperator(s.top()._n)+"");
                s.pop();
            }
            s.push(cal);
        }      
    }
    postOrder.push(sss);
    sss.clear();

    while (!s.empty())
    {
        postOrder.push(GetOperator(s.top()._n)+"");
        s.pop();
    } 
    //====================후위연산 완료=======================

    //================후위연산을 통해 계산하기===============
    while (!postOrder.empty())
    {
        if ('0' <= postOrder.front()[0] && postOrder.front()[0] <= '9') //숫자라는 것
        {
            calu.push(stoi(postOrder.front()));
            postOrder.pop();
        }
        else
        {
            int b = calu.top();
            calu.pop();
            int a = calu.top();
            calu.pop();

   /*         postOrder.front() == "+"*/
            if(postOrder.front() == "+") calu.push(a + b);
            else if (postOrder.front() == "-") calu.push(a - b);
            else if (postOrder.front() == "*") calu.push(a * b);
            else if (postOrder.front() == "/")
            {
                if (b != 0)
                {
                    calu.push(a / b);
                }
                else
                {
                    cout << "Impossible" << endl;
                    return -1;
                }
            }

            postOrder.pop();
        }
    }

    cout << calu.top();
}


/*
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
using namespace std;

struct oper {
    int p;
    string o;
};

stack<int> num;
stack<oper> op;
bool flag = true;

void calc() {
    int a, b, result;
    b = num.top();
    cout << "b : " << b << endl;;
    num.pop();
    a = num.top();
    cout << "a : " << a << endl;;
    num.pop();

    string oper = op.top().o;
    op.pop();

    if (oper == "*")
        result = a * b;
    else if (oper == "/")
    {
        if (b != 0) {
            cout << a << " " << b << endl;
            result = a / b;

        }
        else {
            flag = false;
            cout << "0으로 나눔";
            return;
        }
    }
    else if (oper == "+")
        result = a + b;
    else if (oper == "-")
        result = a - b;

    num.push(result);
}


string solution(string input) {
    string answer = "";
    string tok;
    for (int i = 0; input[i] != '\0'; i++) {
        tok = input[i];
        if (tok == "*" || tok == "+" || tok == "-") {
            int prior; //
            if (tok == "*")
                prior = 2;
            else if (tok == "+")
                prior = 1;
            else if (tok == "-")
                prior = 1;

            while (!op.empty() && prior <= op.top().p)
                calc();

            op.push({ prior, tok });
        }
        else
            num.push(stoi(tok));
    }


    while (!op.empty() && flag)
        calc();

    if (flag) {
        int ans = num.top();
        answer = to_string(ans);
    }
    else
        answer = "impossible";

    return answer;
}


int main()
{
    cout << "1-2*3-5+2" << endl;
    cout << solution("1-2*3-5+2") << endl;
}

*/