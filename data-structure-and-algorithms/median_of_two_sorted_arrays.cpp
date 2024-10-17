#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int m = a.size();
        int n = b.size();
        if (m > n)
        {
            return findMedianSortedArrays(b, a);
        }
        int low = 0;
        int high = m;
        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int right1 = cut1 == m ? INT_MAX : a[cut1];
            int right2 = cut2 == n ? INT_MAX : b[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else
                {
                    return max(left1, left2);
                }
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test case 1: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test case 2: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Test case 3: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {1};
    cout << "Test case 4: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {2};
    nums2 = {};
    cout << "Test case 5: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}