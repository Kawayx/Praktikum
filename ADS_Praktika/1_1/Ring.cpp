
// Ring .cpp
#include "Ring.h"
#include <iostream>

void Ring::addNewNode(std::string desc, std::string data)
{
    RingNode* neuerKnoten = new RingNode(0, desc, data);
    //Falls die Liste leer ist

    if(m_anker==nullptr)
    {
        m_anker = neuerKnoten;
        neuerKnoten->setNext(neuerKnoten);
        m_countNodes++;
        return;
    }

    // Falls die list voll ist

    if(m_countNodes == 6)
    {
        neuerKnoten->setNext(m_anker->getNext()->getNext());
        RingNode* ptr = neuerKnoten;
        do
        {
            ptr = ptr->getNext();
            ptr->setOldAge(ptr->getOldAge()+1);
        } while (ptr != m_anker);
        delete m_anker->getNext();
        m_anker->setNext(neuerKnoten);
        m_anker = neuerKnoten;
        return;
    }

    //Falls liste weder voll, noch leer ist

    neuerKnoten->setNext(m_anker->getNext());
    RingNode* ptr = neuerKnoten;
    do
    {
        ptr = ptr->getNext();
        ptr->setOldAge(ptr->getOldAge()+1);
    } while (ptr != m_anker);
    ptr->setNext(neuerKnoten);
    m_anker = neuerKnoten;
    m_countNodes++;
    return;
}


bool Ring::search(std::string data)
{
    if(m_anker == nullptr)
    {
        return false;
    }

    RingNode* ptr = m_anker;
    do
    {
        if(ptr->getSymbolicData() == data)
        {
            std::cout << "+ Gefunden in Backup: "
                      << "Alter: "<< ptr->getOldAge()
                      << ", Beschreibung: "<< ptr->getDescription()
                      << ", Daten: "<< ptr->getSymbolicData()<<std::endl;
            return true;
        }
        ptr = ptr->getNext();
    }while(ptr != m_anker);
    return false;
}

void Ring::print()
{
    if(m_anker == nullptr)
    {
        return;
    }
    RingNode* ptr = m_anker;
    std::cout << "Alter: "<< ptr->getOldAge()
              << ", Beschreibung: "<< ptr->getDescription()
              << ", Daten: "<< ptr->getSymbolicData()<<std::endl;
    for(int i=0;i<m_countNodes-1;i++)
    {
        for(int k=0;k<m_countNodes-i-1;k++)
            ptr=ptr->getNext();
        std::cout << "--------------------------"<<std::endl
                  << "Alter: "<< ptr->getOldAge()
                  << ", Beschreibung: "<< ptr->getDescription()
                  << ", Daten: "<< ptr->getSymbolicData()<<std::endl;
        ptr=m_anker;
    }

}