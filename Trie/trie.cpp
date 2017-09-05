// Naman Shukla
// Trie template

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node
{
	unordered_map<char,node* >a; // To store addresses of child nodes
	int end; // A var to store the number of strings which end on this node

	node()  // constructor
	{
		end=0;
	}
	void insert(node* p , string str, int cur, int str_len);  // Function to insert all this strings into the trie
	int search(string str);   // Function to query a string
};

void node::insert(node* p , string str, int cur, int str_len)
{
	if(cur==str_len)
	{
		p->end+=1;return;
	}

	char ch = str[cur];
	
	if (p->a[ch] == NULL)
    {
        p->a[ch] = new node();
    }
	insert(p->a[ch], str , cur+1,str_len);

}

int node::search(string str)
{	
	node *p = this;
	for(ll i=0;i<str.length();i++)
	{
		if(p==NULL)
			return 0;
		p = p->a[str[i]];
	}
	return p->end;
}	

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	return 0;
}