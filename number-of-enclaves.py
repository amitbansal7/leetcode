# Runtime: 632 ms
# Memory Usage: 14.8 MB


class Solution:
  def numEnclaves(self, A: List[List[int]]) -> int:
    def dfs(mn, x, y):
      if x < 0 or x >= len(mn) or y < 0 or y >= len(mn[0]) or mn[x][y] == 0:
        return

      mn[x][y] = 0

      for xi, yi in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        dfs(mn, x + xi, y + yi)

    if not A or len(A) == 0:
      return 0

    for i in range(len(A)):
      for j in range(len(A[0])):
        if i == 0 or j == len(A[0]) - 1 or j == 0 or i == len(A) - 1:
          dfs(A, i, j)

    return sum(sum(a) for a in A)
