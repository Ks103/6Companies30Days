class Solution {
public:
     long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums(size(nums1));
        for (int i = 0; i < size(nums); ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        int64_t result = 0;
        const function<void (int, int)> merge_sort = [&](int left, int right) {
            if (left == right) {
                return;
            }
            const int mid = left + (right - left) / 2;
            merge_sort(left, mid);
            merge_sort(mid + 1, right);
            for (int l = left, r = mid + 1; l < mid + 1; ++l) {
                for (; r < right + 1 && nums[l] - nums[r] > diff; ++r);
                result += right - r + 1;
            }
            vector<int> tmp;
            for (int l = left, r = mid + 1; l < mid + 1 || r < right + 1;) {
                if (r >= right + 1 || (l < mid + 1 && nums[l] <= nums[r])) {
                    tmp.emplace_back(nums[l++]);
                } else {
                    tmp.emplace_back(nums[r++]);
                }
            }
            for (int i = 0; i < size(tmp); ++i) {
                nums[left + i] = tmp[i];
            }
        };
        merge_sort(0, size(nums) - 1);
        return result;
    }
};