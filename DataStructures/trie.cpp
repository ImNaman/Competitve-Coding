#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

truct TrieNode
{
    bool leaf;
    unordered_map<char, TrieNode*> chd; 
    
    TrieNode() : leaf(false) { }
};

TrieNode *root;

void insert(TrieNode* x, string s, int pos)
{
    if (pos == s.length()) x -> leaf = true;
    else
    {
        char cur = s[pos];
        if (x -> chd[cur] == NULL)
        {
            x -> chd[cur] = new TrieNode();
        }
        insert(x -> chd[cur], s, pos + 1);
    }
}

bool find(TrieNode* x, string s, int pos)
{
    if (pos == s.length()) return (x -> leaf);
    if (x -> chd[s[pos]] == NULL) return false;
    return find(x -> chd[s[pos]], s, pos+1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	return 0;
}