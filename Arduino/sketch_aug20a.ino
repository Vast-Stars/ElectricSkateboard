const int debug=1;
const int pin_dj=9;  //定义舵机接口数字接口9
int _speed;
char instr[2];
int i,j;

void setup()
{
  pinMode(pin_dj,OUTPUT); //设定舵机接口为输出接口

    Serial.begin(9600);   //设置两组串口波特率
    
    Serial.println("High");
      analogWrite(pin_dj,250);
      delay(2000);

//等电机发出B-B两声后（就是两秒后，大概就是这里了）把油门打到最低点
     Serial.println("Low");
     analogWrite(pin_dj,125);
     delay(2000);

     
//后面提示后，就可以控制电机转动了


  if (!debug)
  {
    Serial.println("3" ) ;
      delay(1000);
    Serial.println("2" ) ;
    delay(1000);
    Serial.println("1" ) ;
    delay(1000);
  }
    analogWrite(pin_dj,125);//引用脉冲函数
    Serial.println("OK!" ) ;
  Serial.println("hello world!" ) ;
}

void loop()
{
  if(Serial.available())
  {
    i=0;
    memset(instr,' ',3);
    while(Serial.available())
    {
      instr[i++]= Serial.read();
      delay(2); //至关重要！！！ 否则串口缓冲区不够时间接受数据！ 
    }
    _speed=atoi(instr);
    Serial.print("speed:");
    Serial.println(_speed);
  }
  analogWrite(pin_dj,_speed);
 }
  


