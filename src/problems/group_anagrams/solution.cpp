class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        
        for (const auto &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (hash.find(temp) == hash.end()) {
                hash[temp] = {s};
            } else {
                hash[temp].push_back(s);
            }
        }
        
        for (const auto &d : hash)
            ans.push_back(d.second);
        
        return ans;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};