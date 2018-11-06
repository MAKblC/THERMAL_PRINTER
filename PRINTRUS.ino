#include         <SoftwareSerial.h>                   //  Подключаем библиотеку для работы по программной шине UART
#include         <Adafruit_Thermal.h>                 //  Подключаем библиотеку для работы с принтером
SoftwareSerial   mySerial(16, 17);                      //  Объявляем объект библиотеки SoftwareSerial, указывая задействованные выводы Arduino (RX=16-зелёный, TX=17-синий). Можно назначить другие выводы
Adafruit_Thermal printer(&mySerial);                  //  Объявляем объект библиотеки Adafruit_Thermal, указывая ссылку на созданный ранее объект mySerial библиотеки SoftwareSerial
         
void setup(){                                         //  Код функции setup выполняется только 1 раз, при старте скетча
    mySerial.begin(9600);                             //  Инициируем передачу данных по программной шине UART на скорости 9600. Функцию begin объекта mySerial нужно вызвать до вызова функции begin объекта printer!
    printer.begin();                                  //  Инициируем работу с термопринтером. В качестве параметра можно указать время нагрева пикселей от 3 (0,03 мс) до 255 (2,55 мс), чем выше тем темнее пикселы. Значение по умолчанию = 120 (1,20 мс)
    printer.setCodePage(CODEPAGE_CP866);  //  Загружаем кодовую страницу CODEPAGE_CP866
    printer.feed(3);    
printer.write(159);                   //  Выводим символ  'Я'
printer.write(255);                   //  Выводим символ  ' '
printer.write(226);                   //  Выводим символ  'т'
printer.write(165);                   //  Выводим символ  'е'
printer.write(161);                   //  Выводим символ  'б'
printer.write(239);                   //  Выводим символ  'я'
printer.write(255);                   //  Выводим символ  ' '
printer.write(171);                   //  Выводим символ  'л'
printer.write(238);                   //  Выводим символ  'ю'
printer.write(161);                   //  Выводим символ  'б'
printer.write(171);                   //  Выводим символ  'л'
printer.write(238);                   //  Выводим символ  'ю'
     printer.print("\r\n");           //  Выводим символы окончания '\r' и начала '\n' строки (перевод «каретки»)
     printer.feed(3);                      
}                                                     
                                                
void loop(){}       
