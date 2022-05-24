class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cr=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            digits[i]+=cr;
            if(digits[i]<10)
            {
                cr=0;
                break;
            }
            else
            {
                int temp=digits[i]/10;
                digits[i]=digits[i]%10;
                cr=temp;
            }
        }
        if(cr!=0)
        {
            vector<int>ans;
            ans.push_back(cr);
            for(int i=0;i<digits.size();i++)
                ans.push_back(digits[i]);
            
            return ans;
        }
        return digits;
    }
};