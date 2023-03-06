#include <iostream>

using namespace std;

class Forbidden : public exception{
public:
virtual const char* what() const noexcept override {return "Вы ввели слово запретной длины! До свидания!";}
};

int check(string str, int forbidden_length){
    if(str.length() == forbidden_length) throw Forbidden();
    return str.length();
}

int main(){
    string word;
    int forbidden_length, length;
    cout << "Введите запретную длину ";
    cin >> forbidden_length;

    while(word.length() != forbidden_length){
    cout << "\nВведите слово ";
    cin >> word;
    try{
        length = check(word, forbidden_length);
        cout <<"Длина слова " << word << " равна " << length << endl;
    }
    catch(const Forbidden& ex) {cout << ex.what() << endl;}
    }
}