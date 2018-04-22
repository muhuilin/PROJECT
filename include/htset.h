#ifndef _HTSET_H
#define _HTSET_H

typedef struct TEST_INFO {
    int testNum;
    int YesNum;
    int NoNum;
    int flag;
}TEST_INFO;

#define TEST(a, b) \
        void test##_##a##_##b(TEST_INFO *__ti);\
        int p##_##a##_##b = test_run(test##_##a##_##b, #a, #b);\
        void test##_##a##_##b(TEST_INFO *__ti)

#define EXPECT_GT(a,b) {\
                        if((a) > (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}+
#define EXPECT_LT(a,b) {\
                        if((a) < (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}
#define EXPECT_GE(a,b){\
                        if((a) >= (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}
#define EXPECT_LE(a,b) {\
                        if((a) <= (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}
#define EXPECT_NE(a,b){\
                        if((a) != (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}
#define EXPECT_EQ(a,b){\
                        if((a) == (b)){\
                            __ti->YesNum++;\
                        }\
                        else{\
                             printf("x = %d %d\n",(a),(b));\
                            __ti->NoNum++,__ti->flag = 1;\
                             break;\
                        }\
                        __ti->testNum++;\
}
int test_run(void (*func)(TEST_INFO *), const char *str1,const char *str2){
    TEST_INFO ti = {0 ,0, 0, 0};
    printf("[run ] %s.%s\n",str1,str2);
    func(&ti);
    if(ti.flag == 1) {
        printf("\033[33m[ Wrong ]\033[0m %s.%s\n",str1,str2);
        return 0;
    }
    if(ti.NoNum == 0) {
        printf("\033[32m[    ok ] testNum = %d Yes = %d\033[0m %s.%s\n",ti.testNum,ti.YesNum,str1,str2);
    }
    else {
        printf("\033[31m[ FAILED ] \033[0m %s.%s %d pass %d faild \n",
              str1,str2,ti.YesNum,ti.NoNum);
    }
    return 0;
}
#endif

