class Solution {

private:
    void merge(vector<int>&arr, int n, int start, int mid, int end)
    {
        int n1 = mid - start + 1;
        int n2 = end - mid;

        int arr1[n1];
        int arr2[n2];

        for (int i = 0; i < n1; i++)
            arr1[i] = arr[start + i];

        for (int i = 0; i < n2; i++)
            arr2[i] = arr[mid + 1 + i];

        int i = 0, j = 0, idx = start;

        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                arr[idx] = arr1[i];
                i++;
                idx++;
            }

            else
            {
                arr[idx] = arr2[j];
                j++;
                idx++;
            }
        }

        while (i < n1)
        {
            arr[idx] = arr1[i];
            i++;
            idx++;
        }

        while (j < n2)
        {
            arr[idx] = arr2[j];
            j++;
            idx++;
        }
    }

    void mergeSort(vector<int>&arr, int n, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(arr, n, start, mid);
            mergeSort(arr, n, mid + 1, end);

            merge(arr, n, start, mid, end);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, nums.size(), 0, nums.size() - 1);
        return  nums;
    }
};