#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{   char students[MAX][50];
    int n=0, choice, index=0;
    char name[50];
    
    printf("\n1. Create the list of students\n");
        printf("2. Insert a new student\n");
        printf("3. Delete a student\n");
        printf("4. Display student list\n");
        printf("5. Search for a student\n");
        printf("6. Exit\n");
    
    while(1) {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Enter the number of students:");
                scanf("%d",&n);
                for(int i=0; i<n; i++){
                    printf("Enter student name %d:",i+1);
                    scanf("%s",students[i]);
                }
                printf("Student list created.\n");
                printf("Student list:");
                for(int i=0; i<n; i++){
                    printf("%s ",students[i]);
                }
                printf("\n");
                break;
                
            case 2:
                if(n<MAX){
                    printf("Enter the student's name to insert:");
                    scanf("%s",&name);
                    printf("Enter the position to insert the student:");
                    scanf("%d",&index);
                    if(index>=0 && index<=n){
                        n=n+1;
                        for(int i=n-1; i>=index; i--){
                            strcpy(students[i+1],students[i]);
                        }
                    strcpy(students[index],name);
                    printf("Student inserted.\n");
                    printf("Student list:");
                    for(int i=0; i<n; i++){
                    printf("%s ",students[i]);
                }
                    }
                    else{
                        printf("Invalid index.\n");
                    }
                    }
                else{
                    printf("List is full.\n");
                    }
                printf("\n");
                break;
                
            case 3:
                char delChoice;
                printf("Delete by name or position? (n/p):");
                scanf("%s",&delChoice);
                
                if(delChoice=='p'){
                    printf("Enter the position to delete:");
                    scanf("%d",&index);
                    if(index>=0 && index<n){
                        n=n-1;
                        for(int i=index; i<n; ++i){
                            strcpy(students[i],students[i+1]);
                        }
                    printf("Student deleted.\n");
                    printf("Student list:");
                    for(int i=0; i<n; i++){
                    printf("%s ",students[i]);}
                    }
                else{
                   printf("Invalid index.\n");
                    }
                }
                else if(delChoice=='n'){
                    printf("Enter the student's name to delete:");
                    scanf("%s",name);
                    int found = -1;
                    for(int i=0; i<n; i++){
                        if(strcmp(students[i],name)==0){
                            found = i;
                            break;
                        }
                    }
                    if(found!=-1){
                        for(int i=found; i<n-1; i++){
                            strcpy(students[i],students[i+1]);
                        }
                    n--;
                    printf("Student deleted.\n");
                    printf("Student list:");
                    for(int i=0; i<n; i++){
                    printf("%s ",students[i]);
                    }
                    }
                    else{
                        printf("Student not found.\"n");
                    }
                }
                printf("\n");
                break;
                
            case 4:
                printf("Student list:");
                    for(int i=0; i<n; i++){
                    printf("%s ",students[i]);
                    }
                    printf("\n");
                    break;
                    
            case 5:
               printf("Enter the student's name to search:");
               scanf("%s",name);
               int found = -1;
                    for(int i=0; i<n; i++){
                        if(strcmp(students[i],name)==0){
                            found = i;
                            break;
                        }
                    }
                    if(found!=-1){
                        printf("%s found at position %d\n",name,found);
                    }
                    else{
                        printf("%s not found.\n,name");
                    }
                    printf("\n");
                    break;
                    
            case 6:
                printf("Exiting the program...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}
