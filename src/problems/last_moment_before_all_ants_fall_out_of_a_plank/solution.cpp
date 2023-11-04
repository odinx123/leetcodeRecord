class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_dis = 0;
        for (const int& i : left)
            max_dis = max(max_dis, i);
        for (const int& i : right)
            max_dis = max(max_dis, n-i);

        return max_dis;
    }
};