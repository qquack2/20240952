#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 100

int main()
{
    int count;
    int stock[MAX_PRODUCTS];
    int sold[MAX_PRODUCTS];
    int initialStock[MAX_PRODUCTS];
    int id, soldInput, i;
    int soldTotal = 0, initialTotal = 0;

    do {
        printf("상품 개수(종류)입력 (1 ~ 100): ");
        scanf("%d", &count);
    } while (count < 1 || count > 100);

    printf("상품 별 입고수량 입력: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
        initialStock[i] = stock[i];
        sold[i] = 0;
        initialTotal += stock[i];
    }

    printf("상품 별 판매수량을 입력: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &soldInput);
        if (soldInput <= stock[i]) {
            stock[i] -= soldInput;
            sold[i] = soldInput;
            soldTotal += soldInput;
        }
        else {
            printf("판매 수량이 재고보다 많음. 최대 판매 가능 수량: %d\n", stock[i]);
        }
    }

    while (1) {
        printf("재고 수량을 확인할 상품 ID를 입력 (1 ~ %d, 종료는 0): ", count);
        scanf("%d", &id);

        if (id == 0) {
            break;
        }
        else if (id > 0 && id <= count) {
            printf("남은 재고 수량 : ");
            for (i = 0; i < count; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n");
        }
        else {
            printf("잘못된 ID입니다. 다시 입력\n");
        }
    }

    printf("총 판매량 %d (판매율 %.2f%%)\n", soldTotal, ((double)soldTotal / initialTotal) * 100);

    int maxSold = sold[0], minSold = sold[0];
    int maxID = 1, minID = 1;

    for (i = 1; i < count; i++) {
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

    return 0;
}
