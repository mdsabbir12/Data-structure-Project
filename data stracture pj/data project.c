#include<stdio.h>

int i,j,k=0,count=0;
float bill[100];
int main_exit;
struct {
    char name[60];
    long int meter_No;
    float amount;
    int day,month,year;
    }add,fee;
struct meter {
  int key;
  struct meter *left, *right;
};


struct meter *newmeter(int item) {
  struct meter *temp = (struct meter *)malloc(sizeof(struct meter));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void inorder(struct meter *rootmeter) {
  if (rootmeter != NULL) {

    inorder(rootmeter->left);


    printf("%d --> ", rootmeter->key);


    inorder(rootmeter->right);
  }

}


struct meter *insert(struct meter *meter, int key) {

  if (meter == NULL)
    return newmeter(key);


  if (key < meter->key)
    meter->left = insert(meter->left, key);
  else
    meter->right = insert(meter->right, key);

  return meter;
}


struct meter *minValuemeter(struct meter *meter) {
  struct meter *current = meter;


  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct meter *deletemeter(struct meter *rootmeter, int key) {

  if (rootmeter == NULL)
    return rootmeter;


  if (key < rootmeter->key)
    rootmeter->left = deletemeter(rootmeter->left, key);
  else if (key > rootmeter->key)
    rootmeter->right = deletemeter(rootmeter->right, key);

  else {

    if (rootmeter->left == NULL) {
      struct meter *temp = rootmeter->right;
      free(rootmeter);
      return temp;
    } else if (rootmeter->right == NULL) {
      struct meter *temp = rootmeter->left;
      free(rootmeter);
      return temp;
    }
    struct meter *temp = minValuemeter(rootmeter->right);
    rootmeter->key = temp->key;
    rootmeter->right = deletemeter(rootmeter->right, temp->key);
  }
  return rootmeter;
}




void Add_meter_Delete_meter() {
  struct meter *rootmeter = NULL;

  int ins;
  again:
  printf("For Adding a meter:");
  scanf("%d",&ins);
  printf("\nAfter Add meter: \n");
  rootmeter = insert(rootmeter, ins);
  inorder(rootmeter);
  int select;
  printf("\n\n 1. Add another meter\n\n 2. Disconnect meter ");
  printf("\n press 1 or 2 :");
  scanf("%d",&select);
  if(select==1)
     goto again;
  int value;
  printf("\n Disconnect a meter: ");
  scanf("%d",&value);
  printf("\nAfter deleting %d\n",value);

  rootmeter = deletemeter(rootmeter, value);
  printf("Inorder traversal: ");
  inorder(rootmeter);
}


void hight_bill()
{
    float hig;
    for(int h=0;h<k;h++)
    {
         hig=bill[0];
        if(bill[k]>hig)
        {
           hig=bill[k];
        }
    }
    printf("\n\n\t\tHight Bill : %0.2f",hig);

}



void Add_user()

{

    FILE *user;

    user=fopen("user f admin record.text","a+");
    account_no:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\ ADD User  \xB2\xB2\xB2\xB2");

    printf("\n\n\n\t\t Meter ID number:");
    scanf("%ld",&add.meter_No);
    printf("\n\t\t User name:");
    scanf("%s",&add.name);
    printf("\n\t\t Today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.month,&add.day,&add.year);


        fprintf(user,"%ld    %s    %d/%d/%d \n",add.meter_No,add.name,add.month,add.day,add.year);


    fclose(user);
    printf("\nAccount created successfully!");
    goinvalid:
    printf("\n\n\n\t\t press 1 and go to the main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu2();
    else
        {
            printf("\nInvalid!\a");
            goto goinvalid;
        }
}

void Add_bill()

{
    count++;
    FILE *user;

    user=fopen("user record.text","a+");
    //account_no:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2  Bill pay  \xB2\xB2\xB2\xB2");

    printf("\n\n\n\t\t Meter ID number:");
    scanf("%ld",&fee.meter_No);
    printf("\n\t\t Amount:");

    scanf("%f",&fee.amount);
    bill[k]=fee.amount;
    k++;
    printf("\n\t\t Today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&fee.month,&fee.day,&fee.year);


        fprintf(user,"%ld    %0.2f       %d/%d/%d  \n",fee.meter_No,fee.amount,fee.month,fee.day,fee.year);


    fclose(user);
    printf("\n\t\t successfully Added!!");
    invalid:
    printf("\n\n\n\t\t press 1 and go to the main menu:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu1();
    else
        {
            printf("\nInvalid!\n");
            goto invalid;
        }
}
void view_list()
{
    printf("%d",count);
    FILE *user;
    user=fopen("user record.text","r");

    system("cls");
    printf("\nMeter ID    \tAmount\t\t\tDate\n");

    for(int i=0;i<count;i++)
    {
         while(fscanf(user,"%ld    %0.2f       %d/%d/%d ",&fee.meter_No,&fee.amount,&fee.month,&fee.day,&fee.year)!=feof(user))
       {
           printf("\n%ld     \t%0.2f    \t\t%d/%d/%d \n",fee.meter_No,fee.amount,fee.month,fee.day,fee.year);

           if(count-1==i)
            break;
       }
    }
    fclose(user);
    toinvalid:
     printf("\n\nPress 1 and go to the main menu:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu2();
        else
        {
            printf("\nInvalid!\a");
            goto toinvalid;
        }
}
void menu1()
{
    int select;
    system("color 2");
    printf("\n\n\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2          WELCOME TO ADMIN PANEL        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\n\t\t\t\t \xB6\xB6\xB6\xB6  Admin menu  \xB6\xB6\xB6\xB6\n\n\t\t 1. Add user bill\n\t\t 2. Add meter and Disconnect meter\n\t\t 3. Exit");
    printf("\n\n\t\tEnter your choice 1,2 or 3: ");
    scanf("%d",&select);
    system("cls");
    switch(select)
    {
        case 1:Add_bill();
        break;
        case 2:Add_meter_Delete_meter();
        break;
        case 3:main();
    }
}
void menu2()
{
    int select;
    system("color 2");
    printf("\n\n\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2          WELCOME TO USER PANEL         \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\n\t\t\t\t \xB6\xB6\xB6\xB6  User Menu  \xB6\xB6\xB6\xB6\n\n\t\t 1. Add User \n\t\t 2. See bill history\n\t\t 3. See hight Bill\n\t\t 4. Exit");
    printf("\n\n\t\tEnter your choice 1,2,3 or 4: ");

    scanf("%d",&select);
    system("cls");
    switch(select)
    {
        case 1:Add_user();
        break;
        case 2:view_list();
        break;
        case 3:hight_bill();
        break;
        case 4:main();
    }
}

void repassward()
{
    char  passward[10],demopass[]="Pass25@$";
    int n,i,pass;
    printf("\n\t\tPlease login by Current Passward: ");
    scanf("%s",&passward);
    pass=strcmp(passward,demopass);
    if(pass==0)
    {

        printf("\n\t\tSuccessfully login !!");
        system("cls");
        main();

    }
    else
    {
       printf("\n\t\tWorng Passward !!!");
       printf("\n\t\tPlease press 1 and Input current passward : ");
        scanf("%d",&n);
        if (n==1)
        {
            system("cls");
            repassward();
        }
        else
        {
            system("cls");
            repit();
        }
    }

}

void repit()
{
    int n;
    printf("\n\t\tPlease press 1: ");
    scanf("%d",&n);
    if (n==1)
    {
        system("cls");
        repassward();
    }
    else
    {
        printf("\n\t\tPlease press 1 and Input current passward : ");
        scanf("%d",&n);
        if (n==1)
        {
            system("cls");
            repassward();
        }
        else
        {
            system("cls");
            repit();
        }
    }
}


void demo1()
{
    char  passward[10],demopass[]="Pass25@$";
    int n,i,pass;
    printf("\n\t\tPlease login by Current Passward: ");
    scanf("%s",&passward);
    pass=strcmp(passward,demopass);
    if(pass==0)
    {

        printf("\n\t\tLoading ");
        for(i=0; i<6; i++)
        {

            printf(".");
        }

        printf("\n\t\tSuccessfully login !!");
        system("cls");
        menu1();

    }
    else
    {
        printf("\n\t\tWorng Passward !!!");
        printf("\n\t\tPlease press 1 and Input current passward : ");
        scanf("%d",&n);
        if (n==1)
        {
            system("cls");
            repassward();
        }
        else
        {
            system("cls");
            repit();
        }
    }
}

void demo2()
{
    char  passward[10],demopass[]="Pass25@$";
    int n,i,pass;
    printf("\n\t\tPlease login by Current Passward: ");
    scanf("%s",&passward);
    pass=strcmp(passward,demopass);
    if(pass==0)
    {

        printf("\n\t\tLoading ");
        for(i=0; i<6; i++)
        {

            printf(".");
        }

        printf("\n\t\tSuccessfully login !!");
        system("cls");
        menu2();

    }
    else
    {
        printf("\n\t\tWorng Passward !!!");
        printf("\n\t\tPlease press 1 and Input current passward : ");
        scanf("%d",&n);
        if (n==1)
        {
            system("cls");
            repassward();
        }
        else
        {
            system("cls");
            repit();
        }
    }
}

int main()
{
    int select;
    system("color 2");
    printf("\n\n\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2          WELCOME TO POLLI APP          \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB2                                        \xB2\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\t\t\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
    printf("\n\n\t\t\t \xB6\xB6\xB6\xB6  ADMIN AND USER PANAL  \xB6\xB6\xB6\xB6\n\n\t\t 1. Admin\n\n\t\t 2. User");

    printf("\n\n\t\tEnter your choice 1 or 2: ");
    scanf("%d",&select);
    system("cls");
    switch(select)
    {
        case 1:demo1();
        break;
        case 2:demo2();

    }

getch();
}



