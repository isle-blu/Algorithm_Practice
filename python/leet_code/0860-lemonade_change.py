# 860. Lemonade Change
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = 0
        ten = 0
        for b in bills:
            if b == 5:
                five += 1
            elif b == 10:
                if five < 1:
                    return False
                
                five -= 1
                ten += 1
            else:
                if ten > 0 and five > 0:
                        ten -= 1
                        five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        
        return True