
# a little preview

![1752845240921 (1) (1)](https://github.com/user-attachments/assets/3ac6342a-1dbf-4d04-b9a7-31ba160fc5e6)

# what u need 
## 1 . oled screen (128*64) 

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/9998ac0c-f254-4460-9915-4774ebb10855" />


## 2. lens from a diy vr goggles kits


<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/85e87ea8-5d34-47c2-bfdc-5940dc8b6985" />

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/1b893a46-acb9-4f11-bafa-663d9332bfac" />

## 3.  arduino or esp8266

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/a990bfdd-27d3-494a-8b19-437b5ada4c27" />

## 4.  pair of seethrough glasses with a flat lense
### example

<img width="225" height="225"  alt="image" src="https://github.com/user-attachments/assets/76bae35e-ea1a-457b-b354-1cc77c721e40" />


<img width="225" height="225"  alt="image" src="https://github.com/user-attachments/assets/92357644-b16b-42f9-84e9-e0e5376ef0e9" />




# 5. button

# 6 . potentiometer

so how this works is it works of the peppers ghost effect which works of the internal refraction effect. a common place u see this effect when your window starts acting like a mirror at certain angles

how to make it 
take your oled and stick it on a piece of foam or cardboard and then stick the lens the flatter side facing the screen approximately 1-2 cm away from the screen .

![1752847424344 (1) (1)](https://github.com/user-attachments/assets/7e113f7c-edc0-4f1a-8c6c-6a0d2be125af)


as u can see theyre parrallel
now   solder up the oled

<img width="291" height="173" alt="image" src="https://github.com/user-attachments/assets/21a2748e-533c-421c-a160-5f88c46f5cf9" />

download these libraries
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

replace these with youre wifi name and wifi password

const char *ssid     = "wifi name";
const char *password = "wifi password;


and then upload ar time.ino to the esp 

if u havent setup youre esp yet follow this tutorial

https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide

now wear the glasses and hold the lens facing towards the screen and move aro0und the arrangement till u get the best image

![1752847424344 (1) (1)](https://github.com/user-attachments/assets/7e113f7c-edc0-4f1a-8c6c-6a0d2be125af)


for me placing it parrallel and 2cm away from the screen gave me the best image while wearing(my eyes do have a slight power of 0.5 )

now just glue that arrangement on and glue the esp8266 on to the glasses and power the esp using a 5v battery using ther vin and gnd ports

<img width="291" height="173" alt="image" src="https://github.com/user-attachments/assets/e176e8b0-1261-455c-895f-dc3adebd2f75" />

now youre done you have a simple ar glasses which shows u the time,date and day

u can try your hand it and modify the scripts to show what u like. like imgs and animations
 i myself have made a onscreen keyboard i have uploaded the code but i havent uploaded a demo cause its a bit hard to record 
 thats also why the time image is a bit blurry its pretty hard to get on camera but look pretty good while wearing

##  Tip : change these constants underlined to 20 or 30 to make it fit on screen


   display.setCursor( <ins> 10 </ins> , 10);
   display.print("Time: ");
   display.println(formattedTime);
   
   display.setCursor(<ins>10</ins>, 20);
   display.print("Date:");
   display.println(currentDate);
   
   display.setCursor(<ins>10</ins> 30);
   display.print("Day: ");
   display.println(weekDay);








