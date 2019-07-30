#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

const int Max=1010;

int n,m,s_starting,t;
int special,number_of_valid=0;

vector<int> graph [Max];
int prices [Max][Max];
bool roads [Max][Max];

void bfs(int s){
queue< pair<int,int> > queuem;
queuem.push({s,0});
int current_price,current_index;
while(!queuem.empty()){
    current_index=queuem.front().first;
    current_price=queuem.front().second;
    queuem.pop();
    for(int counter=0;counter<graph[current_index].size();counter++){
        if(prices [s][graph[current_index][counter]]==0 and graph[current_index][counter]!=s){
            prices [s][graph[current_index][counter]]=current_price+1;
            queuem.push({graph[current_index][counter],current_price+1});
        }
    }
}
return;
}

int main(){
ios_base::sync_with_stdio(false);
cin>>n>>m>>s_starting>>t;
s_starting--;
t--;
int a,b;
for(int counter=0;counter<m;counter++){
    cin>>a>>b;
    a--;
    b--;
    graph [a].push_back(b);
    graph [b].push_back(a);
    roads [a][b]=true;
    roads [b][a]=true;

}
for(int counter=0;counter<n;counter++){
bfs(counter);
}
special=prices[s_starting][t];
for(int counter=0;counter<n;counter++){
    for(int counter_1=counter+1;counter_1<n;counter_1++){
        if(prices [s_starting][counter]+1+prices [counter_1][t]>=special and roads[counter][counter_1]==false){
            number_of_valid++;
        }
    }
}
cout<<number_of_valid;
return 0;
}
