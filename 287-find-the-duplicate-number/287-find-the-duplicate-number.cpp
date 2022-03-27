class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>v;
        v=nums;
        int ans;
        sort(v.begin(),v.end());
        int i=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if((v[i]^v[i+1])==0)
            { ans=v[i];
             break;}
        }
        return ans;
    }
};