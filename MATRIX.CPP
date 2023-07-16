#include<iostream.h>
#include<conio.h>
#include<time.h>

class mmu1
{
    int a[2][2], b[2][2], c[2][2], p, q, r, s, t, u, v, i, j;

public:
    void get();
    void put();
    void formula();
};

void mmu1::get()
{
    cout << "\nEnter matrix 1: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\nEnter matrix 2: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
    }
}

void mmu1::formula()
{
    p = ((a[0][0] + a[1][1]) * (b[0][0] + b[1][1]));
    q = ((a[1][0] + a[1][1]) * b[0][0]);
    r = (a[0][0] * (b[0][1] - b[1][1]));
    s = (a[1][1] * (b[1][0] - b[0][0]));
    t = ((a[0][0] + a[0][1]) * b[1][1]);
    u = ((a[1][0] - a[0][0]) * (b[0][0] + b[0][1]));
    v = ((a[0][1] - a[1][1]) * (b[1][0] + b[1][1]));

    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;
}

void mmu1::put()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}

void main()
{
    clrscr();
    mmu1 m;
    clock_t e, s;

    m.get();
    s = clock();

    m.formula();
    cout << "\nOutput: " << endl;
    m.put();

    e = clock();
    cout << "\nTime complexity: " << ((e - s) / CLK_TCK);

    getch();
}
