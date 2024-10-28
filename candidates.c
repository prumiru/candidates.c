#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *candidates[12] = {
        "박지연", "000001", "Ethan Smith", "000002", "Helena Silva", "000003", "Liam Wilson", "000004", "Sakura Tanaka", "000005", "Carlos Mendez", "000006"};

    char judge_name[50], expertise[50];
    printf("####################################\n");
    printf("#       오디션 심사 결과 입력      #\n");
    printf("####################################\n");
    printf("> 심사자 이름: ");
    scanf("%s", judge_name);
    printf("> 전문 분야: ");
    scanf("%s", expertise);

    // 후보자 점수 배열 (ID, 음악, 댄스, 보컬, 비주얼, 전달력, 총점)
    int scoring_sheet[42];

    // 후보자 점수 입력
    for (int i = 0; i < 6; i++)
    {
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("후보자: %s\n", candidates[i * 2]);

        scoring_sheet[i * 7] = atoi(candidates[i * 2 + 1]); // 후보자 ID candidates에서 꺼내옴

        int total_score = 0;
        for (int j = 1; j <= 5; j++)
        {
            int score = -1;
            const char *fields[] = {"음악 소양", "댄스", "보컬", "비주얼", "전달력"};
            while (score < 0 || score > 100)
            {
                printf("%s: ", fields[j - 1]);
                scanf("%d", &score);
                if (score < 0 || score > 100)
                {
                    printf("0에서 100 사이의 점수만 입력 가능.\n");
                }
            }
            scoring_sheet[i * 7 + j] = score;
            total_score += score;
        }
        scoring_sheet[i * 7 + 6] = total_score;
    }

    // 총점 출력
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("입력을 모두 완료했습니다.\n");
    printf("입력하신 내용을 검토하세요!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%s: %d\n", candidates[i * 2], scoring_sheet[i * 7 + 6]);
    }

    // 제출 확인
    char submit;
    printf("제출하시겠습니까? ");
    getchar();
    scanf("%c", &submit);

    if (submit == 'Y' || submit == 'y')
    {
        printf("***최종 제출을 완료했습니다.***\n");
        printf(">\n");

        // 버블 정렬
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (scoring_sheet[i * 7 + 6] < scoring_sheet[j * 7 + 6])
                {
                    // 점수 데이터 교환
                    for (int k = 0; k < 7; k++)
                    {
                        int temp = scoring_sheet[i * 7 + k];
                        scoring_sheet[i * 7 + k] = scoring_sheet[j * 7 + k];
                        scoring_sheet[j * 7 + k] = temp;
                    }
                    // 이름 교환
                    char *temp_name = candidates[i * 2];
                    candidates[i * 2] = candidates[j * 2];
                    candidates[j * 2] = temp_name;

                    char *temp_id = candidates[i * 2 + 1];
                    candidates[i * 2 + 1] = candidates[j * 2 + 1];
                    candidates[j * 2 + 1] = temp_id;
                }
            }
        }

        // 합격 멤 출력
        printf("=======================================\n");
        printf("후보 선발 결과 집계 중 ...\n");
        printf("=======================================\n");
        printf("#########################################\n");
        printf("# 밀리웨이즈의 멤버가 된 걸 축하합니다! #\n");
        printf("#########################################\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d. %s\n", i + 1, candidates[i * 2]);
        }
        printf("\n>\n");
    }
    else
    {
        printf("다시 처음부터 입력.\n");
    }

    getchar();
    getchar();

    return 0;
}
