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
        printf("���� ���忡 �����߽��ϴ�.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %d %d %d\n", products[i].id, products[i].name, products[i].stock, products[i].sold, products[i].price);
    }
    fclose(file);
    printf("��ǰ ������ ����Ǿ����ϴ�.\n");
}


void loadProductInfo() {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("���� �ε忡 �����߽��ϴ�.\n");
        return;
    }
    productCount = 0;
    while (fscanf(file, "%d %s %d %d %d", &products[productCount].id, products[productCount].name, &products[productCount].stock, &products[productCount].sold, &products[productCount].price) == 5) {
        productCount++;
    }
    fclose(file);
    printf("��ǰ ������ �ε�Ǿ����ϴ�.\n");
}


void resetProductList() {
    productCount = 0;
    printf("��� ��ǰ ������ �ʱ�ȭ�Ǿ����ϴ�.\n");
}


void addStock() {
    if (productCount >= MAX_PRODUCTS) {
        printf("��ǰ ���� �ʰ��Դϴ�. �ִ� %d���� ��ǰ�� ����� �� �ֽ��ϴ�.\n", MAX_PRODUCTS);
        return;
    }
    Product p;
    printf("��ǰ ID: ");
    scanf("%d", &p.id);
    printf("��ǰ��: ");
    scanf("%s", p.name);
    printf("�԰� ����: ");
    scanf("%d", &p.stock);
    printf("�Ǹ� ����: ");
    scanf("%d", &p.price);
    p.sold = 0;

    products[productCount++] = p;
    printf("��ǰ�� �԰�Ǿ����ϴ�.\n");
}


void sellProduct() {
    int id, sellAmount;
    printf("�Ǹ��� ��ǰ ID: ");
    scanf("%d", &id);
    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("�ش� ��ǰ�� �����ϴ�.\n");
        return;
    }
    printf("�Ǹ� ����: ");
    scanf("%d", &sellAmount);
    if (sellAmount > products[found].stock) {
        printf("��� �����մϴ�. �ִ� %d������ �Ǹ� �����մϴ�.\n", products[found].stock);
    }
    else {
        products[found].stock -= sellAmount;
        products[found].sold += sellAmount;
        printf("�ǸŰ� �Ϸ�Ǿ����ϴ�.\n");
    }
}


void showProductStatus() {
    int id;
    printf("Ȯ���� ��ǰ ID: ");
    scanf("%d", &id);
    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("�ش� ��ǰ�� �����ϴ�.\n");
        return;
    }
    printf("��ǰ��: %s\n��� ����: %d\n�Ǹ� ����: %d\n�Ǹ� ����: %d\n", products[found].name, products[found].stock, products[found].price, products[found].sold);
}


void showAllStatus() {
    printf("��ü ��ǰ ��Ȳ:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | ��ǰ��: %s | ��� ����: %d | �Ǹ� ����: %d | �Ǹ� ����: %d\n",
            products[i].id, products[i].name, products[i].stock, products[i].price, products[i].sold);
    }
}


int main() {
    int choice;
    loadProductInfo();

    do {
        printf("\n[���θ� ��� ���� �ý���]\n");
        printf("1. �԰�  2. �Ǹ�  3. ���� ��Ȳ  4. ��ü ��Ȳ  5. �ʱ�ȭ 6. ���� �� ����\n");
        printf("����: ");
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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    } while (1);

    return 0;
}
