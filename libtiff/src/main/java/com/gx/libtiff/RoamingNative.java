package com.gx.libtiff;

public class RoamingNative {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("tiff");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String stringFromJNI();
}
