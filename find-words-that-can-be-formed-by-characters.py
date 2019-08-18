# Runtime: 296 ms
# Memory Usage: 14.3 MB
from typing import Dict


class Solution:
  def countCharacters(self, words: List[str], chars: str) -> int:
    def createMap(ls: str) -> Dict[str, int]:
      mp = {}
      for c in ls:
        mp[c] = mp.get(c, 0) + 1

      return mp

    mChars = createMap(chars)

    res = 0
    for word in words:
      wMap = createMap(word)

      for k, v in wMap.items():
        if v > mChars.get(k, 0):
          break
      else:
        res += len(word)

    return res
