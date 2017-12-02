//
//  main.cpp
//  nck
//
//  Created by Indira Bobburi on 11/26/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int nck(int n, int k)
{
    if(n-k < k) k = n-k;
    int c[k+1];
    memset(c, 0, sizeof(c));
    
    c[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
       for(int j = min(i,k); j > 0; j--)
       {
           c[j] = (c[j] + c[j-1]); 
       } 
    }
    
    /*for(int i=0; i<=n; i++)
    {
        for(int j=0; j<= min(i, k); j++)
        {
            if(j == 0 || j == i)
                val[i][j] = 1;
            else
                val[i][j] = val[i-1][j-1] + val[i-1][j];
        }
    }*/
    
    return c[k];
}

int main() 
{
    //string input;
    int i;
    cin >> i;
    while(i != 0)
    {
        int n, k;
        
        cin >> n;
        cin >> k;
        
        cout << nck(n, k) << endl;
        
        i--;
    }
    return 0;
}
