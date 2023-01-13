#include <iostream>
#include <cstring>
using namespace std;

string *split(string str,char delim = ' '){
    int size = 0;
    int init_size = (int)str.size();

	for(int i=0;i<init_size;i++){
		if(str[i] == delim) size++;
	}
	size++;

    string *fin = new string[size+1];
	int index = 1;
    string tmp = "";
	for(int i=0;i<init_size;i++){
		if(str[i] != delim) tmp += str[i];
		else{
			fin[index] = tmp;
			index++;
			tmp = "";
		}
	}
	fin[index] = tmp;
    fin[0] = to_string(index+1);
    tmp = "";
    return fin;
}

int main(){
    string input;
    while(1){
        cout << "input > ";
		getline(cin, input);
        if(input == "") continue; // ignore empty input
		string *alt = split(input); // the first element is the size of the array, split(<string>,<delimiter>)
        int arr_size = stoi(alt[0]);
        for(int i=1;i<arr_size;i++) cout << i << ": " << alt[i] << endl;
    }
}