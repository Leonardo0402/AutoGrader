/*
1.  �����׼�����ݽṹ���� struct Answer { int id; char correct_option; }��
2.  ��ȡ��׼���ļ�����������
3.  ��ȡ�������ļ�����������
4.  ���������𰸣����׼�𰸱ȶԲ��������
5.  �������ֱ��棬������ն˻��ļ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100

struct Answer{
    int id; // ���
    char correct_option; // ���
};

void display()
{
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("|         WELCOME TO AUTO-GRADER        |\n");
    printf("|                                      |\n");
    printf("|      Automatically Grade Exams       |\n");
    printf("|                                      |\n");
    printf("|      Author: GWW | v1.0      |\n");
    printf("+--------------------------------------+\n\n");
    printf("��ѡ������ѡ��: \n");
    printf("----- 1.�����׼�� -----\n");
    printf("----- 2.����ѧ���� -----\n");
    printf("----- 3.��ʼ�Զ��ľ� -----\n");
    printf("----- 4. Exit -----\n");
    printf("���������ѡ��");
}

void importAnswer(struct Answer answer[])
{
    int mode ;
    int count = 0;
    printf(">>>>> 1. ��TXT�ļ��е����\n");
    printf(">>>>> 2. �ֶ������\n");
    printf("��ѡ��");
    scanf("%d", &mode);
    while(getchar() != '\n'); // ���� stdin ����
    if(mode == 1)
    {
        char filename[100];
        printf("�������ı��ļ�����(e.g. answer.txt): ");
        // ɾ���ո�
        fgets(filename, sizeof(filename),stdin); // stdin�Ӽ��̶�ȡ���������
        filename[strcspn(filename, "\n")] = 0; // strcspnȥ����fgets()�����Ķ���Ŀո��

        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            printf("�޷����ļ�");
            exit(0);
        }
        while(fscanf(fp, "%d %c", &answer[count].id, &answer[count].correct_option) == 2) //���ȣ�txt�ı�д��ʽӦ�������ڡ�1 A�������ֺ���ĸ֮��Ҫ��һ���ո�������ȡ�����𰸷���2��ʱ��ѭ������
        {
            count++;
            if(count > MAX_QUESTIONS)   break;
        }
        fclose(fp);
        printf(">>>>> �� %d �����Ѿ��� %s �ļ��е������\n", count, filename);
    }
    else if(mode == 2)
    {
        printf("���ֶ������׼��(����0ֹͣ)\n");
        while(1)
        {
            if(count >= MAX_QUESTIONS)
            {
                printf("�Ѵﵽ�����Ŀ���� %d���Զ��������롣\n", MAX_QUESTIONS);
                break;
            }

            printf("������ÿ����ţ�");
            scanf("%d", &answer[count].id);
            if(answer[count].id == 0)    break;
            printf("��������ȷ�Ĵ�(A/B/C/D)��");
            scanf(" %c", &answer[count].correct_option);
            count++;
            if(count > MAX_QUESTIONS)    break;
            printf(">>>>> �� %d �����Ѿ��������\n", count);

            char confirm;
            printf("�Ƿ��Ѿ�����������𰸣�(Y/N)\n");
            scanf(" %c", &confirm);
            if(confirm == 'Y' || confirm == 'y')
            {
                printf("������Ĵ����£�\n");
                for(int i = 0; i < count; i++)
                {
                    printf("��ţ�%d --> ��ȷ���ǣ�%c\n", answer[i].id, answer[i].correct_option);
                }
            }
            else
            {
                printf("��������ƴ𰸺���ȷ�ϡ�\n");
            }
        }
    }
    else
    {
        printf("Invalid Choice");
    }
}

void importStuAnswer(struct Answer answer[])
{
    int mode;
    int count = 0;
    printf(">>>>> 1. ��TXT�ļ��е����\n");
    printf(">>>>> 2. �ֶ������\n");
    printf("��ѡ��");
    scanf("%d", &mode);
    while(getchar() != '\0')
    if(mode == 1)
    {
        char filename[100];
        printf("������Ҫ������ı��ļ���(e.g. answer.txt): ");
        fgets(filename, sizeof(filename) , stdin);
        filename[strcspn(filename, "\n")] = 0;
        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            printf("�޷����ļ�");
            exit(0);
        }

        while(fscanf(fp, "%d %c", &answer[count].id, &answer[count].correct_option) == 2)
        {
            count++;
            if(count > MAX_QUESTIONS)    break;
        }
        fclose(fp);
        printf(">>>>> �Ѿ��� %d ���𰸴� %s �ļ��е������", count, filename);
    }
    else if(mode == 2)
    {
        printf("���ֶ�����ѧ���Ĵ�(����0ֹͣ): \n");
        while(1)
        {
            if(count >= MAX_QUESTIONS)
            {
                printf("�Ѿ�����������¼��������\n");
                break;
            }
            printf("������ÿ����ţ�");
            scanf("%d", &answer[count].id);
            if(answer[count].id == 0)    break;
            printf("������ÿ���(A/B/C/D)��");
            scanf("%c", &answer[count].correct_option);
            count++;

            char confirm;
            printf("�Ƿ�����������(Y/N): ");
            scanf(" %c", &confirm);

            if(confirm == 'Y' || confirm == 'y')
            {
                printf("�������ѧ�������£�\n");
                for(int i = 0; i < count; i++)
                {
                    printf("��ţ�%d --> ��ȷ���ǣ�%c\n", answer[i].id, answer[i].correct_option);
                }
            }
            else
            {
                printf("���������𰸣�");
            }
        }
    }
    else
    {
        printf("Invalid Choice");
    }
}

int main()
{
    struct Answer answer[MAX_QUESTIONS];
    int choice ;
    display();
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            importAnswer(answer);
            break;
        case 2:
            importStuAnswer(answer);
            break;
        case 3:
            break;
        default:
            break;
    }

    // ��ʼ�ľ�
    system("pause");
    return 0;
}
