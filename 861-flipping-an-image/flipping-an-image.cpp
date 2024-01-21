class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int j,k,temp;
        for(int i=0;i<image.size();i++)
        {
            // j=0;
            // k=image[i].size()-1;
            // while(j<k){
            //     temp=image[i][k];
            //     image[i][k]=image[i][j];
            //     image[i][j]=temp;
            // }
            reverse(image[i].begin(),image[i].end());
            for(int l=0;l<image[i].size();l++)
            {
                image[i][l]=image[i][l]^1;
            }
        }
        return image;
    }
};