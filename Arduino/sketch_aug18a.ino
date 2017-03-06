const int debug=0;
const int pin_dj=9;  //定义舵机接口数字接口9
int _speed;
char instr[2];
int i,j;



void servopulse(int pin_dj,int val1)//定义一个脉冲函数
{
  int myangle1;
  myangle1=map(val1,0,180,500,2480);
  digitalWrite(pin_dj,HIGH);//将舵机接口电平至高
  delayMicroseconds(myangle1);//延时脉宽值的微秒数
  digitalWrite(pin_dj,LOW);//将舵机接口电平至低
  delay(20-val1/1000);
}

void setup()
{
  pinMode(pin_dj,OUTPUT); //设定舵机接口为输出接口

    Serial.begin(9600);   //设置两组串口波特率
    
  for(int i=0;i<=110;i++)
    {
      analogWrite(pin_dj,250);
      delay(20);
    }
    Serial.println("High");
//等电机发出B-B两声后（就是两秒后，大概就是这里了）把油门打到最低点
    for(int i=0;i<=110;i++)
    {
     analogWrite(pin_dj,125);//引用脉冲函数
     delay(20);
    }
     Serial.println("Low");
     
//后面提示后，就可以控制电机转动了
  analogWrite(pin_dj,125);//引用脉冲函数
    Serial.println("OK!" ) ;

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
  delay(2);
 }
  




 

