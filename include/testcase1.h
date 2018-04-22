/*************************************************************************
	> File Name: testcase1.h
	> Author: muhuilin
	> Mail: muhuilin@outlook.com 
	> Created Time: 2017年12月09日 星期六 16时15分38秒
 ************************************************************************/

#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include"htset.h"
#include "unit.h"
/* 
 TEST(unit, newton_sqrt) {
     for(int i = -100; i < 100; i++) {

         double x = newton_sqrt(i);
         if(i <= 0){
             EXPECT_GT(EPSLON, x + 1);
             continue;
         }
        EXPECT_GT(EPSLON,x * x - i);
     }
 }
*/
TEST(unit, orla6) {
     for(int i = -100; i < 500; i++) {
        int  ans1 = ca(i);
        int t;
        int x = i;
        if(x > 100 || x < 0) {
            EXPECT_EQ(ans1,-1);
             continue;
        }
        int sum1 = (1 + x) * x / 2, sum2 = 0;
        for(int j = 1; j <= x; j++) {
            sum2 += (j * j);
        }
        t =  sum1 * sum1 - sum2;
       // printf("%d %d\n",i,ans1);
        EXPECT_EQ(ans1, t);
    } 

 }
#endif

