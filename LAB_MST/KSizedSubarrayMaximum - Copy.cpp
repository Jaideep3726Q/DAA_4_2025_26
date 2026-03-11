
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ma;

        if(k == 1) return arr;

        for(int i = 0; i <= arr.size() - k; i++) {
            int h = arr[i];
            
            for(int j = 0; j < k; j++) {
                if(arr[i + j] > h) {
                    h = arr[i + j];
                }
            }

            ma.push_back(h);
        }

        return ma;
    }
};
