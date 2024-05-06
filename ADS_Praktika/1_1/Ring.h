
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring{

private:
    int m_countNodes = 0;
    RingNode* m_anker = nullptr;

public:
    Ring(){};
    void addNewNode(std::string desc, std::string data);
    bool search(std::string data);
    void print();

    friend RingNode * get_anker(Ring& r);
    friend int get_countNodes(Ring& r);
};
