class Solution {
    
    int countnode(struct Node* root) {
        // base case
        if (root == NULL) {
            return 0;
        }
        int ans = 1 + countnode(root->left) + countnode(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int cnt) {
        if (root == NULL) {
            return true;
        }
        if (index >= cnt) {
            return false;
        } else {
            bool left = isCBT(root->left, 2*index + 1, cnt);
            bool right = isCBT(root->right, 2*index + 2, cnt);
            return (left && right);
        }
    }
    
    bool ismaxorder(struct Node* root) {
        // leaf node
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        if (root->right == NULL) {
            return (root->data > root->left->data);
        } else {
            bool left = ismaxorder(root->left);
            bool right = ismaxorder(root->right);
            return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
        }
    }

  public:
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalcount = countnode(tree);
        if (isCBT(tree, index, totalcount) && ismaxorder(tree)) {
            return true;
        } else {
            return false;
        }
    }
};