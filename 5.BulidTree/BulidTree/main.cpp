//
//  main.cpp
//  BulidTree
//
//  Created by wyy on 2017/3/20.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>

using namespace std;
struct BinaryTreeNode {
    int m_Value;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_right;
};

BinaryTreeNode* construCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    //前序遍历拿到root
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root -> m_Value = rootValue;
    root -> m_pLeft = root -> m_right = NULL;
    
    //如果只有头结点
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startInorder == *startInorder) {
            return root;
        }else {
//            throw std::exception("Invalid input");
        }
    }
    
    
    //在中序拿到头节点
    int *rootInorder = startInorder;
    while (rootInorder <= endPreorder && *rootInorder != rootValue) {
          rootInorder ++;
    }
    
    if(rootInorder == endPreorder && *rootInorder != rootValue){
       //            throw std::exception("Invalid input");
    }
    //左子树的节点
    int leftLenght = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLenght;
    
    if (leftLenght > 0) {
        root -> m_pLeft = construCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLenght < endPreorder - startPreorder) {
        root -> m_right = construCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1 , endInorder);
    }
    return root;
}

BinaryTreeNode* construct(int *preorder, int *inorder, int lenght) {
    if (preorder == NULL && inorder == NULL && lenght <= 0) return NULL;
    return construCore(preorder, preorder + lenght - 1, inorder, inorder + lenght -1);
}

int main()
{
    int pre[8] = {1,2,4,7,3,5,6,8};
    int in[8]  = {4,7,2,1,5,3,8,6};
   BinaryTreeNode *root =  construct(pre, in, 8);
    
}
