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
    printf("��ǰ �� �԰���� �Է� \n");
    for (int i = 0; i < count; i++) {
        printf("��ǰ ID %d: ", i + 1);
        scanf("%d", &count);
        initialStock[i] = stock[i];
        sold[i] = 0;
        initialTotal += stock[i];
    }
}

void sTotal() {
    int soldInput;
    printf("��ǰ �� �Ǹż��� �Է� \n");
    for (int i = 0; i < count; i++) {
        printf("%s�� �Ǹ� ����: ", productNames[i]);
        scanf("%d", &soldInput);
        if (soldInput <= stock[i]) {
            stock[i] -= soldInput;
            sold[i] += soldInput;
            soldTotal += soldInput;
        }
        else {
            printf("�Ǹ� ������ ����� �����ϴ�. �ִ� �Ǹ� ���� ����: %d\n", stock[i]);
        }
    }
}

void allTotal() {
    printf("������: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n�� �Ǹŷ�: %d (�Ǹ���: %.2f%%)\n", soldTotal, ((double)soldTotal / initialTotal) * 100);

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

    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxID, maxSold);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minID, minSold);

    for (int i = 0; i < count; i++) {
        if (stock[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, stock[i]);
        }
    }
}

void inputName()
{
    printf("��ǰ���� �Է��ϼ���:\n");
    for (int i = 0; i < count; i++) {
        printf("ID %d ��ǰ��: ", i + 1);
        scanf("%s", &productNames[i]);
    }
}

int main() {
    int choice;
    
    if (count > 1 || count < 100) {
        printf("��ǰ������ �Է��ϼ���(1~100): ");
        scanf("%d", &count);
    }
    else {
        printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է� ���ּ���(1~100)");
    }
    do {
        printf("[���θ� ���� ���α׷�]\n");
        printf("1.�԰� 2.�Ǹ� 3.��ǰ��Ȳ 4.��ǰ�� �Է� 5����\n");
        printf("���ϴ� �޴��� �����ϼ���: ");
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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
        }
    } while (1);

    return 0;
}
