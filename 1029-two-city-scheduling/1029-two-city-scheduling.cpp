class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        vector<pair<int,int>>arr(n);
        
        for(int i=0;i<n;i++)
            arr[i] = make_pair(abs(costs[i][1] - costs[i][0]), i);
        
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        int a = 0, b = 0, sum = 0;
        
        for(int i=0;i<n/2;i++)
        {
            int ind = arr[i].second;
            if(costs[ind][0] > costs[ind][1])
            {
                b++;
                sum += costs[ind][1];
            }
            else
            {
                a++;
                sum += costs[ind][0];
            }
        }
        
        for(int i=n/2;i<n;i++)
        {
            int ind = arr[i].second;
            if(costs[ind][0] > costs[ind][1])
            {
                if(b != n/2){
                    b++;
                    sum += costs[ind][1];
                }
                else
                {
                    a++;
                    sum += costs[ind][0];
                }
            }
            else
            {
                if(a != n/2){
                    a++;
                    sum += costs[ind][0];
                }
                else
                {
                    b++;
                    sum += costs[ind][1];
                }
            }
        }
        
        return sum;
    }
};