//
// Created by Sophia on 21.05.2020.
//

#include "Command.h"
Command::Command()
{

}

void Command::add(const string& s)
{
    node *cur_v = root;
    cur_v->vfunc.push_back(func);

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ( cur_v->next[c - 'a'] == nullptr )
        {
            cur_v->next[c - 'a'] = new node();
        }

        cur_v = cur_v->next[c - 'a'];
    }

    cur_v->strings++;
}

bool Command::has(const string& s)
{
    node *cur_v = root;

    for (int i = 0; i < s.length(); i++)
    {
        cur_v = cur_v->next[s[i] - 'a'];
        if (cur_v == nullptr)
        {
            return false;
        }
    }

    return cur_v->strings > 0;
}