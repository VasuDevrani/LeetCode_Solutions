class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int j=i;
            int num=0;
            while(j>0)
            {
                j=(j&(j-1));
                num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};