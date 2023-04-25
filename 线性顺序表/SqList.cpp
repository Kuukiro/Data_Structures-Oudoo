#include "SqList.h"
#include <iostream>

using namespace std;

bool SqList::Init_SqList(int* data, int length)
{
    this->length = length;
    this->data = new int[length];
    for (int i = 0; i < length; i++)
    {
        this->data[i] = data[i];
    }
    return true;
}

void SqList::PrintList()
{
    for (int i = 0; i < this->length; i++)
        cout << this->data[i] << ' ';
    cout << endl;
}

bool SqList::Del_Min(SqList &L, ElemType &e)
{
    if (L.length == 0)
        return false;
    e = L.data[0];
    int loc = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < e)
        {
            e = L.data[i];
            loc = i;
        }
    }
    L.data[loc] = L.data[L.length - 1];
    L.length--;
    return true;
}

void SqList::Reverse(SqList& L)
{
    if (L.length <= 1)
        return;
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length -1 - i];
        L.data[L.length - 1 - i] = temp;
    }
    return;

}

void SqList::Del_Value(SqList& L, ElemType x)
{
    int del_count = 0;
    for (int i = 0; i < L.length; i++)
    {
        
        if (L.data[i] == x)
            // ��¼Ҫɾ��Ԫ�صĸ���
            del_count++;
        else
            // Ҫ�����Ԫ��ǰ�ƣ���ǰ���Ŀ�λ��������Ҫɾ��Ԫ�صĸ���
            L.data[i - del_count] = L.data[i];
    }
    L.length -= del_count;
    return;
}

bool SqList::Del_Seq(SqList& L, ElemType s, ElemType t)
{
    if (L.length == 0 || s >= t)
        return false;

    int del_count = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s)
        {
            if (L.data[i] <= t)
                // ��¼[s, t]�����ڵ�Ԫ�ظ���
                del_count++;
            else
                // ���������У�t,row]��Ԫ��ǰ��
                data[i - del_count] = data[i];
        }
    }
    // ��Ҫ���Ǹı�������
    L.length -= del_count;
    return true;
}

bool SqList::Del_Seq_NoSort(SqList& L, ElemType s, ElemType t)
{
    if (L.length == 0 || s >= t)
        return false;

    int del_count = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
            del_count++;
        else
            L.data[i - del_count] = L.data[i];
    }
    L.length -= del_count;
    return true;
}
