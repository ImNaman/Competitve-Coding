#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v,int n){
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i]<v[j]){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}

int main() {
	
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int num;
	    cin>>num;
	    arr.push_back(num);
	}
	bubbleSort(arr,n);
		for(int i=0;i<n;i++){
		    cout<<arr[i]<<" ";
		}
	
	return 0;
}
