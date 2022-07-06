vector<int> memData;
class Solution {
public:
    int fib(int n) {
        int size = memData.size();
        if (size-1 >= n)
            return memData.at(n);

        size = size >= 2 ? size : 2;
        
        memData.resize(n >= 2 ? n+1 : 2);
        memData.at(1) = 1;
        for (int i = size; i <= n; ++i)
            memData.at(i) = memData.at(i-1) + memData.at(i-2);
        
        return memData.at(n);
    }
};