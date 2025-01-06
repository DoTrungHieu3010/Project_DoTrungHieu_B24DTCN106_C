#include<stdbool.h>
#include<stdio.h>

typedef struct {
	int categoryId;
	char categoryName[50];
}Category;

typedef struct {
	int productId;
	char productName[50];
	long long productPrice;
	int productAmount;
}Product;

