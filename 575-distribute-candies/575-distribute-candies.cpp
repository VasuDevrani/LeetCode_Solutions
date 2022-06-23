class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>s;
        
        for(int i=0;i<candyType.size();i++)
            s.insert(candyType[i]);
        
        int half = candyType.size()/2;
        
        if(half < s.size())
            return half;
        else
            return s.size();
    }
};