class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int longest = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int tempSize = 1;
            while (i < nums.size()) {
                if (nums.at(i)-1 == nums.at(i-1))
                    ++tempSize;
                else if (nums.at(i) != nums.at(i-1))
                    break;
                ++i;
            }
            
            longest = max(longest, tempSize);
        }
        
        return min(longest, int(nums.size()));
    }
};