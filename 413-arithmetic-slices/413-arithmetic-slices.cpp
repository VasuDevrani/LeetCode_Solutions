class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        
        if(n < 3)
            return 0;
        
        int l = 1, ct = 0, prev = arr[1] - arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(arr[i] - arr[i-1] == prev)
                l++;
            else{
                prev = arr[i] - arr[i-1];
                l = 2;
            }
            
            if(l == 3)
                ct++;
            else if(l > 3)
                ct += (l - 2);
        }
        
        return ct;
    }
};