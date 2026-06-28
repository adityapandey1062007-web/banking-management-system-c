#include <stdio.h>
#include <string.h>

void servicesprovidedbybank();
void accountstatus();

int accountno[] = {
    456432,
    567654,
    768987,
    909876,
    334562,
    947578
};

char mypasswords[][20] = {
    "meowmeow",
    "woofwoof",
    "rawrrawr",
    "ilikebabparantha",
    "dhinkachika",
    "iamlearningClangauge"
};

int main()
{
    printf("\n");
    printf("=================================================\n");
    printf("         WELCOME TO SURAKSHIT BANK\n");
    printf("=================================================\n\n");

    accountstatus();

    printf("\n");
    printf("-------------------------------------------------\n");
    printf(" Here you can:\n");
    printf("  • Withdraw Money\n");
    printf("  • Deposit Money\n");
    printf("  • Check Account Balance\n");
    printf("-------------------------------------------------\n\n");

    servicesprovidedbybank();

    return 0;
}

void servicesprovidedbybank()sss
{
    int choice;
    int bankaccountbalance = 0;
    int withdraw = 0;
    int deposit = 0;
    int transactionchoice;

    FILE *pfile = fopen("bankreciept.txt", "w");

    if (pfile == NULL)
    {
        printf("\nERROR OPENING FILE!\n");
        return;
    }

    fprintf(pfile, "============ SURAKSHIT BANK ============\n");

    fclose(pfile);

    do
    {
        printf("\n========================================\n");
        printf("        BANKING SERVICES MENU\n");
        printf("========================================\n");
        printf("1. Check Account Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\n----------------------------------------\n");
            printf("Current Balance : %d\n", bankaccountbalance);
            printf("----------------------------------------\n");
            break;

        case 2:

            printf("\nEnter amount to deposit : ");
            scanf("%d", &deposit);

            bankaccountbalance += deposit;

            printf("\nDeposit Successful!\n");
            printf("Amount Deposited : %d\n", deposit);
            printf("Current Balance  : %d\n", bankaccountbalance);

            FILE *pfile = fopen("bankreceipt.txt", "a");

            fprintf(pfile, "DEPOSITED : %d\n", deposit);

            fclose(pfile);

            break;

        case 3:

            printf("\nEnter amount to withdraw : ");
            scanf("%d", &withdraw);

            if (withdraw <= bankaccountbalance)
            {
                bankaccountbalance -= withdraw;

                FILE *pfile = fopen("bankreceipt.txt", "a");

                printf("\nWithdrawal Successful!\n");
                printf("Amount Withdrawn : %d\n", withdraw);
                printf("Current Balance  : %d\n", bankaccountbalance);

                fprintf(pfile, "WITHDRAWN : %d\n", withdraw);

                fclose(pfile);
            }
            else
            {
                printf("\nInsufficient Balance!\n");
            }

            break;

        case 4:

            printf("\n========================================\n");
            printf("Thank You For Choosing Surakshit Bank!\n");
            printf("========================================\n");

            break;

        default:

            printf("\nInvalid Choice! Please Try Again.\n");
        }

    } while (choice != 4);

    printf("\nWould you like a receipt of your transactions?\n");
    printf("1. Yes\n");
    printf("0. No\n");
    printf("Enter your choice : ");
    scanf("%d", &transactionchoice);

    if (transactionchoice == 1)
    {
        FILE *pfile = fopen("bankreciept.txt", "w");

        if (pfile == NULL)
        {
            printf("\nERROR OPENING FILE!\n");
            return;
        }

        fprintf(pfile,
                "=========== TRANSACTION RECEIPT ==========\n");
        fprintf(pfile,
                "Current Balance : %d\n",
                bankaccountbalance);
        fprintf(pfile,
                "==========================================\n");

        fclose(pfile);
    }
}

void accountstatus()
{
    char password[20];
    int accountchoice;
    int enteredaccountnumber;

    printf("========================================\n");
    printf("          ACCOUNT VERIFICATION\n");
    printf("========================================\n");
    printf("1. Existing Account\n");
    printf("2. Create New Account\n");
    printf("----------------------------------------\n");
    printf("Enter your choice : ");

    scanf("%d", &accountchoice);

    if (accountchoice == 1)
    {
        printf("\nWelcome Back!\n");
        printf("Enter your Account Number : ");
        scanf("%d", &enteredaccountnumber);

        if (enteredaccountnumber == accountno[0])
        {
            printf("Enter Password : ");
            scanf("%s", password);

            if (strcmp(mypasswords[0], password) == 0)
            {
                printf("\nLogin Successful!\n");
                printf("You can now proceed.\n");
            }
        }

        else if (enteredaccountnumber == accountno[1])
        {
            printf("Enter Password : ");
            scanf("%s", password);

            if (strcmp(mypasswords[1], password) == 0)
            {
                printf("\nLogin Successful!\n");
                printf("You can now proceed.\n");
            }
        }

        else if (enteredaccountnumber == accountno[2])
        {
            printf("Enter Password : ");
            scanf("%s", password);

            if (strcmp(mypasswords[2], password) == 0)
            {
                printf("\nLogin Successful!\n");
                printf("You can now proceed.\n");
            }
        }

        else if (enteredaccountnumber == accountno[3])
        {
            printf("Enter Password : ");
            scanf("%s", password);

            if (strcmp(mypasswords[3], password) == 0)
            {
                printf("\nLogin Successful!\n");
                printf("You can now proceed.\n");
            }
        }

        else if (enteredaccountnumber == accountno[4])
        {
            printf("Enter Password : ");
            scanf("%s", password);

            if (strcmp(mypasswords[4], password) == 0)
            {
                printf("\nLogin Successful!\n");
                printf("You can now proceed.\n");
            }
        }

        else
        {
            printf("\nInvalid Credentials!\n");
        }
    }
}