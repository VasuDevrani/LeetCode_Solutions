class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int num = (-1 + sqrt(1 + 8 * grades.size()))/2;
        
        return floor(num);
    }
};