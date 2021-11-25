#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 0
#define MAX_NUMBER_OF_POINT 10

#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#pragma warning(disable: 4996)

int main() {
    system("chcp 1251");
    system("cls");
    int current;
    int Start_point = NULL;
    int Finish_point = NULL;
    int i, j;
    //int Numbers_first[MAX_NUMBER_OF_POINT];
    //int Numbers_second[MAX_NUMBER_OF_POINT];
    //for (i = 0; i < MAX_NUMBER_OF_POINT; i++)
    //{
    //	Numbers_first[i] = 0;
    //	Numbers_second[i] = 0;
    //}
    //------------------------------------------------------------------------//

    FILE* f1;
    if ((f1 = fopen("Graph1.txt", "w")) == NULL) {
        printf("Cannot open Graph1.txt.\n");
        exit(1);
    }

    fprintf(f1, "digraph D{\n");
    printf("Введите первый граф в формате:         |\n №_первой_вершины -> №_второй_вершины; |\n");
    printf("---------------------------------------|\n");
    while ((current = getchar()) != EOF)
        fputc(current, f1);
    fprintf(f1, "}");
    fclose(f1);

    //------------------------------------------------------------------------//

    FILE* f2;
    if ((f2 = fopen("Graph2.txt", "w")) == NULL) {
        printf("Cannot open Graph2.txt.\n");
        exit(1);
    }

    fprintf(f2, "digraph D{\n");
    printf("Введите второй граф в формате:         |\n №_первой_вершины -> №_второй_вершины; |\n");
    printf("---------------------------------------|\n");
    while ((current = getchar()) != EOF)
        fputc(current, f2);
    fprintf(f2, "}");
    fclose(f2);

    //------------------------------------------------------------------------//	

    system("dot C:\\Users\\Professional\\Desktop\\Projects\\Homework_3\\Graph1.txt -Tbmp -o Graph1.bmp");
    system("dot C:\\Users\\Professional\\Desktop\\Projects\\Homework_3\\Graph2.txt -Tbmp -o Graph2.bmp");
    system("start Graph1.bmp");
    system("start Graph2.bmp");

    //------------------------------------------------------------------------//
    //f1 = fopen("Graph1.txt", "r");
    //while ((current = fgetc(f1)) != EOF)
    //{
    //	if ((current == '1') || (current == '2') || (current == '3') || (current == '4') || (current == '5') || (current == '6') || (current == '7') || (current == '8') || (current == '9') || (current == '10'))
    //		Numbers_first[current - '0'] = 1;
    //}
    //fclose(f1);
    //f2 = fopen("Graph2.txt", "r");
    //while ((current = fgetc(f2)) != EOF)
    //{
    //	if ((current == '1') || (current == '2') || (current == '3') || (current == '4') || (current == '5') || (current == '6') || (current == '7') || (current == '8') || (current == '9') || (current == '10'))
    //		Numbers_second[current - '0'] = 1;
    //}
    //fclose(f2);
    int m1[MAX_NUMBER_OF_POINT][MAX_NUMBER_OF_POINT];
    int m2[MAX_NUMBER_OF_POINT][MAX_NUMBER_OF_POINT];
    int buffer[MAX_NUMBER_OF_POINT][MAX_NUMBER_OF_POINT];
    for (i = 0; i < MAX_NUMBER_OF_POINT; i++)
        for (j = 0; j < MAX_NUMBER_OF_POINT; j++) {
            m1[i][j] = 0;
            m2[i][j] = 0;
            buffer[i][j] = 0;
        }
    //------------------------------------------------------------------------//

    f1 = fopen("Graph1.txt", "r");
    while ((Start_point = fgetc(f1)) != EOF) {
        if ((Start_point == '1') || (Start_point == '2') || (Start_point == '3') || (Start_point == '4') || (Start_point == '5') || (Start_point == '6') || (Start_point == '7') || (Start_point == '8') || (Start_point == '9')) {
            while ((Finish_point = fgetc(f1)) != EOF) {
                if ((Finish_point == '1') || (Finish_point == '2') || (Finish_point == '3') || (Finish_point == '4') || (Finish_point == '5') || (Finish_point == '6') || (Finish_point == '7') || (Finish_point == '8') || (Finish_point == '9')) {
                    m1[Start_point - '0'][Finish_point - '0'] = 1;
                    break;
                }
            }
        }
    }
    fclose(f1);

    f2 = fopen("Graph2.txt", "r");
    while ((Start_point = fgetc(f2)) != EOF) {
        if ((Start_point == '1') || (Start_point == '2') || (Start_point == '3') || (Start_point == '4') || (Start_point == '5') || (Start_point == '6') || (Start_point == '7') || (Start_point == '8') || (Start_point == '9')) {
            while ((Finish_point = fgetc(f2)) != EOF) {
                if ((Finish_point == '1') || (Finish_point == '2') || (Finish_point == '3') || (Finish_point == '4') || (Finish_point == '5') || (Finish_point == '6') || (Finish_point == '7') || (Finish_point == '8') || (Finish_point == '9')) {
                    m2[Start_point - '0'][Finish_point - '0'] = 1;
                    break;
                }
            }
        }
    }
    fclose(f1);

    //------------------------------------------------------------------------//
    //for (i = 1; i < MAX_NUMBER_OF_POINT; i++)
    //	{
    //	for (j = 1; j < MAX_NUMBER_OF_POINT; j++)
    //		{
    //		printf("%3d",m1[i][j]);
    //		}
    //	printf("\n");
    //	}	
    //printf("\n\n");

    //for (i = 1; i < MAX_NUMBER_OF_POINT; i++)
    //{
    //	for (j = 1; j < MAX_NUMBER_OF_POINT; j++)
    //	{
    //		printf("%3d", m2[i][j]);
    //	}
    //	printf("\n");
    //}

    for (i = 1; i < MAX_NUMBER_OF_POINT; i++) {
        for (j = 1; j < MAX_NUMBER_OF_POINT; j++) {
            if ((m1[i][j] == 1) && (m2[i][j] == 1))
                buffer[i][j] = 1;
        }
    }

    //for (i = 1; i < MAX_NUMBER_OF_POINT; i++)
    //{
    //	for (j = 1; j < MAX_NUMBER_OF_POINT; j++)
    //	{
    //		printf("%2d", buffer[i][j]);
    //	}
    //	printf("\n");
    //}
    FILE* Result_graph_file;
    if ((Result_graph_file = fopen("Result_graph_file.txt", "w")) == NULL) {
        printf("Cannot open Result_graph_file.\n");
        exit(1);
    }
    fprintf(Result_graph_file, "digraph D{\n");
    //for (i = 1; i < MAX_NUMBER_OF_POINT; i++)
    //	{
    //	for (j = 1; j < MAX_NUMBER_OF_POINT; j++)
    //		{
    //		if (buffer[i][j] == 1)
    //			{
    //			fprintf(Result_graph_file,"%d;\n",i);
    //			fprintf(Result_graph_file, "%d;\n", i);
    //			}
    //		}
    //	}

    for (i = 1; i < MAX_NUMBER_OF_POINT; i++) {
        for (j = 1; j < MAX_NUMBER_OF_POINT; j++) {
            if (buffer[i][j] == 1) {
                fprintf(Result_graph_file, "%d -> %d;\n", i, j);
            }
        }
    }
    fprintf(Result_graph_file, "}");
    fclose(Result_graph_file);
    system("dot C:\\Users\\Professional\\Desktop\\Projects\\Homework_3\\Result_graph_file.txt -Tbmp -o Result_graph_file.bmp");
    system("start Result_graph_file.bmp");

    return 0;
}
