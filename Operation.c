#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h> // Include the necessary header for the bool type
#include <time.h>
#include <string.h>
#include <math.h>
#include"STD_TYPES.h"
#include"Bank_Accountt.h"

// Length of the generated password

u16 Cheak_Number_Of_Digits( u8 * arr)
{
    u8 count=0;
    u8 size=sizeof( arr)/sizeof(u8);
    for(u8 i=0;i<size;i++)
    {
        if(arr[i]!="\0")
        {
            count++;
        }

    }
    return count;
}

 // Length of the generated password



long long Generate_Password() {
    u32 min = 1234;
    u32 max = 9999;

    srand(time(0));

    // Generate random number from min to max
    u32 random = rand() % (max - min + 1) + min;
    random=random*1000000;
   return abs(random);
//    return random;
}

u8 Cheak_Name(u8  *arr)
{
    u8 i=0;
    u8 count=0;
    //adsad adsasd sdad sadas
    while(arr[i]!= '\0')
        {
           // isspace(arr[i])
        //    if(isspace(arr[i]))  // Why detect only 3
        if(arr[i]==' ')
                {
                    count++;
                   arr++;
                }
            else
                {
                   arr++;
                    continue;
                }

        }

    return count;

}



bool hasExactly14Digits(long long number) {
    char numberStr[20]; // At most 19 digits + 1 for null terminator
    int length;

    // Use snprintf to safely convert to a string
    length = snprintf(numberStr, sizeof(numberStr), "%lld", number);

    // Check if the length is exactly 14
    return (length == 14);
}

long long Cheak_National_ID()
{
    long long num ; // Replace with your number
    printf("Please Enter National ID : \n");
    scanf("%lld",&num);
    if (hasExactly14Digits(num)) {
        /*
        *
        */
//        printf("Yes  ID\n");
        return num;
    } else {
        printf("The number does not have exactly 14 digits.\n");
       return Cheak_National_ID();
    }
}

long long Cheak_Guardian_National_ID()
{
    long long num ; // Replace with your number
    printf("Please Enter Your Guardian National ID : \n");
    scanf("%lld",&num);
    if (hasExactly14Digits(num)) {
        /*
         *
         */
        printf("Yes Guardian ID\n");
        return num;
    } else {
        printf("The number does not have exactly 14 digits.\n");
       return  Cheak_Guardian_National_ID();
    }
}






