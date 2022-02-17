

int removeDuplicates(int* nums, int numsSize)
{

    int c_i = 0;
    int i = 1;
    if (numsSize > 1)
    {
        for (; i<numsSize; i++)
        {
            if(nums[c_i] != nums[i] )
            {
                nums[++c_i] = nums[i];
            }
        }
        
        return c_i+1;
    }
        
    return numsSize;
      
}

