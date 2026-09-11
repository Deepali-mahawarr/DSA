class Solution {
public:
    int dist(vector<int>& point) {
        int x = point[0];
        int y = point[1];

        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, vector<int>>
        > maxHeap;

        for (auto& point : points) {
            maxHeap.push({dist(point), point});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
         while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};