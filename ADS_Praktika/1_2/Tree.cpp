/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
using namespace std;
#include <queue>

Tree::~Tree()
{
    m_deleteSubtree(m_anker);
}

Tree::Tree() : m_anker(nullptr), m_currentNodeChronologicalID(0) {}

void Tree::m_deleteSubtree(TreeNode *node)
{
    if (node == nullptr)
        return;
    m_deleteSubtree(node->getLeft());
    m_deleteSubtree(node->getRight());
    delete node;
}

void Tree::addNode(std::string Name, int Age, double Income, int PostCode)
{
    TreeNode* neuerKnoten = new TreeNode(Age + PostCode + Income, m_currentNodeChronologicalID++, Name, Age, Income, PostCode);
    neuerKnoten->setLeft(nullptr);
    neuerKnoten->setRight(nullptr);

    if(m_anker == nullptr)
    {
        m_anker = neuerKnoten;
    }
    else
    {
        TreeNode* ptr = m_anker;
        while(ptr != nullptr)
        {
            if(neuerKnoten->getNodeOrderID() > ptr->getNodeOrderID() && ptr->getRight() == nullptr)
            {
                ptr->setRight(neuerKnoten);
                return;
            }
            if(neuerKnoten->getNodeOrderID() < ptr->getNodeOrderID() && ptr->getLeft() == nullptr)
            {
                ptr->setLeft(neuerKnoten);
                return;
            }
            if(neuerKnoten->getNodeOrderID() < ptr->getNodeOrderID() && ptr->getLeft() != nullptr)
            {
                ptr = ptr->getLeft();
            }
            if(neuerKnoten->getNodeOrderID() > ptr->getNodeOrderID() && ptr->getRight() != nullptr)
            {
                ptr = ptr->getRight();
            }
        }
    }
}

bool Tree::searchNode(string Name)
{
    return searchNodeHelper(Name, m_anker);
}

bool Tree::searchNodeHelper(string Name, TreeNode* node)
{
    bool check = false;

    if(node == nullptr)
    {
        return false;
    }
    if(node->getName() == Name)
    {
        node->print();
        check = true;
    }
    bool leftResult = searchNodeHelper(Name, node->getLeft());
    if(leftResult)
        check = true;
    bool rightResult = searchNodeHelper(Name, node->getRight());
    if(rightResult)
        check = true;
    return check;
}

bool Tree::deleteNode(int NodeOrderID)
{
    TreeNode* current = m_anker;
    TreeNode* parent = nullptr;
    bool leftChild = false;

    if(current == nullptr)
        return false;

    else
    {
        while(current != nullptr  && current->getNodeOrderID() != NodeOrderID)
        {
            parent = current;
            if(NodeOrderID < current->getNodeOrderID())
            {
                current = current->getLeft();
                leftChild = true;
            }
            else
            {
                current = current->getRight();
                leftChild = false;
            }


        }
        if(current == nullptr) // Knoten nicht vorhanden
        {
            return false;
        }

        else
        {
            // Knoten hat keine Nachfolger
            if(current->getRight() == nullptr && current->getLeft() == nullptr)
            {
                if(current == m_anker)
                    m_anker = nullptr;

                else if(leftChild)
                    parent->setLeft(nullptr);

                else
                    parent->setRight(nullptr);

                delete current;
            }

            //Knoten hat einen Nachfolger
            //1.1 nur Rechten Nachfolger
            else if(current->getLeft() == nullptr)
            {
                if(current == m_anker)
                    m_anker = current->getRight();

                else if(leftChild)
                    parent->setLeft(current->getRight());

                else
                    parent->setRight(current->getRight());

                delete current;
            }

            //Knoten hat einen Nachfolger
            //1.2  nur Linken Nachfolger
            else if(current->getRight() == nullptr)
            {
                if(current == m_anker)
                    m_anker = current->getLeft();

                else if(leftChild)
                    parent->setLeft(current->getLeft());

                else
                    parent->setRight(current->getRight());

                delete current;
            }

            //Knoten hat 2 Nachfolger
            else
            {
                    TreeNode* tmp = current->getRight();
                    TreeNode* child = tmp;

                    while(child->getLeft() != nullptr)
                    {
                        child = child->getLeft();
                    }
                    TreeNode* childParent = tmp;
                    tmp->setLeft(child->getRight());
                    child->setLeft(current->getLeft());
                    child->setRight(tmp);

                    if(current != m_anker)
                    {
                        if(leftChild)
                            parent->setLeft(child);

                        if(!leftChild)
                            parent->setRight(child);
                    }



                    delete current;
            }
        }
    }
    return true;
}

void Tree::printAll()
{
    cout << setw(4) << " ID "
         << "|" << setw(18) << left << " Name"
         << "|" << setw(7) << " Age"
         << "|" << setw(11) << " Income"
         << "|" << setw(10) << " PostCode "
         << "|" << setw(7) << " OrderID" << endl;
    cout << "----+------------------+-------+-----------+----------+-------" << endl;
    m_printAll(m_anker);
}

void Tree::m_printAll(TreeNode* node)
{
    printNode(node);
    m_printAll(node->getLeft());
    m_printAll(node->getRight());
}

void Tree::printNode(TreeNode* node)
{
    if (node == nullptr)
        return;
    cout << right << setw(4) << node->getNodeChronologicalID() << "|"
         << setw(18) << node->getName() << "|"
         << setw(7) << node->getAge() << "|"
         << setw(11) << node->getIncome() << "|"
         << setw(10) << node->getPostCode() << "|"
         << setw(7) << node->getNodeOrderID() << endl;
}

void Tree::printPreOrder()
{
    printPreOrderHelper(m_anker);
}


void Tree::printPreOrderHelper(TreeNode* node)
{
    printNode(node);
    printPreOrderHelper(node->getLeft());
    printPreOrderHelper(node->getRight());
}

void Tree::levelOrder()
{
    printLevelOrderHelper(m_anker);
}

void Tree::printLevelOrderHelper(TreeNode* node)
{
    queue<TreeNode *> q1, q2;

    if(m_anker == nullptr)
        return;

    q1.push(m_anker);

    while(!q1.empty() || !q2.empty())
    {
        while(!q1.empty())
        {
            if(q1.front()->getLeft() != nullptr)
                q2.push(q1.front()->getLeft());

            if(q1.front()->getRight() != nullptr)
                q2.push(q1.front()->getRight());

            printNode(q1.front());
            q1.pop();
        }

        while(!q2.empty())
        {
            if(q2.front()->getLeft() != nullptr)
                q1.push(q2.front()->getLeft());

            if(q2.front()->getRight() != nullptr)
                q1.push(q2.front()->getRight());

            printNode(q2.front());
            q2.pop();
        }
    }
}

void Tree::printPostOrder()
{
    printPostOrderHelper(m_anker);
}

void Tree::printPostOrderHelper(TreeNode* node)
{
    printPostOrderHelper(node->getLeft());
    printPostOrderHelper(node->getRight());
    printNode(node);
}

void Tree::printInOrder()
{
    printInOrderHelper(m_anker);
}

void Tree::printInOrderHelper(TreeNode* node)
{
    printInOrderHelper(node->getLeft());
    printNode(node);
    printInOrderHelper(node->getRight());
}