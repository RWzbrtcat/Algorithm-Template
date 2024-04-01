//
// Created by Lazy Cat on 2024/4/1.
//

// 原题 Leetcode 3102.最小化曼哈顿距离


class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> xs, ys;
        for(auto &p: points){
            xs.insert(p[0] + p[1]);
            ys.insert(p[1] - p[0]);
        }
        int ans = INT_MAX;
        for(auto &p: points){
            int x = p[0] + p[1], y = p[1] - p[0];
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));
            ans = min(ans, max(*xs.rbegin() - *xs.begin(), *ys.rbegin() - *ys.begin()));
            xs.insert(x);
            ys.insert(y);
        }
        return ans;
    }
};