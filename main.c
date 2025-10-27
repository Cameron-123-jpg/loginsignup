#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lowerCaseWord(char word[]);
int signUp();
void login();
int checkExistingEmail(char email[]);

int main()
{
    while (1)
    {
        printf("Signup or Login: ");
        char response[20];
        scanf("%19s", response);
        lowerCaseWord(response);

        if (strcmp(response, "signup") == 0)
        {
            int success = signUp();
            if (success == 1)
            {
                printf("Account creation successful.\n");
            }
            else
            {
                printf("Error creating account, please try again.\n");
            }
        }
        else if (strcmp(response, "login") == 0)
        {
            login();
        }
        else
        {
            printf("Please enter a valid response.\n");
        }
    }
}

void lowerCaseWord(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] += 32;
        }
    }
}
int signUp()
{
    int success = 0;
    char email[50];
    char password[50];
    printf("Enter email: ");
    scanf("%49s", email);
    if (strrchr(email, '@') != 0 && strchr(email, ',') == NULL)
    {
        if (checkExistingEmail(email) == 1)
        {
            printf("Enter password: ");
            scanf("%49s", password);
            FILE *loginFile = fopen("login.txt", "a");
            fprintf(loginFile, "%s,%s\n", email, password);
            fclose(loginFile);
            success = 1;
        }
    }

    else
    {
        printf("Please enter valid email.\n");
    }
    return success;
}

void login()
{
    char email[50];
    char fileLine[150];
    char filePassword[50];
    char fileEmail[50];
    char password[50];
    int counter = 0;

    printf("Enter email address: ");
    scanf("%49s", email);
    FILE *masterLogins = fopen("login.txt", "r");
    if (strrchr(email, '@') == 0)
        printf("Invalid email address.\n");
    else
    {
        printf("Enter password: ");
        scanf("%49s", password);
        while (fgets(fileLine, sizeof(fileLine), masterLogins) != NULL)
        {
            counter = 0;
            fileEmail[0] = '\0';
            for (int i = 0; i < strlen(fileLine); i++)
            {
                if (fileLine[i] == ',')
                {
                    for (int j = 0; j < i; j++)
                    {
                        fileEmail[j] = fileLine[j];
                    }
                    fileEmail[i] = '\0';
                }
            }
            for(int i = strlen(fileEmail) +1; i < strlen(fileLine); i++){
                filePassword[counter] = fileLine[i];
                counter++;
            }
            filePassword[counter - 1] = '\0';
            if((strcmp(fileEmail, email) == 0) && (strcmp(filePassword, password) == 0)){
                printf("Login successful.\n");
                break;
            }
        }
    }
    fclose(masterLogins);
}

int checkExistingEmail(char email[])
{
    int success = 1;
    FILE *masterLogins = fopen("login.txt", "r");
    if (masterLogins == NULL)
    {
        printf("Couldn't find login.txt.\n");
        return 1;
    }
    char fileLine[150];
    char fileEmail[50];
    while (fgets(fileLine, sizeof(fileLine), masterLogins) != NULL)
    {
        fileEmail[0] = '\0';
        for (int i = 0; i < strlen(fileLine); i++)
        {
            if (fileLine[i] == ',')
            {
                for (int j = 0; j < i; j++)
                {
                    fileEmail[j] = fileLine[j];
                }
                fileEmail[i] = '\0';
            }
        }
        if (strcmp(fileEmail, email) == 0)
        {
            printf("Email already in use.\n");
            success = 0;
            break;
        }
    }
    fclose(masterLogins);
    return success;
}