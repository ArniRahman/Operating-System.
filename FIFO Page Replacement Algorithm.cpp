#include<bits/stdc++.h>
using namespace std;

double rate(double pageFault, double nRef)
{
    return (pageFault*100.00)/nRef;
}

int main()
{
    cout<<"Number of pages: ";
    int nPage;
    cin>>nPage;

    cout<<"Number of Page References: ";
    int nRef;
    cin>>nRef;

    cout<<"Reference: ";
    int Ref[nRef];
    for(int i=0;i<nRef;i++)
        cin>>Ref[i];

    cout<<"Number of Memory Page Frame: ";
    int nPageFrame;
    cin>>nPageFrame;

    int pageFrame[nPageFrame];
    map<int,int> mp;

    for(int i=0;i<nPageFrame;i++)
    {
        pageFrame[i] = -1; //-1 means empty
    }

    int old = 0;
    int pageFault = 0;
    for(int i=0;i<nRef;i++)
    {
        if(mp[Ref[i]]==0)
        {
            mp[pageFrame[old]] = 0;
            pageFrame[old] = Ref[i];
            mp[Ref[i]] = 1;
            old = (old+1)%nPageFrame;
            pageFault++;
        }
    }

    cout<<"Number of page fault using FIFO Page replacement Algorithm: "<<pageFault<<endl;
    cout<<"Page Fault Rate: "<<rate(pageFault,nRef)<<"%"<<endl;

    return 0;
}

/*
8
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*/
