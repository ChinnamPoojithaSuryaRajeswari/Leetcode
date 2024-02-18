class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        priority_queue<int>pririt;
        int i=0;
        for(i=1;i<height.size();i++){
            int l=0;
            if(height[i-1]-height[i]<0){
                if(bricks-abs(height[i-1]-height[i])>=0){
                    bricks-=abs(height[i-1]-height[i]);
                    pririt.push(abs(height[i-1]-height[i]));
                }
                else{
                    bricks-=abs(height[i-1]-height[i]);
                    pririt.push(abs(height[i-1]-height[i]));
                    l = pririt.top();
                    cout<<l<<" ";
                    pririt.pop();
                    bricks+=l;
                    if(ladders>0){
                        ladders-=1;
                        // bricks-=abs(height[i-1]-height[i]);
                    }
                    else{
                        break;
                    }
                }
                cout<<bricks<<" ";
            }
        }
        return i-1;
    }
};