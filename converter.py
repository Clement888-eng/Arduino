import pandas as pd
import csv
import numpy as np

#check wh
fields = ['Temp 1', 'Temp 2', 'Temp 3', 'Temp 4', 'Temp 5',
          'Temp 6', 'Temp 7', 'Temp 8', 'Temp 9', 'Temp 10',
          'Temp 11', 'Temp 12', 'Temp 13', 'Temp 14', 'Temp 15',
          'Temp 16', 'Temp 17', 'Temp 18', 'Temp 19', 'Temp 20',
          'Temp 21', 'Temp 22', 'Temp 23', 'Temp 24', 'Temp 25',
          'Temp 26 (do not use)', 'Voltage 1', 'Voltage 2', 'Voltage 3', 'Voltage 4', 'Voltage 5',
          'Current 1', 'Current 2', 'Current 3', 'Current 4', 'Current 5']

filename = 'converted_data.csv'
arr = []
inp = []

def convert():
    array = []
    arr2 = []
    '''
    with open('data-test.csv') as f:            #check file-in name
        for line in f:
            array = [line[:-1].split(' ')]
            arr.append(array)
        print(array[0])
    '''
    for i in inp:
        array = [i[:-1].split(' ')]
        arr2.append(array)
    print(arr2[0])

    with open(filename,'w') as csvfile:         #check file-out name
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(fields)
        for items in arr2:
            csvwriter.writerows(items)

def get_data():
    df = pd.read_csv('data stream from arduino.csv')
    arr = np.array(df)
    start = 6
    for i in range(start,1000):
        if type(arr[i][1])!=float:
            inp.append(arr[i][1])
        else:
            continue
    


if __name__=='__main__':
    get_data()
    convert()
    print("DONE!")


