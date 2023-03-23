//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* findNode(Node* root,int &target,int &sum){
        if(!root||target==root->data)
            return root;
        sum+=root->data;
        return (target>root->data?findNode(root->right,target,sum):findNode(root->left,target,sum));
    }
    int sumLeaf(Node* node){
        if(!node)
            return 0;
        if(!node->right)
            return node->data+sumLeaf(node->left);
        if(!node->left)
            return node->data+sumLeaf(node->right);
        return min(node->data+sumLeaf(node->left),node->data+sumLeaf(node->right));
    }
    int maxDifferenceBST(Node *root,int target){
        int sum1=0;
        Node* node=findNode(root,target,sum1);
        if(!node)
            return -1;
        int sum2=sumLeaf(node)-node->data;
        // cout<<sum1<<' '<<sum2<<'\n';
        return sum1-sum2;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends