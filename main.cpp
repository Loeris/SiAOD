#include <iostream>
#include <cmath>
using namespace std;

void Task1(int exercise){
    if (exercise == 1){
        int n = 0x7FFFFFF;
        cout << "1) Initial number:" << n << endl;
        cout << "Modified number(9th, 10th, 11th and 12th bits turned into 1):" << (n | 0x00000F00) << endl;

        cout << "2) Initial number:";
        cin >> n;
        cout << "Modified number(17th, 15th and 1st bits nullified):" << (n & 0x111E711E) << endl;

        cout << "3) Initial number:";
        cin >> n;
        cout << "Modified number(multiplied by 1024):" << (n<<10) << endl;

        cout << "4) Initial number:";
        cin >> n;
        cout << "Modified number(divided by 1024):" << (n>>10) << endl;

        cout << "5) Initial number:";
        cin >> n;
        cout << "n-th bit that should be nullified:";
        int k;
        cin >> k;
        cout << "Modified number("<< k << "th bit nullified): " << (n & (~((0x00000001)<<(k-1)))) << endl;
    }
    if (exercise == 2){
        int N0_7 = 312500, N7 = 281250;
        int A = N7;
        int offsett = 1000000;
        unsigned int array[A];
        for (int i = 0; i < A; i++)
            array[i] = 0;
        cout << "Amount of numbers:";
        int N, n;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cout << "Number " << i << ":";
            cin >> n;
            n -= offsett;
            array[n / 32] = array[n / 32] | (1<<(n % 32));
        }
        for (int i = 0; i < A; i++){
            for (unsigned int j = 0, mask = 1; j < 32; j++, mask=mask<<1){
                if ((array[i] & mask) != 0)
                    cout << offsett + i * 32 + j << endl;
            }
        }
    }
}

void Run(int task, int exercise){
    if (task == 1)
        Task1(exercise);
}

int main() {
    // cout << "Input task: ";
    int exercise;
    // cin >> exercise;
    int task = 1;
    exercise = 2;
    Run(task, exercise);
    return 0;
}
