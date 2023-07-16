#include <conio.h>
#include <iostream.h>
#include <process.h>

class TreeOp {
    int a[100], n, i, j, k, l, r;

public:
    void get() {
        cout << "Enter The size: ";
        cin >> n;
        cout << "Enter the Elements: ";
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << "\n";
        for (i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }

    void wunion() {
        cout << "\n Enter the two roots for union:\n";
        cin >> j >> k;
        int temp;
        temp = a[j] + a[k];
        if (a[j] > a[k]) {
            a[j] = k;
            a[k] = temp;
        } else {
            a[k] = j;
            a[j] = temp;
        }
        cout << "\n";
        for (i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }

    void wfind() {
        cout << "\n Enter the element to find root: ";
        cin >> l;
        r = l;
        while (a[r] > 0) {
            r = a[r];
        }
        cout << "Root is: " << r;
        while (l != r) {
            int s = a[l];
            a[l] = r;
            l = s;
        }
    }
};

void main() {
    TreeOp t;
    clrscr();
    t.get();
    int ch;
    while (ch != 3) {
        cout << "\n 1: Weighted Union 2: Collapsing Find 3: Exit ";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                t.wunion();
                break;
            case 2:
                t.wfind();
                break;
            case 3:
                exit(0);
                break;
        }
    }
    getch();
}
