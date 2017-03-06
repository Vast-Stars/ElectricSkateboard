void setup()
{
 Serial.begin(9600);
}
 
void loop()
{
  while(Serial.available())
   {
     delay(2);
     Serial.println("Get Infomation：");
     while(Serial.available())
     {
     Serial.print(char( Serial.read()));
     delay(2);
     }
     Serial.println();
   }
   
}
