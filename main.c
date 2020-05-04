#include <stdio.h>

//STRUCTURE
struct marks
{
    char name[20];
    int roll_no;
    int science, english, maths;
    int total_marks;
};

//FUNCTIONS MADE
void add(struct marks[]);
void view(struct marks[]);
void delete(struct marks[]);
void update(struct marks[]);
void search(struct marks[]);

//GLOBAL VARIABLE
int n=0;

//MAIN FUNCTION
int main()
{
    int choice;
    struct marks record[100];
    
    do
    {
        printf("Choose your choice from the following :\n 1. Add\n 2. View\n 3. Delete\n 4. Update\n 5.Search\n 6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("U can ADD ENTRY \n");
                add(record);
                printf("\n");
                break;
            
            case 2: printf("Ur VIEW : \n");
                view(record);
                printf("\n");
                break;
                
            case 3: printf("U may delete : \n");
                delete(record);
                printf("\n");
                break;
                
            case 4: printf("U may update : \n");
                update(record);
                printf("\n");
                break;
                
            case 5: printf("U may search : \n");
                search(record);
                printf("\n");
                break;
        }
    }
    while(choice!=6);  //exits the function if we press 6
}

//ADD THE ELEMENTS IN STRUCTURE
void add(struct marks student[])
{
    int roll;
    int count;
    char Sname[20];
    n++;
    
rollno:    //GOTO LABEL
//ROLL NO. SHOULD NOT REPEAT
    printf("ROLL NO. : ");
    scanf("%d",&roll);
    count=0;
    for(int i =1; i<n; i++)
    {
        if(roll == student[i].roll_no)
            count++;
    }
    if(count>0)
    {
        printf("Already exists !!! \n");
        goto rollno;   //asks again to re-enter the roll no
    }
    else
        student[n-1].roll_no=roll;

nameS:     //GOTO LABEL
//NAME SHOULD BE ALPHABETICAL
    printf("NAME : ");
    scanf("%s",&Sname);
    for (int i = 0 ; i < strlen(Sname) ; i++)
    {
         if(isdigit(Sname[i]))
            {
             printf("Invalid name\n");
             goto nameS;   //asks again to enter the name
            }
        else
            strcpy(student[n-1].name,Sname);
    }
//MARKS
    printf("SCIENCE : ");
    scanf("%d",&student[n-1].science);
        
    printf("ENGLISH : ");
    scanf("%d",&student[n-1].english);
        
    printf("MATHS : ");
    scanf("%d",&student[n-1].maths);
        
//TOTAL MARKS CALCULATED
    student[n-1].total_marks=student[n-1].science+student[n-1].english+student[n-1].maths;
}

//DISPLAYS THE ELEMENTS OF THE STRUCTURE
void view(struct marks student[])
{
    for(int i=0; i<n; i++)
    {
        printf("NAME : %s\n",student[i].name);
        printf("ROLL NO : %d\n",student[i].roll_no);
        printf("SCIENCE MARKS : %d\n",student[i].science);
        printf("ENGLISH MARKS : %d\n",student[i].english);
        printf("MATHS MARKS : %d\n",student[i].maths);
        printf("TOTAL MARKS : %d\n",student[i].total_marks);
        printf("\n");
    }
}

//DELETES THE ELEMENTS OF THE STRUCTURE USING ROLL NO & DISPLAYS 'Deleted !!!' AFTER DONE ELSE EXITS
void delete(struct marks student[])
{
    int rn;
    printf("Plz Enter the Student roll no : ");
    scanf("%d",&rn);
    for(int i=0; i<n; i++)
    {
        if(rn==student[i].roll_no)
        {
            for(int j=i; j<n; j++)
            {
                student[j]=student[j+1];
                n--;
            }
            printf("Deleted !!!\n");
        }
    }
}

//UPDATES THE VALUES OF ELEMENTS & DISPLAYS 'Updated !!!' AFTER DONE ELSE EXITS
void update(struct marks student[])
{
    int rn1;
    printf("Enter the student roll no. : ");
    scanf("%d",&rn1);
    int choose;
    printf("What do u want to update?\n 1. Name\t 2. Science marks\t 3. English marks\t 4. Maths marks\n");
    scanf("%d",&choose);
    for(int i=0; i<n; i++)
    {
        if(rn1==student[i].roll_no)
        {
            if(choose==1)  //updates name
                {
                    printf("Enter the updated name : ");
                    scanf("%s",&student[i].name);
                }
                    
                if(choose==2)   //updates science marks and its corresponding total marks
                {
                    student[i].total_marks=student[i].total_marks-student[i].science;
                    printf("Enter the updated Science marks : ");
                    scanf("%d",&student[i].science);
                    student[i].total_marks=student[i].total_marks+student[i].science;
                }
                   
                if(choose==3)  //updates english marks and its corresponding total marks
                {
                    student[i].total_marks=student[i].total_marks-student[i].english;
                    printf("Enter the updated English marks : ");
                    scanf("%d",&student[i].english);
                    student[i].total_marks=student[i].total_marks+student[i].english;
                }
                    
                if(choose==4)  //updates maths marks and its corresponding total marks
                {
                    student[i].total_marks=student[i].total_marks-student[i].maths;
                    printf("Enter the updated Maths marks : ");
                    scanf("%d",&student[i].maths);
                    student[i].total_marks=student[i].total_marks+student[i].maths;
                }
            printf("Updated !!!");
        }
    }
}

//SEARCH QUERIES
void search(struct marks student[])
{
    char Sname[20];
    int roll,marks;
    int select;
    printf("How do u want to search a student?\n 1. Name\t 2. Roll no.\t 3. Below Minimum Total marks\t 4. Above Minimum Total marks\t 5. Highest Total marks\n");
    scanf("%d",&select);
    
    if(select==1) //displays all the students with given names
    {
        printf("Name u want to search : ");
        scanf("%s",&Sname);
        for(int j=0; j<n; j++)
        {
            if(strcmp(Sname,student[j].name)==0)
            {
                printf("NAME : %s\n ROLL NO. : %d\n TOTAL MARKS : %d\n",student[j].name,student[j].roll_no,student[j].total_marks);
            }
        }
    }
    if(select==2) //displays the name & total marks of student with given roll no
    {
        printf("Roll no. u want to search : ");
        scanf("%d",&roll);
        for(int j=0; j<n; j++)
        {
            if(roll==student[j].roll_no)
            {
                printf("NAME : %s\n ROLL NO. : %d\n TOTAL MARKS : %d\n",student[j].name,student[j].roll_no,student[j].total_marks);
            }
        }
    }
    if(select==3) //displays all the students scoring below minimum score
    {
        printf("Enter Minimum total marks score : ");
        scanf("%d",&marks);
        printf("Students scoring BELOW minimum marks\n");
        for(int j=0; j<n; j++)
        {
            if(student[j].total_marks<=marks)
            {
                printf("NAME : %s\n ROLL NO. : %d\n TOTAL MARKS : %d\n",student[j].name,student[j].roll_no,student[j].total_marks);
            }
        }
    }
    if(select==4) //displays all the students scoring above minimum score
    {
        printf("Enter Minimum total marks score : ");
        scanf("%d",&marks);
        printf("Students scoring ABOVE minimum marks\n");
        for(int j=0; j<n; j++)
        {
            if(student[j].total_marks>=marks)
            {
                printf("NAME : %s\n ROLL NO. : %d\n TOTAL MARKS : %d\n",student[j].name,student[j].roll_no,student[j].total_marks);
            }
        }
    }
    if(select==5)  //displays student info wd highest marks
    {
        printf("Students scoring HIGHEST total marks\n");
        int max = student[0].total_marks;
        for(int j=0; j<n; j++)
        {
            if(student[j].total_marks>max)
            {
                max=student[j].total_marks;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(student[j].total_marks==max)
            {
                printf("NAME : %s\n ROLL NO. :% d\n SCIENCE MARKS : %d\n ENGLISH MARKS : %d\n MATHS MARKS : %d\n TOTAL MARKS : %d\n",student[j].name,student[j].roll_no,student[j].science,student[j].english,student[j].maths,student[j].total_marks);
            }
        }
    }
}


