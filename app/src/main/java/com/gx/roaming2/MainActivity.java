package com.gx.roaming2;

import android.os.Bundle;


import com.gx.roaming.RoamingNative;
import androidx.appcompat.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getSimpleName();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.btn_set).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                String str = RoamingNative.stringFromJNI();
//                Log.d(TAG, " onClick" + str);
//                str  = com.gx.libjpeg.RoamingNative.stringFromJNI();
//                Log.d(TAG, " onClick" + str);
//                str  = com.gx.libtiff.RoamingNative.stringFromJNI();
//                Log.d(TAG, " onClick" + str);
//                str  = com.gx.libzlib.RoamingNative.stringFromJNI();
//                Log.d(TAG, " onClick" + str);
//                str  = com.gx.libpng.RoamingNative.stringFromJNI();
//                Log.d(TAG, " onClick" + str);
                String str = com.gx.libfreetype.RoamingNative.stringFromJNI();
                Log.d(TAG, " onClick" + str);
            }
        });
    }


}