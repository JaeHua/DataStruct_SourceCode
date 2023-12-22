//
// Created by ½ª½Üîü on 2023/11/1.
//

#include "LabLinkList.h"

void LabLinkList::CreatListR(vector<vector<int>> a) {
    DataNode*r = head->next;
    for(int i = 0; i < head->Row;i++)
    {
        DataNode*newNode = new DataNode();
        for(int j = 0; j < head->Col;j++)
        {
            newNode->data[j] = a[i][j];
        }
        newNode->next = nullptr;
        if(head->next == nullptr) { head->next = newNode; r = newNode;}
        else
        {
            r->next = newNode;
            r = newNode;
        }

    }
    r->next = nullptr;
}

void LabLinkList::disp() {
    DataNode*p = head->next;
    if(p == nullptr)return;
    for(int i = 0; i < head->Row;i++)
    {
        for(int j = 0; j < head->Col;j++)
        {
            cout<<p->data[j]<<" ";
        }
        cout<<endl;
        p = p->next;
    }
}

