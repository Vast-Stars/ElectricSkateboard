const int debug=1;
const int pin_dj=9;  //�������ӿ����ֽӿ�9
int Speed;
char instr[2];
int i,j;


//
//void servopulse(int pin_dj,int val1)//����һ�����庯��
//{
//	int myangle1;
//  myangle1=map(val1,0,180,500,2480);
//  digitalWrite(pin_dj,HIGH);//������ӿڵ�ƽ����
//  delayMicroseconds(myangle1);//��ʱ����ֵ��΢����
//  digitalWrite(pin_dj,LOW);//������ӿڵ�ƽ����
//  delay(20-val1/1000);
//}
//

void setup()
{
  pinMode(pin_dj,OUTPUT); //�趨����ӿ�Ϊ����ӿ�

    Serial.begin(9600);   //�������鴮�ڲ�����
    
	for(int i=0;i<=110;i++)
    {
      analogWrite(pin_dj,255);
      delay(20);
    }
    Serial.println("High");
//�ȵ������B-B�����󣨾�������󣬴�ž��������ˣ������Ŵ���͵�
    for(int i=0;i<=110;i++)
    {
     analogWrite(pin_dj,125);//�������庯��
     delay(20);
    }
     Serial.println("Low");
     
//������ʾ�󣬾Ϳ��Կ��Ƶ��ת����
	analogWrite(pin_dj,125);//�������庯��
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
    memset(instr,'',3)�� 
    while(Serial.available())
    {
      instr[i++]= Serial.read();
      delay(2); //������Ҫ������ ���򴮿ڻ���������ʱ��������ݣ� 
    }
    instr[i]='\0'; 
    _speed=atoi(instr);
    Serial.print("speed:");
    Serial.println(_speed);
  }
  analogWrite(pin_dj,_speed);
  delay(2);
 }
  




 

