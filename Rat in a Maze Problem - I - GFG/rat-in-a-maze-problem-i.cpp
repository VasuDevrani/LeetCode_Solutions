// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:

    void paths(vector<vector<int>>&maze,int i,int j,int n,vector<string>&ans,string s,vector<vector<bool>>&v)
    {
        // base case
        if(i==n-1 && j==n-1 && maze[i][j]!=0)
            {
                ans.push_back(s);
                return;
            } 
        if(i<0 || j<0 || i>n-1 || j>n-1 || maze[i][j]==0 || v[i][j]==true)
        return;
            
        
        // recursive case
       
          v[i][j]=true;
          paths(maze,i-1,j,n,ans,s+'U',v);
          v[i][j]=false;
        
         
          v[i][j]=true;
          paths(maze,i+1,j,n,ans,s+'D',v);
          v[i][j]=false;
          
          
     
          v[i][j]=true;
          paths(maze,i,j-1,n,ans,s+'L',v);
          v[i][j]=false;
          
          
         
          v[i][j]=true;
          paths(maze,i,j+1,n,ans,s+'R',v);
          v[i][j]=false;
          
          
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>ans;
        vector<vector<bool>>v(n,vector<bool>(n,false));
        
        paths(m,0,0,n,ans,"",v);
        
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends