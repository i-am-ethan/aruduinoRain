
// Viral Science
// Rain Detection Module

int rainsense= A0; // analog sensor input pin 0
int buzzerout= 10; // digital output pin 10 - buzzer output
int countval= 0; // counter value starting from 0 and goes up by 1 every second
int ledout= 11; // digital output pin 11 - led output
 
void setup(){
   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout, OUTPUT); 
   pinMode(rainsense, INPUT);
}
void loop(){
   int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading); // シリアルモニタに文字を映す
   delay(250);
  //===数値をいじるときは以下の数値をいじってください===
  //(1)雨センサーの値がxを超えたら => (rainSensereading >< x)
  //(2)その値がy秒間続いたら => (countval >= y)
   if (countval >= 2){ //2秒以上数えられたら
      Serial.print("Heavy rain");  //シリアルモニタに出力
      digitalWrite(buzzerout, HIGH);  //ブザーがなる
      digitalWrite(ledout, HIGH);  // LEDがひかる
   }
   //雨センサーの数値を220で判断するコード（環境によって変わるかと思います）
   if (rainSenseReading <220){ //雨センサーが220を超えたら
      countval++; // カウントを増やす（ここのカウントは上のcountvalに連携している）
   }
   else if (rainSenseReading >220) { //220を超えたら雨は降っていないとみなす
      digitalWrite(buzzerout, LOW); // ブザーを消す
      digitalWrite(ledout, LOW); // LEDを消す
      countval = 0; // カウントをリセットする
   }
   delay(1000);
}
