#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool isSafe(int i,int j,int row,int col,vector<vector<int>>&arr,vector<vector<bool>>&visited)
{
    if((i>=0 && i<row) && (j>=0 && j<col) && (arr[i][j]==1) && (visited[i][j]==false))
    {
        return true;
    }
    return false;
}

void solveMaze(vector<vector<int>>&arr,int row,int col,int i,int j,vector<vector<bool>>& visited,vector<string>& path,string output)
{
    if(i==row-1 && j==col-1)
    {
        path.push_back(output);
        return;
    }

    //down i+1,j
    if(isSafe(i+1,j,row,col,arr,visited))
    {
        visited[i+1][j]=true;
        solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
        //backtrack
        visited[i+1][j]=false;
    }

    //left i,j-1
    if(isSafe(i,j-1,row,col,arr,visited))
    {
        visited[i][j-1]=true;
        solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
        //backtrack
        visited[i][j-1]=false;
    }

    //right i,j+1
    if(isSafe(i,j+1,row,col,arr,visited))
    {
        visited[i][j+1]=true;
        solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
        //backtrack
        visited[i][j+1]=false;
    }
    //up i-1,j
    if(isSafe(i-1,j,row,col,arr,visited))
    {
        visited[i-1][j]=true;
        solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
        //backtrack
        visited[i-1][j]=false;
    }
}

int main()
{
    vector<vector<int>>arr={{1,0,0,0},
                            {1,1,0,1},
                            {1,1,0,1},
                            {0,1,1,1}};

    // vector<vector<int>>arr={{1,1},
    //                         {1,1}};
    
    //edge case
    if(arr[0][0]==0)
    {
        cout<<"No Path exists"<<endl;
        return 0;
    }
    int row=arr.size();
    int col=arr[0].size();
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    visited[0][0]=true;
    vector<string>path;
    string output="";
    solveMaze(arr,row,col,0,0,visited,path,output);
    for(auto it:path)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    if(path.size()==0)
    {
        cout<<"No Path exists"<<endl;
    }
    return 0;
}   