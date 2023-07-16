#include<iostream>
using namespace std;
int quick(int A[],int l,int u)
{
    int loc,right,left,t;
    left=l;
    right=u;
    loc=l;

    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
        {
            right--;
        }
        if(left==right)
            break;
        else
        {
            t=A[loc];
            A[loc]=A[right];
            A[right]=t;
            loc=right;
        }
        while(left<right && A[left] < A[loc])
            left++;
        if(left==right)
            break;
        else
        {
            t=A[left];
            A[left]=A[loc];
            A[loc]=A[left];
            loc=left;
        }
    }
    return loc;
}
void quick_sort(int A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);

    if(l+1<loc)
        quick_sort(A,l,loc-1);
    if(u-1>loc)
        quick_sort(A,loc+1,u);
}
int main()
{
    int i,a[]={88,23,79,56,42,11};
    quick_sort(a,0,5);

    for(i=0;i<=5;i++)
        cout<<a[i]<<" ";
}
