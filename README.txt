Newest version = main.ino

all VCC = 5V

data length = 36
data type = float
data 1~26 = temperature
data 27~31 = voltage
data 32~36 = current

main.ino line 8-11 and 17-20 --> digital pins for mux 1 and 2
main.ino line 14 and 23 --> analog pin for mux 1 and 2
main.ino line 41-45 --> analog pin for voltage sensor 1-5
main.ino line 74-78 --> analog pin for current sensor 1-5

line 185 --> change min and max loop value for different output
line 127 and 129 --> increase delay if data corrupt

//when print//
on arduino IDE, go to tools > boards > arduino mega or mega 2560
upload code
go to tools > serial monitor or Ctrl + Shift + M
show timestep
