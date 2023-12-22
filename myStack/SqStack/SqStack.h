
//
// Created by 刘禧 on 2023/9/28.
//


//顺序栈类
#define MaxSize 1005
template<typename T>
class SqStack
{
public:
    T*data; //存放栈中的元素
    int top;    //栈顶指针
    SqStack()
    {
        data = new T[MaxSize];  //为data分配容量为MaxSize的空间
        top = -1;               //栈顶指针初始化
    }
    ~SqStack()              //析构函数
    {
        delete [] data;//释放data指向的空间
    }
    bool empty();   //判断栈是否为空
    bool push(T e); //进栈
    bool pop(T &e); //出栈
    bool getTop(T&e);//取栈顶元素
};
