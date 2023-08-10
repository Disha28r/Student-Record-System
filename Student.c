#include<stdio.h>

#include<stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char class[10];
    char city[20];
    float perc;
};
int main()
{
    int choice;
    while(choice!=5)
    {
        printf("\n\n\t\t\t\t----STUDENT DATABASE MANAGEMENT SYSTEM----");
        printf("\n\n\n\t\t\t\t  1. Add Student Data\n");
        printf("\t\t\t\t  2. Display Student Record\n");
        printf("\t\t\t\t  3. Search Student\n");
        printf("\t\t\t\t  4. Delete Record\n");
        printf("\t\t\t\t  5. Exit\n");
        printf("\t\t\t\t  ________________________________\n");
        printf("\t\t\t\t  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                
                addstudent();
                
                break;
            case 2:
                studentrecord();
                
                break;
            case 3:
                searchstudent();
                
                break;
            case 4:
                delete();
                
                break;
            case 5:
                printf("\n\t\t\t\tThank you for using this Database!");
                break;
            default:
                printf("\n\t\t\t\tEnter valid choice");
            

        }

    }
   return 0; 
}
void addstudent()
{
    char another;
    FILE *fp;
    struct student info;

    do{
        
        printf("\t\t\t\t----Add Student Info----\n\n");
        fp=fopen("student_info.txt","a");
        printf("\n\t\t\t\tEnter first name: ");
        scanf("%s",&info.first_name);
        printf("\n\t\t\t\tEnter last name :");
        scanf("%s",&info.last_name);
        printf("\n\t\t\t\tEnter roll number :");
        scanf("%d",&info.roll_no);
        printf("\n\t\t\t\tEnter Class :");
        scanf("%s",&info.class);
        printf("\n\t\t\t\tEnter City :");
        scanf("%s",&info.city);
        printf("\n\t\t\t\tEnter percentage :");
        scanf("%f",&info.perc);
        printf("\n\t\t\t\t________________________________\n");

        if(fp==NULL)
        {
            fprintf(stderr,"\t\t\tCan't open file");

        }else{
            printf("\t\t\tRecord stored successfully\n");
        }
        fwrite(&info,sizeof(struct student),1,fp);
        fclose(fp);

        printf("\t\t\tDo you want to add another record?(y/n):");
        scanf("%s",&another);

    }while(another=='y'||another=='Y');
}

void studentrecord()
{
    FILE *fp;
    struct student info;
    fp=fopen("student_info.txt","r");

    printf("\t\t\t\t----Student Records----\n\n\n");
    if(fp==NULL)
    {
        fprintf(stderr,"\t\t\t\tCan't open file\n");

    }else{
        printf("\t\t\t\tRecords\n");
        printf("\t\t\t\t________________________________\n\n");
    }
    while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\tStudent name: %s %s",info.first_name,info.last_name);
        printf("\n\t\t\t\tRoll no     : %d",info.roll_no);
        printf("\n\t\t\t\tClass       : %s",info.class);
        printf("\n\t\t\t\tCity        : %s",info.city);
        printf("\n\t\t\t\tPercentage  : %f",info.perc);
        printf("\n\t\t\t\t________________________________\n");
    }
    fclose(fp);

}
void searchstudent(){
    FILE *fp;
    struct student info;
    int roll_no,found=0;

    fp=fopen("student_info.txt","r");
    printf("\t\t\t\t----Search Student Record----\n\n\n");
    printf("\t\t\tEnter roll number:");
    scanf("%d",&roll_no);

    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no==roll_no){
        found=1;
        printf("\n\t\t\t\tStudent name: %s %s",info.first_name,info.last_name);
        printf("\n\t\t\t\tRoll no     : %d",info.roll_no);
        printf("\n\t\t\t\tClass       : %s",info.class);
        printf("\n\t\t\t\tCity        : %s",info.city);
        printf("\n\t\t\t\tPercentage  : %f",info.perc);
        printf("\n\t\t\t\t________________________________\n");
    }
    }
    if(!found){
        printf("\n\t\t\tRecord not found\n");
    }
    fclose(fp);

}
void delete()
{
     FILE *fp,*fp1;
    struct student info;
    int roll_no,found=0;

    printf("\t\t\t\t----Search Student Record----\n\n\n");
    fp=fopen("student_info.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter roll number:");
    scanf("%d",&roll_no);

    if(fp==NULL)
    {
        fprintf(stderr,"\t\t\t\tCan't open file\n");
    }
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no==roll_no){
        found=1;
        }else{
            fwrite(&info,sizeof(struct student),1,fp1);
        }

    }
    fclose(fp);
    fclose(fp1);

    if(found){
        remove("student_info.txt");
        rename("temp.txt","student_info.txt");
        printf("\n\t\t\tRecord deleted successfully\n");
    }
    if(!found)
    {
        printf("\t\t\t\tRecord not found");
    }


}