// Naman Shukla
// Trie template

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node
{
public:
	char ch;  // to denote the character this node denotes
	node* a[26]; // To store addresses of next 26 nodes
	int end; // A var to store the number of strings which end on this node

	node()  // constructor
	{
		for(ll i=0;i<26;i++)
			a[i] = NULL;
		end=0;
	}
	void insert(string str);  // Function to insert all this strings into the trie
	int search(string str);   // Function to query a string
};

void node::insert(string str)
{
	node *p = this;
	node *q = p;
	ll ptr=0,strlen=str.length();

	if(p->a[str[ptr]-'a'] != NULL)
	while(p!=NULL && ptr<strlen)
	{
		q = p;
		p = p->a[str[ptr]-'a'];
		ptr+=1;
	}
	
	if(ptr==strlen)
	{	(p->end)+=1;	return;	}

	for(ll i=ptr;i<strlen;i++)
	{
		node *nw = new node();
		nw->ch = str[i];

		if(i==strlen-1)
			(nw->end)+=1;

		q->a[str[i]-'a'] = nw;
		q = q->a[str[i]-'a'];
	}
}
	
int node::search(string str)
{	
	node *p = this;
	for(ll i=0;i<str.length();i++)
	{
		if(p==NULL)
			return 0;
		p = p->a[str[i]-'a'];
	}
	return p->end;
}	

int main()
{
	node *root = new node();
	// cout<<"Enter the number of Strings and the number of queries you wanna perform\n";
	int n,q;cin>>n>>q;

	string s[n];
	// cout<<"Enter the input strings\n";
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
		root->insert(s[i]);
	}
	//cout<<"Enter the query strings\n";
	while(q--)
	{
		string str;cin>>str;
		cout<<root->search(str)<<"\n";
	}

	return 0;
}