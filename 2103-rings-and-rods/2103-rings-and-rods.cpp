class Solution {
public:
    int countPoints(string rings) {
        map<char,set<char>> m;
        for(int i = 1 ; i < rings.size() ; i += 2){
            m[rings[i]].insert(rings[i-1]);
        }
        int ct = 0;
        for(auto it : m)
        {
            if(it.second.size() == 3) 
            ct++;
        }
        
        return ct;
    }
};