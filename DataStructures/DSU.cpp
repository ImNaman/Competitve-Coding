#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int size[MAXN],Arr[MAXN];

void initialize( int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}

int root(int i)
{
    while(Arr[ i ] != i)          
    {
        i = Arr[ i ];
    }
    return i;
}


bool find(int A,int B)
{
    if( root(A)==root(B) )       
    return true;
    else
    return false;
}

void weightedunion(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}

int main()
{

}