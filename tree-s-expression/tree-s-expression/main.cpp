//
//  main.cpp
//  tree-s-expression
//
//  Created by Indira Bobburi on 11/25/17.
//  Copyright © 2017 sjsu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Tree
{
public:
    Tree(){};

    void sexp(vector<pair<char, char>> pairs)
    {
        for(auto p:pairs)
        {
            char i = p.first, j = p.second;
            nodes.insert(pair<char, set<char>>(i, set<char>()));
            nodes.insert(pair<char, set<char>>(j, set<char>()));
            nodes[j].insert(i);
            
            if(edges.count(i))
            {
                if(edges[i].count(j))
                {
                    cout << "E2\n";
                    exit(1);
                }
                else
                {
                    edges[i].insert(j);
                    if(edges[i].size() > 2)
                    {
                        cout << "E1\n";
                        exit(1);
                    }
                }
            }
            else
            {
                edges[i].insert(j);
            }
        }
        
        //sort
        for(auto e : edges)
        {
            vector<int> vec(e.second.begin(), e.second.end());
            sort(vec.begin(), vec.end());
            e.second.clear();
            for(auto n:vec) 
                e.second.insert(n);
        }
        
        char root = '0';
        for(auto n : nodes)
        {
            if(n.second.size()==0)
            {
                if(root!='0')
                {
                    cout<<"E4\n"<<endl;
                    exit(1);
                }
                else
                {
                    root = n.first;
                }
            }
        }
        set<char> visited;
        cout<< dfs(root, visited) <<endl;
    }
    
    string dfs(char cur, set<char> &visited)
    {
        visited.insert(cur);
        string ret = "(";
        ret += cur;
        if(edges.count(cur))
        {
            for(auto n:edges[cur])
            {
                if(visited.count(n))
                {
                    cout<<"E3\n";
                    exit(1);
                }
                ret += dfs(n, visited);
            }
        }
        ret += ")";
        return ret;
    }
private:
    map<char, set<char>> nodes;//in
    map<char, set<char>> edges;//out
};

int main()
{
    Tree tree;
    vector<pair<char, char>> pairs;
    
    string line, s;
    while(cin >> s)
    {
        pairs.push_back(pair<char, char>(s[1], s[3]));
        cout<<s<<endl;
    }
    tree.sexp(pairs);
    return 0;
}
