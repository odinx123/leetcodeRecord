class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> grapth;

        bool state = false;
        int x = 0, y = 0;
        grapth.insert({0, 0});
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == 'N')
                ++y;
            else if (path[i] == 'S')
                --y;
            else if (path[i] == 'E')
                ++x;
            else
                --x;
            
            if (grapth.count({y, x}))
                return true;
            else
                grapth.insert({y, x});
        }

        return state;
    }
};