class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, left = 0, [-1]*3
        for right, c in enumerate(s):
            left[ord(c)-ord('a')] = right
            result += min(left)+1
        return result