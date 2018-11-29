#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int a[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10],x,y;

main()
{
cout <<"enter no. of vertices SIR/MAM!";
cin >> n;
cout<<"sir please enter for undirected grah"<<endl;
     cin>>x>>y;
    if(x>=n&&y>=n)
        cout<<"sir ji please enter within range"<<endl;
        else
        {
    while(x!=-1&&y!=-1)
    {
        a[x][y]=1;
        a[y][x]=1;
        cin>>x>>y;

    }
    }
cout <<"enter initial vertex";
cin >>v;
cout <<"AFTER DFS ,SIR ORDER COMES -:"<<endl;
cout << v <<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=n;j>=1;j--)
if(a[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
stk[top]=j;
top++;
}
v=stk[--top];
cout<<v << " ";
k++;
visit[v]=0; visited[v]=1;
}
}
