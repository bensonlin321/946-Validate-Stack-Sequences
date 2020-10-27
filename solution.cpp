#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>
#include <iterator>     // std::distance
#include <list>         // std::list
#include <map>
#include <stack>

// implement a solution with a linear runtime complexity and without using extra memory
class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> tmp_stack;
        int pop_idx = 0;
        for(int i = 0 ; i < pushed.size() ; i++) {
            printf("push: %d\n", pushed[i]);
            tmp_stack.push(pushed[i]);

            while(pop_idx < popped.size() && !tmp_stack.empty() && tmp_stack.top() == popped[pop_idx]) {
                printf("pop: %d\n", tmp_stack.top());
                tmp_stack.pop();
                pop_idx++;
            }
        }
        return pop_idx == pushed.size();
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> nums1{1,0};
    std::vector<int> nums2{1,0};
    printf("output:%d\n", s -> validateStackSequences(nums1, nums2));
}
