class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int dir[8][2]{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int row=M.size(),col=M[0].size();
        int gray_scale,cnt,x,y;
        vector<vector<int>> picture(row,vector<int>(col));
        for(int i=0;i<row;++i)
        {
        	for(int j=0;j<col;++j)
        	{
        		gray_scale=M[i][j];
        		cnt=1;
        		for(int k=0;k<8;++k)
        		{
        			x=i+dir[k][0];
        			y=j+dir[k][1];
        			if(x>=0&&x<row&&y>=0&&y<col)
        			{
        				gray_scale+=M[x][y];
        				++cnt;
        			}
        		}
        		picture[i][j]=gray_scale/cnt;
        	}
        }
        return picture;
    }
};