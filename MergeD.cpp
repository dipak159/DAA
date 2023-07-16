#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int n;

class Merge {
    int a[1000];
    int i, j;

public:
    void read();
    void merge_sort(int l, int h);
    void merge1(int l, int m, int h);
    void disp();
};

void Merge::read() {
    for (i = 0; i < n; i++) {
        a[i] = random(20000);
    }
}

void Merge::merge_sort(int l, int h) {
    int m1;
    if (l < h) {
        m1 = int((l + h) / 2);
        merge_sort(l, m1);
        merge_sort(m1 + 1, h);
        merge1(l, m1, h);
    }
}

void Merge::merge1(int l, int m, int h) {
    int h1 = l;
    int b[1800];
    i = l;
    j = m + 1;
    while ((h1 <= m) && (j <= h)) {
        if (a[h1] >= a[j]) {
            b[i] = a[h1];
            i++;
            h1++;
        } else {
            b[i] = a[j];
            i++;
            j++;
        }
    }
    if (h1 <= m) {
        while (h1 <= m) {
            b[i] = a[h1];
            i++;
            h1++;
        }
    } else {
        while (j <= h) {
            b[i] = a[j];
            i++;
            j++;
        }
    }
    for (int k = l; k <= h; k++)
        a[k] = b[k];
}

void Merge::disp() {
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
        if ((i + 1) % 9 == 0)
            cout << endl;
    }
}

void main() {
    clrscr();
    randomize();
    clock_t s, e;
    int l, h;
    Merge m;
    cout << "Program For Descending Merge Sort ....\n\n";
    cout << "Enter the Element:";
    cin >> n;
    h = n - 1;
    l = 0;
    m.read();
    cout << "\n\nDisplay the ArrayElement=\n\n";
    m.disp();
    s = clock();
    m.merge_sort(l, h);
    e = clock();
    cout << "\nAfter Sorting=\n";
    m.disp();
    cout << "\nTime Com.= " << ((e - s) / CLK_TCK);
    getch();
}
