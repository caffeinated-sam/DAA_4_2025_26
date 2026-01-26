class Solution {
  public:
    bool solve(vector<int> &arr, int i, int sum, int curr, bool &check){
        if(curr==sum) {
            check= true;
            return true;
        } 
        if(check==false){
            if(i>= arr.size()) return false;
            if(curr>sum) return false;
            solve(arr, i+1, sum, curr+arr[i], check);
            return solve(arr, i+1, sum, curr, check);    
        }
        else  return true;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        bool check=false;
        return solve(arr, 0, sum, 0, check);
    }
};