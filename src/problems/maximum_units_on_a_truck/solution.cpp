class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int> &v1, const vector<int> &v2) {
           return v1[1] > v2[1]; 
        });
        
        int boxNum = 0, unitNum = 0;
        for (int i = 0; i < boxTypes.size() && boxNum < truckSize; ++i) {
            if (boxNum + boxTypes[i][0] <= truckSize) {
                boxNum += boxTypes[i][0];
                unitNum += boxTypes[i][0]*boxTypes[i][1];
            } else {
                unitNum += (truckSize-boxNum)*boxTypes[i][1];
                break;
            }
        }
        
        return unitNum;
    }
};