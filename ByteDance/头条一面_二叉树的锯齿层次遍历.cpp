/*
头条一面题目：二叉树的锯齿形层次遍历（LeetCode 103）
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
思路：利用两个队列，一个存放正向的那一层的节点，另一个存放反向的那一层的节点，同时定义一个变量表示正向还是反向，需要注意节点加入的顺序（先左还是先右）
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        vector<TreeNode*> queue_left;
        vector<TreeNode*> queue_right;
        bool flag = true;
        queue_left.push_back(root);
        int num = 0;
        vector<int> vec;
        while(queue_left.size() > 0 || queue_right.size() > 0) {
            TreeNode* temp;
            if(flag) {
                temp = queue_left[num];
                vec.push_back(temp->val);
                if(temp->left != NULL)
                    queue_right.push_back(temp->left);
                if(temp->right != NULL)
                    queue_right.push_back(temp->right);
                num--;
                if(num < 0) {
                    queue_left.clear();
                    num = queue_right.size() - 1;
                    flag = !flag;
                    result.push_back(vec);
                    vec.clear();
                }
            }
            else {
                temp = queue_right[num];
                vec.push_back(temp->val);
                if(temp->right != NULL)
                    queue_left.push_back(temp->right);
                if(temp->left != NULL)
                    queue_left.push_back(temp->left);
                num--;
                if(num < 0) {
                    queue_right.clear();
                    num = queue_left.size() - 1;
                    flag = !flag;
                    result.push_back(vec);
                    vec.clear();
                }
            }
        }
        return result;
    }
};
