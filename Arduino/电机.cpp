int sp1=9;//�������ӿ����ֽӿ�9
int x=0;
int pulsewidth;//�����������
int val1;
int myangle1;
void servopulse(int sp1,int val1)//����һ�����庯��
{
  myangle1=map(val1,0,180,500,2480);
  digitalWrite(sp1,HIGH);//������ӿڵ�ƽ����
  delayMicroseconds(myangle1);//��ʱ����ֵ��΢����
  digitalWrite(sp1,LOW);//������ӿڵ�ƽ����
  delay(20-val1/1000);
}
/rvopulse�������ֵ��˽���
void setup()
{
  pinMode(sp1,OUTPUT);//�趨����ӿ�Ϊ����ӿ�
  //�������鴮�ڲ�����
  Serial.begin(9600);
  
  Serial.println("connected!" ) ;
  
  //�����˵���飬���������г�ʱ��һ��ʼ��Ҫ��ң��������ߵ㡣i<=110�����2�¶�
 //for(int i=0;i<=110;i++)
    {
      servopulse(sp1,150);//�������庯��
    }
    
//�ȵ������B-B�����󣨾�������󣬴�ž��������ˣ������Ŵ���͵�
    for(int i=0;i<=55;i++)
    {
      servopulse(sp1,20);//�������庯��
    }
  
//������ʾ�󣬾Ϳ��Կ��Ƶ��ת����
    for(int i=0;i<=150;i++)
    {
      servopulse(sp1,20);//�������庯��
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
        servopulse(sp1,x);//�������庯�� 
      
    
 }

