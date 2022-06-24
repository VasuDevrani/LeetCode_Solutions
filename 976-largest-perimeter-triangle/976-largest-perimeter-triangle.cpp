class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int i = n-1, j = n-1, sum = 0;
        
        while(j >= 0)
        {
            sum += arr[j];
            if(j <= n-3)
            {
                if(arr[j] + arr[j+1] > arr[i])
                {
                    return sum;
                }
                sum -= arr[i];
                i--;
            }
            j--;
        }
        return 0;
    }
};