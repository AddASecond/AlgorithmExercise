#include"iostream"
#include"vector"
using namespace std;

class LongestDistance {
public:
	int getDis(vector<int> A, int n) {
		// write code here
		// To save the max difference of A[b]-A[a] while 0¡Üa¡Üb<n
		int MaxDiff = 0;
		// Do only when n>0
		if (n>0) {
			int min = A[0];	// Set min value equals to A[0] at beginning
			for (int i = 0; i<n; i++) {	// Do traversal 
				if (A[i] - min>MaxDiff) {	// Update the MaxDiff
					MaxDiff = A[i] - min;
				}
				if (A[i]<min) {	// Update the min value
					min = A[i];
				}
			}	// End of for loop
		}	// End of if
		return MaxDiff;	// return the Max difference 
	}
};

int main() {
	cout<< "Please input a sequence of numbers, seperated by Spaces, press Enter to end!" << endl;
	vector<int> A_test;	// vector to save sequence
	int input;	// an int to temporary save value
	char c;	// a char to temporary save value
	while ((cin>>input).get(c)) // A litte tricky: use get in order to obtain "Enter"('\n') to end a line
	{
		A_test.push_back(input);
		if (c == '\n') { break; }	// Notice that this line should after push back
	}
	int A_length = A_test.size();
	LongestDistance A_Class;
	int A_MaxDiff = A_Class.getDis(A_test, A_length);
	cout << "The length of A is:\n" << A_length << endl;
	cout << "The MaxDiff of A[b]-A[a] while 0¡Üa¡Üb<n is£º\n" << A_MaxDiff << "!" << endl;
	system("pause");
}