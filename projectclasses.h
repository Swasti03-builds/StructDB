#ifndef PROJECTCLASSES_H
#define PROJECTCLASSES_H

#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }
};

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

#endif
