int Solution::seats(string A)
{
    //the people would be towards the median only.. If the median is on right side, that is
    //more number of people are on right side, we will move towards the right side.
    //and vice versa.

    //Therefore we find the more populated are or median

    vector<int> middle;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 'x')
        {
            middle.push_back(i);
        }
    }
    if (middle.size() < 2)
        return 0;

    if (middle.size() % 2 == 0)
    {
        int mid1 = (middle.size() - 1) / 2; // 6 = 5/2 = 2   and 7 = 6/2 = 3
        int mid2 = (middle.size() + 1) / 2; // 6 = 7/2 = 3   and 7 = 8/2 = 4

        //even check both...odd check one

        long long f = 0, s = 0;
        int mid1_first = middle[mid1] - 1;
        int mid1_second = middle[mid1] + 1;
        //cout<<middle.size()<<" "<<mid1<<" "<<mid2<<'\n';
        for (int i = (middle.size() - 1) / 2 - 1; i >= 0; i--)
        {
            f += (mid1_first - middle[i]);
            f %= 10000003;
            mid1_first--;
        }
        for (int i = (middle.size() - 1) / 2 + 1; i < middle.size(); i++)
        {
            f += (middle[i] - mid1_second);
            f %= 10000003;
            mid1_second++;
        }

        mid1_first = middle[mid2] - 1;
        mid1_second = middle[mid2] + 1;

        for (int i = (middle.size() + 1) / 2 - 1; i >= 0; i--)
        {
            s += (mid1_first - middle[i]);
            mid1_first--;
            s %= 10000003;
        }
        for (int i = (middle.size() + 1) / 2 + 1; i < middle.size(); i++)
        {
            s += (middle[i] - mid1_second);
            mid1_second++;
            s %= 10000003;
        }
        return min(f, s);
    }
    else  //not necessary we'll get optimal output using only 1 also
    {
        int mid1 = (middle.size() - 1) / 2;
        long long f = 0, s = 0;
        int mid1_first = middle[mid1] - 1;
        int mid1_second = middle[mid1] + 1;
        //cout<<middle.size()<<" "<<mid1<<" "<<mid2<<'\n';
        for (int i = (middle.size() - 1) / 2 - 1; i >= 0; i--)
        {
            f += (mid1_first - middle[i]);
            f %= 10000003;
            mid1_first--;
        }
        for (int i = (middle.size() - 1) / 2 + 1; i < middle.size(); i++)
        {
            f += (middle[i] - mid1_second);
            f %= 10000003;
            mid1_second++;
        }
        return f;
    }

    return 0;
}
