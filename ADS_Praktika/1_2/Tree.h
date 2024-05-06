/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

using namespace std;

class Tree
{

private:
    TreeNode* m_anker;
    int m_currentNodeChronologicalID;

public:
    Tree();
    ~Tree();
    void m_deleteSubtree(TreeNode*);
    void addNode(string, int, double, int);
    bool deleteNode(int);
    bool searchNode(string);
    bool searchNodeHelper(string, TreeNode*);
    void printAll();
    void m_printAll(TreeNode*);
    void levelOrder();
    void printLevelOrderHelper(TreeNode*);
    void printPreOrder();
    void printPreOrderHelper(TreeNode*);
    void printInOrder();
    void printInOrderHelper(TreeNode*);
    void printPostOrder();
    void printPostOrderHelper(TreeNode*);
    void printNode(TreeNode*);





    friend TreeNode* get_anker(Tree& TN);
};
