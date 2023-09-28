class Solution {
public:
    int twoEggDrop(int n) {
        // 將雞蛋分組由第一組往下進行測試
        // 因為第二組雞蛋要加上測試是不是第一組的那一次
        // 所以假設第一組為x個一組，那第二組就是x-1個一組，以此類推
        // x + (x-1) + (x-2) + ... + 1
        return ceil(0.5 * (-1 + sqrt(1 + 8 * n)));
    }
};