# arbion (orbion qmk firmware test 20230407) 
* qmk v1.1.1

  使用arduino promicro

  ```
  make arbion:default
  ```

* 這是orbion space mouse改用qmk firmware的測試版本，
  目前沒有給3D建模軟體使用的設定
  
  * 主要是針對joystick做的功能切換
    * 遊戲搖桿模式
    * WASD按鍵模式
    * 滑鼠模式
    * 滾輪模式(未完善)
  
  * Rotry Encoder第一層為joystick功能切換，每轉兩步切換功能。
  
  * Orbion原有的4個gpio按鍵，其中1個是joystick按鍵，功能未設定。
  
  * 增加 3x3掃描按鍵，硬體線未拉出。

  * RGB功能保留
  
  * OLED顯示，只先做到可以正常操作，功能目錄未實現，未排版美化。
  
  * VIA未實現
  
  * 
  
  

* 以上功能全部要實現可能rom不夠用
