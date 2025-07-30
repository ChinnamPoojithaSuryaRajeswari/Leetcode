class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>mpp;
        for(int i=0;i<wordList.size();i++){
            mpp[wordList[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        int ans = INT_MAX;
        while(!q.empty()){
            string current = q.front().first;
            int i = q.front().second;
            q.pop();
            // cout<<current<<" ";
            if(current == endWord){
                ans = min(ans,i);
            }
            for(int j=0;j<current.size();j++){
                char res  = current[j];
                for(int k=0;k<26;k++){
                    current[j] = 'a'+k;
                    if(mpp[current]){
                        q.push({current,i+1});
                        mpp[current]--;
                    }
                }
                current[j] = res;
            }
        }
        return ans==INT_MAX ? 0 : ans+1;
    }
};