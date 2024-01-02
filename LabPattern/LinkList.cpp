//
// Created by jjh on 2024/1/2.
//
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* nxt;
    Node() { nxt = nullptr; }
    Node(int d) { data = d; nxt = nullptr; }
};
class Link
{
public:
    Node* head;
    Link() { head = new Node(); }
    void buildHead(vector<int>v)
    {
        int len = v.size();

        for (int i = 0; i < len; i++)
        {
            Node* s = new Node(v[i]);
            s->nxt = head->nxt;
            head->nxt = s;
        }
    }
    void buildTail(vector<int>v)
    {
        int len = v.size();
        Node * r = head;
        for (int i = 0; i < len; i++)
        {
            Node* s = new Node(v[i]);
            r->nxt = s;
            r = s;
        }
        r->nxt = nullptr;
    }
    void dispList()
    {
        Node* p = head->nxt;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->nxt;
        }
        cout << endl;
    }
};
vector<int>v1, v2;
int main() {
    int i = 0, value = 0;
    while (cin >>value)
    {
        v1.push_back(value);
        if (cin.get() == '\n')break;
    }
    Link mylink;
    mylink.buildHead(v1);
    mylink.dispList();
    while (cin >> value)
    {
        v2.push_back(value);
        if (cin.get() == '\n')break;
    }
    Link mylink1;
    mylink.buildTail(v2);
    mylink.dispList();
    return 0;
}