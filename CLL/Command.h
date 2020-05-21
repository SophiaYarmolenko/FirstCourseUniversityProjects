//
// Created by Sophia on 21.05.2020.
//

#ifndef CLL_COMMAND_H
#define CLL_COMMAND_H

#include <string>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Command
{
public:
    Command();
    void virtual func();

    struct node
    {
        node *next[26];
        vector< function <void()> > vfunc;
        int strings;

        node()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }

            strings = 0;
        }
    };
    node *root = new node();
    void add(const string& s);

    bool has(const string& s);
};


#endif //CLL_COMMAND_H
