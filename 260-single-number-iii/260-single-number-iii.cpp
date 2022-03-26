class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0,bit=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        
//         finding bit of 1 in ans;
        int n=ans;
        while(n!=0)
        {
            if((int)(n&1)==1)
            break;
            bit++;
            n=n>>1;
        }
       
        
//         creating mask;
        int mask=1<<bit;
//         finding the first non repeated number by taking xor of those arr elements whose bit's bit is 1
        
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask)!=0)
              a=a^nums[i];  
        }
        
//         finally finding the second non repeated digit
        int b=a^ans;
        
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        return v;
        
    }
};