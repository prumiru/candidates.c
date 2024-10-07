#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 후보자 정보 구조체 정의
struct Candidate {
    char name[50];
    char dob[15];      // 생년월일
    char gender[2];    // 성별
    char email[50];    // 이메일
    char nationality[30]; // 국적
    float bmi;         // BMI
    char main_skill[30]; // 주 스킬
    char sub_skill[30];  // 보조 스킬
    int topik_level;   // 한국어 등급
    char mbti[5];      // MBTI
    char introduction[200]; // 소개
};

// 후보자 정보 배열
struct Candidate candidates[6];

// 함수 선언
void input_candidate_data();
void display_candidate_data();
int calculate_age(const char* dob);

int main() {
    char group_name[50]; // 그룹명 저장
    printf("오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    group_name[strcspn(group_name, "\n")] = '\0';  // 개행문자 제거

    input_candidate_data();

    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회 (%s)\n", group_name);
    printf("####################################\n");

    display_candidate_data();

    return 0;
}

// 후보자 데이터를 입력하는 함수
void input_candidate_data() {
    for (int i = 0; i < 6; i++) {
        printf("\n%d번째 후보자의 정보를 입력하세요.\n", i + 1);

        printf("성명: ");
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';  // 개행문자 제거

        printf("생년월일(YYYY/MM/DD 형식): ");
        fgets(candidates[i].dob, sizeof(candidates[i].dob), stdin);
        candidates[i].dob[strcspn(candidates[i].dob, "\n")] = '\0';

        printf("성별(여성이면 F, 남성이면 M): ");
        fgets(candidates[i].gender, sizeof(candidates[i].gender), stdin);
        candidates[i].gender[strcspn(candidates[i].gender, "\n")] = '\0';

        printf("메일 주소: ");
        fgets(candidates[i].email, sizeof(candidates[i].email), stdin);
        candidates[i].email[strcspn(candidates[i].email, "\n")] = '\0';

        printf("국적: ");
        fgets(candidates[i].nationality, sizeof(candidates[i].nationality), stdin);
        candidates[i].nationality[strcspn(candidates[i].nationality, "\n")] = '\0';

        printf("BMI: ");
        scanf_s("%f", &candidates[i].bmi);

        printf("주 스킬: ");
        fgets(candidates[i].main_skill, sizeof(candidates[i].main_skill), stdin);
        candidates[i].main_skill[strcspn(candidates[i].main_skill, "\n")] = '\0';

        printf("보조 스킬: ");
        fgets(candidates[i].sub_skill, sizeof(candidates[i].sub_skill), stdin);
        candidates[i].sub_skill[strcspn(candidates[i].sub_skill, "\n")] = '\0';

        printf("한국어 등급(TOPIK, 숫자): ");
        scanf_s("%d", &candidates[i].topik_level);

        printf("MBTI: ");
        fgets(candidates[i].mbti, sizeof(candidates[i].mbti), stdin);
        candidates[i].mbti[strcspn(candidates[i].mbti, "\n")] = '\0';

        printf("한 줄 자기소개: ");
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        candidates[i].introduction[strcspn(candidates[i].introduction, "\n")] = '\0';
    }
}

// 후보자 데이터를 출력하는 함수
void display_candidate_data() {
    printf("=============================================================================================\n");
    printf("성   명|  생년월일  | 성별 | 메일 주소 | 국적 | BMI  | 주 스킬 | 보조 스킬 | TOPIK | MBTI  |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < 6; i++) {
        printf("%-8s | %s | %s | %-20s | %-6s | %.1f | %-7s | %-8s | %d | %s |\n",
            candidates[i].name, candidates[i].dob, candidates[i].gender,
            candidates[i].email, candidates[i].nationality, candidates[i].bmi,
            candidates[i].main_skill, candidates[i].sub_skill,
            candidates[i].topik_level, candidates[i].mbti);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[i].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }
}

// 생년월일로 나이를 계산하는 함수 (추가 구현 가능)
int calculate_age(const char* dob) {
    // 생년월일에서 나이를 계산하는 로직을 추가할 수 있습니다.
    return 0;
}
