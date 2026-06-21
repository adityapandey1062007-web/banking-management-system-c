#include <stdio.h>
void servicesprovidedbybank();
int main(){
char choice;
char A;
printf("**********WELCOME TO SURAKSHIT BANK**********\n ");
printf("here you can wihdraw , deposit your money,\ncheck your status of account in a fast and secure way.");
  servicesprovidedbybank();

}


void servicesprovidedbybank(){ 
     int choice;
     int bankaccountbalance =0;
     int withdraw =0;
     int deposit = 0;
     int transactionchoice;
    do{
       
printf("select the task you wanna perform");
printf("\n1:check status of your bankaccountbalance");
printf("\n2:deposit money");
printf("\n3:withdraw money");
printf("\n4:exit");
printf("\nenter your choice");
scanf("%d",&choice);

switch (choice)
{
case 1:
printf("your balance is %d\n",bankaccountbalance);
break;
case 2:
printf("Enter amount to deposit: ");
scanf("%d", &deposit);
 bankaccountbalance += deposit;
 printf("Deposited %d successfully! New balance: %d\n", deposit, bankaccountbalance);
 break;
 case 3:
 printf("Enter amount to withdraw: ");
 scanf("%d", &withdraw);
 if (withdraw <= bankaccountbalance) {
 bankaccountbalance -= withdraw;
 printf("Withdrawn %d successfully! New balance: %d\n", withdraw, bankaccountbalance);}
  else {
 printf("Insufficient balance!\n"); }
   break;
case 4:
printf("exiting the bank and reaching to transaction choice area");
break;
}
   }while(choice != 4);

printf("DO YOU WANT AN FEES RECIEPT OF YOUR CURRENT BANK TRANSACTIONS\n ");
printf("enter your choice as in yes ==1 or no ==0");
scanf("%d",&transactionchoice);
if( transactionchoice == 1){
FILE *pfile = fopen("bankreceipt.txt","w");


if(pfile == NULL){
  printf("ERROR OPENING FILE");
  return;
}
fprintf( pfile,"AFTER ALL TRANSACTIONS YOUR CURRENT BANK ACCOUNT BALANCE IS %d",bankaccountbalance);
printf("YOUR BANK RECIEPT WAS GENERATED SUCCESSFULLY");
fclose(pfile);


return;}

  }
  