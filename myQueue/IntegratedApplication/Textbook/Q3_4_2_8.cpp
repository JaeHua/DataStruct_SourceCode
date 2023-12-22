//
// Created by 姜杰铧 on 2023/10/19.
//
/**
 * 8.设计一个循环队列QUEUE<T>,用data[O..MaxSize-1]存放队列元素,
 * 用front 和rear分别作为队头和队尾指针,另外用一个标志tag标识队列可能空(false)或可能满(true),
 * 这样加上front==rear可以作为队空或队满的条件。要求设计队列的相关基本运算算法。
 * */

/**
 * 好的,这里是使用数组实现的循环队列的设计:

cpp
template <typename T>
class QUEUE {
private:
    T data[MaxSize];
    int front, rear;
    bool tag;

public:
    QUEUE() {
        front = 0;
        rear = 0;
        tag = false;
    }

    void enqueue(T x) {
        if(front == rear && tag == true) {
            // 队列满
        } else {
            data[rear] = x;
            rear = (rear + 1) % MaxSize;
            if(rear == front) {
                tag = true;
            }
        }
    }

    T dequeue() {
        if(front == rear && tag == false) {
           // 队列空
        } else {
            T x = data[front];
            front = (front + 1) % MaxSize;
            if(front == rear) {
                tag = false;
            }
            return x;
        }
    }
};


主要思路:

- 使用数组data存储元素
- front指向队头,rear指向队尾
- tag表示队列满或空的可能性
- enqueue时rear++并环回,dequeue时front++并环回
- 使用front==rear和tag的组合判断队空和队满

这样就可以实现一个循环队列,队空和队满利用标志tag和指针front/rear的组合来判断。
 *
 * */