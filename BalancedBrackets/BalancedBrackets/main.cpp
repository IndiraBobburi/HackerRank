//
//  main.cpp
//  BalancedBrackets
//
//  Created by Indira Bobburi on 11/22/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

map<char, char> mymap;

/*5
}][}}(}][))]
      [](){()}
      ()
      ({}([][]))[]()
{)[](}]}]}))}(())(*/

bool is_balanced(string expression)
{
    stack<char> s;
    for(char c : expression)
    {
        if( c == '{' || c == '[' || c == '(' )
        {
            s.push(c);
        }
        else if(!s.empty() && ((c == '}'  &&  s.top() == '{' ) ||
                               (c == ']'  && '[' == s.top()  ) ||
                               (c == ')'  && '(' == s.top()  )  ))
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    
    return s.empty();
    /*if(expression.size()%2 != 0)
        return false;
    
    int sum = 0;
    size_t at = expression.size()-1;
    
    for(int i = 0; i < expression.size()/2; i++)
    {
        char c = expression[i];
        size_t found = expression.find_last_of(mymap[c], at);
        
        at = found-1;
        
        if(sum == 0)
            sum = i+found;
        else if(i+found != sum)
            return false;
    }
    
    return true;*/
}

int main(){
    int t;
    cin >> t;
    mymap = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
    for(int a0 = 0; a0 < t; a0++)
    {
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

