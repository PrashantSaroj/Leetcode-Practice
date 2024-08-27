class Solution(object):
    def __init__(self) -> None:
        self.symMap = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = self.symMap[s[-1]]
        for i in range(0, len(s)-1):
            if self.symMap[s[i]] < self.symMap[s[i+1]]:
                num -= self.symMap[s[i]]
            else:
                num += self.symMap[s[i]]
        return num
    
list(map(lambda r: print(Solution().romanToInt(r)), ['III', 'LVIII', 'MCMXCIV']))
