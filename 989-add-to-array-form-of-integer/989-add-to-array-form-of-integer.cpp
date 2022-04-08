class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
//          separate the digits of k and add to num from end
        int j=num.size()-1;
        while(k!=0 && j>=0)
        {
            num[j]+=(k%10);
            k/=10;
            j--;
        }
        if(k!=0)
        {
            reverse(num.begin(),num.end());
            while(k!=0)
        {
            num.push_back(k%10);
            k/=10;
        }
            reverse(num.begin(),num.end());
        }
        
        
//         traverse from end and fill in a new vector 
//         look for number greater than 9, if it is, separate its digits keep last digit and push next forward
        
        vector<int>ans;
        int ct=0;
        for(int i=num.size()-1;i>=0;i--)
        {
            if(num[i]+ct<=9){
                ans.push_back(num[i]+ct);
                ct=0;
                }
            else 
            {
                int n=num[i]+ct;
                while(n>9)
                {
                    ans.push_back(n%10);
                    n/=10;
                }
                ct=n;
            }
        }
        if(ct!=0)
            ans.push_back(ct);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    
//         Even after being correct and O(n) below code gives overflow problem
        
//         long long int m=1;
//         long long int pre_int=0;
//         for(int i=num.size()-1;i>=0;i--)
//         {
//             pre_int+=(m*num[i]);
//             m*=10;
//         }
        
//         long long int final=pre_int+k;
        
//         vector<int>ans;
//         while(final!=0)
//         {
//           ans.push_back(final%10);
//             final/=10;
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
        
    }
};