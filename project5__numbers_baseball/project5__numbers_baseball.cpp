#include <iostream>
#include <ctime>
#include <vector>


using namespace std;

int main()
{
    cout << "야구 게임" << endl;
    int count = 0;

    vector<int> random_num;

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        int num = rand() % 9 + 1;
        bool overlap_num = false;

        for (int j = 0; j < i; j++) {
            if (random_num[j] == num) {
                overlap_num = true;
                i--;
            }
        }
        if (!overlap_num) {
            random_num.push_back(num);
        }
    }

    while (1) {
        int num_1, num_2, num_3;
        int strike, ball = 0;

        cout << "1 ~ 9 사이의 숫자 3개를 입력하시오. (이외의 숫자 종료)" << endl;
        cin >> num_1 >> num_2 >> num_3;

        count++;

        if (num_1 > 9 || num_1 < 0 || num_2 > 9 || num_2 < 0 || num_3 > 9 || num_3 < 0) {
            cout << "게임을 종료하였습니다.";
            break;
        }
        else if (num_1 == num_2 || num_1 == num_2 || num_2 == num_3) {
            cout << "중복된 숫자가 있습니다. 다시 입력해주세요." << endl;
        }
        else {
            strike = 0;
            ball = 0;

            if (num_1 == random_num[0]) {
                strike++;
            }
            else if (num_1 == random_num[1] || num_1 == random_num[2]) {
                ball++;
            }

            if (num_2 == random_num[1]) {
                strike++;
            }
            else if (num_2 == random_num[0] || num_2 == random_num[2]) {
                ball++;
            }

            if (num_3 == random_num[2]) {
                strike++;
            }
            else if (num_3 == random_num[0] || num_3 == random_num[1]) {
                ball++;
            }

            cout << "Strike : " << strike << "                ball : " << ball << endl;

            if (strike == 3) {
                cout << "정답입니다." << count << "번만에 맞췄습니다! 게임종료!";
                break;
            }
        }
    }
}
