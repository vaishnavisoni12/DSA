#include <stdio.h>

struct Product {
    char name[20];
    char id[10];
    float price;
};

int main() {
    int n;
    float total_cost = 0;
    struct Product *most_expensive = NULL;
    struct Product *least_expensive = NULL;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    struct Product products[n];

    // Input product details
    for (int i=0; i<n;i++) 
    {   printf("\nEnter details for product %d:\n",i+1);

        printf("Product Name: ");
        scanf("%s",products[i].name);

        printf("Product ID: ");
        scanf("%s",products[i].id);

        printf("Price: ");
        scanf("%f",&products[i].price);

        // calculating total cost
        total_cost += products[i].price;

        // finding the most expensive product
        if (most_expensive == NULL || products[i].price > most_expensive->price) 
        {  
            most_expensive= &products[i];
        }

        // finding the lowest priced product
        if (least_expensive == NULL || products[i].price < least_expensive->price)
        {
            least_expensive= &products[i];
        }

        printf("\n");
    }

    // Display all product details
    printf("Product Details:\n");
    for (int i=0;i<n;i++) 
    {
        printf("Product Name: %s, Product ID: %s, Price: %.2f\n",products[i].name, products[i].id, products[i].price);
    }

    // Displaying most expensive product
    if (most_expensive != NULL) 
    {
        printf("Most Expensive Product: %s, Product ID: %s, Price: %.2f\n",most_expensive->name, most_expensive->id, most_expensive->price);
    }

    // Displaying lowest priced product
    if (least_expensive != NULL) 
    {
        printf("Least Expensive Product: %s, Product ID: %s, Price: %.2f\n",least_expensive->name, least_expensive->id, least_expensive->price);
    }

    // Displaying total cost
    printf("Total Cost of All Products: %.2f\n", total_cost);

    return 0;
}
