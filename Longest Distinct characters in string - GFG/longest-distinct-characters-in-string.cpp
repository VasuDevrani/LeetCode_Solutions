// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int i = 0, j = 0, ans = 0;
    unordered_map<char,int>m;
    
    while(j < s.length())
    {
        if(m.find(s[j]) != m.end())
        ans = max(ans, j-i);
        
        while(m.find(s[j]) != m.end())
        {
            m[s[i]]--;
            
            if(m[s[i]] == 0)
            m.erase(s[i]);
            
            i++;
        }
        m[s[j]]++;
        j++;
    }
    ans = max(ans, j-i);
    return ans;
}