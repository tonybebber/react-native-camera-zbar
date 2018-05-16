/*
 * Copyright (C) 2010 ZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.lwansbrough.RCTCamera;


import android.hardware.Camera;
import android.os.Build;
import android.os.Handler;
import android.os.Message;

final class AutoFocusCallback implements Camera.AutoFocusCallback {

  private static final String TAG = AutoFocusCallback.class.getSimpleName();

  public static final long AUTOFOCUS_INTERVAL_MS = 2500L;
  private Handler handler;
  public void onAutoFocus(boolean success, Camera camera) {
      // Simulate continuous autofocus by sending a focus request every
      // AUTOFOCUS_INTERVAL_MS milliseconds.
      //Log.d(TAG, "Got auto-focus callback; requesting another");
      camera.cancelAutoFocus();
      if(android.os.Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH)
      if(camera.getParameters().isAutoExposureLockSupported())
        if(camera.getParameters().getAutoExposureLock()) {
          Camera.Parameters params = camera.getParameters();
          params.setWhiteBalance(Camera.Parameters.WHITE_BALANCE_AUTO);
          params.setAutoExposureLock(true);
          camera.setParameters(params);
          params = camera.getParameters();
          params.setAutoExposureLock(false);
          camera.setParameters(params);
        }
    if(handler!=null)
      handler.sendEmptyMessage(R.id.auto_focus);
  }

  public void setHandler(Handler handler) {
    this.handler = handler;
  }
}
