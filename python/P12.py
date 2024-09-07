class Solution(object):
    def __init__(self):
        self.thousands = ['', 'M', 'MM', 'MMM']
        self.hundreds = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        self.tens = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        self.units = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        return self.thousands[num//1000] + self.hundreds[(num % 1000)//100] + self.tens[(num % 100)//10] + self.units[(num % 10)]
    
nums = [3749, 58, 1994]
sol = Solution()
for num in nums:
    print(sol.intToRoman(num))
