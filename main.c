#include <windows.h>
#include "shared.h"
#include "auth.h"
#include "problem.h"

/* ================= LINE FUNCTION ================= */

void line()
{
    printf(BOLD MAGENTA);
    printf("====================================================================================================\n");
    printf(RESET);
}

/* ================= TITLE DESIGN ================= */

void title()
{
    printf(BOLD CYAN);

    printf("\n");

    printf("   ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗      █████╗ ██╗███╗   ██╗████████╗\n");
    printf("  ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║     ██╔══██╗██║████╗  ██║╚══██╔══╝\n");
    printf("  ██║     ██║   ██║██╔████╔██║██████╔╝██║     ███████║██║██╔██╗ ██║   ██║   \n");
    printf("  ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══██║██║██║╚██╗██║   ██║   \n");
    printf("  ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ███████╗██║  ██║██║██║ ╚████║   ██║   \n");
    printf("   ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   \n");

    printf("\n");

    printf(" ███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n");
    printf(" ████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n");
    printf(" ██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n");
    printf(" ██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n");
    printf(" ██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n");
    printf(" ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n");

    printf(RESET);

    printf("\n");

    printf(BOLD YELLOW);
    printf("                  📋 COMPLAINT & PROBLEM MANAGEMENT SYSTEM 🚀\n");
    printf(RESET);

    printf("\n");

    line();
}

/* ================= LOADING EFFECT ================= */

void loading()
{
    printf(YELLOW "\n⏳ Loading");

    for(int i = 0; i < 5; i++)
    {
        printf(".");
        Sleep(300);
    }

    printf("\n" RESET);
}

/* ================= USER MENU ================= */

void userMenu(char username[])
{
    int choice;

    while (1)
    {
        system("cls");

        title();

        printf(BOLD BLUE);
        printf("                               👤 USER PANEL\n");
        line();
        printf(RESET);

        printf(GREEN   "\n   1. ➕ Add Problem\n\n" RESET);

        printf(CYAN    "   2. 📋 View Problems\n\n" RESET);

        printf(YELLOW  "   3. 🔍 Search Problem\n\n" RESET);

        printf(MAGENTA "   4. 🏠 Back To Main Menu\n\n" RESET);

        printf(RED     "   5. ❌ Exit Program\n" RESET);

        line();

        printf(BOLD WHITE "\n👉 Enter Your Choice: " RESET);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                system("cls");

                title();

                addProblem(username);

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 2:

                system("cls");

                title();

                viewProblems();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 3:

                system("cls");

                title();

                searchProblem();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 4:

                printf(GREEN "\n🏠 Returning To Main Menu...\n" RESET);

                Sleep(1000);

                return;

            case 5:

                printf(RED "\n❌ Exiting Program...\n" RESET);

                Sleep(1000);

                exit(0);

            default:

                printf(RED "\n❌ Invalid Choice!\n" RESET);

                Sleep(1000);
        }
    }
}

/* ================= ADMIN MENU ================= */

void adminMenu()
{
    int choice;

    while (1)
    {
        system("cls");

        title();

        printf(BOLD RED);
        printf("                              🔐 ADMIN PANEL\n");
        line();
        printf(RESET);

        printf(GREEN   "\n   1. 📋 View Problems\n\n" RESET);

        printf(CYAN    "   2. 🔍 Search Problem\n\n" RESET);

        printf(YELLOW  "   3. ✏️ Update Status\n\n" RESET);

        printf(MAGENTA "   4. ❌ Delete Problem\n\n" RESET);

        printf(BLUE    "   5. 🏠 Back To Main Menu\n\n" RESET);

        printf(RED     "   6. ❌ Exit Program\n" RESET);

        line();

        printf(BOLD WHITE "\n👉 Enter Your Choice: " RESET);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                system("cls");

                title();

                viewProblems();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 2:

                system("cls");

                title();

                searchProblem();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 3:

                system("cls");

                title();

                updateProblem();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 4:

                system("cls");

                title();

                deleteProblem();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 5:

                printf(GREEN "\n🏠 Returning To Main Menu...\n" RESET);

                Sleep(1000);

                return;

            case 6:

                printf(RED "\n❌ Exiting Program...\n" RESET);

                Sleep(1000);

                exit(0);

            default:

                printf(RED "\n❌ Invalid Choice!\n" RESET);

                Sleep(1000);
        }
    }
}

/* ================= MAIN FUNCTION ================= */

int main()
{
    system("chcp 65001");
    system("mode con: cols=120 lines=40");

    int choice;

    char username[50];

    while (1)
    {
        system("cls");

        title();

        printf(BOLD GREEN "                                🌟 MAIN MENU 🌟\n");
        line();

        printf(GREEN  "\n   1. 🔐 Admin Login\n\n" RESET);

        printf(CYAN   "   2. 👤 User Login\n\n" RESET);

        printf(YELLOW "   3. 📝 User Registration\n\n" RESET);

        printf(RED    "   4. ❌ Exit Program\n" RESET);

        line();

        printf(BOLD WHITE "\n👉 Enter Your Choice: " RESET);

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                system("cls");

                title();

                if(adminLogin())
                {
                    loading();

                    adminMenu();
                }

                break;

            case 2:

                system("cls");

                title();

                if(userLogin(username))
                {
                    loading();

                    userMenu(username);
                }

                break;

            case 3:

                system("cls");

                title();

                registerUser();

                printf(YELLOW "\n\nPress Enter To Continue...");
                getchar();
                getchar();

                break;

            case 4:

                printf(GREEN "\n🙏 Thank You For Using Complaint Management System!\n" RESET);

                Sleep(1000);

                exit(0);

            default:

                printf(RED "\n❌ Invalid Choice!\n" RESET);

                Sleep(1000);
        }
    }

    return 0;
}