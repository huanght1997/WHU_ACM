#include<iostream>
#include<map>
using namespace std;

map<int,int> mp;
int xay=0,amr=0;
int desk[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        mp.clear();
        xay=0;amr=0;

        for(int i=1;i<=n;i++)
        {
            cin>>desk[i];

            if(mp[desk[i]]>0)
            {
                int inc=0;
                for(int j=mp[desk[i]];j<=i;j++)
                {
                    if(desk[j]>0)inc++;
                    mp[desk[j]]=0;
                    desk[j]=0;
                }
                if(i%2)xay+=inc;
                else amr+=inc;
            }
            else mp[desk[i]]=i;
        }
        //cout<<"xay="<<xay<<endl<<"amr="<<amr<<endl;
        if(xay>amr)cout<<"xay"<<endl;
        else cout<<"amr"<<endl;
    }
}
