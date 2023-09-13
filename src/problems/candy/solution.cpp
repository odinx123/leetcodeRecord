class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr(ratings.size(), 1);
        
        // 對左邊的child來說，右邊分數比較高的糖果都比他多。
        for (int i = 0; i < ratings.size()-1; ++i) {
            if (ratings[i+1] > ratings[i]) {
                // 題目只有提到說分數比較高糖果要比較多，沒有說相同分數相同糖果
                arr[i+1] = arr[i] + 1;
            }
        }

        int cnt = arr.back();

        // 換成對右邊的child來說
        for (int i = arr.size()-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                // 比較大的要留下(對左邊child來說還是要符合條件)
                // 而比較大的可以符合左右兩者的條件
                arr[i-1] = max(arr[i-1], arr[i] + 1);
            }
            cnt += arr[i-1];
        }


        return cnt;
    }
};