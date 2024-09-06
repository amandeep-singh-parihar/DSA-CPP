class NumArray {
public:
    int prefixSum[10000];

    NumArray(vector<int>& nums) {
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return prefixSum[right];
        } else {
            return prefixSum[right] - prefixSum[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
