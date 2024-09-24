#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    struct contact* next;
};

struct contact* head = NULL, *tmp=NULL;

void displayContacts(){
    if(head==NULL){
        printf("Contact list is empty.\n");
    }else{
        printf("Contact list:");
        tmp = head;
        while(tmp != NULL){
        printf ("%s->", tmp->name);
        tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, n, pos;
    char name[50], delChoice;
    struct contact *newcon, *tmp, *prev;

    printf("\n1. Create the list of contacts\n");
    printf("2. Insert a new contact\n");
    printf("3. Delete a contact\n");
    printf("4. Display contact list\n");
    printf("5. Search for a contact\n");
    printf("6. Exit\n");
    
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1: 
            printf("Enter number of contacts: ");
            scanf("%d", &n);
            
            for(int i=0; i<n; i++){ 
                newcon=(struct contact*)malloc(sizeof(struct contact));
                newcon->next=NULL;
                printf("Enter contact name %d:",i+1);
                scanf("%s",newcon->name);
                if(!head){
                    head=newcon;
                }else{
                    tmp=head;
                    while(tmp->next)
                    tmp=tmp->next;
                    tmp->next=newcon;
                }
                }
                displayContacts();
                printf("\n");
                break;
                
           case 2:
             printf("Enter the contact's name to insert: ");
             scanf("%s", name);
             printf("Enter the position to insert the contact:");
             scanf("%d",&pos);
             newcon=(struct contact*)malloc(sizeof(struct contact));
                strcpy(newcon->name, name);
                newcon->next=NULL;
                if (pos == 0){
                    newcon->next = head;
                    head = newcon;
                }else{
                    tmp = head;
                    for (int i=0; i<pos-1 && tmp!=NULL; i++){
                    tmp = tmp->next;
                    }
                    if(tmp!=NULL){
                      newcon->next = tmp->next;
                      tmp->next = newcon;
                    }else{
                        printf("Position out of range.\n");
                        free(newcon);
                    }
                }
                displayContacts();
                printf("\n");
                break;
                
           case 3:
             printf("Delete by name or position? (n/p): ");
             scanf(" %c", &delChoice);
             if(delChoice=='n') {
               printf("Enter name to delete: ");
               scanf("%s", name);
               tmp = head, prev = NULL;
               while (tmp && strcmp(tmp->name, name)!=0) {
                 prev = tmp;
                 tmp = tmp->next;
                }
                if(tmp){
                  if(prev) 
                    prev->next = tmp->next;
                  else head = tmp->next;
                  free(tmp);
                }else{
                  printf("Contact not found.\n");
                }
                } else {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    tmp = head, prev = NULL;
                    for(int i=0; i<pos && tmp; i++){
                       prev = tmp;
                       tmp = tmp->next;
                    }
                    if (tmp){
                      if(prev)
                      prev->next = tmp->next;
                      else 
                      head = tmp->next;
                      free(tmp);
                    } else {
                        printf("Position out of range.\n");
                    }
                }
                displayContacts();
                printf("\n");    
                break;
                
           case 4:
             displayContacts();
             printf("\n");
             break;
             
           case 5:
             printf("Enter name to search: ");
             scanf("%s", name);
             tmp = head;
             int posFound = 0;
             while(tmp) {
               if(strcmp(tmp->name, name) == 0){
                  printf("%s found at position %d\n", name, posFound);
                  break;
                }
                tmp = tmp->next;
                posFound++;
             }
             if(!tmp) 
                printf("Contact not found.\n");
             
             printf("\n");   
             break;
                
           case 6:
             printf("Exiting...\n");
             exit(0);
             
           default:
             printf("Invalid choice.\n");
        }   
    }
}
