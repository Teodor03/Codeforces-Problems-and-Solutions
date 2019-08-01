#include<iostream>
using namespace std;

const int Max_M=1001;
int useless_roads [Max_M][2];
int added_limit=0;

struct dsu_object{
int parent;
int depth;
};

const int Max_Number_of_Objects=1001;

dsu_object dsu_objects [Max_Number_of_Objects];

void dsu_initialise(int n){
    for(int counter=0;counter<n;counter++){
        dsu_objects[counter].depth=0;
        dsu_objects[counter].parent=counter;
    }
}

int dsu_find(int searched){
if(searched!=dsu_objects[searched].parent){
    dsu_objects[searched].parent=dsu_find(dsu_objects[searched].parent);
}
return dsu_objects[searched].parent;
}

void dsu_union(int first,int second){
int first_parent,second_parent;
first_parent=dsu_find(first);
second_parent=dsu_find(second);
if(first_parent==second_parent){
    useless_roads[added_limit][0]=first;
    useless_roads[added_limit][1]=second;
    added_limit++;
    return;
}
if(dsu_objects[first_parent].depth>dsu_objects[second_parent].depth){
    dsu_objects[second_parent].parent=first_parent;
    return;
}
if(dsu_objects[first_parent].depth<dsu_objects[second_parent].depth){
    dsu_objects[first_parent].parent=second_parent;
    return;
}
dsu_objects[second_parent].parent=first_parent;
dsu_objects[first_parent].depth++;
return;
}

int n,m;

int main(){
ios_base::sync_with_stdio(false);
cin>>n;
dsu_initialise(n);
int a,b;
for(int counter=0;counter<n-1;counter++){
        cin>>a>>b;
        a--;
        b--;
        dsu_union(a,b);
}
int f_parent,s_parent;
int counter_useless_roads=0;
cout<<added_limit<<endl;
for(int counter=1;counter<n;counter++){
    f_parent=dsu_find(0);
    s_parent=dsu_find(counter);
    if(f_parent!=s_parent){
        dsu_union(0,counter);
        cout<<useless_roads[counter_useless_roads][0]+1<<" "<<useless_roads[counter_useless_roads][1]+1<<" 1 "<<counter+1<<endl;
        counter_useless_roads++;
    }
}
return 0;
}
