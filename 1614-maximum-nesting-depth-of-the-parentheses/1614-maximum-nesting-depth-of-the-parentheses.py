class Solution:
    def maxDepth(self, s: str) -> int:
        maxi = 0
        n = len(s)
        cnt = 0

        for i in range(n):
            if s[i] == '(':
                cnt += 1
            elif s[i] == ')':
                cnt -= 1

            if cnt > maxi:
                maxi = cnt

        return maxi
        