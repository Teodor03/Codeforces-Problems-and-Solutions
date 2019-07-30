#include<bits/stdc++.h>
using namespace std;

const int Max_N=300001;
int n,k,result;
int _array [Max_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int counter=0;counter<n;counter++){
        cin>>_array [counter];
    }
    result=_array[n-1]-_array[0];
    for(int counter=0;counter<n;counter++){
        _array[counter]=_array[counter+1]-_array[counter];
    }
    std::sort(_array,_array+n);
    for(int counter=0;counter<k-1;counter++){
        result-=_array[n-1-counter];
    }
    cout<<result;
return 0;
}
