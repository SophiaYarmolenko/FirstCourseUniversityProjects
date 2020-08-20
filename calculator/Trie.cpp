//
// Created by Sophia on 30.05.2020.
//

#include "Trie.h"
Trie::Trie()
{
    head = new TrieNode();
}

Trie::~Trie()
{
    delete head;
}

bool Trie::isExists(const string s)
{
    TrieNode* curr = head;
    for(int i=0; i<s.size(); ++i) {
        int letIdx = s[i]-'a';
        if(curr->sons[letIdx] == NULL) {
            return false;
        }
        curr = curr->sons[letIdx];
    }
    return curr->isEndOfStr;
}

void Trie::addCommand(const string& s, void (&f)())
{
    if(isExists(s))
        return;
    TrieNode* curr = head;
    for(int i=0; i<s.size(); ++i) {
        int letIdx = s[i]-'a';
        if(curr->sons[letIdx] == NULL) {
            curr->sons[letIdx] = new TrieNode();
        }
        ++curr->strsInBranch;
        curr = curr->sons[letIdx];
    }
    ++curr->strsInBranch;
    curr->isEndOfStr = true;
    curr->fcnPtr = f;
}

void Trie::removeString(const string& s)
{
    if(!isExists(s))
        return;
    TrieNode* curr = head;
    for(int i=0; i<s.size(); ++i)
    {
        int letIdx = s[i]-'a';
        if(curr->sons[letIdx] == NULL)
        {
            assert(false);
            return; //string not exists, will not reach here
        }
        if(curr->strsInBranch==1) {    //just 1 str that we want remove, remove the whole branch
            delete curr;
            return;
        }
        //more than 1 son
        --curr->strsInBranch;
        curr = curr->sons[letIdx];
    }
    curr->isEndOfStr = false;
}

void Trie::clear()
{
    for(int i=0; i<26; ++i) {
        delete head->sons[i];
        head->sons[i] = NULL;
    }
}

void Trie::DoFunction(const string &s)
{
    if(!isExists(s))
    {
        cout<<"There are no such command. Please check your spelling\n";
        return;
    }
    TrieNode* curr = head;
    for(int i=0; i<s.size(); ++i) {
        int letIdx = s[i]-'a';
        curr = curr->sons[letIdx];
    }
    void (*fcnPtr1)();
    fcnPtr1 = (*curr).fcnPtr;
    (*fcnPtr1)();
}