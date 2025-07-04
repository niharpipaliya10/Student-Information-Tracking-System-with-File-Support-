#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date
{
    int day;
    int month;
    int year;
} dob, doj;
typedef struct stu
{
    char batch_id[10];
    char name[50];
    float marks;
    char assessment_status[10];
    struct date dob;
    struct date doj;
    struct stu *next;
} sll;
int a = 0;
void add_student_info(sll **);          // add  student data
void print_all_data(sll *);             // print all data
void save_data_file(sll *);             // save data in file
void read_data_file(sll **);            // read data from file
void edit_data_file(sll **);            // edit student data in file
void delete_data_one(sll **);           // delete one student data
void search_student_id(sll *);          // search student id
void search_student_name(sll *);        // search student name
void search_assessment_status(sll *);   // short data assessment status too
void search_student_birthdate(sll *);   // search student dob
void search_student_joindata(sll *);    // search student doj
void search_student_marks_range(sll *); // search student marke in between

void main()
{
    int op;
    sll *headptr = 0;
    while (1)
    {
        printf("1)Add student data\n2)Show all student data\n3)Save student data in file\n4)Read student data from file\n5)Update student data in file\n6)Delete student data in file\n7)Search student bantch\n8)Search_student_name\n9)Short student data base on assessment\n10)Search student base birth date\n11)Search student base join date\n12)Short student marks in range\n13)exit\n");
        printf("Enter a op no:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add_student_info(&headptr);
            break;
        case 2:
            print_all_data(headptr);
            break;
        case 3:
            save_data_file(headptr);
            break;
        case 4:
            read_data_file(&headptr);
            break;
        case 5:
            edit_data_file(&headptr);
            break;
        case 6:
            delete_data_one(&headptr);
            break;
        case 7:
            search_student_id(headptr);
            break;
        case 8:
            search_student_name(headptr);
            break;
        case 9:
            search_assessment_status(headptr);
            break;
        case 10:
            search_student_birthdate(headptr);
            break;
        case 11:
            search_student_joindata(headptr);
            break;

        case 12:
            search_student_marks_range(headptr);
            break;
        case 13:
            exit(0);
            break;

        default:
            printf("you choose invlid option\n");
            break;
        }
    }
}
/**************************************************************************************************************************************************** */
/*   add student data   */
void add_student_info(sll **ptr)
{
    sll *new, *last;
    new = malloc(sizeof(sll));

    printf("student bantch_id:\n");
    scanf(" %s", new->batch_id);

    printf("student name:\n");
    scanf(" %[^\n]", new->name);

    printf("student marks:\n");
    scanf("%f", &new->marks);

    printf("student assessment_status :\n");
    scanf("%s", new->assessment_status);

    printf("student birth date:\n");
    scanf("%d %d %d", &new->dob.day, &new->dob.month, &new->dob.year);

    printf("student join date:\n");
    scanf("%d %d %d", &new->doj.day, &new->doj.month, &new->doj.year);

    new->next = 0;
    if (*ptr == 0)
    {
        *ptr = new;
    }
    else
    {
        last = *ptr;
        while (last->next)
        {
            last = last->next;
        }
        last->next = new;
    }
    a = 1;
    printf("\nStudent added successfully!\n\n");
}
/**************************************************************************************************************************************************** */
/* load all data */
void print_all_data(sll *ptr)
{

    if (ptr == 0)
    {
        printf("no recorde found\n");
        return;
    }
    while (ptr)
    {
        printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n",
               ptr->batch_id, ptr->name, ptr->marks, ptr->assessment_status,
               ptr->dob.day, ptr->dob.month, ptr->dob.year,
               ptr->doj.day, ptr->doj.month, ptr->doj.year);
        ptr = ptr->next;
    }
    printf("\nData load successful\n\n");
}

/***************************************************************************************************** */
/* save data in file*/
void save_data_file(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no record found\n");
        return;
    }
    FILE *f;
    char s[10];
    printf("Enter a file name\n");
    scanf("%s", s);
    f = fopen(s, "w");
    while (ptr)
    {
        fprintf(f, "%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                ptr->assessment_status, ptr->dob.day, ptr->dob.month, ptr->dob.year,
                ptr->doj.day, ptr->doj.month, ptr->doj.year);
        ptr = ptr->next;
    }
    a = 1;
    fclose(f);
    printf("Data save successful\n\n");
}
/***************************************************************************************************** */
/*read data from file*/
void read_data_file(sll **ptr)
{
    if (*ptr == 0)
        a = 1;
    if (a == 1)
    {

        sll *new, *last;
        FILE *f;
        char filename[50];
        printf("Enter a file:\n");
        scanf("%s", filename);
        f = fopen(filename, "r");
        if (f == NULL)
        {
            printf("file not present\n");
            return;
        }
        while (1)
        {
            new = malloc(sizeof(sll));
            int n = fscanf(f, "%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", new->batch_id, new->name, &new->marks,
                           new->assessment_status, &new->dob.day, &new->dob.month, &new->dob.year,
                           &new->doj.day, &new->doj.month, &new->doj.year);
            if (n == EOF)
            {
                free(new);
                break;
            }
            if (n != 10)
            {
                free(new);
                continue;
            }

            new->next = NULL;
            if (*ptr == 0)
                *ptr = new;
            else
            {
                last = *ptr;
                while (last->next)
                    last = last->next;
                last->next = new;
            }
        }
        fclose(f);
        printf("read data successful\n\n");
        a = 0;
    }
    else
    {
        printf("data already read!\n\n");
    }
}
/***************************************************************************************************** */
/*edit data*/
void edit_data_file(sll **head)
{

    if (*head == NULL)
    {
        printf("No record found\n");
        return;
    }

    char batch_id[20], filename[30];
    printf("Enter the file name to save changes: ");
    scanf("%s", filename);

    printf("Enter the batch ID of student to edit: ");
    scanf("%s", batch_id);

    sll *temp = *head;
    int found = 0;

    while (temp)
    {
        if (strcmp(temp->batch_id, batch_id) == 0)
        {
            found = 1;
            printf("\nExisting record:\n");
            printf("%s  %s  %.2f  %s  %d-%d-%d  %d-%d-%d\n", temp->batch_id, temp->name, temp->marks, temp->assessment_status,
                   temp->dob.day, temp->dob.month, temp->dob.year, temp->doj.day, temp->doj.month, temp->doj.year);
            printf("Enter new name: ");
            scanf(" %[^\n]", temp->name);
            printf("Enter new marks: ");
            scanf("%f", &temp->marks);
            printf("Enter new assessment status: ");
            scanf("%s", temp->assessment_status);
            printf("Enter new DOB (dd mm yyyy): ");
            scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);
            printf("Enter new DOJ (dd mm yyyy): ");
            scanf("%d %d %d", &temp->doj.day, &temp->doj.month, &temp->doj.year);
            break;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("Student with batch ID %s not found.\n", batch_id);
        return;
    }

    // Save updated list back to file
    FILE *f = fopen(filename, "w");
    if (!f)
    {
        printf("Error opening file.\n");
        return;
    }

    temp = *head;
    while (temp)
    {
        fprintf(f, "%s  %s  %.2f  %s  %d-%d-%d  %d-%d-%d\n", temp->batch_id, temp->name, temp->marks,
                temp->assessment_status,
                temp->dob.day, temp->dob.month, temp->dob.year, temp->doj.day, temp->doj.month, temp->doj.year);
        temp = temp->next;
    }
    fclose(f);
    a = 1;
    printf("Record updated and saved successfully.\n\n ");
}
/********************************************************************************************************** */
/*delete the node*/
void delete_data_one(sll **ptr)
{
    if (*ptr == 0)
    {
        printf("No records found\n");
        return;
    }
    char bantch_id[20];
    printf("enter bantch_id to delete\n");
    scanf("%s", bantch_id);

    sll *del = *ptr, *prev;
    while (del)
    {
        if (strcmp(del->batch_id, bantch_id) == 0)
        {
            if (del == *ptr)
                *ptr = del->next;
            else
                prev->next = del->next;
            free(del);
            printf("data deleted\n");
            return;
        }
        prev = del;
        del = del->next;
    }
    printf("bantch_id not found\n");
}
/***************************************************************************************************** */
/*search student id*/
void search_student_id(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    char id[50];
    printf("Enter a id\n");
    scanf(" %s", id);
    while (ptr)
    {
        if (strcmp(ptr->batch_id, id) == 0)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}
/********************************************************************************************************** */
/*search student name*/
void search_student_name(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    char name[50];
    printf("Enter a name\n");
    scanf(" %[^\n]", name);
    while (ptr)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}

/************************************************************************************************************************ */
/*search student assessment*/
void search_assessment_status(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    char assessment_status[50];
    printf("Enter a assessment_status\n");
    scanf(" %s", assessment_status);
    while (ptr)
    {
        if (strcmp(ptr->assessment_status, assessment_status) == 0)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}
/************************************************************************************************************************************************************************* */
/*student search_student_birthdate*/
void search_student_birthdate(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    int day, month, year;

    printf("Enter a join date\n");
    scanf("%d %d %d", &day, &month, &year);
    while (ptr)
    {
        if (ptr->dob.day == day && ptr->dob.month == month && ptr->dob.year == year)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}
/***************************************************************************************************************************** */
/*student search_student_joindata*/
void search_student_joindata(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    int day, month, year;

    printf("Enter a join date\n");
    scanf("%d %d %d", &day, &month, &year);
    while (ptr)
    {
        if (ptr->doj.day == day && ptr->doj.month == month && ptr->doj.year == year)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}
/********************************************************************************************************************** */
void search_student_marks_range(sll *ptr)
{
    if (ptr == 0)
    {
        printf("no rcord found\n");
        return;
    }
    int f = 0;
    float marks1, marks2;

    printf("Enter a start range marke\n");
    scanf("%f", &marks1);
    printf("Enter a end range marke\n");
    scanf("%f", &marks2);
    while (ptr)
    {
        if (ptr->marks >= marks1 && ptr->marks <= marks2)
        {
            printf("%s  %s  %f  %s  %d-%d-%d  %d-%d-%d\n", ptr->batch_id, ptr->name, ptr->marks,
                   ptr->assessment_status,
                   ptr->dob.day, ptr->dob.month, ptr->dob.year, ptr->doj.day, ptr->doj.month, ptr->doj.year);
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 0)
        printf("no record found\n\n");
}
