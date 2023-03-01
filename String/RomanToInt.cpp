int convert(char ch)
{
    switch(ch){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            int val1=convert(s[i]);
            if(i+1<s.length())
            {
                int val2=convert(s[i+1]);
                if(val1<val2)
                {
                    sum=sum-val1;
                }
                else{
                    sum+=val1;
                }
            }
            else{
                sum+=val1;
            }
        }
        return sum;
    }