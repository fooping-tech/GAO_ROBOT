
#include <M5Atom.h>
#include "AtomMotion.h"
#include "RINGLED.h"
RINGLED led = RINGLED();
int mode =0;
AtomMotion Atom;

uint32_t startTime = 0;
uint32_t cycleTime = 0;

void setup() {
  // put your setup code here, to run once:
  M5.begin(true, false, true);
  Atom.Init();  
  Atom.SetServoAngle(2, 0);
  //LED_INITIAL
  led.setup();//led setup (led_num)
  led.setbrightness(25);
  
  //SERIAL INITIAL
  Serial.begin(115200); //Serial begin
  delay(50);   //delay 50ms.  延迟50ms
  Serial.println("Connection!");
}

bool SQ =false;
bool CheckSQ(){
  return SQ;
}
void StartSeq(){
  SQ=true;
  startTime=millis();
  cycleTime=millis();
}
void StopSeq(){
  SQ=false;
}

void Seq(){
  uint32_t spentTime = millis() - startTime;
  Serial.println(spentTime);
  int sp=300;
  int a1=150;
  int a2=180;
  //led.flash(100);
  led.fire();
  if(0<=spentTime && spentTime < sp * 1){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 1<=spentTime && spentTime < sp * 2){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 2<=spentTime && spentTime < sp * 3){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 3<=spentTime && spentTime < sp * 4){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 4<=spentTime && spentTime < sp * 5){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 5<=spentTime && spentTime < sp * 6){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 6<=spentTime && spentTime < sp * 7){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 7<=spentTime && spentTime < sp * 8){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 8<=spentTime && spentTime < sp * 9){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 9<=spentTime && spentTime < sp * 10){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 10<=spentTime && spentTime < sp * 11){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 11<=spentTime && spentTime < sp * 12){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 12<=spentTime && spentTime < sp * 13){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 13<=spentTime && spentTime < sp * 14){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 14<=spentTime && spentTime < sp * 15){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 15<=spentTime && spentTime < sp * 16){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 16<=spentTime && spentTime < sp * 17){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 17<=spentTime && spentTime < sp * 18){
    Atom.SetServoAngle(2, a2);
  }else if(sp * 18<=spentTime && spentTime < sp * 19){
    Atom.SetServoAngle(2, a1);
  }else if(sp * 19<=spentTime){
    Atom.SetServoAngle(2, a2);
    Atom.SetServoAngle(2, 0);
    StopSeq();
    mode = 9;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  uint32_t deltaTime = millis() - cycleTime;
  //task
  if(deltaTime >=50){
    if(CheckSQ())Seq();
    cycleTime = millis();
  }
  //stop
  if(mode == 9){
    led.fade();
    Atom.SetServoAngle(2,0);
  }
  //mode1
  if(mode == 1){
    Atom.SetServoAngle(2,180);
    led.clyon();
  }
  //mode2
  if(mode == 2){
    if(!CheckSQ()){
      StartSeq();
    }
  }
  //mode3
  if(mode == 3){
    Atom.SetServoAngle(2,180);
    led.pacifica();
  }
  //mode4
  if(mode == 4){
    Atom.SetServoAngle(2,180);
    led.flash(0);
  }
  //mode5
  if(mode == 5){
    Atom.SetServoAngle(2,180);
    led.flash(100);
  }
  //mode6
  if(mode == 6){
    Atom.SetServoAngle(2,180);
    led.flash(200);
  }

  //シリアルからモード設定
  if (Serial.available())
  {
    int rec=Serial.parseInt();
    if(7000>=rec && rec>= 1)mode = rec ;//serial print改行コード0は無視
  }else{
    
  }

}
