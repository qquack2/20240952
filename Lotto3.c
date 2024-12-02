#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto {
	int number[6];
	int bonus;
	int NO;
}LOTTO;

void initLotto(LOTTO* l) {
	for (int i = 0; i < 6; i++) l->number[i] = 0;
	l->bonus = 0;
	l->NO = 0;
}

int dup(LOTTO l, int num, int n) {
	for (int i = 0; i <= n; i++) {
		if (l.number[i] == num)	return 1;
	}
	return 0;
}

LOTTO createAuto(int NO) {
	LOTTO l;
	int num;
	initLotto(&l);
	l.NO = NO;
	for (int i = 0; i < 6; i++) {
		num = rand() % 45 + 1;
		if (i == 0)		l.number[i] = num;
		else if (i > 0 && !dup(l, num, i - 1)) l.number[i] = num;
		else
		{
			i--;
			printf("중복발생.. 다시 뽑으세요..\n");
		}
	}
	return l;
}

LOTTO createMaual(int NO) {
	LOTTO l;
	int num;
	initLotto(&l);
	l.NO = NO;
	for (int i = 0; i < 6; i++) {
		printf("input number #%d : ", i + 1);
		scanf("%d", &num);
		if (i == 0)		l.number[i] = num;
		else if (i > 0 && !dup(l, num, i - 1)) l.number[i] = num;
		else
		{
			i--;
			printf("중복발생.. 다시 뽑으세요..\n");
		}
	}
	return l;
}

void printLotto(LOTTO l) {
	printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", l.NO,
		l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]);
	printf("BOUNS : %d\n", l.bonus);
}

LOTTO drawingLotto() {
	LOTTO l;
	int num;
	initLotto(&l);
	for (int i = 0; i < 6; i++) {
		num = rand() % 45 + 1;
		if (i == 0)		l.number[i] = num;
		else if (i > 0 && !dup(l, num, i - 1)) l.number[i] = num;
		else
		{
			i--;
		}
	}
	do {
		l.bonus = num = rand() % 45 + 1;

	} while (dup(l, l.bonus, 5));

	return l;
}

int matchCount(LOTTO l, LOTTO l2) {
	int mcount = 0;
	for (int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++){
			if (l.number[i] == l2.number[j]) mcount++;
		}
		return mcount;
	}
}

void saveLottoToFile(LOTTO l, const char* filename) {
	FILE* fp = fopen("20240952.bin", "wb");
	if (fp == NULL) {
		printf("파일 저장 실패\n");
		exit(1);
	}
	fwrite(&l, sizeof(LOTTO), 1, fp);
	fclose(fp);
	printf("로또 번호가 파일 %s 에 저장되었습니다.\n", filename);
}

int main()
{
	LOTTO l, l2;

	srand(time(NULL));
	l = createAuto(20240952);
	saveLottoToFile(l, "20240952.bin");
	printLotto(l);

	return 0;
}