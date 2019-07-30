#include<iostream>
using namespace std;

long long n,k;
long long sum=1;
long long adding=1;
long long number_of_addings=1;

int main (){
cin>>n>>k;
while(number_of_addings<=n){
    if((sum-k==n-number_of_addings) or (k-sum==n-number_of_addings)){
    cout<<n-number_of_addings;
    return 0;
    }
    adding++;
    sum+=adding;
    number_of_addings++;
}
return 0;
}
