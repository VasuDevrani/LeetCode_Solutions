class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++)
            sum+=arr[i];
        
        if(sum%3 != 0)
            return false;
        else
        {
            sum = sum/3;
            int temp = 0, ct = 0;
            for(int i=0;i<arr.size();i++)
            {
                temp += arr[i];
                if(temp == sum){
                    temp = 0;
                    ct++;
                }
            }
            if(ct >= 3)
                return true;
            else
                return false;
        }
    }
};