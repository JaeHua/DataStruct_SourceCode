//
// Created by 姜杰铧 on 2023/10/18.
//
/**2.假设有一个链栈st,设计一个算法,出栈从栈顶开始的第k个结点。*/

/** 貌似很简单，摘录自Claude答案
typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

int popKth(Stack* st, int k) {
    Node* p = st->top;
    for(int i = 0; i < k-1; i++) {
        p = p->next;
    }

    Node* t = p;
    int val = t->val;

    if(p->next == NULL) {
        st->top = NULL;
    } else {
        Node* s = t->next;
        st->top = s;
        free(t);
    }

    return val;
}
*/