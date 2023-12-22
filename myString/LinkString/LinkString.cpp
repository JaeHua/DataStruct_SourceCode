//
// Created by 姜杰铧 on 2023/10/19.
//

#include "LinkString.h"

LinkString &LinkString::InsStr(int i, LinkString &s) {
    // 检查插入位置的合法性
    if(i < 0 || i > length)
        return *this;

    // 找到插入位置的前一个结点
    LinkNode *p = head;
    for(int j = 0; j < i; j++) {
        p = p->next;
    }
    LinkNode*r = p->next;//保存i出结点
    // 插入结点
    LinkNode *q = s.head->next; // 待插入的字符串首节点
    while(q != nullptr) {
        LinkNode *tmp = new LinkNode(q->data);
        tmp->next = p->next;
        p->next = tmp;
        p = tmp;
        q = q->next;
    }
    // 将原位置i处结点重新接回
    LinkNode* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = r;
    // 更新长度
    length += s.length;
    //返回的是对象
    return *this;
}

bool LinkString::StrEqual(LinkString &t) {
    if(length!=t.length)return false;
    LinkNode*p = head->next;
    LinkNode*q = t.head->next;
    while(p!= nullptr&&q!= nullptr)
    {
        if(p->data!=q->data)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}