class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0)
            return 0;

        int i = 0, j = n;
        while (j <= h)
        {
            if (equal(haystack.begin() + i, haystack.begin() + j,
                      needle.begin()))
            {
                return i;
            }
            ++i, ++j;
        }
        return -1;
    }
};