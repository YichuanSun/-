#include <bits/stdc++.h>
#define MAX_E 1005
#define N 1005
using namespace std;

int parent[N];
struct edge {int u,v,cost;};
int V,E;        //�������ͱ���
edge es[MAX_E];

void UFset();       //���鼯��ʼ������
int Find(int x);    //���Һ���
void Union(int R1,int R2);      //��R1��R2���ڼ��Ϻϲ�
bool same(int a,int b);         //�ж�a��b�Ƿ���ͬһ��������
bool cmp(edge e1,edge e2)   { return e1.cost<e2.cost;}
int kruskal()   {
    sort(es,es+E,cmp);
    UFset();
    int res=0;
    for (int i=0;i<E;i++)   {
        if (!same(es[i].u,es[i].v)) {
            Union(es[i].u,es[i].v);
            res+=es[i].cost;
        }
    }
    return res;
}

int main()  {
    return 0;
}

//��ʼ��
void UFset()    {
    for (int i=0;i<n;i++)   parent[i]=-1;
}

//���Ҳ����ؽڵ�x�������ϵĸ��ڵ�
int Find(int x)     {
    int s;
    for (s=x;parent[s]>=0;s=parent[s]);     //��ͣѭ��ֱ���ҵ����ϵĸ��ڵ�s
    while (s!=x)    {                       //·��ѹ������·���ϵ����нڵ�ĸ��ڵ�ȫ����Ϊs
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

// R1��R2������Ԫ�أ�����������ͬ�ļ��ϣ����ںϲ�����������
void Union(int R1,int R2)   {
    int r1=Find(R1),r2=Find(R2);    //r1��R1�ĸ��ڵ㣬r2��R2�ĸ��ڵ�
    int tmp=parent[r1]+parent[r2];  //-tmp�Ǻϲ���ļ��ϵĽڵ���
    if (parent[r1]>parent[r2])  {   //�����Ǹ��ģ����r1����Ԫ������r2����Ԫ��
        parent[r1]=r2;              //��r1�ϲ���r2��
        parent[r2]=tmp;             //�¼���Ԫ��Ϊ-tmp
    }
    else {                          //����ͬ��
        parent[r2]=r1;
        parent[r1]=tmp;
    }
}

bool same(int a,int b)  {
    if (Find(a)==Find(b))   return true;
    return false;
}
