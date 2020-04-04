#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Swap(vector<int> &vec, int a, int b){ //swap two of the elements in a vector
    int tmp = vec[a];
    vec[a] = vec[b];
    vec[b] = tmp;
}

int Partition(vector<int> &vec, int start, int end){ //the last element is chosen as pivot
    
    //i: the index where the last element smaller than pivot is
    int i = start - 1; //-1 since all the other elements might be larger the pivot
    
    for(int j=start; j<end; j++){ //compare all the other elements with pivot
        if(vec[j] <= vec[end]){//if smaller
            i++;//increment i, meaning that one more element smaller than pivot is found
            Swap(vec, i, j);//swap it with the ith element
        }
    }
    Swap(vec, i+1, end); //insert pivot between the smaller part and the larger part
    
    return i + 1; //return the pivot's position
}

void QuickSort(vector<int> &vec, int start, int end){
    if(start < end){ //is there are more than two elements
        int part = Partition(vec, start, end); //break into two parts
        QuickSort(vec, start, part-1); //first part: smaller than pivot
        QuickSort(vec, part+1, end); //second part: larger than pivot
    }
    
}

int main(){
    vector<int> vec;
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";

    //=====Read Input Sequence=====
    ifstream ReadFile(inputFile, ios::in);//declare input file
    //check if file exists
    if(!ReadFile.is_open()){
        cerr << "Input File not found.";
        exit(1);
    }
    
    int n = 0; //save how many numbers to sort
    ReadFile >> n; //read first line(numbers to sort)
    for(int i=0; i<n; i++){ //read the numbers and save them into vec
        int x;
        ReadFile >> x;
        vec.push_back(x);
    }
    
    //=====Do Quick Sort=====
    QuickSort(vec, 0, n-1);
    
    //=====Output Sorted Sequence=====
    ofstream WriteFile(outputFile, ios::out | ios::trunc);//declare output file
    //check if file exists
    if(!WriteFile.is_open()){
        cerr << "Output File not found.";
        exit(1);
    }
    
    for(int i=0; i<n; i++){ //read the sorted numbers in vector and write into file
        WriteFile << vec[i] << '\n';
    }
    
    return 0;
}
