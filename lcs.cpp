/*
Tutorial : Tushar roy
Shafayat Ashraf : http://www.shafaetsplanet.com/planetcoding/?p=1862

*/
#include<bits/stdc++.h>
using namespace std;

const int maxc = 1000;
int dp[maxc][maxc];
bool visited[maxc][maxc];
char strA[maxc],strB[maxc];
int lenA;
int lenB; int k=0;
bool flag = 0; char ans[maxc];


int lcs(int i,int j)
{
    if(strA[i] == '\0' || strB[j]=='\0')
        return 0;
    if(visited[i][j]==1)
        return dp[i][j];
    int len=0;
    if(strA[i] == strB[j])
        len = 1+ lcs(i+1,j+1);
    else
    {
        int m = lcs(i+1,j);
        int n = lcs(i,j+1);
        len = max(m,n);
    }
    visited[i][j] = 1;
    dp[i][j] = len;
    return dp[i][j];
}

void print_lcs(int i,int j)
{
    if(strA[i] == '\0' || strB[j]=='\0')
        return ;
    if(strA[i] == strB[j])
    {
        ans[k++] = strA[i];
        print_lcs(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            print_lcs(i+1,j);
        else
            print_lcs(i,j+1);
    }
}
int main()
{

    cout<<"\nPlease enter two strings : ";
    cin>>strA>>strB;
    int l = lcs(0,0);
    print_lcs(0,0);
    cout<<"Longest common String is : "<<ans<<"\nAnd length is : "<<l;
    return 0;
}
