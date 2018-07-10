package com.arch.cppjni;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.arch.util.IpUtil;

public class NextActivity  extends AppCompatActivity {
    private static final String TAG = "NextActivity";

    static final int MSG_INIT_ASYNC_CALL        		= 0x01; // 初始化异步调用call

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_next);

        mMainHandler.sendEmptyMessage(MSG_INIT_ASYNC_CALL);
//        (Button)findViewById(R.id.getInetaddress).setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
////                mMainHandler.sendMessage()
//            }
//        });

        new Thread(new Runnable() {
            @Override
            public void run() {
                final TextView remoteaddress = (TextView) findViewById(R.id.remoteaddress);
                final String address  = IpUtil.getAddressName("www.baidu.com").getHostAddress();
                remoteaddress.setText(address);
                    Log.d(TAG,address);
            }
        }).start();
    }

    Handler mMainHandler = new Handler() {

        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case MSG_INIT_ASYNC_CALL:{
                    final TextView net4address = (TextView) findViewById(R.id.net4address);
                    net4address.setText(IpUtil.getIpAddress().getHostAddress());

//                    final TextView remoteaddress = (TextView) findViewById(R.id.remoteaddress);
//                    remoteaddress.setText(IpUtil.getAddressName("http://www.baidu.com").getHostAddress());
//                    (TextView)findViewById(R.id.net4address).setText()
//                    IpUtil.getIpAddress();
                }
                break;
                default:
                    break;
            }
        }
    };
}
