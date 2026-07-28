class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,candidates,target,path,ans);
        return ans;
    }
    void solve(int idx, vector<int>& candidates, int remaining,
               vector<int>& path, vector<vector<int>>& ans){
                if (remaining == 0) {
            ans.push_back(path);
            return;
        }
        if (idx == candidates.size() || remaining < 0) return;

        // choice 1: take candidates[idx], stay at idx
        path.push_back(candidates[idx]);
        solve(idx, candidates, remaining - candidates[idx], path, ans);
        path.pop_back();          // ← undo, this is the "backtrack"

        // choice 2: skip candidates[idx], move on
        solve(idx + 1, candidates, remaining, path, ans);
               }
};
