#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int max_cnt = 0;
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int,int> m;
        dfs(root, m);
        vector<int> ans;
        for(const auto& item : m){
            if(item.second == max_cnt){
                ans.push_back(item.first);
            }
        }

        return ans;
    }

    int dfs(TreeNode* root, unordered_map<int,int>& m){
        if(root == nullptr){
            return 0;
        }
        int sum = dfs(root->left, m) + dfs(root->right, m) + root->val;
        if(!m.count(sum)){
            m[sum] = 0;
        }
        m[sum]++;
        max_cnt = max(max_cnt, m[sum]);
        return sum;
    }
};
int main()
{
}