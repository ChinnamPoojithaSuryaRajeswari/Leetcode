class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0 , y = 0, maaxi = 0,flag=0;
        char dir = 'n';
        map<pair<int,int>,int>mppx;
        for(int i=0;i<obstacles.size();i++){
            mppx[{obstacles[i][0],obstacles[i][1]}]+=1;
        }
        for(int j=0;j<commands.size();j++){
            if(commands[j] >= 0){
                // cout<<x<<" "<<y<<" "<<dir<<endl;
                if(dir == 'n'){
                    int i=0;
                        int w = commands[j];
                        while(w){
                            w-=1;
                            y+=1;
                            if(mppx.find({x,y})!=mppx.end()){
                                y-=1;
                                break;
                            }
                            if((x*x)+(y*y) > maaxi){
                                maaxi = (x*x)+(y*y);
                            }   
                        }
                    }
                else if(dir == 'e'){
                    int w = commands[j];
                    while(w){
                        w-=1;
                        x+=1;
                        if(mppx.find({x,y})!=mppx.end()){
                            x-=1;
                            break;
                        }
                        if((x*x)+(y*y) > maaxi){
                            maaxi = (x*x)+(y*y);
                        }
                    }
                }
                else if(dir == 's'){
                        int w = commands[j];
                        while(w){
                            w-=1;
                            y-=1;
                            if(mppx.find({x,y})!=mppx.end()){
                                y+=1;
                                break;
                            }
                            if((x*x)+(y*y) > maaxi){
                                maaxi = (x*x)+(y*y);
                            }   
                        }
                }
                else{
                        int w = commands[j];
                        while(w){
                            w-=1;
                            x-=1;
                            if(mppx.find({x,y})!=mppx.end()){
                                x+=1;
                                break;
                            }
                            if((x*x)+(y*y) > maaxi){
                                maaxi = (x*x)+(y*y);
                            }
                        }
                }
            }
            else{
                if(commands[j]==-1){
                    if(dir=='n'){
                        dir = 'e';
                    }
                    else if(dir == 'e'){
                        dir = 's';
                    }
                    else if(dir == 's'){
                        dir = 'w';
                    }
                    else{
                        dir = 'n';
                    }
                }
                else{
                    if(dir == 'n'){
                        dir = 'w';
                    }
                    else if(dir == 'e'){
                        dir = 'n';
                    }
                    else if(dir == 's'){
                        dir = 'e';
                    }
                    else{
                        dir = 's';
                    }
                }
            }
        }
        return maaxi;
    }
};