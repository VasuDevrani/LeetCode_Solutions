class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ct = 0;
        int j = 1;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] != j)
            {
                ct++;
                if(ct == k)
                    return j;
                i--;
            }
            j++;
        }
        if(ct != k)
            return j+k-ct-1;
        return 0;
    }
};