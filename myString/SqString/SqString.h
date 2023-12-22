//
// Created by 姜杰铧 on 2023/10/19.
//

#ifndef CPP_SQSTRING_H
#define CPP_SQSTRING_H
const int MaxSize = 100;    //字符串的最大长度
class SqString {    //顺序串类
public:
    char *data; //存放串中的元素
    int length; //串的长度
    SqString();
    ~SqString();
    void StrAssign(SqString &s,char *str);//由一个字符串创建一个串
    void DestroyStr(SqString &s);
    bool StrEqual(SqString t);//判断串相等·
    void StrCopy(SqString t); //串复制
    int StrLength();    //获取串长
    bool getI(int i, char& ch);   //返回序列号为i的字符
    bool setI(int i,char ch);   //设置序列号为i的字符
    SqString Concat(SqString s,SqString t);//字符串拼接
    SqString SubStr(SqString s, int i, int j);  //求子串，返回串中从第i个字符开始的j
    SqString InsStr(SqString s1, int i, SqString s2);//串插入
    SqString DelStr(SqString s, int i, int j);//串删除，删除当前串中从第i个字符开始的j个字符
    SqString RepStr(SqString s,int i,int j,SqString t);//串替代，用串t替代从当前串中第i个字符开始的j个字符后的结果
    void DispStr();//输出字符串
    int Strcmp(SqString s,SqString t);
};


#endif //CPP_SQSTRING_H
