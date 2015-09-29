//
//  main.cpp
//  Squirrel
//
//  Created by Martin Olof Norberg on 2015-09-23.
//  Copyright © 2015 Martin Norberg. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int recursive(const int& index, const vector<int>& my_array) {
    vector<int> v;
    int max_jumps = 0;

    if (index > 0)
    {
        if (my_array.at(index-1) < my_array.at(index))
            v.push_back(index-1);
        if (index > 1 && my_array.at(index-2) < my_array.at(index))
            v.push_back(index-2);
    }
    if (index < my_array.size()-1)
    {
        if (my_array.at(index+1) < my_array.at(index))
            v.push_back(index+1);
        if (index < my_array.size()-2 && my_array.at(index+2) < my_array.at(index))
            v.push_back(index+2);
    }
    
    if (v.size() > 0)
    {
        ++max_jumps;
        for (int index : v)
        {
            int jumps = recursive(index, my_array);
            if (jumps >= max_jumps)
                max_jumps = jumps+1;
        }
    }
    
    return max_jumps;
}


int main() {
    
    vector<int> my_array = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    int max_jumps = 0;
    
    for (int index=0; index<my_array.size(); ++index)
        max_jumps = recursive(index, my_array);
    
    cout << "Max jumps: " << max_jumps << endl;
    
    return 0;
}
