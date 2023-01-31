class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long int lNumber = 1, n = x;
        
        // 用反轉數字的方法解比較快
        // 雖然都是O(N)但是少一個迴圈
        while (n != 0) {  // calcular n number.
            n /= 10;
            lNumber *= 10;
        }
        lNumber /= 10;

        for (; lNumber != 0;) {
            if (x / lNumber != x % 10)
                return false;
            x = x % lNumber / 10;  // 去掉最左和最右邊數字
            lNumber /= 100;  // 左和右加起來兩位數字
        }

        return true;
    }
};