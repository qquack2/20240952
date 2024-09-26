#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50

int count;
int stock[MAX_PRODUCTS] = { 0 };
int sold[MAX_PRODUCTS] = { 0 };
int initialStock[MAX_PRODUCTS] = { 0 };
int soldTotal = 0, initialTotal = 0;  
char productNames[MAX_PRODUCTS][MAX_NAME];

void inStock() {
    printf("상품 별 입고수량 입력 \n");
    for (int i = 0; i < count; i++) {
        printf("상품 ID %d: ", i + 1);
        scanf("%d", &count);
        initialStock[i] = stock[i];
        sold[i] = 0;
        initialTotal += stock[i];
    }
}

void sTotal() {
    int soldInput;
    printf("상품 별 판매수량 입력 \n");
    for (int i = 0; i < count; i++) {
        printf("%s의 판매 수량: ", productNames[i]);
        scanf("%d", &soldInput);
        if (soldInput <= stock[i]) {
            stock[i] -= soldInput;
            sold[i] += soldInput;
            soldTotal += soldInput;
        }
        else {
            printf("판매 수량이 재고보다 많습니다. 최대 판매 가능 수량: %d\n", stock[i]);
        }
    }
}

void allTotal() {
    printf("재고수량: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n총 판매량: %d (판매율: %.2f%%)\n", soldTotal, ((double)soldTotal / initialTotal) * 100);

    int maxSold = sold[0], minSold = sold[0];
    int maxID = 1, minID = 1;

    for (int i = 1; i < count; i++) {
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxID = i + 1;
        }
        if (sold[i] < minSold) {
            minSold = sold[i];
            minID = i + 1;
        }
    }

    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxID, maxSold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minID, minSold);

    for (int i = 0; i < count; i++) {
        if (stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i]);
        }
    }
}

void inputName()
{
    printf("상품명을 입력하세요:\n");
    for (int i = 0; i < count; i++) {
        printf("ID %d 상품명: ", i + 1);
        scanf("%s", &productNames[i]);
    }
}

int main() {
    int choice;
    
    if (count > 1 || count < 100) {
        printf("상품개수를 입력하세요(1~100): ");
        scanf("%d", &count);
    }
    else {
        printf("잘못입력하였습니다. 다시 입력 해주세요(1~100)");
    }
    do {
        printf("[쇼핑몰 관리 프로그램]\n");
        printf("1.입고 2.판매 3.상품현황 4.상품명 입력 5종료\n");
        printf("원하는 메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inStock();
            break;
        case 2:
            sTotal();
            break;
        case 3:
            allTotal();
            break;
        case 4:
            inputName();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
        }
    } while (1);

    return 0;
}
