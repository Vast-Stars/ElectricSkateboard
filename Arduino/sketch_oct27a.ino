#include <SoftwareSerial.h>   // 引用程式庫
 
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳

int Speed=0;
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
}
 
void loop() 
{
  if (BT.available() && BT.read()=='A') 
  {
    delay(2);
    receive();
  }
}

void receive()
{
/*  while(BT.available())
  {
    Speed=BT.read();
    
    delay(2);
    安卓调试设备开始以A 最后以19位结束
  }
*/  
  Speed=BT.read()-48;
  BT.println(Speed);
  Serial.println(Speed);

}


