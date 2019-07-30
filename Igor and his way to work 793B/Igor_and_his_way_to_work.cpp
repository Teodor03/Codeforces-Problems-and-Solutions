#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct edge
{
    int x;
    int y;
    int direction;
    int price;

    bool operator <(edge other)const
    {
        return price>other.price;
    }
};

const int Max_N=1010,Max_M=1010;

//  3
//  |
//0-x-2
//  |
//  1

int shortest_paths [Max_M][Max_N][4];
// false if empty true if blocked
bool table [Max_M][Max_N];
int n,m,x_start,y_start,x_end,y_end;
char current;

priority_queue<edge> queuem;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d %d",&n,&m);
    for(int counter=0; counter<n; counter++)
    {
        scanf("\n");
        for(int counter_1=0; counter_1<m; counter_1++)
        {
            scanf("%c",&current);
            if(current=='.')
            {
                table[counter_1][counter]=false;
            }
            else
            {
                if(current=='*')
                {
                    table[counter_1][counter]=true;
                }
                else
                {
                    if(current=='S')
                    {
                        table[counter_1][counter]=false;
                        x_start=counter_1;
                        y_start=counter;
                    }
                    if(current=='T')
                    {
                        table[counter_1][counter]=false;
                        x_end=counter_1;
                        y_end=counter;
                    }
                }
            }
        }
    }
    for(int k=0; k<4; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                shortest_paths[j][i][k]=1000;
            }
        }
    }

    edge adding;
    if(x_start>0 and table[x_start-1][y_start]==false)
    {
        adding= {x_start-1,y_start,2,0};
        queuem.push(adding);
        shortest_paths[x_start-1][y_start][2]=0;
        //cout<<x_start-1<<" "<<y_start<<endl;
    }
    if(x_start<m-1 and table[x_start+1][y_start]==false)
    {
        adding= {x_start+1,y_start,0,0};
        queuem.push(adding);
        shortest_paths[x_start+1][y_start][0]=0;
        //cout<<x_start+1<<" "<<y_start<<endl;
    }
    if(y_start>0 and table[x_start][y_start-1]==false)
    {
        adding= {x_start,y_start-1,1,0};
        queuem.push(adding);
        shortest_paths[x_start][y_start-1][1]=0;
        //cout<<x_start<<" "<<y_start-1<<endl;
    }
    if(y_start<n-1 and table[x_start][y_start+1]==false)
    {
        adding= {x_start,y_start+1,3,0};
        queuem.push(adding);
        shortest_paths[x_start][y_start+1][3]=0;
        //cout<<x_start<<" "<<y_start+1<<endl;
    }
    edge curr;
    while(!queuem.empty())
    {
        curr=queuem.top();
        queuem.pop();
        //cout<<"Top: "<<curr.x<<" "<<curr.y<<" "<<curr.direction<<" "<<curr.price<<endl;
        if(curr.direction!=0 and curr.x>0 and table[curr.x-1][curr.y]==false)
        {
            if(curr.direction==2 and curr.price<shortest_paths[curr.x-1][curr.y][2])
            {
                adding= {curr.x-1,curr.y,2,curr.price};
                queuem.push(adding);
                shortest_paths[curr.x-1][curr.y][2]=curr.price;
                //cout<<"Adding: "<<curr.x-1<<" "<<curr.y<<" "<<curr.price<<endl;
            }
            else if(curr.price<2 and curr.price+1<shortest_paths[curr.x-1][curr.y][2])
            {
                adding= {curr.x-1,curr.y,2,curr.price+1};
                queuem.push(adding);
                shortest_paths[curr.x-1][curr.y][2]=curr.price+1;
                //cout<<"Adding: "<<curr.x-1<<" "<<curr.y<<" "<<curr.price+1<<endl;
            }
        }
        if(curr.direction!=2 and curr.x<m-1 and table[curr.x+1][curr.y]==false)
        {
            if(curr.direction==0 and curr.price<shortest_paths[curr.x+1][curr.y][0])
            {
                adding= {curr.x+1,curr.y,0,curr.price};
                queuem.push(adding);
                shortest_paths[curr.x+1][curr.y][0]=curr.price;
                //cout<<"Adding: "<<curr.x+1<<" "<<curr.y<<" "<<curr.price<<endl;
            }
            else if(curr.price<2 and curr.price+1<shortest_paths[curr.x+1][curr.y][0])
            {
                adding= {curr.x+1,curr.y,0,curr.price+1};
                queuem.push(adding);
                shortest_paths[curr.x+1][curr.y][0]=curr.price+1;
                //cout<<"Adding: "<<curr.x+1<<" "<<curr.y<<" "<<curr.price+1<<endl;
            }
        }
        if(curr.direction!=3 and curr.y>0 and table[curr.x][curr.y-1]==false)
        {
            if(curr.direction==1 and curr.price<shortest_paths[curr.x][curr.y-1][1])
            {
                adding= {curr.x,curr.y-1,1,curr.price};
                queuem.push(adding);
                shortest_paths[curr.x][curr.y-1][1]=curr.price;
                //cout<<"Adding: "<<curr.x<<" "<<curr.y-1<<" "<<curr.price<<endl;
            }
            else if(curr.price<2 and curr.price+1<shortest_paths[curr.x][curr.y-1][1])
            {
                adding= {curr.x,curr.y-1,1,curr.price+1};
                queuem.push(adding);
                shortest_paths[curr.x][curr.y-1][1]=curr.price+1;
                //cout<<"Adding: "<<curr.x<<" "<<curr.y-1<<" "<<curr.price+1<<endl;
            }
        }
        if(curr.direction!=1 and curr.y<n-1 and table[curr.x][curr.y+1]==false)
        {
            if(curr.direction==3 and curr.price<shortest_paths[curr.x][curr.y+1][3])
            {
                adding= {curr.x,curr.y+1,3,curr.price};
                queuem.push(adding);
                shortest_paths[curr.x][curr.y+1][3]=curr.price;
                //cout<<"Adding: "<<curr.x<<" "<<curr.y+1<<" "<<curr.price<<endl;
            }
            else if(curr.price<2 and curr.price+1<shortest_paths[curr.x][curr.y+1][3])
            {
                adding= {curr.x,curr.y+1,3,curr.price+1};
                queuem.push(adding);
                shortest_paths[curr.x][curr.y+1][3]=curr.price+1;
                //cout<<"Adding: "<<curr.x<<" "<<curr.y+1<<" "<<curr.price+1<<endl;
            }
        }
    }
//    for(int k=0; k<4; k++)
//    {
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//            {
//                cout<<shortest_paths[j][i][k];
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
//    for(int y_z=0;y_z<n;y_z++){
//        for(int x_z=0;x_z<n;x_z++){
//            cout<<table[x_z][y_z];
//        }
//        cout<<endl;
//    }
    if(shortest_paths[x_end][y_end][0]<3 or shortest_paths[x_end][y_end][1]<3 or shortest_paths[x_end][y_end][2]<3 or shortest_paths[x_end][y_end][3]<3){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
