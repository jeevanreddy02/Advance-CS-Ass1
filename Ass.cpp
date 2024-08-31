#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& numbers, int desiredSum) {
        unordered_map<int, int> indexMap;
        for (int i = 0;; ++i) {
            int currentNum = numbers[i];
            int difference = desiredSum - currentNum;
            if (indexMap.find(difference) != indexMap.end()) {
                return {indexMap[difference], i};
            }
            indexMap[currentNum] = i;
        }
    }
};

int main() {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int desiredSum = 9;
    vector<int> result = solution.findIndices(numbers, desiredSum);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
