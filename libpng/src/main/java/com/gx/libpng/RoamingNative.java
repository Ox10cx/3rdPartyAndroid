package com.gx.libpng;

public class RoamingNative {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("png");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String stringFromJNI();
}
