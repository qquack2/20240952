#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 100

int main()
{
    int count;
    int stock[MAX_PRODUCTS];
    int id, sold, i;
    int soldTotal = 0, initiaTotal = 0;

    do {
        printf("상품 개수(종류)입력 (1 ~ 100): ");
        scanf("%d", &count);
    } while (count < 1 || count > 100);

    printf("상품 별 입고수량 입력: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
        initiaTotal += stock[i];
    }

    printf("상품 별 판매수량을 입력: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &sold);
        if (sold <= stock[i]) {
            stock[i] -= sold;
            soldTotal += sold;
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
    printf("총 판매량 %d (판매율 %.2f%%) ",soldTotal, ((double)soldTotal / initiaTotal) * 100);
    



    return 0;
}