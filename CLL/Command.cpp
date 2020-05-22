//
// Created by Sophia on 21.05.2020.
//

#include "Command.h"
Command::Command()
{
    //add trie elements
    add("help");
    add("quit");
    add("log on");
    add("exit");
    add("save");
    add("load");
    add("log file");
    add("list");
    add("log Off");
    add("log Append");
    add("log New");
    add("log clear history");
}

void Command::add(const string& s)
{
    node *cur_v = root;
    Function function = functions[numberFunction];
    numberFunction++;

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
