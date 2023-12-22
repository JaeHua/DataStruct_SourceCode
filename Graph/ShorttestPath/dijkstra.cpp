#include <iostream>
#define Max 503
#define INF 0xcffffff

using namespace std;

typedef struct AMGraph {							//����ͼ
    int vex, arc;
    int arcs[Max][Max];								//�ڽӾ���
};

int dis[Max], path[Max];							//dis�������·����Ȩֵ��pathͨ������·����ǰ�����������·��
bool book[Max];										//���ҵ����·����
int n,m;
void Dijkstra(AMGraph &G)							//�Ͻ�˹�����㷨
{
    for (int i = 1; i <= G.vex; i++)
    {
        dis[i] = G.arcs[n][i];						//��ʼ��dis����
        path[i] = dis[i] < INF ? n : -1;			//��ʼ��·������
    }
    book[1] = true;
    dis[1] = 0;										//����ʼ��
    for (int i = 2; i <= G.vex; i++)				//����G.vex-1��
    {
        int mins = INF, u = 1;
        for (int j = 1; j <= G.vex; j++)			//�ҵ���ǰû���뼯�ϵ����·�ĺ�����
        {
            if (!book[j] && mins > dis[j]) {
                mins = dis[j];
                u = j;
            }
        }
        book[u] = true;								//���õ���뼯��
        for (int j = 1; j <= G.vex; j++)			//��������������������·���и��£��ɳڲ�����
        {
            if (!book[j] && dis[j] > dis[u] + G.arcs[u][j]) {
                dis[j] = dis[u] + G.arcs[u][j];		//�������·��ֵ
                path[j] = u;						//�޸�j��ǰ��Ϊu
            }
        }
    }
}

void find(int x)									//�ݹ�������·��
{
    if (path[x] == n) {
        cout << n;
    }
    else {
        find(path[x]);
    }
    cout << " -> " << x;
    return;
}

void putin(AMGraph &G)								//����ͼ
{
    cin >> G.vex >> G.arc;
    cin>>n>>m;
    for (int i = 1; i <= G.vex; i++)				//��ʼ���ڽӾ���
        for (int j = 1; j <= G.vex; j++)
            G.arcs[i][j] = INF;

    for (int i = 1; i <= G.arc; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.arcs[u][v] = w;
    }
}

void putout(AMGraph &G)								//���
{
    //cout << "��� v1 ����������·��Ϊ: \n";
    for (int i = 1; i < G.vex; i++)
    {
        cout << dis[i] << " ";
    }
    cout << dis[G.vex] << endl;
    for (int i = 2; i <= G.vex; i++)
    {
        cout << "��� v1 �� v" << i << " ��·��Ϊ�� ";
        find(i);
        cout << endl;
    }
}

int main()
{
    AMGraph G;
    putin(G);
    Dijkstra(G);
    putout(G);
//    cout<<dis[m]<<endl;
    return 0;
}
/*
7 12 1 7
1 2 4
1 3 6
1 4 6
2 5 7
2 3 1
3 5 6
3 6 4
4 3 2
4 6 5
5 7 6
6 5 1
6 7 8
*/
