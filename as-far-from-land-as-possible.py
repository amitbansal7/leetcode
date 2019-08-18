# Runtime: 652 ms
# Memory Usage: 14.3 MB
from collections import deque


class Solution:
  def maxDistance(self, grid: List[List[int]]) -> int:
    if not grid or len(grid) == 0 or len(grid[0]) == 0:
      return -1

    q = deque([(x, y) for x in range(len(grid)) for y in range(len(grid[x])) if grid[x][y] == 1])

    if len(q) == len(grid) * len(grid[0]) or len(q) == 0:
      return -1

    lvl = 0

    while len(q) > 0:
      size = len(q)
      for i in range(size):
        t = q.popleft()
        x, y = t[0], t[1]
        for xi, yi in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
          xf = x + xi
          yf = y + yi

          if xf >= 0 and yf >= 0 and xf < len(grid) and yf < len(grid[xf]) and grid[xf][yf] == 0:
            q.append((xf, yf))
            grid[xf][yf] = 1

      lvl += 1

    return lvl - 1
