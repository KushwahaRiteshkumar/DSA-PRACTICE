#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        int direction = 0;

        while (left <= right && top <= bottom) {
            if (direction == 0) { // left → right
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            } 
            else if (direction == 1) { // top → bottom
                for (int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            } 
            else if (direction == 2) { // right → left
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            } 
            else if (direction == 3) { // bottom → top
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return result;
    }
};
