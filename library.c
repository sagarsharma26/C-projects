#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
    int issued;
};

void addBook();
void displayBook();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();

int main()
{
    int choice;

    while(1)
    {
        printf("\n (*_*) LIBRARY MANAGEMENT SYSTEM (*_*)\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBook();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}


void addBook()
{
    struct Book b;
    FILE *fp;

    fp=fopen("library.dat","ab");

    printf("\nEnter Book ID: ");
    scanf("%d",&b.id);

    printf("Enter Book Name: ");
    scanf("%s",b.name);

    printf("Enter Author Name: ");
    scanf("%s",b.author);

    b.issued=0;

    fwrite(&b,sizeof(b),1,fp);

    fclose(fp);

    printf("Book Added Successfully!\n");
}


void displayBook()
{
    struct Book b;
    FILE *fp;

    fp=fopen("library.dat","rb");

    if(fp==NULL)
    {
        printf("No books found\n");
        return;
    }


    printf("\nID\tNAME\tAUTHOR\tSTATUS\n");

    while(fread(&b,sizeof(b),1,fp))
    {
        printf("%d\t%s\t%s\t",
        b.id,b.name,b.author);

        if(b.issued)
            printf("Issued\n");
        else
            printf("Available\n");
    }

    fclose(fp);
}


void searchBook()
{
    struct Book b;
    FILE *fp;
    int id,found=0;

    printf("Enter Book ID: ");
    scanf("%d",&id);

    fp=fopen("library.dat","rb");


    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id==id)
        {
            printf("\nBook Found\n");
            printf("Name: %s\n",b.name);
            printf("Author: %s\n",b.author);
            found=1;
        }
    }


    if(found==0)
        printf("Book not found");

    fclose(fp);
}


void issueBook()
{
    struct Book b;
    FILE *fp,*temp;

    int id;

    printf("Enter Book ID: ");
    scanf("%d",&id);


    fp=fopen("library.dat","rb");
    temp=fopen("temp.dat","wb");


    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id==id)
        {
            if(b.issued==0)
            {
                b.issued=1;
                printf("Book Issued\n");
            }
            else
            {
                printf("Already Issued\n");
            }
        }

        fwrite(&b,sizeof(b),1,temp);
    }


    fclose(fp);
    fclose(temp);


    remove("library.dat");
    rename("temp.dat","library.dat");
}


void returnBook()
{
    struct Book b;
    FILE *fp,*temp;

    int id;

    printf("Enter Book ID: ");
    scanf("%d",&id);


    fp=fopen("library.dat","rb");
    temp=fopen("temp.dat","wb");


    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id==id)
        {
            b.issued=0;
            printf("Book Returned\n");
        }

        fwrite(&b,sizeof(b),1,temp);
    }


    fclose(fp);
    fclose(temp);


    remove("library.dat");
    rename("temp.dat","library.dat");
}



void deleteBook()
{
    struct Book b;
    FILE *fp,*temp;

    int id;

    printf("Enter Book ID: ");
    scanf("%d",&id);


    fp=fopen("library.dat","rb");
    temp=fopen("temp.dat","wb");


    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id!=id)
        {
            fwrite(&b,sizeof(b),1,temp);
        }
        else
        {
            printf("Book Deleted\n");
        }
    }


    fclose(fp);
    fclose(temp);


    remove("library.dat");
    rename("temp.dat","library.dat");
}