// 用一将 private 成员暴露的宏，供单测使用
// Created by TinggengYan on 2022/12/12.
//

#ifndef CPPSTUDY_TEST_ENABLE_HEADER_H
#define CPPSTUDY_TEST_ENABLE_HEADER_H
#if defined(UNIT_TEST_ENABLE)
// Get access to private members for testing
#define private public
#define protected public
#endif

#endif //CPPSTUDY_TEST_ENABLE_HEADER_H
