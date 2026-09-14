class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long xMax = max({rec1[0], rec1[2], rec2[0], rec2[2]}), xMin = min({rec1[0], rec1[2], rec2[0], rec2[2]});

        long long yMax = max({rec1[1], rec1[3], rec2[1], rec2[3]}), yMin = min({rec1[1], rec1[3], rec2[1], rec2[3]});

        long long l1 = (long long)abs(rec1[0] - rec1[2]), l2 = (long long)abs(rec2[0] - rec2[2]);
        long long b1 = (long long)abs(rec1[1] - rec1[3]), b2 = (long long)abs(rec2[1] - rec2[3]);

        if((long long)(yMax - yMin) >= (long long)(b1 + b2) or (long long)(xMax - xMin) >= (long long)(l1 + l2)) return false;

        return true;
    }
};