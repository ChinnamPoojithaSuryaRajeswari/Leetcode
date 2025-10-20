class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        k=0
        for i in operations:
            if i=="--X" or i=="X--":
                k-=1
            elif i=="++X" or i=="X++":
                k+=1
        return k