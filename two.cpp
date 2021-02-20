#include<bits/stdc++.h>
using namespace std;
list<pair<int,int>> ls;

void Addedge(int x,int y)
{
    ls.push_back(make_pair(x,y));
}
int findset(int i, int parent[])
{
    if(parent[i]==-1)
        return i;
	return findset(parent[i],parent);
}
void union_set(int x,int y,int parent[],int rank[])
{
    int s1 = findset(x,parent);
    int s2 = findset(y,parent);
    if(s1!=s2)
    {
        if(rank[s1]<rank[s2])                                                   //Union by rank
        {
            parent[s1]=s2;
            rank[s2]=rank[s2]+rank[s1];
        }
        else
        {
            parent[s2]=s1;
            rank[s1]=rank[s1]+rank[s2];        
        }
    }
}
bool contain_cycle(int v)
{
    int parent[v],rank[v];
    fill(parent,parent+v,-1);
    fill(rank,rank+v,1);
    for(auto edge: ls)
    {
        int i =edge.first;
        int j = edge.second;
        int s1 = findset(i,parent);
        int s2 = findset(j,parent);
        if(s1!=s2)
            union_set(s1,s2,parent,rank);
        else
        {
           // cout<<"Both belong to the same set "<<s1<<endl;
			return true;
        }
    }
    return false;
}
int main()
{
    int v=4;
    Addedge(0,1);
    Addedge(1,2);
    Addedge(2,3);
    Addedge(3,0);
    cout<<contain_cycle(4);
}