 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*struct date{
    int month,day,year;
    };*/
struct data{
    char name[60];
    int acc_no,age;
    char address[60],DOB[10];
    double phone;
    char acc_type[10];
    float amount;
    //struct date dob;
    };
struct data add,upd,transactions,new,check;

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.text","a");
    printf("\t\t\tADD RECORD  ");
   
    printf("\nEnter the account number:");
    scanf("%d",&add.acc_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%s",add.DOB);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nenter your address :");
    scanf("%s",add.address);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nType of account:");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
    fclose(ptr);
    printf("\nAccount created successfully!");
    
}

void view_list()
{
    FILE *ptr;
    ptr=fopen("record.text","r");
    printf("\n%-15s %-15s %-15s %-15s\n","ACC. NO.","NAME","PHONE","ADDRESS");
    while(fscanf(ptr,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
       {

           printf("%-15d %-15s %-15.0lf %-15s \n",add.acc_no,add.name,add.phone,add.address);
       }
        fclose(ptr);
}

void edit()
{
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.text","r");
	newrec=fopen("new.text","w");
	printf("\n Enter the account number of the customer whose info you want to change :");
	scanf("%d",&upd.acc_no);
	while(fscanf(old,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
	{
		if(add.acc_no==upd.acc_no)
		{
			test=1;
			printf("\n Which information do you want to change ?? \n 1.Address \n 2.phone");
			printf("\nEnter your chioce :");
			scanf("%d",&choice);

			if(choice==1)
			{
				printf("\n Enter the new address :");
				scanf("%s",upd.address);
				fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,upd.address,add.phone,add.acc_type,add.amount);
				printf("Changes saves!!");
			}

			else if(choice==2)
			{
				printf("\nEnter the new phone number :");
				scanf("%lf",&upd.phone);
				fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,upd.phone,add.acc_type,add.amount);
			}
		}
		else
		{
			fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.text");
	rename("new.text","record.text");
if(test!=1)
{
	printf("\nRecord not found!!");
}
}

void transact()
{

	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.text","r");
	newrec=fopen("new.text","w");
	printf("\n Enter the account number :");
	scanf("%d",&transactions.acc_no);
	while(fscanf(old,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
	{
		if(add.acc_no==transactions.acc_no)
		{
			test=1;
			printf("\n Do you want to \n1.Deposit \n2.Withdraw");
			printf("\n Enter your choice:");
			scanf("%d",&choice);

			if(choice==1)
			{
				printf("\nenter the amount you want to Deposit :");
				scanf("%f",&transactions.amount);
				add.amount+=transactions.amount;
				fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
				printf("\nDeposited successfully!!");
			}
			else if(choice==2)
			{
					printf("\nEnter the amount you want to Withdraw :");
					scanf("%f",&transactions.amount);
					add.amount-=transactions.amount;
					fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
					printf("\nWithdraw successfully!!");
			}
		}
		else
			{
				fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
			}
	}
	fclose(old);
	fclose(newrec);
	remove("record.text");
	rename("new.text","record.text");
	if(test!=1)
	{
		printf("\nRecord not found!!");
	}

}

void erase()
{
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.text","r");
	newrec=fopen("new.text","w");
	printf("\nEnter the account number you want to delete :");
	scanf("%d",&new.acc_no);
	while(fscanf(old,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
	{
		if(add.acc_no!=new.acc_no)
		{
			fprintf(newrec,"%d %s %s %d %s %lf %s %f\n",add.acc_no,add.name,add.DOB,add.age,add.address,add.phone,add.acc_type,add.amount);
		}
		else
		{
			test++;
			printf("\nRecord deleted successfully!!");
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.text");
	rename("new.text","record.text");
if(test==0)
{
	printf("\nRecord not found!!");
}
}

void see()
{
	FILE *fp;
	int choice;
	fp=fopen("record.text","r");
	printf("\nDo you want to check by \n1.account number \n2.name");
	printf("\nenter your chioce :");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("\nEnter your account number :");
		scanf("%d",&check.acc_no);
		while(fscanf(fp,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
		{
			if(add.acc_no==check.acc_no)
			{
				printf("\n Accont No: %d \n Name: %s \n Age: %d \n Address: %s \n Phone number: %0.lf \n Type of account: %s \nAmmount Deposited: %f",add.acc_no,add.name,add.age,add.address,add.phone,add.acc_type,add.amount);

			}
		}
	}
	else if(choice==2)
	{
		printf("Enter the name:");
        scanf("%s",check.name);
        while(fscanf(fp,"%d %s %s %d %s %lf %s %f",&add.acc_no,add.name,add.DOB,&add.age,add.address,&add.phone,add.acc_type,&add.amount)!=EOF)
		{
			 if(strcmp(add.name,check.name)==0)
			 {
			 	printf("\n Accont No: %d \n Name: %s \n Age: %d \n Address: %s \n Phone number: %0.lf \n Type of account: %s \nAmmount Deposited: %f",add.acc_no,add.name,add.age,add.address,add.phone,add.acc_type,add.amount);
			 }
		}

	}
	else
	{
		printf("\nRecord not found!!");
	}
	fclose(fp);
}

int  main()
{   int choice;
    while(choice!=7)
    {
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:
        break;

    }
    }
}
