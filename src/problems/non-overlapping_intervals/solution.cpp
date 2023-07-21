class Solution {
public:
    // 移除最少組達到不重疊
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // For each interval at index i, it checks if the start time of the current interval (intervals[i][0]) is greater than or equal to the end time of the previous interval (intervals[prev][1]).
        // 在start<end的情況下，依照end排序最多是兩個end相等，而這個情況下一定有重複
        // ex: [[1,3],[3,4],[1,2],[2,3]] -> [[1,2],[1,3],[2,3],[3,4]]
        // 上面的[1,3]不要選[1,2]是因為要刪除最少，所以選小的比較不會出現重疊
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        int cnt = 0, prev = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[prev][1])  // 符合條件可以更新沒有重疊的最後一個
                prev = i;
            else // 有重疊
                ++cnt;
        }

        return cnt;
    }
};