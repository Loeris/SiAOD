#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string uint_to_bit(unsigned int n){
    string str = "";
    for (unsigned int i = 0, mask = 1 << (8 * sizeof(n) - 1); i < 8 * sizeof(n); i++, mask = mask >> 1){
        if (n & mask)
            str += "1";
        else
            str += "0";
    }
    return str;
}

void Task1(int exercise){
    if (exercise == 1){
        unsigned int n = 0x00000000;

        cout << "1) Task: Turn 9th, 10th, 11th and 12th bits into 1";
        cout << "\nInitial number:" << n << endl << uint_to_bit(n) << endl;
        n = n | 0x00000F00;
        cout << "Modified number:" << n << endl << uint_to_bit(n) << endl;

        cout << "\n2) Task: Turn 17th, 15th and 1st bits into 0";
        cout << "\nEnter number:";
        cin >> n;
        cout << "Initial number:" << n << endl << uint_to_bit(n) << endl;
        n = n & 0x111E711E;
        cout << "Modified number:" << n << endl << uint_to_bit(n) << endl;

        cout << "\n3) Task: Multiply by 1024";
        cout << "\nEnter number:";
        cin >> n;
        cout << "Initial number:" << n << endl << uint_to_bit(n) << endl;
        n = n<<10;
        cout << "Modified number:" << n << endl << uint_to_bit(n) << endl;

        cout << "\n4) Task: Divide by 1024";
        cout << "\nEnter number:";
        cin >> n;
        cout << "Initial number:" << n << endl << uint_to_bit(n) << endl;
        n = n>>10;
        cout << "Modified number:" << n << endl << uint_to_bit(n) << endl;

        cout << "\n5) Task: Turn n-th bit into 0";
        cout << "\nEnter number:";
        cin >> n;
        cout << "Initial number:" << n << endl << uint_to_bit(n) << endl;
        cout << "Enter n-th bit, that should be nullified:";
        int k;
        cin >> k;
        cout << "Initial number:" << n << endl << uint_to_bit(n) << endl;
        n = n & (~((0x00000001)<<(k-1)));
        cout << "Modified number:" << n << endl << uint_to_bit(n) << endl;
    }
    if (exercise == 2){
        int N0_7 = 312500, N7 = 281250;
        int A = N7;
        int offsett = 1000000;
        unsigned int array[A];
        for (int i = 0; i < A; i++)
            array[i] = 0;
        cout << "Enter amount of numbers:";
        int N, n;
        cin >> N;
        //N = 1000;
        for (int i = 1; i <= N; i++) {
            cout << "Enter number " << i << ":";
            cin >> n;
            //n = rand() % A + 1000000;
            n -= offsett;
            array[n / 32] = array[n / 32] | (1<<(n % 32));
        }
        cout << "\nBits inside array:" << endl;
        for (int i = 0; i < A; i++) {
            if (array[i] != 0) {
                string s = uint_to_bit(array[i]);
                reverse(s.begin(), s.end());
                cout << s << " - Cell " << i << endl;
            }
        }
        int time = clock();
        cout << "\nSorted array:" << endl;
        for (int i = 0; i < A; i++){
            for (unsigned int j = 0, mask = 1; j < 32; j++, mask=mask<<1){
                if ((array[i] & mask) != 0)
                    cout << offsett + i * 32 + j << endl;
            }
        }
        cout << "Execution time:" << clock() - time << " ms";
    }
}


int main() {
    cout << "Input task:";
    int exercise;
    cin >> exercise;
    int task = 1;
    if (task == 1)
        Task1(exercise);
    return 0;
}
