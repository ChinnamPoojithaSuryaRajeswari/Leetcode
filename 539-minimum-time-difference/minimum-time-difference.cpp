class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int mini = INT_MAX;
        for(int i=0;i<timePoints.size()-1;i++){
            int fst = 0;
            int lst = 0;
            int fstmin = 0;
            int lstmin = 0;
            fst = fst*10+(int(timePoints[i][0])-int('0'));
            fst = fst*10+(int(timePoints[i][1])-int('0'));
            lst = lst*10+(int(timePoints[i+1][0])-int('0'));
            lst = lst*10+(int(timePoints[i+1][1])-int('0'));
            fstmin = fstmin*10+(int(timePoints[i][3])-int('0'));
            fstmin = fstmin*10+(int(timePoints[i][4])-int('0'));
            lstmin = lstmin*10+(int(timePoints[i+1][3])-int('0'));
            lstmin = lstmin*10+(int(timePoints[i+1][4])-int('0'));
            mini = min(mini,((lst-fst)*60)-fstmin+lstmin);
            mini = min(mini,((24-lst)*60)-lstmin+fstmin+(fst*60));
        }
        int fst = 0;
        int lst = 0;
        int fstmin = 0;
        int lstmin = 0;
        fst = fst*10+(int(timePoints[0][0])-int('0'));
        fst = fst*10+(int(timePoints[0][1])-int('0'));
        lst = lst*10+(int(timePoints[timePoints.size()-1][0])-int('0'));
        lst = lst*10+(int(timePoints[timePoints.size()-1][1])-int('0'));
        fstmin = fstmin*10+(int(timePoints[0][3])-int('0'));
        fstmin = fstmin*10+(int(timePoints[0][4])-int('0'));
        lstmin = lstmin*10+(int(timePoints[timePoints.size()-1][3])-int('0'));
        lstmin = lstmin*10+(int(timePoints[timePoints.size()-1][4])-int('0'));
        mini = min(mini,((lst-fst)*60)-fstmin+lstmin);
        mini = min(mini,((24-lst)*60)-lstmin+fstmin+(fst*60));
        return mini;
    }
};