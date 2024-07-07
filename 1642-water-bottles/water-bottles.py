class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        m=numBottles
        s = m
        while(m>=numExchange):
            p = m % numExchange
            s += m//numExchange
            m = m//numExchange
            m += p
        return s