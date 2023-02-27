/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(int r,int c,int s,vector<vector<int>>& grid,vector<Node*> &leaf){
        if(s==1)
            return leaf[grid[r][c]];
        s>>=1;
        auto topleft=build(r,c,s,grid,leaf);
        auto topright=build(r,c+s,s,grid,leaf);
        auto bottomleft=build(r+s,c,s,grid,leaf);
        auto bottomright=build(r+s,c+s,s,grid,leaf);
        if(topleft==topright && topleft==bottomright && topleft==bottomleft)
            return topleft;
        return new Node(0,0,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        vector<Node*> leaf(2);
        leaf[0]=new Node(0,1);
        leaf[1]=new Node(1,1);
        return build(0,0,grid.size(),grid,leaf);
    }
};