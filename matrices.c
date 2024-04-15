#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int read_text(char str[], int size, int flag);
void op1();
void op2();
void op3();
void op4();
void op5();
void op6();
void add1();
void sub1();
void num_mult();
void in_mult();
void out_mult();
void mix_mult();
void add2();
void sub2();
void mult1();
void mult2();
void oppos();
void trans();

int main()
{
    int op;

    while(1)
    {
        printf("\n1.Create a matrix or vector\n");
        printf("2.Creare random a matrix or vector\n");
        printf("3.Available matrices and vectors\n");
        printf("4.Delete a matrix or vector\n");
        printf("5.Vector operations\n");
        printf("6.Matrix operations\n");
        printf("\nChoose one of the options above by pressing the corresponding key [0: Exit Program]: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                op1();
            break;

            case 2:
                op2();
            break;

            case 3:
                op3();
            break;

            case 4:
                op4();
            break;

            case 5:
                op5();
            break;

            case 6:
                op6();
            break;

            case 0:
                return 0;

            default:
                printf("\nError! There is no option with key equal to %d...Please try again!\n", op);
            break;
        }
        op = 0;
    }
}

int read_text(char str[], int size, int flag)
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed!");
        exit(EXIT_FAILURE);
    }
    len = strlen(str);
    if(len>0)
    {
        if(flag && (str[len-1]=='\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input");
        exit(EXIT_FAILURE);
    }
    return len;
}


void op1()
{
    FILE *fp;
    char str[50];
    int x, y, z, i, j;
    float a;

    printf("\n-----------Create matrix or vector-------------\n\n");

    do
    {
        printf("If you want to create a vector press 1, else for a matrix press 2: ");
        scanf("%d", &x);
    }while((x!=2)&&(x!=1));

    if(x==1)
    {
        getchar();
        printf("\nInsert the name of the vector you want to create: ");
        read_text(str, sizeof(str), 1);

        fp = fopen(str, "wb");

        if(fp==NULL)
        {
            printf("Error: fopen() for %s failed!", str);
            exit(EXIT_FAILURE);
        }

        printf("Insert the dimension of the vector: ");
        scanf("%d", &y);
        fwrite(&y, sizeof(int), 1, fp);
        z = 1;
        fwrite(&z, sizeof(int), 1, fp);

        for(i=0; i<y; i++)
        {
            printf("Insert the value for the %d coordinate of the vector: ", i+1);
            scanf("%f", &a);
            fwrite(&a, sizeof(float), 1, fp);
        }
        fclose(fp);
    }
    if(x==2)
    {
        getchar();
        printf("\nInsert the name of the matrix you want to create: ");
        read_text(str, sizeof(str), 1);

        fp = fopen(str, "wb");

        if(fp==NULL)
        {
            printf("Error: fopen() for %s failed!", str);
            exit(EXIT_FAILURE);
        }

        printf("Insert the number of rows: ");
        scanf("%d", &y);
        fwrite(&y, sizeof(int), 1, fp);
        printf("Insert the number of columns: ");
        scanf("%d", &z);
        fwrite(&z, sizeof(int), 1, fp);

        for(i=0; i<y; i++)
        {
            for(j=0; j<z; j++)
            {
                printf("Insert the value for the element at row %d and column %d of the matrix: ", i+1, j+1);
                scanf("%f", &a);
                fwrite(&a, sizeof(float), 1, fp);
            }
        }
        fclose(fp);
    }
    return;
}

void op2()
{
    FILE *fp;
    char str[50];
    int x, y, z, i, j;
    float a;

    printf("\n-----------Create random matrix or vector-------------\n\n");

    srand(time(NULL));
    do
    {
        printf("If you want to create a vector press 1, else for a matrix press 2: ");
        scanf("%d", &x);
    }while((x!=2)&&(x!=1));

    if(x==1)
    {
        getchar();
        printf("\nInsert the name of the vector you want to create: ");
        read_text(str, sizeof(str), 1);

        fp = fopen(str, "wb");

        if(fp==NULL)
        {
            printf("Error: fopen() for %s failed!", str);
            exit(EXIT_FAILURE);
        }

        printf("Insert the dimension of the vector: ");
        scanf("%d", &y);
        fwrite(&y, sizeof(int), 1, fp);
        z = 1;
        fwrite(&z, sizeof(int), 1, fp);

        for(i=0; i<y; i++)
        {
            a = (float)rand()/RAND_MAX;
            a = a*(200)-100;
            fwrite(&a, sizeof(float), 1, fp);
        }
        fclose(fp);
    }
    if(x==2)
    {
        getchar();
        printf("\nInsert the name of the matrix you want to create: ");
        read_text(str, sizeof(str), 1);

        fp = fopen(str, "wb");

        if(fp==NULL)
        {
            printf("Error: fopen() for %s failed!", str);
            exit(EXIT_FAILURE);
        }

        printf("Insert the number of rows: ");
        scanf("%d", &y);
        fwrite(&y, sizeof(int), 1, fp);
        printf("Insert the number of columns: ");
        scanf("%d", &z);
        fwrite(&z, sizeof(int), 1, fp);

        for(i=0; i<y; i++)
        {
            for(j=0; j<z; j++)
            {
                a = (float)rand()/RAND_MAX;
                a = a*(200)-100;
                fwrite(&a, sizeof(float), 1, fp);
            }
        }
        fclose(fp);
    }
    return;
}

void op3()
{
    FILE *fp;
    char str[50];
    int x, y, i, j;
    float a;

    printf("\n-----------Available matrices and vectors-------------\n");

    getchar();
    while(1)
    {
        printf("\nInsert the name of the matrix or the vector you wnat to see [stop: Exit]: ");
        read_text(str, sizeof(str), 1);

        if(strcmp("stop", str) == 0)
            return;

        fp = fopen(str, "rb");
        if(fp==NULL)
        {
            printf("Error: There is no matrix or vector with the name %s!\n", str);
        }
        else
        {
            fread(&x, sizeof(int), 1, fp);
            fread(&y, sizeof(int), 1, fp);
            printf("\n");
            for(i=0; i<x; i++)
            {
                for(j=0; j<y; j++)
                {
                    fread(&a, sizeof(float), 1, fp);
                    printf("%8.1f", a);
                }
                if(j != 1)
                    printf("\n");
            }
        }
        fclose(fp);
    }
}

void op4()
{
    FILE *fp;
    char str[50];
    int c;

    getchar();
    while(1)
    {
        do
        {
            printf("\nInsert the name of the matrix or vector you want to delete [stop: Exit]: ");
            read_text(str, sizeof(str), 1);

            if(strcmp("stop", str) == 0)
                return;

            fp = fopen(str, "rb");
            if(fp==NULL)
                printf("There is no matrix or vector with the name %s...Please try again!\n", str);

        }while(fp==NULL);

        fclose(fp);
        c = remove(str);
        if(c==-1)
            printf("\nThere is a problem with deleting this file!");
    }

}

void op5()
{
    int op;

    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Scalar multiplication\n");
    printf("4. Dot Product\n");
    printf("5. Cross Product\n");
    printf("6. Scalar triple product\n");

    printf("\nChoose one of the options above by pressing the corresponding key: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            add1();
        return;

        case 2:
            sub1();
        return;

        case 3:
            num_mult();
        return;

        case 4:
            in_mult();
        return;

        case 5:
            out_mult();
        return;

        case 6:
            mix_mult();
        return;

        default:
            printf("\nError! There is no operation with key equal to %d!\n", op);
        return;
    }
}

void add1()
{
    FILE *fp;
    char str1[50], str2[50], str3[50];
    int r1, c1, r2, c2, i;
    float *p1, *p2;

    printf("\n-----------Addition-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the first vector: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r1, sizeof(int), 1, fp);
            fread(&c1, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p1 = malloc(sizeof(float)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
        fread(p1+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert the name of the second vector: ");
        read_text(str2, sizeof(str2), 1);

        fp = fopen(str2, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str2);
        else
        {
            fread(&r2, sizeof(int), 1, fp);
            fread(&c2, sizeof(int), 1, fp);
            if(c2!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str2);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p2 = malloc(sizeof(float)*r2);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
        fread(p2+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nEnter a name for the product of addition between %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp = fopen(str3, "wb");
    if(fp==NULL)
        exit(EXIT_FAILURE);

    if(r1<r2)
    {
        for(i=0; i<r1; i++)
            p2[i] += p1[i];
        printf("\nThe prosuct we will get from the addition between %s and %s is:\n", str1, str2);
        printf("(%5.1f", p2[0]);
        for(i=1; i<r2; i++)
            printf(", %5.1f", p2[i]);
        printf(")\n");
        fwrite(&r2, sizeof(int), 1, fp);
        fwrite(&c1, sizeof(int), 1, fp);
        for(i=0; i<r2; i++)
            fwrite(p2+i, sizeof(float), 1, fp);
        fclose(fp);
    }
    else
    {
        for(i=0; i<r2; i++)
            p1[i] += p2[i];
        printf("\nThe prosuct we will get from the addition between %s and %s is:\n", str1, str2);
        printf("(%5.1f", p1[0]);
        for(i=1; i<r1; i++)
            printf(", %5.1f", p1[i]);
        printf(")\n");
        fwrite(&r1, sizeof(int), 1, fp);
        fwrite(&c1, sizeof(int), 1, fp);
        for(i=0; i<r1; i++)
            fwrite(p1+i, sizeof(float), 1, fp);
        fclose(fp);
    }
    free(p1);
    free(p2);
}

void sub1()
{
    FILE *fp;
    char str1[50], str2[50], str3[50];
    int r1, c1, r2, c2, i;
    float *p1, *p2;

    printf("\n-----------Subtraction-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the subtrahend: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r1, sizeof(int), 1, fp);
            fread(&c1, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p1 = malloc(sizeof(float)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
        fread(p1+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert the name of minuend: ");
        read_text(str2, sizeof(str2), 1);

        fp = fopen(str2, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str2);
        else
        {
            fread(&r2, sizeof(int), 1, fp);
            fread(&c2, sizeof(int), 1, fp);
            if(c2!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str2);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p2 = malloc(sizeof(float)*r2);
    if(!p2)
    {
        printf("\nÓöÜëìá: Áðïôõ÷ßá äÝóìåõóçò ìíÞìçò!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
        fread(p2+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nInsert a name for the prosuct of subtraction between %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp = fopen(str3, "wb");
    if(fp==NULL)
        exit(EXIT_FAILURE);

    if(r1<r2)
    {
        for(i=0; i<r1; i++)
            p1[i] = p1[i]-p2[i];
        printf("\nThe product we will get from the subtraction of %s and %s is:\n", str1, str2);
        printf("(%5.1f", p2[0]);
        for(i=1; i<r2; i++)
            printf(", %5.1f", p2[i]);
        printf(")\n");
        fwrite(&r2, sizeof(int), 1, fp);
        fwrite(&c1, sizeof(int), 1, fp);
        for(i=0; i<r2; i++)
            fwrite(p2+i, sizeof(float), 1, fp);
        fclose(fp);
    }
    else
    {
        for(i=0; i<r2; i++)
            p1[i] = p1[i]-p2[i];
        printf("\nThe product we will get from the subtraction of %s and %s is:\n", str1, str2);
        printf("(%5.1f", p1[0]);
        for(i=1; i<r1; i++)
            printf(", %5.1f", p1[i]);
        printf(")\n");
        fwrite(&r1, sizeof(int), 1, fp);
        fwrite(&c1, sizeof(int), 1, fp);
        for(i=0; i<r1; i++)
            fwrite(p1+i, sizeof(float), 1, fp);
        fclose(fp);
    }
    free(p1);
    free(p2);
}

void num_mult()
{
    FILE *fp;
    char str1[50], str2[50];
    int r, c, i;
    float *p, num;

    printf("\n-----------Scalar multiplication-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the vector: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r, sizeof(int), 1, fp);
            fread(&c, sizeof(int), 1, fp);
            if(c!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p = malloc(sizeof(float)*r);
    if(!p)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r; i++)
        fread(p+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nInsert the number you wanyt to multiplicate with the vector %s: ", str1);
    scanf("%f",  &num);

    getchar();
    printf("\nInsert a name for the product of the scalar multiplication bbetween vevtor %s and number %.1f: ", str1, num);
    read_text(str2, sizeof(str2), 1);
    fp = fopen(str2, "wb");
    if(fp==NULL)
        exit(EXIT_FAILURE);
    fwrite(&r, sizeof(int), 1, fp);
    fwrite(&c, sizeof(int), 1, fp);

    for(i=0; i<r; i++)
    {
        p[i] *= num;
        fwrite(p+i, sizeof(float), 1, fp);
    }
    fclose(fp);

    printf("\nThe product we will get from the scalar multiplication of vector %s with number %.1f is:\n", str1, num);
    printf("(%8.1f", p[0]);
    for(i=1; i<r; i++)
        printf(", %8.1f", p[i]);
    printf(")\n");
    free(p);
}

void in_mult()
{
    FILE *fp;
    char str1[50], str2[50], str3[50];
    float *p1, *p2, sum;
    int r1, r2, c1, c2, i;

    printf("\n-----------Dot product-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the first vector: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r1, sizeof(int), 1, fp);
            fread(&c1, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p1 = malloc(sizeof(float)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
        fread(p1+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert the name of the second vector: ");
        read_text(str2, sizeof(str2), 1);

        fp = fopen(str2, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str2);
        else
        {
            fread(&r2, sizeof(int), 1, fp);
            fread(&c2, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str2);
                fclose(fp);
                fp = NULL;
            }
        }

    }while(fp==NULL);

    p2 = malloc(sizeof(float)*r2);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
        fread(p2+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nInsert a name for the dot product of vector %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp = fopen(str3, "wb");
    if(fp==NULL)
        exit(EXIT_FAILURE);
    fwrite(&c1, sizeof(int), 1, fp);
    fwrite(&c1, sizeof(int), 1, fp);

    sum = 0;
    if(r1<r2)
    {
        for(i=0; i<r1; i++)
            sum = p1[i]*p2[i];
    }
    else
    {
        for(i=0; i<r2; i++)
            sum += p1[i]*p2[i];
    }
    fwrite(&sum, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nThe dot product of vector %s and %s is equal to %.1f\n", str1, str2, sum);
    free(p1);
    free(p2);
}

void out_mult()
{
    FILE *fp;
    char str1[50], str2[50], str3[50];
    int r1, r2, c1, c2, i;
    float arr1[3]={0}, arr2[3]={0}, x, y, z;

    printf("\n-----------Cross product-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the first vector: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r1, sizeof(int), 1, fp);
            fread(&c1, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
            if(r1>3)
            {
                printf("We can't calculate the crross product for vectors with more than 3 coordinates...Please try again!");
                fclose(fp);
                return;
            }
        }

    }while(fp==NULL);

    for(i=0; i<r1; i++)
        fread(arr1+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert the name of the second vector: ");
        read_text(str2, sizeof(str2), 1);

        fp = fopen(str2, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str2);
        else
        {
            fread(&r2, sizeof(int), 1, fp);
            fread(&c2, sizeof(int), 1, fp);
            if(c2!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str2);
                fclose(fp);
                fp = NULL;
            }
            if(r2>3)
            {
                printf("We can't calculate the crross product for vectors with more than 3 coordinates...Please try again!");
                fclose(fp);
                return;
            }
        }

    }while(fp==NULL);

    for(i=0; i<r2; i++)
        fread(arr2+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nInsert a name for the cross product of vectors %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp = fopen(str3, "wb");

    x = (arr1[1]*arr2[2])-(arr1[2]*arr2[1]);
    y = (arr1[2]*arr2[0])-(arr1[0]*arr2[2]);
    z = (arr1[0]*arr2[1])-(arr1[1]*arr2[0]);

    c1 = 3;
    fwrite(&c1, sizeof(int), 1, fp);
    fwrite(&c2, sizeof(int), 1, fp);
    fwrite(&x, sizeof(float), 1, fp);
    fwrite(&y, sizeof(float), 1, fp);
    fwrite(&z, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nThe cross product of the vectors %s and %s is:\n", str1, str2);
    printf("(%8.1f, %8.1f, %8.1f)", x, y, z);
}

void mix_mult()
{
    FILE *fp;
    char str1[50], str2[50], str3[50], str4[50];
    int r1, r2, r3, c1, c2, c3, i;
    float arr1[3]={0}, arr2[3]={0}, arr3[3]={0}, x;

    printf("\n-----------Scalar triple product-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the first vector: ");
        read_text(str1, sizeof(str1), 1);

        fp = fopen(str1, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str1);
        else
        {
            fread(&r1, sizeof(int), 1, fp);
            fread(&c1, sizeof(int), 1, fp);
            if(c1!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str1);
                fclose(fp);
                fp = NULL;
            }
            if(r1>3)
            {
                printf("We can't calculate the crross product for vectors with more than 3 coordinates...Please try again!");
                fclose(fp);
                return;
            }
        }

    }while(fp==NULL);

    for(i=0; i<r1; i++)
        fread(arr1+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert the name of the second vector: ");
        read_text(str2, sizeof(str2), 1);

        fp = fopen(str2, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str2);
        else
        {
            fread(&r2, sizeof(int), 1, fp);
            fread(&c2, sizeof(int), 1, fp);
            if(c2!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str2);
                fclose(fp);
                fp = NULL;
            }
            if(r2>3)
            {
                printf("We can't calculate the crross product for vectors with more than 3 coordinates...Please try again!");
                fclose(fp);
                return;
            }
        }

    }while(fp==NULL);

    for(i=0; i<r2; i++)
        fread(arr2+i, sizeof(float), 1, fp);
    fclose(fp);

    do
    {
        printf("\nInsert teh name of the third vector: ");
        read_text(str3, sizeof(str3), 1);

        fp = fopen(str3, "rb");
        if(fp==NULL)
            printf("There is no vector with the name %s...Please try again!\n", str3);
        else
        {
            fread(&r3, sizeof(int), 1, fp);
            fread(&c3, sizeof(int), 1, fp);
            if(c2!=1)
            {
                printf("There is no vector with the name %s...Please try again!\n", str3);
                fclose(fp);
                fp = NULL;
            }
            if(r2>3)
            {
                printf("We can't calculate the crross product for vectors with more than 3 coordinates...Please try again!");
                fclose(fp);
                return;
            }
        }

    }while(fp==NULL);

    for(i=0; i<r3; i++)
        fread(arr3+i, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nInsert a name for the scalar triple product of vectors %s, %s and %s: ", str1, str2, str3);
    read_text(str4, sizeof(str4), 1);
    fp = fopen(str4, "wb");
    fwrite(&c2, sizeof(int), 1, fp);
    fwrite(&c2, sizeof(int), 1, fp);

    x = (arr1[0]*arr2[1]*arr3[2])-(arr1[0]*arr2[2]*arr3[1])-(arr1[1]*arr2[0]*arr3[2])+(arr1[2]*arr2[0]*arr3[1])+(arr1[1]*arr2[2]*arr3[0])-(arr1[2]*arr2[1]*arr3[0]);
    fwrite(&x, sizeof(float), 1, fp);
    fclose(fp);

    printf("\nThe scalar triple product of vectors %s, %s and %s is equal to %.1f\n", str1, str2, str3, x);
}

void op6()
{
    int op;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication between matrix and number\n");
    printf("4. Multiplication between matrices\n");
    printf("5. Transposition\n");

    printf("\nChoose one of the options above by pressing the corresponding key: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            add2();
        return;

        case 2:
            sub2();
        return;

        case 3:
            mult1();
        return;

        case 4:
            mult2();
        return;

        case 5:
            trans();
        return;

        default:
            printf("\nError! There is no operation with key equal to %d!\n", op);
        return;
    }
}

void add2()
{
    FILE *fp1,*fp2;
    char str1[50], str2[50], str3[50];
    int r1, r2, c1, c2, i, j;
    float **p1, **p2;

    printf("\n-----------Addition-------------\n\n");

    getchar();
    while(1)
    {
        do
        {
            printf("\nInsert the name of the first matrix: ");
            read_text(str1, sizeof(str1), 1);

            fp1 = fopen(str1, "rb");
            if(fp1==NULL)
                printf("There is no matrix with the name %s...Please try again!\n", str1);

        }while(fp1==NULL);
        fread(&r1, sizeof(int), 1, fp1);
        fread(&c1, sizeof(int), 1, fp1);

        do
        {
            printf("\nInsert the name of the second matrix: ");
            read_text(str2, sizeof(str2), 1);

            fp2 = fopen(str2, "rb");
            if(fp2==NULL)
                printf("There is no matrix with the name %s...Please try again!\n", str2);

        }while(fp2==NULL);
        fread(&r2, sizeof(int), 1, fp2);
        fread(&c2, sizeof(int), 1, fp2);

        if((r1==r2) && (c1==c2))
            break;
        else
        {
            printf("\nWe can't add to matrices if they don't have the same dimensions...Please try again!");
            fclose(fp1);
            fclose(fp2);
            return;
        }
    }

    p1 = malloc(sizeof(float*)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p1[i] = malloc(sizeof(float)*c1);
        if(!p1[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            fread(p1[i]+j, sizeof(float), 1, fp1);
    }
    fclose(fp1);

    p2 = malloc(sizeof(float*)*r2);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
    {
        p2[i] = malloc(sizeof(float)*c2);
        if(!p2[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            fread(p2[i]+j, sizeof(float), 1, fp2);
    }
    fclose(fp2);

    printf("\nInsert a name for the addition product of matrix %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp1 = fopen(str3, "wb");
    fwrite(&r1, sizeof(int), 1, fp1);
    fwrite(&c1, sizeof(int), 1, fp1);

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            p1[i][j] += p2[i][j];
            fwrite(p1[i]+j, sizeof(float), 1, fp1);
        }
    }
    fclose(fp1);

    printf("\nThe matrix we will get from the addition of %s and %s is the following:\n", str1, str2);
    for(i=0; i<r1; i++)
    {
        printf("|");
        for(j=0; j<c1; j++)
            printf("%6.1f", p1[i][j]);
        printf(" |\n");
    }
    free(p1);
    free(p2);
}

void sub2()
{
    FILE *fp1,*fp2;
    char str1[50], str2[50], str3[50];
    int r1, r2, c1, c2, i, j;
    float **p1, **p2;

    printf("\n-----------Subtraction-------------\n\n");

    getchar();
    while(1)
    {
        do
        {
            printf("\nInsert the name of the first matrix: ");
            read_text(str1, sizeof(str1), 1);

            fp1 = fopen(str1, "rb");
            if(fp1==NULL)
                printf("There is no matrix with the name %s...Please try again!\n", str1);

        }while(fp1==NULL);
        fread(&r1, sizeof(int), 1, fp1);
        fread(&c1, sizeof(int), 1, fp1);

        do
        {
            printf("\nInsert the name of the second: ");
            read_text(str2, sizeof(str2), 1);

            fp2 = fopen(str2, "rb");
            if(fp2==NULL)
                printf("There is no matrix with the name %s...Please try again!\n", str2);

        }while(fp2==NULL);
        fread(&r2, sizeof(int), 1, fp2);
        fread(&c2, sizeof(int), 1, fp2);

        if((r1==r2) && (c1==c2))
            break;
        else
        {
            printf("\nWe can't subtract to matrices if they don't have the same dimensions...Please try again!");
            fclose(fp1);
            fclose(fp2);
            return;
        }
    }

    p1 = malloc(sizeof(float*)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p1[i] = malloc(sizeof(float)*c1);
        if(!p1[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            fread(p1[i]+j, sizeof(float), 1, fp1);
    }
    fclose(fp1);

    p2 = malloc(sizeof(float*)*r2);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
    {
        p2[i] = malloc(sizeof(float)*c2);
        if(!p2[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            fread(p2[i]+j, sizeof(float), 1, fp2);
    }
    fclose(fp2);

    printf("\nInsert a name for the subtraction product of matrix %s and %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp1 = fopen(str3, "wb");
    fwrite(&r1, sizeof(int), 1, fp1);
    fwrite(&c1, sizeof(int), 1, fp1);

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            p1[i][j] -= p2[i][j];
            fwrite(p1[i]+j, sizeof(float), 1, fp1);
        }
    }
    fclose(fp1);

    printf("\nThe matrix we will get from the subtraction of %s and %s is the following:\n", str1, str2);
    for(i=0; i<r1; i++)
    {
        printf("|");
        for(j=0; j<c1; j++)
            printf("%6.1f", p1[i][j]);
        printf(" |\n");
    }
    free(p1);
    free(p2);
}

void mult1()
{
    FILE *fp1;
    char str1[50], str2[50];
    int r1, c1, i, j;
    float **p1, num;

    printf("\n-----------Multiplication between matrix and number-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the matrix: ");
        read_text(str1, sizeof(str1), 1);

        fp1 = fopen(str1, "rb");
        if(fp1==NULL)
            printf("There is no matrix with the name %s...PLease try again!\n", str1);

    }while(fp1==NULL);
    fread(&r1, sizeof(int), 1, fp1);
    fread(&c1, sizeof(int), 1, fp1);

    p1 = malloc(sizeof(float*)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p1[i] = malloc(sizeof(float)*c1);
        if(!p1[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            fread(p1[i]+j, sizeof(float), 1, fp1);
    }
    fclose(fp1);

    printf("\nInsert the number you want to multiply with the matrix %s: ", str1);
    scanf("%f", &num);

    getchar();
    printf("\nInsert a name for the product of multiplication of the matrix %s with the number %.1f: ", str1, num);
    read_text(str2, sizeof(str2), 1);
    fp1 = fopen(str2, "wb");
    fwrite(&r1, sizeof(int), 1, fp1);
    fwrite(&c1, sizeof(int), 1, fp1);

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            p1[i][j] *= num;
            fwrite(p1[i]+j, sizeof(float), 1, fp1);
        }
    }
    fclose(fp1);

    printf("\nThe matrix we will get of the multiplication of %s with the number %.1f is the following:\n", str1, num);
    for(i=0; i<r1; i++)
    {
        printf("|");
        for(j=0; j<c1; j++)
            printf("%8.1f", p1[i][j]);
        printf(" |\n");
    }
    free(p1);
}

void mult2()
{
    FILE *fp1,*fp2;
    char str1[50], str2[50], str3[50];
    int r1, r2, c1, c2, i, j, k;
    float **p1, **p2, **p3, sum;

    printf("\n-----------Multiplication of matrices-------------\n\n");

    getchar();
    while(1)
    {
        do
        {
            printf("\nInsert the name of the first matrix: ");
            read_text(str1, sizeof(str1), 1);

            fp1 = fopen(str1, "rb");
            if(fp1==NULL)
                printf("There is no matrix with the namme %s...Please try again!\n", str1);

        }while(fp1==NULL);
        fread(&r1, sizeof(int), 1, fp1);
        fread(&c1, sizeof(int), 1, fp1);

        do
        {
            printf("\nInsert the name of the second matrix: ");
            read_text(str2, sizeof(str2), 1);

            fp2 = fopen(str2, "rb");
            if(fp2==NULL)
                printf("There is no matrix with the namme %s...Please try again!\n", str2);

        }while(fp2==NULL);
        fread(&r2, sizeof(int), 1, fp2);
        fread(&c2, sizeof(int), 1, fp2);

        if(c1==r2)
            break;
        else
        {
            printf("\nWe can't multiply the two matrices because the number of columns of the first one should be equal to the number of rows of the second one!...Please try again!");
            fclose(fp1);
            fclose(fp2);
            return;
        }
    }

    p1 = malloc(sizeof(float*)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p1[i] = malloc(sizeof(float)*c1);
        if(!p1[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            fread(p1[i]+j, sizeof(float), 1, fp1);
    }
    fclose(fp1);

    p2 = malloc(sizeof(float*)*r2);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r2; i++)
    {
        p2[i] = malloc(sizeof(float)*c2);
        if(!p2[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            fread(p2[i]+j, sizeof(float), 1, fp2);
    }
    fclose(fp2);

    printf("\nInsert a name for the multiplication product of matrix %s with %s: ", str1, str2);
    read_text(str3, sizeof(str3), 1);
    fp1 = fopen(str3, "wb");
    fwrite(&r1, sizeof(int), 1, fp1);
    fwrite(&c2, sizeof(int), 1, fp1);
    p3 = malloc(sizeof(float*)*r1);
    if(!p3)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p3[i] = malloc(sizeof(float)*c2);
        if(!p3[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            sum = 0;
            for(k=0; k<r2; k++)
                sum += p1[i][k]*p2[k][j];
            p3[i][j] = sum;
            fwrite(p3[i]+j, sizeof(float), 1, fp1);
        }
    }
    fclose(fp1);

    printf("\nThe matrix we will get from the multiplication of %s with %s is the following:\n", str1, str2);
    for(i=0; i<r1; i++)
    {
        printf("|");
        for(j=0; j<c2; j++)
            printf("%10.1f", p3[i][j]);
        printf(" |\n");
    }
    free(p1);
    free(p2);
    free(p3);
}

void trans()
{
    FILE *fp1;
    char str1[50], str2[50];
    int r1, c1, i, j;
    float **p1, **p2;

    printf("\n-----------Transposition-------------\n\n");

    getchar();
    do
    {
        printf("\nInsert the name of the matrix: ");
        read_text(str1, sizeof(str1), 1);

        fp1 = fopen(str1, "rb");
        if(fp1==NULL)
            printf("There is no matrix with the name %s...Please try again!\n", str1);

    }while(fp1==NULL);
    fread(&r1, sizeof(int), 1, fp1);
    fread(&c1, sizeof(int), 1, fp1);

    p1 = malloc(sizeof(float*)*r1);
    if(!p1)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<r1; i++)
    {
        p1[i] = malloc(sizeof(float)*c1);
        if(!p1[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            fread(p1[i]+j, sizeof(float), 1, fp1);
    }
    fclose(fp1);

    p2 = malloc(sizeof(float*)*c1);
    if(!p2)
    {
        printf("\nError: There is a problem with memory allocation!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<c1; i++)
    {
        p2[i] = malloc(sizeof(float)*r1);
        if(!p2[i])
        {
            printf("\nError: There is a problem with memory allocation!");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nInsert a name for the transposition of matrix %s: ", str1);
    read_text(str2, sizeof(str2), 1);
    fp1 = fopen(str2, "wb");
    fwrite(&c1, sizeof(int), 1, fp1);
    fwrite(&r1, sizeof(int), 1, fp1);

    for(i=0; i<c1; i++)
    {
        for(j=0; j<r1; j++)
        {
            p2[i][j] = p1[j][i];
            fwrite(p2[i]+j, sizeof(float), 1, fp1);
        }
    }
    fclose(fp1);

    printf("\nThe transposition of matrix %s is the following:\n", str1);
    for(i=0; i<c1; i++)
    {
        printf("|");
        for(j=0; j<r1; j++)
            printf("%6.1f", p2[i][j]);
        printf(" |\n");
    }
    free(p1);
    free(p2);
}
