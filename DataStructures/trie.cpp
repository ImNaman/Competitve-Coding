// Naman Shukla

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

truct node
{
    bool leaf;
    unordered_map<char, node*> chd; 
    
    node() : leaf(false) { }
};

node *root;

void insert(node* x, string s, int pos)
{
    if (pos == s.length()) x -> leaf = true;
    else
    {
        char cur = s[pos];
        if (x -> chd[cur] == NULL)
        {
            x -> chd[cur] = new node();
        }
        insert(x -> chd[cur], s, pos + 1);
    }
}

bool find(node* x, string s, int pos)
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