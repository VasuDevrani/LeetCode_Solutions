class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dis=0;
        
        for(int i=0;i<colors.size();i++)
        {
            for(int j=0;j<colors.size();j++)
            {
                if(colors[i] != colors[j]){
                    int x = abs(j - i);
                    if(x>dis)
                        dis = x;
                }
            }
        }
        
        return dis;
    }
};