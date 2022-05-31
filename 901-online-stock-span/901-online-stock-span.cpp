class StockSpanner {
public:
    stack<pair<int,int>>s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.size()==0){
            s.push(make_pair(price,1));
            return 1;
        }
        if(price<s.top().first){
            s.push(make_pair(price,1));
            return 1;
        }
        else
        {
            int ct=1;
            // cout<<s.top()<<" "<<price<<" ";
            while(!s.empty() && s.top().first<=price)
            {
                ct+=s.top().second;
                s.pop();
            }
            s.push(make_pair(price,ct));
            return ct;
        }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */