class Solution(object):
     def nthPersonGetsNthSeat(self, n):
        """
        :type n: int
        :rtype: float
        """
        dp = [0.0]*2
        dp[0] = 1.0  # zero-indexed
        for i in xrange(2, n+1):
            dp[(i-1)%2] = 1.0/i+dp[(i-2)%2]*(i-2)/i
        return dp[(n-1)%2]