//
// Created by Lazy Cat on 2024/4/2.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n);
        for(auto &e: edges){
            g[e[0]].emplace_back(e[1], e[2] + 1);
            g[e[1]].emplace_back(e[0], e[2] + 1);
        }

        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first, x = p.second;
            if(d > dis[x]){
                continue;
            }
            for(auto &v: g[x]){
                int y = v.first, w = v.second;
                if(d + w < dis[y]){
                    dis[y] = d + w;
                    pq.emplace(dis[y], y);
                }
            }
        }
        int ans = 0;
        for(int &d: dis){
            if(d <= maxMoves) ++ans;
        }
        for(auto &e: edges){
            int u = e[0], v = e[1], c = e[2];
            int a = max(0, maxMoves - dis[u]);
            int b = max(0, maxMoves - dis[v]);
            ans += min(a + b, c);
        }
        return ans;
    }
};