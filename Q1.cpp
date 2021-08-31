#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int op=1;
    while(op<=t)
    {
        int n,i,j;
        cin>>n;
        char arr[n][n];
        int nox, noo, nod;
        int min_req=n+1;
        int possible_sol=0;
        std::vector<int> rem_row;
        std::vector<int> rem_col;
        for(i=0; i<n; i++)
        {
            nox=0;
            nod=0;
            noo=0;
            for(j=0; j<n; j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='O') noo++;
                else if(arr[i][j]=='X') nox++;
                else nod++;
            }
            if(nod>0 && noo==0)
            {
                if(min_req==nod)
                {
                    possible_sol++;
                }
                if(min_req>nod){
                    min_req=nod;
                    possible_sol=1;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            nox=0;
            nod=0;
            noo=0;
            for(j=0; j<n; j++)
            {
                if(arr[j][i]=='O') noo++;
                else if(arr[j][i]=='X') nox++;
                else nod++;
            }
            if(nod>0 && noo==0)
            {
                if(min_req==nod)
                {
                    possible_sol++;
                }
                if(min_req>nod){
                    min_req=nod;
                    possible_sol=1;
                }
                if(nod==1)
                    rem_col.push_back(i);
            }
        }
        if(min_req==n+1)
        {
            cout<<"Case #"<<op<<": Impossible"<<endl;
            op++;
        }
        else{
                //todo brute force
                
            cout<<"Case #"<<op<<": "<<min_req<<" "<<possible_sol<<endl;
            op++;
        }
    }
    return 0;
}
