class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int i=0,j=0;
       int n=nums1.size();
       int m=nums2.size();
       vector<int>arr;
       while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            arr.push_back(nums1[i]);
            i++;
        }
        else if(nums2[j]<nums1[i]){
            arr.push_back(nums2[j]);
            j++;
        }
        else {
            arr.push_back(nums1[i]);
            arr.push_back(nums2[j]);
            i++;
            j++;
        }
       }
       while(i<n){
        arr.push_back(nums1[i]);
        i++;
       }
       while(j<m){
        arr.push_back(nums2[j]);
        j++;
       }
       int k=arr.size();
       if(arr.size()%2==1)return arr[k/2];
       return ((long long)arr[k / 2 - 1] + arr[k / 2]) / 2.0;
    }
};