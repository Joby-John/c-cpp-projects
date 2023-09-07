#include<stdio.h>

void main()
{
    int lim,divisor,count, curr_num = 1;
    printf("Enter a limit\n");
    scanf("%d", &lim);
    printf("Prime numbers between 1 and %d = ",lim);

    while(curr_num<=lim)
    {
        divisor = 1;
        count = 0;
        while(divisor<=curr_num)
        {
            if(curr_num%divisor == 0)
            {
                count++;
            }
            if(count>2)
            {
                break;
            }

            divisor++;
        }

        if(count==2)
        {
            printf("%d,", curr_num);
        }
        curr_num++;
       
        
    }

}    