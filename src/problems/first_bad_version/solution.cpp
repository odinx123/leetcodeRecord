// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isBadVersion(mid) == 1 && isBadVersion(mid-1) == 0) {
                return mid;
            }
            else if (isBadVersion(mid) == 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return -1;
    }
};