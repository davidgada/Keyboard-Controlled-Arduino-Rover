/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y,z;

ros::NodeHandle  nh;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){

  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
     delay(10);
      }

else if(vel.angular.z > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(0);
  myMotor->run(FORWARD);
  //myOtherMotor->run(FORWARD);
     delay(10);
        }
        else if(vel.angular.z < 0.0){
Serial.print("tick");



myMotor->setSpeed(0);
myOtherMotor->setSpeed(100);
  //myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    } else if(vel.angular.z > 0.1 && vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
     
        } else if(vel.angular.z < 0.0 && vel.linear.x < 0.0){
Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);




      
        } else if (vel.angular.z > 0.1 && vel.linear.x < 0.0){
          
          Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else if (vel.angular.z > 0.1 && vel.linear.x < 0.0){
          
          Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }

 delay(600);
 myMotor->setSpeed(0);
myOtherMotor->setSpeed(0);
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu <e.agada@uleth.ca>
Sent: Thursday, April 21, 2022 2:47 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: Re: Re: 
 
/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y,z;

ros::NodeHandle  nh;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){

  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
     delay(10);
      }

else if(vel.angular.z > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(0);
  myMotor->run(FORWARD);
  //myOtherMotor->run(FORWARD);
     delay(10);
        }
        else if(vel.angular.z < 0.1){
Serial.print("tick");



myMotor->setSpeed(0);
myOtherMotor->setSpeed(100);
  //myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    } else if(vel.angular.z > 0.1 && vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
     
        } else if(vel.angular.z < 0.1 && vel.linear.x < 0.1){
Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);




      
        } else if (vel.angular.z > 0.1 && vel.linear.x < 0.1){
          
          Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else if (vel.angular.z > 0.1 && vel.linear.x < 0.1){
          
          Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }

 delay(600);
 myMotor->setSpeed(0);
myOtherMotor->setSpeed(0);
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu <e.agada@uleth.ca>
Sent: Wednesday, April 20, 2022 12:37 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: Re: 
 
/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y;

ros::NodeHandle  nh;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){
  uint8_t i;
  if(vel.linear.x > 0.1){UU
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
    
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(150);
myOtherMotor->setSpeed(150);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
    
      }
      else 
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu
Sent: Wednesday, April 20, 2022 12:01 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: 
 
/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y;

ros::NodeHandle  nh;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){
  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");

  myMotor->run(FORWARD);
    myOtherMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);
    myOtherMotor->setSpeed(i);
    delay(10);
  }
  



    
   
  
    
    }
    else if(vel.linear.x < -0.1){
      myMotor->run(BACKWARD);
       myOtherMotor->run(FORWARD);
 for (i=0; i<255; i++){
    myMotor->setSpeed(i);
        myOtherMotor->setSpeed(i);

    delay(10);
  }
      
      }
      else 
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y,z;

ros::NodeHandle  nh;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){

  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
     delay(10);
      }

else if(vel.angular.z > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(0);
  myMotor->run(FORWARD);
  //myOtherMotor->run(FORWARD);
     delay(10);
        }
        else if(vel.angular.z < 0.0){
Serial.print("tick");



myMotor->setSpeed(0);
myOtherMotor->setSpeed(100);
  //myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    } else if(vel.angular.z > 0.1 && vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
     
        } else if(vel.angular.z < 0.0 && vel.linear.x < 0.0){
Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);




      
        } else if (vel.angular.z > 0.1 && vel.linear.x < 0.0){
          
          Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else if (vel.angular.z > 0.1 && vel.linear.x < 0.0){
          
          Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }

 delay(600);
 myMotor->setSpeed(0);
myOtherMotor->setSpeed(0);
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu <e.agada@uleth.ca>
Sent: Thursday, April 21, 2022 2:47 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: Re: Re: 
 
/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y,z;

ros::NodeHandle  nh;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){

  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(100);
myOtherMotor->setSpeed(100);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
     delay(10);
      }

else if(vel.angular.z > 0.1){
Serial.print("tick");



myMotor->setSpeed(100);
myOtherMotor->setSpeed(0);
  myMotor->run(FORWARD);
  //myOtherMotor->run(FORWARD);
     delay(10);
        }
        else if(vel.angular.z < 0.1){
Serial.print("tick");



myMotor->setSpeed(0);
myOtherMotor->setSpeed(100);
  //myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
   
  
    
    } else if(vel.angular.z > 0.1 && vel.linear.x > 0.1){
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
     
        } else if(vel.angular.z < 0.1 && vel.linear.x < 0.1){
Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);




      
        } else if (vel.angular.z > 0.1 && vel.linear.x < 0.1){
          
          Serial.print("tick");



myMotor->setSpeed(70);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
  
          
          
          
          
          } else if (vel.angular.z > 0.1 && vel.linear.x < 0.1){
          
          Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(70);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
     delay(10);
  
          
          } else
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }

 delay(600);
 myMotor->setSpeed(0);
myOtherMotor->setSpeed(0);
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu <e.agada@uleth.ca>
Sent: Wednesday, April 20, 2022 12:37 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: Re: 
 
/* 
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y;

ros::NodeHandle  nh;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){
  uint8_t i;
  if(vel.linear.x > 0.1){UU
Serial.print("tick");



myMotor->setSpeed(150);
myOtherMotor->setSpeed(150);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
    
   
  
    
    }
    else if(vel.linear.x < -0.1){

      myMotor->setSpeed(150);
myOtherMotor->setSpeed(150);
      myMotor->run(BACKWARD);
       myOtherMotor->run(BACKWARD);
    
      }
      else 
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
 
From: Agada, Ebubechukwu
Sent: Wednesday, April 20, 2022 12:01 PM
To: davidagada50@gmail.com <davidagada50@gmail.com>
Subject: 
 
/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_MotorShield.h>

float x,y;

ros::NodeHandle  nh;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(4);


void velCallback( const geometry_msgs::Twist& vel){
  uint8_t i;
  if(vel.linear.x > 0.1){
Serial.print("tick");

  myMotor->run(FORWARD);
    myOtherMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);
    myOtherMotor->setSpeed(i);
    delay(10);
  }
  



    
   
  
    
    }
    else if(vel.linear.x < -0.1){
      myMotor->run(BACKWARD);
       myOtherMotor->run(FORWARD);
 for (i=0; i<255; i++){
    myMotor->setSpeed(i);
        myOtherMotor->setSpeed(i);

    delay(10);
  }
      
      }
      else 
      {
        myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
        }
 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback );




void setup()
{


  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
