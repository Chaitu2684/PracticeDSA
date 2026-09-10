/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sumOfNodesinsubtree(TreeNode* root){
        if(!root) return 0;
        int sum=0;
        sum+= root->val+ sumOfNodesinsubtree(root->left)+sumOfNodesinsubtree(root->right);
        return sum;
    }
    int numberOFnodes(TreeNode* root){
        if(!root) return 0;
        int res=0;
        res+=1+numberOFnodes(root->left)+numberOFnodes(root->right);
        return res;
    }
public:
int cnt=0;

    int averageOfSubtree(TreeNode* root) {

        if(!root) return cnt;
        if(root->val==sumOfNodesinsubtree(root)/numberOFnodes(root)) cnt++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return cnt;
       

        
    }
};