#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
char name[50];
char mname[50];
char uname[]="admin";
char aname[50];
struct log
{
	char fullname[50];
	char username[50];
	char password[50];
};
struct product
{
	int product_id;
	char product_code[50];
	char product_name[50];
	char product_type[50];
	char product_weight[50];
	float cost_per_item;
	char total_stock[50];
};
struct customer
{
	char customername[50];
	char mobilenumber[50];
	char Productname[50];
	float priceperitem;
	int totalitems;
	float totalcost;
	char status[50];
};
void menu();
void isAdminnameTaken(const char *);
void signup();
void login();
void addProduct();
void view();
void productReport();
void searchProduct();
void modifyProduct();
void deleteProduct();
void addsells();
void sellsReport();
void logout();
void gotoxy(int ,int );
int main()
{
    gotoxy(15,8);
    printf("<--:Sales  Management System:-->");
    gotoxy(19,15);
    printf("Press any key to continue.....");
    getch();
    menu();
    return 0;
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//menu function
void menu()
{
    int choice;
    system("cls"); //clrscr()
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1  : Admin Signup.");
    gotoxy(10,8);
    printf("2  : Admin Login.");
    gotoxy(10,9);
    printf("3  : Add Product.");
    gotoxy(10,10);
    printf("4  : Product Reports.");
    gotoxy(10,11);
    printf("5  : Search Product.");
    gotoxy(10,12);
    printf("6  : Modify Product.");
    gotoxy(10,13);
    printf("7  : Delete Product.");
    gotoxy(10,14);
    printf("8  : Add Sells.");
    gotoxy(10,15);
    printf("9  : Sells Report.");
    gotoxy(10,16);
    printf("10 : Log Out.");
    gotoxy(10,18);
    printf("If you have a account please login Otherwise please Signup\n");
    gotoxy(10,20);
    printf("Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        signup();
        break;

    case 2:
        login();
        break;
    case 3:
        addProduct();
        break;
    case 4:
        productReport();
        break;
	case 5:
        searchProduct();
        break;
    case 6:
        modifyProduct();
        break;
	case 7:
		deleteProduct();
		break;
	case 8:
		addsells();
		break;
	case 9:
		sellsReport();
		break;
	case 10:
		logout();
		break;
    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
//checks Admin name is already signedup or not 
void isAdminnameTaken(const char *username) {
    FILE *fb;
	fb=fopen("nazeer.txt", "rb");
    if (fb==NULL) {
    	gotoxy(10,6);
        printf("Error opening file");
       exit(1);
    }
    struct log l;
    while (fread(&l,sizeof(struct log),1,fb)==1) {
        if (strcmp(username,l.username)==0) {
            fclose(fb);
            printf("Admin already exists.....\n");
            signup();
        }
    }
	fclose(fb);
}
//Admin signup
void signup()
{
	FILE *f;
	f=fopen("nazeer.txt","ab");
	struct log l;
	gotoxy(10,5);
	printf("<--:ADMIN SIGNUP:-->");
	gotoxy(10,8);
	printf("Enter Admin Full Name:");
	scanf("%s",l.fullname);
	gotoxy(10,9);
	printf("Enter Admin User Id:");
	scanf("%s",l.username);
	isAdminnameTaken(l.username);
	gotoxy(10,11);
	printf("Enter Password:");
	scanf("%s",l.password);	
	fwrite(&l,sizeof(l),1,f);
	fclose(f);
	gotoxy(10,12);
	printf("Successfully Signup");
	gotoxy(10,16);
	gotoxy(10,18);
    printf("Press any key to continue.....");
    getch();
    system("cls");
    menu();
}
//Admin login
void login()
{
    char username[50];
    char password[50];
    FILE *f;
    int flag = 0;
    f = fopen("nazeer.txt", "rb");
    struct log l;
    gotoxy(10,5);
    printf("<--:ADMIN LOGIN:-->");
	gotoxy(10,8);
    printf("Admin Name:");
    scanf("%s", username);
    gotoxy(10,9);
	strcpy(name,username);
	strcpy(mname,username);
	strcpy(aname,strcat(mname,uname));
    printf("Password:");
    scanf("%s", password);
    while(fread(&l,sizeof(l),1,f))
    {
        if(strcmp(username,l.username)==0&&strcmp(password,l.password)==0)
        {
        	flag=1;
        	break;
		}
    }
    fclose(f);
    if (flag)
    {
    	gotoxy(10,14);
        printf("Successfully Login\n");
    }
    else
    {
    	gotoxy(10,15);
        printf("Please Enter correct Admin name and Password\n");
    }
    gotoxy(10, 18);
    printf("Press any key to continue.....");
    getch();
    system("cls");
	menu();
}
//Adding a product
void addProduct()
{	
    FILE *f;
    FILE *fp;
    struct product p;
    struct log l;
    char *fn;
    char another ='y';
    system("cls");
    fp = fopen(name,"ab");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD PRODUCT:-->");
         gotoxy(10,5);
        printf("Enter details of Product.....");
        gotoxy(10,7);
        printf("Enter Product ID :");
        scanf("%d",&p.product_id);
        fflush(stdin);
        gotoxy(10,8);
        printf("Enter Product Code : ");
        gets(p.product_code);
        gotoxy(10,9);
        printf("Enter Product Name : ");
        gets(p.product_name);
        gotoxy(10,10);
        printf("Enter Product Type : ");
        gets(p.product_type);
        gotoxy(10,11);
        printf("Enter Product Weight : ");
        gets(p.product_weight);
        gotoxy(10,12);
        printf("Enter Product Cost Per One Item : ");
        scanf("%f",&p.cost_per_item);
        gotoxy(10,13);
        printf("Enter Total Stock Of The Product : ");
        fflush(stdin);
        gets(p.total_stock);
        fwrite(&p,sizeof(p),1,fp);
        gotoxy(10,16);
        printf("Want to add of another product? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.....");
    getch();
    system("cls");
    menu();
}
//view product details
void view()
{
	FILE *fp=fopen(name,"rb");
    int i=1,j;
    struct product p;
	gotoxy(10,18);
    printf("S.No.   Product_ID   Product_Code   Name of The Product   Product Type   Product Weight   Cost Per Item   Total Stock");
    gotoxy(10,20);
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    if(fp == NULL){
        gotoxy(10,22);
        printf("Error opening file.");
        exit(1);
    }
    j = 8;
	while (fread(&p, sizeof(p), 1, fp)==1) {
        printf("%12d%14d%16s%18s%18s%16s%16f%16s", i, p.product_id, p.product_code, p.product_name, p.product_type, p.product_weight, p.cost_per_item, p.total_stock);
        printf("\n");
        i++;
        j++;
    }
    fclose(fp);	
}
//View Product Report
void productReport()
{
    FILE *fp=fopen(name,"rb");
    int i=1,j;
    struct product p;
    gotoxy(10,3);
    printf("<--:VIEW PRODUCT REPORT:-->");
    gotoxy(10,5);
    printf("S.No.   Product_ID   Product_Code   Name of The Product   Product Type   Product Weight   Cost Per Item   Total Stock");
    gotoxy(9,7);
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    if(fp == NULL){
        gotoxy(10,10);
        printf("Error opening file.");
        exit(1);
    }
    j = 8;

    while (fread(&p, sizeof(p), 1, fp)==1) {
        printf("%12d%14d%16s%18s%18s%16s%16f%16s", i, p.product_id, p.product_code, p.product_name, p.product_type, p.product_weight, p.cost_per_item, p.total_stock);
        printf("\n");
        i++;
        j++;
    }
    fclose(fp);
    printf("\n\n");
    printf("         Press any key to continue.....");
    getch();
    system("cls");
    menu();
}
//search for a product
void searchProduct()
{
    FILE *fp;
    struct product p;
    char pname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH PRODUCT:-->");
    gotoxy(10,5);
    printf("Enter name of the product : ");
    fflush(stdin);
    gets(pname);
    fp = fopen(name,"rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,fp ) == 1){
        if(strcmp(pname,p.product_name) == 0){
            gotoxy(10,8);
            printf("Product_ID : %d",p.product_id);
            gotoxy(10,9);
            printf("Product Code : %s",p.product_code);
            gotoxy(10,10);
            printf("Product Name : %s",p.product_name);
            gotoxy(10,11);
            printf("Product Type : %s",p.product_type);
            gotoxy(10,12);
            printf("Product Weight : %s",p.product_weight);
            gotoxy(10,13);
            printf("Cost Per Item : %f",p.cost_per_item);
            gotoxy(10,14);
            printf("Total Stock : %s",p.total_stock);
        }
    }
    fclose(fp);
    gotoxy(10,17);
    printf("Press any key to continue.....");
    getch();
    menu();
}
//modify the product details based on product name
void modifyProduct()
{
    char pname[20];
    FILE *fp;
    struct product p;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY PRODUCT:-->");
    gotoxy(10,5);
    printf("Enter name of product to modify: ");
    scanf("%s",pname);
    fp = fopen(name,"rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&p,sizeof(p),1,fp) == 1)
    {
        if(strcmp(pname,p.product_name) == 0){
            gotoxy(10,7);
            printf("Enter Product ID: ");
            scanf("%d",&p.product_id);
            fflush(stdin);
            gotoxy(10,8);
            printf("Enter product code : ");
            gets(p.product_code);
            gotoxy(10,9);
            printf("Enter product name : ");
            gets(p.product_name);
            gotoxy(10,10);
            printf("Enter product type : ");
            gets(p.product_type);
            gotoxy(10,11);
            printf("Enter product weight : ");
            gets(p.product_weight);
            gotoxy(10,12);
            printf("Enter cost per item : ");
            scanf("%f",&p.cost_per_item);
            gotoxy(10,13);
            printf("Enter total stock : ");
            fflush(stdin);
            gets(p.total_stock);
            fseek(fp,sizeof(p),SEEK_CUR);
            fwrite(&p,sizeof(p),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,17);
    printf("Press any key to continue.....");
    getch();
    menu();
}
//deletes a product based on product name
void deleteProduct()
{
    char pname[20];
    FILE *fp,*ft;
    struct product p;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE PRODUCT:-->");
    gotoxy(10,5);
    printf("Enter name of product to delete record : ");
    fflush(stdin);
    gets(pname);
    fp = fopen(name,"rb");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,fp) == 1){
        if(strcmp(pname,p.product_name)!=0)
            fwrite(&p,sizeof(p),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove(name);
    rename("temp.txt",name);
    gotoxy(10,10);
    printf("Press any key to continue.....");
    getch();
    menu();
}
//adding sells
void addsells() {
    FILE *fp, *f;
    int i = 1;
    float bill=0;
    struct customer c;
    char another = 'y';
    system("cls");
    fp = fopen(aname, "ab+");
    if (fp == NULL) {
        gotoxy(10, 5);
        printf("Error opening file\n");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y') {
        gotoxy(10, 6);
        printf("<--:ADD SELLS:-->");
        gotoxy(10, 8);
        printf("Enter details of sales...");
        gotoxy(10, 10);
        printf("Enter Customer Name: ");
        gets(c.customername);
        gotoxy(10, 12);
        printf("Enter Customer Mobile Number: ");
        gets(c.mobilenumber);
        gotoxy(10, 14);
        printf("Select The Products...");
        view();
        printf("\n");
        gotoxy(10, 30);
        printf("Enter the product name: ");
        gets(c.Productname);
        gotoxy(10, 31);
        printf("Enter Quantity: ");
        fflush(stdin);
        scanf("%d", &c.totalitems);
        gotoxy(10,32);
        printf("Enter Price per one item:");
        scanf("%f",&c.priceperitem);
        bill+=c.totalitems*c.priceperitem;
        c.totalcost=bill;
        gotoxy(10,33);
        printf("Total Bill: Rs.%.2f\n", bill);
        gotoxy(10,34);
        printf("Bill Paid or Not:");
        fflush(stdin);
        scanf("%s",c.status);
        fwrite(&c, sizeof(c), 1, fp);
        gotoxy(10,35);
        printf("Want to add another product? Press 'y' for yes or 'n' for no: ");
        scanf(" %c", &another);
        system("cls");
    }
    fclose(fp);
    gotoxy(10,15);
    printf("Press any key to continue.....");
    getch();
    system("cls");
    menu();
}
//sells report
void sellsReport() {
    FILE *fp;
    int i = 1;
    struct customer c;
    gotoxy(10,2);
	printf("<--:VIEW PRODUCT REPORT:-->");
    gotoxy(10,5);
    printf("S.No.   Customer Name   Customer Mobile Number   Product Name   Total Items   Price Per Item   Bill    Status\n");
 	gotoxy(10,8);
    printf("-------------------------------------------------------------------------------------------------------------\n");
	int j=9;
    fp = fopen(aname, "rb+");
    if (fp == NULL) {
        printf("Error opening file: %s\n", aname);
        exit(1);
    }

    while (fread(&c, sizeof(c), 1, fp) == 1) {
    	gotoxy(10,j);
        printf("%-8d%-20s%-25s%-15s%-13d%-14.2f%-10.2f%-8s\n", i, c.customername, c.mobilenumber, c.Productname, c.totalitems, c.priceperitem, c.totalcost, c.status);
        i++;
        j++;
    }

    fclose(fp);

    printf("\n\n");
    gotoxy(10,j+8);
    printf("Press any key to continue.....");
    getch();
    system("cls");
    menu();
}
void logout()
{
	gotoxy(10,5);
	printf("Logout");
	exit(1);
}
