 class Solution {
 	vector<vector<int>> res_;
 	void dfs(vector<int>& temp, int target, int index, int sum, int k){
 		if(temp.size() == k && sum == target){
 			res_.emplace_back(temp);
 		}else if(sum < target && temp.size() < k){
 			for(int i = index; i <= 9; ++i){
 				temp.emplace_back(i);
 				dfs(temp, target, i + 1, sum + i, k);
 				temp.pop_back();
 			}
 		}
 	}
 public:
 	vector<vector<int>> combinationSum3(int k, int n) {
 		vector<int> temp;
 		dfs(temp, n, 1, 0, k);
 		return res_;
 	}
 };