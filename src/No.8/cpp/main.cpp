#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long ret = 0;
        bool valued = false;
        bool fu = false;
        int st = 0;
        for(int i=0; i < s.length(); i++)
        {
            if (valued) {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    ret = 10*ret + s[i] - '0';
                    if (ret > 0)
                        st++;
                    if (st > 10)
                        break;
                }
                else
                {
                    break;
                }      
            }
            else
            {
                if (s[i] == ' ')
                    continue;
                else if (s[i] == '-'){
                    valued = true;
                    fu = true;
                }
                else if (s[i] == '+'){
                    valued = true;
                }
                else if (s[i] >= '0' && s[i] <= '9') {
                    valued = true;
                    ret = 10*ret + s[i] - '0';
                    if (ret > 0)
                        st++;
                }
                else
                {
                    break;
                }
            }
        }
        if (fu) {
            ret = -ret;
            if (ret < INT32_MIN)
                ret = INT32_MIN;
        } 
        else {
            if (ret > INT32_MAX)
                ret = INT32_MAX;
        }
        return (int)ret;
    }
};

int main()
{
    Solution aa;
    string a = "asdf df 234234";
    int r = aa.myAtoi(a);
    printf("a=%s, r=%d\n", a.c_str(), r);
    a = " -234234";
    r = aa.myAtoi(a);
    printf("a=%s, r=%d\n", a.c_str(), r);
    a = "  - 234234";
    r = aa.myAtoi(a);
    printf("a=%s, r=%d\n", a.c_str(), r);
    a = " -0234234";
    r = aa.myAtoi(a);
    printf("a=%s, r=%d\n", a.c_str(), r);
    a = " 0234234";
    r = aa.myAtoi(a);
    printf("a=%s, r=%d\n", a.c_str(), r);
}