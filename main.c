///Highlighted menu
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#define EXTENDED -32
#define Enter 13
#define ESC 27
#define TAB 9
#define Up 72
#define Home 71
#define Down 80
#define End 79

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

struct Employee
{
    int SSN;
    char name[20];
    int age;
    float salary;
    float commission;
    float deduction;
    float netsalary ;
    int isdeleted;


};

int main()
{
    char menu[8][15]= {"New","DisplayAll","DisplayBySSN","DisplayByName","DeleteBySSN","DeleteByName","DeleteAll","Exit"};
    int cursor=0;
    int flag=555;
    char ch;
    int index;
    int ssn_exist=0;
    int temp;
    int ssn_delete;
    int ssn_choice;
    char name_choice[15];
    char name_delete[15];
    struct Employee employees[10]= {0};

    do
    {
        //clear screen
        system("cls");
        for (int i = 0; i < 8; i++)
        {
            if(i==cursor)
            {
                textattr(4);   //R
            }
            else
            {
                textattr(7);   //W
            }
            gotoxy(15,15+i);
            _cprintf("%s",menu[i]);
        }
        //
        ch=getch();  //Enter
        switch(ch)
        {
        case EXTENDED:
            ch=getch();
            switch(ch)
            {
            case Up:
                cursor--;
                if(cursor<0)
                {
                    cursor=7;
                }
                break;
            case Down:
                cursor++;
                if(cursor>7)
                {
                    cursor=0;
                }
                break;
            case Home:
                cursor=0;
                break;
            case End:
                cursor=7;
                break;
            }
            break;
        case Enter:
            switch(cursor)
            {
            case 0:
                system("cls");
                printf("choose index from 0 to 9 : ");
                scanf("%i",&index);
                if (index<0 || index>9 || employees[index].SSN!=0)
                {
                    printf("invalid index , press any key to continue...");
                    getch();
                }

                else
                {

                    system("cls");


                    do
                    {
                        system("cls");
                        ssn_exist = 0;
                        printf("Please enter data from employee %i",index);
                        gotoxy(5,5);
                        printf("SSN : ");
                        gotoxy(55,5);
                        printf("Name : ");
                        _flushall();
                        gotoxy(5,10);
                        printf("Age : ");
                        gotoxy(55,10);
                        printf("Salary : ");
                        gotoxy(5,15);
                        printf("Commission : ");
                        gotoxy(55,15);
                        printf("Deduction : ");

                        gotoxy(10,5);
                        scanf("%i",&temp);
                        //system("cls");



                        for(int i=0; i<10; i++)
                        {
                            if(employees[i].SSN==temp)

                            {

                                ssn_exist=1;
                                system("cls");
                                printf("this employee already exist!!,Please enter a unique SSN");
                                getch();
                                break;

                            }

                        }
                        if(ssn_exist==0)
                        {
                            employees[index].SSN=temp;
                        }

                    }
                    while(ssn_exist==1);

                    gotoxy(61,5);
                    scanf("%s",employees[index].name);
                    gotoxy(10,10);
                    scanf("%i",&employees[index].age);
                    gotoxy(63,10);
                    scanf("%f",&employees[index].salary);
                    gotoxy(18,15);
                    scanf("%f",&employees[index].commission);
                    gotoxy(69,15);
                    scanf("%f",&employees[index].deduction);
                    system("cls");
                    employees[index].netsalary=employees[index].salary+employees[index].commission-employees[index].deduction;                //wait to see
                    getch();
                }
                break;
            case 1:
                system("cls");
                for (int i = 0; i < 10; i++)
                {
                    if(employees[i].SSN!=0 && employees[i].isdeleted==0)
                    {


                        printf("Employee %i",i+1);
                        printf("\n----------\n");
                        printf("Name      : %s",employees[i].name);
                        printf("\n");
                        printf("Age       : %i",employees[i].age);
                        printf("\n");
                        printf("Salary    : %f",employees[i].salary);
                        printf("\n");
                        printf("Commission: %f",employees[i].commission);
                        printf("\n");
                        printf("Deduction : %f",employees[i].deduction);
                        printf("\n");
                        printf("Net salary: %f",employees[i].netsalary);
                        printf("\n-------------------------------------------\n");
                    }
                }


                //wait to see
                getch();
                break;
            case 2:
                system("cls");
                printf("Enter the ssn : ");
                scanf("%i",&ssn_choice);
                system("cls");
                for(int i=0; i<10; i++)
                {
                    if(ssn_choice==employees[i].SSN)
                    {
                        printf("the employee of ssn : %i",ssn_choice);

                        printf("\n----------\n");
                        printf("Name      : %s",employees[i].name);
                        printf("\n");
                        printf("Age       : %i",employees[i].age);
                        printf("\n");
                        printf("Salary    : %f",employees[i].salary);
                        printf("\n");
                        printf("Commission: %f",employees[i].commission);
                        printf("\n");
                        printf("Deduction : %f",employees[i].deduction);
                        printf("\n");
                        printf("Net salary: %f",employees[i].netsalary);
                        printf("\n-------------------------------------------\n");

                    }
                }
                //wait to see
                getch();
                break;
            case 3:
                system("cls");
                printf("Enter the name : ");
                //gets(name_choice);
                scanf("%s",name_choice);
                system("cls");

                for(int i=0; i<10; i++)
                {
                    if(!strcmp(name_choice,employees[i].name))
                    {
                        printf("the employee  : %s",employees[i].name);

                        printf("\n----------\n");
                        printf("Name      : %s",employees[i].name);
                        printf("\n");
                        printf("Age       : %i",employees[i].age);
                        printf("\n");
                        printf("Salary    : %f",employees[i].salary);
                        printf("\n");
                        printf("Commission: %f",employees[i].commission);
                        printf("\n");
                        printf("Deduction : %f",employees[i].deduction);
                        printf("\n");
                        printf("Net salary: %f",employees[i].netsalary);
                        printf("\n-------------------------------------------\n");

                    }
                }
                //wait to see
                getch();
                break;
            case 4:
                system("cls");
                printf("Enter the  ssn to delete : ");

                scanf("%i",&ssn_delete);
                system("cls");

                for(int i=0; i<10; i++)
                {
                    if(employees[i].SSN==ssn_delete)
                    {
                        employees[i].isdeleted=1;
                        printf("the employee of %i is deleted",ssn_delete);
                        getch();
                        break;
                    }

                }

                break;
            case 5:
                system("cls");
                printf("Enter the name to delete : ");
                _flushall();
                scanf("%s",&name_delete);
                system("cls");

                for(int i=0; i<10; i++)
                {
                    system("cls");
                    if(!strcmp(name_delete,employees[i].name))
                    {
                        employees[i].isdeleted=1;
                        printf("the employee of %s is deleted",name_delete);
                        getch();

                        break;
                    }

                }

                break;
            case 6:
                for(int i=0;i<10;i++)
                {
                    employees[i].SSN=0;
                    employees[i].name[i]="Empty";
                    employees[i].age=0;
                    employees[i].commission=0;
                    employees[i].deduction=0;
                    employees[i].netsalary=0;

                }
                system("cls");
                printf("all employees are deleted !!");
                getch();
                break;
            case 7:

                flag=0;
                break;
            }
            break;
        case ESC:
            flag=0;
            break;
        case TAB:
            cursor++;
            if(cursor>7)
            {
                cursor=0;
            }
            break;
        }

    }
    while(flag==555);


    return 0;
}
