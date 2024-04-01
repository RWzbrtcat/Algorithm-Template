

# 以leetcode 3102.最小化曼哈顿距离为例
from sortedcontainers import SortedList
import math

class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        xs = SortedList()
        ys = SortedList()
        for x, y in points:
            xs.add(x + y)
            ys.add(y - x)

        ans = math.inf
        # 枚举移出的点
        for x, y in points:
            xs.remove(x + y)
            ys.remove(y - x)
            ans = min(ans, max(abs(xs[0] - xs[-1]), abs(ys[0] - ys[-1])))
            xs.add(x + y)
            ys.add(y - x)
        return ans