#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 6명의 후보자 데이터를 1차원 배열로 선언
char candidate01[11][100], candidate02[11][100], candidate03[11][100];
char candidate04[11][100], candidate05[11][100], candidate06[11][100];

// 후보자 데이터를 2차원 배열로 관리
char* candidates[6][11] = { candidate01, candidate02, candidate03, candidate04, candidate05, candidate06 };

// 속성명 배열
const char* member_info[11] = { "성명", "생년월일(YYYY/MM/DD 형식)", "성별", "메일 주소", "국적", "BMI", "주 스킬", "보조 스킬", "한국어 등급", "MBTI", "소개" };

// 만 나이 계산 함수
int calculateAge(const char* dob) {
    int year, month, day;
    scanf_sf(dob, "%d년 %d월 %d일", &year, &month, &day);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int current_year = tm.tm_year + 1900;
    int current_month = tm.tm_mon + 1;
    int current_day = tm.tm_mday;

    int age = current_year - year;

    if (current_month < month || (current_month == month && current_day < day)) {
        age--;
    }

    return age;
}

// 한국어 등급을 텍스트로 변환하는 함수
const char* getTopikText(int level) {
    if (level == 0) return "원어민";
    else if (level == 1) return "초급";
    else if (level == 2) return "중급";
    else if (level == 3) return "고급";
    else return "최고급";
}

// 오디션 후보자 데이터 입력 함수
void inputCandidates() {
    int i = 0;
    while (i < 6) {
        printf("####################################\n");
        printf("     오디션 후보자 데이터 입력\n");
        printf("####################################\n");
        printf("후보자 %d의 정보를 입력합니다.\n---------------------------------\n", i + 1);

        for (int j = 0; j < 11; j++) {
            printf("%s: ", member_info[j]);
            fgets(candidates[i][j], 100, stdin);
            candidates[i][j][strcspn(candidates[i][j], "\n")] = '\0'; // 개행 문자 제거
        }
        i++;
    }
}

// 오디션 후보자 데이터 출력 함수
void printCandidates() {
    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    printf("=====================================================================================================\n");
    printf("성   명   | 생   일         | 성별 | 메   일             | 국적 | BMI  | 주 스킬 | 보조 스킬 | 한국어 등급 | MBTI |\n");
    printf("=====================================================================================================\n");

    for (int i = 0; i < 6; i++) {
        int age = calculateAge(candidates[i][1]);
        printf("%s(%d) | %s | %s   | %s | %s | %s | %s   | %s   | %s    | %s\n",
            candidates[i][0], age, candidates[i][1], candidates[i][2], candidates[i][3],
            candidates[i][4], candidates[i][5], candidates[i][6], candidates[i][7],
            getTopikText(atoi(candidates[i][8])), candidates[i][9]);
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[i][10]);
        printf("-----------------------------------------------------------------------------------------------------\n");
    }
}

int main() {
    char group_name[50];

    // 오디션 그룹명을 입력받음
    printf("지원하는 오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    group_name[strcspn(group_name, "\n")] = '\0'; // 개행 문자 제거

    // 후보자 데이터 입력
    inputCandidates();

    // 입력된 후보자 정보 출력
    printf("\n오디션 그룹명: %s\n", group_name);
    printCandidates();

    return 0;
}
