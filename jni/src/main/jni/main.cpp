/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
/* Header for class com_samonkey_controller_jni_JNI */

#ifndef _Included_com_samonkey_controller_jni_JNI
#define _Included_com_samonkey_controller_jni_JNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_samonkey_controller_jni_JNI
 * Method:    execute
 * Signature: (I[Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_samonkey_controller_jni_JNI_execute
        (JNIEnv *env, jclass obj, jint argc, jobjectArray strArray) {
    jstring jstr;
    jsize len = argc;
    char **argv = (char **) malloc(len * sizeof(char *));


    jsize i = 0;


    for (i = 0; i < len; i++) {
        jstr = (jstring) env->GetObjectArrayElement(strArray, i);
        argv[i] = (char *) env->GetStringUTFChars(jstr, 0);


    }
    argc = len;
    int fd;
    ssize_t ret;
    int version;
    struct input_event event;


    if (argc != 5) {
        close(fd);//fprintf(stderr, "use: %s device type code value\n", argv[0]);
        return 1;
    }


    fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        close(fd);//fprintf(stderr, "could not open %s, %s\n", argv[optind], strerror(errno));
        return 2;
    }
    if (ioctl(fd, EVIOCGVERSION, &version)) {
        close(fd);//fprintf(stderr, "could not get driver version for %s, %s\n", argv[optind], strerror(errno));
        return 3;
    }
    memset(&event, 0, sizeof(event));
    event.type = atoi(argv[2]);
    event.code = atoi(argv[3]);
    event.value = atoi(argv[4]);
    ret = write(fd, &event, sizeof(event));
    if (ret < (ssize_t) sizeof(event)) {
        close(fd);
        //fprintf(stderr, "write event failed, %s\n", strerror(errno));
        return -1;
    }
    close(fd);


    return 0;
}

#ifdef __cplusplus
}
#endif
#endif
