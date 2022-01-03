#ifndef _CMAP_H_
#define _CMAP_H_

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Node{
public:
    Node(char data = 0){
        m_cData = data;
        m_bVisited = false;
    }

    Node(const Node& node){
        if(this == &node)
            return;
        *this = node;
    }

    Node& operator=(const Node& node){
        if(this == &node)
            return *this;
        this->m_cData = node.m_cData;
        this->m_bVisited = node.m_bVisited;
        return *this;
    }

public:
    char m_cData;   // 数据
    bool m_bVisited;    // 是否访问
};

class Edge{
public:
    Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightvalue = 0):
        m_iNodeIndexA(nodeIndexA),m_iNodeIndexB(nodeIndexB),m_iWeightValue(weightvalue),
        m_bSelected(false){}

    Edge(const Edge& edge){
        if(this == &edge)
            return;
        *this = edge;
    }

    Edge& operator=(const Edge& edge){
        if(this == &edge)
            return *this;
        this->m_iNodeIndexA = edge.m_iNodeIndexA;
        this->m_iNodeIndexB = edge.m_iNodeIndexB;
        this->m_iWeightValue = edge.m_iWeightValue;
        this->m_bSelected = edge.m_bSelected;
        return *this;
    }

public:
    int m_iNodeIndexA; // 头顶点
    int m_iNodeIndexB;  // 尾顶点
    int m_iWeightValue;
    bool m_bSelected;
};

#endif _CMAP_H_