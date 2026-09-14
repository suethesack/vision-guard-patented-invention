int trigPin = 13; /* Sensorun trig pini Arduinonun 6 numaralı ayağına bağlandı */
int echoPin = 12;  /* Sensorun echo pini Arduinonun 7 numaralı ayağına bağlandı */
int ledsag = 5;
int ledsol = 4;
int buzzer = 8;
long sure;
long uzaklik;

void setup(){
  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT);/* echo pini giriş olarak ayarlandı */
  pinMode(ledsag, OUTPUT);
  pinMode(ledsol, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); /* Seri haberlesme baslatildi */
}
void loop()
{
  digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
  if(uzaklik > 50 && uzaklik<30)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(ledsag,HIGH);
    digitalWrite(ledsol,HIGH);
    delay(500);
    digitalWrite(ledsag,LOW);
    digitalWrite(ledsol,LOW);
    delay(500);
  
  }
  else 
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(ledsag,HIGH);
    digitalWrite(ledsol,HIGH);
  }

    
}

