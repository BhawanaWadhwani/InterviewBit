// [ F1 F2 ] * Transition Matrix = [F2 F3]

// [ F1 F2 ] * [ P Q ] = [F2 F3]
//             [ R S ]

// F1 * P + F2 * R = F2
// F1 * Q + F2 * S = F3 (F1 + F2)

//we get P=0 && R=1
//and Q=1 && S=1

// [ F1 F2 ] * [ 0 1 ] = [F2 F3]
//             [ 1 1 ]

// [ F1 F2 ] * [ 0 1 ] ^ (n-1) = [Fn Fn+1]
//             [ 1 1 ]
#define ll long long
#define mod 1000000007
ll Identity_Matrix[3][3]; //1 based indexing
ll Transition_Matrix[3][3];

void mul(ll A[3][3], ll B[3][3], ll dimension)
{
    ll ans[dimension+1][dimension+1];
    
    for(int i=1;i<=dimension;i++)
    {
        for(int j=1;j<=dimension;j++)
        {
            ans[i][j]=0;
            for(int k=1;k<=dimension;k++)
            {
                ans[i][j]+=((A[i][k]*B[k][j])%mod);
            }
        }
    }
    
    for(int i=1;i<=dimension;i++)
    {
        for(int j=1;j<=dimension;j++)
        {
            A[i][j]=ans[i][j];
        }
    }

}
int Solution::solve(int A) 
{
    
    if(A<=2)
    return 1;
    
    Identity_Matrix[1][1]=Identity_Matrix[2][2]=1;
    Identity_Matrix[1][2]=Identity_Matrix[2][1]=0;
    
    Transition_Matrix[1][1]=0;
    Transition_Matrix[1][2]=Transition_Matrix[2][1]=Transition_Matrix[2][2]=1;
    
    A--;
    while(A)
    {
        if(A%2==1)
        {
            mul(Identity_Matrix, Transition_Matrix, 2);
            A--;
        }
        else
        {
            mul(Transition_Matrix, Transition_Matrix, 2);
            A/=2;
        }
    }
    // F1 * I[1][1] + F2 * I[2][1] ...here F1 = F2 =1
    ll x=(Identity_Matrix[1][1]+Identity_Matrix[2][1])%mod;
    return x;
}
