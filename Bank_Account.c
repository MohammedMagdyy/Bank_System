#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include<stdint.h>
#include"Bank_Accountt.h"

struct Clients_Linked_List * headptr=NULL;
u8 NameArr[30]="Alo";

/*
 * ADMINS DATA
 */
struct Bank_Account_Data Admins[2]={{"Mohammed Magdy Mahrous Morsy",2777,0000},
        {"Mohammed Ahmed Mohammed Fahmy",1234,1111}
};

//Generate Account

struct Clients_Linked_List New_Account ;

void IntroPage()
{
    printf("********************************************************************************\n");
    printf("\t\t\tWelcome To IMT Bank System\n");
    printf("********************************************************************************\n");

    //system("color B ");
    printf("Account Type :  \n");
    printf("1- Admin Window. \n");
    printf("2- Client Window. \n");
    printf("\n");
    printf("Enter Your Choice .... \n");

    u8 user;
    scanf("%d",&user);
    do {
        if ( user == 1)
        {
            bool x=false;
            do{
            printf("Please Enter your User Name & Password :) \n");
            printf("\n");
            printf("User Name :   \n");
            u8 Username[30];

            fflush(stdin);

            gets(Username);
            printf("Password :  \n");
            u32 password;
            scanf("%d",&password);

            if (strcmp(Username, "Mohammed Magdy Mahrous Morsy") == 0 &&  password==2777) {
                printf("Welcome To Admins Window Mr Mohammed Magdy :) \n");
                printf("\n");
                Admin_Page();
            } else if (strcmp(Username, "Mohammed Ahmed Mohammed Fahmy") == 0 && password==1234) {
                printf("Welcome To Admins Window Mr Mohammed Fahmy :) \n");
                printf("\n");
                Admin_Page();
            } else {
                printf("User Name Or Password Is Wrong :( ! \n");
                x=true;
            }

            }while(x);

        }

        else if(user==2)
        {
            //  system("CLS");
            Client_Page();
        }
        else
        {
            printf("Please Enter Valid Number\n");
        }

    }while(user>2 && user<0);
}




static void Admin_Page() {
   // system("color A ");

    printf("\t\t\t\t\t\t\tAdmin Page  \n");
    u8 a=0;
    printf("\n");
    do {
        printf("1- Create New Account \n");
        printf("2- Open Existing Account \n");
        printf("3- Exit System \n");
        printf("\n");
        printf("Enter Your Choice .... \n");
        scanf("%d", &a);
        if ( a == 1)
        {

            Create_New_Account();

        }
       else if(a==2)
        {
            Open_Existing_Account_Admins();
        }
        else if(a==3)
        {
            Exit_The_System();
        }
        else
        {
            printf("Please Enter Valid Number\n");
        }


    }while(a>3 || a<0);

}

static void Client_Page() {

    printf("\t\t\t\t\t\t\tClient Page  \n");
    printf("\n\n");
    Open_Existing_Account_Clients();

}

/*
 *
 * ADMIN PAGE
 *
 */


//******************* 1 **************************

static void Create_New_Account()
 {


     // ***********FULL NAME***********
     struct Clients_Linked_List d;

     printf("Please Enter your Full Name :\n");
      u8 NameArr[40];


    fflush(stdin);
    gets(NameArr);

     //CHEAK IF USER ENTER FULL NAME OR NOT
     u8 Correct_Name =Cheak_Name(NameArr);
     if(Correct_Name>=3)
     {
         strcpy(d.data.Name,NameArr);
       //  ptr->Name=  NameArr;

     }
     else
     {
         printf("Invalid Name ! :(   \n");
         Admin_Page();
     }
     // ***********ADDRESS***********
     fflush(stdin);
     printf("Please Enter your Address :\n");
     u8 AddressArr[40];  // change u32 to u8

     gets(AddressArr);
     strcpy(d.data.Address,AddressArr);
    // ***********AGE***********
     printf("Please Enter your Age :\n");
     u8 age ;
     scanf("%d",&age);
 u8 f =0;
    if(age>=21)
    {
        d.data.Age=age;
        f=1;
    }
    else {

        long long x =Cheak_Guardian_National_ID();
        d.data.Guardian_National_ID=x;

        f=0;

    }

     // ***********National ID***********
     if(f==1) {
         long long y= Cheak_National_ID();
         d.data.National_ID=y;
     }
     // ***********BALANCE***********

     u32 Balance;
     printf("Please Enter your  Balance :\n");
     scanf("%d", &Balance);
     d.data.balance=Balance;

     // ***********Account Status***********

     d.data.Account_Status=Active;
     // ***********ID***********

     srand(time(NULL));
     // Generate random number from min to max
     u32  Bank_ID = rand() % (9999 - 0000 + 1) + 0000;
     d.data.ID=Bank_ID;
    // Bank_ID++;

     // ***********PASSWORD***********
    long long x= Generate_Password();
     d.data.Password=x;
   printf("Account is Created Successfully !");
    printf("USER_NAME IS : %s \n",d.data.Name);
    printf("Password IS :  %d \n",d.data.Password);
    printf("CLIENT ID IS : %d \n",d.data.ID);
     printf("CLIENT ID IS : %d \n",d.data.balance);
     printf("CLIENT ID IS : %s \n",d.data.Address);
     printf("CLIENT ID IS : %d \n",d.data.Age);
   // printf("If you Want To Generate Another Press 1 Or Not Press 0 ");

    Insert_Node(&d);

     printf("\n");
     printf("If You Want To Add New Account Press 1 &for Exiring Press Any Number \n");
     u8 xx;
     scanf("%d",&xx);
     if(xx==1)
     {
         Create_New_Account();
     }
     else
     {
         print();
         printf("\n");
         Admin_Page();
     }
 }

//******************* 2 **************************

static void Open_Existing_Account_Admins()
 {
   printf("Please Enter Client Bank ID : \n");
   u32 ID;
   scanf("%d",&ID);
     struct Clients_Linked_List * Client = Search_For_Client_ID( headptr, ID);
        if(Client==NULL)
   {
       printf("NOT FOUND !! \n");
       Open_Existing_Account_Admins();  //admin page
   }
        else
   {
       printf("Welcome In Account of Mr : %s  :)  \n",Client->data.Name)   ;
       u8 *ActiveStatus;
       if(Client->data.Account_Status==1)
       {
           ActiveStatus="Active";
       }
       else if(Client->data.Account_Status==2)
       {
           ActiveStatus="Closed";
       }
       else if(Client->data.Account_Status==3)
       {
           ActiveStatus="Restricted";
       }
       else
       {
           return;
       }
       printf("Account Status Is : %s\n\n",ActiveStatus);
       u8 in1;

       do{
           printf("1- Make Transactions \n");
           printf("2- Change Account Status \n");
           printf("3- Get Cash \n");
           printf("4- Deposite In Account \n");
           printf("5- Return To Main Menu \n");
           printf("\n");
           printf("Enter Your Choice .... \n");
           scanf("%d", &in1);

           switch(in1)
           {
               /*
                *   MAKE TRANSACTIONS
                */
               case 1:

                   printf("Please Enter Bank Account ID you Want To Transfer Money : \n");
                   u32 d;
                   scanf("%d",&d);
                   struct Clients_Linked_List *AnotherClient= Search_For_Client_ID( headptr, d);
                   if(AnotherClient==NULL)
                   {
                       printf("NOT FOUND !! \n");
                       Open_Existing_Account_Admins();
                   }
                   else{
                   printf("Enter Amount Of Money \n");
                   u32 money;
                   scanf("%d",&money);
                   if(money <= (Client->data.balance)-1000 && Client->data.Account_Status==Active &&AnotherClient->data.Account_Status==Active)
                      {
                          (AnotherClient->data.balance)=(AnotherClient->data.balance)+money;
                          (Client->data.balance)=(Client->data.balance)-money;
                          printf("Transaction is Done \n");
                          printf("Your Balance is: %d \n",Client->data.balance);
                          printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                          u8 f;
                          scanf("%d",&f);
                          if(f==1)
                          {
                              Admin_Page();
                          }
                          else
                          {
                              Exit_The_System();
                          }

                      }
                   else
                   {
                       printf("process Cant Done !! \n");
                       printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                       u8 f;
                       scanf("%d",&f);
                       if(f==1)
                       {
                           Admin_Page();
                       }
                       else
                       {
                           Exit_The_System();
                       }
                   }
           }
                   break;

                    /*
                    *  CHANGE ACCOUNT STATUS
                    */
               case 2:
                   printf("Please Enter The Bank Account Status You Want For This Account  \n");
                   printf("\n");
                   printf("1-Set Account To Active State\n");
                   printf("2-Set Account To Close\n");
                   printf("3-Set Account To Restricted State\n");
                   u8 in2;
                   scanf("%d",&in2);
                   if(in2==1)                  Client->data.Account_Status=Active;
                   else if(in2==2)             Client->data.Account_Status=Closed;
                   else if(in2==3)             Client->data.Account_Status=Restricted;

                   printf("The Current Status is : %d\n",Client->data.Account_Status);
                   printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                   u8 f;
                   scanf("%d",&f);
                   if(f==1)
                   {
                       Admin_Page();
                   }
                   else
                   {
                       Exit_The_System();
                   }

                   break;

                   /*
                   * GET CASH
                    */
               case 3:
                   printf("Enter Amount Of Money \n");
                   u32 cash;
                   scanf("%d",&cash);
                   if(cash<Client->data.balance &&Client->data.Account_Status==Active )
                   {
                       Client->data.balance-=cash;
                       printf("process Is Done !! \n");
                       printf("Your Current Balance Is :%d \n",Client->data.balance);
                       printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                       u8 f;
                       scanf("%d",&f);
                       if(f==1)
                       {
                           Admin_Page();
                       }
                       else
                       {
                          Exit_The_System();
                       }
                   }
                   else
                   {
                       printf("process Cant Done !! \n");
                       printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                       u8 f;
                       scanf("%d",&f);
                       if(f==1)
                       {
                           Admin_Page();
                       }
                       else
                       {
                           Exit_The_System();

                       }
                   }

                   break;

                /*
                * DEPOSITE
                */
               case 4:
                   printf("Enter Amount Of Cash Amount \n");
                   u32 Deposite;
                   scanf("%d",&Deposite);
                   if(Client->data.Account_Status==Active )
                   {
                       Client->data.balance=Client->data.balance+Deposite;
                       printf("process Is Done !! \n");
                       printf("Your Current Balance Is :%d \n",Client->data.balance);
                       printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                       u8 f;
                       scanf("%d",&f);
                       if(f==1)
                       {
                           Admin_Page();
                       }
                       else
                       {
                           Exit_The_System();

                       }
                   }
                   else
                   {
                       printf("process Cant Done !! \n");
                       printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                       u8 f;
                       scanf("%d",&f);
                       if(f==1)
                       {
                           Admin_Page();
                       }
                       else
                       {
                          Exit_The_System();
                       }
                   }

                   break;

               /*
                * RETURN  MAIN MENU
                */
               case 5:
                   IntroPage();
                   break;

               default:
                   printf("Please Enter Valid Number");
                   break;
           }

       }while(in1>5 || in1 <0);
   }

 }

////******************* 3 **************************
static int Exit_The_System()
{
    printf("\t\tThank You !\n");
    exit(0);

}


//**********************************************************************************************************
/*
 *
 * CLIENT PAGE
 *
 */


static void Open_Existing_Account_Clients()
{
    printf("Please Enter Your Bank ID &Password  : \n");
    u32 ID;
    printf("ID : \n");
    scanf("%d",&ID);
    printf("Password : \n");
    long long password;
    scanf("%lld",&password);
    struct Clients_Linked_List * Client= Search_For_Client_ID( headptr, ID);

    if(Client==NULL ||Client->data.Password !=password )
    {
        printf("NOT FOUND !! \n");
        Open_Existing_Account_Clients();
    }
    else {

     printf("Welcome Mr :%s  :)  \n\n",Client->data.Name)   ;         //
            u8 in1;

            do {
                printf("1- Make Transactions \n");
                printf("2- Change Account Password \n");
                printf("3- Get Cash \n");
                printf("4- Deposite In Account \n");
                printf("5- Return To Main Menu \n");
                printf("\n");
                printf("Enter Your Choice .... \n");
                scanf("%d", &in1);

                switch (in1) {
                    case 1:
                         /*
                          *      Make Transaction
                          */
                        printf("Please Enter Bank Account ID you Want To Transfer Money : \n");
                        u32 M;
                        scanf("%d",&M);
                        struct Clients_Linked_List *Another_Client = Search_For_Client_ID(headptr,M);
                        if(Another_Client==NULL)
                        {
                            printf("NOT FOUND !! \n");
                            Open_Existing_Account_Clients();
                        }
                        else {


                            printf("Enter Amount Of Money \n");
                            u32 money2;
                            scanf("%d", &money2);
                            if (money2 <= ((Client->data.balance)-1000) && Client->data.Account_Status == Active &&
                                    Another_Client->data.Account_Status == Active) {
                                Another_Client->data.balance =Another_Client->data.balance+ money2;
                                Client->data.balance =Client->data.balance- money2;
                                printf("Transaction is Done \n");
                                printf("Your Balance is: %d \n",Client->data.balance);
                                printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                                u8 f;
                                scanf("%d", &f);
                                if (f == 1) {
                                    Client_Page();
                                } else {
                                    Exit_The_System();
                                }
                            } else {
                                printf("process Cant Done !! \n");
                                printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                                u8 f;
                                scanf("%d", &f);
                                if (f == 1) {
                                    Client_Page();
                                } else {
                                    Exit_The_System();
                                }


                            }
                        }
                        break;

                    case 2:
                        /*
                          *      Change Account password
                          */
                        printf("\n");
                        u8 flag22 = 1;
                        do {
                            printf("Please Enter  Old Password\n");

                            u32 oldpass;
                            scanf("%d", &oldpass);
                            printf("Please Enter New Password\n");
                            u32 newpass;
                            scanf("%d", &newpass);
                            if (oldpass == Client->data.Password) {
                                Client->data.Password = newpass;
                                printf("Password has Changed Successfully :)  \n");
                                printf("Your New Pass is :%lld",Client->data.Password);
                                printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                                u8 f;
                                scanf("%d", &f);
                                if (f == 1) {
                                    Client_Page();
                                } else {
                                   Exit_The_System();
                                }
                            } else {
                                printf("Wrong Password !!  \n");
                                flag22 = 0;
                            }
                        } while (flag22 == 0);

                        break;

                    case 3:
                        /*
                          *      Get Cash
                          */
                        printf("Enter Amount Of Money \n");
                        u32 cash;
                        scanf("%d", &cash);
                        if (cash < Client->data.balance && Client->data.Account_Status == Active) {
                            Client->data.balance = Client->data.balance-cash;
                            printf("process Is Done !! \n");
                            printf("Your Current Balance Is  :%d \n", Client->data.balance);
                            printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                            u8 f;
                            scanf("%d", &f);
                            if (f == 1) {
                                Client_Page();
                            } else {
                                Exit_The_System();
                            }
                        } else {
                            printf("process Cant Done !! \n");
                            printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                            u8 f;
                            scanf("%d", &f);
                            if (f == 1) {
                                Client_Page();
                            } else {
                                Exit_The_System();
                            }
                        }

                        break;

                    case 4:
                        /*
                          *      Deposit in Account
                          */

                        printf("Enter Amount Of Cash Amount \n");
                        u32 Deposite;
                        scanf("%d", &Deposite);
                        if (Client->data.Account_Status == Active) {
                            Client->data.balance =Client->data.balance+ Deposite;
                            printf("process Is Done !! \n");
                            printf("Your Current Balance Is :%d \n", Client->data.balance);
                            printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                            u8 f;
                            scanf("%d", &f);
                            if (f == 1) {
                                Client_Page();
                            } else {
                                Exit_The_System();
                            }
                        } else {
                            printf("process Cant Done !! \n");
                            printf("If You Want To Return Back Press [1] Or Exit Press [2] \n");
                            u8 f;
                            scanf("%d", &f);
                            if (f == 1) {
                                Client_Page();
                            } else {
                                Exit_The_System();
                            }
                        }

                        break;

                    case 5:
                        /*
                          *     Main Menu
                          */
                        IntroPage();
                        break;
                    default:
                        printf("Please Enter Valid Number");
                        break;
                }

            } while (in1 > 5 || in1 < 0);
        }

}

//**********************************************************************************************************




//**********************************************************************************************************


void Insert_Node(struct Clients_Linked_List * x) {
    struct Clients_Linked_List *temp=(struct Clients_Linked_List *) malloc(sizeof (struct Clients_Linked_List));
    temp->data.ID=x->data.ID;
    temp->data.Password=x->data.Password;
    strcpy((char *) temp->data.Name, (char *)x->data.Name);
    strcpy((char *) temp->data.Address, (char *)x->data.Address);
    temp->data.National_ID=x->data.National_ID;
    temp->data.Guardian_National_ID=x->data.Guardian_National_ID;
    temp->data.Account_Status=x->data.Account_Status;
    temp->data.Age=x->data.Age;
    temp->data.balance=x->data.balance;

    temp->next=NULL;

    if(headptr==NULL)
    {
        headptr=temp;
    }
    else
    {
        struct Clients_Linked_List * Dummy=headptr;
        while(Dummy->next != NULL)
        {
            Dummy = /*(struct Clients_Linked_List *)*/ Dummy->next;
        }
            Dummy->next=  temp;

    }


}

struct Clients_Linked_List *Search_For_Client_ID(struct Clients_Linked_List *head,u32 ID)
{
    struct Clients_Linked_List * Dummy =head;


    while (Dummy != NULL) {
        if (ID == Dummy->data.ID) {
            return Dummy;
        }
        Dummy=Dummy->next;

    }
    return NULL;

}


void print()
{
    u32 i=1;
    struct Clients_Linked_List *Dummy=headptr;
    while(Dummy!=NULL)
    {

        printf("Account %d : \n",i);
        printf("Age :%d\n",Dummy->data.Age);
        printf("ID :%d\n",Dummy->data.ID);
        printf("Balance :%d\n",Dummy->data.balance);

        Dummy=Dummy->next;
        i++;
    }
}