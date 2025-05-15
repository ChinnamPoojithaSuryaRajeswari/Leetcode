class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int i = 0, j = 0;
    int answer = 0;
    int firstVal = -1, secondVal = -1;
    int lastFirst = -1, lastSecond = -1;
    while (i < fruits.size()) {
        if (firstVal == -1 || fruits[i] == firstVal) {
            firstVal = fruits[i];
            lastFirst = i;
        }
        else if (secondVal == -1 || fruits[i] == secondVal) {
            secondVal = fruits[i];
            lastSecond = i;
        }
        else {
            answer = max(answer, i - j);
            if (lastFirst < lastSecond) {
                j = lastFirst + 1;
                firstVal = fruits[i];
                lastFirst = i;
            } else {
                j = lastSecond + 1;
                secondVal = fruits[i];
                lastSecond = i;
            }
        }
        if (fruits[i] == firstVal) lastFirst = i;
        if (fruits[i] == secondVal) lastSecond = i;
        i++;
    }
    answer = max(answer, i - j);
    return answer;
    }
};