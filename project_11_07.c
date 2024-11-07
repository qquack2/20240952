#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILE_NAME "product_data.txt"

typedef struct {
    int id;
    char name[50];
    int stock;
    int sold;
    int price;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;


void saveProductInfo() {
    FILE* file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("파일 저장에 실패했습니다.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %d %d %d\n", products[i].id, products[i].name, products[i].stock, products[i].sold, products[i].price);
    }
    fclose(file);
    printf("상품 정보가 저장되었습니다.\n");
}


void loadProductInfo() {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("파일 로드에 실패했습니다.\n");
        return;
    }
    productCount = 0;
    while (fscanf(file, "%d %s %d %d %d", &products[productCount].id, products[productCount].name, &products[productCount].stock, &products[productCount].sold, &products[productCount].price) == 5) {
        productCount++;
    }
    fclose(file);
    printf("상품 정보가 로드되었습니다.\n");
}


void resetProductList() {
    productCount = 0;
    printf("모든 상품 정보가 초기화되었습니다.\n");
}


void addStock() {
    if (productCount >= MAX_PRODUCTS) {
        printf("상품 개수 초과입니다. 최대 %d개의 상품만 등록할 수 있습니다.\n", MAX_PRODUCTS);
        return;
    }
    Product p;
    printf("상품 ID: ");
    scanf("%d", &p.id);
    printf("상품명: ");
    scanf("%s", p.name);
    printf("입고 수량: ");
    scanf("%d", &p.stock);
    printf("판매 가격: ");
    scanf("%d", &p.price);
    p.sold = 0;

    products[productCount++] = p;
    printf("상품이 입고되었습니다.\n");
}


void sellProduct() {
    int id, sellAmount;
    printf("판매할 상품 ID: ");
    scanf("%d", &id);
    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("해당 상품이 없습니다.\n");
        return;
    }
    printf("판매 수량: ");
    scanf("%d", &sellAmount);
    if (sellAmount > products[found].stock) {
        printf("재고가 부족합니다. 최대 %d개까지 판매 가능합니다.\n", products[found].stock);
    }
    else {
        products[found].stock -= sellAmount;
        products[found].sold += sellAmount;
        printf("판매가 완료되었습니다.\n");
    }
}


void showProductStatus() {
    int id;
    printf("확인할 상품 ID: ");
    scanf("%d", &id);
    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("해당 상품이 없습니다.\n");
        return;
    }
    printf("상품명: %s\n재고 수량: %d\n판매 가격: %d\n판매 수량: %d\n", products[found].name, products[found].stock, products[found].price, products[found].sold);
}


void showAllStatus() {
    printf("전체 상품 현황:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | 상품명: %s | 재고 수량: %d | 판매 가격: %d | 판매 수량: %d\n",
            products[i].id, products[i].name, products[i].stock, products[i].price, products[i].sold);
    }
}


int main() {
    int choice;
    loadProductInfo();

    do {
        printf("\n[쇼핑몰 재고 관리 시스템]\n");
        printf("1. 입고  2. 판매  3. 개별 현황  4. 전체 현황  5. 초기화 6. 저장 및 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStock();
            break;
        case 2:
            sellProduct();
            break;
        case 3:
            showProductStatus();
            break;
        case 4:
            showAllStatus();
            break;
        case 5:
            resetProductList();
            break;
        case 6:
            saveProductInfo();
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    } while (1);

    return 0;
}
