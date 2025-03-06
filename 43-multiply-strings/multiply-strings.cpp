class Solution {
public:
    void solve(string &ans,string &nums1,int vl,int k){
        int carry = 0, j = ans.size()-k;
        for(int i=nums1.size()-1;i>=0;i--){
            int val = int(nums1[i]-'0')*vl;
            val += int(ans[j]-'0');
            val += carry;
            carry = val/10;
            ans[j--] = (val%10)+'0';
            // cout<<val<<" ";
        }
        if(carry)ans[j] = (int(ans[j]-'0')+carry)+'0';
        // cout<<ans<<endl;
    }
    string multiply(string nums1, string nums2) {
        string ans = "";
        for(int i = 0 ; i < nums1.size()+nums2.size() ; i++){
            ans+='0';
        }
        int carry = 1;
        for(int i=nums2.size()-1;i>=0;i--){
            solve(ans,nums1,int(nums2[i]-'0'),carry++);
        }
        int i=0;
        while(i<ans.size()){
            if(ans[i]!='0')break;
            i++;
        }
        if(i==ans.size())return "0";
        return ans.substr(i,(ans.size()-i));
    }
};