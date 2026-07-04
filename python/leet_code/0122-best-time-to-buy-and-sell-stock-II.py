# 122. Best Time to Buy and Sell Stock II

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        answer = 0
        buy_price = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < prices[i - 1]:
                answer += prices[i - 1] - buy_price
                buy_price = prices[i]

        if buy_price < prices[-1]:
            answer += prices[-1] - buy_price

        return answer