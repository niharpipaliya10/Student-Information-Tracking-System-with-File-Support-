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
void add_student_data(sll **);
void print_node(sll *);
void save_file(sll *);
void search_name(sll *);
void search_id(sll *);
void search_assessment_status(sll *);
void search_student_joindata(sll *);
void search_student_birthdate(sll *);
void read_file(sll **);
void edit_file(sll **);

void main()
{
    int op;
    sll *headptr = 0;
    while (1)
    {
        printf("1)add student data\n2)show all data\n3)save data in file\n4)search name student\n5)search banch_id\n6)search earch_assessment_status\n7)search_student_joindata\n8)search_student_birthdate\n9)read_file\n10)edit data\n11)exit\n");
        printf("Enter a op no:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add_student_data(&headptr);
            break;
        case 2:
            print_node(headptr);
            break;
        case 3:
            save_file(headptr);
            break;
        case 4:
            search_name(headptr);
            break;
        case 5:
            search_id(headptr);
            break;
        case 6:
            search_assessment_status(headptr);
            break;
        case 7:
            search_student_joindata(headptr);
            break;
        case 8:
            search_student_birthdate(headptr);
            break;
        case 9:
            read_file(&headptr);
            break;
        case 10:
            edit_file(&headptr);
            break;
        case 11:
            exit(0);
            break;

        default:
            printf("you choose invlid option\n");
            break;
        }
    }
}
/****************************************************************************************************** */
/*add student data*/
void add_student_data(sll **ptr)
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
    printf("Student added successfully!\n");
}
/***************************************************************************************************** */
/* load all data */
void print_node(sll *ptr)
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
    printf("\n");
}
/***************************************************************************************************** */
/* save data in file*/
void save_file(sll *ptr)
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

    fclose(f);
}
/********************************************************************************************************** */
/*search student name*/
void search_name(sll *ptr)
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
        printf("no record found\n");
}
/***************************************************************************************************** */
/*search student id*/
void search_id(sll *ptr)
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
        printf("no record found\n");
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
        printf("no record found\n");
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
        printf("no record found\n");
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
        printf("no record found\n");
}
/***************************************************************************************************************************************************** */
/*read data from file*/
void read_file(sll **ptr)
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
    printf("read data successful\n");
}
/********************************************************************************************************************************************* */
/*edit data*/
void edit_file(sll **head)
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
    printf("Record updated and saved successfully.\n");
}
