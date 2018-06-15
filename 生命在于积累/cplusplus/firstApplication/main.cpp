#include <iostream>
#include <fstream>
using namespace std;

int* quickSort(int a[], int start, int end) {

    int base = a[start];
    int s = start;
    int e = end;

    while(s <= e) {
//        for (int i = 0; i < 9; i++) {
//            cout << a[i] << " , ";
//        }

//        cout << endl;

        while(base > a[s] && s < end) {
            s++;
        }

        while(base < a[e] && e > start) {
            e--;
        }

        if(s <= e) {
            int temp = a[s];
            a[s] = a[e];
            a[e] = temp;
            s++;
            e--;
        }
    }

    if(start < e) {
        quickSort(a, start, e);
    }

    if(end > s) {
        quickSort(a, s, end);
    }

    return a;
}



//int* mergeSort(int a[], int size) {

//    if (first < last) {
//        int mid = (first + last) / 2;
//        mergeSort(a, first, mid, )
//    }
//    return a;
//}

//读取文件
void read(ifstream &T) {
    char c;
    while(T.peek() != EOF) {
        T.get(c);
        cout << c;
    }
}

int main(int argc, char *argv[])
{

    int array[] = {12, 4, 66, 9, 30, 75, 20, 19, 66};
    int array1[] = {12, 4, 66, 9, 30, 75, 20, 19, 66};
    //cout << sizeof(array)/sizeof(int) << " lalalala";
    int size = sizeof(array)/sizeof(int);

    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }

    cout << "befor " << size << endl;
    int *p = quickSort(array, 0, size - 1);
    cout << "end" << endl;

    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        cout << p[i] << endl;
    }

    ofstream SaveFile("pipi.txt");
    SaveFile << "leihouyas";
    SaveFile.close();

    ifstream OpenFile("pipi.txt");
    read(OpenFile);
    OpenFile.close();

    cout << "---------------------" << endl;

//    ofstream oo("pepe.txt");
//    oo.close();

    fstream File("pepe.txt", ios::in | ios::out);
    if(!File) {
        cout << "Error opening the file! Aborting…/n";
    }
//    ofstream oof("popo.txt", ios::nocreate);

//    if (oof.fail()) {
//        cout << "Error opening the file! Aborting…/n";
//    }
//    oof.close();

    File << "cece!";
    static char str[10];
    File.seekg(ios::beg);
    File >> str;
    cout << str << endl;
    File.close();

    return 0;
}


