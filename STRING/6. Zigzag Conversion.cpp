class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res = "";
        int n = s.size();
        for (int i = 0; i < numRows; ++i)
        {
            int idx = i;
            int deltaBelow = 2 * (numRows - 1 - i);
            int deltaUp = 2 * i;

            bool down = true;

            while (idx < n)
            {
                res += s[idx];

                if (i == 0)
                {
                    idx += deltaBelow;
                }
                else if (i == numRows - 1)
                {
                    idx += deltaUp;
                }
                else
                {
                    if (down)
                    {
                        idx += deltaBelow;
                    }
                    else
                    {
                        idx += deltaUp;
                    }
                    down = !down;
                }
            }
        }
        return res;
    }
};