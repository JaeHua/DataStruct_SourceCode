#define NULLKEY -1
#define MAXM 100
template<class T>
struct HNode
{
    int key;
    T value;
    HNode():key(NULLKEY){}
    HNode(int k,T v)
    {
        key = k;
        value = v;
    }
};

template<class T>
class HashTable
{
public:
    int n;  //元素个数
    int m; //哈希表长度
    int p; //
    HNode<T>ha[MAXM];
    HashTable(int m,int p)
    {
        this->m = m;
        this->p = p;
        for(int i = 0; i < m;i++)
            ha[i].key = NULLKEY;
        n = 0;
    }
    void insert(int k,int v)
    {
        int d = k % d;
        while (ha[d].key!=NULLKEY)
            d = (d + 1)%m;
        ha[d] = HNode<T>(k,v);
        n++;
    }
    int search(int k)
    {
        int d = k % p;
        while (ha[d].key!=NULLKEY&&ha[d].key!=k)
            d = (d + 1)%m;
        if(ha[d].key == k)
            return d;
        else
            return -1;
    }
};