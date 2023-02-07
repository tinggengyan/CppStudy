#ifndef LOGGING_H
#define LOGGING_H

#ifdef __ANDROID__
#include <android/log.h>
#endif
#include <iostream>


#ifdef Windows
#define __FILENAME__ (strrchr(__FILE__, '\\') + 1) // Windows下文件目录层级是'\\'
#else
#define __FILENAME__ (strrchr(__FILE__, '/') + 1) // 默认使用这种方式
#endif

// 对应 cmake 的 build type
#ifdef Debug

#ifdef __ANDROID__
#define LOGV(TAG, format, ...) __android_log_print(ANDROID_LOG_VERBOSE, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGD(TAG, format, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGI(TAG, format, ...) __android_log_print(ANDROID_LOG_INFO, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGW(TAG, format, ...) __android_log_print(ANDROID_LOG_WARN, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGE(TAG, format, ...) __android_log_print(ANDROID_LOG_ERROR, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#define LOGV(TAG, format, ...) printf("[%s][%s][%s][%d]: " format, TAG,__FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n");
#define LOGD(TAG, format, ...) printf("[%s][%s][%s][%d]: " format, TAG,__FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n");
#define LOGI(TAG, format, ...) printf("[%s][%s][%s][%d]: " format, TAG,__FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n");
#define LOGW(TAG, format, ...) printf("[%s][%s][%s][%d]: " format, TAG,__FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n");
#define LOGE(TAG, format, ...) printf("[%s][%s][%s][%d]: " format, TAG,__FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n");

#endif // __ANDROID__

#else
#define LOGV(TAG, format, ...);
#define LOGD(TAG, format, ...);
#define LOGI(TAG, format, ...);
#define LOGW(TAG, format, ...);
#define LOGE(TAG, format, ...);


#endif // DEBUG


#endif //LOGGING_H
