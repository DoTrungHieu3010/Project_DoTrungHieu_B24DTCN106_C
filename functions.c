#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void categoryMenu() {
    printf("==== CATEGORY MANAGEMENT ====\n");
    printf("[1]. Display categories\n");
    printf("[2]. Add a new category\n");
    printf("[3]. Update a category\n");
    printf("[4]. Delete a category\n");
    printf("[5]. Find a category\n");
    printf("[6]. Arrange categories\n");
    printf("[7]. Check category duplicates\n");
    printf("[8]. Product management\n");
    printf("[9]. Exit\n");
}

void printCategory(Category category[], int n) {
    system("cls");
    if (n == 0) {
        printf("No categories to display.\n");
        return;
    }
    printf("*=======|===========================*\n");
    printf("|  ID   |       Category Name       |\n");
    printf("|=======|===========================|\n");
    for (int i = 0; i < n; i++) {
        printf("|%6d | %-25s |\n", category[i].categoryId, category[i].categoryName);
        printf("|-------|---------------------------|\n");
    }
    printf("*=======|===========================*\n");
}

void addCategory(Category category[], int *n) {
    system("cls");
    printf("Enter the ID of the new category: ");
    scanf("%d", &category[*n].categoryId);
    getchar(); 
    printf("Enter the name of the new category: ");
    fgets(category[*n].categoryName, 50, stdin);
    category[*n].categoryName[strcspn(category[*n].categoryName, "\n")] = '\0'; 
    (*n)++;
    printf("Category added successfully!\n");
}

void updateCategory(Category category[], int *n) {
    system("cls");
    if (*n == 0) {
        printf("No categories to update.\n");
        return;
    }
    int id, found = -1;
    printf("Enter the ID of the category to update: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++) {
        if (category[i].categoryId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Category not found.\n");
    } else {
        getchar(); 
        printf("Enter the new name for the category: ");
        fgets(category[found].categoryName, 50, stdin);
        category[found].categoryName[strcspn(category[found].categoryName, "\n")] = '\0';
        printf("Category updated successfully!\n");
    }
}

void deleteCategory(Category category[], int *n) {
    system("cls");
    if (*n == 0) {
        printf("No categories to delete.\n");
        return;
    }
    int id, found = -1;
    printf("Enter the ID of the category to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++) {
        if (category[i].categoryId == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Category not found.\n");
    } else {
        for (int i = found; i < *n - 1; i++) {
            category[i] = category[i + 1];
        }
        (*n)--;
        printf("Category deleted successfully!\n");
    }
}

void arrangeCategory(Category category[], int n) {
    if (n == 0) {
        printf("No categories to arrange.\n");
        return;
    }
    int choice;
    printf("Enter 1 to sort A-Z or 2 to sort Z-A: ");
    scanf("%d", &choice);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((choice == 1 && strcmp(category[i].categoryName, category[j].categoryName) > 0) ||
                (choice == 2 && strcmp(category[i].categoryName, category[j].categoryName) < 0)) {
                Category temp = category[i];
                category[i] = category[j];
                category[j] = temp;
            }
        }
    }
    printf("Categories arranged successfully!\n");
}

void arrangeMenu(Category category[], int *n) {
    system("cls");
    printf("=== Arrange Menu ===\n");
    printf("1. Sort categories A-Z\n");
    printf("2. Sort categories Z-A\n");
}

void findCategory(Category category[], int n) {
    system("cls");
    if (n == 0) {
        printf("No categories to search.\n");
        return;
    }
    char findName[50];
    printf("Enter the name of the category to find: ");
    getchar();
    fgets(findName, 50, stdin);
    findName[strcspn(findName, "\n")] = '\0'; 
    int found = 0;
    printf("*=======|===========================*\n");
    printf("|  ID   |       Category Name       |\n");
    printf("|=======|===========================|\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(category[i].categoryName, findName) == 0) {
            printf("|%6d | %-25s |\n", category[i].categoryId, category[i].categoryName);
            printf("|-------|---------------------------|\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No matching category found.\n");
    }
    printf("*=======|===========================*\n");
}

void checkCategory(Category category[], int n) {
    system("cls");
    if (n == 0) {
        printf("No categories to check.\n");
        return;
    }
    int check = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (category[i].categoryId == category[j].categoryId) {
                printf("Duplicate ID found: %d\n", category[i].categoryId);
                check++;
            }
            if (strcmp(category[i].categoryName, category[j].categoryName) == 0) {
                printf("Duplicate name found: %s\n", category[i].categoryName);
                check++;
            }
        }
    }
    if (check == 0) {
        printf("No duplicates found.\n");
    }
}

void productMenu() {
    system("cls");
    printf("==== PRODUCT MANAGEMENT ====\n");
    printf("[1]. Display products\n");
    printf("[2]. Add a new product\n");
    printf("[3]. Update a product\n");
    printf("[4]. Delete a product\n");
    printf("[5]. Find a product\n");
    printf("[6]. Arrange products\n");
    printf("[7]. Check product duplicates\n");
    printf("[8]. Exit\n");
}

void adminLogin() {
    char loginEmail[50];
    char loginPassword[50];
    char registerEmail[] = "admin";
    char registerPassword[] = "1234";
    printf("Please enter your email: ");
    fflush(stdin);
    fgets(loginEmail, sizeof(loginEmail), stdin);
    loginEmail[strcspn(loginEmail, "\n")] = '\0';
    printf("Please enter your password: ");
    fflush(stdin);
    fgets(loginPassword, sizeof(loginPassword), stdin);
    loginPassword[strcspn(loginPassword, "\n")] = '\0';
    if (strcmp(loginEmail, registerEmail) == 0 && strcmp(loginPassword, registerPassword) == 0) {
        printf("Login Successful!\n");
    } else {
        printf("Invalid email or password. Exiting program.\n");
        exit(1);
    }
}

void exitMenu(int choice){
	printf("Go back(b)?: ");
	scanf("%d", &choice);
	getchar();
	if (choice=='b'){
		printf("Go back complete!");
	}
}



