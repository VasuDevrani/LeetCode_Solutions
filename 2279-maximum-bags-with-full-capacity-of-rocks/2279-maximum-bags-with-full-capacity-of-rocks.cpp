class Solution {
public:
    int maximumBags(vector<int>& cp, vector<int>& rocks, int ar) {
        priority_queue<int,vector<int>,greater<int>>q; //minHeap
        int ct = 0;
        
        for(int i=0;i<rocks.size();i++)
        {
            if(cp[i] == rocks[i])
                ct++;
            
            if(cp[i] - rocks[i] != 0)
                q.push(cp[i] - rocks[i]);
        }
        
        while(!q.empty() && ar > 0)
        {
            cout<<q.top()<<" ";
            ar = ar - q.top();
            q.pop();
            if(ar >= 0)
            ct++;
        }
        
        return ct;
    }
};