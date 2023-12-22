//
// Created by 姜杰铧 on 2023/10/19.
//

#ifndef CPP_LINKSTRING_H
#define CPP_LINKSTRING_H
struct LinkNode //链串结点的类型
{
    char data;  //存放一个字符
    LinkNode*next;  //指向下一个结点
    LinkNode():next(nullptr){}
    LinkNode(char d):data(d),next(nullptr){}
};

class LinkString {
public:
    LinkNode*head;
    int length;
    LinkString(){
        head = new LinkNode();
        head->next = nullptr;
        length = 0;
    }
    //仅示例两个函数
    LinkString&InsStr(int i,LinkString &s);//串插入
    bool StrEqual(LinkString&t);//判断链s和t是否相等
};


#endif //CPP_LINKSTRING_H
