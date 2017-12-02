//
//  main.cpp
//  rgb_values
//
//  Created by Indira Bobburi on 11/23/17.
//  Copyright © 2017 sjsu. All rights reserved.
// 100 00000000 00000000

#include <iostream>
#include <string>
#include <bitset>
#include "math.h"

using namespace std;

/*sequence of 24 bits that represent a pixel. The leftmost 8 bits give the red component of the pixel,
 the middle 8 bits give the green component and the rightmost 8 bits give the blue component.
 The red, green and blue components of the pixel can take values between 0 (binary 00000000) to 255 (binary 11111111) each.

I need to identify whether the color of this pixel is geometrically closest to pure red, green, white or black.
The geometric distance between two colors with RGB component (r1, g1, b1) and (r2,g2,b2) is given by

d = ( (r1-r2)^2 + (g1-g2)^2 + (b1-b2)^2 ) ^ 1/2
The RGB value of pure black is (0, 0, 0), pure white is (255, 255, 255), pure red is (255, 0, 0) and pure blue is (0, 0, 255)*/

class Color
{
public:
    Color(int r, int g, int b, string name = "") : r(r), g(g), b(b), name(name)
    {
    }
    
    int distance(Color &color)
    {
        return pow(this->r - color.r , 2) + pow(this->g - color.g , 2) + pow(this->b - color.b , 2);
    }

    int r, g, b;
    string name;
};

Color* var[5] =
{
    new Color(255, 0, 0, "Red"),
    new Color(0, 255, 0, "Green"),
    new Color(0, 0, 255, "Blue"),
    new Color(255, 255, 255, "White"),
    new Color(0, 0, 0, "Black")
};

string findClosest(string num)
{
    bitset<8> r(num.substr(0,8));
    bitset<8> g(num.substr(8,8));
    bitset<8> b(num.substr(16,8));
    
    Color x(r.to_ulong(), g.to_ulong(), b.to_ulong());
    
    string result;
    int smallest = 0X40000;
    int count = 0;
    
    for(auto c : var)
    {
        int dis = x.distance(*c);
        
        if(dis == smallest)
        {
            count++;
        }
        
        if(dis < smallest)
        {
            result = c->name;
            smallest = dis;
        }
    }
    
    return count ? "Ambiguous" : result;
}

int main()
{
    int n;
    string val;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        cout << findClosest(val) << endl;
    }
    
    return 0;
}
