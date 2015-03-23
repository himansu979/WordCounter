#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

double CalculateMedian(vector<int> numbers){
  sort(numbers.begin(), numbers.end()); // sort the the vector in increasing order
  int size = numbers.size();
  double median = size % 2 ? numbers[(size+1)/2 - 1] : (numbers[(size/2) - 1] + numbers[size / 2]) / 2.0;
  return median;
}

int main(){

  ifstream inFile("wc_input/insight.txt");

  // check if input file exists or not.
  if (!inFile){
    cerr << "... Could not open input file" << endl;
    return EXIT_FAILURE;
  }

  FILE *outFile;
  outFile = fopen ("wc_output/med_result.txt", "w");
  // create an empty file for writing

  vector<int> numWords;
  while(inFile.good()){
    // read each line from the file
    std::string line;
    std::getline(inFile, line);

    // read each word from the line
    std::istringstream line_words(line);
    std::string words;
    int line_word_count=0;
    while(line_words >> words){
      ++line_word_count;
    }

    numWords.push_back(line_word_count);
    double median = CalculateMedian(numWords);

    //cout << line << "\t" << line_word_count << endl;

    fprintf(outFile, "%2.1f \n", median);

  }

  fclose(outFile);

  inFile.close();

  return 0;
}
