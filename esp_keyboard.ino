#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUTTON_PIN1 15
#define BUTTON_PIN2 13
int no = 0 ;
int bob=0;
String str = "      ";
const char* ab = "     ";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
String key[37] = {
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
  "q", "w", "e", "r", "t", "y", "u", "i", "o", "p",
  "a", "s", "d", "f", "g", "h", "j", "k", "l","",
  "z", "x", "c", "v", "b", "n", "m"
};
String msg[39] = {
  "  -234567890           qwertyuiop            asdfghjkl bc         zxcvbnm en _ ",  
  "  1-34567890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  12-4567890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  123-567890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  1234-67890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  12345-7890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  123456-890           qwertyuiop            asdfghjkl bc         zxcvbnm en _  ",  
  "  1234567-90           qwertyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  12345678-0           qwertyuiop            asdfghjkl bc         zxcvbnm en _    ",  
  "  123456789-           qwertyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           Qwertyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qWertyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwErtyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qweRtyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwerTyuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertYuiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyUiop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuIop            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiOp            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuioP            asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            Asdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            aSdfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asDfghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdFghjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfGhjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfgHjkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghJkl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjKl bc         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkL bc         zxcvbnm en _     ",
  "  1234567890           qwertyuiop            asdfghjkl BC         zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         Zxcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zXcvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxCvbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcVbnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcvBnm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcvbNm en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcvbnM en _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcvbNm EN _     ",  
  "  1234567890           qwertyuiop            asdfghjkl bc         zxcvbnM en --     "  
  
};

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN1, INPUT_PULLUP); 
  pinMode(BUTTON_PIN2, INPUT_PULLUP); 

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);

  // ✅ Flip OLED along Y-axis (right-left mirror)
  display.ssd1306_command(SSD1306_SEGREMAP); // Reverse left-right mapping
  display.ssd1306_command(SSD1306_COMSCANDEC);    // Keep normal top-bottom mapping
}

void loop() {
  int buttonState1 = digitalRead(BUTTON_PIN1);
  int buttonState2 = digitalRead(BUTTON_PIN2);
  no=analogRead(A0);

  
  
  if ((buttonState1 ==1 )){
      Serial.println("high1");
      delay(200);
      
      if(bob == 29){
        str.remove(str.length() - 1);
        
        }
      if(bob == 38){
        str += " " ;
        }
      else {
        str += key[bob] ;
      }
    }
  if ((buttonState2 ==0 )){
      Serial.println("high2");
      str.remove(str.length() - 1);
        
    }

  if (no > 0 && no <= 1024) {
     bob = (no - 1) / 26.25;
    Serial.print("no = ");
    Serial.print(no);
    Serial.print(" → bob = ");
    Serial.println(bob);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 15);
  display.println(str);
  display.setCursor(0, 25);
  display.println(msg[bob]);
  display.invertDisplay(true); 
  display.display();
  delay(100);
}
