class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(h);
        vc.push_back(w);
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        long long int hr = hc[0] - 0;
        long long int vr = vc[0] - 0;
        
        for(int i=1;i<hc.size();i++)
        {
            if(hr < hc[i] - hc[i-1])
                hr = hc[i] - hc[i-1];
        }

        for(int i=1;i<vc.size();i++)
        {
            if(vr < vc[i] - vc[i-1])
                vr = vc[i] - vc[i-1];
        }
        
        return (hr * vr) % 1000000007;
    }
};