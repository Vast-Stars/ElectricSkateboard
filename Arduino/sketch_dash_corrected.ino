#include <SoftwareSerial.h>   // 引用程式庫
const int pin=3;
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
int minSpeed=40;
int Speed=0,CSpeed=0;

void receive();
void setA();

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
  pinMode(pin,OUTPUT);
}
 
void loop() 
{
  if (BT.available() ) 
  {
    delay(2);
    receive();
  }
}
void setA()
{

    if(Speed>CSpeed+10)
    {
      analogWrite(pin,CSpeed+10);
      Serial.println(CSpeed);
      delay(100);
      CSpeed+=10;
    }
    else
    {
      analogWrite(pin,CSpeed+10);
      delay(100);
      CSpeed=Speed;
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
  Speed=BT.read();
  if (Speed<minSpeed)
    Speed=minSpeed;
  Speed=map(Speed,minSpeed,100,125,200);
  
  while(Speed!=CSpeed)
    setA();
  analogWrite(pin,Speed);
  Serial.println(CSpeed);
}


