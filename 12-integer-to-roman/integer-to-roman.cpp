class Solution {
public:
    string intToRoman(int num) {
         map<int, string, greater<int>> mpp{{1000, "M"},{900, "CM"},{500, "D"},{400, "CD"},{100, "C"},{90, "XC"},{50, "L"},{40, "XL"},{10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}};
        string ans = "";
        while(num){
            for(auto it:mpp){
                int divvy = num/it.first;
                while(divvy){
                    ans += it.second;
                    divvy--;
                }
                num=num%(it.first);
            }
        }
        return ans;
    }
};