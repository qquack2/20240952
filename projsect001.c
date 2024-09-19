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
        printf("��ǰ ����(����)�Է� (1 ~ 100): ");
        scanf("%d", &count);
    } while (count < 1 || count > 100);

    printf("��ǰ �� �԰���� �Է�: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
        initiaTotal += stock[i];
    }

    printf("��ǰ �� �Ǹż����� �Է�: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &sold);
        if (sold <= stock[i]) {
            stock[i] -= sold;
            soldTotal += sold;
        }
        else {
            printf("�Ǹ� ������ ����� ����. �ִ� �Ǹ� ���� ����: %d\n", stock[i]);
        }
    }

    while (1) {
        printf("��� ������ Ȯ���� ��ǰ ID�� �Է� (1 ~ %d, ����� 0): ", count);
        scanf("%d", &id);

        if (id == 0) {
            break;
        }
        else if (id > 0 && id <= count) {
            printf("���� ��� ���� : ");
            for (i = 0; i < count; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n");
        }
        else {
            printf("�߸��� ID�Դϴ�. �ٽ� �Է�\n");
        }
    }
    printf("�� �Ǹŷ� %d (�Ǹ��� %.2f%%) ",soldTotal, ((double)soldTotal / initiaTotal) * 100);
    



    return 0;
}