#include <stdio.h>
#include <stdlib.h>

void generate_odd_magic_square(int n, int square[n][n]) {
    int i = 0, j = n / 2, num;
    for (num = 1; num <= n * n; num++) {
        square[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (square[newi][newj])
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }
}

void generate_4n_magic_square(int n, int square[n][n]) {
    int i, j;
    int num = 1;
    int rev = n * n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ( (i % 4 == j % 4) || ((i + j) % 4 == 3) )
                square[i][j] = rev;
            else
                square[i][j] = num;
            num++;
            rev--;
        }
    }
}

void print_square(int n, int square[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", square[i][j]);
        printf("\n");
    }
}

int verify_magic_square(int n, int square[n][n]) {
    int magic_sum = n * (n * n + 1) / 2;
    int sum;

    for (int i = 0; i < n; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += square[i][j];
            col_sum += square[j][i];
        }
        if (row_sum != magic_sum || col_sum != magic_sum)
            return 0;
    }

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += square[i][i];
    if (sum != magic_sum)
        return 0;

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += square[i][n - 1 - i];
    if (sum != magic_sum)
        return 0;

    return 1;
}

int main() {
    int n;
    printf("홀수 또는 4의 배수인 마방진의 크기를 입력하세요: ");
    scanf("%d", &n);

    if ((n % 2 != 1) && (n % 4 != 0)) {
        printf("홀수 또는 4의 배수만 입력 가능합니다.\n");
        return 1;
    }

    int square[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;

    if (n % 2 == 1)
        generate_odd_magic_square(n, square);
    else
        generate_4n_magic_square(n, square);

    printf("\n생성된 마방진:\n");
    print_square(n, square);

    if (verify_magic_square(n, square))
        printf("\n검증 결과: 모든 행, 열, 대각선의 합이 %d로 일치합니다. 마방진이 정상적으로 생성되었습니다!\n", n * (n * n + 1) / 2);
    else
        printf("\n검증 실패: 마방진이 올바르지 않습니다.\n");

    return 0;
}
