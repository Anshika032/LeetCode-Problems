class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> rows;

        // Reserved seats ko row-wise store karo
        for(auto seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if(s >= 2 && s <= 9)
                rows[row] |= (1 << s);
        }

        // Initially har empty row mein 2 groups
        int ans = 2 * (n - rows.size());

        for(auto [row, mask] : rows) {
            
            bool left  = !(mask & (1<<2)) && !(mask & (1<<3)) &&
                         !(mask & (1<<4)) && !(mask & (1<<5));

            bool right = !(mask & (1<<6)) && !(mask & (1<<7)) &&
                         !(mask & (1<<8)) && !(mask & (1<<9));

            bool middle = !(mask & (1<<4)) && !(mask & (1<<5)) &&
                          !(mask & (1<<6)) && !(mask & (1<<7));

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};