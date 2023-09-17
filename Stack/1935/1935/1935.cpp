#include <iostream>
#include <stack>

int main()
{
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string exp;
    cin >> N >> exp;

    int* operands = new int[N];
    
    for (int i = 0; i < N; i++)
    {
        cin >> operands[i];
    }

    stack<double> stack;

    for (int i = 0; i < exp.length(); i++)
    {
        if ('A' <= exp[i] && exp[i] <= 'Z')
        {
            //A를 1로 바꾸고 인덱스에 대응
            stack.push(operands[exp[i] - 'A']);
        }
        else if (exp[i] == '+' || exp[i] == '*' || exp[i] == '-' || exp[i] == '/')
        {
            double val2 = stack.top();
            stack.pop();
            double val1 = stack.top();
            stack.pop();

            switch (exp[i])
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