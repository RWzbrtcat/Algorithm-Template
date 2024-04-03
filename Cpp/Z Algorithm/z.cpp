//
// Created by Lazy Cat on 2024/4/3.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        int left = 0, right = 0;
        vector<int> z(n, 0);
        long long ans = n;
        for(int i = 1; i < n; ++i){
            if(i <= right){
                z[i] = min(z[i - left], right - i + 1);
            }
            while(z[i] + i < n && s[z[i]] == s[z[i] + i]){
                left = i;
                right = i + z[i]++;
            }
            ans += z[i];
        }
        return ans;
    }
};