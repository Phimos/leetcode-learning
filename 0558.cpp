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

    Node() {}

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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* newTree = new Node(quadTree1->val | quadTree2->val, false, NULL, NULL, NULL, NULL);
        if (quadTree1->isLeaf && quadTree2->isLeaf)
        {
            newTree->isLeaf = true;
        }
        else
        {
            newTree->topLeft = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->topLeft, quadTree2->isLeaf ? quadTree2 : quadTree2->topLeft);
            newTree->topRight = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->topRight, quadTree2->isLeaf ? quadTree2 : quadTree2->topRight);
            newTree->bottomLeft = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->bottomLeft, quadTree2->isLeaf ? quadTree2 : quadTree2->bottomLeft);
            newTree->bottomRight = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->bottomRight, quadTree2->isLeaf ? quadTree2 : quadTree2->bottomRight);
            if (newTree->topLeft->isLeaf && newTree->topRight->isLeaf && newTree->bottomLeft->isLeaf && newTree->bottomRight->isLeaf && newTree->topLeft->val == newTree->topRight->val && newTree->bottomLeft->val == newTree->bottomRight->val && newTree->topLeft->val == newTree->bottomLeft->val)
            {
                newTree->val = newTree->topLeft->val;
                newTree->isLeaf = true;
                free(newTree->topLeft);
                newTree->topLeft = NULL;
                free(newTree->topRight);
                newTree->topRight = NULL;
                free(newTree->bottomLeft);
                newTree->bottomLeft = NULL;
                free(newTree->bottomRight);
                newTree->bottomRight = NULL;
            }
        }
        return newTree;
    }
};