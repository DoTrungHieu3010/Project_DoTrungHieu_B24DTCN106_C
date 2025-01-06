#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//
	int n= 0;
	int choice;
	//
	Category category[50]={
	};
	//
	adminLogin();
	FILE *ptr = fopen("categoryData.dat", "rb");
    if (ptr != NULL) {
        while (fread(&category[n], sizeof(Category), 1, ptr)) {
            n++;
        }
        fclose(ptr);
    }
	do {
        system("cls");
        printf("|     STORE MANAGEMENT    |\n");
        printf("---------------------------\n");
        categoryMenu(); 
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printCategory(category, n);
                exitMenu(choice);
                break;
            case 2: 
                addCategory(category, &n);
                exitMenu(choice);
                break;
            case 3: 
                updateCategory(category, &n);
                exitMenu(choice);
                break;
            case 4: 
                deleteCategory(category, &n);
                exitMenu(choice);
                break;
            case 5: 
                findCategory(category, n);
                exitMenu(choice);
                break;
            case 6: 
                arrangeMenu(category, &n);
                arrangeCategory(category, n);
                exitMenu(choice);
                break;
            case 7:
                checkCategory(category, n);
                exitMenu(choice);
                break;
            case 8:
                productMenu();
                do {
        			system("cls");
        			printf("Please enter your choice: ");
        			scanf("%d", &choice);
        			switch(choice){
        				case 1:
        				break;	
					}
				}
				while (choice!=8);
                break;
            case 9: 
                return 0;
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);
	ptr = fopen("categoryData.dat", "rb");
    if (ptr == NULL) {
        printf("Error saving data!\n");
    } else {
        for (int i = 0; i < n; i++) {
            fwrite(&category[i], sizeof(Category), 1, ptr);
        }
        fclose(ptr);
    }
    return 0;
}
