#include <functional>
namespace searching{
    template<typename T>
    T firstTrue(T low, T high, std::function<bool(T)> f){
        while(low < high){
            T mid = low + (high - low) / 2;
            if(f(mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    template<typename T>
    T lastTrue(T low, T high, std::function<bool(T)> f){
        while(low < high){
            T mid = low + (high - low + 1) / 2;
            if(f(mid)){
                low = mid;
            }
            else{
                high = mid + 1;
            }
        }
        return low;
    }
    template<typename T>
    T ternaryFirstTrue(T low, T high, std::function<bool(T, T)> f){
        //G1 problem file
        /*
        ll l = 1, r = 1000;
    while(r - l > 2){
        ll m1 = (2 * l + r) / 3, m2 = (2 * r + l) / 3;
        ll mm = m1 * m2;
        cout << "? " << m1 << " " << m2 << endl;
        ll t;
        cin >> t;
        if(t == mm){
            l = m2;
            //cout << "d > m2" << endl;
        }
        else if(t == mm + m1){
            l = m1;
            r = m2;
            //cout << "m1 < d2 <= m2" << endl;
        }
        else{
            r = m1;
            //cout << "d2 <= m1" << endl;
        }
    }
    if(r - l == 2){
        cout << "? 1 " << l + 1 << endl;
        int t;
        cin >> t;
        if(t != l + 1){
            r = l + 1;
        }
    }
    cout << "! " << r << endl;
        */
    }
};



