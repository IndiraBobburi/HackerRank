//
//  main.cpp
//  anagrams
//
//  Created by Indira Bobburi on 11/20/17.
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

int number_needed(string a, string b)
{
    int ans = 0;
    for(string::iterator iter = a.begin(); iter != a.end();  )
    {
        if(b.find(*iter) == string::npos)
        {
            iter = a.erase(iter);
            ans++;
        }
        else
        {
            iter++;
        }
    }
    
    for(string::iterator iter = b.begin(); iter != b.end();  )
    {
        if(a.find(*iter) == string::npos)
        {
            iter = b.erase(iter);
            ans++;
        }
        else
        {
            iter++;
        }
    }
    
    if(b.size() >= a.size())
        ans += (b.size() - a.size());
    else
        ans += (a.size() - b.size());
    
    return ans;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}


