int strStr(char * haystack, char * needle)
{
    int h_i = 0;
    int n_i = 0;
	int ret = -1;


    if(needle[0] == '\0')
    {
        return 0;
    }

    while(haystack[h_i] != '\0')
    {
        if(haystack[h_i] == needle[n_i])
        {

			if(n_i == 0)
			{
				ret = h_i;
			}

            n_i++;

            if (needle[n_i] == '\0')
            {
                return ret;
            }

        }
        else
        {
			if(n_i != 0)
			{
				h_i = ret;
			}
            n_i = 0;
			
        }

        h_i++;
    }

    return -1;
}