class Solution {
public:
    double angleClock(int hr, int m) {
        
        double Am=(double)m*6;
        double th;
        if(hr!=12){
        th=hr + (double)m/60;
        }
        else
        th=(double)m/60;
        
        double Ah=(double)th*30;
        
        
        if((th<=6 && m<=30) || (th>=6 && m>=30))
        return abs(Ah-Am);
        else 
        {
            return min(abs(Ah-Am),(360-abs(Ah-Am)));
        }
    }
};