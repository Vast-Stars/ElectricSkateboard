const int debug=1;
const int pin_dj=9;  //定义舵机接口数字接口9
int _speed;
char instr[1];
int i,j;

void setup()
{
  pinMode(pin_dj,OUTPUT); //设定舵机接口为输出接口

    Serial.begin(9600);   //设置两组串口波特率
    analogWrite(pin_dj,0);
  if (!debug)
  {
    Serial.println("3" ) ;
      delay(1000);
    Serial.println("2" ) ;
    delay(1000);
    Serial.println("1" ) ;
    delay(1000);
  }
  Serial.println("hello world!" ) ;
}

void loop()
{
  if(Serial.available())
  {
    i=0;
    while(Serial.available())
    {
      instr[i++]= Serial.read();
      delay(2); //至关重要！！！ 否则串口缓冲区不够时间接受数据！ 
    }
    _speed=atoi(instr);
    Serial.print("speed:");
    Serial.println(_speed);M
  }
  analogWrite(pin_dj,_speed);
 }
 

