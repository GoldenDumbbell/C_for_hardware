#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//---------------------------------- Code 3 ------------------------------------------------------------------------
int SensorIN = 6; 
int SensorOUT = 7; 
int Sensor = 8; 
int Sensor1 =9; 
int Sensor2 = 10; 
int Sensor3 = 11; 
int Value;
int servo1 = 4;
int servo2 = 5;
int vitri = 0;
Servo myservo1;
Servo myservo2;

//Tạo ký tự đặc biệt
 byte va[] = {
  B00000,
  B01100,
  B10010,
  B10100,
  B01000,
  B10101,
  B10010,
  B01101
};
void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(SensorIN, INPUT);
  pinMode(SensorOUT, INPUT);

  myservo1.attach(servo1);
  myservo1.write (0);
  myservo2.attach(servo2);
  myservo2.write (0);
  
  Serial.begin(9600);
  lcd.init(); // Khởi tạo màn hình Màn hình
  lcd.backlight(); // Bật đèn màn hình Màn hình
  lcd.createChar(0, va); // Tạo ký tự đặc biệt &


}
 int val1;
 int val2;
void loop() {
  int tong = 0;
  int a[4];
  int Value1 = digitalRead(Sensor);
  int Value2 = digitalRead(Sensor1);
  int Value3 = digitalRead(Sensor2);
  int Value4 = digitalRead(Sensor3);
  a[0] = Value1;
  a[1] = Value2;
  a[2] = Value3;
  a[3] = Value4;
 
 
  for(int c =0; c<4; c++){
    
      Serial.print( a[c] );


    if(a[c] != 0){
      tong++;
      
    }
  }
   Serial.println("");
  int ValueIN = digitalRead(SensorIN); 
  int ValueOUT = digitalRead(SensorOUT); 
  

    if (ValueIN == 1){
      delay(2000);
      myservo1.write (vitri = 93);
      

      
    }

     if (ValueOUT == 1){
       delay(2000);
      myservo2.write (vitri = 93);
      

     }
    
    
     
  

  
      lcd.setCursor(0, 0); // Chọn cột 1 và hàng 1
      lcd.print("Spot left:");
      lcd.setCursor(0, 1); // Chọn cột 1 và hàng 1
      lcd.print(tong);
      delay(100);
      if(ValueIN == 0){
         Receive_data();
     }
     if(ValueOUT == 0){
         Receive_data_OUT();
     }
 
}
void Receive_data()
{
 val1 = Serial.parseInt();
 if(val1 !=0){
   myservo1.write(val1);
 }

  
}
void Receive_data_OUT()
{
 val2 = Serial.parseInt();
 if(val2 !=0){
   myservo2.write(val2);
 }
 
  
}