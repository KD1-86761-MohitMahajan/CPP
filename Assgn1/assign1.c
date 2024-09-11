#include <stdio.h>
struct Date
{
    int date;
    int month;
    int year;
};
void initDate(struct Date *ptrDate)
{
    ptrDate->date = 0;
    ptrDate->month = 0;
    ptrDate->year = 0;
}
void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter day only\n");
    scanf("%d\n", &ptrDate->date);
    printf("Enter month only\n");
    scanf("%d\n", &ptrDate->month);
    printf("Enter year only\n");
    scanf("%d\n", &ptrDate->year);
    if (ptrDate->date <= 31 && ptrDate->month <= 12 && ptrDate->year <= 2024)
    {
        printf("Date and Time updated.\n");
    }
    else
    {
        printf("Please Enter valid date and time.\n");
    }
}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("You have entered the following values: %d- %d -%d \n", ptrDate->date, ptrDate->month, ptrDate->year);
}
int main()
{
    int choice = 1;
    struct Date d1;
    while (choice != 0)
    {
        printf(" Menu \n 0. Exit  \n 1. Add time.\n 2. Display Time. \n 3. Enter your choice. \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            acceptDateFromConsole(&d1);
            break;
        case 2:
            printDateOnConsole(&d1);
            break;
        case 3:
            printf("You have chosen option to Exit! Ok Bye!");
            break;
        default:
            printf("Enter a valid choice!\n");
        };
    };
    return 0;
}