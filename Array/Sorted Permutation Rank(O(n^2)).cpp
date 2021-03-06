vector<long long> f(int n)
{
    vector<long long>vec;
    vec.push_back(0);
    long long x=1;
    for(int i=1;i<=n;i++)
    {
        x*=i;
        x%=1000003;
        vec.push_back(x);
    }
    return vec;
}

int Solution::findRank(string A) {
    string s=A;
    vector<char>v;
    for(int i=0;i<s.size();i++)
    {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    vector<long long>vec=f(A.size()-1);
    long long c=0;
    long long spaces=A.size()-1;
    
    for(int i=0;i<A.size()-1;i++)
    {
        char ch=A[i];
        long long j=0;
        for(j=0;j<v.size();j++)
        {
            if(v[j]==ch)
            {
                break;
            }
        }
        v.erase(v.begin()+j);
        c+=(j*vec[spaces]);
        c%=1000003;
        spaces--;
    }
    c++;
    c%=1000003;
    return c;
}
//METHOD - 1
//Eg - STRING IS "STRING"
//Sorted order - G, I, N, R, S, T

//Fix S
//S_____
//Before this 4* 5! possible cases are there, where characters are smaller than S
//that are 
//G_____ = 5!
//I_____ = 5!
//N_____ = 5!
//R_____ = 5!
//total = 4*5!

//Fix T
//ST____
//Before this 4*4! possible cases
//SG____
//SI____
//SN____
//SR____
//total = 4*5! + 4*4!

//Fix R
//STR___
//Before this 3*3! possible cases
//STG___
//STI___
//STN___
//total = 4*5! + 4*4! + 3*3!

//Fix I
//STRI__
//Before this 1*2! possible cases, as only G is smaller than I
//STRG__
//total = 4*5! + 4*4! + 3*3! + 1*2!

//FIX N
//STRIN_
//Before this 1*1! cases are possible
//STRIG_
//total = 4*5! + 4*4! + 3*3! + 1*2! + 1


//FIX G, 0 cases possible 


