class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int cost = 0;

        int sr = startPos[0];
        int sc = startPos[1];

        int hr = homePos[0];
        int hc = homePos[1];

        // Move in rows
        while (sr < hr) {
            sr++;
            cost += rowCosts[sr];
        }

        while (sr > hr) {
            sr--;
            cost += rowCosts[sr];
        }

        // Move in columns
        while (sc < hc) {
            sc++;
            cost += colCosts[sc];
        }

        while (sc > hc) {
            sc--;
            cost += colCosts[sc];
        }

        return cost;
    }
};