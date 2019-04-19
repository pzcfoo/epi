long long swap_bits(long long x, int i, int j)  
{                     
    short val_i = (x >> i) & 1;                  
    short val_j = (x >> j) & 1;  
    long long mask_i;                
    long long mask_j;                                 
    if (val_i)                      
    {                                                 
        mask_j = 1 << j;                              
        x |= mask_j;                                  
    }                   
    else                
    {                   
        mask_j = ~(1 << j);     
        x &= mask_j;       
    }                      
    if (val_j)             
    {                      
        mask_i = 1 << i;   
        x |= mask_i;       
    }                                                 
    else                
    {                                                 
        mask_i = ~(1 << i);     
        x &= mask_i;       
    }                      
    return x;              
}   
