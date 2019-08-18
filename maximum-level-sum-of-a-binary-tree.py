# Runtime: 356 ms
# Memory Usage: 18.4 MB
from collections import deque


class Solution(object):
  def maxLevelSum(self, root):
    q = deque([(root, 1)])
    mp = {}

    while len(q) > 0:
      t = q.popleft()
      node = t[0]
      lvl = t[1]

      mp[lvl] = mp.get(lvl, 0) + node.val

      if node.left:
        q.append((node.left, lvl + 1))

      if node.right:
        q.append((node.right, lvl + 1))

    return max(mp, key=mp.get)
