#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){

  ifstream inFile("wc_input/insight.txt");

  // check if input file exists or not.
  if (!inFile){
    cerr << "... Could not open input file" << endl;
    return EXIT_FAILURE;
  }

  string words;

  vector<string> wordcounter;
  while(inFile >> words){

    if ((words=="'" || words=="." || words==",")) continue;

    // remove the special characters from the words
    char chars[] = "~`!@#$%^&8(0_-+={}[]|:;'<>,.?/";
    for (unsigned int i = 0; i < strlen(chars); ++i){
      words.erase (std::remove(words.begin(), words.end(), chars[i]), words.end());
   }

    // transform all words to lowercase
    std::transform(words.begin(), words.end(), words.begin(), ::tolower );

    wordcounter.push_back(words);
  }

  sort(wordcounter.begin(), wordcounter.end()); // sort the vector alphabatically

  ofstream outFile;
  outFile.open ("wc_output/wc_result.txt");

  for (int i=0; i<wordcounter.size(); i++){
    int second_index=0;
    int count=0;

    for (int j=0; j<wordcounter.size(); j++){
      if ((wordcounter[i]==wordcounter[j])) {
	second_index=j;
	count++;
      }
    }

    if (i!=second_index) continue; // to remove multiple outputs of the same word
    outFile << wordcounter[i] << "\t" << count << "\n"; 
  }

  outFile.close();

  inFile.close();
  return 0;
}
