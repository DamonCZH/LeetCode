class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        
        for(int i=0;i<nums.size();i++){
            int n=result.size();
            for(int j=0;j<n;j++){
                //遍历已有的子集，将新元素添加进去形成新子集
                vector<int> temp;
                temp=result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
                temp.clear();
            }
        }
        
        for(int i=0;i<result.size();i++)
            sort(result[i].begin(),result[i].end());
        
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};
//20 ms	9.9 MB
