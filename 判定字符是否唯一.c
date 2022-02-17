bool isUnique(char* astr)
{
    char i = 0;

    //字符ASCII吗为0-127,定义长度为128/8=16个字符数组,用每一位来表示是否出现过次字符
    char ret[16] = {0};
    while(astr[i])
    {

        if (ret[astr[i] >> 3]  & 1 <<  (astr[i] & 0x07))
        {
            return false;
        }
        else
        {
            ret[astr[i] >> 3] |= 1 << ( astr[i] & 0x07);
        }
        i++;
    }

    return true;
}