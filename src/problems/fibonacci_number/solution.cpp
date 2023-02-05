class Solution {
public:
    int fib(int n) {
        int preNum = 1, ppreNum = 0;
        
        // int ans;
        for (int i = 0; i < n; ++i) {
            int temp = preNum + ppreNum;
            preNum = ppreNum;
            ppreNum = temp;
        }
        
        return ppreNum;
    }
};