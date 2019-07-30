#include<iostream>
using namespace std;

const int Max=1010;

int n,k,current;
int current_used=0;

int requests [Max];
int students;

int main(){
ios_base::sync_with_stdio(false);
cin>>n>>k;
for(int counter=0;counter<n;counter++){
    cin>>current;
    current--;
    requests [current]++;
}
for(int counter=0;counter<k;counter++){
    current_used+=requests [counter]/2;
}
students=current_used*2;
if(n%2==0){
    students+=n/2-current_used;
}else{
    students+=n/2+1-current_used;
}
cout<<students;
return 0;
}
