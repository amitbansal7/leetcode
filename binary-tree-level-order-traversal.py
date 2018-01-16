# Runtime: 61 ms
import Queue as queue


class Solution(object):
    def levelOrder(self, root):
        res = []
        if not root:
            return res

        temp = []
        Q = queue.Queue()

        Q.put([root, 0])
        maxlvl = 0
        while not Q.empty():
            t = Q.get()

            if(t[1] > maxlvl):
                if len(temp) > 0:
                    res.append([] + temp)
                    temp = []

                maxlvl += 1

            temp.append(t[0].val)

            if t[0].left:
                Q.put([t[0].left, t[1] + 1])

            if t[0].right:
                Q.put([t[0].right, t[1] + 1])

        if len(temp) > 0:
            res.append(temp)

        return res
