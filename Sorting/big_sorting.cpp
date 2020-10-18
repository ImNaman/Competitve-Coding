//https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.
bool check(string a, string b){
    return a.length() == b.length() ? a > b : a.length() > b.length();
}
      
int main(){
    int n;
    cin >>n;
    vector<string> unsorted;
    for(int i;i<n;i++){
        string num;
        cin >>num;
        unsorted.push_back(num);
    }

  
    sort(unsorted.begin(),unsorted.end(),check);

    for(int i=n-1;i>=0;i--){
        cout <<unsorted[i]<<endl;
    }


    return 0;
}
