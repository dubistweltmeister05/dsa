#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t num= 0xabcdef23;
    
    printf("0x%x\n", num&(0xff<<8));

    return 0;
}
