#include<iostream>
using namespace std;
class Queue
{
    int q[30];
    int r,f;
public:
    Queue(){r=f=-1;}
    void enqueue(int temp);
    int dequeue();
    int isempty();
    int isfull();
    void display();
};
int Queue::isempty()
{
    if(f==r)
        return 1;
    else
        return 0;
}
int Queue :: isfull()
{
    if(r==30)
        return 1;
    else
        return 0;
}
void Queue::enqueue(int temp)
{
    if(isfull())
    {
        cout<<"Queue full"<<endl;
    }
    else
    {
        r=r+1;
        q[r]=temp;
    }
}
int Queue:: dequeue()
{
    if(isempty())
    {
        cout<<endl<<"Queue Empty"<<endl;
        return -10;
    }
    else
    {
        f=f+1;
        return q[f];
    }
}
void Queue::display()
{
    for (int i=f+1;i<=r;i++)
        cout<<q[i];
}

int bfs(int image[7][7],int image1[7][7])
{
    static int flag=2;
    Queue a,b;
    int end=1;
    int c=0,d=0;
    for (int i=0;i<7;i++)
    {
        for (int j=0;j<7;j++)
        {
            if (image[i][j]==1 && image1[i][j]==0)
            {
                a.enqueue(i);
                b.enqueue(j);
                end=0;
                goto L1;
            }
        }
    }
    L1:
    if (end)
    {
        for(int i=0;i<7;i++)
        {
            for (int j=0;j<7;j++)
            {
                cout<<image1[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return 1;
    }
    while(!a.isempty())
    {
        c=a.dequeue();
        d=b.dequeue();
        image1[c][d]=flag;
        cout<<"start "<<c<<d<<endl;
        cout<<endl;
        if (d!=6 )
        {
            if (image[c-1][d]==1 && image1[c-1][d]==0 )
            {
                image1[c-1][d]=flag;
                a.enqueue(c-1);
                b.enqueue(d);
                cout<<"1 "<<c<<d+1<<endl;
            }
        }
        if (d!=6)
        {
            if (image[c][d+1]==1 && image1[c][d+1]==0)
            {
                image1[c][d+1]=flag;
                a.enqueue(c);
                b.enqueue(d+1);
                cout<<"2 "<<c+1<<d-1<<endl;
            }
        }
        if (c!=6)
        {
            if (image[c+1][d]==1 && image1[c+1][d]==0 )
            {
                image1[c+1][d]=flag;
                a.enqueue(c+1);
                b.enqueue(d);
                cout<<"3 "<<c+1<<d<<endl;
            }
        }
        if (d!=0)
        {
            if (image[c][d-1]==1 && image1[c][d-1]==0)
            {
                image1[c][d-1]=flag;
                a.enqueue(c);
                b.enqueue(d-1);
                cout<<"4 "<<c+1<<d+1<<endl;
            }
        }
    }
    flag++;     
    bfs(image,image1);
}
int main()
{
    int image[7][7]={{0,0,1,0,0,0,0},{0,0,1,1,0,0,0},{0,0,0,0,1,0,0},{0,0,0,1,1,0,0},{0,1,0,0,1,0,1},{1,1,1,0,0,0,1},{1,1,1,0,0,1,1}};
    int image1[7][7]={0};
    int image2[7][7]={{0,0,1,1,1,0,0},{0,1,1,1,1,0,0},{0,1,0,1,0,0,0},{0,1,0,1,0,0,0},{0,1,1,1,0,0,0},{0,0,0,0,0,0,0}};
    {
        for(int i=0;i<7;i++)
        {
            for (int j=0;j<7;j++)
            {
                cout<<image[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        
    }
    bfs(image,image1);
}