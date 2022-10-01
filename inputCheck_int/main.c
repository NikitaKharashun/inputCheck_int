#include <stdio.h>
#include <locale.h>


int fast();
int pow();

int main()
{
    setlocale(LC_ALL, "rus");
    char a[20];
    printf("dgdgdg\n");
    int b = inputCheck(gets_s(a, 20));
    printf("%d", b);
    return 0;
}

int fast(int a, int b)
{
    if (0 == a)
        return 0;
    if (b == 0) 
        return 1;
    if (b % 2 == 1)
        return a * fast(a, b - 1);
    else
        return fast(a * a, b / 2);
}

int pow(int number, int degree)
{
    int res = 0;

    if (number == 0)
        return 0;
    if (degree == 0)
        return 1;

    for (int i = 0; i < degree - 1; i++)
        res += number * number;

    if (degree < 0) 
        return 1 / res;
    
    else
        return res;
}

int inputCheck(char* stringInput)
{
    int min = 0, num2 = 0, mincnt = 0, temp;


    int length = sizeof(stringInput) / sizeof(char);

    if (length > 9)
    {
        printf("Ошибка ввода\n"); return 0;
    }

    int snum = length;

    for (int i = 0; stringInput[i] != '\0'; i++)
    {
        if (stringInput[i] == 45)
            mincnt++;
    }

    if (mincnt > 1)
    {
        printf("Ошибка ввода\n"); return 0;
    }

    if (stringInput[0] == 45 && stringInput[1] == 48)
    {
        printf("Ошибка ввода\n"); return 0;
    }

    if (stringInput[0] == 45)
    {
        for (int i = 1; i < length; i++)
            stringInput[i - 1] = stringInput[i];

        stringInput[length - 1] = '0';
    }

    for (int i = 0; stringInput[i] != '\0'; i++)
    {
        if (stringInput[i] < 48 || stringInput[i]>57)
        {
            printf("Ошибка ввода\n"); return 0;
        }
    }


    for (int i = 0; i <= snum - 1; i++) //i<=snum-1
    {
        num2 += (stringInput[i] - '0') * fast(10, length - 1);
        length--;
    }

    if (mincnt == 1)
    {
        snum--;
        length--;
        for (int i = 0; i <= snum - 1; i++) //i<=snum-1
        {
            num2 += (stringInput[i] - '0') * fast(10, length - 1);
            length--;
        }

        num2 = -1 * num2;
        printf("%d\n", num2);
        return num2;
    }
    else
    {
        for (int i = 0; i <= snum - 1; i++, length--) //i<=snum-1
        {
            num2 += (stringInput[i] - '0') * fast(10, length - 1);
        }

        printf("%d\n", num2);
        return num2;
    }
}