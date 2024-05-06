#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode;
    TreeNode* m_left;
    TreeNode* m_right;
public:
    TreeNode(int NodeOrderID, int ChronologicalID, string Name, int Age, double Income, int PostCode)
    : m_NodeOrderID(NodeOrderID), m_NodeChronologicalID(ChronologicalID), m_Name(Name), m_Income(Income), m_PostCode(PostCode){};
    void print();

    int getNodeOrderID() const{return m_NodeOrderID;}
    void setNodeOrderID(int id) {m_NodeOrderID = id;}

    int getNodeChronologicalID() const {return m_NodeChronologicalID;}
    void setNodeChronologicalID(int id) {m_NodeChronologicalID = id;}

    string getName() const {return m_Name;}
    void setName(string name) {m_Name = name;}

    int getAge() const {return m_Age;}
    void setAge(int age) {m_Age = age;}

    double getIncome() const {return m_Income;}
    void setIncome(double income) {m_Income = income;}

    int getPostCode() const {return m_PostCode;}
    void setPostCode(int PostCode) {m_PostCode = PostCode;}

    TreeNode* getLeft() const {return m_left;}
    void setLeft(TreeNode* node) {m_left = node;}

    TreeNode* getRight() const {return m_right;}
    void setRight(TreeNode* node) {m_right = node;}
};
