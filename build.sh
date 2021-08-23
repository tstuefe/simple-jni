# compile with 8:

JAVA_HOME=/shared/projects/openjdk/jdks/openjdk8

$JAVA_HOME/bin/javac ./de/stuefe/repros/SimpleJNI.java

# only needed for JDK < 10
$JAVA_HOME/bin/javah de.stuefe.repros.SimpleJNI

gcc -o libsimple-jni.so -lc -shared -I/shared/projects/openjdk/jdks/openjdk8/include -I/shared/projects/openjdk/jdks/sapmachine16/include/linux simple-jni.c


