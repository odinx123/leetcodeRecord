class Solution {
public:
    string reverseWords(string s) {
        ss.clear();
        ss.str(s);

        string ans;
        while (!ss.eof()) {
            string temp;
            ss >> temp;
            reverse(temp.begin(), temp.end());
            ans += temp + " ";
        }
        ans.pop_back();

        return ans;
    }
private:
    stringstream ss;
};