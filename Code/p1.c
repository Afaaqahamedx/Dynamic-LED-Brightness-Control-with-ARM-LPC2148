#include <lpc214x.h>
//#include <stdio.h>
void delay(unsigned int n);

int main(void)
{
    unsigned int result, temp;
    PINSEL1 = 0x00040000; // p0.25   pin is selected as as ad0.4
    IO0DIR = 0x000f0000;

    while (1)
    {
        AD0CR = 0x09200010; // control register for adc     ad.04
        while((temp = AD0GDR) == 0x80000000);
        result = AD0GDR;      // to get the adc values in result
        AD0CR &= ~0x01000000; // to stop the ADC
        result = (result >> 6);
        result = result & 0x000003FF;

        if (result < 0x00CC)  //  <  0.66
        {
            // IOCLR0 = 0x00000000;
            IOSET0 = 0x000F0000;	   	//all led's off
        }

        if (result > 0x00CC && result <= 0x0199)  // from 0.66 to 1.32
        {
            IOCLR0 = 0x00080000;
            IOSET0 = 0x00070000;
            delay(100000);
        }

        else if (result > 0x0199 && result <= 0x0266)	// from 1.32 to 1.98
        {
            IOCLR0 = 0x000C0000;
            IOSET0 = 0x00030000;
            delay(100000);
        }

        else if (result > 0x0266 && result <= 0x0333)	//from 1.98 ro 2.64
        {
            IOCLR0 = 0x000E0000;
            IOSET0 = 0x00010000;
            delay(100000);
        }

        else if(result > 0x0333 && result <= 0x03FF)	 //from 2.64 to 3.3
        {
            IOCLR0 = 0x000F0000;
            IOSET0 = 0x00000000;
            delay(100000);
        }
		
    }
}

void delay(unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++);
}