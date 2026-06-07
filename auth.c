#include "shared.h"
#include "auth.h"

int adminLogin()
{
    char username[50];
    char password[50];
     printf(CYAN "\n🔐 ADMIN LOGIN\n" RESET);

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    FILE *fp = fopen("admin.txt", "r");

    if (fp == NULL)
    {
        printf(RED "❌ admin.txt not found!\n" RESET);
        return 0;
    }

    char fileUser[50], filePass[50];

    fscanf(fp, "%s %s", fileUser, filePass);

    fclose(fp);

    if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0)
    {
        printf(GREEN "✅ Admin Login Successful!\n" RESET);
        return 1;
    }

    printf(RED "❌ Invalid Admin Credentials!\n" RESET);
    return 0;
}
void registerUser()
{
    char username[50];
    char password[50];

    FILE *fp = fopen("users.txt", "a");

    if (fp == NULL)
    {
        printf(RED "❌ Error opening users.txt\n" RESET);
        return;
    }

    printf(CYAN "\n📝 USER REGISTRATION\n" RESET);

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf(GREEN "✅ Registration Successful!\n" RESET);
}

int userLogin(char username[])
{
    char password[50];
    char fileUser[50];
    char filePass[50];

    printf(CYAN "\n👤 USER LOGIN\n" RESET);

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");

    if (fp == NULL)
    {
        printf(RED "❌ users.txt not found!\n" RESET);
        return 0;
    }
while (fscanf(fp, "%s %s", fileUser, filePass) != EOF)
    {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0)
        {
            fclose(fp);
            printf(GREEN "✅ User Login Successful!\n" RESET);
            return 1;
        }
    }

    fclose(fp);

    printf(RED "❌ Invalid User Credentials!\n" RESET);

    return 0;
}