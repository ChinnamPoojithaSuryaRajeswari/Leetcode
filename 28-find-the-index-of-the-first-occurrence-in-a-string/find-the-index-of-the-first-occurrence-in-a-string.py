class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack)):
            if(needle==haystack[i:i+len(needle)]):
                return i
        else:
            return -1