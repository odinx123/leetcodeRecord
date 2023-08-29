
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        /*
        分析: [c,d]、[a,b]根據c跟a進行排序inc，變成[a,b]、[c,d]
        那麼b > a，c >= a，d > [a,b,c]->c跟b不知誰大

        如果根據b,d進行排序，變成[a,b]、[c,d]
        那麼b > a，d >= b，且c必定<d，所以若b,d相等c < b

        結論: 如果使用right排序，那麼我只要比較前一個right跟當前left就好，排序確定right>=prevRight
            但是如果使用left排序，那麼比較left跟前個right無法知道當前right是否大於prevRight.
        */

        sort(pairs.begin(), pairs.end(), [] (const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int prev = pairs[0][1], ans = 1;
        // 紀錄前一個pair的位置，這樣如果條件不允許，將cur往下移動，直到條件允許換到cur位置
        // 中間沒用的跳過(如果經過的curL都小於prevR，那代表經過的curL必定小於他們的前一個R->有排序過)
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > prev) {
                ++ans;
                prev = pairs[i][1];  // prev往下移動
            }
        }

        return ans;
    }
};