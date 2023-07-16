#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int b[5000];

class heap
{
public:
    void heapsort(int a[], int n);
    void heapify(int a[], int n);
    void adjust(int a[], int i, int n);
};

void heap::heapsort(int a[], int n)
{
    heapify(a, n);
    for (int i = n; i >= 2; i--)
    {
        int t = a[i];
        a[i] = a[1];
        a[1] = t;
        adjust(a, 1, i - 1);
    }
}

void heap::heapify(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        adjust(a, i, n);
    }
}

void heap::adjust(int a[], int i, int n)
{
    int j = 2 * i;
    int item = a[i];
    while (j <= n)
    {
        if ((j < n) && (a[j] > a[j + 1]))
            j = j + 1;
        if (item <= a[j])
            break;
        else
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = item;
}

void main()
{
    clrscr();
    clock_t e, s;
    int n, i;
    heap h;
    cout << "\n Enter Size Of The Array :->";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        if (i % 8 == 0)
            cout << "\n";
        b[i] = random(n);
        cout << "\t" << b[i];
    }
    s = clock();
    h.heapsort(b, n);
    e = clock();
    cout << "\n After Heap Sorting : \n";
    for (i = 1; i <= n; i++)
    {
        if (i % 8 == 0)
            cout << "\n";
        cout << "\t" << b[i];
    }
    cout << "\n\n The Time Complexity Is :=" << ((e - s) / CLK_TCK);
    getch();
}
