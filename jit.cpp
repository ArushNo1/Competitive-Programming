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
        
    }
};



