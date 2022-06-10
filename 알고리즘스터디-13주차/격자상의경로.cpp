#include <iostream>
using namespace std;
typedef long long ll;

//���� 10164 ���ڻ��� �ݷ�
/*��ü �̵��Ҽ� �ִ� ��� - 0�� ���ļ� �̵��ϴ� ��츦 ���ֱ�*/

int main(void) {
    ll arr[20][20];
    ll dp[20][20];

    int number = 1;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) { //1���� ������� ��ȣ �ű��
        for (int j = 1; j <= m; j++) {
            arr[i][j] = number;
            number++;
            dp[i][j] = 1;
        }
    }



    for (int i = 1; i <= n; i++) { //n*m��η� ���� ��� ����� �� 
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        }
    }

    ll cur_dp_count = dp[n][m]; //��ü ����� ��
    ll zero_dp = 0;//0�� x,y��ǥ�� 0�� ���ļ� ���� ���
    int x = 0;
    int y = 0;

    bool is_find = false; //n*m���� 0�� ã���� true��
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            if (arr[i][j] == k) { //ã���� �ش� xy�� 0���� �ٲٰ� ��ǥ ���� + ���� Ż��
                is_find = true;
                dp[i][j] = 0;
                x = i;
                y = j;
                break;
            }
        }
        if (is_find == true) {
            break;
        }
    }

    for (int i = x; i <= n; i++) { //0���� n*m���� ���� ��� ���ϱ�
        for (int j = y; j <= m; j++) {
            if (i == x && j == y) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }


    zero_dp = dp[n][m]; //���� ���ϱ�
    if (cur_dp_count == zero_dp) {
        cout << dp[n][m];
        return 0;
    }
    else {
        cout << cur_dp_count - zero_dp;
        return 0;
    }


}