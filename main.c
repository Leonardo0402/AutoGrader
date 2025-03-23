/*
1.  定义标准答案数据结构（如 struct Answer { int id; char correct_option; }）
2.  读取标准答案文件，存入数组
3.  读取考生答案文件，存入数组
4.  遍历考生答案，与标准答案比对并计算分数
5.  生成评分报告，输出到终端或文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100

struct Answer{
    int id; // 题号
    char correct_option; // 题号
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
    printf("请选择下面选项: \n");
    printf("----- 1.导入标准答案 -----\n");
    printf("----- 2.导入学生答案 -----\n");
    printf("----- 3.开始自动阅卷 -----\n");
    printf("----- 4. Exit -----\n");
    printf("请输入你的选择：");
}

void importAnswer(struct Answer answer[])
{
    int mode ;
    int count = 0;
    printf(">>>>> 1. 从TXT文件中导入答案\n");
    printf(">>>>> 2. 手动输入答案\n");
    printf("请选择：");
    scanf("%d", &mode);
    while(getchar() != '\n'); // 清理 stdin 换行
    if(mode == 1)
    {
        char filename[100];
        printf("请输入文本文件名称(e.g. answer.txt): ");
        // 删除空格
        fgets(filename, sizeof(filename),stdin); // stdin从键盘读取输入的数据
        filename[strcspn(filename, "\n")] = 0; // strcspn去掉由fgets()带来的多余的空格符

        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            printf("无法打开文件");
            exit(0);
        }
        while(fscanf(fp, "%d %c", &answer[count].id, &answer[count].correct_option) == 2) //首先，txt的编写格式应该类似于“1 A”，数字和字母之间要有一个空格，完整读取题号与答案返回2的时候，循环继续
        {
            count++;
            if(count > MAX_QUESTIONS)   break;
        }
        fclose(fp);
        printf(">>>>> 有 %d 个答案已经从 %s 文件中导入进来\n", count, filename);
    }
    else if(mode == 2)
    {
        printf("请手动输入标准答案(输入0停止)\n");
        while(1)
        {
            if(count >= MAX_QUESTIONS)
            {
                printf("已达到最大题目数量 %d，自动结束输入。\n", MAX_QUESTIONS);
                break;
            }

            printf("请输入每题题号：");
            scanf("%d", &answer[count].id);
            if(answer[count].id == 0)    break;
            printf("请输入正确的答案(A/B/C/D)：");
            scanf(" %c", &answer[count].correct_option);
            count++;
            if(count > MAX_QUESTIONS)    break;
            printf(">>>>> 有 %d 个答案已经输入进来\n", count);

            char confirm;
            printf("是否已经完整的输入答案：(Y/N)\n");
            scanf(" %c", &confirm);
            if(confirm == 'Y' || confirm == 'y')
            {
                printf("已输入的答案如下：\n");
                for(int i = 0; i < count; i++)
                {
                    printf("题号：%d --> 正确答案是：%c\n", answer[i].id, answer[i].correct_option);
                }
            }
            else
            {
                printf("请继续完善答案后再确认。\n");
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
    printf(">>>>> 1. 从TXT文件中导入答案\n");
    printf(">>>>> 2. 手动输入答案\n");
    printf("请选择：");
    scanf("%d", &mode);
    while(getchar() != '\0')
    if(mode == 1)
    {
        char filename[100];
        printf("请输入要导入的文本文件：(e.g. answer.txt): ");
        fgets(filename, sizeof(filename) , stdin);
        filename[strcspn(filename, "\n")] = 0;
        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            printf("无法打开文件");
            exit(0);
        }

        while(fscanf(fp, "%d %c", &answer[count].id, &answer[count].correct_option) == 2)
        {
            count++;
            if(count > MAX_QUESTIONS)    break;
        }
        fclose(fp);
        printf(">>>>> 已经有 %d 个答案从 %s 文件中导入进来", count, filename);
    }
    else if(mode == 2)
    {
        printf("请手动输入学生的答案(输入0停止): \n");
        while(1)
        {
            if(count >= MAX_QUESTIONS)
            {
                printf("已经超过了最大的录入数量！\n");
                break;
            }
            printf("请输入每题题号：");
            scanf("%d", &answer[count].id);
            if(answer[count].id == 0)    break;
            printf("请输入每题答案(A/B/C/D)：");
            scanf("%c", &answer[count].correct_option);
            count++;

            char confirm;
            printf("是否输入完整答案(Y/N): ");
            scanf(" %c", &confirm);

            if(confirm == 'Y' || confirm == 'y')
            {
                printf("已输入的学生答案如下：\n");
                for(int i = 0; i < count; i++)
                {
                    printf("题号：%d --> 正确答案是：%c\n", answer[i].id, answer[i].correct_option);
                }
            }
            else
            {
                printf("请继续输入答案！");
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

    // 开始阅卷
    system("pause");
    return 0;
}
