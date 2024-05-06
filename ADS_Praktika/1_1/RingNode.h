//
// Created by Kawa Akbulut on 22.04.24.
//

#ifndef ADS_PRAKTIKA_RINGNODE_H
#define ADS_PRAKTIKA_RINGNODE_H

#endif //ADS_PRAKTIKA_RINGNODE_H
/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>
#include <iostream>

class RingNode{

private:
    int m_oldAge;
    std::string m_description  = {};
    std::string m_symbolicData = {};
    RingNode* m_next;

public:
    RingNode(){};
    RingNode(int age, std::string desc, std::string data): m_oldAge(age), m_description(desc), m_symbolicData(data){};

    int getOldAge(){return m_oldAge;}
    void setOldAge(int age) {m_oldAge = age;};

    std::string getDescription(){return m_description;}
    void setDescription(std::string desc) {m_description = desc;};

    std::string getSymbolicData(){return m_symbolicData;}
    void setSymbolicData(std::string data){m_symbolicData = data;};

    RingNode* getNext(){return m_next;};
    void setNext(RingNode* n){m_next = n;};
};
