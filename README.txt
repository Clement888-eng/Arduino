Newest version = main.ino

all VCC = 5V

data = = ['Temp 1', 'Temp 2', 'Temp 3', 'Temp 4', 'Temp 5',
          'Temp 6', 'Temp 7', 'Temp 8', 'Temp 9', 'Temp 10',
          'Temp 11', 'Temp 12', 'Temp 13', 'Temp 14', 'Temp 15',
          'Temp 16', 'Temp 17', 'Temp 18', 'Temp 19', 'Temp 20',
          'Temp 21', 'Temp 22', 'Temp 23', 'Temp 24', 'Temp 25',
          'Temp 26 (do not use)', 'Voltage 1', 'Voltage 2', 'Voltage 3', 'Voltage 4', 'Voltage 5',
          'Current 1', 'Current 2', 'Current 3', 'Current 4', 'Current 5']

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
