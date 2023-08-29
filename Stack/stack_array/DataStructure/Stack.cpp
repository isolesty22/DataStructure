#include <iostream>
#include <fstream>
#include "StackArray.h"

double calc(const char* fileName)
{
    using namespace std;

    StackArray<double> stack;
    ifstream fin(fileName);
    char ch;

    while (fin.get(ch))
    {
        if ('0' <= ch && ch <= '9') 
        {
            fin.unget();
            double val;
            fin >> val;
            stack.push(val);
        }
        else if (ch == '+'||ch=='*'||ch=='-'||ch=='/')
        {
            double val2 = stack.pop();
            double val1 = stack.pop();

			switch (ch)
			{
			case '+': stack.push(val1 + val2); break;
			case '*': stack.push(val1 * val2); break;
			case '-': stack.push(val1 - val2); break;
			case '/': stack.push(val1 / val2); break;
			}
        }
    }
    
    fin.close();

    return stack.pop();
}

int precedence(char op)
{
    switch (op)
    {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void change(std::string & fileName)
{
    using namespace std;

	/*ifstream fin;
	fin.open(fileName);
	char ch;

	if (fin.is_open())
	{
		while (fin.get(ch))
		{
			cout << ch;
		}
	}*/

    StackArray<char> stack;
    ifstream fin(fileName);

    char ch;
    char op;
   
    ofstream fout("result.txt");



    /*if (fin.is_open())
    {
        while (fin.get(ch))
        {
            cout << ch;
        }
    }*/



    while (fin.get(ch))
    {
        if ('0' <= ch && ch <= '9')
        {
            fin.unget();
            double val;
            fin >> val;
            fout << val << ' ';
            //cout << val << ' ';
        }
        else if (ch == '(') 
            stack.push(ch);
        else if (ch == ')')
        {
            while (!stack.isEmpty())
            {
                op = stack.pop();
                if (op == '(')
                    break;
                else
                {
                    fout << op << ' ';
                    //cout << op << ' ';
                }
            }
        }
        else if (ch == '+' || ch == '*' || ch == '-' || ch == '/')
        {
            while (!stack.isEmpty())
            {
                op = stack.peek();
                if (precedence(ch) <= precedence(op))
                {
                    //스택에서 빼내고 새로운 거 푸시.
                    fout << stack.pop() << ' ';
                    //cout << stack.pop() << ' ';
                }
				else break;
            }

            stack.push(ch);
        }
    }

    while (!stack.isEmpty())
    {
        //cout << stack.pop() << ' ';
        fout << stack.pop() << ' ';
    }

    fin.close();
    fout.close();
}

int main()
{
    using namespace std;

    cout << "파일 이름을 입력하시오: ";
    string fileName;
    cin >> fileName;
    //cin.get();

	cout << "수식을 입력하시오: ";
    string text;
   cin >> text;

	ofstream fout(fileName);
    fout << text;
	fout.close();
     
	change(fileName);
    
    double result = calc("result.txt");
    cout << result;
}   