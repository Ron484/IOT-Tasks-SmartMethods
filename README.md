# Task1-SmartMethods(IOT)
The first task in training smart methods - the Internet of Things (IOT) path:

#The first subtask:

1- A web page that converts speech to Arabic text:

for run the website page:

1-Click the page link : 
https://speech-text-convertor.netlify.app/

2-then press the "Start" button only once and then start talking.

Converting your speech to Arabic text will stop as soon as you stop talking, then if you talk again a new recording will start.
This web page works on laptops, mobiles.

 
#The second subtask:

2-Algorithm for running Wasdom ESP32.


# Task2-SmartMethods(IOT)
 The second task in training smart methods - the Internet of Things (IOT) path:

 In this task, we will use the previous web page task that converts speech to text, in order to convert speech into movement, by linking the page with an Arduino      connected with a servo motor, so that when we say "right", the motor moves 180 degrees and when we say "left" moves to zero degrees.

##The first subtask: 

1-Programming a web page to control the arm using the web serial API:

    We used the web serial library, which will associate the Arduino ID with the html page.

    Press the "connect" button, to connect to the serial port, and when you speak in Arabic and say (left or right) then the robot arm will move.
  
##The second subtask: 

2-Write the Arduino code for the control.

# Task3-SmartMethods(IOT)
 The third task in training smart methods - the Internet of Things (IOT) path:
 in this task we will have :
 1-ESP32  programmed with Arduino IDE
 2-DHT11 sensor (temperature & humidity sensor).
 3-PHP script to insert data into MySQL database.
 4-MySQL database to store readings
 
 Goal: we will read the temperature and humidity values  and store it in MYSQL database
 
 before running:
-  We need to install "MYSQL database", create a database named "get_sensorval", then create a table named"sensor", with two columns(temperature,humidity)
![image](https://user-images.githubusercontent.com/107871236/184456563-ad959db5-1e9e-4c93-8df7-8b9e7e3fa57d.png)

- in "sendValue.php" , Make sure to change the database password  to your password or put "".






