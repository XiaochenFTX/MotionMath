//
//  main.cpp
//  UniformlyAcceleratedMotion
//
//  Created by 王晓辰 on 15/7/25.
//  Copyright (c) 2015年 ftxtool. All rights reserved.
//

#include <iostream>

//S = V0 * t + 0.5 * a * t * t
//Vt = V0 + a * t
//Vt * Vt - V0 * V0 = 2 * a * S

// 基于Vt=0 的情况

//a = 0 - V0 / t

//S - V0 * t = 0.5 * a * t * t
//2 * (S - V0 * t) / (t * t) = a = - V0 / t
//V0 = 2 * S / t

//a = - 2 * S / t / t

double v0_ByST(double S, double T)
{
    return 2 * S / T;
}

double a_ByST(double S, double T)
{
    return 0 - 2 * S / (T * T);
}

double deltaS_BySTdt(double total_S, double total_T, double delta_t)
{
    return v0_ByST(total_S, total_T) * delta_t + 0.5 * a_ByST(total_S, total_T) * delta_t * delta_t;
}


int main(int argc, const char * argv[]) {

    double S = 3010;
//    double T = 0.5;
    
    double Ts[10] = {0.1, 0.3, 0.5, 0.7, 1, 2, 3, 3.5, 3.7, 4};
    
    for (auto T : Ts)
    {
        std::cout<<"a:"<<a_ByST(S, T)<<std::endl;
        std::cout<<"V0:"<<v0_ByST(S, T)<<std::endl;
        for (int i = 1; i <= 10; ++i)
        {
            double t = T / 10 * i;
            std::cout<<"dS:"<<deltaS_BySTdt(S, T, t)<<std::endl;
        }
        std::cout<<"==============================="<<std::endl;
    }
    
    
    
    return 0;
}
