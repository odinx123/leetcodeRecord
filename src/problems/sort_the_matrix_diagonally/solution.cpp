class Solution {
    int gap = 0;
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        gap = mat[0].size();
        int minLength = min(mat.size(), mat[0].size());
        
        int cnt = 1;
        for (int i = mat.size()-1; i >= 0; --i) {
            int left = i*gap;
            int len = min(cnt++, minLength)-1;
            
            quickSort(mat, left, left+len*(gap+1));
        }
        for (int i = 1; i < gap; ++i) {
            double len = min(gap-i, minLength);
            len = sqrt(len*len*2) / sqrt(2) - 1;
            
            quickSort(mat, i, (int)round(i+len*(gap+1)));
        }
        
        return mat;
    }
    
    void quickSort(vector<vector<int>> &arr, int left, int right) {
        // Base case
        if (left >= right) return;

        // Recursion relation
        int lPos = left;
        int rPos = right + gap + 1;
        int pivot = arr[left/gap][left%gap];
        while (true) {
            lPos += gap + 1;
            rPos -= gap + 1;
            while (lPos < right && arr[lPos/gap][lPos%gap] < pivot) lPos += gap + 1;
            while (rPos > left && arr[rPos/gap][rPos%gap] > pivot) rPos -= gap + 1;

            if (lPos >= rPos) break;

            swap(arr[lPos/gap][lPos%gap], arr[rPos/gap][rPos%gap]);
        }
        swap(arr[left/gap][left%gap], arr[rPos/gap][rPos%gap]);

        quickSort(arr, left, rPos - gap - 1);
        quickSort(arr, rPos + gap + 1, right);
    }
};