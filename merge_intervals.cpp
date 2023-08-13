#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        // Step 1: Sort the intervals based on their start times.
        sort(intervals.begin(), intervals.end());

        // Initialize variables to represent the start and end of the first interval.
        int x1 = intervals[0][0];
        int x2 = intervals[0][1];
        
        // Step 2: Loop through the intervals to merge overlapping intervals.
        for (int i = 1; i < intervals.size(); i++) {
            int y1 = intervals[i][0]; // Start of the current interval.
            int y2 = intervals[i][1]; // End of the current interval.

            // Step 3: Check for overlap between the current interval and the previous merged interval.
            if (x2 < y1) {
                // Case 1: No overlap, push the previous interval to the result and update x1 and x2 to the current interval.
                res.push_back({x1, x2});
                x1 = y1;
                x2 = y2;
            } else if (x2 == y1) {
                // Case 2: The current interval starts exactly where the previous interval ends, so merge them.
                x2 = y2;
            } else if (x1 <= y1 && y1 < x2) {
                // Case 3: There is an overlap, merge the current interval with the previous one.
                x2 = max(x2, y2);
            }
        }
        
        // Step 4: Push the last merged interval to the result vector.
        res.push_back({x1, x2});
        
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution solution;
    vector<vector<int>> mergedIntervals = solution.merge(intervals);
    
    // Output the merged intervals
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    
    return 0;
}
