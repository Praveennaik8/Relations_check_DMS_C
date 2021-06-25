#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct relation
{
    char a,b;
}Relation;

char set[100];
int n,size;
Relation rel[100];

int readFile()
{
     FILE *fp=NULL;
     int i=-1;
     fp=fopen("relations.txt","r");
     if(fp==NULL)
     {
        printf("\n file open error");
        return 0;
     }
     while(!feof(fp))
     {
         ++i;
         fscanf(fp,"%s",str);
         rel[i].a=str[0];
         rel[i].b=str[2];
     }
     return i;
}
int isReflexive()
{
    int flag=0,i,j;
    for(i=0;i<size;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(set[i]==rel[j].a&&rel[j].a==rel[j].b)
            {
                flag=1;
                break;
            }

        }
        if(flag==0)
        {
            return 0;
        }
    }

    printf("\nReflexive\n");
    return 1;
}
int search(char x,int j)
{
    for(int i=j;i<n;i++)
    {
        if(rel[i].a==x)
        {
            return i;
        }
    }
    return -1;
}
int isTransitive()
{
     int i,j,temp1,temp2,found,k;
     for(i=0;i<n;i++)
     {
         j=0;
         while(j<n)
         {
           temp1=search(rel[i].b,j);

           if(temp1!=-1)
           {
               k=0;
               found=0;
               while(k<n)
               {

                   temp2=search(rel[i].a,k);
                   if(temp2==-1&&k==0)
                     return 0;
                   else if(temp2==-1)
                     break;
                   else if(rel[temp1].b==rel[temp2].b)
                   {

                      if(k==temp2)
                        k++;
                      else
                        k=temp2+1;
                   }
                   else
                     k=temp2+1;

                }
                if(j==temp1)
                   j++;
                else
                   j=temp1+1;


           }
           else if(temp1==-1&&j==0)
              return 0;
           else
              break;
         }
         if(found)
         {
            return 0;
         }

     }

     printf("\nTransitive\n");
     return 1;

}
int isSymmetric()
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(rel[i].a==rel[j].b&&rel[i].b==rel[j].a)
                flag=1;
        }
        if(flag==0)
            return 0;

    }
    return 1;
}

int main()
{
    int i=-1;
    char str[10];
    printf("\nEnter the set elements continuously\n");
    gets(set);
    size=strlen(set);

    n=readFile();
    printf("\nRelation is \n");
    for(i=0;i<n;i++)
    {
        printf(" %c , %c \n",rel[i].a,rel[i].b);
    }
     fclose(fp);

    if(isSymmetric()&&isReflexive()&&isTransitive())
    {
        printf("\nThe Realtion is Equivalence relation,not partial ordering\n");
        return 0;
    }
    if(!isSymmetric()&&isReflexive()&&isTransitive())
    {
        printf("\nThe Realtion is Partial ordering,not equivalence relation\n");
        return 0;
    }
    printf("\nIt is neither Equivalence relation nor Partial ordering\n");
}
