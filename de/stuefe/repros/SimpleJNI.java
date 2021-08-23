package de.stuefe.repros;

public class SimpleJNI {

	static {
		System.out.println(System.getProperty("java.library.path"));
		System.loadLibrary("simple-jni");
	}

	private static native void printArrayAsHex(byte[] array);

	public static void main(String[] args) {
		byte[] ar = { 0, 1, 2, 3, 4, 33, 44, 55, 22, 0xa, 0x3, 22, 11, 55, 22, 25, 11 };
		printArrayAsHex(ar);
	}

}
