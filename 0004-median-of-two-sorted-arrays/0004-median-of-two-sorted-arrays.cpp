class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
            swap(nums1,nums2);
        int n=nums1.size(),m=nums2.size(),l=0,r=m*2;
        while(l<=r){
            int m2=(l+r)/2,m1=n+m-m2;
            double l1=(!m1)?INT_MIN:nums1[(m1-1)/2];
            double l2=(!m2)?INT_MIN:nums2[(m2-1)/2];
            double r1=(m1==2*n)?INT_MAX:nums1[m1/2];
            double r2=(m2==2*m)?INT_MAX:nums2[m2/2];
            if(l1>r2)
                l=m2+1;
            else if(l2>r1)
                r=m2-1;
            else
                return (max(l1,l2)+min(r1,r2))/2;
        }
        return -1;
    }
};