/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

void TreeNode::print()
{
    cout << "Name: " << m_Name << ", Age: " << m_Age << ", Income: " << m_Income << ", PostCode: " << m_PostCode << endl;
}
