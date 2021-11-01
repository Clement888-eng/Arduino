//Set all pins for temperature, voltage and current sensor
//Initialize array container for all data
//data[] = {temp1-25, voltage1-5, current1-5}
float data[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Temperature sensor
    //digital pins mux 1
int m1_s0 = 37;             
int m1_s1 = 41;
int m1_s2 = 45;
int m1_s3 = 49;

    //Analog pins mux 1
int m1_SIG_pin = 15;

    //digital pins mux 2
int m2_s0 = 45;             
int m2_s1 = 39;
int m2_s2 = 33;
int m2_s3 = 27;
  
    //Analog pins mux 2
int m2_SIG_pin = 11; 

    //Initialize parameters
int Vo;
float R1_temp = 1000;
float logR2, R2_temp, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int j;                      //initialize global variable j

//Voltage sensor
    //hold value from analogRead 
int value_0 = 0;                      
int value_1 = 0;
int value_2 = 0;
int value_3 = 0;
int value_4 = 0;

    //analog pins config
const int voltageSensor_0 = A0;       
const int voltageSensor_1 = A1;
const int voltageSensor_2 = A2;
const int voltageSensor_3 = A3;
const int voltageSensor_4 = A4;

    //map value to 0-5V
float vOUT_0 = 0.0;                   
float vOUT_1 = 0.0;
float vOUT_2 = 0.0;
float vOUT_3 = 0.0;
float vOUT_4 = 0.0;

    //final input voltage to print
float vIN_0 = 0.0;                    
float vIN_1 = 0.0;
float vIN_2 = 0.0;
float vIN_3 = 0.0;
float vIN_4 = 0.0;

    //Initialize parameters
float R1_volt = 30000.0;
float R2_volt = 7500.0;

//Current sensor
    //hold value from analogRead
int adcValue_0 = 0;
int adcValue_1 = 0;
int adcValue_2 = 0;
int adcValue_3 = 0;
int adcValue_4 = 0;

    //analog pins config
const int currentPin_0 = A5;
const int currentPin_1 = A6;
const int currentPin_2 = A7;
const int currentPin_3 = A8;
const int currentPin_4 = A9;

    //map value to 0-5V
double adcVoltage_0 = 0;
double adcVoltage_1 = 0;
double adcVoltage_2 = 0;
double adcVoltage_3 = 0;
double adcVoltage_4 = 0;

    //final input current to print
double currentValue_0 = 0;
double currentValue_1 = 0;
double currentValue_2 = 0;
double currentValue_3 = 0;
double currentValue_4 = 0;

    //Initialize parameters
int sensitivity = 66;         //sensitivity for ADC
int offsetVoltage = 2500; 

void setup(){
  Serial.begin(9600);         //set BAUD rate
  
  pinMode(m1_s0, OUTPUT);     //setup mux 1 and 2
  pinMode(m1_s1, OUTPUT); 
  pinMode(m1_s2, OUTPUT); 
  pinMode(m1_s3, OUTPUT); 

  digitalWrite(m1_s0, LOW);
  digitalWrite(m1_s1, LOW);
  digitalWrite(m1_s2, LOW);
  digitalWrite(m1_s3, LOW);

  pinMode(m2_s0, OUTPUT); 
  pinMode(m2_s1, OUTPUT); 
  pinMode(m2_s2, OUTPUT); 
  pinMode(m2_s3, OUTPUT); 

  digitalWrite(m2_s0, LOW);
  digitalWrite(m2_s1, LOW);
  digitalWrite(m2_s2, LOW);
  digitalWrite(m2_s3, LOW);
}

void loop(){
  //Loop from Temperature, Voltage and Current sensor
  //Loop through and read all 16 values Temperature sensor
  for(j = 0; j < 13; j ++){
    readMux_1(j);                           //check Mux_1 value
    delay(100);                              //add slight delay
    readMux_2(j);
    delay(50);                              
  }

  //Voltage sensor
  value_0 = analogRead(voltageSensor_0);
  value_1 = analogRead(voltageSensor_1);
  value_2 = analogRead(voltageSensor_2);
  value_3 = analogRead(voltageSensor_3);
  value_4 = analogRead(voltageSensor_4);

  vOUT_0 = (value_0 * 5.0) / 1024.0;
  vOUT_1 = (value_1 * 5.0) / 1024.0;
  vOUT_2 = (value_2 * 5.0) / 1024.0;
  vOUT_3 = (value_3 * 5.0) / 1024.0;
  vOUT_4 = (value_4 * 5.0) / 1024.0;

  vIN_0 = vOUT_0 / (R2_volt/(R1_volt+R2_volt));
  vIN_1 = vOUT_1 / (R2_volt/(R1_volt+R2_volt));
  vIN_2 = vOUT_2 / (R2_volt/(R1_volt+R2_volt));
  vIN_3 = vOUT_3 / (R2_volt/(R1_volt+R2_volt));
  vIN_4 = vOUT_4 / (R2_volt/(R1_volt+R2_volt));

  data[26] = vIN_0;
  data[27] = vIN_1;
  data[28] = vIN_2;
  data[29] = vIN_3;
  data[30] = vIN_4;

  //Current sensor
  adcValue_0 = analogRead(currentPin_0);
  adcValue_1 = analogRead(currentPin_1);
  adcValue_2 = analogRead(currentPin_2);
  adcValue_3 = analogRead(currentPin_3);
  adcValue_4 = analogRead(currentPin_4);

  adcVoltage_0 = (adcValue_0 / 1024.0) * 5000;
  adcVoltage_1 = (adcValue_1 / 1024.0) * 5000;
  adcVoltage_2 = (adcValue_2 / 1024.0) * 5000;
  adcVoltage_3 = (adcValue_3 / 1024.0) * 5000;
  adcVoltage_4 = (adcValue_4 / 1024.0) * 5000;

  currentValue_0 = ((adcVoltage_0 - offsetVoltage) / sensitivity);
  currentValue_1 = ((adcVoltage_1 - offsetVoltage) / sensitivity);
  currentValue_2 = ((adcVoltage_2 - offsetVoltage) / sensitivity);
  currentValue_3 = ((adcVoltage_3 - offsetVoltage) / sensitivity);
  currentValue_4 = ((adcVoltage_4 - offsetVoltage) / sensitivity);

  data[31] = currentValue_0;
  data[32] = currentValue_0;
  data[33] = currentValue_0;
  data[34] = currentValue_0;
  data[35] = currentValue_0;

  //print value
  int loop;

  for(loop = 0; loop < 6; loop++){
    Serial.print((String)data[loop]+" ");
  }
  Serial.println(" ");
  delay(1000);
}

int readMux_1(int channel){
  int controlPin[] = {m1_s0, m1_s1, m1_s2, m1_s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(m1_SIG_pin);

  //calculate temperature
  Vo = val;
  R2_temp = R1_temp * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2_temp);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  
  //write temp data to temp1 array
  data[j] = T;
}

int readMux_2(int channel){ //read mux 2
  int controlPin[] = {m2_s0, m2_s1, m2_s2, m2_s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(m2_SIG_pin);

  //calculate temperature
  Vo = val;
  R2_temp = R1_temp * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2_temp);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;

  //write temp data to temp2 array
  data[j+13] = T;
}
