class RecentCounter {
public:
    queue<int>pings;
    vector<int>pin;
    int j=0;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int x=t-3000;
        pings.push(t);
        pin.push_back(t);
        
        int ct=0;
        for(int i=pin.size()-1;i>=j;i--)
        {
            if(pin[i]>=x && pin[i]<=t)
            {
                ct++;
            }
            else
            {
                pings.pop();
                j++;
            }
        }
        return ct;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */