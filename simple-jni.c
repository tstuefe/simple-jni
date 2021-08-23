#include <jni.h>
#include <stdio.h>

// actually only needed for tripping on prototype changes
#include "de_stuefe_repros_SimpleJNI.h"


/*
 * Class:     de_stuefe_repros_SimpleJNI
 * Method:    printArrayAsHex
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_de_stuefe_repros_SimpleJNI_printArrayAsHex
  (JNIEnv* env, jclass clazz, jbyteArray ar)
{
	jsize sz = (*env)->GetArrayLength(env, ar);
	jboolean is_copy = JNI_FALSE;
	jbyte* elems = (*env)->GetByteArrayElements(env, ar, &is_copy);
	
	for (int i = 0; i < sz; i ++) {
		printf("%x ", elems[i]);
		if (((i + 1) % 8) == 0) {
			printf("\n");
		}
	}
	
	(*env)->ReleaseByteArrayElements(env, ar, elems, is_copy);
}

