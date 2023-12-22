//
// Created by ½ª½Üîü on 2023/11/3.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    int data[10];
    Node* next;
};

class LinkedList {
public:
    Node* head;
    int m;
    int n;

    LinkedList(int m, int n) {
        this->m = m;
        this->n = n;
        head = new Node();
    }

    ~LinkedList() {
        Node* p = head;
        while (p) {
            Node* q = p;
            p = p->next;
            delete q;
        }
    }

    void create(vector<vector<int>>& matrix) {
        Node* cur = head;
        for (int i = 0; i < m; i++) {
            Node* newNode = new Node();
            for (int j = 0; j < n; j++) {
                newNode->data[j] = matrix[i][j];
            }
            cur->next = newNode;
            cur = newNode;
        }
        cur->next = nullptr;
    }

    void join(LinkedList& R, LinkedList& S, int a1, int a2) {
        Node* p = R.head->next;
        Node* q = S.head->next;

        while (p) {
            while (q) {
                if (p->data[a1-1] == q->data[a2-1]) {
                    for (int i = 0; i < R.n; i++) {
                        cout << p->data[i] << " ";
                    }
                    for (int j = 0; j < S.n-1; j++) {
                        cout << q->data[j] << " ";
                    }
                    cout << q->data[S.n - 1]<<endl;
                }
                q = q->next;
            }
            q = S.head->next;
            p = p->next;
        }
    }
};

int main() {
    ifstream ifs("in.txt");
    int m1, n1;
    ifs >> m1 >> n1;

    vector<vector<int>> R(m1, vector<int>(n1));
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            ifs >> R[i][j];
        }
    }

    LinkedList listR(m1, n1);
    listR.create(R);

    int m2, n2;
    ifs >> m2 >> n2;

    vector<vector<int>> S(m2, vector<int>(n2));
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            ifs >> S[i][j];
        }
    }

    LinkedList listS(m2, n2);
    listS.create(S);

    int a1, a2;
    ifs >> a1 >> a2;

    listR.join(listR, listS, a1, a2);

    return 0;
}
