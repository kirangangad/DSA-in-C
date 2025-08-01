#include <stdio.h>

// Function declarations
void displayPersonalInfo();
void displaySkills();
void displayProjects();
void displayContactInfo();

int main() {
    int choice;
    
    while (1) {
        // Display menu
        printf("\n====== Personal Portfolio ======\n");
        printf("1. Personal Information\n");
        printf("2. Skills\n");
        printf("3. Projects\n");
        printf("4. Contact Information\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);
        getchar(); // Clear input 

        switch (choice) {
            case 1:
                displayPersonalInfo();
                break;
            case 2:
                displaySkills();
                break;
            case 3:
                displayProjects();
                break;
            case 4:
                displayContactInfo();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void displayPersonalInfo() {
    printf("\n==== Personal Information ====");
    printf("\nName: Kiran Gangad");
    printf("\nProfession: BCA Student & Aspiring Data Analyst");
    printf("\nUniversity: Savitribai Phule Pune University\n");
}

void displaySkills() {
    printf("\n==== Skills ====");
    printf("\n- C, C++, Python, SQL");
    printf("\n- Data Analysis & Database Management");
    printf("\n- Web Development (HTML, CSS, JavaScript)\n");
}

void displayProjects() {
    printf("\n==== Projects ====");
    printf("\n1. Student-Teacher Database (SQL & PostgreSQL)");
    printf("\n2. Trading Analysis Web App (HTML, JS, Python)");
    printf("\n3. YouTube Song: Tuta Dil\n");
}

void displayContactInfo() {
    printf("\n==== Contact Information ====");
    printf("\nEmail: kiran@example.com");
    printf("\nGitHub: github.com/kiran");
    printf("\nLinkedIn: linkedin.com/in/kiran\n");
}
