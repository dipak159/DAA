#include<iostream>
#include<conio.h>
using namespace std;
class all
{
    int s[10][10],a[10][10],i,j,k,n,m;
    public:
    void get();
    int min(int,int);
    void find();
    void display();
};
int all::min(int m,int n)
{
    return(m<n ?m:n);
}
void all::get()
{
    cout<<"\n Enter the size of element :- \n";
    cin>>n;
    cout<<"\nEnter the element in array :- \n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==-1)
            {
                s[i][j]=9999;
            }
            else
            {
                s[i][j]=a[i][j];
            }
        }
    }
}
void all::find()
{
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=n;k++)
    {
        if(i==j)
        {
            s[i][j]=0;
        }
        else
            s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
        if(s[i][j]>=9999)
            s[i][j]=0;
    }
}
void all::display()
{
        cout<<"\n display the element after perform operation find :- \n";
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<s[i][j]<<"\t";
            cout<<endl;
        }
}
int main()
{
all a;
a.get();
a.find();
a.display();
getch();
}
