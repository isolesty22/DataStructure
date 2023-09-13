#include <iostream>
#include <stack>

int main()
{
    using namespace std;

    int N;
    string exp;
    cin >> N >> exp;

    //치환
    for (int i = 0; i < N; i++)
    {
        string n;
        cin >> n;
        char ch = 'A';

        size_t pos;
        while ((pos=exp.find(ch+i)) != string::npos)
        {
            exp.replace(pos, 1, n);
        }
    }

    //후위 표기 계산
    stack<double> stack;

    char ch;
    int n = exp.length();
    for (int i = 0; i < n; i++)
    {
        ch = exp[i];

        if ('0' <= ch && ch <= '9')
        {
            int val;
            val = ch - '0';
            stack.push(val);
        }
        else if (ch == '+' || ch == '*' || ch == '-' || ch == '/')
        {
            double val2 = stack.top();
            stack.pop();
            double val1 = stack.top();
            stack.pop();

            switch (ch)
            {
            case '+': stack.push(val1 + val2); break;
            case '*': stack.push(val1 * val2); break;
            case '-': stack.push(val1 - val2); break;
            case '/': stack.push(val1 / val2); break;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stack.top();
}