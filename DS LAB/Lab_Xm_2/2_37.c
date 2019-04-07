#include<stdio.h>
#include<string.h>

typedef struct
{
    char add[150];
    char city[150];
    char country[100];
    char postalcode[10];


}address;

typedef struct
{
    char name[100];
    char NID[100];
    address y;
    int age;
    int salary;
}personal_info;


int main()
{
    int n,i,j,l,o,inc,sal,tsalary;



    personal_info x[1000],temp;
    char line[200],tem,nid[200];
    FILE *fp;
    char *input_file = "input.txt";
    fp=fopen(input_file,"r");
    for(j=0;j<100;j++)
    {


        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].name,line);


        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].NID,line);


        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].y.add,line);


        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].y.city,line);


        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].y.country,line);

        fgets(line,200,fp);
        l=strlen(line);
        line[l-1]='\0';
        strcpy(x[j].y.postalcode,line);


        fscanf(fp,"%d",&x[j].age);
        fscanf(fp,"%d",&x[j].salary);
        fscanf(fp,"%c",&tem); //for new line
        if(tem==NULL) break;



    }

     n=j;
     fclose(fp);


     scanf("%d",&o);
     if(o==1)
     {
         scanf("%s",nid);
         for(i=0;i<n;i++)
         {
             int p=strcmp(nid,x[i].NID);
             if(p==0) printf("%s\n",x[i].name);
         }
     }
     else if(o==2)
     {
         scanf("%d",&sal);
         for(i=0;i<n;i++)
         {
             if(x[i].salary<sal) printf("%s\n",x[i].name);
         }
     }
     else if(o==3)
     {
         scanf("%s %d",nid,&inc);
         for(i=0;i<n;i++)
         {
             int r= strcmp(nid,x[i].NID);
             if(r==0)
             {
                 tsalary=(x[i].salary )*(inc/100.0)+ (x[i].salary);
                 printf("Salary of %s has been increased to %d\n",x[i].name,tsalary);
             }

         }
     }

     else
     {
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                 if(x[i].salary>x[j].salary)
                 {
                     temp=x[i];
                     x[i]=x[j];
                     x[j]=temp;
                 }
                 if(x[i].salary==x[j].salary)
                 {
                     if(x[i].age<x[j].age)
                     {
                     temp=x[i];
                     x[i]=x[j];
                     x[j]=temp;
                     }
                 }
             }
         }

         for(i=0;i<n;i++)
      {
          puts(x[i].name);
          puts(x[i].NID);
          puts(x[i].y.add);
          puts(x[i].y.city);
          puts(x[i].y.country);
          puts(x[i].y.postalcode);
          printf("%d\n",x[i].age);
          printf("%d\n",x[i].salary);
      }
     }

    return 0;
}
