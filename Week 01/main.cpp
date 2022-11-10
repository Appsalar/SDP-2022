// Задачата е https://leetcode.com/problems/product-of-array-except-self/
// Като първа част може да се изполва делене.
// Решението без делене е много добре обяснено в дискусията за задачата:
// https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach

#include <iostream>
#include <vector>

using namespace std;


// При решението с делене идеята е да намерим произведението на всички числа
// в масива и да делим, за да получим числата в новия масив. Като трябва да
// се внимава, ако има нули в масива. 
vector<int> productWithoutSelf(const vector<int> &arr) {
	vector<int> result(arr.size(), 0);

	int product = 1;
	int zeroCount = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == 0) {
			zeroCount += 1;
		}
		else
			product *= arr[i];

		if (zeroCount > 1) {
			return result;
		}
	}

	for (int i = 0; i < arr.size(); ++i) {
		if (zeroCount) {
			result[i] = arr[i] ? 0 : product;
		}
		else {
			result[i] = product / arr[i];
		}
	}

	return result;
}


// Удобно е да има отделна функция, която да се грижи за принтирането
// на масива, за да може по-лесно да се проверява резултата. 
void executeAndPrint(const vector<int>& arr) {
	auto result = productWithoutSelf(arr);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	cout << endl;
}


int main() {
	vector<int> arr = { 1, 2, 3, 4 };
	executeAndPrint(arr);
	arr = { -1,1,0,-3,3 };
	executeAndPrint(arr);

}