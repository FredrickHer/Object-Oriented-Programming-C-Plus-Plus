#include <iostream>
#include <vector>
#include<fstream>
#include <ctime>
using namespace std;


/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either 
 * finds the element or until it reaches the end (i.e element does not exist)
 * @param v : vector of elements 
 * @param elem : integer to look for 
 * @return int
*/
int iterativeService(vector<int>v, int elem){
    for (int i = 0; i < v.size(); ++i){
        
        if (v[i] == elem){

            return i;
        }
    }
    return -1;

}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
 * binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is increasing order(e.g. values go up and 
 * duplicates are not allowed.)
 * 
 * It calculates the mid from the start and end index. It compares v[mid](i.e. value
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * 
 * @param v : vector of elements 
 * @param start: leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int
*/
int binarySearch(vector<int> & v, int start, int end, int elem){
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (v[mid] == elem){
        return mid;
    } else if (v[mid] > elem){
        return binarySearch(v, start, mid -1, elem);
    } else{
        return binarySearch(v, mid + 1, end, elem);
    }
}

/**
 * @brief updates v to contain the values from filename (leave as is)
 * 
 * It is expected that the file contain values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename : string
 * @param v : vector
*/
void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

/**
 * @brief writes to file the time it took to search with respect to the 
 * size of the vector,  n
 * Number of Elements (n)       Time (sec)
 * XXXX                         X.XXXX
 * XXXX                         X.XXXX
 * @param filename (string) : filename  (e.g. output_10000_numbers.csv)
 * @param times (vector<double>) : average times 
 * @param n (vector<int>) : sizes of vectors 
*/
void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}
/**
 * @brief computes the average of the elements in vector, a
 * 
 * @param a vector of double 
 * @return double 
*/
double average(const vector<double> a){
    double sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum = sum + a[i];
    }
    return sum / a.size();

}

int main(){
    //test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // size (n) of all tests 
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    //n list of numbers
    vector<int>v;

    //results of times
    vector<double> times;

    //results of times
    vector<double> avg;

    //create a for loop to iterate through the file sizes
    for(int i = 0; i < file_sizes.size(); i++){
    // get the name/size of the file and assign it to string called filename
        string(filename) = to_string(file_sizes[i]) + "_numbers.csv";
    //call vecGen on filename and v
        vecGen(filename, v);
    // print filename (this will be good for debugging)
        cout << "Filename: " << filename << endl;
    // call times.clear() // this ensures that we reset times everytime we read a new file
        times.clear();
    // create another for loop to iterate through all the elements form elem_to_find.
    // the code here should be nearly identical to the code from the perivious lab
    for(int i = 0; i < elem_to_find.size(); i++){
        // gets the elem to serach for
        int elem = elem_to_find[i];

        // stopwatches the time 
        clock_t start = clock();                       // start time
        int index_if_found = iterativeService(v, elem); // call serach
        clock_t end = clock();                         // end time

        // calculates the total time it took in seconds
        double elpased_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        //prints the index and how long it took to find it
        cout << index_if_found << ": " << elpased_time_in_sec << endl;
        times.push_back(elpased_time_in_sec);
    }
    //call average on the vector, times, and save it as a double. This code should be
    //outside the for loop that iterates through all the elements from elem_to_find
    //but within the for loop that iterates through the file sizes
    double average_time = average(times);
    // append the double to avg. (hint: push_back())
    // This code should be outside the for loop that iterates through
    // all elements from elem_to_find 
    // but within the for loop that iterates through th efile sizes
    avg.push_back(average_time);

}
//outside both for loops call writeTimes with the appropriate parameters 
// the first parameter should be "interativeSearch_times.csv"
// read the function brief to complete the rest of the parameters
writeTimes("iterativeSerach_times.csv", avg, file_sizes);

//call avg.clear() to reset avg, so we can use it for binarySerach
avg.clear();

for(int i = 0; i < file_sizes.size(); i++){
    // get the name/size of the file and assign it to string called filename
        string(filename) = to_string(file_sizes[i]) + "_numbers.csv";
    //call vecGen on filename and v
        vecGen(filename, v);
    // print filename (this will be good for debugging)
        cout << "Filename: " << filename << endl;
    // call times.clear() // this ensures that we reset times everytime we read a new file
        times.clear();

//repeat the nested for loops used for iternativeSearch, but call binarySearch instead
    for(int i = 0; i < elem_to_find.size(); i++){
            // gets the elem to serach for
            int elem = elem_to_find[i];

            // stopwatches the time 
            clock_t start = clock();                       // start time
            int index_if_found = binarySearch(v, 0, v.size(), elem); // call serach
            clock_t end = clock();                         // end time

            // calculates the total time it took in seconds
            double elpased_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

            //prints the index and how long it took to find it
            cout << index_if_found << ": " << elpased_time_in_sec << endl;
            times.push_back(elpased_time_in_sec);
        }
    double average_time = average(times);
        // append the double to avg. (hint: push_back())
        // This code should be outside the for loop that iterates through
        // all elements from elem_to_find 
        // but within the for loop that iterates through th efile sizes
    avg.push_back(average_time);
}

//outside both for loops call writeTimes with the appropriate parameters 
// the first parameter should be "interativeSearch_times.csv"
// read the function brief to complete the rest of the parameters
writeTimes("binarySerach_times.csv", avg, file_sizes);
}