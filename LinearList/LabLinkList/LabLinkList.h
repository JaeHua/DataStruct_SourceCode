//
// Created by ½ª½Üîü on 2023/11/1.
//

#ifndef CPP_LABLINKLIST_H
#define CPP_LABLINKLIST_H
#include <iostream>
#include <vector>
using namespace std;
#define MaxCol 15
struct DataNode
{
    int data[MaxCol];
    DataNode*next;
};
struct HNode
{
    int Row,Col;
    DataNode*next;
    HNode():next(nullptr){}
    HNode(int r,int c)
    {
        Row = r;
        Col = c;
        next = nullptr;
    }
};
class LabLinkList {
public:
    HNode* head;//Í·Ö¸Õë
    LabLinkList()
    {
        head = new HNode();
    }
    LabLinkList(int r,int c)
    {
        head = new HNode(r,c);
    }
    void CreatListR(vector<vector<int>>a);
    void disp();
    ~LabLinkList()
    {

    }
};


#endif //CPP_LABLINKLIST_H
