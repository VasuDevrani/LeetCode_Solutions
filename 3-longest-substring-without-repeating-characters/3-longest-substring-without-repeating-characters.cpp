class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		int ans = 0;
		int i = 0, j = -1;
        unordered_map<char, int> ct;


		while (i < n && j < n - 1) {
			ct[s[++j]]++;
			while (i < j && ct[s[j]] == 2) {
				ct[s[i++]]--;
			}

			ans = max(ans, j - i + 1);
		}

		return ans;
	}
};