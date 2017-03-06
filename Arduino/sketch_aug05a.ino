int sp1=9;//定义舵机接口数字接口9
int x=0;
int pulsewidth;//定义脉宽变量
int val1;
int myangle1;

void servopulse(int sp1,int val1)//定义一个脉冲函数
{
  myangle1=map(val1,0,180,500,2480);
  digitalWrite(sp1,HIGH);//将舵机接口电平至高
  delayMicroseconds(myangle1);//延时脉宽值的微秒数
  digitalWrite(sp1,LOW);//将舵机接口电平至低
  delay(20-val1/1000);
}

void setup()
{
  pinMode(sp1,OUTPUT);//设定舵机接口为输出接口
  //设置两组串口波特率
  Serial.begin(9600);
  Serial.println("connected!" ) ;
  
  //看电调说明书，设置油门行程时，一开始需要把遥控器打到最高点。i<=110大概是2杪多
 //for(int i=0;i<=110;i++)
    {
      servopulse(sp1,150);//引用脉冲函数
    }
    
//等电机发出B-B两声后（就是两秒后，大概就是这里了）把油门打到最低点
    for(int i=0;i<=55;i++)
    {
      servopulse(sp1,20);//引用脉冲函数
    }
 
//后面提示后，就可以控制电机转动了
    for(int i=0;i<=150;i++)
    {
      servopulse(sp1,20);//引用脉冲函数
    }
    Serial.println("OK!" ) ;
}

void loop()
{
   if(Serial.available())
  {
      char ch=Serial.read();
      if(isDigit(ch)) 
      {
          x=(ch-'0');
          x=x*10+20; 
       }
   }
  if(x<=20)
      {
        x=20;
      } 
        servopulse(sp1,x);//引用脉冲函数 
 }

