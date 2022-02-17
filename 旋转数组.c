void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;    
    if((numsSize > 1) && ( k != 0))
    {
        int temp_i = numsSize - 1;
        int c_i = temp_i;
        int temp = nums[c_i];
        int n_i = c_i - k;

        for(int i=0; i < numsSize; i++)
        {
            n_i = (n_i + numsSize) % numsSize;
            if(n_i == temp_i)
            {
                nums[c_i] = temp;
                temp_i = temp_i-1;
                c_i = temp_i;
                temp = nums[c_i];
                n_i = c_i - k;
            }
            else
            {
                nums[c_i] = nums[n_i];
                c_i = n_i;
                n_i -= k;
            }
        }
    }
}