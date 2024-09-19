import re
from typing import List

class Solution:
    """
    optimization using dp: subproblem dp[i,j] = list of results
    """
    def isOperator(self, c: str) -> bool:
        return c in ['+', '-', '*']

    def evaluate(self, operand1: int, operation: str, operand2: int) -> int:
        match operation:
            case '-':
                return operand1-operand2
            case '*':
                return operand1*operand2
            case '+':
                return operand2+operand1
    
    def combine(self, l: List[int], r: List[int], operation: str) -> List[int]:
        result = []
        for opL in l:
            for opR in r:
                result.append(self.evaluate(opL, operation, opR))
        return result


    def helper(self, expression: List) -> List[int]:
        if len(expression) == 1:
            return expression

        result = []
        for index, exp in enumerate(expression):
            if self.isOperator(exp):
                l = self.helper(expression[:index])
                r = self.helper(expression[index+1:])
                result.extend(self.combine(l, r, exp))
        return result


    def diffWaysToCompute(self, expression: str) -> List[int]:
        expressionList = re.split('(\+|\-|\*)', expression)
        expressionList = list(map(lambda exp: exp if self.isOperator(exp) else int(exp), expressionList))
        return self.helper(expressionList)
       

print(Solution().diffWaysToCompute('2*3-4*5'))