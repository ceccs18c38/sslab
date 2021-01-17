#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#define SIZE 100
struct symtab{
 char label[10];
 int addr;
}sym[SIZE];
unsigned hash(char *s){
 unsigned hashval;
 for(hashval=0;*s!='\0';s++)
 hashval+=*s;
 return hashval%SIZE;
}
void initialize(){
 for(int i=0;i<SIZE;i++)
 sym[i].addr=-1;
}
void create(){
 char s[10];
 unsigned hashval;
 printf("Enter Label: ");
 scanf("%s",s);
 if(search(s)){
 printf("\nLabel exists");
 exit(0);
 }
 else{
 hashval=hash(s);
 strcpy(sym[hashval].label,s);
 printf("Enter address: ");
 scanf("%d",&sym[hashval].addr);
 printf("\nLabel created");
 }
}
void display(){
 printf("\nINDEX\tLABEL\t\tADDRESS\n\n");
 for(int i=0;i<SIZE;i++)
 {
 if(sym[i].addr!=-1)
 printf("%d\t%s\t\t%d\n",i,sym[i].label,sym[i].addr);
 }
}
int search(char label[]){
 if(sym[hash(label)].addr!=-1)
 return 1;
 return 0;
}
void main(){
 int op;
 char s[10];
 initialize();
 printf("\nSYMBOL TABLE IMPLEMENTATION\n");
 do{
 printf("\n\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.END\n");
 printf("\nEnter your option : ");
 scanf("%d",&op);
 switch(op){
 case 1: create();
 break;
 case 2: display();
 break;
 case 3: printf("\nEnter Label to be searched for: ");
 scanf("%s",s);
 if(search(s))
 printf("\nLabel is found with address: %d", sym[hash(s)].addr);
 else
 printf("\nLabel not Found");
 break;
 case 4: exit(0);
 }
 }while(1);
}
