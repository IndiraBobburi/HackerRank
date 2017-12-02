//
//  main.cpp
//  longest_inc_subsequence
//
//  Created by Indira Bobburi on 11/26/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>

using namespace std;

/*int compute(int a[], int n)
{
    int count = 1;
        
    for(int j=0; j<n; j++)
    {
        if(count < n-j)
        {
            int c = 1;
            int prev = a[j];
            for(int k=j+1; k<n; k++)
            {
                if(a[k] > prev)
                {
                    c++;
                    prev = a[k];
                }
            }
            if(c > count)
                count = c;
        }
        else
            break;
    }
    
    return count;
}*/

int compute(int a[], int n)
{
    int L[n];
    for(int i=0; i<n; i++)
    {
        L[i] = 1;
    }
    
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                L[i] = max(L[i], 1+L[j]);
            }
        }
    }
    
    int res = L[0];
    for(int i = 1; i<n; i++)
    {
        if(res < L[i])
            res = L[i];
    }
    
    return res;
}

int main() 
{
    int n_input;
    cin >> n_input;
    
    for(int i=0; i<n_input; i++)
    {
        int n;
        cin >> n;
        int a[n];
        for(int j=0; j<n; j++)
        {
            cin >> a[j];
        }
        
        cout << compute(a, n) << endl;
    }
    return 0;
}
