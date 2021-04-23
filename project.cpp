//I am using Recursion to solve this problem
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
COORD coord = {0,0};
void gotoxy(int x,int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct node
{
    int no;
    int food_no;
    int qua;
    struct node *next;
};
int beriany=NULL,berger=NULL,pizza=NULL,singara=NULL,somoca=NULL,tehari=NULL;
int service_no=0;
int receve=0;
int served=0;
struct node *head;
void enqueue(int x,int y,int z)
{
    receve++;
    struct node *temp=(struct node *)malloc(sizeof(struct node));

    temp->no=x;
    temp->food_no=y;
    temp->qua=z;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
    temp1->next=temp;
    }
}
void dqueue()
{
    served++;
    struct node *temp=head;
    head=temp->next;
    free(temp);
}
void paied(int x,int y)
{
    if(x==1)
        printf("\n\t\t\t\tYour total bill:%d\n",120*y);
    else if(x==2)
        printf("\n\t\t\t\tYour total bill:%d\n",60*y);
    else if(x==3)
        printf("\n\t\t\t\tYour total bill:%d\n",60*y);
    else if(x==4)
        printf("\n\t\t\t\tYour total bill:%d\n",8*y);
    else if(x==5)
        printf("\n\t\t\t\tYour total bill:%d\n",8*y);
    else if(x==6)
        printf("\n\t\t\t\tYour total bill:%d\n",70*y);
}
void food_name(int x)
{
    if(x==1)
        printf("\t\t\t\tYou are order for Beriany\n\t\t\t\t\tPrice :120 bdt");
    else if(x==2)
        printf("\t\t\t\tYou are order for Berger\n\t\t\t\t\tPrice :60 bdt");
    else if(x==3)
        printf("\t\t\t\tYou are order for Pizza\n\t\t\t\t\tPrice :60 bdt");
    else if(x==4)
        printf("\t\t\t\tYou are order for Singara\n\t\t\t\t\tPrice :8 bdt");
    else if(x==5)
        printf("\t\t\t\tYou are order for Somica\n\t\t\t\t\tPrice :8 bdt");
    else if(x==6)
        printf("\t\t\t\tYou are order for Tehari\n\t\t\t\t\tPrice :70 bdt");
}
void stok_order(int x,int y)
{
    if(x==1)
    {
        beriany=beriany-y;
        if(beriany<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
    else if(x==2)
    {
        berger=berger-y;
        if(berger<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
    else if(x==3)
    {
        pizza=pizza-y;
        if(pizza<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
    else if(x==4)
    {
        singara=singara-y;
        if(singara<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
    else if(x==5)
    {
        somoca=somoca-y;
        if(somoca<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
    else if(x==6)
    {
        tehari=tehari-y;
        if(tehari<0)
            printf("\n\t\t\t\tStoke is overloaded back to home and modify this order");
    }
}
void edet(int x)
{
    int a,b,c;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(x==temp->no)
        {
            printf("Service no:%d",temp->no);
            printf("Food no:");
            temp->qua=scanf("%d",&b);
            food_name(b);
            printf("Food quantity:");
            temp->food_no=scanf("%d",&c);
            paied(b,c);
            break;
        }
    }
}
void display_hole()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("\t\t\t\tService no:%d\n\t\t\t\tFood no:%d\n\t\t\t\tFood quantity:%d\n\n",temp->no,temp->food_no,temp->qua);
        food_name(temp->food_no);
        paied(temp->no,temp->qua);
        temp=temp->next;
    }
}
void display();
void input();
void home()
{
    int choice;
    system("cls");
    gotoxy(50,5);
    printf("HOME");
    gotoxy(20,10);
    printf("1-Add order");
    gotoxy(20,11);
    printf("2-Serve order");
    gotoxy(20,12);
    printf("3-Display");
    gotoxy(20,13);
    printf("4-Display order with record");
    gotoxy(20,14);
    printf("5-Modify order");
    gotoxy(20,15);
    printf("6-Display stoke");
    gotoxy(15,17);
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        input();
    }
    else if(choice==2)
    {
        system("cls");
        dqueue();
        printf("Food supply successfully\n");
        printf("Press any key to go back to your main menu\n");
        getch();
        home();//Recursion
    }
    else if(choice==3)
    {
        system("cls");
        display();
        printf("Press any key to go back to your main menu\n");
        getch();
        home();
    }
    else if(choice==4)
    {
        int p;
        system("cls");
        display_hole();
        printf("Press any key to go back to your main menu\n");
        getch();
        home();
    }
    else if(choice==5)
    {
        int q;
        system("cls");
        printf("Enter the service number to modify order");
        scanf("%d",&q);
        edet(q);
        printf("Order Successfully modify.\nPress any key to go back to your main menu\n");
        getch();
        home();
    }
    else if(choice==6)
    {
        system("cls");
        printf("\n\t\t\t\tberiany=%d\n\t\t\t\tberger=%d\n\t\t\t\tpizza=%d\n\t\t\t\tsingara=%d\n\t\t\t\tsomoca=%d\n\t\t\t\ttehari=%d",beriany,berger,pizza,singara,somoca,tehari);
        printf("Press any key to go back to your main menu\n");
        getch();
        home();
    }
}
void input()
{
    service_no++;
    int e;
    int b;
    int c;
    int f;
    printf("Add item\n");
    printf("\t\t\t\tService no:%d",service_no);
    printf("\n\t\t\t\tFood no:");
    scanf("%d",&b);
    food_name(b);
    printf("\n\t\t\t\tFood quantity:");
    scanf("%d",&c);
    //f=b*c;
    stok_order(b,c);
    paied(b,c);
    enqueue(service_no,b,c);
    printf("Order Successfully Inserted.\nDo you want to continue ?\n1:-Yes\n2:-No \n");
    scanf("%d",&e);
    if(e==2)
        home();
    else if(e==1)
        input();
}
void display()
{
    system("cls");
    int choice,x;
    gotoxy(20,10);
    printf("1-Total receive");
    gotoxy(20,11);
    printf("2-Total serve order");
    gotoxy(20,12);
    printf("3-Waiting\n\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Total receive:-%d\n",receve);
    }
    else if(choice==2)
    {
        printf("Total serve:-%d\n",served);
    }
    else if(choice==3)
    {
        printf("Waiting:-%d\n",receve-served);
    }
    printf("If you want to go HOME type 1,or continue type 2\n\t\t\t");
    scanf("%d",&x);
    if(x==1)
        home();
    else if(x==2)
        display();
}
int main()
{
    printf("Enter your stoke\n");
    printf("Beriany:");
    scanf("%d",&beriany);
    printf("Berger:");
    scanf("%d",&berger);
    printf("Pizza:");
    scanf("%d",&pizza);
    printf("Singara:");
    scanf("%d",&singara);
    printf("Somoca:");
    scanf("%d",&somoca);
    printf("Tehari:");
    scanf("%d",&tehari);
    home();
    return 0;
}
