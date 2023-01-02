class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0, i = 0, len = 0;
        int digitS[10] = {0}, digitG[10] = {0};
        string ret = "";
        
        len = secret.length();
        for (i = 0; i < len; ++i)
        {
            if (secret[i] == guess[i])
                ++A;
            else
            {
                ++digitS[secret[i] - '0'];
                ++digitG[guess[i] - '0'];
            } 
        }
        for (i = 0; i < 10; ++i)
        {
            if (digitS[i] == digitG[i])
                B += digitS[i];
            else if (digitS[i] > 0 && digitG[i] > 0)
                B += (digitS[i] > digitG[i] ? digitG[i] : digitS[i]);
        }
        ret = to_string(A)+"A"+to_string(B)+"B";
        
        return ret;
    }
};