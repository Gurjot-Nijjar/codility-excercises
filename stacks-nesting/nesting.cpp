

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>


int solution(string &S) {
    
    stack<char> _par;
    
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
        {
            _par.push(S[i]);
        }
        else 
        {
            if(_par.top() == '(')
            {
                _par.pop();
            }
            else
            {
                _par.push(S[i]);
            }
        }
    }
    
    if(_par.empty() != true)
    {
        return 0;
    }
    
    else
    {
        return 1;
    }
    
    // write your code in C++14 (g++ 6.2.0)
}

