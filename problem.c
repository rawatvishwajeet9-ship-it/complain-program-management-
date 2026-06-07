#include "shared.h"
#include "problem.h"

/* ================= ADD PROBLEM ================= */

void addProblem(char username[])
{
    FILE *fp = fopen("problems.txt", "a");

    if (fp == NULL)
    {
        printf(RED "❌ Error opening file!\n" RESET);
        return;
    }

    Problem p;

    printf(CYAN "\n➕ ADD NEW PROBLEM\n" RESET);

    printf("Enter Problem ID: ");
    scanf("%d", &p.id);

    getchar();

    strcpy(p.user, username);

    printf("Enter Problem Description: ");
    fgets(p.description, sizeof(p.description), stdin);

    p.description[strcspn(p.description, "\n")] = '\0';

    strcpy(p.status, "Pending");

    fprintf(fp,
            "%d|%s|%s|%s\n",
            p.id,
            p.user,
            p.description,
            p.status);

    fclose(fp);

    printf(GREEN "✅ Problem Added Successfully!\n" RESET);
}

/* ================= VIEW PROBLEMS ================= */

void viewProblems()
{
    FILE *fp = fopen("problems.txt", "r");

    if (fp == NULL)
    {
        printf(RED "❌ No Problems Found!\n" RESET);
        return;
    }

    Problem p;

    printf(YELLOW "\n📋 ALL PROBLEMS\n" RESET);

    while (fscanf(fp,
                  "%d|%49[^|]|%199[^|]|%49[^\n]\n",
                  &p.id,
                  p.user,
                  p.description,
                  p.status) != EOF)
    {
        printf(BOLD BLUE "-----------------------------------\n" RESET);

        printf(GREEN "🆔 ID        : %d\n" RESET, p.id);
        printf(CYAN "👤 User      : %s\n" RESET, p.user);
        printf(YELLOW "📝 Problem   : %s\n" RESET, p.description);
        printf(MAGENTA "📌 Status    : %s\n" RESET, p.status);
    }

    fclose(fp);
}

/* ================= SEARCH PROBLEM ================= */

void searchProblem()
{
    FILE *fp = fopen("problems.txt", "r");

    if (fp == NULL)
    {
        printf(RED "❌ File not found!\n" RESET);
        return;
    }

    int id;
    int found = 0;

    Problem p;

    printf(CYAN "\n🔍 SEARCH PROBLEM\n" RESET);

    printf("Enter Problem ID: ");
    scanf("%d", &id);

    while (fscanf(fp,
                  "%d|%49[^|]|%199[^|]|%49[^\n]\n",
                  &p.id,
                  p.user,
                  p.description,
                  p.status) != EOF)
    {
        if (p.id == id)
        {
            found = 1;

            printf(GREEN "\n✅ Problem Found!\n" RESET);

            printf("🆔 ID       : %d\n", p.id);
            printf("👤 User     : %s\n", p.user);
            printf("📝 Problem  : %s\n", p.description);
            printf("📌 Status   : %s\n", p.status);

            break;
        }
    }

    if (!found)
    {
        printf(RED "❌ Problem Not Found!\n" RESET);
    }

    fclose(fp);
}

/* ================= UPDATE PROBLEM ================= */

void updateProblem()
{
    FILE *fp = fopen("problems.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf(RED "❌ Error opening file!\n" RESET);
        return;
    }

    int id;
    int found = 0;

    char newStatus[50];

    Problem p;

    printf(CYAN "\n✏️ UPDATE PROBLEM STATUS\n" RESET);

    printf("Enter Problem ID: ");
    scanf("%d", &id);

    while (fscanf(fp,
                  "%d|%49[^|]|%199[^|]|%49[^\n]\n",
                  &p.id,
                  p.user,
                  p.description,
                  p.status) != EOF)
    {
        if (p.id == id)
        {
            found = 1;

            printf("\nCurrent Status: %s\n", p.status);

            printf("Enter New Status: ");
            scanf("%s", newStatus);

            strcpy(p.status, newStatus);

            printf(GREEN "✅ Status Updated Successfully!\n" RESET);
        }

        fprintf(temp,
                "%d|%s|%s|%s\n",
                p.id,
                p.user,
                p.description,
                p.status);
    }

    fclose(fp);
    fclose(temp);

    remove("problems.txt");
    rename("temp.txt", "problems.txt");

    if (!found)
    {
        printf(RED "❌ Problem ID Not Found!\n" RESET);
    }
}

/* ================= DELETE PROBLEM ================= */

void deleteProblem()
{
    FILE *fp = fopen("problems.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf(RED "❌ Error opening file!\n" RESET);
        return;
    }

    int id;
    int found = 0;

    Problem p;

    printf(CYAN "\n❌ DELETE PROBLEM\n" RESET);

    printf("Enter Problem ID: ");
    scanf("%d", &id);

    while (fscanf(fp,
                  "%d|%49[^|]|%199[^|]|%49[^\n]\n",
                  &p.id,
                  p.user,
                  p.description,
                  p.status) != EOF)
    {
        if (p.id == id)
        {
            found = 1;
            continue;
        }

        fprintf(temp,
                "%d|%s|%s|%s\n",
                p.id,
                p.user,
                p.description,
                p.status);
    }

    fclose(fp);
    fclose(temp);

    remove("problems.txt");
    rename("temp.txt", "problems.txt");

    if (found)
    {
        printf(GREEN "✅ Problem Deleted Successfully!\n" RESET);
    }
    else
    {
        printf(RED "❌ Problem ID Not Found!\n" RESET);
    }
}