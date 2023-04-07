/* Student record
    with adt implementation
    insert,delete,update,search*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct sRecord{
    char name[31];
    int quiz1,quiz2,quiz3;
}sREC;

typedef struct sData{
    sREC data[MAX];
    int last;
}LIST;
LIST L;

int isEmpty();
int locateRecord(char nm[31]);
void addRec(sREC w);
int createNull();
int menu();//main menu
int isFull();
void insertRecord();
void deleteRecord(char nm[31]);
void displayRecord();
void searchRecord(char nm[31]);
void updateRecord(char nm[31]);
void saveRecord();
void retrieveRecord();

void retrieveRecord(){
    FILE *fp;
    sREC w;
    fp=fopen("DATA_STUD.txt","r");
    if(fp==NULL){
        printf("file not found!\n");
        system("pause");
    }
    else{
        while(!feof(fp)){
            fscanf(fp,"%s %d %d %d\n",&w.name,&w.quiz1,&w.quiz2,&w.quiz3);
            addRec(w);
        }
    }
    fclose(fp);
}
void saveRecord(){
    FILE *fp;
    fp=fopen("DATA_STUD.txt","w+");
    if(fp==NULL){
        printf("file not found!\n");
        system("pause");
    }
    else{
        for(int i=0;i<=L.last;i++){
             fprintf(fp,"%s\n%d %d %d\n\n",L.data[i].name,L.data[i].quiz1,L.data[i].quiz2,L.data[i].quiz3);
        }

    }
    fclose(fp);
}
void updateRecord(char nm[31]){
     int i,p;

    if(isEmpty()){
        printf("Empty Records\n");
        system("pause");
    }
    else{
        p=locateRecord(nm);
        if(p==-1){
            printf("Record not Found\n");
            system("pause");
        }
        else{
            printf("Name: %s\n",L.data[p].name);
            printf("Quiz 1: %d\n",L.data[p].quiz1);
            printf("Quiz 2: %d\n",L.data[p].quiz2);
            printf("Quiz 3: %d\n",L.data[p].quiz3);
            printf("\nEnter Quiz 1: ");
            scanf("%d",&L.data[p].quiz1);
            printf("Enter Quiz 2: ");
            scanf("%d",&L.data[p].quiz2);
            printf("Enter Quiz 3: ");
            scanf("%d",&L.data[p].quiz3);
            printf("\nRecord Updated Successfully!\n");
        }
    }
}
void searchRecord(char nm[31]){
    int i,p;

    if(isEmpty()){
        printf("Empty Records\n");
        system("pause");
    }
    else{
        p=locateRecord(nm);
        if(p==-1){
            printf("Record not Found\n");
            system("pause");
        }
        else{
            printf("Record Found!\n");
            printf("Name: %s\n",L.data[p].name);
            printf("Quiz 1: %d\n",L.data[p].quiz1);
            printf("Quiz 2: %d\n",L.data[p].quiz2);
            printf("Quiz 3: %d\n",L.data[p].quiz3);
            system("pause");
        }
    }
}
void displayRecord(){
    if(isEmpty()){
        printf("No Records\n");
        system("pause");
    }
    else{
        printf("=== STUDENTS RECORD ===\n");
        for(int i=0;i<=L.last;i++){
            printf("Name: %s\nQuiz 1: %d\nQuiz 2: %d\nQuiz 3: %d\n\n",L.data[i].name,L.data[i].quiz1,L.data[i].quiz2,L.data[i].quiz3);

        }
    }
}
void deleteRecord(char nm[31]){
    //check if empty
    int i,p;
    if(isEmpty()){
        printf("No Records!\n");
        system("pause");
    }
    else{
        p=locateRecord(nm);
        if(p==-1){
            printf("Record not Found!\n");
            system("pause");
        }
        else{
            for(i=p;i<L.last;i++)
                L.data[i]=L.data[i+1];
            L.last--;
            printf("Record Deleted Successfully!\n");
            system("pause");
        }

    }
}
int isEmpty(){
    return L.last == -1;
}
int locateRecord(char nm[31]){
    for(int i=0;i<=L.last;i++)
        if(strcmp(L.data[i].name,nm)==0)
            return (i);
return -1;
}
void addRec(sREC w){
    L.last++;
    L.data[L.last] = w;
}
int createNull(){
   return L.last = -1;
}
int isFull(){
   return L.last == MAX-1;
}
void insertRecord(){
    sREC y;
    //check if full
    if(isFull()){
        printf("Records is already full\n");
        system("pause");
    }
    else{

        printf("Enter Name: ");
        scanf("%s",&y.name);
        printf("Enter Quiz 1: ");
        scanf("%d",&y.quiz1);
        printf("Enter Quiz 2: ");
        scanf("%d",&y.quiz2);
        printf("Enter Quiz 3: ");
        scanf("%d",&y.quiz3);

        printf("Recorded Successfully\n");
        system("pause");
        // add to data
        addRec(y);
    }

}
int main(){
    createNull();
    retrieveRecord();
    int ch;
    char nm[31];
    while(ch!=6){
        switch(menu()){
            case 1:system("cls");
                // insert
                insertRecord();
                break;
            case 2:system("cls");
                //delete
                printf("\nEnter Name to Delete: ");
                scanf("%s",&nm);
                //call void
                deleteRecord(nm);
                break;
            case 3:system("cls");
                //update
                printf("Enter Name to Update: ");
                scanf("%s",&nm);
                updateRecord(nm);
                break;
            case 4:system("cls");
                //search record
                printf("Enter Name: ");
                scanf("%s",&nm);
                searchRecord(nm);
                break;
            case 5:system("cls");
                //display

                displayRecord();
                break;
            case 6:system("cls");
                saveRecord();
                exit(0);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }

return 0;
}
int menu(){
    int ch;
    printf("\n1.Insert\n2.Delete\n3.Update\n4.Search Record\n5.Display Record\n6.Exit\nChoice: ");
    scanf(" %d",&ch);
    return ch;
}
