//===============================================//
// IMPLEMENTASI LPF (LOW PASS FILTER)            //   
// DI ARDUINO, UNTUK FILTER DATA DARI            //
// SENSOR SUHU, AGAR DATA LEBIH HALUS            //
// Diprogram oleh: ARIF JOHAR TAUFIQ             //
//                 (arifjt@gmail.com)            //
//                 www.youtube.com/c/ArifJTaufiq //
// Out dapat dilihat lewat SERIAL MONITOR        //
// Out dapat dilihat lewat SERIAL PLOTTER        //
//===============================================//
float AktualTemp; 
float AktualTemp_1;   
float tempSet;
float Awal;
float tempC1;
float sensorSuhu = A0;                  //sensor suhu IC LM35
int Ts= 10;                             //T sampling 10 mS
void setup()
{ Serial.begin(9600);                   
  pinMode(sensorSuhu, INPUT);
  float Awal = analogRead(sensorSuhu);  // suhu awal 
  AktualTemp_1 = (5.0*Awal*100)/1024;   // konversi teg analog ke suhu Celcius
  Serial.println("Suhu Suhu_LPF");
}
void loop()
{       
    float Baca = analogRead(sensorSuhu); // baca data dari sensor 
    tempC1 = (5.0*Baca*100)/1024;        // konversi teg analog ke suhu
    
    //=========ini LPF DIGITAL ==================
    AktualTemp=(0.97*AktualTemp_1)+(0.03*tempC1);
    //=========ini  END LPF======================
         
    Serial.print(tempC1,1);             //plotter-1
    Serial.print(" ");                  //chr jeda   
    Serial.print(AktualTemp,1);         //plotter-2
    Serial.println(" ");
    AktualTemp_1=AktualTemp;
    delay(Ts); 
}
