class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        vector<long long>ans;
        
        if(finalSum % 2 != 0)
            return ans;
        
        long long i = 1, sum = 0;
        while((sum+i*2) <= finalSum)
        {
            sum += i*2;
            ans.push_back(i*2);
            i++;
        }
        
        if(sum == finalSum)
            return ans;
        else
        {
            ans[ans.size()-1] = ans[ans.size()-1] + finalSum - sum;
            
            return ans;
        }
        
        return ans;
    }
};