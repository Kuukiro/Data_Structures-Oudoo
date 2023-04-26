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
            // 记录要删除元素的个数
            del_count++;
        else
            // 要保存的元素前移，其前方的空位置数就是要删除元素的个数
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
                // 记录[s, t]区间内的元素个数
                del_count++;
            else
                // 将有序序列（t,row]的元素前移
                data[i - del_count] = data[i];
        }
    }
    // 不要忘记改表长！！！
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

void SqList::Del_Same(SqList& L)
{
    // 顺序表删除值问题，就是遍历每个元素，做两类操作，前移 n 个位置或不变，重点讨论 n 的变化
    //int same_count = 1;
    //for (int i = 1; i < L.length; i++)
    //{
    //    // 检测当前元素与不重复有序序列中的最后一个元素是否相等（重复元素连在一起，只可能和最后一个元素相等）
    //    if (L.data[i] == L.data[i - same_count])
    //        // 检测到重复元素，默认有一个元素
    //        same_count++;
    //    else
    //        // 前移count - 1位，保留一个不重复元素
    //        L.data[i - same_count + 1] = L.data[i];
    //}
    //L.length -= same_count - 1;
    //return;

    // 直接插入算法思想
    int i = 0, j = 1;
    for (; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    }
    L.length = i + 1;
    return;
}

bool SqList::Merge(SqList L1, SqList L2, SqList& L_res)
{
    if (L1.length == 0 && L2.length == 0)
        return false;

    int p1 = 0, p2 = 0, res = 0;
    L_res.data = new int[L1.length + L2.length];
    while (p1 < L1.length && p2 < L2.length)
    {
        // 归并排序，插入较小的元素到新表
        if (L1.data[p1] < L2.data[p2])
            L_res.data[res++] = L1.data[p1++];
        else
            L_res.data[res++] = L2.data[p2++];
    }
    // 插入较长表中剩下的元素
    while (p1 < L1.length)
        L_res.data[res++] = L1.data[p1++];
    while (p2 < L2.length)
        L_res.data[res++] = L2.data[p2++];
    L_res.length = res;
    return true;
}

bool Reverse_Pos(SqList& L, int left, int right)
{
    // 按位置逆序
    if (left >= right && right >= L.length)
        return false;
    int mid = (left + right) / 2;
    while (left <= mid)
    {
        ElemType temp = L.data[left];
        L.data[left++] = L.data[right];
        L.data[right--] = temp;
    }
    return true;
}

bool SqList::Exchange(SqList& L, int m, int n)
{
    Reverse_Pos(L, 0, m + n - 1);
    Reverse_Pos(L, 0, n - 1);
    Reverse_Pos(L, n, m + n - 1);
    return true;
}

void SqList::Find_x(SqList& L, ElemType x)
{
    // 顺序查找
    /*for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            ElemType temp = L.data[i];
            L.data[i] = L.data[i + 1];
            L.data[i + 1] = temp;
            break;
        }
        else if (L.data[i] > x)
        {
            L.length++;
            for (int j = L.length - 1; j > i; j--)
                L.data[j] = L.data[j - 1];
            L.data[i] = x;
            break;
        }
    }
    return;*/
    // 折半查找
    int low = 0, high = L.length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > L.data[mid])
            low = mid + 1;
        else if (x < L.data[mid])
            high = mid - 1;
        else if (x == L.data[mid])
        {
            ElemType temp = L.data[mid];
            L.data[mid] = L.data[mid + 1];
            L.data[mid + 1] = temp;
            return;
        }
    }
    // 折半查找结束，low指向值大于x的位置，此处为插入位置！
    L.length++;
    for (int i = L.length - 1; i > low; i--)
        L.data[i] = L.data[i - 1];
    L.data[low] = x;
    return;
}

// 效果等同于Reverse_Pos()
bool Reverse_arr(int R[], int low, int high)
{
    int mid = (low + high) / 2;
    while (low <= mid)
    {
        ElemType temp = R[low];
        R[low++] = R[high];
        R[high--] = temp;
    }
    return true;
}

void SqList::LMove(int R[], int n, int p)
{
    Reverse_arr(R, 0, n - 1);
    Reverse_arr(R, 0, n - p - 1);
    Reverse_arr(R, n - p, n - 1);
}
