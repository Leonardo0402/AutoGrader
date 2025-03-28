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
    printf("|      Author: GWW | v1.5      |\n");
    printf("+--------------------------------------+\n\n");
    printf("��ѡ������ѡ��: \n");
    printf("----- 1.�����׼�� -----\n");
    printf("----- 2.����ѧ���� -----\n");
    printf("----- 3.��ʼ�Զ��ľ� -----\n");
    printf("----- 4. Exit -----\n");
    printf("���������ѡ��\n");
}

int importAnswer(struct Answer answer[])
{
    int mode ;

    int count = 0 ;

    printf(">>>>>>> 1. ��TXT�ļ��е����\n");
    printf(">>>>>>> 2. �ֶ������\n");
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
        int id;
        char opt;
        while (!feof(fp)) {
            int result = fscanf(fp, "%d %c", &id, &opt);
            if (result == 2) {
                if (count >= MAX_QUESTIONS) {
                    printf("�ﵽ���������ֹͣ��ȡ\n");
                    break;
                }
                answer[count].id = id;
                answer[count].correct_option = opt;
                count++;
            } else {
                // ���� fscanf ��ѭ��������һ����
                fscanf(fp, "%*[^\n]\n");
            }
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
        }

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
    else
    {
        printf("Invalid Choice");
    }
    return count;
}

int importStuAnswer(struct Answer stuAnswer[])
{
    int mode;
    int count = 0;
    printf(">>>>>>> 1. ��TXT�ļ��е����\n");
    printf(">>>>>>> 2. �ֶ������\n");
    printf("��ѡ��");
    scanf("%d", &mode);
    getchar();
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
        int id;
        char opt;
        while (!feof(fp)) {
            int result = fscanf(fp, "%d %c", &id, &opt);
            if (result == 2) {
                if (count >= MAX_QUESTIONS) {
                    printf("�Ѵﵽ���¼��������ֹͣ��ȡ\n");
                    break;
                }
                stuAnswer[count].id = id;
                stuAnswer[count].correct_option = opt;
                count++;
            } else {
                // ������ǰ��Ч�б�����ѭ��
                fscanf(fp, "%*[^\n]\n");
            }
        }
        fclose(fp);
        printf(">>>>> �Ѿ��� %d ���𰸴� %s �ļ��е������\n", count, filename);
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
            scanf("%d", &stuAnswer[count].id);
            if(stuAnswer[count].id == 0)    break;
            printf("������ÿ���(A/B/C/D)��");
            scanf(" %c", &stuAnswer[count].correct_option);
            count++;
        }
        char confirm;
        printf("�Ƿ�����������(Y/N): ");
        scanf(" %c", &confirm);

        if(confirm == 'Y' || confirm == 'y')
        {
            printf("�������ѧ�������£�\n");
            for(int i = 0; i < count; i++)
            {
                printf("�������ѧ�������£�\n");
                for(int i = 0; i < count; i++)
                {
                    printf("��ţ�%d --> ��ȷ���ǣ�%c\n", stuAnswer[i].id, stuAnswer[i].correct_option);
                }
            }
        }
        else
        {
            printf("���������𰸣�");
        }
    }
    else
    {
        printf("Invalid Choice");
    }
    return count;
}

int autoGrade(struct Answer standard[], int standard_count, struct Answer student[], int student_count)
{
    int total = standard_count;
    int correct = 0;

    for(int i = 0; i < standard_count; i++)
    {
        int sid = standard[i].id;
        char correct_option = standard[i].correct_option;
        for(int j = 0; j < student_count; j++)
        {
            if(student[j].id == sid)
            {
                if(student[j].correct_option == correct_option)
                {
                    correct++;
                }
                break;
            }
        }
    }

    printf("�� %d ����Ŀ����� %d ����Ŀ����ȷ�ʣ�%.2f%%\n",total, correct, (correct * 100.0) / total);

    return correct;
}

int main()
{
    struct Answer answer[MAX_QUESTIONS];
    struct Answer stuAnswer[MAX_QUESTIONS];
    int standard_count = 0;
    int student_count = 0;

    display();
    printf(">>>>> 1. ���ڵ����׼�� \n");
    standard_count = importAnswer(answer);
    printf(">>>>> 2. ���ڵ���ѧ���� \n");
    student_count = importStuAnswer(stuAnswer);
    printf(">>>>> 3. ���ڿ�ʼ�Զ��о� \n");
    autoGrade(answer, standard_count, stuAnswer , student_count);

    system("pause");
    return 0;
}