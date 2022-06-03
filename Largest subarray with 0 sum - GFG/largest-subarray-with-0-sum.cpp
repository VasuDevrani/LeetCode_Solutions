// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int preSum=0;
        unordered_map<int,int>m;
        int max=0;
        
        for(int i=0;i<A.size();i++)
        {
            preSum=preSum+A[i];
            if(preSum == 0)
            {
                int l = i+1;
                if(max<l)
                max=l;
            }
            if(m.find(preSum)!=m.end())
            {
                auto it=m.find(preSum);
                int l=i-(*it).second; 
                if(l>max)
                max=l;
            }
            if(m.find(preSum)==m.end())
            m[preSum] = i;
        }
        
        return max;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends