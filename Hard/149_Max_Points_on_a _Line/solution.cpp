#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    static int maxPoints(const vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slopeCount;
            int duplicates = 1;
            int localMax = 0;

            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;

                if (points[i] == points[j]) {
                    duplicates++;
                } else {
                    double slope = calculateSlope(points[i], points[j]);
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }

            result = max(result, localMax + duplicates);
        }

        return result;
    }

private:
    static double calculateSlope(const vector<int> &p1, const vector<int> &p2) {
        if (!p1.empty() && !p2.empty()) {
            double slope = 0;
            const double x1 = p1[0];
            const double x2 = p2[0];
            const double y1 = p1[1];
            const double y2 = p2[1];

            if (x1 != x2) {
                slope = (y1 - y2) / (x1 - x2);
            } else {
                slope = numeric_limits<double>::infinity();
            }
            return slope;
        }
        return 0;
    }
};
