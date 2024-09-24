#include <stdio.h>

struct Type{
    char friend_type[20];
    char common_friends[20];
    int places_visited;
};

struct Friends{
    char name[20];
    char petname[20];
    char phone_number[20];
    struct Type type;
};

int main(){
    struct Friends friends[3];
    int i;
    for(i=0;i<3;i++)
    {  printf("\nEnter details for friend: \n",i+1);
    
       printf("Name:");
       scanf("%s",friends[i].name);
       
       printf("Pet Name:");
       scanf("%s",friends[i].petname);
       
       printf("Phone Number:");
       scanf("%s",friends[i].phone_number);
       
       printf("Type of Friend:");
       scanf("%s",friends[i].type.friend_type);
       
       printf("Name of Common Friends:");
       scanf("%s",friends[i].type.common_friends);
       
       printf("Places Visited Together:");
       scanf("%d",&friends[i].type.places_visited);
    }
    
//Display the data
    printf("\nFriends List:\n");
    for(i=0;i<3;i++)
    {  printf("\nFriend %d:\n",i+1);
    
       printf("Name: %s\n",friends[i].name);
       
       printf("Pet Name: %s\n",friends[i].petname);
       
       printf("Phone Number: %s\n",friends[i].phone_number);
       
       printf("Type of Friend: %s\n",friends[i].type.friend_type);
       
       printf("Common Friends: %s\n",friends[i].type.common_friends);
       
       printf("Places Visited Together: %d\n",friends[i].type.places_visited);
    }
    
    return 0;
       
}
