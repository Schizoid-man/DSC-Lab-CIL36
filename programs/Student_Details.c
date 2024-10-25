#include <stdio.h>
struct STUDENT{
        char name[50];
        int roll_no;
        float marks;
};
void readStudentDetails(struct STUDENT *S, int n)
{
        for(int i =0;i<n;i++)
        {
        printf("\nEnter details for student %d \n", i+1);
        printf("\nName: ");
        scanf(" %[^\n]", S[i].name);
        printf("\nRoll No:");
        scanf("%d", &S[i].roll_no);
        printf("\nMarks: ");
        scanf("%f", &S[i].marks);
        }
}
void displayStudentDetails(struct STUDENT *S, int n)
{
        printf("\n Student Details: \n");
        for (int i=0;i<n;i++)
        {
                printf("\n Student %d: \n", i+1);
                printf("Name: %s \n" , S[i].name);
                printf("Roll No: %d \n", S[i].roll_no);
                printf("Marks: %.2f \n", S[i].marks);
        }
}
int main()
{
        int n;
        printf("Enter no of students");
        scanf("%d", &n);
        struct STUDENT students[n];
        readStudentDetails(students, n);
        displayStudentDetails(students,n);
        return 0;
}
